---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/matrix_det/main.test.cpp
    title: test/yosupo-judge/matrix_det/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/LinearAlgebra/determinant.cpp\"\n#include <utility>\n\
    \nnamespace haar_lib {\n  template <typename M, typename T = typename M::value_type>\n\
    \  T determinant(M m){\n    const int N = m.size();\n\n    int s = 0;\n    for(int\
    \ i = 0; i < N; ++i){\n      if(m[i][i] == 0){\n        for(int j = i + 1; j <\
    \ N; ++j){\n          if(m[j][i] != 0){\n            std::swap(m[i], m[j]);\n\
    \            (s += 1) %= 2;\n            break;\n          }\n          if(j ==\
    \ N - 1) return 0;\n        }\n      }\n\n      for(int j = i + 1; j < N; ++j){\n\
    \        T t = m[j][i] / m[i][i];\n        for(int k = 0; k < N; ++k) m[j][k]\
    \ -= m[i][k] * t;\n      }\n    }\n\n    T ret = s ? -1 : 1;\n    for(int i =\
    \ 0; i < N; ++i) ret *= m[i][i];\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <utility>\n\nnamespace haar_lib {\n  template <typename\
    \ M, typename T = typename M::value_type>\n  T determinant(M m){\n    const int\
    \ N = m.size();\n\n    int s = 0;\n    for(int i = 0; i < N; ++i){\n      if(m[i][i]\
    \ == 0){\n        for(int j = i + 1; j < N; ++j){\n          if(m[j][i] != 0){\n\
    \            std::swap(m[i], m[j]);\n            (s += 1) %= 2;\n            break;\n\
    \          }\n          if(j == N - 1) return 0;\n        }\n      }\n\n     \
    \ for(int j = i + 1; j < N; ++j){\n        T t = m[j][i] / m[i][i];\n        for(int\
    \ k = 0; k < N; ++k) m[j][k] -= m[i][k] * t;\n      }\n    }\n\n    T ret = s\
    \ ? -1 : 1;\n    for(int i = 0; i < N; ++i) ret *= m[i][i];\n    return ret;\n\
    \  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/LinearAlgebra/determinant.cpp
  requiredBy: []
  timestamp: '2020-12-09 11:11:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/matrix_det/main.test.cpp
documentation_of: Mylib/LinearAlgebra/determinant.cpp
layout: document
title: Determinant
---

## Operations

## Requirements

## Notes

## Problems

## References
