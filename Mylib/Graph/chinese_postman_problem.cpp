#pragma once
#include <vector>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_B
 * @attention 時間計算量 O(n^2 2^n)
 */
template <typename T> T chinese_postman_problem(const Graph<T> &g){
  int n = g.size();
  T ret = 0;

  // 頂点間の最短距離を求める。
  std::vector<std::vector<int>> dist(n, std::vector<T>(n, -1));

  for(int i = 0; i < n; ++i) dist[i][i] = 0;

  for(int i = 0; i < n; ++i){
    for(auto &e : g[i]){
      if(dist[e.from][e.to] == -1) dist[e.from][e.to] = e.cost;
      else chmin(dist[e.from][e.to], e.cost);
    }
  }

  for(int k = 0; k < n; ++k){
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        if(dist[i][k] >= 0 and dist[k][j] >= 0){
          if(dist[i][j] == -1) dist[i][j] = dist[i][k] + dist[k][j];
          else chmin(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  // 奇数次数の頂点を列挙
  std::vector<int> odd;
  for(int i = 0; i < n; ++i){
    if(g[i].size() % 2) odd.push_back(i);
  }

  int m = odd.size();

  // 奇数次数の頂点間の最小マッチングを求める。
  std::vector<T> dp(1<<m, -1);
  dp[0] = 0;

  for(int i = 0; i < (1<<m); ++i){
    for(int j = 0; j < m; ++j){
      for(int k = 0; k < j; ++k){
        if((i & (1<<j)) and (i & (1<<k))){
          if(dp[i] == -1) dp[i] = dp[i ^ (1<<j) ^ (1<<k)] + dist[odd[j]][odd[k]];
          else chmin(dp[i], dp[i ^ (1<<j) ^ (1<<k)] + dist[odd[j]][odd[k]]);
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
