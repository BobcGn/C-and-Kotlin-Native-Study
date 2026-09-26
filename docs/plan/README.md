# 学习计划总览

七个 Phase 表达 Native / ABI dependency roadmap。Cross-cutting Track 可以跨 Phase 推进；Production 从 Phase 2 开始持续补强，不必等到最后才进行。

## Cross-cutting Learning Tracks

**Phase** 表示既有 Native 学习依赖路线；**Track** 表示可以跨 Phase 推进的实际研究路径。Track 不会新增或替代 Phase。

- **Shared Fundamentals**：C/C++、Compiler、Build、Debugging、Runtime、OS / Architecture，为各实践路径提供共用概念和诊断能力。
- **Native / ABI Track**：Phase 1–4 是主要承载，从现代 C++、Native Library 与 C ABI 到 Kotlin/Native、KMP；Phase 5–7 提供生产和上游延伸。
- **Kotlin/JS / MiniApp Track**：近期实践路径，观察 Kotlin Source 经 Gradle、Kotlin Compiler、Kotlin/JS、Generated JS、Link / Bundle、MiniApp Artifact 到 WeChat Runtime 的变化。当前问题与瓶颈尚未验证；见 [`Kotlin/JS → MiniApp Track`](../tracks/kotlin-js-miniapp.md)。
- **Production / Evidence Track**：跨路径推进 Testing、Benchmark、Compatibility、Release，并以可复现实验和运行证据支持结论。

这些 Track 共享基础，但不要求串行完成，也不代表同等成熟度。先从真实问题和已有证据选择下一步。

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
