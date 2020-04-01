#pragma once
#include <vector>
#include <algorithm>

/**
 * @title 個数制限無しナップサック問題
 * @attention 時間計算量 O(NW)
 */
template <typename Weight, typename Value>
Value knapsack_unlimited(int N, Weight W, const std::vector<Weight> &w, const std::vector<Value> &v){
  std::vector<std::vector<Value>> dp(N+1, std::vector<Value>(W+1));
  
  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= W; ++j){
      if(j < w[i]) dp[i+1][j] = dp[i][j];
      else dp[i+1][j] = std::max(dp[i][j], dp[i+1][j-w[i]]+v[i]);
    }
  }

  return dp[N][W];
};
