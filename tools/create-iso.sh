#!/bin/bash
# Create bootable ISO image for FractureOS

set -e

BUILD_DIR="build"
ISO_DIR="$BUILD_DIR/iso"
GRUB_DIR="$ISO_DIR/boot/grub"

echo "Creating FractureOS ISO..."

# Create directories
mkdir -p "$GRUB_DIR"

# Copy kernel
cp "$BUILD_DIR/kernel.bin" "$ISO_DIR/boot/"

# Create GRUB config
cat > "$GRUB_DIR/grub.cfg" << EOF
set timeout=0
set default=0

menuentry "FractureOS" {
    multiboot2 /boot/kernel.bin
    boot
}
EOF

# Create ISO
grub-mkrescue -o "$BUILD_DIR/fractureos.iso" "$ISO_DIR"

echo "ISO created: $BUILD_DIR/fractureos.iso"
