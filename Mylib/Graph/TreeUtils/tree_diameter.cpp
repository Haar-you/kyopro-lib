#pragma once
#include <algorithm>
#include <stack>
#include <utility>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  std::pair<T, std::vector<int>> tree_diameter(const tree<T> &tr) {
    const int N = tr.size();

    std::vector<bool> check(N);
    std::vector<T> dp(N);
    std::stack<int> st;

    st.push(0);
    while (st.size()) {
      int i = st.top();
      st.pop();

      check[i] = true;

      for (const auto &e : tr[i]) {
        if (not check[e.to]) {
          dp[e.to] = dp[i] + e.cost;
          st.push(e.to);
        }
      }
    }

    const int u = std::max_element(dp.begin(), dp.end()) - dp.begin();

    dp.assign(N, 0);
    check.assign(N, false);

    std::vector<int> prev(N);

    st.push(u);
    while (st.size()) {
      int i = st.top();
      st.pop();

      check[i] = true;

      for (const auto &e : tr[i]) {
        if (not check[e.to]) {
          dp[e.to] = dp[i] + e.cost;
          st.push(e.to);
          prev[e.to] = i;
        }
      }
    }

    const int v = std::max_element(dp.begin(), dp.end()) - dp.begin();

    std::vector<int> ret;

    int cur = v;
    while (1) {
      ret.push_back(cur);
      if (cur == u) break;
      cur = prev[cur];
    }

    return std::make_pair(dp[v], ret);
  }
}  // namespace haar_lib
