#pragma once
#include <vector>
#include <algorithm>
#include <utility>

/**
 * @title Weighted interval scheduling problem
 * @docs weighted_interval_scheduling.md
 */
template <typename T, typename U>
U weighted_interval_scheduling(std::vector<T> from, std::vector<T> to, std::vector<U> value){
  int n = from.size();

  std::vector<T> c(from);
  c.insert(c.end(), to.begin(), to.end());

  std::sort(c.begin(), c.end());
  c.erase(std::unique(c.begin(), c.end()), c.end());

  for(int i = 0; i < n; ++i){
    from[i] = lower_bound(c.begin(), c.end(), from[i]) - c.begin();
    to[i] = lower_bound(c.begin(), c.end(), to[i]) - c.begin();
  }

  int m = c.size();

  std::vector<U> dp(m + 1);

  std::vector<std::vector<std::pair<int, U>>> memo(m);
  for(int i = 0; i < n; ++i){
    memo[to[i]].emplace_back(from[i], value[i]);
  }

  for(int i = 0; i < m; ++i){
    dp[i + 1] = dp[i];

    for(auto &p : memo[i]){
      dp[i + 1] = std::max(dp[i + 1], dp[p.first] + p.second);
    }
  }

  return dp[m];
}
