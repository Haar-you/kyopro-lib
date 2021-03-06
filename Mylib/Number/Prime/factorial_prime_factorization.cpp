#pragma once
#include <cstdint>

namespace haar_lib {
  int64_t factorial_prime_factorization(int64_t a, int64_t p) {
    int64_t ret = 0, q = p;

    while (q <= a) {
      int64_t t = a / q;

      ret += t;

      int64_t k;
      if (__builtin_smulll_overflow(q, p, (long long int*) &k)) break;

      q = k;
    }
    return ret;
  }
}  // namespace haar_lib
