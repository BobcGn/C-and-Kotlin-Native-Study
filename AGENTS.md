# Repository Guidelines

## 仓库定位与目录职责

本仓库用于循序学习 C/C++、Native SDK、Kotlin/Native 与 KMP，重点是通过可运行实验理解 ownership、lifetime、ABI 和 FFI，而不是堆叠孤立语法示例。

- `basics/`：按阶段递进的基础实验；目录和文件使用两位编号，如 `04-stl/02_string_view.ipynb`。
- `labs/`：验证一个具体问题的最小实验。
- `projects/`：整合 C++ Core、C ABI、cinterop/JNI 和 Kotlin API 的完整项目。
- `docs/plan/`：阶段任务与 Definition of Done；`notes/` 和 `upstream-notes/` 保存提炼后的结论。
- `upstream/`：本地第三方源码，不得提交。

新增或重命名阶段、主题目录时，同步更新该目录的 `README.md`、根 `README.md` 和对应计划。

## 实验 Notebook 规范

新增实验以较新的 RAII、`std::string` 和 `std::string_view` Notebook 为风格基准，不顺手批量改写旧实验。每份 Notebook 应：

1. 以“阶段标题 + `实验 N：主题`”开场，先说明研究问题和范围。
2. 用编号小节逐步推进；每段代码前说明观察目标，之后解释实际/预期结果。
3. 每个代码单元必须包含中文步骤注释；单元内的每个逻辑步骤也要在对应代码前说明“正在做什么、为什么这样做或要观察什么”。注释应解释意图与生命周期，不能只把语法翻译成中文。
4. 让行为可观察，例如打印构造/析构顺序、地址、容量或错误信息；失败案例优先写在 Markdown 代码块中，避免阻断整本运行。
5. 结尾总结规则、设计边界，并说明它与 Native SDK、C ABI 或 Kotlin/Native 的关系。

每个实验至少回答：如何运行、预期与实际结果、谁创建/拥有/释放资源、借用何时失效、跨 ABI/FFI 边界发生什么。图示使用简短 ASCII 数据流即可。

## C++ 风格与接口设计

使用 C++23、四空格缩进和 Allman 大括号。类型用 `PascalCase`，函数与变量用 `snake_case`，私有成员以 `_` 结尾。沿用仓库现有声明风格，如 `const std::string &name() const`。公开头文件放在 `include/`，使用 `KOTLIN_NATIVE_STUDY_...` include guard。

优先使用 RAII、`const` correctness、最小作用域和明确的 owner/borrower 语义。资源 owner 不得被无意复制；析构清理应 `noexcept`；C++ 异常不能穿过 C ABI。不要用 `using namespace std;`，也不要用未解释的 `new/delete` 替代标准容器或智能指针。

## 运行与验证

- `jupyter kernelspec list`：确认存在 `xcpp23`。
- `jupyter lab`：从仓库根目录启动实验。

提交前确认 Notebook 的 kernel 为 `xcpp23`，重启 kernel 后从上到下运行所有修改单元。检查输出顺序、失败分支和资源清理；修改公共头文件时同时验证声明、实现和调用。实验生成文件写入主题目录下的 `outputs/<实验编号>/`，不要提交二进制、缓存、checkpoint 或无关日志。仅保留能解释结论的少量 Notebook 输出。

## 提交与评审

提交标题沿用现有形式：`notes(cpp): ...`、`fix(cpp): ...`、`docs(cpp): ...`、`chore(notebooks): ...`。一次提交聚焦一个实验或一种修正。PR 需写明学习问题、改动范围、复现步骤、验证结果及相关 issue；涉及可视化结果时再附截图。

修改时保留用户未完成的 Notebook 和无关工作区变更。不要只为“更现代”而改写教学代码；每次抽象或重构都必须服务于当前实验目标。
