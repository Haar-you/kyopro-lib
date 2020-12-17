---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/184/main.test.cpp
    title: test/yukicoder/184/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/LinearAlgebra/gaussian_elimination_binary.cpp\"\n\
    #include <vector>\n#include <bitset>\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  template <size_t N>\n  int gaussian_elimination(std::vector<std::bitset<N>>\
    \ &m){\n    const int n = m.size();\n    int rank = 0;\n\n    for(size_t j = 0;\
    \ j < N; ++j){\n      int pivot = -1;\n\n      for(int i = rank; i < n; ++i){\n\
    \        if(m[i][j]){\n          pivot = i;\n          break;\n        }\n   \
    \   }\n\n      if(pivot == -1) continue;\n\n      std::swap(m[pivot], m[rank]);\n\
    \n      for(int i = 0; i < n; ++i){\n        if(i != rank and m[i][j]) m[i] ^=\
    \ m[rank];\n      }\n      ++rank;\n    }\n\n    return rank;\n  }\n\n  template\
    \ <size_t N>\n  int gaussian_elimination(std::vector<std::bitset<N>> &&m){\n \
    \   return gaussian_elimination(m);\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <bitset>\n#include <utility>\n\n\
    namespace haar_lib {\n  template <size_t N>\n  int gaussian_elimination(std::vector<std::bitset<N>>\
    \ &m){\n    const int n = m.size();\n    int rank = 0;\n\n    for(size_t j = 0;\
    \ j < N; ++j){\n      int pivot = -1;\n\n      for(int i = rank; i < n; ++i){\n\
    \        if(m[i][j]){\n          pivot = i;\n          break;\n        }\n   \
    \   }\n\n      if(pivot == -1) continue;\n\n      std::swap(m[pivot], m[rank]);\n\
    \n      for(int i = 0; i < n; ++i){\n        if(i != rank and m[i][j]) m[i] ^=\
    \ m[rank];\n      }\n      ++rank;\n    }\n\n    return rank;\n  }\n\n  template\
    \ <size_t N>\n  int gaussian_elimination(std::vector<std::bitset<N>> &&m){\n \
    \   return gaussian_elimination(m);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/LinearAlgebra/gaussian_elimination_binary.cpp
  requiredBy: []
  timestamp: '2020-12-09 11:11:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/184/main.test.cpp
documentation_of: Mylib/LinearAlgebra/gaussian_elimination_binary.cpp
layout: document
title: Gaussian elimination (Mod2)
---

## Operations

## Requirements

## Notes

## Problems

- [codeFlyer D - 数列 XOR](https://atcoder.jp/contests/bitflyer2018-final-open/tasks/bitflyer2018_final_d)
- [CSA Xor Closure](https://csacademy.com/contest/archive/task/xor-closure/)

## References

