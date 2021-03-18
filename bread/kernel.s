bits 32
section .multiboot_header
header_start:
	dd 0x1BADB002
	dd 0
	dd 0x100000000 - (0x1BADB002 + 0)
	dw 0
	dw 0
	dd 8
header_end:
global start

section .text
extern _Z11kernel_mainv
start:
    mov esp, stack_bot
    call _Z11kernel_mainv
    cli
    hlt
section .bss
stack_bot:
    resb 4096 * 6
stack_top:
