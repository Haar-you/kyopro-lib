#pragma once
#include <cstdint>
#include <utility>

namespace haar_lib {
  constexpr int64_t mod_inv(int64_t a, int64_t m) {
    int64_t b = m, u = 1, v = 0;

    while (b) {
      int64_t t = a / b;
      a -= t * b;
      a = a ^ b;
      b = a ^ b;
      a = a ^ b;

      u -= t * v;
      u = u ^ v;
      v = u ^ v;
      u = u ^ v;
    }

    u %= m;
    if (u < 0) u += m;

    return u;
  }
}  // namespace haar_lib
