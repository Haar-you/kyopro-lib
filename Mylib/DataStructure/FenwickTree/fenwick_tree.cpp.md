---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp
    title: Fenwick tree (On Fenwick tree)
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_B/main.fenwick_tree.test.cpp
    title: test/aoj/DSL_2_B/main.fenwick_tree.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp
    title: test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/FenwickTree/fenwick_tree.cpp\"\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace haar_lib {\n  template <typename AbelianGroup>\n\
    \  class fenwick_tree {\n  public:\n    using value_type = typename AbelianGroup::value_type;\n\
    \n  private:\n    AbelianGroup G_;\n    int size_;\n    std::vector<value_type>\
    \ data_;\n\n  public:\n    fenwick_tree() {}\n    fenwick_tree(int size) : size_(size),\
    \ data_(size + 1, G_()) {}\n\n    void update(int i, const value_type &val) {\n\
    \      assert(0 <= i and i < size_);\n      i += 1;  // 1-index\n\n      while\
    \ (i <= size_) {\n        data_[i] = G_(data_[i], val);\n        i += i & (-i);\n\
    \      }\n    }\n\n    value_type fold(int i) const {  // [0, i)\n      assert(0\
    \ <= i and i <= size_);\n      value_type ret = G_();\n\n      while (i > 0) {\n\
    \        ret = G_(ret, data_[i]);\n        i -= i & (-i);\n      }\n\n      return\
    \ ret;\n    }\n\n    value_type fold(int l, int r) const {  // [l, r)\n      assert(0\
    \ <= l and l <= r and r <= size_);\n      return G_(fold(r), G_.inv(fold(l)));\n\
    \    }\n\n    value_type operator[](int x) const {\n      return fold(x, x + 1);\n\
    \    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename AbelianGroup>\n  class fenwick_tree {\n  public:\n \
    \   using value_type = typename AbelianGroup::value_type;\n\n  private:\n    AbelianGroup\
    \ G_;\n    int size_;\n    std::vector<value_type> data_;\n\n  public:\n    fenwick_tree()\
    \ {}\n    fenwick_tree(int size) : size_(size), data_(size + 1, G_()) {}\n\n \
    \   void update(int i, const value_type &val) {\n      assert(0 <= i and i < size_);\n\
    \      i += 1;  // 1-index\n\n      while (i <= size_) {\n        data_[i] = G_(data_[i],\
    \ val);\n        i += i & (-i);\n      }\n    }\n\n    value_type fold(int i)\
    \ const {  // [0, i)\n      assert(0 <= i and i <= size_);\n      value_type ret\
    \ = G_();\n\n      while (i > 0) {\n        ret = G_(ret, data_[i]);\n       \
    \ i -= i & (-i);\n      }\n\n      return ret;\n    }\n\n    value_type fold(int\
    \ l, int r) const {  // [l, r)\n      assert(0 <= l and l <= r and r <= size_);\n\
    \      return G_(fold(r), G_.inv(fold(l)));\n    }\n\n    value_type operator[](int\
    \ x) const {\n      return fold(x, x + 1);\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/FenwickTree/fenwick_tree.cpp
  requiredBy:
  - Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp
  - test/aoj/DSL_2_B/main.fenwick_tree.test.cpp
documentation_of: Mylib/DataStructure/FenwickTree/fenwick_tree.cpp
layout: document
title: Fenwick tree
---

## Operations
可換群$(G, +, e)$上の列を扱う。
- `FenwickTree(n)`
- `update(i, v)`
	- $a_i \leftarrow a_i + v$に更新する。
	- Time complexity $O(\log n)$
- `get(i)`
	- $a_0 + a_1 + \ldots + a_{i-1}$を返す。
	- Time complexity $O(\log n)$
- `get(l, r)`
	- $a_l + a_{l+1} + \ldots + a_{r-1}$を返す。
	- Time complexity $O(\log n)$
- `at(i)`
	- $a_i$を返す。
	- Time complexity $O(\log n)$

## Requirements

- `AbelianGroup`は可換性・結合性を満たす演算`op`と単位元`id`と逆元を与える関数`inv`をもつ。

## Notes

## Problems

## References
