---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_1_F/main.test.cpp
    title: test/aoj/DPL_1_F/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/KnapsackProblem/knapsack_small_value.cpp\"\
    \n#include <vector>\n#include <algorithm>\n#include <numeric>\n#include <climits>\n\
    \nnamespace haar_lib {\n  template <typename Weight, typename Value>\n  Value\
    \ knapsack_small_value(int N, Weight cap, const std::vector<Weight> &w, const\
    \ std::vector<Value> &v){\n    const Value MAX_V = std::accumulate(v.begin(),\
    \ v.end(), 0);\n    std::vector<std::vector<Value>> dp(N + 1, std::vector<Value>(MAX_V\
    \ + 1, LLONG_MAX));\n\n    dp[0][0] = 0;\n\n    for(int i = 0; i < N; ++i){\n\
    \      for(int j = 0; j <= MAX_V; ++j){\n        dp[i + 1][j] = std::min(dp[i\
    \ + 1][j], dp[i][j]);\n        if(j + v[i] <= MAX_V and dp[i][j] < LLONG_MAX){\n\
    \          dp[i + 1][j + v[i]] = std::min(dp[i + 1][j + v[i]], dp[i][j] + w[i]);\n\
    \        }\n      }\n    }\n\n    Value ret = 0;\n\n    for(int i = 0; i <= MAX_V;\
    \ ++i){\n      if(dp[N][i] <= cap) ret = i;\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <numeric>\n\
    #include <climits>\n\nnamespace haar_lib {\n  template <typename Weight, typename\
    \ Value>\n  Value knapsack_small_value(int N, Weight cap, const std::vector<Weight>\
    \ &w, const std::vector<Value> &v){\n    const Value MAX_V = std::accumulate(v.begin(),\
    \ v.end(), 0);\n    std::vector<std::vector<Value>> dp(N + 1, std::vector<Value>(MAX_V\
    \ + 1, LLONG_MAX));\n\n    dp[0][0] = 0;\n\n    for(int i = 0; i < N; ++i){\n\
    \      for(int j = 0; j <= MAX_V; ++j){\n        dp[i + 1][j] = std::min(dp[i\
    \ + 1][j], dp[i][j]);\n        if(j + v[i] <= MAX_V and dp[i][j] < LLONG_MAX){\n\
    \          dp[i + 1][j + v[i]] = std::min(dp[i + 1][j + v[i]], dp[i][j] + w[i]);\n\
    \        }\n      }\n    }\n\n    Value ret = 0;\n\n    for(int i = 0; i <= MAX_V;\
    \ ++i){\n      if(dp[N][i] <= cap) ret = i;\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/KnapsackProblem/knapsack_small_value.cpp
  requiredBy: []
  timestamp: '2020-09-21 02:36:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DPL_1_F/main.test.cpp
documentation_of: Mylib/Typical/KnapsackProblem/knapsack_small_value.cpp
layout: document
title: 0-1 Knapsack problem (Small value)
---

## Operations

- `knapsack_small_value(int N, Weight cap, Weight w[N], Value v[N])`
	- 0-1ナップサック問題を解く。
	- Time complexity $O(N \sum v)$

## Requirements

## Notes

## Problems

- [EDPC E - Knapsack 2](https://atcoder.jp/contests/dp/tasks/dp_e)

## References

