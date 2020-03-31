#pragma once
#include <vector>
#include <optional>
#include <stack>
#include <utility>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @see https://atcoder.jp/contests/maximum-cup-2018/submissions/4199048
 * @see https://atcoder.jp/contests/arc099/submissions/7457350
 */
template <typename T> struct CheckBipartiteGraph{
  std::vector<std::optional<std::pair<int,int>>> results;
  bool all_bipartite;
  
  CheckBipartiteGraph(const Graph<T> &g): all_bipartite(true){
    const int n = g.size();

    std::vector<int> check(n,-1);
    std::vector<bool> visit(n,false);

    for(int i = 0; i < n; ++i){
      if(visit[i]) continue;

      auto t = aux(g, i, check, visit);
      results.push_back(t);

      if(not t){
        all_bipartite = false;
      }
    }
  }
  
  std::optional<std::pair<int,int>> aux(const Graph<T> &graph, int root, std::vector<int> &check, std::vector<bool> &visit){
    std::stack<int> st;

    int a = 1, b = 0;
 
    st.push(root);
    check[root] = 0;
 
    while(!st.empty()){
      auto cur = st.top(); st.pop();
      if(visit[cur]) continue;
      visit[cur] = true;
 
      for(auto &e : graph[cur]){
        if(check[e.to] == check[cur]) return std::nullopt;
 
        if(check[e.to] == -1){
          if(check[cur] == 0){
            check[e.to] = 1;
            ++b;
          }else{
            check[e.to] = 0;
            ++a;
          }
          st.push(e.to);
        }
      }
    }
  
    return {std::make_pair(a, b)};
  }
};
