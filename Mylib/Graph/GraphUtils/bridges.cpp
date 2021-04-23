#pragma once
#include <algorithm>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  namespace bridges_impl {
    template <typename T>
    int dfs(
        const graph<T> &graph,
        int cur,
        int par,
        std::vector<int> &visit,
        std::vector<int> &low,
        std::vector<edge<T>> &ret,
        int &v) {
      if (visit[cur] != -1) return visit[cur];
      visit[cur] = v;
      int temp   = v;
      ++v;
      for (auto &e : graph[cur]) {
        if (e.to == par) continue;
        int t = dfs(graph, e.to, cur, visit, low, ret, v);
        temp  = std::min(temp, t);
        if (low[e.to] > visit[cur]) ret.push_back(e);
      }
      return low[cur] = temp;
    }
  }  // namespace bridges_impl

  template <typename T>
  auto bridges(const graph<T> &graph) {
    const int n = graph.size();
    std::vector<int> visit(n, -1), low(n, -1);
    std::vector<edge<T>> ret;
    int v = 0;

    for (int i = 0; i < n; ++i)
      if (visit[i] == -1) bridges_impl::dfs(graph, i, -1, visit, low, ret, v);
    return ret;
  }
}  // namespace haar_lib
