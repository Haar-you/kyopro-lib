---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/staticrmq/main.sparse_table.test.cpp
    title: test/yosupo-judge/staticrmq/main.sparse_table.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SparseTable/sparse_table.cpp\"\n#include\
    \ <vector>\n#include <utility>\n#include <algorithm>\n#include <optional>\n\n\
    namespace haar_lib {\n  template <typename Semilattice>\n  class sparse_table\
    \ {\n    using value_type = typename Semilattice::value_type;\n    const static\
    \ Semilattice S;\n\n    std::vector<std::vector<value_type>> a;\n    std::vector<int>\
    \ log_table;\n\n  public:\n    template <typename T>\n    sparse_table(const std::vector<T>\
    \ &v){\n      int n = v.size();\n      int logn = 0;\n      while((1 << logn)\
    \ <= n) ++logn;\n\n      a.assign(n, std::vector<value_type>(logn));\n      for(int\
    \ i = 0; i < n; ++i) a[i][0] = v[i];\n      for(int j = 1; j < logn; ++j){\n \
    \       for(int i = 0; i < n; ++i){\n          a[i][j] = S(a[i][j - 1], a[std::min<int>(n\
    \ - 1, i + (1 << (j - 1)))][j - 1]);\n        }\n      }\n\n      log_table.assign(n\
    \ + 1, 0);\n      for(int i = 2; i < n + 1; ++i) log_table[i] = log_table[i >>\
    \ 1] + 1;\n    }\n\n    std::optional<value_type> get(int s, int t) const { //\
    \ [s, t)\n      if(s == t) return std::nullopt;\n      int k = log_table[t - s];\n\
    \      return S(a[s][k], a[t - (1 << k)][k]);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include <optional>\n\nnamespace haar_lib {\n  template <typename Semilattice>\n\
    \  class sparse_table {\n    using value_type = typename Semilattice::value_type;\n\
    \    const static Semilattice S;\n\n    std::vector<std::vector<value_type>> a;\n\
    \    std::vector<int> log_table;\n\n  public:\n    template <typename T>\n   \
    \ sparse_table(const std::vector<T> &v){\n      int n = v.size();\n      int logn\
    \ = 0;\n      while((1 << logn) <= n) ++logn;\n\n      a.assign(n, std::vector<value_type>(logn));\n\
    \      for(int i = 0; i < n; ++i) a[i][0] = v[i];\n      for(int j = 1; j < logn;\
    \ ++j){\n        for(int i = 0; i < n; ++i){\n          a[i][j] = S(a[i][j - 1],\
    \ a[std::min<int>(n - 1, i + (1 << (j - 1)))][j - 1]);\n        }\n      }\n\n\
    \      log_table.assign(n + 1, 0);\n      for(int i = 2; i < n + 1; ++i) log_table[i]\
    \ = log_table[i >> 1] + 1;\n    }\n\n    std::optional<value_type> get(int s,\
    \ int t) const { // [s, t)\n      if(s == t) return std::nullopt;\n      int k\
    \ = log_table[t - s];\n      return S(a[s][k], a[t - (1 << k)][k]);\n    }\n \
    \ };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SparseTable/sparse_table.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
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
