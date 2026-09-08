# 第四部分：STL 连续容器与视图

本目录通过四个 C++23 Notebook 学习拥有型连续容器、非拥有视图以及它们在 Native SDK 边界上的生命周期规则。

## 实验目录

| 顺序 | 实验 | 核心问题 |
| --- | --- | --- |
| 1 | [`std::string`](01_string.ipynb) | 字符所有权、容量、重分配和 C 字符串边界 |
| 2 | [`std::string_view`](02_string_view.ipynb) | 零拷贝借用、切片、NUL 与悬空 view |
| 3 | [`std::vector`](03_vector.ipynb) | 动态连续存储、iterator 失效和 pointer + length |
| 4 | [`std::array`](04_array.ipynb) | 编译期固定长度、值语义和固定协议字段 |

## 学习与验证方式

使用 `xcpp23` kernel 按编号从上到下执行每份 Notebook。修改类或函数定义后，先重启 kernel 再重新运行。重点观察谁拥有底层存储、哪些操作使借用失效，以及 C ABI/Kotlin/Native 调用能否把借用限制在同步作用域内。

完成本部分后，应能根据长度是否固定、数据是否需要拥有、借用持续多久，选择 `string`、`string_view`、`vector` 或 `array`，并解释为什么 C ABI 不能直接暴露这些 C++ 类型。
