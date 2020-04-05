#pragma once
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>

/**
 * @title Bitonic tour
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_C
 */
template <typename T>
double bitonic_tour(int n, const std::vector<T> &x, const std::vector<T> &y){
  std::vector<std::vector<double>> dist(n, std::vector<double>(n));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      double dx = x[i] - x[j];
      double dy = y[i] - y[j];
      dist[i][j] = std::sqrt(dx * dx + dy * dy);
    }
  }

  std::vector<std::vector<double>> dp(n, std::vector<double>(n, std::numeric_limits<double>::max()));

  dp[0][0] = 0;

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      dp[i][i] = std::min(dp[i][i], dp[i][j] + dist[i][j]);
      if(i+1 < n){
        dp[i+1][j] = std::min(dp[i+1][j], dp[i][j] + dist[i][i+1]);
        dp[i][i+1] = std::min(dp[i][i+1], dp[i][j] + dist[j][i+1]);
      }
      if(j+1 < n){
        dp[i][j+1] = std::min(dp[i][j+1], dp[i][j] + dist[j][j+1]);
        dp[j+1][j] = std::min(dp[j+1][j], dp[i][j] + dist[i][j+1]);
      }
    }
  }

  return dp[n-1][n-1];
}
