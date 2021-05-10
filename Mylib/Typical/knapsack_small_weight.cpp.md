---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_1_B/main.test.cpp
    title: test/aoj/DPL_1_B/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/knapsack_small_weight.cpp\"\n#include <algorithm>\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename Weight, typename\
    \ Value>\n  Value knapsack_small_weight(int N, Weight cap, const std::vector<Weight>\
    \ &w, const std::vector<Value> &v) {\n    std::vector<std::vector<Value>> dp(N\
    \ + 1, std::vector<Value>(cap + 1));\n\n    for (int i = 0; i < N; ++i) {\n  \
    \    for (int j = 0; j <= cap; ++j) {\n        dp[i + 1][j] = std::max(dp[i +\
    \ 1][j], dp[i][j]);\n        if (j + w[i] <= cap) dp[i + 1][j + w[i]] = std::max(dp[i\
    \ + 1][j + w[i]], dp[i][j] + v[i]);\n      }\n    }\n\n    return dp[N][cap];\n\
    \  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename Weight, typename Value>\n  Value knapsack_small_weight(int\
    \ N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v) {\n\
    \    std::vector<std::vector<Value>> dp(N + 1, std::vector<Value>(cap + 1));\n\
    \n    for (int i = 0; i < N; ++i) {\n      for (int j = 0; j <= cap; ++j) {\n\
    \        dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);\n        if (j + w[i]\
    \ <= cap) dp[i + 1][j + w[i]] = std::max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);\n\
    \      }\n    }\n\n    return dp[N][cap];\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/knapsack_small_weight.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DPL_1_B/main.test.cpp
documentation_of: Mylib/Typical/knapsack_small_weight.cpp
layout: document
title: 0-1 Knapsack problem (Small weight)
---

## Operations

- `knapsack_small_weight(int N, Weight cap, Weight w[N], Value v[N])`
	- 0-1ナップサック問題を解く。
	- Time complexity $O(N * cap)$

## Requirements

## Notes

## Problems

- [EDPC D - Knapsack 1](https://atcoder.jp/contests/dp/tasks/dp_d)

## References