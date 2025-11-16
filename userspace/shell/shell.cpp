// FractureOS Shell
// Command-line interface

#include "../../lib/libfracture/include/types.h"
#include "../../lib/libfracture/include/io.h"
#include "../../lib/libfracture/include/string.h"

namespace fracture {
namespace shell {

class Shell {
public:
    Shell() = default;
    
    void run() {
        print_banner();
        
        while (running_) {
            print_prompt();
            // Main shell loop
        }
    }

private:
    bool running_ = true;
    
    void print_banner() {
        io::Console::println("FractureOS Shell v0.1.0");
        io::Console::println("Type 'help' for available commands");
    }
    
    void print_prompt() {
        io::Console::print("fracture> ");
    }
};

} // namespace shell
} // namespace fracture

int main() {
    fracture::shell::Shell shell;
    shell.run();
    return 0;
}
