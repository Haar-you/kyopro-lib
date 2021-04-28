---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/2842/main.segment_tree.test.cpp
    title: test/aoj/2842/main.segment_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/segment_tree_2d.cpp\"\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename Monoid>\n  class\
    \ segment_tree_2d {\n  public:\n    using value_type = typename Monoid::value_type;\n\
    \n  private:\n    Monoid M_;\n    int w_, h_;\n    std::vector<std::vector<value_type>>\
    \ data_;\n\n    value_type get_w(int l, int r, int y) const {\n      l += w_ /\
    \ 2;\n      r += w_ / 2;\n\n      value_type ret = M_();\n\n      while (l < r)\
    \ {\n        if (r & 1) ret = M_(ret, data_[--r][y]);\n        if (l & 1) ret\
    \ = M_(ret, data_[l++][y]);\n        l >>= 1, r >>= 1;\n      }\n\n      return\
    \ ret;\n    }\n\n  public:\n    segment_tree_2d() {}\n    segment_tree_2d(int\
    \ width, int height) {\n      w_ = 1;\n      while (w_ < width) w_ *= 2;\n   \
    \   w_ = w_ * 2;\n\n      h_ = 1;\n      while (h_ < height) h_ *= 2;\n      h_\
    \ = h_ * 2;\n\n      data_ = std::vector(w_, std::vector<value_type>(h_, M_()));\n\
    \    }\n\n    value_type fold(std::pair<int, int> p1, std::pair<int, int> p2)\
    \ const {\n      const auto [x1, y1] = p1;\n      const auto [x2, y2] = p2;\n\
    \      int l               = y1 + h_ / 2;\n      int r               = y2 + h_\
    \ / 2;\n\n      value_type ret = M_();\n\n      while (l < r) {\n        if (r\
    \ & 1) ret = M_(ret, get_w(x1, x2, --r));\n        if (l & 1) ret = M_(ret, get_w(x1,\
    \ x2, l++));\n        l >>= 1, r >>= 1;\n      }\n\n      return ret;\n    }\n\
    \n    value_type operator[](std::pair<int, int> p) const {\n      auto [x, y]\
    \ = p;\n      return data_[w_ / 2 + x][h_ / 2 + y];\n    }\n\n    void set(std::pair<int,\
    \ int> p, const value_type &val) {\n      const auto [x, y] = p;\n      const\
    \ int i       = x + w_ / 2;\n      const int j       = y + h_ / 2;\n\n      data_[i][j]\
    \ = val;\n\n      for (int X = i >> 1, Y = j; X > 0; X >>= 1) {\n        data_[X][Y]\
    \ = M_(data_[X << 1 | 0][Y], data_[X << 1 | 1][Y]);\n      }\n\n      for (int\
    \ Y = j >> 1; Y > 0; Y >>= 1) {\n        for (int X = i; X > 0; X >>= 1) {\n \
    \         data_[X][Y] = M_(data_[X][Y << 1 | 0], data_[X][Y << 1 | 1]);\n    \
    \    }\n      }\n    }\n\n    void update(std::pair<int, int> p, const value_type\
    \ &val) {\n      set(p, M_((*this)[p], val));\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ Monoid>\n  class segment_tree_2d {\n  public:\n    using value_type = typename\
    \ Monoid::value_type;\n\n  private:\n    Monoid M_;\n    int w_, h_;\n    std::vector<std::vector<value_type>>\
    \ data_;\n\n    value_type get_w(int l, int r, int y) const {\n      l += w_ /\
    \ 2;\n      r += w_ / 2;\n\n      value_type ret = M_();\n\n      while (l < r)\
    \ {\n        if (r & 1) ret = M_(ret, data_[--r][y]);\n        if (l & 1) ret\
    \ = M_(ret, data_[l++][y]);\n        l >>= 1, r >>= 1;\n      }\n\n      return\
    \ ret;\n    }\n\n  public:\n    segment_tree_2d() {}\n    segment_tree_2d(int\
    \ width, int height) {\n      w_ = 1;\n      while (w_ < width) w_ *= 2;\n   \
    \   w_ = w_ * 2;\n\n      h_ = 1;\n      while (h_ < height) h_ *= 2;\n      h_\
    \ = h_ * 2;\n\n      data_ = std::vector(w_, std::vector<value_type>(h_, M_()));\n\
    \    }\n\n    value_type fold(std::pair<int, int> p1, std::pair<int, int> p2)\
    \ const {\n      const auto [x1, y1] = p1;\n      const auto [x2, y2] = p2;\n\
    \      int l               = y1 + h_ / 2;\n      int r               = y2 + h_\
    \ / 2;\n\n      value_type ret = M_();\n\n      while (l < r) {\n        if (r\
    \ & 1) ret = M_(ret, get_w(x1, x2, --r));\n        if (l & 1) ret = M_(ret, get_w(x1,\
    \ x2, l++));\n        l >>= 1, r >>= 1;\n      }\n\n      return ret;\n    }\n\
    \n    value_type operator[](std::pair<int, int> p) const {\n      auto [x, y]\
    \ = p;\n      return data_[w_ / 2 + x][h_ / 2 + y];\n    }\n\n    void set(std::pair<int,\
    \ int> p, const value_type &val) {\n      const auto [x, y] = p;\n      const\
    \ int i       = x + w_ / 2;\n      const int j       = y + h_ / 2;\n\n      data_[i][j]\
    \ = val;\n\n      for (int X = i >> 1, Y = j; X > 0; X >>= 1) {\n        data_[X][Y]\
    \ = M_(data_[X << 1 | 0][Y], data_[X << 1 | 1][Y]);\n      }\n\n      for (int\
    \ Y = j >> 1; Y > 0; Y >>= 1) {\n        for (int X = i; X > 0; X >>= 1) {\n \
    \         data_[X][Y] = M_(data_[X][Y << 1 | 0], data_[X][Y << 1 | 1]);\n    \
    \    }\n      }\n    }\n\n    void update(std::pair<int, int> p, const value_type\
    \ &val) {\n      set(p, M_((*this)[p], val));\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/segment_tree_2d.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/2842/main.segment_tree.test.cpp
documentation_of: Mylib/DataStructure/SegmentTree/segment_tree_2d.cpp
layout: document
title: Segment tree (2D)
---

## Operations
モノイド$(M, \oplus, e)$上の二次元配列を扱う。
- `SegmentTree2D(w, h)`
	- Space complexity $O(wh)$
- `at(x, y)`
	- $a_{x, y}$を返す。
    - Time complexity $O(1)$
- `get(x1, y1, x2, y2)`
	- $\bigoplus_{x1 \le x \lt x2}\bigoplus_{y1 \le y \lt y2} a_{x,y}$を返す。
	- Time complexity $O(\log w \log h)$
- `update(x, y, value)`
	- $a_{x, y}$を`value`に変更する。
	- Time complexity $O(\log w \log h)$

## Requirements

- `Monoid`は**可換性**・結合律を満たす演算`op`と単位元`id`をもつ。

## Notes

## Problems

## References

