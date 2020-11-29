---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/194/main.test.cpp
    title: test/yukicoder/194/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/LinearAlgebra/Square/inverse_matrix.cpp\"\n#include\
    \ <utility>\n#include <optional>\n\nnamespace haar_lib {\n  template <typename\
    \ M>\n  std::optional<M> inverse_matrix(M m){\n    using T = typename M::value_type;\n\
    \    const int N = m.size();\n    M ret = M::unit();\n\n    for(int i = 0; i <\
    \ N; ++i){\n      int p = i;\n      for(int j = i; j < N; ++j){\n        if(m[i][j]\
    \ != 0){\n          p = j;\n          break;\n        }\n      }\n\n      std::swap(m[i],\
    \ m[p]);\n      std::swap(ret[i], ret[p]);\n\n      {\n        T d = m[i][i];\n\
    \n        if(d == 0) return std::nullopt;\n\n        for(int j = 0; j < N; ++j){\n\
    \          m[i][j] /= d;\n          ret[i][j] /= d;\n        }\n      }\n\n  \
    \    for(int j = 0; j < N; ++j){\n        if(i == j) continue;\n        T d =\
    \ m[j][i] / m[i][i];\n        for(int k = 0; k < N; ++k){\n          m[j][k] -=\
    \ m[i][k] * d;\n          ret[j][k] -= ret[i][k] * d;\n        }\n      }\n  \
    \  }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <utility>\n#include <optional>\n\nnamespace haar_lib\
    \ {\n  template <typename M>\n  std::optional<M> inverse_matrix(M m){\n    using\
    \ T = typename M::value_type;\n    const int N = m.size();\n    M ret = M::unit();\n\
    \n    for(int i = 0; i < N; ++i){\n      int p = i;\n      for(int j = i; j <\
    \ N; ++j){\n        if(m[i][j] != 0){\n          p = j;\n          break;\n  \
    \      }\n      }\n\n      std::swap(m[i], m[p]);\n      std::swap(ret[i], ret[p]);\n\
    \n      {\n        T d = m[i][i];\n\n        if(d == 0) return std::nullopt;\n\
    \n        for(int j = 0; j < N; ++j){\n          m[i][j] /= d;\n          ret[i][j]\
    \ /= d;\n        }\n      }\n\n      for(int j = 0; j < N; ++j){\n        if(i\
    \ == j) continue;\n        T d = m[j][i] / m[i][i];\n        for(int k = 0; k\
    \ < N; ++k){\n          m[j][k] -= m[i][k] * d;\n          ret[j][k] -= ret[i][k]\
    \ * d;\n        }\n      }\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/LinearAlgebra/Square/inverse_matrix.cpp
  requiredBy: []
  timestamp: '2020-09-21 01:58:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/194/main.test.cpp
documentation_of: Mylib/LinearAlgebra/Square/inverse_matrix.cpp
layout: document
title: Inverse matrix
---

## Operations

## Requirements

## Notes

## Problems

## References
