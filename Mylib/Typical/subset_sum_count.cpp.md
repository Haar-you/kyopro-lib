---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/subset_sum_count.cpp\"\n#include <cassert>\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  auto subset_sum_count(int\
    \ N, int K, const std::vector<int> &a) {\n    assert((int) a.size() == N);\n \
    \   std::vector<std::vector<T>> dp(2, std::vector<T>(K + 1));\n\n    dp[0][0]\
    \ = 1;\n\n    for (int i = 0; i < N; ++i) {\n      for (int j = 0; j <= K; ++j)\
    \ {\n        if (j >= a[i])\n          dp[(i + 1) & 1][j] = dp[i & 1][j - a[i]]\
    \ + dp[i & 1][j];\n        else\n          dp[(i + 1) & 1][j] = dp[i & 1][j];\n\
    \      }\n    }\n\n    return dp[N & 1];\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  auto subset_sum_count(int N, int K, const std::vector<int>\
    \ &a) {\n    assert((int) a.size() == N);\n    std::vector<std::vector<T>> dp(2,\
    \ std::vector<T>(K + 1));\n\n    dp[0][0] = 1;\n\n    for (int i = 0; i < N; ++i)\
    \ {\n      for (int j = 0; j <= K; ++j) {\n        if (j >= a[i])\n          dp[(i\
    \ + 1) & 1][j] = dp[i & 1][j - a[i]] + dp[i & 1][j];\n        else\n         \
    \ dp[(i + 1) & 1][j] = dp[i & 1][j];\n      }\n    }\n\n    return dp[N & 1];\n\
    \  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/subset_sum_count.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Typical/subset_sum_count.cpp
layout: document
title: Subset sum problem (Count)
---

## Operations

- `subset_sum_count(N, K, a[N])`
	- Time complexity $O(NK)$

## Requirements

## Notes

## Problems

## References

