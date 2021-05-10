---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/partition_function/main.test.cpp
    title: test/yosupo-judge/partition_function/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/partition_number_n.cpp\"\n#include <cmath>\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T>\
    \ partition_number_n(int N) {\n    std::vector<T> p(N + 1);\n\n    p[0] = 1;\n\
    \n    for (int i = 1; i <= N; ++i) {\n      int s = std::sqrt(1 + 24 * i);\n\n\
    \      for (int j = 1; j <= (s + 1) / 6; ++j) {\n        p[i] += p[i - j * (3\
    \ * j - 1) / 2] * (j % 2 ? 1 : -1);\n      }\n\n      for (int j = 1; j <= (s\
    \ - 1) / 6; ++j) {\n        p[i] += p[i - j * (3 * j + 1) / 2] * (j % 2 ? 1 :\
    \ -1);\n      }\n    }\n\n    return p;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cmath>\n#include <vector>\n\nnamespace haar_lib {\n\
    \  template <typename T>\n  std::vector<T> partition_number_n(int N) {\n    std::vector<T>\
    \ p(N + 1);\n\n    p[0] = 1;\n\n    for (int i = 1; i <= N; ++i) {\n      int\
    \ s = std::sqrt(1 + 24 * i);\n\n      for (int j = 1; j <= (s + 1) / 6; ++j) {\n\
    \        p[i] += p[i - j * (3 * j - 1) / 2] * (j % 2 ? 1 : -1);\n      }\n\n \
    \     for (int j = 1; j <= (s - 1) / 6; ++j) {\n        p[i] += p[i - j * (3 *\
    \ j + 1) / 2] * (j % 2 ? 1 : -1);\n      }\n    }\n\n    return p;\n  }\n}  //\
    \ namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Combinatorics/partition_number_n.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
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