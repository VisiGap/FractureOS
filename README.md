# FractureOS

一个类 Linux 操作系统，使用 Rust 构建内核，C++ 构建系统组件。

A Linux-like operating system built with Rust kernel and C++ system components.

## ✨ 特性

- **内存安全**: Rust 内核提供内存安全保证
- **高性能**: C++ 用户空间组件提供高性能
- **微内核架构**: 最小化内核，大部分功能在用户空间
- **现代设计**: 使用最新的 Rust 和 C++20 特性

## 🚀 快速开始

### 自动设置

**Windows:**
```powershell
.\setup.ps1
```

**Linux/macOS:**

```bash
# Build the kernel
cd kernel && cargo build --release

# Build system components
cd userspace && make

# Create bootable image
./tools/create-image.sh
```

## Requirements

- Rust nightly toolchain
- C++20 compatible compiler (GCC 11+ or Clang 13+)
- QEMU for testing
- NASM assembler

