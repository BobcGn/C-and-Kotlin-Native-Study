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
- [ ] 比较手动 `new/delete`、`unique_ptr` 和 `shared_ptr`
- [x] 练习 `vector`、`string`、iterator 与算法
- [x] 使用 `span` 表达非拥有视图
- [x] 使用 `optional` 与 `variant` 表达结果状态
- [x] 编写 ownership 笔记

## Week 3：移动、并发与工具链

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

