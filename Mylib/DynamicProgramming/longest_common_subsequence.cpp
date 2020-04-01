#pragma once
#include <vector>
#include <algorithm>

/**
 * @title 最長共通部分列
 * @attention 時間計算量 O(nm)
 */
template <typename T>
int lcs(const T &a, const T &b){
  const int n = a.size(), m = b.size();
  
  std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      dp[i][j] = a[i-1] == b[j-1] ? dp[i-1][j-1] + 1 : std::max(dp[i-1][j], dp[i][j-1]);
    }
  }
    
  return dp[n][m];
}
