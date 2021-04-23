#pragma once
#include <numeric>
#include <vector>

namespace haar_lib {
  std::vector<int> totient_table(int n) {
    std::vector<int> ret(n + 1);
    std::iota(ret.begin(), ret.end(), 0);

    for (int i = 2; i <= n; ++i) {
      if (ret[i] == i) {
        for (int j = i; j <= n; j += i) {
          ret[j] = ret[j] / i * (i - 1);
        }
      }
    }

    return ret;
  }
}  // namespace haar_lib
