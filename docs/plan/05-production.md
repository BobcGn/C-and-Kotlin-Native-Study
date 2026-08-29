# Phase 5：Production Engineering（持续进行）

## 目标

把 Demo 提升为可诊断、可兼容、可发布的 SDK。本阶段从 Native SDK 出现后持续执行。

## 任务

- [ ] C++ unit test、C ABI contract test
- [ ] Kotlin common test 与平台 integration test
- [ ] 跨版本 ABI compatibility test
- [ ] ASan、UBSan、TSan 和静态分析任务
- [ ] LLDB 调试手册与 crash symbolication
- [ ] benchmark 基线和回归阈值
- [ ] CI 覆盖主要 host/target
- [ ] API reference、示例和 migration guide
- [ ] Semantic Versioning、CHANGELOG、release checklist
- [ ] artifact 校验、许可证和发布说明

## Definition of Done

- CI 从干净 checkout 构建、测试并运行诊断任务。
- release artifact 由版本化流程产生，示例只依赖发布产物。
- ABI/API 破坏能在合并前被检测。
- 新使用者仅凭公开文档可以完成集成。

