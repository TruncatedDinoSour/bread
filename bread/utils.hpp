#ifndef BREAD_UTILS_HPP
#define BREAD_UTILS_HPP
namespace bstd {
using size_t = unsigned int;
using uint8_t = unsigned char;
using uint16_t = short unsigned int;
using storage_t = bstd::uint8_t*;
enum class Color : bstd::uint16_t { Black = 0, Grey = 7, White = 15 };
struct ColorInterface {
    Color text;
    Color background;
    bstd::uint16_t get() {
        bstd::uint16_t t = static_cast<bstd::uint16_t>(text);
        bstd::uint16_t b = static_cast<bstd::uint16_t>(background);
        return (t | b << 4);
    }
};
template<class It, class Size, class T>
It fill_n(It first, Size count, const T& value)
{
    for (;count--;) {
        *first++ = value;
    }
    return first;
}
}  // namespace bstd
#endif
