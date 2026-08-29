# 上游仓库清单

`upstream/` 用来放置源码阅读、调试和问题复现所需的第三方仓库。该目录整体被 `.gitignore` 排除：本项目只提交仓库清单、固定版本和学习笔记，不重新分发上游源码。

## 当前使用

### JetBrains Skiko

- 官方仓库：<https://github.com/JetBrains/skiko>
- 个人 fork：<https://github.com/BobcGn/skiko>
- 本地目录：`upstream/skiko`
- 当前研究版本：`96378296bb23c23c5f30cd2b0d42d6f8fdeff730`
- 用途：研究 Kotlin、JNI/Kotlin Native binding、C++ 与 Skia 的调用链

从官方仓库复现：

```bash
git clone https://github.com/JetBrains/skiko.git upstream/skiko
git -C upstream/skiko checkout 96378296bb23c23c5f30cd2b0d42d6f8fdeff730
```

需要向个人 fork 推送贡献分支时，可另行添加远端：

```bash
git -C upstream/skiko remote rename origin upstream
git -C upstream/skiko remote add origin https://github.com/BobcGn/skiko.git
```

> 固定 commit 只描述已验证的源码基线。上游仓库的构建依赖和平台要求以该版本自己的 `README.md`、`DEVELOPMENT.md` 与许可证为准。

## 后续计划

下列仓库将在对应学习阶段开始时拉取；首次使用后应在本页补充实际验证过的 commit SHA、用途和初始化命令。

| 项目 | 官方仓库 | 计划研究内容 |
| --- | --- | --- |
| Kotlin | <https://github.com/JetBrains/kotlin> | Kotlin/Native runtime、interop、compiler |
| kotlinx-io | <https://github.com/Kotlin/kotlinx-io> | Buffer、Source/Sink、平台抽象 |
| LLVM | <https://github.com/llvm/llvm-project> | Clang、LLVM 与 Native toolchain |
| Skia | <https://skia.googlesource.com/skia.git> | Skiko 底层图形实现 |
| libuv | <https://github.com/libuv/libuv> | 跨平台事件循环与 Native API |
| SQLite | <https://github.com/sqlite/sqlite> | 稳定 C API 与嵌入式库设计 |

## 新增上游仓库的记录要求

每个条目至少记录：

- 官方 URL 与可选 fork URL
- 本地目录和研究目的
- 验证过的 commit SHA 或 tag
- clone、checkout 和 submodule 初始化命令
- 上游许可证位置
- 对应的 `upstream-notes/` 文档

不要把上游源码、其构建产物或对上游工作树的临时修改提交到本仓库。
