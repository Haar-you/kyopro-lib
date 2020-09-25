---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Number/euler_totient_function_table.cpp\"\n#include\
    \ <vector>\n#include <numeric>\n\nnamespace haar_lib {\n  auto totient_table(int\
    \ n){\n    std::vector<int> ret(n + 1);\n    std::iota(ret.begin(), ret.end(),\
    \ 0);\n\n    for(int i = 2; i <= n; ++i){\n      if(ret[i] == i){\n        for(int\
    \ j = i; j <= n; j += i){\n          ret[j] = ret[j] / i * (i - 1);\n        }\n\
    \      }\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <numeric>\n\nnamespace haar_lib\
    \ {\n  auto totient_table(int n){\n    std::vector<int> ret(n + 1);\n    std::iota(ret.begin(),\
    \ ret.end(), 0);\n\n    for(int i = 2; i <= n; ++i){\n      if(ret[i] == i){\n\
    \        for(int j = i; j <= n; j += i){\n          ret[j] = ret[j] / i * (i -\
    \ 1);\n        }\n      }\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/euler_totient_function_table.cpp
  requiredBy: []
  timestamp: '2020-09-25 03:54:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Number/euler_totient_function_table.cpp
layout: document
title: Euler's totient function (Enumerate)
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
