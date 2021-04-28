---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_1_C/main.test.cpp
    title: test/aoj/DPL_1_C/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/knapsack_unlimited.cpp\"\n#include <algorithm>\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename Weight, typename\
    \ Value>\n  Value knapsack_unlimited(int N, Weight cap, const std::vector<Weight>\
    \ &w, const std::vector<Value> &v) {\n    std::vector<std::vector<Value>> dp(N\
    \ + 1, std::vector<Value>(cap + 1));\n\n    for (int i = 0; i < N; ++i) {\n  \
    \    for (int j = 0; j <= cap; ++j) {\n        if (j < w[i])\n          dp[i +\
    \ 1][j] = dp[i][j];\n        else\n          dp[i + 1][j] = std::max(dp[i][j],\
    \ dp[i + 1][j - w[i]] + v[i]);\n      }\n    }\n\n    return dp[N][cap];\n  }\n\
    }  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename Weight, typename Value>\n  Value knapsack_unlimited(int\
    \ N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v) {\n\
    \    std::vector<std::vector<Value>> dp(N + 1, std::vector<Value>(cap + 1));\n\
    \n    for (int i = 0; i < N; ++i) {\n      for (int j = 0; j <= cap; ++j) {\n\
    \        if (j < w[i])\n          dp[i + 1][j] = dp[i][j];\n        else\n   \
    \       dp[i + 1][j] = std::max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);\n     \
    \ }\n    }\n\n    return dp[N][cap];\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/knapsack_unlimited.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DPL_1_C/main.test.cpp
documentation_of: Mylib/Typical/knapsack_unlimited.cpp
layout: document
title: Knapsack problem (Without quantity limitations)
---

## Operations

- `knapsack_unlimited(int N, Weight cap, Weight w[N], Value v[N])`
	- 個数制限なしナップサック問題を解く。
	- Time complexity $O(N * cap)$

## Requirements

## Notes

## Problems

- [AOJ DPL_1_C Knapsack Problem](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C)

## References

