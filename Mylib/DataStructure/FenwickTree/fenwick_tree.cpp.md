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
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/FenwickTree/fenwick_tree.cpp\"\n#include\
    \ <vector>\n\nnamespace haar_lib {\n  template <typename AbelianGroup>\n  class\
    \ fenwick_tree {\n    using value_type = typename AbelianGroup::value_type;\n\
    \    const static AbelianGroup G;\n\n    int size;\n    std::vector<value_type>\
    \ data;\n\n  public:\n    fenwick_tree(){}\n    fenwick_tree(int size):\n    \
    \  size(size), data(size + 1, G())\n    {}\n\n    void update(int i, const value_type\
    \ &val){\n      i += 1; // 1-index\n\n      while(i <= size){\n        data[i]\
    \ = G(data[i], val);\n        i += i & (-i);\n      }\n    }\n\n    value_type\
    \ get(int i) const { // [0, i)\n      value_type ret = G();\n      i += 1; //\
    \ 1-index\n\n      while(i > 0){\n        ret = G(ret, data[i]);\n        i -=\
    \ i & (-i);\n      }\n\n      return ret;\n    }\n\n    value_type get(int l,\
    \ int r) const { // [l, r)\n      return G(get(r - 1), G.inv(get(l - 1)));\n \
    \   }\n\n    value_type operator[](int x) const {\n      return get(x, x + 1);\n\
    \    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ AbelianGroup>\n  class fenwick_tree {\n    using value_type = typename AbelianGroup::value_type;\n\
    \    const static AbelianGroup G;\n\n    int size;\n    std::vector<value_type>\
    \ data;\n\n  public:\n    fenwick_tree(){}\n    fenwick_tree(int size):\n    \
    \  size(size), data(size + 1, G())\n    {}\n\n    void update(int i, const value_type\
    \ &val){\n      i += 1; // 1-index\n\n      while(i <= size){\n        data[i]\
    \ = G(data[i], val);\n        i += i & (-i);\n      }\n    }\n\n    value_type\
    \ get(int i) const { // [0, i)\n      value_type ret = G();\n      i += 1; //\
    \ 1-index\n\n      while(i > 0){\n        ret = G(ret, data[i]);\n        i -=\
    \ i & (-i);\n      }\n\n      return ret;\n    }\n\n    value_type get(int l,\
    \ int r) const { // [l, r)\n      return G(get(r - 1), G.inv(get(l - 1)));\n \
    \   }\n\n    value_type operator[](int x) const {\n      return get(x, x + 1);\n\
    \    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/FenwickTree/fenwick_tree.cpp
  requiredBy:
  - Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_2_B/main.fenwick_tree.test.cpp
  - test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp
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

