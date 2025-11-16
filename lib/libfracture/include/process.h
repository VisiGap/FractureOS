#ifndef FRACTURE_PROCESS_H
#define FRACTURE_PROCESS_H

#include "types.h"
#include "syscall.h"

namespace fracture {
namespace process {

using pid_t = int32_t;

class Process {
public:
    static pid_t current_pid() {
        return syscall::getpid();
    }
    
    static pid_t fork() {
        return syscall::syscall0(syscall::SyscallNumber::FORK);
    }
    
    static void exit(int status) {
        syscall::exit(status);
    }
    
    static int wait(pid_t pid) {
        return syscall::syscall1(syscall::SyscallNumber::WAIT, pid);
    }
    
    static int exec(const char* path, char* const argv[]) {
        return syscall::syscall3(
            syscall::SyscallNumber::EXEC,
            reinterpret_cast<uint64_t>(path),
            reinterpret_cast<uint64_t>(argv),
            0
        );
    }
};

} // namespace process
} // namespace fracture

#endif // FRACTURE_PROCESS_H
