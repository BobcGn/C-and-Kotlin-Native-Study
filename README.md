# KotlinNativeStudy

一个可复现、持续演进的 Kotlin/Native 与 Native SDK 工程学习仓库。学习主线从现代 C++ 出发，经过 C ABI、FFI 和 Kotlin/Native，最终落到 Kotlin Multiplatform SDK、生产工程与上游开源贡献。

> 当前进度：Phase 1（现代 C/C++）。引用与生命周期、类与对象、RAII，以及第四部分 STL ownership/API contract 实验已经完成；智能指针、移动语义、并发和工具链仍是后续工作，详细任务见 [`docs/plan`](docs/plan/README.md)。

## 学习主线

```text
Modern C/C++ → Native Library → Stable C ABI → Kotlin/Native cinterop
      → Idiomatic Kotlin API → Kotlin Multiplatform → Production SDK
      → Upstream Source Study → Open-source Contribution
```

最终要能够独立设计并解释下面的技术链路：

```text
                         ┌── JNI ─────── JVM / Android
C++ Core → Stable C ABI ─┤
                         └── cinterop ── Kotlin/Native ── KMP / iOS
```

## 快速开始

### 1. 获取仓库

```bash
git clone <本仓库的 GitHub URL>
cd KotlinNativeStudy
```

### 2. 准备环境

当前实验以 macOS + Clang 为主要验证环境。Linux 也可运行 C++ 实验，只需将 `clang++` 替换为支持 C++23 的编译器。

必需工具：

- Git
- Clang 16+（或兼容 C++23 的 GCC）
- JupyterLab
- `xeus-cling`，并提供名为 `xcpp23` 的 C++23 kernel

使用 Conda/Mamba 安装笔记环境：

```bash
conda create -n kotlin-native-study -c conda-forge jupyterlab xeus-cling
conda activate kotlin-native-study
jupyter kernelspec list
```

输出中应包含 `xcpp23`。随后在仓库根目录启动：

```bash
jupyter lab
```

从 [`basics/01-cpp`](basics/01-cpp/) 选择编号主题目录，确认 kernel 为 **C++23**，再按文件编号和单元顺序执行。C++ Jupyter kernel 会保留已执行的声明；修改并重复执行函数定义时若出现 `redefinition`，请重启 kernel 后从头执行。

### 3. 运行已有 C++ 实验

当前 C++ 实验使用 C++23 Notebook。每个实验从一个可观察问题出发，通过代码输出、断言和失败案例解释 ownership、lifetime 以及 ABI 边界。主题目录的 `README.md` 记录实验顺序与验收要求；公开接口示例放在相邻 `include/` 中。

### 4. 推荐学习顺序

1. 依次运行 `01-reference-const` 中的四个 Jupyter 笔记。
2. 依次运行 `02-class-object` 中的六个 Jupyter 笔记，并在实验 6 练习分离编译。
3. 依次运行 `03-raii`，从手动清理推进到可复用资源 owner。
4. 依次运行 [`04-stl`](basics/01-cpp/04-stl/README.md)，完成类型语义与 C ABI 翻译验收。
5. 按 [`docs/plan/01-modern-cpp.md`](docs/plan/01-modern-cpp.md) 继续补齐智能指针、移动语义、并发和工具链。
6. 通过阶段计划中的验收条件后，再进入下一阶段。

## 当前目录结构

此树描述当前仓库以及已经预留的工作区；新增内容时必须同步更新本节。

```text
KotlinNativeStudy/
├── README.md                         # 项目入口、环境与复现说明
├── .gitignore                        # 本地环境、构建产物和上游源码规则
├── docs/
│   ├── upstream.md                   # 上游仓库清单与复现方式
│   └── plan/                         # 分阶段学习计划与验收标准
│       ├── README.md                 # 总览、阶段依赖与进度表
│       ├── 01-modern-cpp.md          # Week 1–3
│       ├── 02-native-sdk.md          # Week 4–6
│       ├── 03-kotlin-native.md       # Week 7–9
│       ├── 04-kotlin-sdk-kmp.md      # Week 10–12
│       ├── 05-production.md          # 生产化工程
│       ├── 06-upstream-study.md      # Week 13–16
│       └── 07-contribution.md        # 上游贡献闭环
├── basics/
│   ├── 01-cpp/
│   │   ├── 01-reference-const/       # 4 个 C++23 笔记与生命周期反例
│   │   ├── 02-class-object/          # 类、构造析构、栈堆、分离编译
│   │   ├── 03-raii/                  # 文件资源、作用域、提前返回、异常安全
│   │   ├── 04-stl/                   # 容器、视图、结果状态与 SDK API contract
│   │   ├── 05-smart-pointer/         # 预留：智能指针
│   │   ├── 06-move-semantics/        # 预留：移动语义
│   │   └── 07-threading/             # 预留：并发与内存模型
│   ├── 02-libraries/                 # 预留：静态库、动态库、符号、C ABI
│   ├── 03-kotlin_native/             # 预留：cinterop 基础实验
│   ├── 04-mini_sdk/                  # 预留：Native/Kotlin SDK 主线项目
│   └── notes/                        # C/C++、ABI、ownership、cinterop 笔记
├── labs/                              # 独立、单一问题的实验
├── notes/                             # 跨阶段整理后的知识笔记
├── projects/                          # 完整项目工作区
├── upstream/                          # 外部源码（被 Git 忽略）
└── upstream-notes/                    # 上游源码阅读记录
```

目录约定：`basics/` 用于循序练习，`labs/` 用于验证单个问题，`projects/` 用于整合完整 SDK；克隆的第三方源码放进 `upstream/`，研究结论则写入可提交的 `upstream-notes/`。

需要拉取的第三方源码、版本和命令统一记录在 [`docs/upstream.md`](docs/upstream.md)，不会直接收录进本仓库。

## 阶段计划

| 阶段 | 周期 | 核心产出 |
| --- | --- | --- |
| [Phase 1：Modern C/C++](docs/plan/01-modern-cpp.md) | Week 1–3 | 生命周期、RAII、STL、并发与工具链实验 |
| [Phase 2：Native SDK](docs/plan/02-native-sdk.md) | Week 4–6 | 动静态库、稳定 C ABI、ABI 破坏实验 |
| [Phase 3：Kotlin/Native](docs/plan/03-kotlin-native.md) | Week 7–9 | cinterop、内存、字符串与 callback |
| [Phase 4：Kotlin SDK & KMP](docs/plan/04-kotlin-sdk-kmp.md) | Week 10–12 | Kotlin 包装层、JNI、XCFramework |
| [Phase 5：Production](docs/plan/05-production.md) | 持续 | 测试、Sanitizer、CI、版本与发布 |
| [Phase 6：Upstream Study](docs/plan/06-upstream-study.md) | Week 13–16 | Skiko、kotlinx-io、Kotlin/Native 调用链笔记 |
| [Phase 7：Contribution](docs/plan/07-contribution.md) | 后续 | 一次完整的 upstream contribution |

每阶段的任务、实验、成果物和 Definition of Done 均在对应文档中维护。

## 实验记录规范

每个实验至少回答：

- 研究问题是什么？
- 如何构建和运行？
- 预期与实际结果是什么？
- 资源由谁创建、持有和释放？
- 跨 ABI/FFI 边界时发生了什么？
- 有哪些失败案例及诊断证据？

生成的二进制、缓存、Jupyter checkpoint 和上游仓库不提交；源码、笔记、少量可解释的输出和复现命令应提交。

## 总体验收目标

完成路线后，应能够解释 API 与 ABI 的差异、C ABI 的稳定性价值、FFI ownership 与 callback 生命周期，并独立实现由 C++ Core、C ABI、JNI/cinterop 和 Kotlin Multiplatform API 组成的可测试、可发布 SDK。
