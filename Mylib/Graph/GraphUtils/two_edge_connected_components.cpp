#pragma once
#include <vector>
#include <stack>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Two edge connected components
 * @docs two_edge_connected_components.md
 */
namespace haar_lib {
  namespace two_edge_connected_components_impl {
    template <typename T>
    int dfs(
      const graph<T> &g,
      int cur,
      int par,
      std::vector<int> &low,
      std::vector<int> &order,
      std::vector<std::vector<int>> &ret,
      std::stack<int> &st,
      int &v
    ){
      if(order[cur] != -1) return order[cur];
      order[cur] = v;
      int temp = v++;
      st.push(cur);

      int count = 0;

      for(const auto &e : g[cur]){
        if(e.to == par){
          ++count;
          if(count == 1) continue;
        }

        const int t = dfs(g, e.to, cur, low, order, ret, st, v);
        temp = std::min(temp, t);

        if(low[e.to] > order[cur]){ // e is a bridge
          std::vector<int> cc;
          while(true){
            int c = st.top();
            cc.emplace_back(c);
            st.pop();
            if(c == e.to) break;
          }
          ret.emplace_back(cc);
        }
      }

      return low[cur] = temp;
    }
  }

  template <typename T>
  auto two_edge_connected_components(const graph<T> &g){
    const int n = g.size();

    std::vector<int> low(n, -1), order(n, -1);
    std::vector<std::vector<int>> ret;
    std::stack<int> st;
    int v = 0;

    for(int i = 0; i < n; ++i){
      if(order[i] == -1){
        two_edge_connected_components_impl::dfs(g, i, -1, low, order, ret, st, v);
        if(not st.empty()){
          std::vector<int> cc;
          while(not st.empty()) cc.emplace_back(st.top()), st.pop();
          ret.emplace_back(cc);
        }
      }
    }

    return ret;
  }
}
