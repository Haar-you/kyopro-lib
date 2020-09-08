#pragma once
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

/**
 * @title 0-1 Knapsack problem (Small value)
 * @docs knapsack_small_value.md
 */
namespace haar_lib {
  template <typename Weight, typename Value>
  Value knapsack_small_value(int N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v){
    const Value MAX_V = std::accumulate(v.begin(), v.end(), 0);
    std::vector<std::vector<Value>> dp(N + 1, std::vector<Value>(MAX_V + 1, LLONG_MAX));

    dp[0][0] = 0;

    for(int i = 0; i < N; ++i){
      for(int j = 0; j <= MAX_V; ++j){
        dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]);
        if(j + v[i] <= MAX_V and dp[i][j] < LLONG_MAX){
          dp[i + 1][j + v[i]] = std::min(dp[i + 1][j + v[i]], dp[i][j] + w[i]);
        }
      }
    }

    Value ret = 0;

    for(int i = 0; i <= MAX_V; ++i){
      if(dp[N][i] <= cap) ret = i;
    }

    return ret;
  }
}
