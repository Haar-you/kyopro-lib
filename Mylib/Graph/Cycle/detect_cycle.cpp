#pragma once
#include <optional>
#include <vector>
#include <algorithm>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Detect cycle
 * @docs detect_cycle.md
 */
namespace haar_lib {
  namespace detect_cycle_impl {
    constexpr static int SEARCHED = 1;
    constexpr static int SEARCHING = 2;

    template <typename T>
    std::optional<int> rec(
      const graph<T> &g,
      int cur,
      std::vector<edge<T>> &temp,
      std::vector<edge<T>> &ret,
      std::vector<int> &check
    ){
      if(check[cur] == SEARCHED) return std::nullopt;
      if(check[cur] == SEARCHING) return {cur};
      check[cur] = SEARCHING;

      for(auto &e : g[cur]){
        temp.push_back(e);

        if(auto res = rec(g, e.to, temp, ret, check); res){
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
    }
  }

  template <typename T>
  std::optional<std::vector<edge<T>>> detect_cycle(const graph<T> &g){
    const int N = g.size();
    std::vector<int> check(N);

    for(int i = 0; i < N; ++i){
      if(check[i] == 0){
        std::vector<edge<T>> temp, ret;
        detect_cycle_impl::rec(g, i, temp, ret, check);
        if(not ret.empty()){
          std::reverse(ret.begin(), ret.end());
          return {ret};
        }
      }
    }

    return std::nullopt;
  }
}
