#include "terminal.hpp"

extern "C++" void kernel_main() {
    bstd::Terminal term;
    term.WriteString("hello there");;
}
