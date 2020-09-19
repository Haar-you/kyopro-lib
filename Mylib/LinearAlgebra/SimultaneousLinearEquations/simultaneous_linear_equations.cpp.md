---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/system_of_linear_equations/main.test.cpp
    title: test/yosupo-judge/system_of_linear_equations/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/LinearAlgebra/SimultaneousLinearEquations/simultaneous_linear_equations.cpp\"\
    \n#include <vector>\n#include <optional>\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  namespace simulaneous_linear_equations_impl {\n    template <typename T>\n\
    \    struct result {\n      int rank, dim;\n      std::vector<T> solution;\n \
    \     std::vector<std::vector<T>> basis;\n    };\n  }\n\n  template <typename\
    \ T>\n  auto simulaneous_linear_equations(std::vector<std::vector<T>> a, std::vector<T>\
    \ b){\n    using result = simulaneous_linear_equations_impl::result<T>;\n    std::optional<result>\
    \ ret;\n    const int n = a.size();\n    const int m = a[0].size();\n\n    int\
    \ rank = 0;\n\n    for(int j = 0; j < m; ++j){\n      int pivot = -1;\n\n    \
    \  for(int i = rank; i < n; ++i){\n        if(a[i][j] != 0){\n          pivot\
    \ = i;\n          break;\n        }\n      }\n\n      if(pivot == -1) continue;\n\
    \n      std::swap(a[pivot], a[rank]);\n      std::swap(b[pivot], b[rank]);\n\n\
    \      auto d = a[rank][j];\n      for(int k = 0; k < m; ++k) a[rank][k] /= d;\n\
    \      b[rank] /= d;\n\n      for(int i = 0; i < n; ++i){\n        if(i == rank\
    \ or a[i][j] == 0) continue;\n        auto d = a[i][j];\n        for(int k = 0;\
    \ k < m; ++k) a[i][k] -= a[rank][k] * d;\n        b[i] -= b[rank] * d;\n     \
    \ }\n\n      ++rank;\n    }\n\n    for(int i = rank; i < n; ++i){\n      if(b[i]\
    \ != 0){\n        return ret;\n      }\n    }\n\n    const int dim = m - rank;\n\
    \n    std::vector<std::vector<T>> basis(dim, std::vector<T>(m));\n    std::vector<int>\
    \ index;\n\n    {\n      int k = 0;\n      for(int i = 0; i < rank; ++i){\n  \
    \      for(int j = k; j < m; ++j){\n          if(a[i][j] == 1){\n            k\
    \ = j + 1;\n            break;\n          }\n\n          index.push_back(j);\n\
    \        }\n      }\n\n      for(int j = k; j < m; ++j) index.push_back(j);\n\
    \    }\n\n    for(int i = 0, k = 0; i < rank; ++i){\n      for(int j = k; j <\
    \ m; ++j){\n        if(a[i][j] == 1){\n          for(int l = 0; l < dim; ++l)\
    \ basis[l][j] = -a[i][index[l]];\n          k = j + 1;\n          break;\n   \
    \     }\n      }\n    }\n\n    for(int i = 0; i < dim; ++i) basis[i][index[i]]\
    \ = 1;\n\n    std::vector<T> solution(m);\n    for(int i = 0; i < rank; ++i) solution[i]\
    \ = b[i];\n\n    ret = result({rank, dim, solution, basis});\n\n    return ret;\n\
    \  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <optional>\n#include <utility>\n\
    \nnamespace haar_lib {\n  namespace simulaneous_linear_equations_impl {\n    template\
    \ <typename T>\n    struct result {\n      int rank, dim;\n      std::vector<T>\
    \ solution;\n      std::vector<std::vector<T>> basis;\n    };\n  }\n\n  template\
    \ <typename T>\n  auto simulaneous_linear_equations(std::vector<std::vector<T>>\
    \ a, std::vector<T> b){\n    using result = simulaneous_linear_equations_impl::result<T>;\n\
    \    std::optional<result> ret;\n    const int n = a.size();\n    const int m\
    \ = a[0].size();\n\n    int rank = 0;\n\n    for(int j = 0; j < m; ++j){\n   \
    \   int pivot = -1;\n\n      for(int i = rank; i < n; ++i){\n        if(a[i][j]\
    \ != 0){\n          pivot = i;\n          break;\n        }\n      }\n\n     \
    \ if(pivot == -1) continue;\n\n      std::swap(a[pivot], a[rank]);\n      std::swap(b[pivot],\
    \ b[rank]);\n\n      auto d = a[rank][j];\n      for(int k = 0; k < m; ++k) a[rank][k]\
    \ /= d;\n      b[rank] /= d;\n\n      for(int i = 0; i < n; ++i){\n        if(i\
    \ == rank or a[i][j] == 0) continue;\n        auto d = a[i][j];\n        for(int\
    \ k = 0; k < m; ++k) a[i][k] -= a[rank][k] * d;\n        b[i] -= b[rank] * d;\n\
    \      }\n\n      ++rank;\n    }\n\n    for(int i = rank; i < n; ++i){\n     \
    \ if(b[i] != 0){\n        return ret;\n      }\n    }\n\n    const int dim = m\
    \ - rank;\n\n    std::vector<std::vector<T>> basis(dim, std::vector<T>(m));\n\
    \    std::vector<int> index;\n\n    {\n      int k = 0;\n      for(int i = 0;\
    \ i < rank; ++i){\n        for(int j = k; j < m; ++j){\n          if(a[i][j] ==\
    \ 1){\n            k = j + 1;\n            break;\n          }\n\n          index.push_back(j);\n\
    \        }\n      }\n\n      for(int j = k; j < m; ++j) index.push_back(j);\n\
    \    }\n\n    for(int i = 0, k = 0; i < rank; ++i){\n      for(int j = k; j <\
    \ m; ++j){\n        if(a[i][j] == 1){\n          for(int l = 0; l < dim; ++l)\
    \ basis[l][j] = -a[i][index[l]];\n          k = j + 1;\n          break;\n   \
    \     }\n      }\n    }\n\n    for(int i = 0; i < dim; ++i) basis[i][index[i]]\
    \ = 1;\n\n    std::vector<T> solution(m);\n    for(int i = 0; i < rank; ++i) solution[i]\
    \ = b[i];\n\n    ret = result({rank, dim, solution, basis});\n\n    return ret;\n\
    \  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/LinearAlgebra/SimultaneousLinearEquations/simultaneous_linear_equations.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/system_of_linear_equations/main.test.cpp
documentation_of: Mylib/LinearAlgebra/SimultaneousLinearEquations/simultaneous_linear_equations.cpp
layout: document
title: Simultaneous linear equations
---

## Operations

## Requirements

## Notes

## Problems

## References
