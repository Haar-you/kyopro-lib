#pragma once
#include <cstdint>
#include <vector>

namespace haar_lib {
  std::vector<int64_t> enumerate_mod_inv(int n, int64_t p) {
    std::vector<int64_t> ret(n + 1);

    ret[1] = 1;

    for (int i = 2; i <= n; ++i) {
      ret[i] = (p / i) * (p - ret[p % i]) % p;
    }

    return ret;
  }
}  // namespace haar_lib
