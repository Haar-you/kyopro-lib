#pragma once
#include <cstdint>

namespace haar_lib {
  constexpr int64_t mod_pow(int64_t n, int64_t p, int64_t m) {
    int64_t ret = 1;
    while (p > 0) {
      if (p & 1) (ret *= n) %= m;
      (n *= n) %= m;
      p >>= 1;
    }
    return ret;
  }
}  // namespace haar_lib
