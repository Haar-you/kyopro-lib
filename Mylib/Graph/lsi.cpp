#pragma once
#include <algorithm>
#include <cassert>
#include <optional>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T, typename U>
  std::optional<std::vector<U>> lsi(const graph<T> &g, const std::vector<U> &c) {
    const int N = g.size();
    assert((int) c.size() == N);

    graph<T> h(N);

    int M = 0;
    for (auto &v : g) {
      for (auto &e : v) {
        h[e.from].push_back(e);
        h[e.to].push_back(e);
        M = std::max(M, e.index + 1);
      }
    }

    std::vector<U> ret(M);
    std::vector<bool> check(N);

    auto dfs =
        [&](auto &dfs, int cur) -> U {
      check[cur] = true;

      U t = c[cur];

      for (auto &e : h[cur]) {
        auto v = e.from == cur ? e.to : e.from;
        if (check[v]) continue;

        auto y = dfs(dfs, v);

        if (e.from == cur)
          ret[e.index] = y;
        else
          ret[e.index] = -y;

        t += y;
      }

      return t;
    };

    for (int i = 0; i < N; ++i) {
      if (check[i]) continue;
      auto y = dfs(dfs, i);
      if (y != 0) return std::nullopt;
    }

    return ret;
  }
}  // namespace haar_lib
