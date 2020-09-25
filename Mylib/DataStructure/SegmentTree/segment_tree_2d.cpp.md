---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2842/main.segment_tree.test.cpp
    title: test/aoj/2842/main.segment_tree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/segment_tree_2d.cpp\"\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename Monoid>\n  class\
    \ segment_tree_2d {\n    using value_type = typename Monoid::value_type;\n   \
    \ const static Monoid M;\n\n    int w, h;\n    std::vector<std::vector<value_type>>\
    \ data;\n\n    value_type get_w(int l, int r, int y) const {\n      l += w / 2;\n\
    \      r += w / 2;\n\n      value_type ret = M();\n\n      while(l < r){\n   \
    \     if(r & 1) ret = M(ret, data[--r][y]);\n        if(l & 1) ret = M(ret, data[l++][y]);\n\
    \        l >>= 1, r >>= 1;\n      }\n\n      return ret;\n    }\n\n  public:\n\
    \    segment_tree_2d(int width, int height){\n      w = 1;\n      while(w < width)\
    \ w *= 2;\n      w = w * 2;\n\n      h = 1;\n      while(h < height) h *= 2;\n\
    \      h = h * 2;\n\n      data = std::vector<std::vector<value_type>>(w, std::vector<value_type>(h));\n\
    \    }\n\n    value_type fold(std::pair<int, int> p1, std::pair<int, int> p2)\
    \ const {\n      const auto [x1, y1] = p1;\n      const auto [x2, y2] = p2;\n\
    \      int l = y1 + h / 2;\n      int r = y2 + h / 2;\n\n      value_type ret\
    \ = M();\n\n      while(l < r){\n        if(r & 1) ret = M(ret, get_w(x1, x2,\
    \ --r));\n        if(l & 1) ret = M(ret, get_w(x1, x2, l++));\n        l >>= 1,\
    \ r >>= 1;\n      }\n\n      return ret;\n    }\n\n    value_type operator[](std::pair<int,\
    \ int> p) const {\n      auto [x, y] = p;\n      return data[w / 2 + x][h / 2\
    \ + y];\n    }\n\n    void set(std::pair<int, int> p, const value_type &val){\n\
    \      const auto [x, y] = p;\n      const int i = x + w / 2;\n      const int\
    \ j = y + h / 2;\n\n      data[i][j] = val;\n\n      for(int X = i >> 1, Y = j;\
    \ X > 0; X >>= 1){\n        data[X][Y] = M(data[X << 1 | 0][Y], data[X << 1 |\
    \ 1][Y]);\n      }\n\n      for(int Y = j >> 1; Y > 0; Y >>= 1){\n        for(int\
    \ X = i; X > 0; X >>= 1){\n          data[X][Y] = M(data[X][Y << 1 | 0], data[X][Y\
    \ << 1 | 1]);\n        }\n      }\n    }\n\n    void update(std::pair<int, int>\
    \ p, const value_type &val){\n      set(p, M((*this)[p], val));\n    }\n  };\n\
    }\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ Monoid>\n  class segment_tree_2d {\n    using value_type = typename Monoid::value_type;\n\
    \    const static Monoid M;\n\n    int w, h;\n    std::vector<std::vector<value_type>>\
    \ data;\n\n    value_type get_w(int l, int r, int y) const {\n      l += w / 2;\n\
    \      r += w / 2;\n\n      value_type ret = M();\n\n      while(l < r){\n   \
    \     if(r & 1) ret = M(ret, data[--r][y]);\n        if(l & 1) ret = M(ret, data[l++][y]);\n\
    \        l >>= 1, r >>= 1;\n      }\n\n      return ret;\n    }\n\n  public:\n\
    \    segment_tree_2d(int width, int height){\n      w = 1;\n      while(w < width)\
    \ w *= 2;\n      w = w * 2;\n\n      h = 1;\n      while(h < height) h *= 2;\n\
    \      h = h * 2;\n\n      data = std::vector<std::vector<value_type>>(w, std::vector<value_type>(h));\n\
    \    }\n\n    value_type fold(std::pair<int, int> p1, std::pair<int, int> p2)\
    \ const {\n      const auto [x1, y1] = p1;\n      const auto [x2, y2] = p2;\n\
    \      int l = y1 + h / 2;\n      int r = y2 + h / 2;\n\n      value_type ret\
    \ = M();\n\n      while(l < r){\n        if(r & 1) ret = M(ret, get_w(x1, x2,\
    \ --r));\n        if(l & 1) ret = M(ret, get_w(x1, x2, l++));\n        l >>= 1,\
    \ r >>= 1;\n      }\n\n      return ret;\n    }\n\n    value_type operator[](std::pair<int,\
    \ int> p) const {\n      auto [x, y] = p;\n      return data[w / 2 + x][h / 2\
    \ + y];\n    }\n\n    void set(std::pair<int, int> p, const value_type &val){\n\
    \      const auto [x, y] = p;\n      const int i = x + w / 2;\n      const int\
    \ j = y + h / 2;\n\n      data[i][j] = val;\n\n      for(int X = i >> 1, Y = j;\
    \ X > 0; X >>= 1){\n        data[X][Y] = M(data[X << 1 | 0][Y], data[X << 1 |\
    \ 1][Y]);\n      }\n\n      for(int Y = j >> 1; Y > 0; Y >>= 1){\n        for(int\
    \ X = i; X > 0; X >>= 1){\n          data[X][Y] = M(data[X][Y << 1 | 0], data[X][Y\
    \ << 1 | 1]);\n        }\n      }\n    }\n\n    void update(std::pair<int, int>\
    \ p, const value_type &val){\n      set(p, M((*this)[p], val));\n    }\n  };\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/segment_tree_2d.cpp
  requiredBy: []
  timestamp: '2020-09-25 01:38:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
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

