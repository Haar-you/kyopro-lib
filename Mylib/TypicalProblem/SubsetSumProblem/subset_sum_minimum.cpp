#pragma once
#include <vector>
#include <algorithm>

/**
 * @title 最小個数部分和問題
 * @attention 時間計算量 O(NK)
 * @return 和がKになる部分集合の最小サイズ。そのような部分集合が存在しないとき-1を返す。
 */
int64_t subset_sum_minimum(int N, int K, const std::vector<int> &a){
  std::vector<std::vector<int64_t>> dp(2, std::vector<int64_t>(K+1, INT_MAX));

  dp[0][0] = 0;

  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= K; ++j){
      if(j >= a[i]) dp[(i+1)&1][j] = std::min(dp[i&1][j-a[i]]+1, dp[i&1][j]);
      else dp[(i+1)&1][j] = dp[i&1][j];
    }
  }

  return dp[N&1][K] == INT_MAX ? -1 : dp[N&1][K];
}
