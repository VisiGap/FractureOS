# FractureOS 快速开始指南

## 5 分钟快速上手

### 第一步：安装依赖

**Windows (PowerShell 管理员模式):**
```powershell
# 运行自动设置脚本
.\setup.ps1
```

**Linux/macOS:**
```bash
# 运行自动设置脚本
chmod +x setup.sh
./setup.sh
```

### 第二步：构建内核

```bash
cd kernel
cargo build --release
```

### 第三步：测试

```bash
# 运行测试
cargo test

# 检查代码
cargo clippy
cargo fmt --check
```

## 项目结构速览

```
FractureOS/
├── kernel/              # Rust 内核
│   ├── src/
│   │   ├── lib.rs      # 内核入口
│   │   ├── vga.rs      # VGA 驱动
│   │   ├── serial.rs   # 串口驱动
│   │   ├── gdt.rs      # 全局描述符表
│   │   ├── interrupts.rs # 中断处理
│   │   ├── memory.rs   # 内存管理
│   │   └── allocator.rs # 堆分配器
│   └── Cargo.toml
│
├── userspace/           # C++ 用户空间
│   ├── init/           # Init 进程
│   └── shell/          # Shell
│
├── lib/                # 系统库
│   └── libfracture/
│       └── include/
│           ├── types.h    # 基础类型
│           ├── syscall.h  # 系统调用
│           ├── process.h  # 进程管理
│           ├── memory.h   # 内存管理
│           ├── string.h   # 字符串
│           └── io.h       # I/O 操作
│
├── boot/               # 引导加载器
│   └── boot.asm
│
└── docs/               # 文档
```

## 核心概念

### 1. 内核 (Rust)
- **内存安全**: 利用 Rust 的所有权系统
- **零成本抽象**: 高性能的抽象
- **无运行时**: 完全 no_std 环境

### 2. 用户空间 (C++)
- **Freestanding**: 不依赖标准库
- **C++20**: 使用现代 C++ 特性
- **系统调用**: 通过 libfracture 与内核交互

### 3. 系统调用接口
```cpp
// 示例：写入数据
#include "syscall.h"
fracture::syscall::write(1, "Hello\n", 6);

// 示例：创建进程
#include "process.h"
auto pid = fracture::process::Process::fork();
```

## 常用命令

```bash
# 构建所有组件
make all

# 只构建内核
cd kernel && cargo build --release

# 只构建用户空间
make userspace

# 清理构建产物
make clean

# 运行 (需要 QEMU)
make run

# 创建 ISO 镜像
make iso
```

## 开发工作流

1. **修改代码**
2. **格式化**: `cargo fmt` (Rust) 或使用 clang-format (C++)
3. **检查**: `cargo clippy`
4. **构建**: `cargo build`
5. **测试**: `cargo test`
6. **提交**: Git commit

## 调试技巧

### 使用串口输出
```rust
// 在内核中
serial_println!("Debug: value = {}", value);
```

### 使用 QEMU 调试
```bash
# 启动 QEMU 并等待 GDB
qemu-system-x86_64 -s -S -drive format=raw,file=build/fractureos.img

# 在另一个终端
gdb build/kernel.elf
(gdb) target remote :1234
(gdb) break _start
(gdb) continue
```

## 常见问题

**Q: 编译错误 "can't find crate for `core`"**
A: 运行 `rustup component add rust-src`

**Q: 链接错误**
A: 确保使用正确的目标配置 `x86_64-unknown-none.json`

**Q: C++ 找不到头文件**
A: 检查 `.vscode/c_cpp_properties.json` 中的 includePath

**Q: QEMU 无法运行**
A: 确保 QEMU 已安装并在 PATH 中

## 下一步

- 📖 阅读 [架构文档](ARCHITECTURE.md)
- 🔨 查看 [构建指南](BUILD.md)
- 🗺️ 了解 [开发路线图](ROADMAP.md)
- 🤝 参与 [贡献](CONTRIBUTING.md)

## 获取帮助

- 查看文档目录 `docs/`
- 阅读代码注释
- 参考 Rust 和 C++ 最佳实践

---

**祝你开发愉快！** 🚀
