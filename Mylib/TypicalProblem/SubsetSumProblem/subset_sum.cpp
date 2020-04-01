#pragma once
#include <vector>

/**
 * @title 部分和判定問題
 * @attention 時間計算量 O(NK)
 */
bool subset_sum(int N, int K, const std::vector<int> &a){
  std::vector<std::vector<bool>> dp(2, std::vector<bool>(K+1));

  dp[0][0] = true;

  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= K; ++j){
      if(j >= a[i]) dp[(i+1)&1][j] = dp[i&1][j-a[i]] or dp[i&1][j];
      else dp[(i+1)&1][j] = dp[i&1][j];
    }
  }

  return dp[N&1][K];
}
