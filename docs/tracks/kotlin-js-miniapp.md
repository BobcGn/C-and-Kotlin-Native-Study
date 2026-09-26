# Kotlin/JS → MiniApp Track

## Goal

能够独立解释并 Debug 以下链路：

```text
Kotlin Source
→ Gradle
→ Kotlin Compiler
→ Kotlin/JS
→ Generated JS
→ Link / Bundle
→ MiniApp Artifact
→ WeChat Runtime
```

## Stage 1 — Build / Artifact Observation

选择并固定真实项目和环境；记录构建命令、Gradle task graph、构建产物位置、Generated JS、最终 MiniApp Artifact，并建立可重复的 baseline。

## Stage 2 — Compiler Mapping

从 Stage 1 的真实构建对象出发，将 Traditional Compiler Concepts 与 Kotlin Compiler Reality 对照，逐步观察 Frontend、FIR、IR、Backend 和 Code Generation。每次研究都对应真实输入、产物或可定位源码。

## Stage 3 — KJS Bottleneck

```text
Observed Problem
→ Baseline
→ Hypothesis
→ Experiment
→ Root Cause
→ Change
→ Measurement
→ Trade-off
```

当前 bottleneck：**UNVERIFIED**。在建立基线并验证假设前，不预填根因或优化方向。

## Definition of Done

用户能够独立解释编译构建链、基于当前证据定位问题最早可观察的异常阶段、设计并复现实验、完成 Debug，并用证据支持结论。优化数量或构建成功本身不构成完成。
