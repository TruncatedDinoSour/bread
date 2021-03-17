section .text
align 4


global start
extern _Z11kernel_mainv

start:
    cli
    call _Z11kernel_mainv
    hlt
