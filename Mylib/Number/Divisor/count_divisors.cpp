#pragma once
#include <cstdint>

namespace haar_lib {
  constexpr int count_divisors(int64_t n) {
    int count = 0;
    for (int64_t i = 1LL; i * i <= n; ++i) {
      if (n % i == 0) {
        count += 2;
        if (i * i == n) count -= 1;
      }
    }
    return count;
  }
}  // namespace haar_lib
