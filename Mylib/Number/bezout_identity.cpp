#pragma once
#include <utility>
#include <optional>
#include "Mylib/Number/extended_gcd.cpp"

namespace haar_lib {
  struct bezout_generator {
    int64_t a, b, c, x, y, dx, dy;

    auto value() const {return std::make_pair(x, y);}
    auto next(int64_t n = 1){x += dx * n, y -= dy * n; return std::make_pair(x, y);}
    auto prev(int64_t n = 1){x -= dx * n, y += dy * n; return std::make_pair(x, y);}
  };

  std::optional<bezout_generator> bezout_identity(int64_t a, int64_t b, int64_t c){
    auto [g, x, y] = ext_gcd(a, b);

    if(c % g != 0) return std::nullopt;

    int64_t dx = b / g;
    int64_t dy = a / g;
    int64_t dc = c / g;

    x %= dx;
    if(x < 0){
      x += std::abs(dx);
    }

    x *= dc;
    dx *= dc;
    dy *= dc;

    y = (c - a * x) / b;

    return bezout_generator({a, b, c, x, y, dx, dy});
  }
}
