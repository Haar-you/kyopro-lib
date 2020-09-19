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
  bundledCode: "#line 2 \"Mylib/DataStructure/SparseTable/disjoint_sparse_table.cpp\"\
    \n#include <vector>\n#include <algorithm>\n#include <cassert>\n#include <optional>\n\
    \nnamespace haar_lib {\n  template <typename Semigroup>\n  class disjoint_sparse_table\
    \ {\n    using value_type = typename Semigroup::value_type;\n    const static\
    \ Semigroup S;\n\n    int N;\n    int logN;\n    std::vector<value_type> A;\n\n\
    \    std::vector<std::vector<value_type>> data;\n\n    void build(int l, int r,\
    \ int d){\n      if(d <= 0) return;\n\n      const int m = (l + r) / 2;\n\n  \
    \    data[d][m] = A[m];\n      for(int i = m + 1; i < r; ++i){\n        data[d][i]\
    \ = S(data[d][i - 1], A[i]);\n      }\n\n      data[d][m - 1] = A[m - 1];\n  \
    \    for(int i = m - 2; i >= l; --i){\n        data[d][i] = S(data[d][i + 1],\
    \ A[i]);\n      }\n\n      build(l, m, d - 1);\n      build(m, r, d - 1);\n  \
    \  }\n\n  public:\n    disjoint_sparse_table(std::vector<value_type> a):\n   \
    \   N(a.size()),\n      logN(N > 1 ? 32 - __builtin_clz(N - 1) : 0),\n      A(a),\n\
    \      data(logN, std::vector<value_type>(1 << logN))\n    {\n      A.resize(1\
    \ << logN);\n      if(logN > 0) std::copy(A.begin(), A.end(), data[0].begin());\n\
    \      build(0, 1 << logN, logN - 1);\n    }\n\n    std::optional<value_type>\
    \ get(int l, int r) const {\n      if(l == r) return std::nullopt;\n      --r;\n\
    \n      if(l == r) return A[l];\n\n      const int k = 31 - __builtin_clz(l ^\
    \ r);\n      return S(data[k][l], data[k][r]);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    #include <optional>\n\nnamespace haar_lib {\n  template <typename Semigroup>\n\
    \  class disjoint_sparse_table {\n    using value_type = typename Semigroup::value_type;\n\
    \    const static Semigroup S;\n\n    int N;\n    int logN;\n    std::vector<value_type>\
    \ A;\n\n    std::vector<std::vector<value_type>> data;\n\n    void build(int l,\
    \ int r, int d){\n      if(d <= 0) return;\n\n      const int m = (l + r) / 2;\n\
    \n      data[d][m] = A[m];\n      for(int i = m + 1; i < r; ++i){\n        data[d][i]\
    \ = S(data[d][i - 1], A[i]);\n      }\n\n      data[d][m - 1] = A[m - 1];\n  \
    \    for(int i = m - 2; i >= l; --i){\n        data[d][i] = S(data[d][i + 1],\
    \ A[i]);\n      }\n\n      build(l, m, d - 1);\n      build(m, r, d - 1);\n  \
    \  }\n\n  public:\n    disjoint_sparse_table(std::vector<value_type> a):\n   \
    \   N(a.size()),\n      logN(N > 1 ? 32 - __builtin_clz(N - 1) : 0),\n      A(a),\n\
    \      data(logN, std::vector<value_type>(1 << logN))\n    {\n      A.resize(1\
    \ << logN);\n      if(logN > 0) std::copy(A.begin(), A.end(), data[0].begin());\n\
    \      build(0, 1 << logN, logN - 1);\n    }\n\n    std::optional<value_type>\
    \ get(int l, int r) const {\n      if(l == r) return std::nullopt;\n      --r;\n\
    \n      if(l == r) return A[l];\n\n      const int k = 31 - __builtin_clz(l ^\
    \ r);\n      return S(data[k][l], data[k][r]);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SparseTable/disjoint_sparse_table.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/DataStructure/SparseTable/disjoint_sparse_table.cpp
layout: document
title: Disjoint sparse table
---

## Operations

## Requirements

## Notes

## Problems

- [CodeChef SEGPROD](https://www.codechef.com/problems/SEGPROD)

## References

- [https://noshi91.hatenablog.com/entry/2018/05/08/183946](https://noshi91.hatenablog.com/entry/2018/05/08/183946)
