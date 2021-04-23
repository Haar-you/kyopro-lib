#pragma once
#include <tuple>

namespace haar_lib {
  auto ext_gcd(int64_t a, int64_t b) -> std::tuple<
      int64_t,  // gcd
      int64_t,  // p
      int64_t   // q
      > {
    if (b == 0) return std::make_tuple(a, 1, 0);
    const auto [d, q, p] = ext_gcd(b, (a + b) % b);
    return std::make_tuple(d, p, q - a / b * p);
  }
}  // namespace haar_lib
