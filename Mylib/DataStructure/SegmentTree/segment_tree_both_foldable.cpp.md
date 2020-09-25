---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/vertex_set_path_composite/main.test.cpp
    title: test/yosupo-judge/vertex_set_path_composite/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/segment_tree_both_foldable.cpp\"\
    \n#include <vector>\n\nnamespace haar_lib {\n  template <typename Monoid>\n  class\
    \ segment_tree_both_foldable {\n    using value_type = typename Monoid::value_type;\n\
    \    const static Monoid M;\n\n    const int depth, size, hsize;\n    std::vector<value_type>\
    \ data_left, data_right;\n\n  public:\n    segment_tree_both_foldable(int n):\n\
    \      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 << depth),\n\
    \      hsize(size / 2),\n      data_left(size, M()),\n      data_right(size, M())\n\
    \    {}\n\n    auto operator[](int i) const {return data_left[hsize + i];}\n\n\
    \    auto fold_left(int x, int y) const {\n      value_type ret_left = M();\n\
    \      value_type ret_right = M();\n\n      int l = x + hsize, r = y + hsize;\n\
    \      while(l < r){\n        if(r & 1) ret_right = M(data_left[--r], ret_right);\n\
    \        if(l & 1) ret_left = M(ret_left, data_left[l++]);\n        l >>= 1, r\
    \ >>= 1;\n      }\n\n      return M(ret_left, ret_right);\n    }\n\n    auto fold_right(int\
    \ x, int y) const {\n      value_type ret_left = M();\n      value_type ret_right\
    \ = M();\n\n      int l = x + hsize, r = y + hsize;\n      while(l < r){\n   \
    \     if(r & 1) ret_right = M(ret_right, data_right[--r]);\n        if(l & 1)\
    \ ret_left = M(data_right[l++], ret_left);\n        l >>= 1, r >>= 1;\n      }\n\
    \n      return M(ret_right, ret_left);\n    }\n\n    void set(int i, const value_type\
    \ &x){\n      i += hsize;\n      data_left[i] = data_right[i] = x;\n      while(i\
    \ > 1){\n        i >>= 1;\n        data_left[i] = M(data_left[i << 1 | 0], data_left[i\
    \ << 1 | 1]);\n        data_right[i] = M(data_right[i << 1 | 1], data_right[i\
    \ << 1 | 0]);\n      }\n    }\n\n    template <typename T>\n    void init_with_vector(const\
    \ std::vector<T> &val){\n      data_left.assign(size, M());\n      data_right.assign(size,\
    \ M());\n\n      for(int i = 0; i < (int)val.size(); ++i){\n        data_left[hsize\
    \ + i] = val[i];\n        data_right[hsize + i] = val[i];\n      }\n      for(int\
    \ i = hsize - 1; i >= 1; --i){\n        data_left[i] = M(data_left[i << 1 | 0],\
    \ data_left[i << 1 | 1]);\n        data_right[i] = M(data_right[i << 1 | 1], data_right[i\
    \ << 1 | 0]);\n      }\n    }\n\n    template <typename T>\n    void init(const\
    \ T &val){\n      init_with_vector(std::vector<value_type>(hsize, val));\n   \
    \ }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ Monoid>\n  class segment_tree_both_foldable {\n    using value_type = typename\
    \ Monoid::value_type;\n    const static Monoid M;\n\n    const int depth, size,\
    \ hsize;\n    std::vector<value_type> data_left, data_right;\n\n  public:\n  \
    \  segment_tree_both_foldable(int n):\n      depth(n > 1 ? 32 - __builtin_clz(n\
    \ - 1) + 1 : 1),\n      size(1 << depth),\n      hsize(size / 2),\n      data_left(size,\
    \ M()),\n      data_right(size, M())\n    {}\n\n    auto operator[](int i) const\
    \ {return data_left[hsize + i];}\n\n    auto fold_left(int x, int y) const {\n\
    \      value_type ret_left = M();\n      value_type ret_right = M();\n\n     \
    \ int l = x + hsize, r = y + hsize;\n      while(l < r){\n        if(r & 1) ret_right\
    \ = M(data_left[--r], ret_right);\n        if(l & 1) ret_left = M(ret_left, data_left[l++]);\n\
    \        l >>= 1, r >>= 1;\n      }\n\n      return M(ret_left, ret_right);\n\
    \    }\n\n    auto fold_right(int x, int y) const {\n      value_type ret_left\
    \ = M();\n      value_type ret_right = M();\n\n      int l = x + hsize, r = y\
    \ + hsize;\n      while(l < r){\n        if(r & 1) ret_right = M(ret_right, data_right[--r]);\n\
    \        if(l & 1) ret_left = M(data_right[l++], ret_left);\n        l >>= 1,\
    \ r >>= 1;\n      }\n\n      return M(ret_right, ret_left);\n    }\n\n    void\
    \ set(int i, const value_type &x){\n      i += hsize;\n      data_left[i] = data_right[i]\
    \ = x;\n      while(i > 1){\n        i >>= 1;\n        data_left[i] = M(data_left[i\
    \ << 1 | 0], data_left[i << 1 | 1]);\n        data_right[i] = M(data_right[i <<\
    \ 1 | 1], data_right[i << 1 | 0]);\n      }\n    }\n\n    template <typename T>\n\
    \    void init_with_vector(const std::vector<T> &val){\n      data_left.assign(size,\
    \ M());\n      data_right.assign(size, M());\n\n      for(int i = 0; i < (int)val.size();\
    \ ++i){\n        data_left[hsize + i] = val[i];\n        data_right[hsize + i]\
    \ = val[i];\n      }\n      for(int i = hsize - 1; i >= 1; --i){\n        data_left[i]\
    \ = M(data_left[i << 1 | 0], data_left[i << 1 | 1]);\n        data_right[i] =\
    \ M(data_right[i << 1 | 1], data_right[i << 1 | 0]);\n      }\n    }\n\n    template\
    \ <typename T>\n    void init(const T &val){\n      init_with_vector(std::vector<value_type>(hsize,\
    \ val));\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/segment_tree_both_foldable.cpp
  requiredBy: []
  timestamp: '2020-09-25 01:38:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
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

