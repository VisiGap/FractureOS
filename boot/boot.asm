; FractureOS Bootloader
; Simple bootloader for x86_64

[BITS 16]
[ORG 0x7C00]

start:
    cli
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00
    
    ; Load kernel
    mov si, msg_loading
    call print_string
    
    ; Enable A20 line
    call enable_a20
    
    ; Load GDT
    lgdt [gdt_descriptor]
    
    ; Enter protected mode
    mov eax, cr0
    or eax, 1
    mov cr0, eax
    
    jmp CODE_SEG:protected_mode

enable_a20:
    in al, 0x92
    or al, 2
    out 0x92, al
    ret

print_string:
    lodsb
    or al, al
    jz .done
    mov ah, 0x0E
    int 0x10
    jmp print_string
.done:
    ret

[BITS 32]
protected_mode:
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov esp, 0x90000
    
    ; Jump to kernel
    jmp 0x100000

msg_loading: db 'Loading FractureOS...', 13, 10, 0

; GDT
gdt_start:
    dq 0x0

gdt_code:
    dw 0xFFFF
    dw 0x0
    db 0x0
    db 10011010b
    db 11001111b
    db 0x0

gdt_data:
    dw 0xFFFF
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0

gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

times 510-($-$$) db 0
dw 0xAA55
