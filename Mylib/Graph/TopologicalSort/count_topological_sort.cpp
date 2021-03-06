#pragma once
#include <cstdint>
#include <vector>

namespace haar_lib {
  int64_t count_topological_sort(const std::vector<int> &g) {
    const int n = g.size();
    std::vector<int64_t> dp(1 << n);

    dp[0] = 1;

    for (int s = 0; s < (1 << n); ++s) {
      for (int i = 0; i < n; ++i) {
        if (s & (1 << i)) {
          if ((s ^ (1 << i)) & g[i]) continue;
          dp[s] += dp[s ^ (1 << i)];
        }
      }
    }

    return dp[(1 << n) - 1];
  }
}  // namespace haar_lib
