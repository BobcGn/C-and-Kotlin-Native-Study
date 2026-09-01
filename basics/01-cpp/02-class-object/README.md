# 第二部分：类与对象

本目录通过六个 C++23 Notebook 从 `struct`/`class` 的基本语法逐步进入对象生命周期、成员函数、所有权和头文件组织，为后续学习 RAII、对象布局与 Native SDK 构建打基础。

## 实验目录

| 顺序 | 实验 | 大致内容 |
| --- | --- | --- |
| 1 | [从结构体到类](01_class_struct.ipynb) | `struct` 与 `class`、访问控制、状态与行为封装，以及工程中的选择。 |
| 2 | [构造与析构函数](02_constructor_destructor.ipynb) | 构造函数、成员初始化列表、类的不变量、析构顺序和作用域生命周期。 |
| 3 | [常量成员函数](03_const_member.ipynb) | 成员函数末尾的 `const`、只读对象调用规则，以及 getter 的返回方式。 |
| 4 | [`this` 指针与静态成员](04_this_static.ipynb) | 成员函数如何定位当前对象、`this` 指针，以及属于类而非对象的静态成员。 |
| 5 | [栈对象与堆对象](05_stack_heap.ipynb) | 自动和动态存储期、对象销毁时机、所有权，以及避免直接使用 `new/delete` 的原因。 |
| 6 | [头文件与源文件分离](06_header_source.ipynb) | 类接口与实现的拆分、include guard、作用域解析、编译链接流程，以及对象布局与 ABI。 |

实验 6 使用的公开头文件位于 [`include/user.hpp`](include/user.hpp)，其余声明、实现和调用代码可在 Notebook 中交互执行。

## 学习顺序

按编号依次执行六个 Notebook。前五个实验建立类与对象的语义基础，最后一个实验把这些知识放进多文件工程和 Native SDK 的构建链路中。
