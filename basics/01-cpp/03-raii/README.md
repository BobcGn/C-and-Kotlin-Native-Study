# 第三部分：RAII 与资源生命周期

本目录通过六个 C++23 Notebook，把前两部分学习的引用、对象和生命周期进一步扩展到资源管理。核心思想是：资源的生命周期不依赖调用者“记得释放”，而是由对象的构造与析构自动管理。

RAII（Resource Acquisition Is Initialization）不只适用于内存，也适用于文件、锁、Socket、数据库连接和 Native handle。它是后续编写可靠 Native SDK、设计所有权模型和异常安全代码的基础。

## 实验目录

| 顺序 | 实验 | 大致内容 |
| --- | --- | --- |
| 1 | [手动管理资源](01_manual-resource.ipynb) | 直接获取和释放资源，观察正常路径、提前返回和遗漏清理时的重复代码与泄漏风险。 |
| 2 | [使用 RAII 管理文件](02_file_raii.ipynb) | 把文件句柄绑定到对象，在构造函数中获取资源、析构函数中释放资源，建立 RAII 的基本模型。 |
| 3 | [作用域与资源生命周期](03_scope_lifetime.ipynb) | 观察嵌套作用域、多个局部对象和逆序析构，理解对象生命周期如何决定资源释放时机。 |
| 4 | [提前返回与自动清理](04_early_return.ipynb) | 对比手动清理与 RAII 在多个返回分支中的表现，理解单一释放路径带来的可靠性。 |
| 5 | [异常安全](05_exception_safety.ipynb) | 观察跨调用栈的异常传播、部分构造失败和成员清理，理解异常安全保证及 C ABI 边界。 |
| 6 | [封装完整的 `File` 类](06_file_class.ipynb) | 综合唯一所有权、类不变量、确定性析构、错误报告和 C handle 借用，形成可复用的文件资源类型。 |

实验 6 的公开接口位于 [`include/file.hpp`](include/file.hpp)，成员函数实现和使用代码保留在 Notebook 中，便于交互执行。

## 运行方式与输出

使用 C++23 kernel 按编号打开 Notebook，并从上到下执行单元格。Notebook kernel 会保留已经执行的声明；修改类或函数定义后遇到 `redefinition` 时，请重启 kernel 再重新执行。

各实验产生的文件统一写入 `outputs/<实验编号>/`。整个 `outputs/` 目录已被 Git 忽略，不应把运行产物加入提交。

## 学习主线

```text
手动获取与释放资源
        ↓
发现遗漏清理和重复代码
        ↓
把资源绑定到对象生命周期
        ↓
作用域结束自动析构
        ↓
提前返回和异常路径仍能正确清理
        ↓
形成可复用的 RAII 资源包装类
```

## 与 Native SDK 的关系

Native SDK 经常向上层暴露文件、网络连接、线程同步对象或不透明 handle。如果释放逻辑散落在各个调用分支中，就容易出现泄漏、重复释放和异常路径清理不完整。RAII 可以把资源所有权集中到一个对象中，使资源的创建、使用和销毁具有明确且可测试的边界。

完成本部分后，应能从“谁拥有资源、何时释放资源、所有退出路径是否安全”三个角度审视资源管理代码，并能说明 RAII 如何把资源生命周期转换为对象生命周期问题。

## 本部分形成的设计约定

- 构造成功的资源对象必须处于有效状态。
- 析构函数负责不抛异常的兜底清理。
- 唯一资源 owner 不能被错误复制；所有权转移留到移动语义阶段处理。
- 原始 handle 只作为受约束的借用值，不转移所有权。
- 资源作用域应尽可能小，多个资源依靠成员组合和逆序析构管理依赖关系。
- C++ 异常必须在 C ABI 边界内被捕获并转换为稳定错误协议。

## 验收题

1. 为什么：

   ```cpp
   File file(...);
   ```

   比：

   ```cpp
   FILE *file = fopen(...);
   ```

   多表达了一个：

   ```text
   ownership model
   ```

2. 为什么 RAII 可以解决：

   ```text
   early return
   ```

   带来的 cleanup 问题？

3. 为什么 exception 抛出过程中，RAII resource 仍然能够释放？

   回答里应该出现：

   ```text
   stack unwinding
   ```

4. 为什么：

   ```cpp
   ~File()
   ```

   通常不能抛出 exception？

5. 假设析构函数会对 `file_` 调用 `fclose()`，为什么下面这个类允许复制会很危险？

   ```cpp
   class File
   {
   private:
       FILE *file_;
   };
   ```

   如果允许：

   ```cpp
   File b = a;
   ```

   回答里应该包含：

   ```text
   shallow copy
   → shared raw handle
   → double release
   ```

6. 为什么：

   ```cpp
   File(const File &) = delete;
   ```

   和：

   ```cpp
   File &operator=(const File &) = delete;
   ```

   可以保护 ownership？

7. RAII 和 GC 最大的区别是什么？

   回答里至少应该包含：

   ```text
   RAII
   deterministic destruction

   GC
   non-deterministic reclamation
   ```

8. 为什么：

   ```text
   RAII ≠ smart pointer
   ```

   ？
