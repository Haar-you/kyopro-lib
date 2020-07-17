#pragma once
#include <optional>
#include <vector>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title Detect cycle
 * @docs detect_cycle.md
 */
template <typename T>
std::optional<std::vector<int>> detect_cycle(int V, int E, std::vector<Edge<T>> edges){
  std::vector<std::vector<std::pair<Edge<T>, int>>> g(V);
  std::vector<int> check(V);

  constexpr int SEARCHED = 1;
  constexpr int SEARCHING = 2;

  for(int i = 0; i < E; ++i){
    g[edges[i].from].emplace_back(edges[i], i);
  }

  auto rec =
    [&](auto &rec, int cur, std::vector<int> &temp, std::vector<int> &ret) -> std::optional<int> {
      if(check[cur] == SEARCHED) return std::nullopt;
      if(check[cur] == SEARCHING) return {cur};
      check[cur] = SEARCHING;

      for(auto [e, i] : g[cur]){
        temp.push_back(i);

        if(auto res = rec(rec, e.to, temp, ret); res){
          if(*res != -1){
            ret.push_back(i);
            if(*res == cur){
              return {-1};
            }
          }
          
          return res;
        }

        temp.pop_back();
      }

      check[cur] = SEARCHED;
      
      return std::nullopt;
    };

  for(int i = 0; i < V; ++i){
    if(check[i] == 0){
      std::vector<int> temp, ret;
      rec(rec, i, temp, ret);
      if(not ret.empty()){
        std::reverse(ret.begin(), ret.end());
        return {ret};
      }
    }
  }

  return std::nullopt;
}
