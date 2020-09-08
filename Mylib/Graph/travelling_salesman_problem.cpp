#pragma once
#include <vector>
#include <optional>
#include <algorithm>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Travelling salesman problem
 * @docs travelling_salesman_problem.md
 */
namespace haar_lib {
  template <typename T>
  std::optional<T> travelling_salesman_problem(const Graph<T> &g, int src){
    const int n = g.size();

    std::vector<std::vector<std::optional<T>>> dp(n, std::vector<std::optional<T>>(1 << n));

    for(auto &e : g[src]){
      if(not dp[e.to][1 << e.to]){
        dp[e.to][1 << e.to] = e.cost;
      }else{
        dp[e.to][1 << e.to] = std::min(*dp[e.to][1 << e.to], e.cost);
      }
    }

    for(int s = 1; s < (1 << n); ++s){
      for(int i = 0; i < n; ++i){
        if(not (s & (1 << i))) continue;

        for(auto &e : g[i]){
          if(s & (1 << e.to)) continue;

          if(dp[i][s]){
            if(not dp[e.to][s | (1 << e.to)]){
              dp[e.to][s | (1 << e.to)] = *dp[i][s] + e.cost;
            }else{
              dp[e.to][s | (1 << e.to)] = std::min(*dp[e.to][s | (1 << e.to)], *dp[i][s] + e.cost);
            }
          }
        }
      }
    }

    return dp[src][(1 << n) - 1];
  }
}
