#ifndef FRACTURE_IO_H
#define FRACTURE_IO_H

#include "types.h"
#include "syscall.h"

namespace fracture {
namespace io {

class Console {
public:
    static void print(const char* str) {
        size_t len = 0;
        while (str[len]) ++len;
        syscall::write(1, str, len);
    }
    
    static void println(const char* str) {
        print(str);
        print("\n");
    }
    
    static void print_char(char c) {
        syscall::write(1, &c, 1);
    }
};

} // namespace io
} // namespace fracture

#endif // FRACTURE_IO_H
