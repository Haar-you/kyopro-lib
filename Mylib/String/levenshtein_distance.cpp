#pragma once
#include <vector>
#include <algorithm>

namespace haar_lib {
  template <typename Container, typename T = typename Container::value_type>
  int levenshtein_distance(const Container &a, const Container &b){
    const int n = a.size(), m = b.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    for(int i = 0; i <= n; ++i) dp[i][0] = i;
    for(int i = 0; i <= m; ++i) dp[0][i] = i;

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        dp[i + 1][j + 1] = std::min(dp[i][j + 1] + 1, dp[i + 1][j] + 1);

        if(a[i] == b[j]){
          dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j]);
        }else{
          dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j] + 1);
        }
      }
    }
    return dp[n][m];
  }
}
