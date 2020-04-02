#pragma once
#include <vector>
#include <algorithm>

/**
 * @title 重さの制約が小さい0-1ナップサック問題
 * @attention 時間計算量 O(NW)
 * @see https://atcoder.jp/contests/dp/submissions/6394556
 */
template <typename Weight, typename Value>
Value knapsack_small_weight(int N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v){
  std::vector<std::vector<Value>> dp(N+1, std::vector<Value>(cap+1));

  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= cap; ++j){
      dp[i+1][j] = std::max(dp[i+1][j], dp[i][j]);
      if(j+w[i] <= cap) dp[i+1][j+w[i]] = std::max(dp[i+1][j+w[i]], dp[i][j]+v[i]);
    }
  }
  
  return dp[N][cap];
}