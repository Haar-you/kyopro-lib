---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_10_C/main.test.cpp
    title: test/aoj/ALDS1_10_C/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/String/longest_common_subsequence.cpp\"\n#include\
    \ <vector>\n#include <algorithm>\n\nnamespace haar_lib {\n  template <typename\
    \ Container>\n  int lcs(const Container &a, const Container &b){\n    const int\
    \ n = a.size(), m = b.size();\n\n    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m\
    \ + 1, 0));\n    for(int i = 1; i <= n; ++i){\n      for(int j = 1; j <= m; ++j){\n\
    \        dp[i][j] = a[i - 1] == b[j - 1] ? dp[i - 1][j - 1] + 1 : std::max(dp[i\
    \ - 1][j], dp[i][j - 1]);\n      }\n    }\n\n    return dp[n][m];\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n\nnamespace haar_lib\
    \ {\n  template <typename Container>\n  int lcs(const Container &a, const Container\
    \ &b){\n    const int n = a.size(), m = b.size();\n\n    std::vector<std::vector<int>>\
    \ dp(n + 1, std::vector<int>(m + 1, 0));\n    for(int i = 1; i <= n; ++i){\n \
    \     for(int j = 1; j <= m; ++j){\n        dp[i][j] = a[i - 1] == b[j - 1] ?\
    \ dp[i - 1][j - 1] + 1 : std::max(dp[i - 1][j], dp[i][j - 1]);\n      }\n    }\n\
    \n    return dp[n][m];\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/longest_common_subsequence.cpp
  requiredBy: []
  timestamp: '2020-10-10 11:12:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_10_C/main.test.cpp
documentation_of: Mylib/String/longest_common_subsequence.cpp
layout: document
title: Longest common subsequence
---

## Operations

- `lcs(a[N], b[M])`
	- `a`と`b`の最長共通部分列の長さを返す。
	- Time complexity $O(NM)$

## Requirements

## Notes

## Problems

## References

