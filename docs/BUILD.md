# Building FractureOS

## Prerequisites

### Required Tools

1. **Rust Toolchain**
   ```bash
   curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
   rustup default nightly
   rustup component add rust-src
   rustup component add llvm-tools-preview
   cargo install bootimage
   ```

2. **C++ Compiler**
   - GCC 11+ or Clang 13+
   - Must support C++20

3. **Build Tools**
   ```bash
   # Ubuntu/Debian
   sudo apt install build-essential nasm qemu-system-x86 grub-pc-bin xorriso

   # Arch Linux
   sudo pacman -S base-devel nasm qemu grub xorriso

   # macOS
   brew install nasm qemu i686-elf-gcc
   ```

## Building

### Full Build
```bash
make all
```

### Individual Components

**Kernel only:**
```bash
cd kernel
cargo build --release
```

**Userspace only:**
```bash
make userspace
```

**Bootloader:**
```bash
make boot
```

## Running

### QEMU
```bash
make run
```

### With KVM acceleration (Linux)
```bash
qemu-system-x86_64 -enable-kvm -drive format=raw,file=build/fractureos.img
```

### Create ISO
```bash
make iso
```

## Testing

```bash
cd kernel
cargo test
```

## Debugging

### GDB
```bash
qemu-system-x86_64 -s -S -drive format=raw,file=build/fractureos.img &
gdb build/kernel.elf
(gdb) target remote :1234
(gdb) continue
```

## Troubleshooting

**Issue**: Rust nightly not found
**Solution**: Run `rustup update nightly`

**Issue**: Bootimage fails
**Solution**: Ensure `llvm-tools-preview` is installed

**Issue**: QEMU not found
**Solution**: Install QEMU for your platform
