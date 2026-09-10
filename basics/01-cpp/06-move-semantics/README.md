# 第六阶段：移动语义

本阶段从表达式的 value category 出发，逐步理解右值引用、`std::move`、移动构造与移动赋值。重点不是记忆语法，而是判断资源所有权何时可以安全转移，以及 moved-from 对象仍需满足什么约束。

## 实验顺序

| 实验 | 内容 | 验收重点 |
| --- | --- | --- |
| [实验 1：Value Category](notebooks/01_value_categories.ipynb) | lvalue、xvalue、prvalue 与 `std::move` | 能根据表达式和函数返回类型判断 category |

后续实验将在此基础上引入右值引用、copy/move constructor、move assignment、Rule of Five 与 Rule of Zero。

## 运行方式

从仓库根目录启动 Jupyter：

```bash
jupyter lab
```

打开 `notebooks/` 中的实验，确认 kernel 为 `xcpp23`，重启 kernel 后按顺序运行全部单元。失败示例仅用于解释编译限制，不应直接执行。

## 当前验收

完成实验 1 后，应能直接解释：

```text
命名变量                 -> lvalue
临时值或按值返回结果     -> prvalue
std::move(object)        -> xvalue
命名的 T&& 变量表达式    -> lvalue
```

`std::move` 本身不搬运资源，它只把表达式转换为可被移动操作接收的 xvalue。value category 影响重载与资源转移机会，但不取代 ownership 和 lifetime contract。C ABI 也不暴露引用类别；跨 ABI 边界仍应使用 pointer、length、handle 和 status 等稳定表示。
