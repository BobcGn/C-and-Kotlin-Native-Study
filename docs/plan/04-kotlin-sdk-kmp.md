# Phase 4：Kotlin SDK Abstraction & KMP（Week 10–12）

## 目标

隔离低层 binding，通过惯用 Kotlin API 提供稳定能力，并让 JVM/Android 与 Kotlin/Native 共享公共模型。

## Week 10：Kotlin SDK 包装层

- [ ] 建立 `Public API → Adapter → Raw Binding → C ABI → C++` 分层
- [ ] 用显式 `close` 管理 native handle
- [ ] 转换 error code，防止 close 后调用和重复 close
- [ ] 建立不可变 request/response 模型

## Week 11：KMP 与 Android

- [ ] 设计 `commonMain` 和 `expect/actual`
- [ ] JVM/Android 通过 JNI 访问同一 Native Core
- [ ] 对齐 JNI 与 cinterop 的错误和 ownership 语义

## Week 12：Apple 平台

- [ ] 生成并消费 XCFramework
- [ ] 比较 Objective-C interop 与 Swift Export
- [ ] 验证 Swift/Kotlin/Native/C++ 生命周期
- [ ] 编写 Android 与 iOS 最小示例

## Definition of Done

- 业务示例不直接调用原始 C 函数。
- 公共 API 可在 common code 编译并具有契约测试。
- Android/JVM 和至少一个 Apple target 使用相同语义运行。

