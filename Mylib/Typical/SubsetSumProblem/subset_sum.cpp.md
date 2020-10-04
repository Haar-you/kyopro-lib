---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/SubsetSumProblem/subset_sum.cpp\"\n#include\
    \ <vector>\n\nnamespace haar_lib {\n  auto subset_sum(int N, int K, const std::vector<int>\
    \ &a){\n    std::vector<std::vector<bool>> dp(2, std::vector<bool>(K + 1));\n\n\
    \    dp[0][0] = true;\n\n    for(int i = 0; i < N; ++i){\n      for(int j = 0;\
    \ j <= K; ++j){\n        if(j >= a[i]) dp[(i + 1) & 1][j] = dp[i & 1][j - a[i]]\
    \ or dp[i & 1][j];\n        else dp[(i + 1) & 1][j] = dp[i & 1][j];\n      }\n\
    \    }\n\n    return dp[N & 1];\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  auto subset_sum(int\
    \ N, int K, const std::vector<int> &a){\n    std::vector<std::vector<bool>> dp(2,\
    \ std::vector<bool>(K + 1));\n\n    dp[0][0] = true;\n\n    for(int i = 0; i <\
    \ N; ++i){\n      for(int j = 0; j <= K; ++j){\n        if(j >= a[i]) dp[(i +\
    \ 1) & 1][j] = dp[i & 1][j - a[i]] or dp[i & 1][j];\n        else dp[(i + 1) &\
    \ 1][j] = dp[i & 1][j];\n      }\n    }\n\n    return dp[N & 1];\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/SubsetSumProblem/subset_sum.cpp
  requiredBy: []
  timestamp: '2020-09-21 02:36:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Typical/SubsetSumProblem/subset_sum.cpp
layout: document
title: Subset sum problem
---

## Operations

- `subset_sum(N, K, a[N])`
	- Time complexity $O(NK)$

## Requirements

## Notes

## Problems

## References

