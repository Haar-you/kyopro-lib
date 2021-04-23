#pragma once
#include <cmath>
#include <cstdint>

namespace haar_lib {
  int64_t ceil(int64_t a, int64_t b) {
    if ((a <= 0 and b < 0) or (a >= 0 and b > 0)) return (std::abs(a) + std::abs(b) - 1) / std::abs(b);
    return -(std::abs(a) / std::abs(b));
  }

  int64_t floor(int64_t a, int64_t b) {
    if ((a <= 0 and b < 0) or (a >= 0 and b > 0)) return a / b;
    return -(std::abs(a) + std::abs(b) - 1) / std::abs(b);
  }
}  // namespace haar_lib
