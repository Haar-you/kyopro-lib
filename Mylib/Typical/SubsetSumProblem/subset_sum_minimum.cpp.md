---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/SubsetSumProblem/subset_sum_minimum.cpp\"\n\
    #include <vector>\n#include <algorithm>\n#include <climits>\n\nnamespace haar_lib\
    \ {\n  auto subset_sum_minimum(int N, int K, const std::vector<int> &a){\n   \
    \ std::vector<std::vector<int64_t>> dp(2, std::vector<int64_t>(K + 1, INT_MAX));\n\
    \n    dp[0][0] = 0;\n\n    for(int i = 0; i < N; ++i){\n      for(int j = 0; j\
    \ <= K; ++j){\n        if(j >= a[i]) dp[(i + 1) & 1][j] = std::min(dp[i & 1][j\
    \ - a[i]] + 1, dp[i & 1][j]);\n        else dp[(i + 1) & 1][j] = dp[i & 1][j];\n\
    \      }\n    }\n\n    for(int i = 0; i <= K; ++i){\n      if(dp[N & 1][i] ==\
    \ INT_MAX) dp[N & 1][i] = -1;\n    }\n\n    return dp[N & 1];\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <climits>\n\
    \nnamespace haar_lib {\n  auto subset_sum_minimum(int N, int K, const std::vector<int>\
    \ &a){\n    std::vector<std::vector<int64_t>> dp(2, std::vector<int64_t>(K + 1,\
    \ INT_MAX));\n\n    dp[0][0] = 0;\n\n    for(int i = 0; i < N; ++i){\n      for(int\
    \ j = 0; j <= K; ++j){\n        if(j >= a[i]) dp[(i + 1) & 1][j] = std::min(dp[i\
    \ & 1][j - a[i]] + 1, dp[i & 1][j]);\n        else dp[(i + 1) & 1][j] = dp[i &\
    \ 1][j];\n      }\n    }\n\n    for(int i = 0; i <= K; ++i){\n      if(dp[N &\
    \ 1][i] == INT_MAX) dp[N & 1][i] = -1;\n    }\n\n    return dp[N & 1];\n  }\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/SubsetSumProblem/subset_sum_minimum.cpp
  requiredBy: []
  timestamp: '2020-09-21 02:36:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Typical/SubsetSumProblem/subset_sum_minimum.cpp
layout: document
title: Subset sum problem (Minimum)
---

## Operations

- `subset_sum_minimum(N, K, a[N])`
	-  和が`K`になる部分集合の最小サイズ。そのような部分集合が存在しないとき-1を返す。
	- Time complexity $O(NK)$

## Requirements

## Notes

## Problems

## References

