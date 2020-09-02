#pragma once
#include <optional>
#include <vector>
#include <algorithm>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Detect cycle
 * @docs detect_cycle.md
 */
template <typename T>
std::optional<std::vector<Edge<T>>> detect_cycle(const Graph<T> &g){
  const int N = g.size();
  std::vector<int> check(N);

  constexpr int SEARCHED = 1;
  constexpr int SEARCHING = 2;

  auto rec =
    [&](auto &rec, int cur, std::vector<Edge<T>> &temp, std::vector<Edge<T>> &ret) -> std::optional<int> {
      if(check[cur] == SEARCHED) return std::nullopt;
      if(check[cur] == SEARCHING) return {cur};
      check[cur] = SEARCHING;

      for(auto &e : g[cur]){
        temp.push_back(e);

        if(auto res = rec(rec, e.to, temp, ret); res){
          if(*res != -1){
            ret.push_back(e);
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

  for(int i = 0; i < N; ++i){
    if(check[i] == 0){
      std::vector<Edge<T>> temp, ret;
      rec(rec, i, temp, ret);
      if(not ret.empty()){
        std::reverse(ret.begin(), ret.end());
        return {ret};
      }
    }
  }

  return std::nullopt;
}
