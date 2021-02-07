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
  bundledCode: "#line 2 \"Mylib/DataStructure/SparseTable/disjoint_sparse_table.cpp\"\
    \n#include <vector>\n#include <algorithm>\n#include <cassert>\n#include <optional>\n\
    \nnamespace haar_lib {\n  template <typename Semigroup>\n  class disjoint_sparse_table\
    \ {\n  public:\n    using value_type = typename Semigroup::value_type;\n\n  private:\n\
    \    Semigroup S_;\n\n    int N_, logN_;\n    std::vector<value_type> A_;\n  \
    \  std::vector<std::vector<value_type>> data_;\n\n    void build(int l, int r,\
    \ int d){\n      if(d <= 0) return;\n\n      const int m = (l + r) / 2;\n\n  \
    \    data_[d][m] = A_[m];\n      for(int i = m + 1; i < r; ++i){\n        data_[d][i]\
    \ = S_(data_[d][i - 1], A_[i]);\n      }\n\n      data_[d][m - 1] = A_[m - 1];\n\
    \      for(int i = m - 2; i >= l; --i){\n        data_[d][i] = S_(data_[d][i +\
    \ 1], A_[i]);\n      }\n\n      build(l, m, d - 1);\n      build(m, r, d - 1);\n\
    \    }\n\n  public:\n    disjoint_sparse_table(){}\n    disjoint_sparse_table(std::vector<value_type>\
    \ a):\n      N_(a.size()),\n      logN_(N_ > 1 ? 32 - __builtin_clz(N_ - 1) :\
    \ 0),\n      A_(a),\n      data_(logN_, std::vector<value_type>(1 << logN_))\n\
    \    {\n      A_.resize(1 << logN_);\n      if(logN_ > 0) std::copy(A_.begin(),\
    \ A_.end(), data_[0].begin());\n      build(0, 1 << logN_, logN_ - 1);\n    }\n\
    \n    std::optional<value_type> fold(int l, int r) const {\n      assert(0 <=\
    \ l and l <= r and r <= N_);\n      if(l == r) return std::nullopt;\n      --r;\n\
    \n      if(l == r) return A_[l];\n\n      const int k = 31 - __builtin_clz(l ^\
    \ r);\n      return S_(data_[k][l], data_[k][r]);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    #include <optional>\n\nnamespace haar_lib {\n  template <typename Semigroup>\n\
    \  class disjoint_sparse_table {\n  public:\n    using value_type = typename Semigroup::value_type;\n\
    \n  private:\n    Semigroup S_;\n\n    int N_, logN_;\n    std::vector<value_type>\
    \ A_;\n    std::vector<std::vector<value_type>> data_;\n\n    void build(int l,\
    \ int r, int d){\n      if(d <= 0) return;\n\n      const int m = (l + r) / 2;\n\
    \n      data_[d][m] = A_[m];\n      for(int i = m + 1; i < r; ++i){\n        data_[d][i]\
    \ = S_(data_[d][i - 1], A_[i]);\n      }\n\n      data_[d][m - 1] = A_[m - 1];\n\
    \      for(int i = m - 2; i >= l; --i){\n        data_[d][i] = S_(data_[d][i +\
    \ 1], A_[i]);\n      }\n\n      build(l, m, d - 1);\n      build(m, r, d - 1);\n\
    \    }\n\n  public:\n    disjoint_sparse_table(){}\n    disjoint_sparse_table(std::vector<value_type>\
    \ a):\n      N_(a.size()),\n      logN_(N_ > 1 ? 32 - __builtin_clz(N_ - 1) :\
    \ 0),\n      A_(a),\n      data_(logN_, std::vector<value_type>(1 << logN_))\n\
    \    {\n      A_.resize(1 << logN_);\n      if(logN_ > 0) std::copy(A_.begin(),\
    \ A_.end(), data_[0].begin());\n      build(0, 1 << logN_, logN_ - 1);\n    }\n\
    \n    std::optional<value_type> fold(int l, int r) const {\n      assert(0 <=\
    \ l and l <= r and r <= N_);\n      if(l == r) return std::nullopt;\n      --r;\n\
    \n      if(l == r) return A_[l];\n\n      const int k = 31 - __builtin_clz(l ^\
    \ r);\n      return S_(data_[k][l], data_[k][r]);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SparseTable/disjoint_sparse_table.cpp
  requiredBy: []
  timestamp: '2020-10-15 01:51:15+09:00'
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
