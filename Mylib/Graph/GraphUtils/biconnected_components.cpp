#pragma once
#include <vector>
#include <stack>
#include <algorithm>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Biconnected components
 * @docs biconnected_components.md
 */
template <typename T>
auto biconnected_components(const Graph<T> &g){
  const int n = g.size();

  std::vector<std::vector<Edge<T>>> ret;
  std::stack<Edge<T>> st;

  std::vector<int> low(n, -1), ord(n, -1);
  int t = 0;

  std::vector<bool> check(n);
  
  auto dfs =
    [&](auto &dfs, int cur, int par) -> void {
      check[cur] = true;
      ord[cur] = t;
      low[cur] = t;
      ++t;

      for(auto &e : g[cur]){
        if(e.to == par) continue;
        
        if(ord[e.to] < ord[cur]){
          auto f = e;
          if(f.from > f.to) std::swap(f.from, f.to);
          st.push(f);
        }
        if(not check[e.to]){
          dfs(dfs, e.to, cur);
          low[cur] = std::min(low[cur], low[e.to]);
          if(low[e.to] >= ord[cur]){
            ret.emplace_back();
            while(true){
              auto f = st.top(); st.pop();
              ret.back().push_back(f);
              if(f.from == std::min(e.from, e.to) and f.to == std::max(e.from, e.to)) break;
            }
          }
        }else{
          low[cur] = std::min(low[cur], ord[e.to]);
        }
      }
    };

  for(int i = 0; i < n; ++i){
    if(not check[i]) dfs(dfs, i, -1);
  }

  return ret;
}
