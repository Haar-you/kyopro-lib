#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Strongly connected components
 * @docs strongly_connected_components.md
 */
namespace haar_lib {
  template <typename T>
  auto strongly_connected_components(const Graph<T> &g){
    const int n = g.size();

    std::vector<bool> visit(n);
    std::vector<int> check(n);
    std::vector<int> result(n, -1);

    auto dfs =
      [&](auto &f, int cur) -> void {
        visit[cur] = true;
        for(const auto &e : g[cur]){
          if(not visit[e.to]) f(f, e.to);
        }
        check.push_back(cur);
      };

    for(int i = 0; i < n; ++i) if(not visit[i]) dfs(dfs, i);

    std::reverse(check.begin(), check.end());

    Graph<T> rg(n);

    auto rdfs =
      [&](auto &f, int cur, int i) -> void {
        result[cur] = i;
        for(const auto &e : rg[cur]){
          if(result[e.to] == -1) f(f, e.to, i);
        }
      };

    for(int i = 0; i < n; ++i) for(const auto &e : g[i]) rg[e.to].emplace_back(e.to, e.from, e.cost);

    int i = 0;
    for(auto c : check) if(result[c] == -1) rdfs(rdfs, c, i), ++i;

    return std::make_pair(result, i);
  }
}
