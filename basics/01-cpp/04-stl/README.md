# 第四部分：STL 容器、视图与值语义

本部分通过 C++23 Notebook 学习拥有型容器、非拥有视图和显式状态类型。目标不是记忆模板 API，而是从函数签名直接读出 ownership、borrow、mutability、lifetime 与 result state。

> 核心原则：**类型本身就是 ownership 和 API contract。**

> 当前状态：8 个实验及阶段验收已完成。

## 实验目录

| 顺序 | 实验 | 核心问题 |
| --- | --- | --- |
| 1 | [`std::string`](01_string.ipynb) | 字符所有权、容量、重分配和 C 字符串边界 |
| 2 | [`std::string_view`](02_string_view.ipynb) | 零拷贝借用、切片、NUL 与悬空 view |
| 3 | [`std::vector`](03_vector.ipynb) | 动态连续存储、iterator 失效和 pointer + length |
| 4 | [`std::array`](04_array.ipynb) | 编译期固定长度、值语义和固定协议字段 |
| 5 | [`std::span`](05_span.ipynb) | 通用连续借用、extent、子视图和跨边界生命周期 |
| 6 | [`std::optional`](06_optional.ipynb) | 显式缺失、contained value 生命周期和 C 状态码 |
| 7 | [`std::variant`](07_variant.ipynb) | 封闭状态、visitor、alternative 生命周期和 tagged ABI |
| 8 | [SDK 风格 API](08_sdk_style_api.ipynb) | 组合 ownership contract，并翻译为稳定 C ABI |

## 学习主线

```text
owning text/buffer       string / vector / array
                              │
                              ▼
borrowed view            string_view / span
                              │
                              ▼
explicit value state     optional / variant
                              │
                              ▼
internal SDK contract    expressive C++ API
                              │
                 ═════ ABI boundary ═════
                              │
                              ▼
stable C contract        pointer / length / handle
                         status / tag / out parameter
```

## 类型语义速查

| 类型 | 直接翻译 |
| --- | --- |
| `std::string` | 拥有动态文本 |
| `std::string_view` | 借用只读连续字符 |
| `std::vector<T>` | 拥有动态连续元素 |
| `std::array<T, N>` | 拥有固定数量连续元素 |
| `std::span<T>` | 借用可写连续元素 |
| `std::span<const T>` | 借用只读连续元素 |
| `std::optional<T>` | 拥有一个 T，或正常不存在 |
| `std::variant<A, B>` | 拥有 A 或 B 中恰好一种状态 |

optional/variant 只管理 contained value；若 T 本身是 pointer 或 view，contained value 仍然是借用。

## 运行与验证

从仓库根目录运行 `jupyter lab`，选择 `xcpp23` kernel，按编号从上到下执行。修改类或函数定义后先重启 kernel。每个实验都应检查：

- owner 是谁，资源何时释放；
- pointer/reference/view 的有效期；
- 哪些修改会使借用失效；
- 输入能否修改，数据是否连续；
- 缺失与失败是否被不同类型表达；
- C++ 异常是否在 ABI 边界内转换。

生成的二进制、缓存、checkpoint 和实验输出目录不提交；只保留能解释结论的少量 Notebook 输出。

## API 语义翻译验收

看到以下 API：

```cpp
std::vector<std::uint8_t> read_file();

void process(
    std::span<const std::uint8_t> input
);

std::optional<User> find_user(
    std::string_view name
);

std::variant<Result, Error> execute();
```

应直接翻译为：

```text
read_file()
└─ 返回自己拥有的动态字节数据，调用方接管结果 owner

process()
└─ 调用期间借用只读连续 buffer，不保存、不释放、不修改

find_user()
├─ 调用期间借用只读字符串
└─ 返回拥有的 User，或者用户正常不存在

execute()
└─ 返回并拥有 Result 或 Error 中恰好一种状态
```

只回答“span 是 STL 模板类”不算通过。答案必须包含 ownership、borrow、mutability、lifetime 和 state contract。

## 最终关键验收

为什么下面的接口适合作为 C++ 内部 API，却绝对不应该直接作为 C ABI 暴露？

```cpp
std::variant<
    std::vector<std::uint8_t>,
    Error
>
process(
    std::span<const std::uint8_t> input
);
```

合格答案必须说明：

1. 输入 span 是同步只读借用；成功 vector 是调用方拥有的动态输出；Error 是另一拥有型结果。
2. variant 管理 active alternative，vector 管理动态分配和析构，span 表达 pointer + length 视图。
3. 三者都是 C++ 类型，涉及 C++ ABI、object layout、constructor/destructor、template instantiation、standard library implementation、异常机制以及 compiler/runtime compatibility。
4. C 编译器无法理解这些对象及其生命周期；不同 C++ 工具链也不能默认二进制兼容。
5. C ABI 必须重新表达相同语义：pointer + length 表达借用，caller buffer 或 opaque handle 表达所有权，固定 enum/status 与 out parameter 表达结果。
6. 所有 C++ 异常必须在 ABI 内部捕获，跨边界的分配与释放必须遵循同一明确协议。

```text
          Internal C++

 span / vector / optional / variant
                │
                ▼
             C++ Core

════════════ ABI Boundary ════════════

               C ABI
                │
                ▼
 pointer / length / handle
 status / tag / out parameter
                │
                ▼
    Kotlin/Native cinterop wrapper
```

完成本部分后，应能先从类型读懂内部 API contract，再把它翻译成简单、稳定、可验证的 C ABI，为后续 Kotlin/Native cinterop 建立正确的内存与状态模型。
