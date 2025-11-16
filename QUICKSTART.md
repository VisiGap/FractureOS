# FractureOS 快速入门

欢迎来到 FractureOS！这是一个使用 Rust 构建内核、C++ 构建系统组件的类 Linux 操作系统。

## 🚀 快速开始

### Windows 用户

1. **运行自动设置脚本**
   ```powershell
   .\setup.ps1
   ```

2. **构建内核**
   ```powershell
   cd kernel
   cargo build --release
   ```

### Linux/macOS 用户

1. **运行自动设置脚本**
   ```bash
   chmod +x setup.sh
   ./setup.sh
   ```

2. **构建内核**
   ```bash
   cd kernel
   cargo build --release
   ```

## 📋 手动设置（如果自动脚本失败）

### 1. 安装 Rust Nightly

```bash
rustup default nightly
rustup component add rust-src llvm-tools-preview rustfmt clippy
rustup target add x86_64-unknown-none
```

### 2. 安装构建工具

**Windows (使用 Chocolatey):**
```powershell
choco install nasm qemu make
```

**Ubuntu/Debian:**
```bash
sudo apt install build-essential nasm qemu-system-x86
```

**macOS:**
```bash
brew install nasm qemu
```

## 🏗️ 项目结构

```
FractureOS/
├── kernel/              # Rust 内核
│   ├── src/            # 内核源代码
│   │   ├── lib.rs      # 内核入口
│   │   ├── vga.rs      # VGA 显示
│   │   ├── serial.rs   # 串口通信
│   │   ├── gdt.rs      # 全局描述符表
│   │   ├── interrupts.rs # 中断处理
│   │   ├── memory.rs   # 内存管理
│   │   └── allocator.rs # 堆分配器
│   └── Cargo.toml      # Rust 配置
├── userspace/          # C++ 用户空间
│   ├── init/           # Init 进程
│   └── shell/          # Shell
├── boot/               # 引导加载程序
├── lib/                # 共享库
│   └── libfracture/    # 系统库
└── docs/               # 文档
```

## 🔧 开发工作流

### 构建整个项目
```bash
make all
```

### 只构建内核
```bash
cd kernel
cargo build --release
```

### 只构建用户空间
```bash
make userspace
```

### 运行测试
```bash
cd kernel
cargo test
```

### 在 QEMU 中运行
```bash
make run
```

## 📚 文档

- **[SETUP.md](docs/SETUP.md)** - 详细设置指南
- **[BUILD.md](docs/BUILD.md)** - 构建说明
- **[ARCHITECTURE.md](docs/ARCHITECTURE.md)** - 系统架构
- **[CONTRIBUTING.md](docs/CONTRIBUTING.md)** - 贡献指南
- **[ROADMAP.md](docs/ROADMAP.md)** - 开发路线图

## 🐛 常见问题

### 问题：找不到 `core` crate
**解决方案：**
```bash
rustup component add rust-src
```

### 问题：rust-analyzer 报错
**解决方案：** 确保 `.vscode/settings.json` 已正确配置，或重启 VS Code。

### 问题：链接器错误
**解决方案：** 确保使用自定义目标 `x86_64-unknown-none.json`。

### 问题：QEMU 无法启动
**解决方案：** 确保 QEMU 已安装并在 PATH 中。

## 💡 下一步

1. 阅读 [ARCHITECTURE.md](docs/ARCHITECTURE.md) 了解系统设计
2. 查看 [ROADMAP.md](docs/ROADMAP.md) 了解开发计划
3. 开始贡献！查看 [CONTRIBUTING.md](docs/CONTRIBUTING.md)

## 📞 获取帮助

- 查看 `docs/` 目录中的文档
- 检查 GitHub Issues
- 阅读代码注释

## 📄 许可证

MIT License - 详见 [LICENSE](LICENSE) 文件

---

**祝你编码愉快！** 🎉
