#pragma once
#include <algorithm>
#include <optional>
#include <vector>

namespace haar_lib {
  namespace enumerate_functional_cycles_impl {
    constexpr static int SEARCHED  = 1;
    constexpr static int SEARCHING = 2;

    std::optional<int> rec(
        const std::vector<int> &g,
        int cur,
        std::vector<int> &temp,
        std::vector<std::vector<int>> &ret,
        std::vector<int> &check) {
      if (check[cur] == SEARCHED) return std::nullopt;
      if (check[cur] == SEARCHING) return {cur};
      check[cur] = SEARCHING;

      const int i = g[cur];

      if (auto res = rec(g, i, temp, ret, check); res) {
        if (*res != -1) {
          temp.push_back(i);
          if (*res == cur) {
            check[cur] = SEARCHED;
            return {-1};
          }
        }

        check[cur] = SEARCHED;
        return res;
      }

      check[cur] = SEARCHED;
      return std::nullopt;
    }
  }  // namespace enumerate_functional_cycles_impl

  std::vector<std::vector<int>> enumerate_functional_cycles(std::vector<int> g) {
    const int n = g.size();

    std::vector<std::vector<int>> ret;
    std::vector<int> check(n);

    for (int i = 0; i < n; ++i) {
      if (check[i] == 0) {
        std::vector<int> temp;
        auto res = enumerate_functional_cycles_impl::rec(g, i, temp, ret, check);
        if (res) {
          std::reverse(temp.begin(), temp.end());
          ret.push_back(temp);
        }
      }
    }

    return ret;
  }
}  // namespace haar_lib
