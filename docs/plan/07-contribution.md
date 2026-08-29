# Phase 7：Open-source Contribution

## 目标

完成一次真实的上游工程闭环。第一次贡献优先选择文档、测试、构建、互操作、平台兼容或范围清晰的小型 bug。

## 任务流

1. **Find**：筛选与已有研究相关且仍接受贡献的问题。
2. **Reproduce**：固定 commit、环境、命令、预期与实际结果。
3. **Locate**：沿调用链定位责任层。
4. **Understand**：记录 root cause、ownership、线程和兼容约束。
5. **Discuss**：需要设计确认时先与维护者沟通。
6. **Fix**：做最小且符合项目风格的变更。
7. **Test**：覆盖回归测试和相关平台。
8. **Submit**：准备清晰 commit/PR 并响应 review。
9. **Reflect**：无论是否合并，都总结结果和后续行动。

调查记录至少包含 Problem、Environment/Commit、Reproduction、Expected/Actual、Call Chain、Root Cause、Solution、Tests、Discussion 和 Result。

## Definition of Done

- 第三方能按调查记录复现。
- fix 包含上游可接受的自动化验证。
- 完成 issue/PR 沟通；未合并时记录明确原因。
- 将结论反馈到本仓库的 SDK 设计或测试。
