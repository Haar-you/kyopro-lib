---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp
    title: Segment tree (On segment tree)
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp
    title: Manhattan distance MST
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0390/main.test.cpp
    title: test/aoj/0390/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2444/main.test.cpp
    title: test/aoj/2444/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3132/main.test.cpp
    title: test/aoj/3132/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A/main.test.cpp
    title: test/aoj/DSL_2_A/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B/main.test.cpp
    title: test/aoj/DSL_2_B/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/manhattanmst/main.test.cpp
    title: test/yosupo-judge/manhattanmst/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/point_add_rectangle_sum/main.test.cpp
    title: test/yosupo-judge/point_add_rectangle_sum/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/point_set_range_composite/main.test.cpp
    title: test/yosupo-judge/point_set_range_composite/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp
    title: test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/vertex_add_path_sum/main.test.cpp
    title: test/yosupo-judge/vertex_add_path_sum/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp
    title: test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp
    title: test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1030/main.test.cpp
    title: test/yukicoder/1030/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/510/main.test.cpp
    title: test/yukicoder/510/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/776/main.test.cpp
    title: test/yukicoder/776/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/875/main.test.cpp
    title: test/yukicoder/875/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\n#include\
    \ <vector>\n#include <algorithm>\n#include <functional>\n#include <cassert>\n\n\
    namespace haar_lib {\n  template <typename Monoid>\n  class segment_tree {\n \
    \ public:\n    using value_type = typename Monoid::value_type;\n\n  private:\n\
    \    Monoid M_;\n    int depth_, size_, hsize_;\n    std::vector<value_type> data_;\n\
    \n  public:\n    segment_tree(){}\n    segment_tree(int n):\n      depth_(n >\
    \ 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size_(1 << depth_), hsize_(size_\
    \ / 2),\n      data_(size_, M_())\n    {}\n\n    auto operator[](int i) const\
    \ {\n      assert(0 <= i and i < hsize_);\n      return data_[hsize_ + i];\n \
    \   }\n\n    auto fold(int l, int r) const {\n      assert(0 <= l and l <= r and\
    \ r <= hsize_);\n      value_type ret_left = M_();\n      value_type ret_right\
    \ = M_();\n\n      int L = l + hsize_, R = r + hsize_;\n      while(L < R){\n\
    \        if(R & 1) ret_right = M_(data_[--R], ret_right);\n        if(L & 1) ret_left\
    \ = M_(ret_left, data_[L++]);\n        L >>= 1, R >>= 1;\n      }\n\n      return\
    \ M_(ret_left, ret_right);\n    }\n\n    auto fold_all() const {\n      return\
    \ data_[1];\n    }\n\n    void set(int i, const value_type &x){\n      assert(0\
    \ <= i and i < hsize_);\n      i += hsize_;\n      data_[i] = x;\n      while(i\
    \ > 1) i >>= 1, data_[i] = M_(data_[i << 1 | 0], data_[i << 1 | 1]);\n    }\n\n\
    \    void update(int i, const value_type &x){\n      assert(0 <= i and i < hsize_);\n\
    \      i += hsize_;\n      data_[i] = M_(data_[i], x);\n      while(i > 1) i >>=\
    \ 1, data_[i] = M_(data_[i << 1 | 0], data_[i << 1 | 1]);\n    }\n\n    template\
    \ <typename T>\n    void init_with_vector(const std::vector<T> &val){\n      data_.assign(size_,\
    \ M_());\n      for(int i = 0; i < (int)val.size(); ++i) data_[hsize_ + i] = val[i];\n\
    \      for(int i = hsize_; --i >= 1;) data_[i] = M_(data_[i << 1 | 0], data_[i\
    \ << 1 | 1]);\n    }\n\n    template <typename T>\n    void init(const T &val){\n\
    \      init_with_vector(std::vector<value_type>(hsize_, val));\n    }\n\n  private:\n\
    \    template <bool Lower, typename F>\n    int bound(const int l, const int r,\
    \ value_type x, F f) const {\n      std::vector<int> pl, pr;\n      int L = l\
    \ + hsize_;\n      int R = r + hsize_;\n      while(L < R){\n        if(R & 1)\
    \ pr.push_back(--R);\n        if(L & 1) pl.push_back(L++);\n        L >>= 1, R\
    \ >>= 1;\n      }\n\n      std::reverse(pr.begin(), pr.end());\n      pl.insert(pl.end(),\
    \ pr.begin(), pr.end());\n\n      value_type a = M_();\n\n      for(int i : pl){\n\
    \        auto b = M_(a, data_[i]);\n\n        if((Lower and not f(b, x)) or (not\
    \ Lower and f(x, b))){\n          while(i < hsize_){\n            const auto c\
    \ = M_(a, data_[i << 1 | 0]);\n            if((Lower and not f(c, x)) or (not\
    \ Lower and f(x, c))){\n              i = i << 1 | 0;\n            }else{\n  \
    \            a = c;\n              i = i << 1 | 1;\n            }\n          }\n\
    \n          return i - hsize_;\n        }\n\n        a = b;\n      }\n\n     \
    \ return r;\n    }\n\n  public:\n    template <typename F = std::less<value_type>>\n\
    \    int lower_bound(int l, int r, value_type x, F f = F()) const {\n      return\
    \ bound<true>(l, r, x, f);\n    }\n\n    template <typename F = std::less<value_type>>\n\
    \    int upper_bound(int l, int r, value_type x, F f = F()) const {\n      return\
    \ bound<false>(l, r, x, f);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <functional>\n\
    #include <cassert>\n\nnamespace haar_lib {\n  template <typename Monoid>\n  class\
    \ segment_tree {\n  public:\n    using value_type = typename Monoid::value_type;\n\
    \n  private:\n    Monoid M_;\n    int depth_, size_, hsize_;\n    std::vector<value_type>\
    \ data_;\n\n  public:\n    segment_tree(){}\n    segment_tree(int n):\n      depth_(n\
    \ > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size_(1 << depth_), hsize_(size_\
    \ / 2),\n      data_(size_, M_())\n    {}\n\n    auto operator[](int i) const\
    \ {\n      assert(0 <= i and i < hsize_);\n      return data_[hsize_ + i];\n \
    \   }\n\n    auto fold(int l, int r) const {\n      assert(0 <= l and l <= r and\
    \ r <= hsize_);\n      value_type ret_left = M_();\n      value_type ret_right\
    \ = M_();\n\n      int L = l + hsize_, R = r + hsize_;\n      while(L < R){\n\
    \        if(R & 1) ret_right = M_(data_[--R], ret_right);\n        if(L & 1) ret_left\
    \ = M_(ret_left, data_[L++]);\n        L >>= 1, R >>= 1;\n      }\n\n      return\
    \ M_(ret_left, ret_right);\n    }\n\n    auto fold_all() const {\n      return\
    \ data_[1];\n    }\n\n    void set(int i, const value_type &x){\n      assert(0\
    \ <= i and i < hsize_);\n      i += hsize_;\n      data_[i] = x;\n      while(i\
    \ > 1) i >>= 1, data_[i] = M_(data_[i << 1 | 0], data_[i << 1 | 1]);\n    }\n\n\
    \    void update(int i, const value_type &x){\n      assert(0 <= i and i < hsize_);\n\
    \      i += hsize_;\n      data_[i] = M_(data_[i], x);\n      while(i > 1) i >>=\
    \ 1, data_[i] = M_(data_[i << 1 | 0], data_[i << 1 | 1]);\n    }\n\n    template\
    \ <typename T>\n    void init_with_vector(const std::vector<T> &val){\n      data_.assign(size_,\
    \ M_());\n      for(int i = 0; i < (int)val.size(); ++i) data_[hsize_ + i] = val[i];\n\
    \      for(int i = hsize_; --i >= 1;) data_[i] = M_(data_[i << 1 | 0], data_[i\
    \ << 1 | 1]);\n    }\n\n    template <typename T>\n    void init(const T &val){\n\
    \      init_with_vector(std::vector<value_type>(hsize_, val));\n    }\n\n  private:\n\
    \    template <bool Lower, typename F>\n    int bound(const int l, const int r,\
    \ value_type x, F f) const {\n      std::vector<int> pl, pr;\n      int L = l\
    \ + hsize_;\n      int R = r + hsize_;\n      while(L < R){\n        if(R & 1)\
    \ pr.push_back(--R);\n        if(L & 1) pl.push_back(L++);\n        L >>= 1, R\
    \ >>= 1;\n      }\n\n      std::reverse(pr.begin(), pr.end());\n      pl.insert(pl.end(),\
    \ pr.begin(), pr.end());\n\n      value_type a = M_();\n\n      for(int i : pl){\n\
    \        auto b = M_(a, data_[i]);\n\n        if((Lower and not f(b, x)) or (not\
    \ Lower and f(x, b))){\n          while(i < hsize_){\n            const auto c\
    \ = M_(a, data_[i << 1 | 0]);\n            if((Lower and not f(c, x)) or (not\
    \ Lower and f(x, c))){\n              i = i << 1 | 0;\n            }else{\n  \
    \            a = c;\n              i = i << 1 | 1;\n            }\n          }\n\
    \n          return i - hsize_;\n        }\n\n        a = b;\n      }\n\n     \
    \ return r;\n    }\n\n  public:\n    template <typename F = std::less<value_type>>\n\
    \    int lower_bound(int l, int r, value_type x, F f = F()) const {\n      return\
    \ bound<true>(l, r, x, f);\n    }\n\n    template <typename F = std::less<value_type>>\n\
    \    int upper_bound(int l, int r, value_type x, F f = F()) const {\n      return\
    \ bound<false>(l, r, x, f);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/segment_tree.cpp
  requiredBy:
  - Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp
  - Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp
  timestamp: '2020-10-15 01:51:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo-judge/point_add_rectangle_sum/main.test.cpp
  - test/yosupo-judge/vertex_add_path_sum/main.test.cpp
  - test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp
  - test/yosupo-judge/manhattanmst/main.test.cpp
  - test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp
  - test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp
  - test/yosupo-judge/point_set_range_composite/main.test.cpp
  - test/yukicoder/510/main.test.cpp
  - test/yukicoder/776/main.test.cpp
  - test/yukicoder/1030/main.test.cpp
  - test/yukicoder/875/main.test.cpp
  - test/aoj/3132/main.test.cpp
  - test/aoj/0390/main.test.cpp
  - test/aoj/DSL_2_B/main.test.cpp
  - test/aoj/2444/main.test.cpp
  - test/aoj/DSL_2_A/main.test.cpp
documentation_of: Mylib/DataStructure/SegmentTree/segment_tree.cpp
layout: document
title: Segment tree
---

## Operations
モノイド$(M, \circ, e)$上の列を扱う。
- `SegmentTree(n)`
- `operator[](i)`
- `at(i)`
	- $a_i$を返す。
	- Time complexity $O(1)$
- `get(l, r)`
	- $a_l \circ a_{l+1} \circ \ldots \circ a_{r-1}$を返す。
	- Time complexity $O(\log n)$
- `update(i, value)`
	- $a_i$を`value`に変更する。
	- Time complexity $O(\log n)$
- `init_with_vector(a)`
- `init(value)`

## Requirements

- `Monoid`は結合律を満たす演算`op`と単位元`id`をもつ。

## Notes

## Problems

## References

