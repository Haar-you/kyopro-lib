#pragma once
#include <algorithm>
#include <vector>
#include "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  namespace chu_liu_edmonds_impl {
    template <typename T>
    graph<T> rec(graph<T> g, int r) {
      const int N = g.size();

      graph<T> in_edges(N);

      for (int i = 0; i < N; ++i) {
        if (i != r) {
          auto e = *std::min_element(
              g[i].begin(), g[i].end(),
              [](const auto &a, const auto &b) {
                return a.cost < b.cost;
              });

          in_edges[i].push_back(e);
        }
      }

      const auto [s, m] = strongly_connected_components(in_edges);

      std::vector<std::vector<int>> v(m);
      for (int i = 0; i < N; ++i) {
        v[s[i]].push_back(i);
      }

      int count_cycle = 0;
      for (int i = 0; i < m; ++i) {
        if (v[i].size() > 1) {
          for (int j : v[i]) {
            auto c =
                *std::min_element(
                    g[j].begin(), g[j].end(),
                    [](const auto &a, const auto &b) { return a.cost < b.cost; });

            for (auto &e : g[j]) {
              e.cost -= c.cost;
            }
          }
          ++count_cycle;
        }
      }

      if (count_cycle == 0) {
        return in_edges;
      }

      graph<T> G(m);
      const int R = s[r];
      for (int i = 0; i < N; ++i) {
        for (auto &e : g[i]) {
          if (s[e.from] == s[e.to]) continue;
          G.add_edge(s[e.from], s[e.to], e.cost);
        }
      }

      auto res = rec(G, R);

      for (int i = 0; i < m; ++i) {
        if (i == R) continue;

        int j = res[i][0].to;

        std::vector<edge<T>> c;

        for (int x : v[i]) {
          for (auto &e : g[x]) {
            if (s[e.to] == j) {
              c.push_back(e);
            }
          }
        }

        auto e =
            *std::min_element(
                c.begin(), c.end(),
                [](const auto &a, const auto &b) { return a.cost < b.cost; });

        in_edges[e.from][0] = e;
      }

      return in_edges;
    }
  }  // namespace chu_liu_edmonds_impl

  template <typename T>
  auto chu_liu_edmonds(graph<T> g, int r) {
    std::vector<edge<T>> ret;

    const int N = g.size();

    graph<T> rg(N);
    for (int i = 0; i < N; ++i) {
      for (auto &e : g[i]) {
        rg.add_edge(e.to, e.from, e.cost);
      }
    }

    auto res = chu_liu_edmonds_impl::rec(rg, r);

    for (int i = 0; i < N; ++i) {
      if (i != r) {
        std::vector<T> c;

        for (auto &e : rg[i]) {
          if (e.to == res[i][0].to) {
            c.push_back(e.cost);
          }
        }

        ret.emplace_back(res[i][0].to, i, *std::min_element(c.begin(), c.end()));
      }
    }

    return ret;
  }
}  // namespace haar_lib
