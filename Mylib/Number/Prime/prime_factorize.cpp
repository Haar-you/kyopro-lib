#pragma once
#include <cstdint>
#include <utility>
#include <vector>

namespace haar_lib {
  auto prime_factorize(int64_t n) -> std::vector<std::pair<int64_t, int64_t>> {
    std::vector<std::pair<int64_t, int64_t>> ret;
    for (int64_t i = 2LL; i * i <= n; ++i) {
      if (n % i == 0) {
        int64_t c = 0;
        while (n % i == 0) {
          n /= i;
          ++c;
        }
        ret.emplace_back(i, c);
      }
    }
    if (n != 1) ret.emplace_back(n, 1);
    return ret;
  }
}  // namespace haar_lib
