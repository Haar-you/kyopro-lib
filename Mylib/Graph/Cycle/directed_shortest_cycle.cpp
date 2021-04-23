#pragma once
#include <algorithm>
#include <climits>
#include <optional>
#include <queue>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  std::optional<std::vector<int>> direct_shortest_cycle(const graph<T> &g, int src) {
    std::optional<std::vector<int>> ret;
    const int N = g.size();
    int min_len = INT_MAX;
    std::queue<int> q;
    q.push(src);

    std::vector<int> dist(N), pre(N);
    std::vector<bool> visited(N);

    while (not q.empty()) {
      int cur = q.front();
      q.pop();

      if (visited[cur]) continue;
      visited[cur] = true;

      for (auto &e : g[cur]) {
        if (e.to == src) {
          if (dist[cur] < min_len) {
            min_len = dist[cur];
            ret     = std::vector<int>();

            int j = cur;
            while (1) {
              (*ret).push_back(j);
              if (j == src) break;

              j = pre[j];
            }

            std::reverse((*ret).begin(), (*ret).end());
          }

          return ret;
        }

        if (not visited[e.to]) {
          dist[e.to] = dist[cur] + 1;
          pre[e.to]  = cur;
          q.push(e.to);
        }
      }
    }

    return ret;
  }
}  // namespace haar_lib
