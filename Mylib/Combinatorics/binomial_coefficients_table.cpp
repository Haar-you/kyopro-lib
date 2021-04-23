#pragma once
#include <vector>

namespace haar_lib {
  template <typename T>
  auto binomial_coefficients_table(int n, int k) -> std::vector<std::vector<T>> {
    std::vector<std::vector<T>> ret(n + 1, std::vector<T>(k + 1));
    ret[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
      ret[i][0] = 1;

      for (int j = 1; j <= k; ++j) {
        ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
      }
    }

    return ret;
  }
}  // namespace haar_lib
