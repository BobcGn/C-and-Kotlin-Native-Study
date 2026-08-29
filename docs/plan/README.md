# 学习计划总览

本目录把项目总目标拆成七个可交付阶段。各阶段按依赖顺序推进；生产工程从 Phase 2 开始持续补强，不必等到最后才进行。

| 阶段 | 建议周期 | 状态 | 退出条件 |
| --- | --- | --- | --- |
| [1. Modern C/C++](01-modern-cpp.md) | Week 1–3 | 进行中 | 能构建、调试并解释一个现代 C++ 小型库 |
| [2. Native SDK](02-native-sdk.md) | Week 4–6 | 未开始 | 提供版本化、可测试的稳定 C ABI |
| [3. Kotlin/Native](03-kotlin-native.md) | Week 7–9 | 未开始 | Kotlin/Native 能安全调用 Native SDK |
| [4. Kotlin SDK & KMP](04-kotlin-sdk-kmp.md) | Week 10–12 | 未开始 | 公共 Kotlin API 屏蔽底层 binding |
| [5. Production](05-production.md) | 持续 | 未开始 | 测试、诊断、CI 和发布链路完整 |
| [6. Upstream Study](06-upstream-study.md) | Week 13–16 | 未开始 | 完成真实项目调用链研究 |
| [7. Contribution](07-contribution.md) | 后续 | 未开始 | 完成一次可追踪的上游贡献闭环 |

## 执行规则

1. 每个任务产出源码、测试或笔记，不以“看完资料”作为完成标准。
2. 每个实验保留从干净 checkout 开始的构建与运行命令。
3. 正反例都要记录，未定义行为明确标注并使用 Sanitizer 验证。
4. 满足阶段文档的 Definition of Done 后才更新状态。
5. 目录、依赖或运行方法变化时，同步更新根目录 README。

建议每周投入 8–10 小时：4 小时主线编码、2 小时系统知识、2 小时源码阅读、1 小时调试/性能工具、1 小时整理笔记。

