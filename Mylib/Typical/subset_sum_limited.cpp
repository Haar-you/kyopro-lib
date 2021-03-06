#pragma once
#include <cassert>
#include <vector>

namespace haar_lib {
  auto subset_sum_limited(int N, int K, const std::vector<int> &a, const std::vector<int> &m) {
    assert((int) a.size() == N and (int) m.size() == N);
    std::vector<int> dp(K + 1, -1);

    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j <= K; ++j) {
        if (dp[j] >= 0) {
          dp[j] = m[i];
        } else if (j < a[i] or dp[j - a[i]] <= 0) {
          dp[j] = -1;
        } else {
          dp[j] = dp[j - a[i]] - 1;
        }
      }
    }

    for (int i = 0; i <= K; ++i) dp[i] = dp[i] >= 0;

    return dp;
  }
}  // namespace haar_lib
