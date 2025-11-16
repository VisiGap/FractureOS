#!/bin/bash
# FractureOS Setup Script for Linux/macOS
# Run this script to set up the development environment

set -e

echo "Setting up FractureOS development environment..."

# Colors
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Check if Rust is installed
echo -e "\n${YELLOW}Checking Rust installation...${NC}"
if command -v rustc &> /dev/null; then
    RUST_VERSION=$(rustc --version)
    echo -e "${GREEN}✓ Rust is installed: $RUST_VERSION${NC}"
else
    echo -e "${RED}✗ Rust is not installed${NC}"
    echo -e "${YELLOW}Installing Rust...${NC}"
    curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
    source "$HOME/.cargo/env"
fi

# Switch to nightly
echo -e "\n${YELLOW}Switching to Rust nightly...${NC}"
rustup default nightly

# Install required components
echo -e "\n${YELLOW}Installing Rust components...${NC}"
rustup component add rust-src
rustup component add llvm-tools-preview
rustup component add rustfmt
rustup component add clippy

# Add x86_64 target
echo -e "\n${YELLOW}Adding x86_64-unknown-none target...${NC}"
rustup target add x86_64-unknown-none

# Check for NASM
echo -e "\n${YELLOW}Checking for NASM...${NC}"
if command -v nasm &> /dev/null; then
    NASM_VERSION=$(nasm -v)
    echo -e "${GREEN}✓ NASM is installed: $NASM_VERSION${NC}"
else
    echo -e "${RED}✗ NASM is not installed${NC}"
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        echo -e "${YELLOW}Install with: sudo apt install nasm${NC}"
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        echo -e "${YELLOW}Install with: brew install nasm${NC}"
    fi
fi

# Check for QEMU
echo -e "\n${YELLOW}Checking for QEMU...${NC}"
if command -v qemu-system-x86_64 &> /dev/null; then
    echo -e "${GREEN}✓ QEMU is installed${NC}"
else
    echo -e "${RED}✗ QEMU is not installed${NC}"
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        echo -e "${YELLOW}Install with: sudo apt install qemu-system-x86${NC}"
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        echo -e "${YELLOW}Install with: brew install qemu${NC}"
    fi
fi

# Check for Make
echo -e "\n${YELLOW}Checking for Make...${NC}"
if command -v make &> /dev/null; then
    echo -e "${GREEN}✓ Make is installed${NC}"
else
    echo -e "${RED}✗ Make is not installed${NC}"
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        echo -e "${YELLOW}Install with: sudo apt install build-essential${NC}"
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        echo -e "${YELLOW}Install with: xcode-select --install${NC}"
    fi
fi

echo -e "\n========================================"
echo -e "${GREEN}Setup complete!${NC}"
echo -e "========================================\n"
echo -e "${YELLOW}Next steps:${NC}"
echo -e "${NC}1. cd kernel${NC}"
echo -e "${NC}2. cargo build --release${NC}"
echo -e "\n${YELLOW}For more information, see docs/SETUP.md${NC}"
