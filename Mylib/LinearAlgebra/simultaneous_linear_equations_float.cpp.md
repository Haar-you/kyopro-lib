---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2171/main.test.cpp
    title: test/aoj/2171/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/LinearAlgebra/simultaneous_linear_equations_float.cpp\"\
    \n#include <vector>\n#include <optional>\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  namespace float_simultaneous_linear_equations_impl {\n    template <typename\
    \ T>\n    struct result {\n      int rank, dim;\n      std::vector<T> solution;\n\
    \    };\n  }\n\n  template <typename T>\n  auto float_simultaneous_linear_equations(std::vector<std::vector<T>>\
    \ a, std::vector<T> b, T eps){\n    using result = float_simultaneous_linear_equations_impl::result<T>;\n\
    \    std::optional<result> ret;\n\n    const int n = a.size(), m = a[0].size();\n\
    \    int rank = 0;\n\n    for(int j = 0; j < m; ++j){\n      int pivot = -1;\n\
    \n      double M = eps;\n      for(int i = rank; i < n; ++i){\n        if(std::abs(a[i][j])\
    \ > M){\n          M = std::abs(a[i][j]);\n          pivot = i;\n        }\n \
    \     }\n\n      if(pivot == -1) continue;\n\n      std::swap(a[pivot], a[rank]);\n\
    \      std::swap(b[pivot], b[rank]);\n\n      {\n        double d = a[rank][j];\n\
    \        for(int k = 0; k < m; ++k) a[rank][k] /= d;\n        b[rank] /= d;\n\
    \      }\n\n      for(int i = 0; i < n; ++i){\n        if(i == rank or std::abs(a[i][j])\
    \ <= eps) continue;\n        double d = a[i][j];\n        for(int k = 0; k < m;\
    \ ++k){\n          a[i][k] -= a[rank][k] * d;\n        }\n        b[i] -= b[rank]\
    \ * d;\n      }\n\n      ++rank;\n    }\n\n    for(int i = rank; i < n; ++i){\n\
    \      if(std::abs(b[i]) > eps){\n        return ret;\n      }\n    }\n\n    const\
    \ int dim = m - rank;\n\n    std::vector<T> solution(m);\n    for(int i = 0; i\
    \ < rank; ++i) solution[i] = b[i];\n\n    ret = result({rank, dim, solution});\n\
    \    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <optional>\n#include <utility>\n\
    \nnamespace haar_lib {\n  namespace float_simultaneous_linear_equations_impl {\n\
    \    template <typename T>\n    struct result {\n      int rank, dim;\n      std::vector<T>\
    \ solution;\n    };\n  }\n\n  template <typename T>\n  auto float_simultaneous_linear_equations(std::vector<std::vector<T>>\
    \ a, std::vector<T> b, T eps){\n    using result = float_simultaneous_linear_equations_impl::result<T>;\n\
    \    std::optional<result> ret;\n\n    const int n = a.size(), m = a[0].size();\n\
    \    int rank = 0;\n\n    for(int j = 0; j < m; ++j){\n      int pivot = -1;\n\
    \n      double M = eps;\n      for(int i = rank; i < n; ++i){\n        if(std::abs(a[i][j])\
    \ > M){\n          M = std::abs(a[i][j]);\n          pivot = i;\n        }\n \
    \     }\n\n      if(pivot == -1) continue;\n\n      std::swap(a[pivot], a[rank]);\n\
    \      std::swap(b[pivot], b[rank]);\n\n      {\n        double d = a[rank][j];\n\
    \        for(int k = 0; k < m; ++k) a[rank][k] /= d;\n        b[rank] /= d;\n\
    \      }\n\n      for(int i = 0; i < n; ++i){\n        if(i == rank or std::abs(a[i][j])\
    \ <= eps) continue;\n        double d = a[i][j];\n        for(int k = 0; k < m;\
    \ ++k){\n          a[i][k] -= a[rank][k] * d;\n        }\n        b[i] -= b[rank]\
    \ * d;\n      }\n\n      ++rank;\n    }\n\n    for(int i = rank; i < n; ++i){\n\
    \      if(std::abs(b[i]) > eps){\n        return ret;\n      }\n    }\n\n    const\
    \ int dim = m - rank;\n\n    std::vector<T> solution(m);\n    for(int i = 0; i\
    \ < rank; ++i) solution[i] = b[i];\n\n    ret = result({rank, dim, solution});\n\
    \    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/LinearAlgebra/simultaneous_linear_equations_float.cpp
  requiredBy: []
  timestamp: '2020-12-09 11:11:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2171/main.test.cpp
documentation_of: Mylib/LinearAlgebra/simultaneous_linear_equations_float.cpp
layout: document
title: Simultaneous linear equations (Floating point number)
---

## Operations

## Requirements

## Notes

## Problems

## References
