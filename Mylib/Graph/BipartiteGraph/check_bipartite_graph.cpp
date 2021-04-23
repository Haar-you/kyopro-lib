#pragma once
#include <optional>
#include <stack>
#include <utility>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  auto check_bipartite_graph(const graph<T> &g) {
    std::vector<std::optional<std::pair<std::vector<int>, std::vector<int>>>> ret;

    const int N = g.size();

    std::vector<int> check(N, -1);
    std::vector<bool> visit(N);

    for (int i = 0; i < N; ++i) {
      if (visit[i]) continue;

      std::vector<int> a, b;

      bool res =
          [&]() {
            std::stack<int> st;

            st.push(i);
            check[i] = 0;
            a.push_back(i);

            while (not st.empty()) {
              auto cur = st.top();
              st.pop();
              if (visit[cur]) continue;
              visit[cur] = true;

              for (auto &e : g[cur]) {
                if (check[e.to] == check[cur]) return false;

                if (check[e.to] == -1) {
                  if (check[cur] == 0) {
                    check[e.to] = 1;
                    b.push_back(e.to);
                  } else {
                    check[e.to] = 0;
                    a.push_back(e.to);
                  }

                  st.push(e.to);
                }
              }
            }

            return true;
          }();

      if (res) {
        ret.emplace_back(std::make_pair(a, b));
      } else {
        ret.emplace_back();
      }
    }

    return ret;
  }
}  // namespace haar_lib
