---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_1_E/main.test.cpp
    title: test/aoj/DPL_1_E/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/String/levenshtein_distance.cpp\"\n#include <algorithm>\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename Container>\n \
    \ int levenshtein_distance(const Container &a, const Container &b) {\n    const\
    \ int n = a.size(), m = b.size();\n    std::vector<std::vector<int>> dp(n + 1,\
    \ std::vector<int>(m + 1, 0));\n\n    for (int i = 0; i <= n; ++i) dp[i][0] =\
    \ i;\n    for (int i = 0; i <= m; ++i) dp[0][i] = i;\n\n    for (int i = 0; i\
    \ < n; ++i) {\n      for (int j = 0; j < m; ++j) {\n        dp[i + 1][j + 1] =\
    \ std::min(dp[i][j + 1] + 1, dp[i + 1][j] + 1);\n\n        if (a[i] == b[j]) {\n\
    \          dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j]);\n        }\
    \ else {\n          dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j] + 1);\n\
    \        }\n      }\n    }\n    return dp[n][m];\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename Container>\n  int levenshtein_distance(const Container\
    \ &a, const Container &b) {\n    const int n = a.size(), m = b.size();\n    std::vector<std::vector<int>>\
    \ dp(n + 1, std::vector<int>(m + 1, 0));\n\n    for (int i = 0; i <= n; ++i) dp[i][0]\
    \ = i;\n    for (int i = 0; i <= m; ++i) dp[0][i] = i;\n\n    for (int i = 0;\
    \ i < n; ++i) {\n      for (int j = 0; j < m; ++j) {\n        dp[i + 1][j + 1]\
    \ = std::min(dp[i][j + 1] + 1, dp[i + 1][j] + 1);\n\n        if (a[i] == b[j])\
    \ {\n          dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j]);\n    \
    \    } else {\n          dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j]\
    \ + 1);\n        }\n      }\n    }\n    return dp[n][m];\n  }\n}  // namespace\
    \ haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/levenshtein_distance.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DPL_1_E/main.test.cpp
documentation_of: Mylib/String/levenshtein_distance.cpp
layout: document
title: Levenshtein distance / Edit distance
---

## Operations

## Requirements

## Notes

## Problems

## References