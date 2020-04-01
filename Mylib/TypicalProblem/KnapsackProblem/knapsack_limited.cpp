#pragma once
#include <vector>
#include <algorithm>

/**
 * @title 個数制限付きナップサック問題
 * @attention 時間計算量 O(NWlog(MaxM))
 */
template <typename Weight, typename Value>
Value knapsack_limited(int N, Weight W, const std::vector<Weight> &w, const std::vector<Value> &v, const std::vector<int> &m){
  std::vector<Value> dp(W+1);

  for(int i = 0; i < N; ++i){
    for(int64_t a = 1, x = m[i], k; k = std::min(x,a), x > 0; x -= k, a *= 2){
      for(int j = W; j >= 0; --j){
        if(j-k*w[i] >= 0){
          dp[j] = std::max(dp[j], dp[j-k*w[i]] + (Weight)k*v[i]);
        }
      }
    }
  }

  return dp[W];
}
