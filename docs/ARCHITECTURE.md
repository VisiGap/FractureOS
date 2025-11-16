# FractureOS Architecture

## Overview

FractureOS is a microkernel-based operating system combining Rust's memory safety for the kernel with C++'s performance for system utilities.

## System Architecture

### Kernel Layer (Rust)
- **Memory Management**: Page-based virtual memory with demand paging
- **Process Management**: Lightweight process scheduling with priority queues
- **IPC**: Message-passing between processes
- **Device Drivers**: Minimal drivers in kernel space
- **System Calls**: Fast syscall interface (SYSCALL/SYSRET)

### System Layer (C++)
- **Init System**: First userspace process, manages system services
- **Shell**: Command-line interface
- **VFS**: Virtual filesystem abstraction
- **Device Manager**: Userspace device management
- **Network Stack**: TCP/IP implementation

## Memory Layout

```
0x0000000000000000 - 0x00007FFFFFFFFFFF: User space
0xFFFF800000000000 - 0xFFFF807FFFFFFFFF: Physical memory mapping
0xFFFF808000000000 - 0xFFFFFFFFFFFFFFFF: Kernel space
```

## Boot Process

1. BIOS/UEFI loads bootloader
2. Bootloader enters protected mode
3. Bootloader loads kernel into memory
4. Kernel initializes GDT, IDT, paging
5. Kernel starts init process
6. Init spawns system services

## System Calls

System calls use the SYSCALL instruction on x86_64:
- RAX: syscall number
- RDI, RSI, RDX, R10, R8, R9: arguments
- Return value in RAX

## IPC Mechanism

Message-passing IPC with:
- Synchronous send/receive
- Asynchronous notifications
- Shared memory regions for bulk data

## Security Model

- Capability-based security
- Process isolation via paging
- Minimal kernel attack surface
- Userspace drivers where possible
