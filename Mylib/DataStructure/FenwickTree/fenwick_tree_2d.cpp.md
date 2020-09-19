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
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp\"\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename AbelianGroup>\n\
    \  class fenwick_tree_2d {\n    using value_type = typename AbelianGroup::value_type;\n\
    \    const static AbelianGroup G;\n\n    int w, h;\n    std::vector<std::vector<value_type>>\
    \ data;\n\n  private:\n    value_type get_w(int i, int y) const {\n      value_type\
    \ ret = G();\n      i += 1;\n      while(i > 0){\n        ret = G(ret, data[i][y]);\n\
    \        i -= i & (-i);\n      }\n      return ret;\n    }\n\n    value_type get_w(int\
    \ l, int r, int y) const {\n      return G(get_w(r - 1, y), G.inv(get_w(l - 1,\
    \ y)));\n    }\n\n    value_type get(int x1, int x2, int y) const {\n      value_type\
    \ ret = G();\n      y += 1;\n      while(y > 0){\n        ret = G(ret, get_w(x1,\
    \ x2, y));\n        y -= y & (-y);\n      }\n      return ret;\n    }\n\n  public:\n\
    \    fenwick_tree_2d(int width, int height){\n      w = width;\n      h = height;\n\
    \      data = std::vector<std::vector<value_type>>(w + 1, std::vector<value_type>(h\
    \ + 1));\n    }\n\n    value_type get(std::pair<int, int> p1, std::pair<int, int>\
    \ p2) const { // [(x1, y1), (x2, y2))\n      const auto [x1, y1] = p1;\n     \
    \ const auto [x2, y2] = p2;\n      return G(get(x1, x2, y2 - 1), G.inv(get(x1,\
    \ x2, y1 - 1)));\n    }\n\n    value_type operator[](std::pair<int, int> p) const\
    \ {\n      const auto [x, y] = p;\n      return get({x, y}, {x + 1, y + 1});\n\
    \    }\n\n    void update(std::pair<int, int> p, const value_type &val){\n   \
    \   auto [x, y] = p;\n      x += 1;\n      y += 1;\n\n      for(int i = x; i <=\
    \ w; i += i & (-i)){\n        for(int j = y; j <= h; j += j & (-j)){\n       \
    \   data[i][j] = G(data[i][j], val);\n        }\n      }\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ AbelianGroup>\n  class fenwick_tree_2d {\n    using value_type = typename AbelianGroup::value_type;\n\
    \    const static AbelianGroup G;\n\n    int w, h;\n    std::vector<std::vector<value_type>>\
    \ data;\n\n  private:\n    value_type get_w(int i, int y) const {\n      value_type\
    \ ret = G();\n      i += 1;\n      while(i > 0){\n        ret = G(ret, data[i][y]);\n\
    \        i -= i & (-i);\n      }\n      return ret;\n    }\n\n    value_type get_w(int\
    \ l, int r, int y) const {\n      return G(get_w(r - 1, y), G.inv(get_w(l - 1,\
    \ y)));\n    }\n\n    value_type get(int x1, int x2, int y) const {\n      value_type\
    \ ret = G();\n      y += 1;\n      while(y > 0){\n        ret = G(ret, get_w(x1,\
    \ x2, y));\n        y -= y & (-y);\n      }\n      return ret;\n    }\n\n  public:\n\
    \    fenwick_tree_2d(int width, int height){\n      w = width;\n      h = height;\n\
    \      data = std::vector<std::vector<value_type>>(w + 1, std::vector<value_type>(h\
    \ + 1));\n    }\n\n    value_type get(std::pair<int, int> p1, std::pair<int, int>\
    \ p2) const { // [(x1, y1), (x2, y2))\n      const auto [x1, y1] = p1;\n     \
    \ const auto [x2, y2] = p2;\n      return G(get(x1, x2, y2 - 1), G.inv(get(x1,\
    \ x2, y1 - 1)));\n    }\n\n    value_type operator[](std::pair<int, int> p) const\
    \ {\n      const auto [x, y] = p;\n      return get({x, y}, {x + 1, y + 1});\n\
    \    }\n\n    void update(std::pair<int, int> p, const value_type &val){\n   \
    \   auto [x, y] = p;\n      x += 1;\n      y += 1;\n\n      for(int i = x; i <=\
    \ w; i += i & (-i)){\n        for(int j = y; j <= h; j += j & (-j)){\n       \
    \   data[i][j] = G(data[i][j], val);\n        }\n      }\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
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

