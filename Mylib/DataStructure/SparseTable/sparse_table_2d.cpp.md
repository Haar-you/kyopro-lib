---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SparseTable/sparse_table_2d.cpp\"\n\
    #include <vector>\n#include <utility>\n#include <algorithm>\n#include <optional>\n\
    \nnamespace haar_lib {\n  template <typename Semilattice>\n  class sparse_table_2d\
    \ {\n  public:\n    using value_type = typename Semilattice::value_type;\n\n \
    \ private:\n    Semilattice S_;\n\n    std::vector<std::vector<std::vector<std::vector<value_type>>>>\
    \ data_;\n    std::vector<int> log_table_;\n\n  public:\n    sparse_table_2d(){}\n\
    \    sparse_table_2d(const std::vector<std::vector<value_type>> &v){\n      const\
    \ int n = v.size();\n      const int m = v[0].size();\n      int logn = 0;\n \
    \     int logm = 0;\n      while((1 << logn) <= n) ++logn;\n      while((1 <<\
    \ logm) <= m) ++logm;\n\n      data_ = std::vector(n, std::vector(logn, std::vector(m,\
    \ std::vector<value_type>(logm))));\n\n      for(int i = 0; i < n; ++i){\n   \
    \     for(int j = 0; j < m; ++j) data_[i][0][j][0] = v[i][j];\n\n        for(int\
    \ y = 1; y < logm; ++y){\n          for(int j = 0; j < m; ++j){\n            data_[i][0][j][y]\
    \ =\n              S_(data_[i][0][j][y - 1],\n                 data_[i][0][std::min<int>(m\
    \ - 1, j + (1 << (y - 1)))][y - 1]);\n          }\n        }\n      }\n\n    \
    \  for(int x = 1; x < logn; ++x){\n        for(int i = 0; i < n; ++i){\n     \
    \     for(int y = 0; y < logm; ++y){\n            for(int j = 0; j < m; ++j){\n\
    \              data_[i][x][j][y] =\n                S_(data_[i][x - 1][j][y],\n\
    \                   data_[std::min<int>(n - 1, i + (1 << (x - 1)))][x - 1][j][y]);\n\
    \            }\n          }\n        }\n      }\n\n      log_table_.assign(std::max(n,\
    \ m) + 1, 0);\n      for(int i = 2; i < std::max(n, m) + 1; ++i) log_table_[i]\
    \ = log_table_[i >> 1] + 1;\n    }\n\n    std::optional<value_type> fold(int r1,\
    \ int c1, int r2, int c2) const {\n      if(r1 == r2 or c1 == c2) return std::nullopt;\n\
    \      const int kr = log_table_[r2 - r1];\n      const int kc = log_table_[c2\
    \ - c1];\n\n      const value_type x = S_(data_[r1][kr][c1][kc], data_[r1][kr][c2\
    \ - (1 << kc)][kc]);\n      const value_type y = S_(data_[r2 - (1 << kr)][kr][c1][kc],\
    \ data_[r2 - (1 << kr)][kr][c2 - (1 << kc)][kc]);\n\n      return S_(x, y);\n\
    \    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include <optional>\n\nnamespace haar_lib {\n  template <typename Semilattice>\n\
    \  class sparse_table_2d {\n  public:\n    using value_type = typename Semilattice::value_type;\n\
    \n  private:\n    Semilattice S_;\n\n    std::vector<std::vector<std::vector<std::vector<value_type>>>>\
    \ data_;\n    std::vector<int> log_table_;\n\n  public:\n    sparse_table_2d(){}\n\
    \    sparse_table_2d(const std::vector<std::vector<value_type>> &v){\n      const\
    \ int n = v.size();\n      const int m = v[0].size();\n      int logn = 0;\n \
    \     int logm = 0;\n      while((1 << logn) <= n) ++logn;\n      while((1 <<\
    \ logm) <= m) ++logm;\n\n      data_ = std::vector(n, std::vector(logn, std::vector(m,\
    \ std::vector<value_type>(logm))));\n\n      for(int i = 0; i < n; ++i){\n   \
    \     for(int j = 0; j < m; ++j) data_[i][0][j][0] = v[i][j];\n\n        for(int\
    \ y = 1; y < logm; ++y){\n          for(int j = 0; j < m; ++j){\n            data_[i][0][j][y]\
    \ =\n              S_(data_[i][0][j][y - 1],\n                 data_[i][0][std::min<int>(m\
    \ - 1, j + (1 << (y - 1)))][y - 1]);\n          }\n        }\n      }\n\n    \
    \  for(int x = 1; x < logn; ++x){\n        for(int i = 0; i < n; ++i){\n     \
    \     for(int y = 0; y < logm; ++y){\n            for(int j = 0; j < m; ++j){\n\
    \              data_[i][x][j][y] =\n                S_(data_[i][x - 1][j][y],\n\
    \                   data_[std::min<int>(n - 1, i + (1 << (x - 1)))][x - 1][j][y]);\n\
    \            }\n          }\n        }\n      }\n\n      log_table_.assign(std::max(n,\
    \ m) + 1, 0);\n      for(int i = 2; i < std::max(n, m) + 1; ++i) log_table_[i]\
    \ = log_table_[i >> 1] + 1;\n    }\n\n    std::optional<value_type> fold(int r1,\
    \ int c1, int r2, int c2) const {\n      if(r1 == r2 or c1 == c2) return std::nullopt;\n\
    \      const int kr = log_table_[r2 - r1];\n      const int kc = log_table_[c2\
    \ - c1];\n\n      const value_type x = S_(data_[r1][kr][c1][kc], data_[r1][kr][c2\
    \ - (1 << kc)][kc]);\n      const value_type y = S_(data_[r2 - (1 << kr)][kr][c1][kc],\
    \ data_[r2 - (1 << kr)][kr][c2 - (1 << kc)][kc]);\n\n      return S_(x, y);\n\
    \    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SparseTable/sparse_table_2d.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/DataStructure/SparseTable/sparse_table_2d.cpp
layout: document
title: Sparse table (2D)
---

## Operations

- `SparseTable2D(v[n][m])`
	- Time complexity $O(nm\log n \log m)$
- `get(int r1, int c1, int r2, int c2)`
	- `[r1, r2), [c1, c2)`を`Semilattice::op`でfoldする。
	- Time complexity $O(1)$

## Requirements

- `Semilattice`は冪等性・可換性・結合性を満たす`op`を持つ。
	- `max`, `min`, `gcd`, `lcm`, `and`, `or`など

## Notes

## Problems

- [Codeforces Round #619 (Div. 2) E. Nanosoft](https://codeforces.com/contest/1301/problem/E)

## References

- [https://codeforces.com/blog/entry/45485](https://codeforces.com/blog/entry/45485)
