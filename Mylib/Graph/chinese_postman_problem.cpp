#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 中国人郵便配達問題
 * @docs chinese_postman_problem.cpp
 */
template <typename T> T chinese_postman_problem(const Graph<T> &g){
  const int n = g.size();
  T ret = 0;

  // 頂点間の最短距離を求める。
  std::vector<std::vector<int>> dist(n, std::vector<T>(n, -1));

  for(int i = 0; i < n; ++i) dist[i][i] = 0;

  for(int i = 0; i < n; ++i){
    for(auto &e : g[i]){
      if(dist[e.from][e.to] == -1) dist[e.from][e.to] = e.cost;
      else dist[e.from][e.to] = std::min(dist[e.from][e.to], e.cost);
    }
  }

  for(int k = 0; k < n; ++k){
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        if(dist[i][k] >= 0 and dist[k][j] >= 0){
          if(dist[i][j] == -1) dist[i][j] = dist[i][k] + dist[k][j];
          else dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  // 奇数次数の頂点を列挙
  std::vector<int> odd;
  for(int i = 0; i < n; ++i){
    if(g[i].size() % 2) odd.push_back(i);
  }

  const int m = odd.size();

  // 奇数次数の頂点間の最小マッチングを求める。
  std::vector<T> dp(1<<m, -1);
  dp[0] = 0;

  for(int i = 0; i < (1<<m); ++i){
    for(int j = 0; j < m; ++j){
      for(int k = 0; k < j; ++k){
        if((i & (1<<j)) and (i & (1<<k))){
          if(dp[i] == -1) dp[i] = dp[i ^ (1<<j) ^ (1<<k)] + dist[odd[j]][odd[k]];
          else dp[i] = std::min(dp[i], dp[i ^ (1<<j) ^ (1<<k)] + dist[odd[j]][odd[k]]);
        }
      }
    }
  }

  // 返り値を計算
  for(int i = 0; i < n; ++i){
    for(auto &e : g[i]) if(e.from <= e.to) ret += e.cost;
  }

  ret += dp[(1<<m)-1];

  return ret;
}
