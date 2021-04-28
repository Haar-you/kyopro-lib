---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_5_I/main.table.test.cpp
    title: test/aoj/DPL_5_I/main.table.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/stirling_number_second_table.cpp\"\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  auto stirling_number_of_second_kind_table(int\
    \ n) -> std::vector<std::vector<T>> {\n    std::vector<std::vector<T>> ret(n +\
    \ 1, std::vector<T>(n + 1));\n\n    ret[0][0] = 1;\n\n    for (int i = 1; i <=\
    \ n; ++i) ret[i][1] = ret[i][i] = 1;\n\n    for (int i = 3; i <= n; ++i) {\n \
    \     for (int j = 2; j < i; ++j) {\n        ret[i][j] = ret[i - 1][j - 1] + j\
    \ * ret[i - 1][j];\n      }\n    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  auto stirling_number_of_second_kind_table(int n) -> std::vector<std::vector<T>>\
    \ {\n    std::vector<std::vector<T>> ret(n + 1, std::vector<T>(n + 1));\n\n  \
    \  ret[0][0] = 1;\n\n    for (int i = 1; i <= n; ++i) ret[i][1] = ret[i][i] =\
    \ 1;\n\n    for (int i = 3; i <= n; ++i) {\n      for (int j = 2; j < i; ++j)\
    \ {\n        ret[i][j] = ret[i - 1][j - 1] + j * ret[i - 1][j];\n      }\n   \
    \ }\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Combinatorics/stirling_number_second_table.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DPL_5_I/main.table.test.cpp
documentation_of: Mylib/Combinatorics/stirling_number_second_table.cpp
layout: document
title: Stirling numbers of the second kind (Table)
---

## Operations

- `stirling_number_table(int n)`
	- $S(0,0)$ ~ $S(n,n)$を列挙する。
	- Time complexity $O(n^2)$

## Requirements

## Notes

## Problems

## References
