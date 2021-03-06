#pragma once
#include <cstdint>

namespace haar_lib {
  constexpr int64_t totient(int64_t n) {
    int64_t ret = n;

    for (int64_t i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        ret -= ret / i;
        while (n % i == 0) n /= i;
      }
    }

    if (n != 1) ret -= ret / n;

    return ret;
  }
}  // namespace haar_lib
