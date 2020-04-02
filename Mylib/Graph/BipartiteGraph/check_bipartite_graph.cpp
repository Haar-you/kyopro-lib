#pragma once
#include <vector>
#include <optional>
#include <stack>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 連結グラフの二部グラフ判定
 */
template <typename T>
std::optional<std::vector<int>> is_bipartite_graph(const Graph<T> &graph){
  std::vector<int> check(graph.size(), -1);
  std::vector<bool> visit(graph.size(), false);
  std::stack<int> st;

  st.push(0);
  check[0] = 0;

  while(not st.empty()){
    auto cur = st.top(); st.pop();
    if(visit[cur]) continue;
    visit[cur] = true;

    for(auto &e : graph[cur]){
      if(check[e.to] == check[e.from]) return std::nullopt;

      if(check[e.to] == -1){
        check[e.to] = (check[e.from] == 0 ? 1 : 0);
      }

      st.push(e.to);
    }
  }

  for(auto x : check) if(x == -1) return std::nullopt;

  return {check};
}
