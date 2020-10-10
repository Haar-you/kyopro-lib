#pragma once
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

namespace haar_lib {
  auto subset_sum_minimum(int N, int K, const std::vector<int> &a){
    assert((int)a.size() == N);
    std::vector<std::vector<int64_t>> dp(2, std::vector<int64_t>(K + 1, INT_MAX));

    dp[0][0] = 0;

    for(int i = 0; i < N; ++i){
      for(int j = 0; j <= K; ++j){
        if(j >= a[i]) dp[(i + 1) & 1][j] = std::min(dp[i & 1][j - a[i]] + 1, dp[i & 1][j]);
        else dp[(i + 1) & 1][j] = dp[i & 1][j];
      }
    }

    for(int i = 0; i <= K; ++i){
      if(dp[N & 1][i] == INT_MAX) dp[N & 1][i] = -1;
    }

    return dp[N & 1];
  }
}
