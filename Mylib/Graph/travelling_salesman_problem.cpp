#pragma once
#include <vector>
#include <optional>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
 * @attention 時間計算量 O(n^2 2^n)
 */
template <typename Cost>
std::optional<Cost> travelling_salesman_problem(const Graph<Cost> &g, int src){
  const int n = g.size();

  std::vector<std::vector<std::optional<Cost>>> dp(n, std::vector<std::optional<Cost>>(1<<n));

  for(auto &e : g[src]){
    if(not dp[e.to][1 << e.to]){
      dp[e.to][1 << e.to] = e.cost;
    }else{
      dp[e.to][1 << e.to] = std::min(*dp[e.to][1 << e.to], e.cost);
    }
  }

  for(int s = 1; s < (1<<n); ++s){
    for(int i = 0; i < n; ++i){
      if(not (s & (1<<i))) continue;

      for(auto &e : g[i]){
        if(s & (1<<e.to)) continue;

        if(dp[i][s]){
          if(not dp[e.to][s | (1<<e.to)]){
            dp[e.to][s | (1<<e.to)] = *dp[i][s] + e.cost;
          }else{
            dp[e.to][s | (1<<e.to)] = std::min(*dp[e.to][s | (1<<e.to)], *dp[i][s] + e.cost);
          }
        }
      }
    }
  }

  return dp[src][(1<<n)-1];
}