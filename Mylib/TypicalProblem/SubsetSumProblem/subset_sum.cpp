#pragma once
#include <vector>

namespace haar_lib {
  auto subset_sum(int N, int K, const std::vector<int> &a){
    std::vector<std::vector<bool>> dp(2, std::vector<bool>(K + 1));

    dp[0][0] = true;

    for(int i = 0; i < N; ++i){
      for(int j = 0; j <= K; ++j){
        if(j >= a[i]) dp[(i + 1) & 1][j] = dp[i & 1][j - a[i]] or dp[i & 1][j];
        else dp[(i + 1) & 1][j] = dp[i & 1][j];
      }
    }

    return dp[N & 1];
  }
}
