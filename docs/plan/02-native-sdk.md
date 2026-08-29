# Phase 2：Native SDK Engineering（Week 4–6）

## 目标

把 C++ 实现封装成可供其他语言消费的 Native SDK，理解 API、ABI、符号、对象布局和 allocator boundary。

## Week 4：库与符号

- [ ] 生成 static/shared library 与独立 consumer
- [ ] 使用 `nm`、`otool`/`ldd` 检查符号和依赖
- [ ] 比较 C 与 C++ name mangling
- [ ] 隐藏内部符号，只导出公共 API

## Week 5：稳定 C ABI

- [ ] 用 `extern "C"` 和 opaque handle 隔离实现
- [ ] 定义字符串、buffer、callback 与 user data 接口
- [ ] 标注所有指针的所有权、可空性、有效期和释放方
- [ ] 设计 error code 模型，禁止异常穿越 ABI
- [ ] 验证 allocator boundary

## Week 6：ABI 兼容实验

- [ ] 构建 SDK/consumer v1
- [ ] 修改 struct/class layout、函数签名和符号
- [ ] 让旧 consumer 加载新 library 并记录证据
- [ ] 对比 opaque handle 方案
- [ ] 制定版本和兼容策略

## Definition of Done

- C 与 C++ consumer 使用同一份 C header。
- SDK v2 在约定范围内兼容 v1 consumer。
- API 文档明确 ownership、thread safety 与 error contract。

