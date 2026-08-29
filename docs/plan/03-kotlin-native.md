# Phase 3：Kotlin/Native Interop（Week 7–9）

## 目标

让 Kotlin/Native 通过 cinterop 安全调用 Native SDK，并明确 Kotlin GC 与 Native resource lifetime 的关系。

## Week 7：建立绑定

- [ ] 创建 Kotlin Multiplatform/Native 工程
- [ ] 编写 `.def` 并配置 headers、compilerOpts、linkerOpts
- [ ] 生成 binding，调用并链接 native library
- [ ] 检查 Kotlin 与 C 类型映射

## Week 8：数据与内存

- [ ] 使用 `CPointer`、`CValue`、`memScoped`、`nativeHeap`
- [ ] 完成 Kotlin String/ByteArray 与 C string/buffer 转换
- [ ] 验证 nullability、边界长度和错误输入
- [ ] 实验 caller-owned、callee-owned、borrowed memory

## Week 9：对象与 callback

- [ ] 封装 opaque handle 生命周期
- [ ] 使用 `StableRef` 携带 Kotlin user data
- [ ] 覆盖同步/异步 callback 及线程行为
- [ ] 添加泄漏、use-after-free、callback-after-close 测试

## Definition of Done

- Native target 可从零构建并运行。
- 所有跨边界资源都有唯一、可测试的释放路径。
- callback 不依赖偶然的 GC 行为维持有效性。

