# 第五阶段：智能指针与所有权设计

本阶段从 raw pointer 的手动清理问题出发，学习用类型表达 owner、borrower、ownership transfer、shared lifetime 和 non-owning observation。重点不是“把所有 pointer 换成智能指针”，而是选择最简单、最准确的 ownership contract。

> 当前状态：9 个实验及阶段验收已完成。

## 实验目录

| 实验 | 主题 | 核心问题 |
| --- | --- | --- |
| [01](notebooks/01_raw_pointer_problem.ipynb) | Raw pointer | 提前返回为什么造成泄漏？ |
| [02](notebooks/02_unique_ptr.ipynb) | `unique_ptr` | 唯一 owner 如何自动清理？ |
| [03](notebooks/03_unique_ownership_transfer.ipynb) | Ownership transfer | 为什么不能复制但可以移动？ |
| [04](notebooks/04_custom_deleter.ipynb) | Custom deleter | 如何用 RAII 管理 `FILE*`？ |
| [05](notebooks/05_shared_ptr.ipynb) | `shared_ptr` | 多个 owner 如何共同延长生命周期？ |
| [06](notebooks/06_weak_ptr.ipynb) | `weak_ptr` | 如何安全观察但不保活对象？ |
| [07](notebooks/07_cyclic_reference.ipynb) | Cyclic reference | strong cycle 和 callback self-cycle 为什么泄漏？ |
| [08](notebooks/08_owner_borrower.ipynb) | Owner / borrower | 为什么普通业务 API 应接收对象借用？ |
| [09](notebooks/09_sdk_style.ipynb) | SDK ownership | 如何选择成员类型并设计 C ABI handle？ |

## 运行与诊断

从仓库根目录启动 `jupyter lab`，确认 kernel 为 `xcpp23`，重启后从上到下运行 Notebook。

实验 9 提供两个独立程序。进入本目录后运行 raw pointer 版本：

```bash
clang++ -std=c++23 -Wall -Wextra -Wpedantic -g -O0 \
  -fsanitize=address,undefined src/09_raw_double_free.cpp \
  -o /tmp/09_raw_double_free
/tmp/09_raw_double_free
```

预期 AddressSanitizer 报告 double-free。安全版本应正常退出：

```bash
clang++ -std=c++23 -Wall -Wextra -Wpedantic -g -O0 \
  -fsanitize=address,undefined src/09_unique_ptr_safe.cpp \
  -o /tmp/09_unique_ptr_safe
/tmp/09_unique_ptr_safe
```

## 从类型读取 Contract

| 类型 | 直接语义 |
| --- | --- |
| `const User&` | 必须存在的 read-only borrow |
| `User&` | 必须存在的 mutable borrow |
| `User*` | nullable/non-owning pointer；ownership 需由 contract 说明 |
| `unique_ptr<User>` 参数 | ownership transfer into function |
| `unique_ptr<User>` 返回值 | ownership transfer to caller |
| `shared_ptr<User>` 参数 | 函数参与 shared ownership |
| `weak_ptr<User>` | 不保活 shared object 的可检查观察 |

智能指针应主要出现在 factory、owner 成员、ownership sink 和共享边界。函数只使用对象时，优先传 `T&` 或 `T*`，不要让业务逻辑依赖调用方的 ownership container。

## Ownership 选择顺序

```text
直接成员
   │ 生命周期完全属于父对象
   ▼
unique_ptr
   │ 动态、可选、可替换、多态或实现隔离
   ▼
shared_ptr
     多个实体确实需要独立延长生命周期
```

看到 Runtime 的 Engine、Model、Buffer 全部使用 `shared_ptr` 时，先问“为什么必须共享？”如果它们与 Runtime 同生共死且不需要动态替换，直接成员更准确；若需要唯一的动态生命周期，使用 `unique_ptr`。raw pointer/reference 只表达借用，不能承担未说明的销毁责任。

## C ABI 与 Kotlin/Native

C++ 内部可以使用直接成员、RAII 和智能指针；C ABI 不应暴露这些 C++ 类型，而应使用 opaque handle、定宽状态码及成对 lifecycle 函数：

```text
C++ Core: Runtime / unique_ptr / shared_ptr / RAII
                         │
══════════════ ABI Boundary ══════════════
                         │
C ABI: handle / status / create / destroy
                         │
Kotlin/Native: owner wrapper / execute / close
```

Kotlin wrapper 必须防止重复 destroy 和 close 后使用。GC 管理 Kotlin 引用，不等于自动管理 C/C++ handle。

## 阶段验收

不查资料回答：

1. 为什么 `unique_ptr` 是默认的动态 ownership 类型？
2. 为什么 `unique_ptr` 不能复制，`std::move` 后谁是 owner？
3. `shared_ptr` 的 control block、reference counting 和 shared lifetime 带来什么成本？
4. cyclic `shared_ptr` 为什么不能自动回收？
5. `weak_ptr::lock()` 表达什么语义？
6. 为什么 `process(const Engine&)` 通常优于 `process(const unique_ptr<Engine>&)`？
7. `get()`、`release()` 和 `reset()` 分别如何改变 ownership？
8. 面对对象关系，能否从 owner、转移、共享、可空及借用时间决定使用直接成员、智能指针或引用？

通过标准：能画出 ownership graph，说明谁创建、拥有、借用和释放每个资源，并解释该关系跨 C ABI 后如何变成 handle contract。下一阶段将深入 copy/move constructor、右值引用和 rule of zero/five。
