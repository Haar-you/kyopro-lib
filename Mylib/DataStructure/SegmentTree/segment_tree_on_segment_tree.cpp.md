---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/DataStructure/SegmentTree/segment_tree.cpp
    title: Segment tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/point_add_rectangle_sum/main.test.cpp
    title: test/yosupo-judge/point_add_rectangle_sum/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp
    title: test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp\"\
    \n#include <vector>\n#include <algorithm>\n#line 4 \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\
    \n#include <functional>\n\nnamespace haar_lib {\n  template <typename Monoid>\n\
    \  class segment_tree {\n    using value_type = typename Monoid::value_type;\n\
    \    const static Monoid M;\n\n    int depth, size, hsize;\n    std::vector<value_type>\
    \ data;\n\n  public:\n    segment_tree(){}\n    segment_tree(int n):\n      depth(n\
    \ > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 << depth), hsize(size\
    \ / 2),\n      data(size, M())\n    {}\n\n    auto operator[](int i) const {return\
    \ data[hsize + i];}\n\n    auto fold(int x, int y) const {\n      value_type ret_left\
    \ = M();\n      value_type ret_right = M();\n\n      int l = x + hsize, r = y\
    \ + hsize;\n      while(l < r){\n        if(r & 1) ret_right = M(data[--r], ret_right);\n\
    \        if(l & 1) ret_left = M(ret_left, data[l++]);\n        l >>= 1, r >>=\
    \ 1;\n      }\n\n      return M(ret_left, ret_right);\n    }\n\n    void set(int\
    \ i, const value_type &x){\n      i += hsize;\n      data[i] = x;\n      while(i\
    \ > 1) i >>= 1, data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);\n    }\n\n  \
    \  void update(int i, const value_type &x){\n      i += hsize;\n      data[i]\
    \ = M(data[i], x);\n      while(i > 1) i >>= 1, data[i] = M(data[i << 1 | 0],\
    \ data[i << 1 | 1]);\n    }\n\n    template <typename T>\n    void init_with_vector(const\
    \ std::vector<T> &val){\n      data.assign(size, M());\n      for(int i = 0; i\
    \ < (int)val.size(); ++i) data[hsize + i] = val[i];\n      for(int i = hsize -\
    \ 1; i >= 1; --i) data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);\n    }\n\n\
    \    template <typename T>\n    void init(const T &val){\n      init_with_vector(std::vector<value_type>(hsize,\
    \ val));\n    }\n\n  private:\n    template <bool Lower, typename F>\n    int\
    \ bound(const int l, const int r, value_type x, F f) const {\n      std::vector<int>\
    \ pl, pr;\n      int L = l + hsize;\n      int R = r + hsize;\n      while(L <\
    \ R){\n        if(R & 1) pr.push_back(--R);\n        if(L & 1) pl.push_back(L++);\n\
    \        L >>= 1, R >>= 1;\n      }\n\n      std::reverse(pr.begin(), pr.end());\n\
    \      pl.insert(pl.end(), pr.begin(), pr.end());\n\n      value_type a = M();\n\
    \n      for(int i : pl){\n        auto b = M(a, data[i]);\n\n        if((Lower\
    \ and not f(b, x)) or (not Lower and f(x, b))){\n          while(i < hsize){\n\
    \            if(auto c = M(a, data[i << 1 | 0]); (Lower and not f(c, x)) or (not\
    \ Lower and f(x, c))){\n              i = i << 1 | 0;\n            }else{\n  \
    \            a = c;\n              i = i << 1 | 1;\n            }\n          }\n\
    \n          return i - hsize;\n        }\n\n        a = b;\n      }\n\n      return\
    \ r;\n    }\n\n  public:\n    template <typename F = std::less<value_type>>\n\
    \    int lower_bound(int l, int r, value_type x, F f = F()) const {\n      return\
    \ bound<true>(l, r, x, f);\n    }\n\n    template <typename F = std::less<value_type>>\n\
    \    int upper_bound(int l, int r, value_type x, F f = F()) const {\n      return\
    \ bound<false>(l, r, x, f);\n    }\n  };\n}\n#line 5 \"Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Monoid>\n  class segment_tree_on_segment_tree\
    \ {\n    using value_type = typename Monoid::value_type;\n    const static Monoid\
    \ M;\n\n    int N = 0;\n    std::vector<int64_t> xs, ys;\n    std::vector<int>\
    \ c_xs;\n\n    std::vector<std::vector<int>> c_ys;\n\n    int x_size;\n\n    std::vector<segment_tree<Monoid>>\
    \ segs;\n\n  public:\n    segment_tree_on_segment_tree(){}\n\n    void add(int64_t\
    \ x, int64_t y){\n      xs.push_back(x);\n      ys.push_back(y);\n      ++N;\n\
    \    }\n\n    void build(){\n      c_xs.insert(c_xs.end(), xs.begin(), xs.end());\n\
    \n      std::sort(c_xs.begin(), c_xs.end());\n      c_xs.erase(std::unique(c_xs.begin(),\
    \ c_xs.end()), c_xs.end());\n\n      x_size = 1;\n      while(x_size < (int)c_xs.size())\
    \ x_size *= 2;\n      x_size *= 2;\n\n      c_ys.resize(x_size);\n      segs.resize(x_size);\n\
    \n      for(int i = 0; i < N; ++i){\n        int j = std::lower_bound(c_xs.begin(),\
    \ c_xs.end(), xs[i]) - c_xs.begin();\n        c_ys[j + x_size / 2].push_back(ys[i]);\n\
    \      }\n\n      for(int i = 0; i < x_size / 2; ++i){\n        auto &v = c_ys[i\
    \ + x_size / 2];\n        std::sort(v.begin(), v.end());\n        v.erase(std::unique(v.begin(),\
    \ v.end()), v.end());\n      }\n\n      for(int i = x_size / 2 - 1; i >= 1; --i){\n\
    \        const auto &a = c_ys[i << 1 | 0];\n        const auto &b = c_ys[i <<\
    \ 1 | 1];\n        auto &c = c_ys[i];\n        c.resize(a.size() + b.size());\n\
    \n        std::merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());\n   \
    \     c.erase(std::unique(c.begin(), c.end()), c.end());\n      }\n\n      for(int\
    \ i = 1; i < x_size; ++i){\n        segs[i] = segment_tree<Monoid>(c_ys[i].size());\n\
    \      }\n    }\n\n    void update(std::pair<int64_t, int64_t> p, const value_type\
    \ &val){\n      const auto [x, y] = p;\n      int i = std::lower_bound(c_xs.begin(),\
    \ c_xs.end(), x) - c_xs.begin() + x_size / 2;\n\n      while(i >= 1){\n      \
    \  int j = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y) - c_ys[i].begin();\n\
    \        segs[i].update(j, val);\n\n        i >>= 1;\n      }\n    }\n\n  private:\n\
    \    value_type get_sub(int i, int64_t y1, int64_t y2) const {\n      int l =\
    \ std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y1) - c_ys[i].begin();\n  \
    \    int r = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y2) - c_ys[i].begin();\n\
    \n      return segs[i].fold(l, r);\n    }\n\n  public:\n    value_type fold(std::pair<int64_t,\
    \ int64_t> p1, std::pair<int64_t, int64_t> p2) const {\n      const auto [x1,\
    \ y1] = p1;\n      const auto [x2, y2] = p2;\n      int l = std::lower_bound(c_xs.begin(),\
    \ c_xs.end(), x1) - c_xs.begin() + x_size / 2;\n      int r = std::lower_bound(c_xs.begin(),\
    \ c_xs.end(), x2) - c_xs.begin() + x_size / 2;\n\n      value_type ret = M();\n\
    \n      while(l < r){\n        if(r & 1) ret = M(ret, get_sub(--r, y1, y2));\n\
    \        if(l & 1) ret = M(ret, get_sub(l++, y1, y2));\n        l >>= 1;\n   \
    \     r >>= 1;\n      }\n\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Monoid>\n  class segment_tree_on_segment_tree\
    \ {\n    using value_type = typename Monoid::value_type;\n    const static Monoid\
    \ M;\n\n    int N = 0;\n    std::vector<int64_t> xs, ys;\n    std::vector<int>\
    \ c_xs;\n\n    std::vector<std::vector<int>> c_ys;\n\n    int x_size;\n\n    std::vector<segment_tree<Monoid>>\
    \ segs;\n\n  public:\n    segment_tree_on_segment_tree(){}\n\n    void add(int64_t\
    \ x, int64_t y){\n      xs.push_back(x);\n      ys.push_back(y);\n      ++N;\n\
    \    }\n\n    void build(){\n      c_xs.insert(c_xs.end(), xs.begin(), xs.end());\n\
    \n      std::sort(c_xs.begin(), c_xs.end());\n      c_xs.erase(std::unique(c_xs.begin(),\
    \ c_xs.end()), c_xs.end());\n\n      x_size = 1;\n      while(x_size < (int)c_xs.size())\
    \ x_size *= 2;\n      x_size *= 2;\n\n      c_ys.resize(x_size);\n      segs.resize(x_size);\n\
    \n      for(int i = 0; i < N; ++i){\n        int j = std::lower_bound(c_xs.begin(),\
    \ c_xs.end(), xs[i]) - c_xs.begin();\n        c_ys[j + x_size / 2].push_back(ys[i]);\n\
    \      }\n\n      for(int i = 0; i < x_size / 2; ++i){\n        auto &v = c_ys[i\
    \ + x_size / 2];\n        std::sort(v.begin(), v.end());\n        v.erase(std::unique(v.begin(),\
    \ v.end()), v.end());\n      }\n\n      for(int i = x_size / 2 - 1; i >= 1; --i){\n\
    \        const auto &a = c_ys[i << 1 | 0];\n        const auto &b = c_ys[i <<\
    \ 1 | 1];\n        auto &c = c_ys[i];\n        c.resize(a.size() + b.size());\n\
    \n        std::merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());\n   \
    \     c.erase(std::unique(c.begin(), c.end()), c.end());\n      }\n\n      for(int\
    \ i = 1; i < x_size; ++i){\n        segs[i] = segment_tree<Monoid>(c_ys[i].size());\n\
    \      }\n    }\n\n    void update(std::pair<int64_t, int64_t> p, const value_type\
    \ &val){\n      const auto [x, y] = p;\n      int i = std::lower_bound(c_xs.begin(),\
    \ c_xs.end(), x) - c_xs.begin() + x_size / 2;\n\n      while(i >= 1){\n      \
    \  int j = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y) - c_ys[i].begin();\n\
    \        segs[i].update(j, val);\n\n        i >>= 1;\n      }\n    }\n\n  private:\n\
    \    value_type get_sub(int i, int64_t y1, int64_t y2) const {\n      int l =\
    \ std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y1) - c_ys[i].begin();\n  \
    \    int r = std::lower_bound(c_ys[i].begin(), c_ys[i].end(), y2) - c_ys[i].begin();\n\
    \n      return segs[i].fold(l, r);\n    }\n\n  public:\n    value_type fold(std::pair<int64_t,\
    \ int64_t> p1, std::pair<int64_t, int64_t> p2) const {\n      const auto [x1,\
    \ y1] = p1;\n      const auto [x2, y2] = p2;\n      int l = std::lower_bound(c_xs.begin(),\
    \ c_xs.end(), x1) - c_xs.begin() + x_size / 2;\n      int r = std::lower_bound(c_xs.begin(),\
    \ c_xs.end(), x2) - c_xs.begin() + x_size / 2;\n\n      value_type ret = M();\n\
    \n      while(l < r){\n        if(r & 1) ret = M(ret, get_sub(--r, y1, y2));\n\
    \        if(l & 1) ret = M(ret, get_sub(l++, y1, y2));\n        l >>= 1;\n   \
    \     r >>= 1;\n      }\n\n      return ret;\n    }\n  };\n}\n"
  dependsOn:
  - Mylib/DataStructure/SegmentTree/segment_tree.cpp
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-09-25 01:38:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/point_add_rectangle_sum/main.test.cpp
  - test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp
documentation_of: Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp
layout: document
title: Segment tree (On segment tree)
---

## Operations

- `SegmentTree2D()`
- `add(x, y)`
	- 点`(x, y)`を追加する。
- `build()`
- `update(x, y, value)`
- `get(x1, y1, x2, y2)`

## Requirements

- `Monoid`は**可換性**・結合律を満たす演算`op`と単位元`id`をもつ。
- `add`, `build`, `update / get`の順で呼び出す。

## Notes

## Problems

## References

