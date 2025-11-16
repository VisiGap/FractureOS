#ifndef FRACTURE_SYSCALL_H
#define FRACTURE_SYSCALL_H

#include "types.h"

namespace fracture {
namespace syscall {

enum class SyscallNumber : uint64_t {
    READ = 0,
    WRITE = 1,
    OPEN = 2,
    CLOSE = 3,
    FORK = 57,
    EXEC = 59,
    EXIT = 60,
    WAIT = 61,
    GETPID = 39,
    MMAP = 9,
    MUNMAP = 11,
};

inline uint64_t syscall0(SyscallNumber num) {
    uint64_t ret;
    asm volatile(
        "syscall"
        : "=a"(ret)
        : "a"(static_cast<uint64_t>(num))
        : "rcx", "r11", "memory"
    );
    return ret;
}

inline uint64_t syscall1(SyscallNumber num, uint64_t arg1) {
    uint64_t ret;
    asm volatile(
        "syscall"
        : "=a"(ret)
        : "a"(static_cast<uint64_t>(num)), "D"(arg1)
        : "rcx", "r11", "memory"
    );
    return ret;
}

inline uint64_t syscall3(SyscallNumber num, uint64_t arg1, uint64_t arg2, uint64_t arg3) {
    uint64_t ret;
    asm volatile(
        "syscall"
        : "=a"(ret)
        : "a"(static_cast<uint64_t>(num)), "D"(arg1), "S"(arg2), "d"(arg3)
        : "rcx", "r11", "memory"
    );
    return ret;
}

// High-level wrappers
inline ssize_t read(int fd, void* buf, size_t count) {
    return syscall3(SyscallNumber::READ, fd, 
                    reinterpret_cast<uint64_t>(buf), count);
}

inline ssize_t write(int fd, const void* buf, size_t count) {
    return syscall3(SyscallNumber::WRITE, fd, 
                    reinterpret_cast<uint64_t>(buf), count);
}

inline void exit(int status) {
    syscall1(SyscallNumber::EXIT, status);
    __builtin_unreachable();
}

inline int getpid() {
    return syscall0(SyscallNumber::GETPID);
}

} // namespace syscall
} // namespace fracture

#endif // FRACTURE_SYSCALL_H
