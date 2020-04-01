#pragma once
#include <vector>

/**
 * @title 個数制限付き部分和問題
 * @attention 時間計算量 O(NK)
 * @see https://onlinejudge.u-aizu.ac.jp/beta/room.html#HUPC2019Day2/problems/D
 */
bool subset_sum_limited(int N, int K, const std::vector<int> &a, const std::vector<int> &m){
  std::vector<int> dp(K+1, -1);

  dp[0] = 0;
  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= K; ++j){
      if(dp[j] >= 0){
        dp[j] = m[i];
      }else if(j < a[i] or dp[j-a[i]] <= 0){
        dp[j] = -1;
      }else{
        dp[j] = dp[j-a[i]]-1;
      }
    }
  }

  return dp[K] >= 0;
}
