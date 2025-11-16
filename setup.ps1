# FractureOS Setup Script for Windows
# Run this script to set up the development environment

Write-Host "Setting up FractureOS development environment..." -ForegroundColor Green

# Check if Rust is installed
Write-Host "`nChecking Rust installation..." -ForegroundColor Yellow
if (Get-Command rustc -ErrorAction SilentlyContinue) {
    $rustVersion = rustc --version
    Write-Host "✓ Rust is installed: $rustVersion" -ForegroundColor Green
} else {
    Write-Host "✗ Rust is not installed" -ForegroundColor Red
    Write-Host "Please install Rust from: https://rustup.rs/" -ForegroundColor Yellow
    exit 1
}

# Switch to nightly
Write-Host "`nSwitching to Rust nightly..." -ForegroundColor Yellow
rustup default nightly

# Install required components
Write-Host "`nInstalling Rust components..." -ForegroundColor Yellow
rustup component add rust-src
rustup component add llvm-tools-preview
rustup component add rustfmt
rustup component add clippy

# Add x86_64 target
Write-Host "`nAdding x86_64-unknown-none target..." -ForegroundColor Yellow
rustup target add x86_64-unknown-none

# Check for NASM
Write-Host "`nChecking for NASM..." -ForegroundColor Yellow
if (Get-Command nasm -ErrorAction SilentlyContinue) {
    $nasmVersion = nasm -v
    Write-Host "✓ NASM is installed: $nasmVersion" -ForegroundColor Green
} else {
    Write-Host "✗ NASM is not installed" -ForegroundColor Red
    Write-Host "Install with: choco install nasm" -ForegroundColor Yellow
}

# Check for QEMU
Write-Host "`nChecking for QEMU..." -ForegroundColor Yellow
if (Get-Command qemu-system-x86_64 -ErrorAction SilentlyContinue) {
    Write-Host "✓ QEMU is installed" -ForegroundColor Green
} else {
    Write-Host "✗ QEMU is not installed" -ForegroundColor Red
    Write-Host "Install with: choco install qemu" -ForegroundColor Yellow
}

# Check for Make
Write-Host "`nChecking for Make..." -ForegroundColor Yellow
if (Get-Command make -ErrorAction SilentlyContinue) {
    Write-Host "✓ Make is installed" -ForegroundColor Green
} else {
    Write-Host "✗ Make is not installed" -ForegroundColor Red
    Write-Host "Install with: choco install make" -ForegroundColor Yellow
}

Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "Setup complete!" -ForegroundColor Green
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "`nNext steps:" -ForegroundColor Yellow
Write-Host "1. cd kernel" -ForegroundColor White
Write-Host "2. cargo build --release" -ForegroundColor White
Write-Host "`nFor more information, see docs/SETUP.md" -ForegroundColor Yellow
