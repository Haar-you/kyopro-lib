---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/binomial_coefficients_table.cpp\"\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  auto binomial_coefficients_table(int\
    \ n, int k){\n    std::vector<std::vector<T>> ret(n + 1, std::vector<T>(k + 1));\n\
    \    ret[0][0] = 1;\n\n    for(int i = 1; i <= n; ++i){\n      ret[i][0] = 1;\n\
    \n      for(int j = 1; j <= k; ++j){\n        ret[i][j] = ret[i - 1][j - 1] +\
    \ ret[i - 1][j];\n      }\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  auto binomial_coefficients_table(int n, int k){\n    std::vector<std::vector<T>>\
    \ ret(n + 1, std::vector<T>(k + 1));\n    ret[0][0] = 1;\n\n    for(int i = 1;\
    \ i <= n; ++i){\n      ret[i][0] = 1;\n\n      for(int j = 1; j <= k; ++j){\n\
    \        ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];\n      }\n    }\n\n  \
    \  return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Combinatorics/binomial_coefficients_table.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Combinatorics/binomial_coefficients_table.cpp
layout: document
title: Binomial coefficients table
---

## Operations

- `binomial_coefficients_table<T>(int n, int k) -> [[T]]`
	- $\binom{0}{0}$ ~ $\binom{n}{k}$を列挙する。
	- Time complexity $O(nk)$

## Requirements

## Notes

## Problems

## References
