---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/partition_function/main.test.cpp
    title: test/yosupo-judge/partition_function/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/partition_number_n.cpp\"\n#include <cmath>\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  auto partition_number_n(int\
    \ N){\n    std::vector<T> p(N + 1);\n\n    p[0] = 1;\n\n    for(int i = 1; i <=\
    \ N; ++i){\n      int s = std::sqrt(1 + 24 * i);\n\n      for(int j = 1; j <=\
    \ (1 + s) / 6; ++j){\n        p[i] += p[i - j * (3 * j - 1) / 2] * (j % 2 ? 1\
    \ : -1);\n      }\n\n      for(int j = 1; j <= (-1 + s) / 6; ++j){\n        p[i]\
    \ += p[i - j * (3 * j + 1) / 2] * (j % 2 ? 1 : -1);\n      }\n    }\n\n    return\
    \ p;\n  }\n}\n"
  code: "#pragma once\n#include <cmath>\n#include <vector>\n\nnamespace haar_lib {\n\
    \  template <typename T>\n  auto partition_number_n(int N){\n    std::vector<T>\
    \ p(N + 1);\n\n    p[0] = 1;\n\n    for(int i = 1; i <= N; ++i){\n      int s\
    \ = std::sqrt(1 + 24 * i);\n\n      for(int j = 1; j <= (1 + s) / 6; ++j){\n \
    \       p[i] += p[i - j * (3 * j - 1) / 2] * (j % 2 ? 1 : -1);\n      }\n\n  \
    \    for(int j = 1; j <= (-1 + s) / 6; ++j){\n        p[i] += p[i - j * (3 * j\
    \ + 1) / 2] * (j % 2 ? 1 : -1);\n      }\n    }\n\n    return p;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Combinatorics/partition_number_n.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/partition_function/main.test.cpp
documentation_of: Mylib/Combinatorics/partition_number_n.cpp
layout: document
title: Partition number (Enumerate $P(n, n)$)
---

## Operations

- `partition_number(int n)`
	- $P(0)$ ~ $P(n)$を列挙する。
	- Time complexity $O(n\sqrt{n})$

## Requirements

## Notes

## Problems

- [Partition Function](https://judge.yosupo.jp/problem/partition_function)

## References
