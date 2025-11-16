# FractureOS 快速设置指南

## 1. 安装 Rust 工具链

```bash
# 安装 Rust（如果还没有）
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

# 切换到 nightly 版本
rustup default nightly

# 安装必要组件
rustup component add rust-src llvm-tools-preview rustfmt clippy

# 安装 x86_64 目标（可选，我们使用自定义目标）
rustup target add x86_64-unknown-none
```

## 2. 安装构建工具

### Windows
```powershell
# 使用 Chocolatey
choco install nasm qemu make

# 或使用 Scoop
scoop install nasm qemu make
```

### Linux (Ubuntu/Debian)
```bash
sudo apt update
sudo apt install build-essential nasm qemu-system-x86 grub-pc-bin xorriso
```

### macOS
```bash
brew install nasm qemu i686-elf-gcc
```

## 3. 验证安装

```bash
# 检查 Rust
rustc --version
cargo --version

# 检查 nightly
rustup show

# 检查组件
rustup component list | grep installed

# 检查 NASM
nasm -v

# 检查 QEMU
qemu-system-x86_64 --version
```

## 4. 构建项目

```bash
# 进入内核目录
cd kernel

# 构建内核
cargo build --release

# 如果遇到问题，尝试清理后重新构建
cargo clean
cargo build --release
```

## 5. 常见问题

### 问题：找不到 core crate
**解决方案**：
```bash
rustup component add rust-src
```

### 问题：链接器错误
**解决方案**：确保使用自定义目标文件 `x86_64-unknown-none.json`

### 问题：QEMU 无法运行
**解决方案**：
- Windows: 确保 QEMU 在 PATH 中
- Linux: 安装 `qemu-system-x86`
- macOS: 使用 `brew install qemu`

## 6. 开发环境推荐

### VS Code 扩展
- rust-analyzer
- C/C++ (Microsoft)
- x86 and x86_64 Assembly
- EditorConfig

### 配置 rust-analyzer
在 `.vscode/settings.json` 中添加：
```json
{
    "rust-analyzer.cargo.target": "x86_64-unknown-none.json",
    "rust-analyzer.checkOnSave.allTargets": false
}
```

## 7. 下一步

查看 `docs/BUILD.md` 了解详细构建说明。
