// FractureOS Init Process
// First userspace process

#include "../../lib/libfracture/include/types.h"
#include "../../lib/libfracture/include/io.h"
#include "../../lib/libfracture/include/process.h"

namespace fracture {

class InitProcess {
public:
    InitProcess() = default;
    
    void run() {
        io::Console::println("FractureOS Init Process Starting...");
        
        // Initialize system services
        init_vfs();
        init_device_manager();
        spawn_system_daemons();
        
        io::Console::println("System initialization complete");
        
        // Enter main loop
        main_loop();
    }

private:
    void init_vfs() {
        io::Console::println("[init] Mounting filesystems...");
    }
    
    void init_device_manager() {
        io::Console::println("[init] Initializing device manager...");
    }
    
    void spawn_system_daemons() {
        io::Console::println("[init] Starting system daemons...");
    }
    
    void main_loop() {
        while (true) {
            // Wait for events and handle process reaping
            asm volatile("hlt");
        }
    }
};

} // namespace fracture

extern "C" void _start() {
    fracture::InitProcess init;
    init.run();
    
    // Should never reach here
    while (true) {
        asm volatile("hlt");
    }
}
