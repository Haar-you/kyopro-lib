---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/vertex_set_path_composite/main.test.cpp
    title: test/yosupo-judge/vertex_set_path_composite/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/segment_tree_both_foldable.cpp\"\
    \n#include <vector>\n#include <cassert>\n\nnamespace haar_lib {\n  template <typename\
    \ Monoid>\n  class segment_tree_both_foldable {\n  public:\n    using value_type\
    \ = typename Monoid::value_type;\n\n  private:\n    Monoid M_;\n    int depth_,\
    \ size_, hsize_;\n    std::vector<value_type> data_left_, data_right_;\n\n  public:\n\
    \    segment_tree_both_foldable(){}\n    segment_tree_both_foldable(int n):\n\
    \      depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size_(1 << depth_),\n\
    \      hsize_(size_ / 2),\n      data_left_(size_, M_()),\n      data_right_(size_,\
    \ M_())\n    {}\n\n    auto operator[](int i) const {\n      assert(0 <= i and\
    \ i < hsize_);\n      return data_left_[hsize_ + i];\n    }\n\n    auto fold_left(int\
    \ l, int r) const {\n      assert(0 <= l and l <= r and r <= hsize_);\n      value_type\
    \ ret_left = M_();\n      value_type ret_right = M_();\n\n      l += hsize_, r\
    \ += hsize_;\n      while(l < r){\n        if(r & 1) ret_right = M_(data_left_[--r],\
    \ ret_right);\n        if(l & 1) ret_left = M_(ret_left, data_left_[l++]);\n \
    \       l >>= 1, r >>= 1;\n      }\n\n      return M_(ret_left, ret_right);\n\
    \    }\n\n    auto fold_right(int l, int r) const {\n      assert(0 <= l and l\
    \ <= r and r <= hsize_);\n      value_type ret_left = M_();\n      value_type\
    \ ret_right = M_();\n\n      l += hsize_, r += hsize_;\n      while(l < r){\n\
    \        if(r & 1) ret_right = M_(ret_right, data_right_[--r]);\n        if(l\
    \ & 1) ret_left = M_(data_right_[l++], ret_left);\n        l >>= 1, r >>= 1;\n\
    \      }\n\n      return M_(ret_right, ret_left);\n    }\n\n    void set(int i,\
    \ const value_type &x){\n      assert(0 <= i and i < hsize_);\n      i += hsize_;\n\
    \      data_left_[i] = data_right_[i] = x;\n      while(i > 1){\n        i >>=\
    \ 1;\n        data_left_[i] = M_(data_left_[i << 1 | 0], data_left_[i << 1 | 1]);\n\
    \        data_right_[i] = M_(data_right_[i << 1 | 1], data_right_[i << 1 | 0]);\n\
    \      }\n    }\n\n    template <typename T>\n    void init_with_vector(const\
    \ std::vector<T> &val){\n      data_left_.assign(size_, M_());\n      data_right_.assign(size_,\
    \ M_());\n\n      for(int i = 0; i < (int)val.size(); ++i){\n        data_left_[hsize_\
    \ + i] = val[i];\n        data_right_[hsize_ + i] = val[i];\n      }\n      for(int\
    \ i = hsize_; --i >= 1;){\n        data_left_[i] = M_(data_left_[i << 1 | 0],\
    \ data_left_[i << 1 | 1]);\n        data_right_[i] = M_(data_right_[i << 1 | 1],\
    \ data_right_[i << 1 | 0]);\n      }\n    }\n\n    template <typename T>\n   \
    \ void init(const T &val){\n      init_with_vector(std::vector<value_type>(hsize_,\
    \ val));\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  template <typename Monoid>\n  class segment_tree_both_foldable {\n  public:\n\
    \    using value_type = typename Monoid::value_type;\n\n  private:\n    Monoid\
    \ M_;\n    int depth_, size_, hsize_;\n    std::vector<value_type> data_left_,\
    \ data_right_;\n\n  public:\n    segment_tree_both_foldable(){}\n    segment_tree_both_foldable(int\
    \ n):\n      depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size_(1\
    \ << depth_),\n      hsize_(size_ / 2),\n      data_left_(size_, M_()),\n    \
    \  data_right_(size_, M_())\n    {}\n\n    auto operator[](int i) const {\n  \
    \    assert(0 <= i and i < hsize_);\n      return data_left_[hsize_ + i];\n  \
    \  }\n\n    auto fold_left(int l, int r) const {\n      assert(0 <= l and l <=\
    \ r and r <= hsize_);\n      value_type ret_left = M_();\n      value_type ret_right\
    \ = M_();\n\n      l += hsize_, r += hsize_;\n      while(l < r){\n        if(r\
    \ & 1) ret_right = M_(data_left_[--r], ret_right);\n        if(l & 1) ret_left\
    \ = M_(ret_left, data_left_[l++]);\n        l >>= 1, r >>= 1;\n      }\n\n   \
    \   return M_(ret_left, ret_right);\n    }\n\n    auto fold_right(int l, int r)\
    \ const {\n      assert(0 <= l and l <= r and r <= hsize_);\n      value_type\
    \ ret_left = M_();\n      value_type ret_right = M_();\n\n      l += hsize_, r\
    \ += hsize_;\n      while(l < r){\n        if(r & 1) ret_right = M_(ret_right,\
    \ data_right_[--r]);\n        if(l & 1) ret_left = M_(data_right_[l++], ret_left);\n\
    \        l >>= 1, r >>= 1;\n      }\n\n      return M_(ret_right, ret_left);\n\
    \    }\n\n    void set(int i, const value_type &x){\n      assert(0 <= i and i\
    \ < hsize_);\n      i += hsize_;\n      data_left_[i] = data_right_[i] = x;\n\
    \      while(i > 1){\n        i >>= 1;\n        data_left_[i] = M_(data_left_[i\
    \ << 1 | 0], data_left_[i << 1 | 1]);\n        data_right_[i] = M_(data_right_[i\
    \ << 1 | 1], data_right_[i << 1 | 0]);\n      }\n    }\n\n    template <typename\
    \ T>\n    void init_with_vector(const std::vector<T> &val){\n      data_left_.assign(size_,\
    \ M_());\n      data_right_.assign(size_, M_());\n\n      for(int i = 0; i < (int)val.size();\
    \ ++i){\n        data_left_[hsize_ + i] = val[i];\n        data_right_[hsize_\
    \ + i] = val[i];\n      }\n      for(int i = hsize_; --i >= 1;){\n        data_left_[i]\
    \ = M_(data_left_[i << 1 | 0], data_left_[i << 1 | 1]);\n        data_right_[i]\
    \ = M_(data_right_[i << 1 | 1], data_right_[i << 1 | 0]);\n      }\n    }\n\n\
    \    template <typename T>\n    void init(const T &val){\n      init_with_vector(std::vector<value_type>(hsize_,\
    \ val));\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/segment_tree_both_foldable.cpp
  requiredBy: []
  timestamp: '2020-10-15 01:51:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/vertex_set_path_composite/main.test.cpp
documentation_of: Mylib/DataStructure/SegmentTree/segment_tree_both_foldable.cpp
layout: document
title: Segment tree (Both foldable)
---

## Operations
モノイド$(M, \circ, e)$上の列を扱う。
- `SegmentTreeBothFoldable()`
- `operator[](i)`
- `at(i)`
	- $a_i$を返す。
- `fold_left(x, y)`
	- $a_l \circ a_{l+1} \circ \ldots a_{r-2} \circ a_{r-1}$を返す。
- `fold_right(x, y)`
	- $a_{r-1} \circ a_{r-2} \circ \ldots \circ a_{l+1} \circ a_l$を返す。
- `update(i, value)`
	- $a_i$を`value`に変更する。
- `init_with_vector(a)`
- `init(value)`

## Requirements

- `Monoid`は結合律を満たす演算`op`と単位元`id`をもつ。

## Notes

## Problems

## References

