---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_G/main.table.test.cpp
    title: test/aoj/DPL_5_G/main.table.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/bell_number_table.cpp\"\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  auto bell_number_table(int\
    \ n){\n    std::vector<std::vector<T>> ret(n + 1, std::vector<T>(n + 1));\n\n\
    \    ret[0][0] = 1;\n\n    for(int i = 1; i <= n; ++i) ret[i][1] = ret[i][i] =\
    \ 1;\n\n    for(int i = 3; i <= n; ++i){\n      for(int j = 2; j < i; ++j){\n\
    \        ret[i][j] = ret[i - 1][j - 1] + j * ret[i - 1][j];\n      }\n    }\n\n\
    \    for(int i = 0; i <= n; ++i){\n      for(int j = 1; j <= n; ++j){\n      \
    \  ret[i][j] += ret[i][j - 1];\n      }\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  auto bell_number_table(int n){\n    std::vector<std::vector<T>> ret(n\
    \ + 1, std::vector<T>(n + 1));\n\n    ret[0][0] = 1;\n\n    for(int i = 1; i <=\
    \ n; ++i) ret[i][1] = ret[i][i] = 1;\n\n    for(int i = 3; i <= n; ++i){\n   \
    \   for(int j = 2; j < i; ++j){\n        ret[i][j] = ret[i - 1][j - 1] + j * ret[i\
    \ - 1][j];\n      }\n    }\n\n    for(int i = 0; i <= n; ++i){\n      for(int\
    \ j = 1; j <= n; ++j){\n        ret[i][j] += ret[i][j - 1];\n      }\n    }\n\n\
    \    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Combinatorics/bell_number_table.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_G/main.table.test.cpp
documentation_of: Mylib/Combinatorics/bell_number_table.cpp
layout: document
title: Bell number (Table)
---

## Operations

- `bell_number_table(int n) -> [[T]]`
	- $B(0,0)$ ~ $B(N,N)$を列挙する
	- Time complexity $O(n^2)$

## Requirements

## Notes

## Problems

## References
