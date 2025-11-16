#ifndef FRACTURE_MEMORY_H
#define FRACTURE_MEMORY_H

#include "types.h"
#include "syscall.h"

namespace fracture {
namespace memory {

constexpr size_t PAGE_SIZE = 4096;

enum class MemoryProtection : int {
    NONE = 0,
    READ = 1,
    WRITE = 2,
    EXEC = 4,
};

inline MemoryProtection operator|(MemoryProtection a, MemoryProtection b) {
    return static_cast<MemoryProtection>(
        static_cast<int>(a) | static_cast<int>(b)
    );
}

class MemoryMapper {
public:
    static void* map(void* addr, size_t length, MemoryProtection prot) {
        return reinterpret_cast<void*>(
            syscall::syscall3(
                syscall::SyscallNumber::MMAP,
                reinterpret_cast<uint64_t>(addr),
                length,
                static_cast<uint64_t>(prot)
            )
        );
    }
    
    static int unmap(void* addr, size_t length) {
        return syscall::syscall3(
            syscall::SyscallNumber::MUNMAP,
            reinterpret_cast<uint64_t>(addr),
            length,
            0
        );
    }
    
    static void* allocate_pages(size_t count) {
        return map(nullptr, count * PAGE_SIZE, 
                   MemoryProtection::READ | MemoryProtection::WRITE);
    }
    
    static void free_pages(void* addr, size_t count) {
        unmap(addr, count * PAGE_SIZE);
    }
};

} // namespace memory
} // namespace fracture

#endif // FRACTURE_MEMORY_H
