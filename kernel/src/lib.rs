#![no_std]
#![no_main]
#![feature(abi_x86_interrupt)]
#![feature(alloc_error_handler)]

extern crate alloc;

use core::panic::PanicInfo;

pub mod memory;
pub mod interrupts;
pub mod gdt;
pub mod serial;
pub mod vga;
pub mod allocator;

#[no_mangle]
pub extern "C" fn _start() -> ! {
    serial_println!("FractureOS Kernel v0.1.0");
    serial_println!("Initializing...");

    gdt::init();
    interrupts::init_idt();
    unsafe { interrupts::PICS.lock().initialize() };
    x86_64::instructions::interrupts::enable();

    serial_println!("Kernel initialized successfully");
    
    hlt_loop();
}

#[panic_handler]
fn panic(info: &PanicInfo) -> ! {
    serial_println!("KERNEL PANIC: {}", info);
    hlt_loop();
}

pub fn hlt_loop() -> ! {
    loop {
        x86_64::instructions::hlt();
    }
}

#[alloc_error_handler]
fn alloc_error_handler(layout: alloc::alloc::Layout) -> ! {
    panic!("allocation error: {:?}", layout)
}
