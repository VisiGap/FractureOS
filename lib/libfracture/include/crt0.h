#ifndef FRACTURE_CRT0_H
#define FRACTURE_CRT0_H

#include "types.h"

// C Runtime Startup (CRT0) for FractureOS userspace programs
// This provides the entry point and initialization for C/C++ programs

// User program entry point - to be defined by the application
// Note: main is not extern "C" in C++ to allow proper name mangling
int main(int argc, char* argv[]);

#ifdef __cplusplus
extern "C" {
#endif

// Exit function - terminates the process
void exit(int status) __attribute__((noreturn));

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
// C++ global constructor/destructor support
typedef void (*init_func_t)(void);

// These symbols are provided by the linker
extern init_func_t __init_array_start[];
extern init_func_t __init_array_end[];
extern init_func_t __fini_array_start[];
extern init_func_t __fini_array_end[];

namespace fracture {
namespace crt {

// Call all global constructors
inline void call_constructors() {
    for (init_func_t* func = __init_array_start; func != __init_array_end; ++func) {
        (*func)();
    }
}

// Call all global destructors
inline void call_destructors() {
    for (init_func_t* func = __fini_array_start; func != __fini_array_end; ++func) {
        (*func)();
    }
}

} // namespace crt
} // namespace fracture
#endif

// The actual entry point called by the kernel
// This should be defined in a separate crt0.S or crt0.cpp file
extern "C" void _start(void) __attribute__((noreturn));

#endif // FRACTURE_CRT0_H
