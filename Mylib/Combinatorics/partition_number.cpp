#pragma once
#include <vector>

/**
 * @see https://mathtrain.jp/bunkatsu
 * @see http://drken1215.hatenablog.com/entry/2018/01/16/222843
 * @note 自然数nをk個以下の1以上の整数に分割する方法。
 */
template <typename T>
auto partition_number(int n, int k){
  std::vector<std::vector<T>> dp(n+1, std::vector<T>(k+1));
  dp[0][0] = 1;

  for(int i = 0; i <= n; ++i){
    for(int j = 1; j <= k; ++j){
      if(i-j >= 0) dp[i][j] = dp[i][j-1] + dp[i-j][j];
      else dp[i][j] = dp[i][j-1];
    }
  }

  return dp;
}

