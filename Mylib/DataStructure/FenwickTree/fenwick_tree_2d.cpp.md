---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2842/main.fenwick_tree.test.cpp
    title: test/aoj/2842/main.fenwick_tree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp\"\n\
    #include <vector>\n#include <cassert>\n\nnamespace haar_lib {\n  template <typename\
    \ AbelianGroup>\n  class fenwick_tree_2d {\n  public:\n    using value_type =\
    \ typename AbelianGroup::value_type;\n\n  private:\n    AbelianGroup G_;\n\n \
    \   int w_, h_;\n    std::vector<std::vector<value_type>> data_;\n\n  private:\n\
    \    value_type get_w(int i, int y) const {\n      value_type ret = G_();\n  \
    \    while(i > 0){\n        ret = G_(ret, data_[i][y]);\n        i -= i & (-i);\n\
    \      }\n      return ret;\n    }\n\n    value_type get_w(int l, int r, int y)\
    \ const {\n      return G_(get_w(r, y), G_.inv(get_w(l, y)));\n    }\n\n    value_type\
    \ get(int x1, int x2, int y) const {\n      value_type ret = G_();\n      while(y\
    \ > 0){\n        ret = G_(ret, get_w(x1, x2, y));\n        y -= y & (-y);\n  \
    \    }\n      return ret;\n    }\n\n  public:\n    fenwick_tree_2d(){}\n    fenwick_tree_2d(int\
    \ width, int height):\n      w_(width), h_(height), data_(w_ + 1, std::vector<value_type>(h_\
    \ + 1, G_())){}\n\n    value_type fold(std::pair<int, int> p1, std::pair<int,\
    \ int> p2) const {\n      const auto [x1, y1] = p1;\n      const auto [x2, y2]\
    \ = p2;\n      assert(0 <= x1 and x1 <= x2 and x2 <= w_);\n      assert(0 <= y1\
    \ and y1 <= y2 and y2 <= h_);\n      return G_(get(x1, x2, y2), G_.inv(get(x1,\
    \ x2, y1)));\n    }\n\n    value_type operator[](std::pair<int, int> p) const\
    \ {\n      const auto [x, y] = p;\n      return fold({x, y}, {x + 1, y + 1});\n\
    \    }\n\n    void update(std::pair<int, int> p, const value_type &val){\n   \
    \   auto [x, y] = p;\n      assert(0 <= x and x < w_);\n      assert(0 <= y and\
    \ y < h_);\n      x += 1;\n      y += 1;\n\n      for(int i = x; i <= w_; i +=\
    \ i & (-i)){\n        for(int j = y; j <= h_; j += j & (-j)){\n          data_[i][j]\
    \ = G_(data_[i][j], val);\n        }\n      }\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  template <typename AbelianGroup>\n  class fenwick_tree_2d {\n  public:\n\
    \    using value_type = typename AbelianGroup::value_type;\n\n  private:\n   \
    \ AbelianGroup G_;\n\n    int w_, h_;\n    std::vector<std::vector<value_type>>\
    \ data_;\n\n  private:\n    value_type get_w(int i, int y) const {\n      value_type\
    \ ret = G_();\n      while(i > 0){\n        ret = G_(ret, data_[i][y]);\n    \
    \    i -= i & (-i);\n      }\n      return ret;\n    }\n\n    value_type get_w(int\
    \ l, int r, int y) const {\n      return G_(get_w(r, y), G_.inv(get_w(l, y)));\n\
    \    }\n\n    value_type get(int x1, int x2, int y) const {\n      value_type\
    \ ret = G_();\n      while(y > 0){\n        ret = G_(ret, get_w(x1, x2, y));\n\
    \        y -= y & (-y);\n      }\n      return ret;\n    }\n\n  public:\n    fenwick_tree_2d(){}\n\
    \    fenwick_tree_2d(int width, int height):\n      w_(width), h_(height), data_(w_\
    \ + 1, std::vector<value_type>(h_ + 1, G_())){}\n\n    value_type fold(std::pair<int,\
    \ int> p1, std::pair<int, int> p2) const {\n      const auto [x1, y1] = p1;\n\
    \      const auto [x2, y2] = p2;\n      assert(0 <= x1 and x1 <= x2 and x2 <=\
    \ w_);\n      assert(0 <= y1 and y1 <= y2 and y2 <= h_);\n      return G_(get(x1,\
    \ x2, y2), G_.inv(get(x1, x2, y1)));\n    }\n\n    value_type operator[](std::pair<int,\
    \ int> p) const {\n      const auto [x, y] = p;\n      return fold({x, y}, {x\
    \ + 1, y + 1});\n    }\n\n    void update(std::pair<int, int> p, const value_type\
    \ &val){\n      auto [x, y] = p;\n      assert(0 <= x and x < w_);\n      assert(0\
    \ <= y and y < h_);\n      x += 1;\n      y += 1;\n\n      for(int i = x; i <=\
    \ w_; i += i & (-i)){\n        for(int j = y; j <= h_; j += j & (-j)){\n     \
    \     data_[i][j] = G_(data_[i][j], val);\n        }\n      }\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp
  requiredBy: []
  timestamp: '2020-10-10 11:12:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2842/main.fenwick_tree.test.cpp
documentation_of: Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp
layout: document
title: Fenwick tree (2D)
---

## Operations
可換群$(G, +, e)$上の二次元配列を扱う。
- `FenwickTree2D(w, h)`
- `get(x1, y1, x2, y2)`
	- $\sum_{x_1 \le i \lt x_2} \sum_{y_1 \le j \lt y_2} a_{i, j}$を返す。
	- Time complexity $O(\log w \log h)$
- `at(x, y)`
	- $a_{x, y}$を返す。
	- Time complexity $O(\log w \log h)$
- `update(x, y, v)`
	- $a_{x, y} \leftarrow a_{x, y} + v$で更新する。
	- Time complexity $O(\log w \log h)$

## Requirements

- `AbelianGroup`は可換性・結合性を満たす演算`op`と単位元`id`と逆元を与える関数`inv`をもつ。

## Notes

## Problems

## References

