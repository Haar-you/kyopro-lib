---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/cartesian_tree/main.test.cpp
    title: test/yosupo-judge/cartesian_tree/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/cartesian_tree.cpp\"\n#include <optional>\n\
    #include <tuple>\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T, typename Compare>\n  auto cartesian_tree(const std::vector<T> &a, Compare\
    \ compare) -> std::tuple<\n      int,                              // root\n \
    \     std::vector<std::optional<int>>,  // parent nodes\n      std::vector<std::optional<int>>,\
    \  // left nodes\n      std::vector<std::optional<int>>   // right nodes\n   \
    \   > {\n    const int n = a.size();\n    std::vector<std::optional<int>> p(n),\
    \ l(n), r(n);\n    int root = 0;\n\n    for (int i = 0; i < n; ++i) {\n      if\
    \ (i == 0) {\n        continue;\n      }\n\n      int j = i - 1;\n\n      while\
    \ (1) {\n        if (compare(a[i], a[j])) {\n          if (not p[j]) {\n     \
    \       p[j] = i;\n            l[i] = j;\n            root = i;\n            break;\n\
    \          }\n\n          j = *p[j];\n          continue;\n        }\n\n     \
    \   auto t = r[j];\n        r[j]   = i;\n        p[i]   = j;\n\n        l[i] =\
    \ t;\n        if (t) p[*t] = i;\n\n        break;\n      }\n    }\n\n    return\
    \ std::make_tuple(root, p, l, r);\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <optional>\n#include <tuple>\n#include <vector>\n\n\
    namespace haar_lib {\n  template <typename T, typename Compare>\n  auto cartesian_tree(const\
    \ std::vector<T> &a, Compare compare) -> std::tuple<\n      int,             \
    \                 // root\n      std::vector<std::optional<int>>,  // parent nodes\n\
    \      std::vector<std::optional<int>>,  // left nodes\n      std::vector<std::optional<int>>\
    \   // right nodes\n      > {\n    const int n = a.size();\n    std::vector<std::optional<int>>\
    \ p(n), l(n), r(n);\n    int root = 0;\n\n    for (int i = 0; i < n; ++i) {\n\
    \      if (i == 0) {\n        continue;\n      }\n\n      int j = i - 1;\n\n \
    \     while (1) {\n        if (compare(a[i], a[j])) {\n          if (not p[j])\
    \ {\n            p[j] = i;\n            l[i] = j;\n            root = i;\n   \
    \         break;\n          }\n\n          j = *p[j];\n          continue;\n \
    \       }\n\n        auto t = r[j];\n        r[j]   = i;\n        p[i]   = j;\n\
    \n        l[i] = t;\n        if (t) p[*t] = i;\n\n        break;\n      }\n  \
    \  }\n\n    return std::make_tuple(root, p, l, r);\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/cartesian_tree.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/cartesian_tree/main.test.cpp
documentation_of: Mylib/Algorithm/cartesian_tree.cpp
layout: document
title: Cartesian tree
---

## Operations

## Requirements

- 数列`a`はdistinctでなければならない。

## Notes

## Problems

- [Manthan, Codefest 18 F. Maximum Reduction](https://codeforces.com/contest/1037/problem/F)

## References

- [https://kimiyuki.net/blog/2020/07/27/recursion-on-cartesian-tree/](https://kimiyuki.net/blog/2020/07/27/recursion-on-cartesian-tree/)
- [https://en.wikipedia.org/wiki/Cartesian_tree](https://en.wikipedia.org/wiki/Cartesian_tree)