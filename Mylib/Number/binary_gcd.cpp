#pragma once
#include <cmath>
#include <utility>

namespace haar_lib {
  int64_t binary_gcd(int64_t a, int64_t b) {
    int64_t g = 1;

    while (1) {
      if (a > b) std::swap(a, b);

      if (a == 0) {
        break;
      } else {
        if ((a & 1) == 0 and (b & 1) == 0) {
          a >>= 1;
          b >>= 1;
          g <<= 1;
        } else if ((a & 1) == 0) {
          a >>= 1;
        } else if ((b & 1) == 0) {
          b >>= 1;
        } else {
          int64_t t = std::abs(a - b) >> 1;
          b         = t;
        }
      }
    }

    return g * b;
  }
}  // namespace haar_lib
