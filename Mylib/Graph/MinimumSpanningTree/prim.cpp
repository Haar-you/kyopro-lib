#pragma once
#include <queue>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  std::vector<edge<T>> prim(const graph<T> &graph) {
    const int n = graph.size();
    std::vector<bool> visit(n, false);
    std::vector<edge<T>> ret;

    auto cmp = [](const auto &a, const auto &b) { return a.cost > b.cost; };
    std::priority_queue<edge<T>, std::vector<edge<T>>, decltype(cmp)> pq(cmp);

    visit[0] = true;
    for (auto &e : graph[0]) pq.push(e);

    while (not pq.empty()) {
      auto t = pq.top();
      pq.pop();

      if (visit[t.from] == visit[t.to]) continue;

      int i = visit[t.from] ? t.to : t.from;
      for (auto &e : graph[i]) {
        pq.push(e);
      }

      visit[i] = true;
      ret.push_back(t);
    }

    return ret;
  }
}  // namespace haar_lib
