---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1308/main.test.cpp
    title: test/aoj/1308/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2530/main.test.cpp
    title: test/aoj/2530/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/LinearAlgebra/simultaneous_linear_equations_binary.cpp\"\
    \n#include <bitset>\n#include <optional>\n#include <utility>\n#include <vector>\n\
    \nnamespace haar_lib {\n  namespace binary_simultaneous_linear_equations_impl\
    \ {\n    template <size_t N>\n    struct result {\n      int rank, dim;\n    \
    \  std::vector<bool> solution;\n    };\n  }  // namespace binary_simultaneous_linear_equations_impl\n\
    \n  template <size_t N>\n  auto binary_simultaneous_linear_equations(std::vector<std::bitset<N>>\
    \ a, std::vector<bool> b) {\n    using result = binary_simultaneous_linear_equations_impl::result<N>;\n\
    \    std::optional<result> ret;\n\n    const int n = a.size(), m = N;\n    int\
    \ rank = 0;\n\n    for (int j = 0; j < m; ++j) {\n      int pivot = -1;\n    \
    \  for (int i = rank; i < n; ++i) {\n        if (a[i][j]) {\n          pivot =\
    \ i;\n          break;\n        }\n      }\n\n      if (pivot == -1) continue;\n\
    \      std::swap(a[pivot], a[rank]);\n      swap(b[pivot], b[rank]);\n\n     \
    \ for (int i = 0; i < n; ++i) {\n        if (i != rank and a[i][j]) {\n      \
    \    a[i] ^= a[rank];\n          b[i] = b[i] ^ b[rank];\n        }\n      }\n\n\
    \      ++rank;\n    }\n\n    for (int i = rank; i < n; ++i) {\n      if (b[i])\
    \ {\n        return ret;\n      }\n    }\n\n    const int dim = m - rank;\n\n\
    \    std::vector<bool> solution(m);\n    for (int i = 0; i < rank; ++i) solution[i]\
    \ = b[i];\n\n    ret = result({rank, dim, solution});\n    return ret;\n  }\n\
    }  // namespace haar_lib\n"
  code: "#pragma once\n#include <bitset>\n#include <optional>\n#include <utility>\n\
    #include <vector>\n\nnamespace haar_lib {\n  namespace binary_simultaneous_linear_equations_impl\
    \ {\n    template <size_t N>\n    struct result {\n      int rank, dim;\n    \
    \  std::vector<bool> solution;\n    };\n  }  // namespace binary_simultaneous_linear_equations_impl\n\
    \n  template <size_t N>\n  auto binary_simultaneous_linear_equations(std::vector<std::bitset<N>>\
    \ a, std::vector<bool> b) {\n    using result = binary_simultaneous_linear_equations_impl::result<N>;\n\
    \    std::optional<result> ret;\n\n    const int n = a.size(), m = N;\n    int\
    \ rank = 0;\n\n    for (int j = 0; j < m; ++j) {\n      int pivot = -1;\n    \
    \  for (int i = rank; i < n; ++i) {\n        if (a[i][j]) {\n          pivot =\
    \ i;\n          break;\n        }\n      }\n\n      if (pivot == -1) continue;\n\
    \      std::swap(a[pivot], a[rank]);\n      swap(b[pivot], b[rank]);\n\n     \
    \ for (int i = 0; i < n; ++i) {\n        if (i != rank and a[i][j]) {\n      \
    \    a[i] ^= a[rank];\n          b[i] = b[i] ^ b[rank];\n        }\n      }\n\n\
    \      ++rank;\n    }\n\n    for (int i = rank; i < n; ++i) {\n      if (b[i])\
    \ {\n        return ret;\n      }\n    }\n\n    const int dim = m - rank;\n\n\
    \    std::vector<bool> solution(m);\n    for (int i = 0; i < rank; ++i) solution[i]\
    \ = b[i];\n\n    ret = result({rank, dim, solution});\n    return ret;\n  }\n\
    }  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/LinearAlgebra/simultaneous_linear_equations_binary.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1308/main.test.cpp
  - test/aoj/2530/main.test.cpp
documentation_of: Mylib/LinearAlgebra/simultaneous_linear_equations_binary.cpp
layout: document
title: Simultaneous linear equations (Mod2)
---

## Operations

## Requirements

## Notes

## Problems

## References