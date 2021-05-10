---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Number/Totient/totient_sum.cpp
    title: Sum of totient function
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/sum_of_totient_function/main.test.cpp
    title: test/yosupo-judge/sum_of_totient_function/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Totient/totient_table.cpp\"\n#include <numeric>\n\
    #include <vector>\n\nnamespace haar_lib {\n  std::vector<int> totient_table(int\
    \ n) {\n    std::vector<int> ret(n + 1);\n    std::iota(ret.begin(), ret.end(),\
    \ 0);\n\n    for (int i = 2; i <= n; ++i) {\n      if (ret[i] == i) {\n      \
    \  for (int j = i; j <= n; j += i) {\n          ret[j] = ret[j] / i * (i - 1);\n\
    \        }\n      }\n    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  std::vector<int> totient_table(int n) {\n    std::vector<int> ret(n + 1);\n\
    \    std::iota(ret.begin(), ret.end(), 0);\n\n    for (int i = 2; i <= n; ++i)\
    \ {\n      if (ret[i] == i) {\n        for (int j = i; j <= n; j += i) {\n   \
    \       ret[j] = ret[j] / i * (i - 1);\n        }\n      }\n    }\n\n    return\
    \ ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Totient/totient_table.cpp
  requiredBy:
  - Mylib/Number/Totient/totient_sum.cpp
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/sum_of_totient_function/main.test.cpp
documentation_of: Mylib/Number/Totient/totient_table.cpp
layout: document
title: Euler's totient function (Table)
---

## Operations

- `totient_table(n)`
	- `i in [0, n]`について$\varphi(i)$を求める。
	- $\varphi(nm) = \varphi(n) * \varphi(m)$ if nとmが互いに素

## Requirements

## Notes

## Problems

- [Manthan, Codefest 19 G. Polygons](https://codeforces.com/contest/1208/problem/G)

## References