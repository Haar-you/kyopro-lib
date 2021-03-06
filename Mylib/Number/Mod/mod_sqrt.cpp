#pragma once
#include <optional>
#include <random>
#include "Mylib/Number/Mod/mod_pow.cpp"

namespace haar_lib {
  std::optional<int64_t> mod_sqrt(int64_t a, int64_t p) {
    if (p == 2) return a % 2;
    if (a == 0) return 0;

    int64_t b = mod_pow(a, (p - 1) / 2, p);

    if (b == p - 1) return {};
    if (p % 4 == 3) return mod_pow(a, (p + 1) / 4, p);

    int64_t q = p - 1, s = 0;
    while (q % 2 == 0) {
      q /= 2;
      s += 1;
    }

    static std::mt19937_64 rand(time(0));
    std::uniform_int_distribution<> dist(0, p - 1);

    int64_t z;
    while (1) {
      z = dist(rand);
      if (mod_pow(z, (p - 1) / 2, p) == p - 1) break;
    }

    int64_t m = s;
    int64_t c = mod_pow(z, q, p);
    int64_t t = mod_pow(a, q, p);
    int64_t r = mod_pow(a, (q + 1) / 2, p);

    while (1) {
      if (t == 0) return 0;
      if (t == 1) return r;

      int i = 1;
      for (int64_t T = t; i < m; ++i) {
        (T *= T) %= p;
        if (T == 1) break;
      }

      int64_t b = mod_pow(c, 1LL << (m - i - 1), p);

      m = i;
      c = b * b % p;
      (t *= b * b % p) %= p;
      (r *= b) %= p;
    }
  }
}  // namespace haar_lib
