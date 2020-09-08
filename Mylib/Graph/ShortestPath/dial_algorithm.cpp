#pragma once
#include <vector>
#include <optional>
#include <stack>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Dial's algorithm
 * @docs dial_algorithm.md
 */
namespace haar_lib {
  auto dial_algorithm(const graph<int> &g, std::vector<int> src, int MAX){
    const int N = g.size();
    std::vector<std::stack<int>> buckets(MAX + 1);
    std::vector<std::optional<int>> ret(N);
    std::vector<bool> check(N);

    for(int i : src){
      ret[i] = 0;
      buckets[0].push(i);
    }

    for(int i = 0; i <= MAX; ++i){
      while(not buckets[i].empty()){
        int cur = buckets[i].top(); buckets[i].pop();

        if(check[cur]) continue;
        check[cur] = true;

        for(auto &e : g[cur]){
          if(not ret[e.to] or *ret[cur] + e.cost < *ret[e.to]){
            ret[e.to] = *ret[cur] + e.cost;
            buckets[*ret[e.to] % (MAX + 1)].push(e.to);
          }
        }
      }
    }

    return ret;
  }
}
