#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  auto strongly_connected_components(const graph<T> &g){
    const int n = g.size();

    std::vector<int> ret(n), low(n, -1), ord(n, -1), S;
    std::vector<bool> check(n);
    S.reserve(n);
    int t = 0;
    int k = 0;

    auto dfs =
      [&](auto &dfs, int cur) -> void {
        low[cur] = ord[cur] = t++;
        S.push_back(cur);
        check[cur] = true;

        for(auto &e : g[cur]){
          if(ord[e.to] == -1){
            dfs(dfs, e.to);
            low[cur] = std::min(low[cur], low[e.to]);
          }else if(check[e.to]){
            low[cur] = std::min(low[cur], low[e.to]);
          }
        }

        if(low[cur] == ord[cur]){
          while(true){
            int u = S.back(); S.pop_back();
            check[u] = false;
            ret[u] = k;
            if(cur == u) break;
          }
          ++k;
        }
      };

    for(int i = 0; i < n; ++i){
      if(ord[i] == -1){
        t = 0;
        dfs(dfs, i);
      }
    }

    for(auto &x : ret) x = k - 1 - x;

    return std::make_pair(ret, k);
  }
}
