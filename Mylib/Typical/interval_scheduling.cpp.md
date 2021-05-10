---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_15_C/main.test.cpp
    title: test/aoj/ALDS1_15_C/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/interval_scheduling.cpp\"\n#include <algorithm>\n\
    #include <limits>\n#include <numeric>\n#include <utility>\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  std::vector<std::pair<T, T>>\
    \ interval_scheduling(const std::vector<T> &l, const std::vector<T> &r) {\n  \
    \  const int N = l.size();\n    std::vector<std::pair<T, T>> ret;\n    std::vector<int>\
    \ ord(N);\n    std::iota(ord.begin(), ord.end(), 0);\n    std::sort(ord.begin(),\
    \ ord.end(), [&](int i, int j) { return r[i] < r[j]; });\n\n    auto b = std::numeric_limits<T>::lowest();\n\
    \n    for (int i : ord) {\n      if (l[i] >= b) {\n        ret.emplace_back(l[i],\
    \ r[i]);\n        b = r[i];\n      }\n    }\n\n    return ret;\n  }\n}  // namespace\
    \ haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <numeric>\n\
    #include <utility>\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  std::vector<std::pair<T, T>> interval_scheduling(const std::vector<T>\
    \ &l, const std::vector<T> &r) {\n    const int N = l.size();\n    std::vector<std::pair<T,\
    \ T>> ret;\n    std::vector<int> ord(N);\n    std::iota(ord.begin(), ord.end(),\
    \ 0);\n    std::sort(ord.begin(), ord.end(), [&](int i, int j) { return r[i] <\
    \ r[j]; });\n\n    auto b = std::numeric_limits<T>::lowest();\n\n    for (int\
    \ i : ord) {\n      if (l[i] >= b) {\n        ret.emplace_back(l[i], r[i]);\n\
    \        b = r[i];\n      }\n    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/interval_scheduling.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_15_C/main.test.cpp
documentation_of: Mylib/Typical/interval_scheduling.cpp
layout: document
title: Interval scheduling problem
---

## Operations

- `interval_scheduling(l[N], r[N])`
	- `N`個の半開区間`[l[i], r[i])`を互いに交差しないように選べる個数を最大にする方法。
	- Time complexity $O(N \log N)$

## Requirements

## Notes

## Problems

- [KUPC 2015 A - 東京都](https://atcoder.jp/contests/kupc2015/tasks/kupc2015_a)
- [Codeforces Round #296 (Div. 1) B. Clique Problem](https://codeforces.com/contest/528/problem/B)

## References
