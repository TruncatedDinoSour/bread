import os

kernel_asm = "./kernel.s"
main_cpp = "./main.cpp"
out_asm = "kmain.o"
out_cpp = "kcpp.o"
out_ken = "kernel.bin"
ld_main = "./main.ld"

cpp_flags = f"clang++ -std=c++20 -Wextra -Wall -pedantic -c -m32 -o {out_cpp} {main_cpp} -fno-stack-protector -O3"
nasm_flags = f"nasm -f elf32 -o {out_asm} {kernel_asm}"
ld_flags = f"ld -m elf_i386 -o {out_ken} -T {ld_main} {out_asm} {out_cpp}"

os.system(cpp_flags)
os.system(nasm_flags)
os.system(ld_flags)
print("done")
