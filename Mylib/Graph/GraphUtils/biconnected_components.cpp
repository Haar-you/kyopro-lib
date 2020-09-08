#pragma once
#include <vector>
#include <stack>
#include <algorithm>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Biconnected components
 * @docs biconnected_components.md
 */
namespace haar_lib {
  namespace biconnected_components_impl {
    template <typename T>
    void dfs(
      const Graph<T> &g,
      int cur,
      int par,
      std::vector<bool> &check,
      std::vector<int> &low,
      std::vector<int> &ord,
      std::vector<std::vector<Edge<T>>> &ret,
      std::stack<Edge<T>> &st,
      int &t
    ){
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
          dfs(g, e.to, cur, check, low, ord, ret, st, t);
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
    }
  }

  template <typename T>
  auto biconnected_components(const Graph<T> &g){
    const int n = g.size();

    std::vector<bool> check(n);
    std::vector<int> low(n, -1), ord(n, -1);
    std::vector<std::vector<Edge<T>>> ret;
    std::stack<Edge<T>> st;
    int t = 0;

    for(int i = 0; i < n; ++i){
      if(not check[i]) biconnected_components_impl::dfs(g, i, -1, check, low, ord, ret, st, t);
    }

    return ret;
  }
}
