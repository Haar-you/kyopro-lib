#pragma once
#include <vector>

/**
 * @title 部分和数え上げ問題
 * @docs subset_sum_count.md
 */
template <typename T>
T subset_sum_count(int N, int K, const std::vector<int> &a){
  std::vector<std::vector<T>> dp(2, std::vector<T>(K+1));

  dp[0][0] = 1;

  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= K; ++j){
      if(j >= a[i]) dp[(i+1)&1][j] = dp[i&1][j-a[i]] + dp[i&1][j];
      else dp[(i+1)&1][j] = dp[i&1][j];
    }
  }

  return dp[N&1][K];
}
