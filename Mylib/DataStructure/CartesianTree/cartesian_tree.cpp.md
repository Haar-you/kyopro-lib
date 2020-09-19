---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/cartesian_tree/main.test.cpp
    title: test/yosupo-judge/cartesian_tree/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/CartesianTree/cartesian_tree.cpp\"\n\
    #include <vector>\n#include <tuple>\n#include <optional>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Compare>\n  auto cartesian_tree(const std::vector<T>\
    \ &a, Compare compare){\n    const int n = a.size();\n    std::vector<std::optional<int>>\
    \ p(n), l(n), r(n);\n    int root = 0;\n\n    for(int i = 0; i < n; ++i){\n  \
    \    if(i == 0){\n        continue;\n      }\n\n      int j = i - 1;\n\n     \
    \ while(1){\n        if(compare(a[i], a[j])){\n          if(not p[j]){\n     \
    \       p[j] = i;\n            l[i] = j;\n            root = i;\n            break;\n\
    \          }\n\n          j = *p[j];\n          continue;\n        }\n\n     \
    \   auto t = r[j];\n        r[j] = i;\n        p[i] = j;\n\n        l[i] = t;\n\
    \        if(t) p[*t] = i;\n\n        break;\n      }\n    }\n\n    return std::make_tuple(root,\
    \ p, l, r);\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <tuple>\n#include <optional>\n\n\
    namespace haar_lib {\n  template <typename T, typename Compare>\n  auto cartesian_tree(const\
    \ std::vector<T> &a, Compare compare){\n    const int n = a.size();\n    std::vector<std::optional<int>>\
    \ p(n), l(n), r(n);\n    int root = 0;\n\n    for(int i = 0; i < n; ++i){\n  \
    \    if(i == 0){\n        continue;\n      }\n\n      int j = i - 1;\n\n     \
    \ while(1){\n        if(compare(a[i], a[j])){\n          if(not p[j]){\n     \
    \       p[j] = i;\n            l[i] = j;\n            root = i;\n            break;\n\
    \          }\n\n          j = *p[j];\n          continue;\n        }\n\n     \
    \   auto t = r[j];\n        r[j] = i;\n        p[i] = j;\n\n        l[i] = t;\n\
    \        if(t) p[*t] = i;\n\n        break;\n      }\n    }\n\n    return std::make_tuple(root,\
    \ p, l, r);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/CartesianTree/cartesian_tree.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/cartesian_tree/main.test.cpp
documentation_of: Mylib/DataStructure/CartesianTree/cartesian_tree.cpp
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
