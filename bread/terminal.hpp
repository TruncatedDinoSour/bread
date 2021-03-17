#ifndef BREAD_TERMINAL_HPP
#define BREAD_TERMINAL_HPP
#include "utils.hpp"
namespace bstd {
class Terminal {
  bstd::uint16_t *m_Buffer;
  bstd::size_t m_Row;
  bstd::size_t m_Col;
  bstd::size_t m_Height;
  bstd::size_t m_Width;
  bstd::ColorInterface m_Color;

public:
  Terminal(bstd::size_t h = 25, bstd::size_t w = 80,
           bstd::ColorInterface col = {bstd::Color::Black, bstd::Color::Grey})
      : m_Buffer{reinterpret_cast<bstd::uint16_t *>(0xB8000)}, m_Row{0},
        m_Col{0}, m_Height{h}, m_Width{w}, m_Color{col} {
            Clear();
  }
  void WriteChar(bstd::uint16_t c) {
    bstd::size_t idx = m_Row * m_Width + m_Col;
    m_Buffer[idx] = (static_cast<bstd::uint16_t>(c) |
                                               (m_Color.get() << 8));
    if (++m_Col >= m_Height) {
      m_Col = 0;
    } else if (++m_Row >= m_Width) {
      m_Row = 0;
    }
  }
  template <bstd::size_t N> void WriteString(const char (&str)[N]) {
    for (bstd::size_t i = 0; i < N; i++) {
      WriteChar(str[i]);
    }
  }
  void Clear() {
      bstd::fill_n(m_Buffer,
              m_Height * m_Width * 2,
              0);
  }
  bstd::uint16_t *getBuffer() { return m_Buffer; }
};
} // namespace bstd
#endif
