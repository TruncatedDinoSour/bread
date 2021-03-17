#include "terminal.hpp"

void kernel_main() {
    bstd::Terminal term;
    term.WriteString("hello, world!");
}
