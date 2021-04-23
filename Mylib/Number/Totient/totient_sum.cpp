#pragma once
#include <cmath>
#include <unordered_map>
#include <vector>
#include "Mylib/Number/Totient/totient_table.cpp"

namespace haar_lib {
  template <typename T>
  T totient_sum(int64_t N) {
    const int64_t K = (int64_t) pow(N, 0.66);

    std::vector<T> memo1(K + 1);
    auto table = totient_table(K);
    T sum      = 0;
    for (int i = 1; i <= K; ++i) {
      sum += table[i];
      memo1[i] = sum;
    }

    std::unordered_map<int64_t, T> memo2;

    auto f =
        [&](auto &f, int64_t x) -> T {
      if (x <= K) return memo1[x];
      if (memo2.find(x) != memo2.end()) return memo2[x];

      T ret = 0;

      const int64_t s = sqrt(x);

      for (int i = 2; i <= s; ++i) {
        if (x / i <= s) continue;
        ret -= f(f, x / i);
      }

      for (int i = 1; i <= s; ++i) {
        ret -= f(f, i) * (x / i - x / (i + 1));
      }

      ret += (T) x * (x + 1) / 2;

      return memo2[x] = ret;
    };

    return f(f, N);
  }
}  // namespace haar_lib
