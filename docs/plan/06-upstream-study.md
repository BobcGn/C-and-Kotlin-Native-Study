# Phase 6：Upstream Study（Week 13–16）

## 目标

以具体问题为入口阅读工业项目，形成可核查的调用链、ownership 和构建分析，而不是试图通读整个代码库。

## Week 13–14：Skiko

- [ ] 选择一个从 Kotlin API 到 Skia 的最小功能
- [ ] 追踪 Kotlin → JNI/Kotlin Native → binding → C++ → Skia
- [ ] 记录文件、函数、commit hash 和 build target
- [ ] 标注线程、错误处理与资源生命周期
- [ ] 用调试器或日志验证关键跳转

## Week 15：kotlinx-io

- [ ] 研究 Buffer/Source/Sink 公共 API
- [ ] 对比 common abstraction 与 native implementation
- [ ] 分析内存、边界检查和错误传播

## Week 16：Kotlin/Native

- [ ] 选择 cinterop 或 runtime 的具体问题
- [ ] 定位 compiler/runtime 入口与数据结构
- [ ] 记录相关 LLVM/libclang 接入点
- [ ] 构建或运行最小相关测试

第三方仓库放在被忽略的 `upstream/`；研究成果放在 `upstream-notes/<project>/`。笔记应包含问题、commit、复现、调用链、ownership、线程、结论和未决问题。

## Definition of Done

- 完成 Skiko、kotlinx-io、Kotlin/Native 各一篇问题驱动笔记。
- 关键结论可链接到源码位置或调试证据。
- 本地重现至少一条完整跨语言调用链。

