#!/usr/bin/sh
kernel_asm="./kernel.s"
main_cpp="./main.cpp"
out_asm="kmain.o"
out_cpp="kcpp.o"
out_ken="kernel.bin"
ld_main="./main.ld"

cpp_flags="clang++ -std=c++20 -Wextra -Wall -pedantic -c -m32 -o ${out_cpp} ${main_cpp} -fno-stack-protector -nostdinc -fno-exceptions -fno-rtti"
nasm_flags="nasm -f elf32 -o ${out_asm} ${kernel_asm}"
ld_flags="ld -m elf_i386 -o ${out_ken} -T ${ld_main} ${out_asm} ${out_cpp}"

$cpp_flags
$nasm_flags
$ld_flags

echo "done"
