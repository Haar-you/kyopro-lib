#pragma once
#include <algorithm>
#include <vector>

namespace haar_lib {
  template <typename Weight, typename Value>
  Value knapsack_unlimited(int N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v) {
    std::vector<std::vector<Value>> dp(N + 1, std::vector<Value>(cap + 1));

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j <= cap; ++j) {
        if (j < w[i])
          dp[i + 1][j] = dp[i][j];
        else
          dp[i + 1][j] = std::max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
      }
    }

    return dp[N][cap];
  }
}  // namespace haar_lib
