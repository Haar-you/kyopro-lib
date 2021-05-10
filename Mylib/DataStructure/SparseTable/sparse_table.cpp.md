---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/staticrmq/main.sparse_table.test.cpp
    title: test/yosupo-judge/staticrmq/main.sparse_table.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SparseTable/sparse_table.cpp\"\n#include\
    \ <algorithm>\n#include <cassert>\n#include <optional>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace haar_lib {\n  template <typename Semilattice>\n  class\
    \ sparse_table {\n  public:\n    using value_type = typename Semilattice::value_type;\n\
    \n  private:\n    Semilattice S_;\n\n    int n_;\n    std::vector<std::vector<value_type>>\
    \ data_;\n    std::vector<int> log_table_;\n\n  public:\n    sparse_table() {}\n\
    \    template <typename T>\n    sparse_table(const std::vector<T> &v) : n_(v.size())\
    \ {\n      int logn = 0;\n      while ((1 << logn) <= n_) ++logn;\n\n      data_.assign(n_,\
    \ std::vector<value_type>(logn));\n      for (int i = 0; i < n_; ++i) data_[i][0]\
    \ = v[i];\n      for (int j = 1; j < logn; ++j) {\n        for (int i = 0; i <\
    \ n_; ++i) {\n          data_[i][j] = S_(data_[i][j - 1], data_[std::min<int>(n_\
    \ - 1, i + (1 << (j - 1)))][j - 1]);\n        }\n      }\n\n      log_table_.assign(n_\
    \ + 1, 0);\n      for (int i = 2; i < n_ + 1; ++i) log_table_[i] = log_table_[i\
    \ >> 1] + 1;\n    }\n\n    std::optional<value_type> fold(int l, int r) const\
    \ {\n      assert(0 <= l and l <= r and r <= n_);\n      if (l == r) return std::nullopt;\n\
    \      int k = log_table_[r - l];\n      return S_(data_[l][k], data_[r - (1 <<\
    \ k)][k]);\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <optional>\n\
    #include <utility>\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ Semilattice>\n  class sparse_table {\n  public:\n    using value_type = typename\
    \ Semilattice::value_type;\n\n  private:\n    Semilattice S_;\n\n    int n_;\n\
    \    std::vector<std::vector<value_type>> data_;\n    std::vector<int> log_table_;\n\
    \n  public:\n    sparse_table() {}\n    template <typename T>\n    sparse_table(const\
    \ std::vector<T> &v) : n_(v.size()) {\n      int logn = 0;\n      while ((1 <<\
    \ logn) <= n_) ++logn;\n\n      data_.assign(n_, std::vector<value_type>(logn));\n\
    \      for (int i = 0; i < n_; ++i) data_[i][0] = v[i];\n      for (int j = 1;\
    \ j < logn; ++j) {\n        for (int i = 0; i < n_; ++i) {\n          data_[i][j]\
    \ = S_(data_[i][j - 1], data_[std::min<int>(n_ - 1, i + (1 << (j - 1)))][j - 1]);\n\
    \        }\n      }\n\n      log_table_.assign(n_ + 1, 0);\n      for (int i =\
    \ 2; i < n_ + 1; ++i) log_table_[i] = log_table_[i >> 1] + 1;\n    }\n\n    std::optional<value_type>\
    \ fold(int l, int r) const {\n      assert(0 <= l and l <= r and r <= n_);\n \
    \     if (l == r) return std::nullopt;\n      int k = log_table_[r - l];\n   \
    \   return S_(data_[l][k], data_[r - (1 << k)][k]);\n    }\n  };\n}  // namespace\
    \ haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SparseTable/sparse_table.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/staticrmq/main.sparse_table.test.cpp
documentation_of: Mylib/DataStructure/SparseTable/sparse_table.cpp
layout: document
title: Sparse table
---

## Operations

- `SparseTable(v[n])`
    - Time complexity $O(n \log n)$
- `get(int s, int t)`
	- `[s, t)`を`Semilattice::op`でfoldする。
	- Time complexity $O(1)$

## Requirements

- `Semilattice`は冪等性・可換性・結合性を満たす`op`を持つ。
	- `max`, `min`, `gcd`, `lcm`, `and`, `or`など

## Notes

## Problems

## References