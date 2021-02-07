---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/mobius_function.cpp\"\n#include <vector>\n\n\
    namespace haar_lib {\n  template <typename Checker>\n  std::vector<int> mobius_function(int\
    \ n, Checker is_prime){\n    std::vector<int> ret(n + 1), ps;\n\n    ret[1] =\
    \ 1;\n\n    for(int i = 2; i <= n; ++i){\n      if(is_prime(i)){\n        ps.push_back(i);\n\
    \        ret[i] = -1;\n      }\n      for(auto &j : ps){\n        if(i * j > n)\
    \ break;\n        if(i % j == 0) ret[i * j] = 0;\n        else ret[i * j] = ret[i]\
    \ * ret[j];\n      }\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ Checker>\n  std::vector<int> mobius_function(int n, Checker is_prime){\n   \
    \ std::vector<int> ret(n + 1), ps;\n\n    ret[1] = 1;\n\n    for(int i = 2; i\
    \ <= n; ++i){\n      if(is_prime(i)){\n        ps.push_back(i);\n        ret[i]\
    \ = -1;\n      }\n      for(auto &j : ps){\n        if(i * j > n) break;\n   \
    \     if(i % j == 0) ret[i * j] = 0;\n        else ret[i * j] = ret[i] * ret[j];\n\
    \      }\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/mobius_function.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Number/mobius_function.cpp
layout: document
title: "M\xF6bius function"
---

## Operations

## Requirements

## Notes

## Problems

- [Codeforces Round #548 (Div. 2) D. Steps to One](https://codeforces.com/contest/1139/problem/D)

## References

- [https://en.wikipedia.org/wiki/M%C3%B6bius_function](https://en.wikipedia.org/wiki/M%C3%B6bius_function)
