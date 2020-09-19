---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_2_C/main.test.cpp
    title: test/aoj/DPL_2_C/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DynamicProgramming/bitonic_tour.cpp\"\n#include <vector>\n\
    #include <limits>\n#include <algorithm>\n#include <cmath>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  double bitonic_tour(int n, const std::vector<T>\
    \ &x, const std::vector<T> &y){\n    std::vector<std::vector<double>> dist(n,\
    \ std::vector<double>(n));\n    for(int i = 0; i < n; ++i){\n      for(int j =\
    \ 0; j < n; ++j){\n        double dx = x[i] - x[j];\n        double dy = y[i]\
    \ - y[j];\n        dist[i][j] = std::sqrt(dx * dx + dy * dy);\n      }\n    }\n\
    \n    std::vector<std::vector<double>> dp(n, std::vector<double>(n, std::numeric_limits<double>::max()));\n\
    \n    dp[0][0] = 0;\n\n    for(int i = 0; i < n; ++i){\n      for(int j = 0; j\
    \ < n; ++j){\n        dp[i][i] = std::min(dp[i][i], dp[i][j] + dist[i][j]);\n\
    \        if(i + 1 < n){\n          dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]\
    \ + dist[i][i + 1]);\n          dp[i][i + 1] = std::min(dp[i][i + 1], dp[i][j]\
    \ + dist[j][i + 1]);\n        }\n        if(j + 1 < n){\n          dp[i][j + 1]\
    \ = std::min(dp[i][j + 1], dp[i][j] + dist[j][j + 1]);\n          dp[j + 1][j]\
    \ = std::min(dp[j + 1][j], dp[i][j] + dist[i][j + 1]);\n        }\n      }\n \
    \   }\n\n    return dp[n - 1][n - 1];\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <limits>\n#include <algorithm>\n\
    #include <cmath>\n\nnamespace haar_lib {\n  template <typename T>\n  double bitonic_tour(int\
    \ n, const std::vector<T> &x, const std::vector<T> &y){\n    std::vector<std::vector<double>>\
    \ dist(n, std::vector<double>(n));\n    for(int i = 0; i < n; ++i){\n      for(int\
    \ j = 0; j < n; ++j){\n        double dx = x[i] - x[j];\n        double dy = y[i]\
    \ - y[j];\n        dist[i][j] = std::sqrt(dx * dx + dy * dy);\n      }\n    }\n\
    \n    std::vector<std::vector<double>> dp(n, std::vector<double>(n, std::numeric_limits<double>::max()));\n\
    \n    dp[0][0] = 0;\n\n    for(int i = 0; i < n; ++i){\n      for(int j = 0; j\
    \ < n; ++j){\n        dp[i][i] = std::min(dp[i][i], dp[i][j] + dist[i][j]);\n\
    \        if(i + 1 < n){\n          dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]\
    \ + dist[i][i + 1]);\n          dp[i][i + 1] = std::min(dp[i][i + 1], dp[i][j]\
    \ + dist[j][i + 1]);\n        }\n        if(j + 1 < n){\n          dp[i][j + 1]\
    \ = std::min(dp[i][j + 1], dp[i][j] + dist[j][j + 1]);\n          dp[j + 1][j]\
    \ = std::min(dp[j + 1][j], dp[i][j] + dist[i][j + 1]);\n        }\n      }\n \
    \   }\n\n    return dp[n - 1][n - 1];\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DynamicProgramming/bitonic_tour.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DPL_2_C/main.test.cpp
documentation_of: Mylib/DynamicProgramming/bitonic_tour.cpp
layout: document
title: Bitonic tour
---

## Operations

## Requirements

## Notes

## Problems

## References
