# Phase 1：Modern C/C++（Week 1–3）

## 目标

掌握 Native SDK 开发直接依赖的 C++ 语义：对象生命周期、所有权、RAII、容器、移动语义、并发和基础诊断工具。

## Week 1：引用、对象与生命周期

- [x] 引用、指针、地址与重新绑定差异
- [x] 值传递、引用传递、`const T&`
- [x] `const` 与 pointer/reference 组合
- [x] 悬空引用与生命周期反例
- [x] `struct`/`class`、构造与析构、`this`、静态成员
- [x] 栈对象与堆对象、头文件与实现文件分离
- [ ] 用 AddressSanitizer 记录悬空引用诊断

## Week 2：RAII、STL 与所有权

- [x] 为文件句柄或动态资源实现 RAII wrapper
- [x] 比较手动 `new/delete`、`unique_ptr` 和 `shared_ptr`
- [x] 练习 `vector`、`string`、iterator 与算法
- [x] 使用 `span` 表达非拥有视图
- [x] 使用 `optional` 与 `variant` 表达结果状态
- [x] 编写 ownership 笔记

## Week 3：移动、并发与工具链

- [x] 区分 lvalue、prvalue、xvalue，并理解 `std::move` 产生 xvalue
- [ ] 观察 copy/move constructor 和 move assignment
- [ ] 实现 rule of zero / rule of five 对照实验
- [ ] 使用 `thread`、`mutex`、`atomic`
- [ ] 用 ThreadSanitizer 验证 data race
- [ ] 使用 CMake + Ninja 构建多文件小型库
- [ ] 使用 LLDB、ASan 与 UBSan

## Definition of Done

- 从干净环境可一条命令构建和运行全部实验。
- 能解释资源创建、转移和销毁，以及悬空引用、泄漏、double free 和 data race。
- CMake 项目具有测试目标和 Sanitizer 构建选项。
- 形成 RAII、ownership 和 concurrency 总结。

## Current Priority / Scheduling Note

Phase 1 的 checklist 保持完整；近期 Kotlin/JS 目标不会删除或改写这些任务。

- **Move Semantics** 正在进行，完成 copy/move 行为的最小学习闭环。
- **CMake / Ninja** 保留为 Build / Native Track 内容，但不是开始 Kotlin/JS Track 的前置条件。
- **Concurrency / TSan** 延后到出现真实并发或 Native Runtime 问题时再优先处理。
- **LLDB / ASan / UBSan** 是 Native Debug 能力，随相关原生实验引入；不作为进入 Kotlin/JS Track 的门槛。
- Phase 1 完成与否 **不阻止开始 Kotlin/JS Track**。Phase checklist 记录主题任务状态；Track 按其自身问题和证据推进。
