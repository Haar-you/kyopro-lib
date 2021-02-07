---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_1_B/main.test.cpp
    title: test/aoj/DPL_1_B/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/knapsack_small_weight.cpp\"\n#include <vector>\n\
    #include <algorithm>\n\nnamespace haar_lib {\n  template <typename Weight, typename\
    \ Value>\n  Value knapsack_small_weight(int N, Weight cap, const std::vector<Weight>\
    \ &w, const std::vector<Value> &v){\n    std::vector<std::vector<Value>> dp(N\
    \ + 1, std::vector<Value>(cap + 1));\n\n    for(int i = 0; i < N; ++i){\n    \
    \  for(int j = 0; j <= cap; ++j){\n        dp[i + 1][j] = std::max(dp[i + 1][j],\
    \ dp[i][j]);\n        if(j + w[i] <= cap) dp[i + 1][j + w[i]] = std::max(dp[i\
    \ + 1][j + w[i]], dp[i][j] + v[i]);\n      }\n    }\n\n    return dp[N][cap];\n\
    \  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n\nnamespace haar_lib\
    \ {\n  template <typename Weight, typename Value>\n  Value knapsack_small_weight(int\
    \ N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v){\n\
    \    std::vector<std::vector<Value>> dp(N + 1, std::vector<Value>(cap + 1));\n\
    \n    for(int i = 0; i < N; ++i){\n      for(int j = 0; j <= cap; ++j){\n    \
    \    dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);\n        if(j + w[i] <=\
    \ cap) dp[i + 1][j + w[i]] = std::max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);\n\
    \      }\n    }\n\n    return dp[N][cap];\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/knapsack_small_weight.cpp
  requiredBy: []
  timestamp: '2020-11-07 03:03:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
