#ifndef BREAD_UTILS_HPP
#define BREAD_UTILS_HPP
namespace bstd {
using size_t = unsigned int;
using uint8_t = unsigned char;
using uint16_t = short unsigned int;
using storage_t = bstd::uint8_t*;
enum class Color : bstd::uint8_t { Black = 0, White = 15 };
struct ColorInterface {
    Color text;
    Color background;
    bstd::uint16_t get() {
        int t = static_cast<bstd::uint8_t>(text) - '0';
        int b = static_cast<bstd::uint8_t>(background) - '0';
        return (t | b << 4);
    }
};
}  // namespace bstd
#endif
