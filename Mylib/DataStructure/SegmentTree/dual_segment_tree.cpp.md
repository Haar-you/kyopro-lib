---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_D/main.test.cpp
    title: test/aoj/DSL_2_D/main.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_E/main.test.cpp
    title: test/aoj/DSL_2_E/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/dual_segment_tree.cpp\"\n\
    #include <cassert>\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ Monoid>\n  class dual_segment_tree {\n  public:\n    using value_type = typename\
    \ Monoid::value_type;\n\n  private:\n    Monoid M_;\n    int depth_, size_, hsize_;\n\
    \    std::vector<value_type> data_;\n\n    void propagate(int i) {\n      if (i\
    \ < hsize_) {\n        data_[i << 1 | 0] = M_(data_[i], data_[i << 1 | 0]);\n\
    \        data_[i << 1 | 1] = M_(data_[i], data_[i << 1 | 1]);\n        data_[i]\
    \          = M_();\n      }\n    }\n\n    void propagate_top_down(int i) {\n \
    \     std::vector<int> temp;\n      while (i > 1) {\n        i >>= 1;\n      \
    \  temp.push_back(i);\n      }\n\n      for (auto it = temp.rbegin(); it != temp.rend();\
    \ ++it) propagate(*it);\n    }\n\n  public:\n    dual_segment_tree() {}\n    dual_segment_tree(int\
    \ n) : depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n                  \
    \             size_(1 << depth_),\n                               hsize_(size_\
    \ / 2),\n                               data_(size_, M_()) {}\n\n    void update(int\
    \ l, int r, const value_type &x) {\n      assert(0 <= l and l <= r and r <= hsize_);\n\
    \      propagate_top_down(l + hsize_);\n      propagate_top_down(r + hsize_);\n\
    \n      int L = l + hsize_;\n      int R = r + hsize_;\n\n      while (L < R)\
    \ {\n        if (R & 1) --R, data_[R] = M_(x, data_[R]);\n        if (L & 1) data_[L]\
    \ = M_(x, data_[L]), ++L;\n        L >>= 1, R >>= 1;\n      }\n    }\n\n    value_type\
    \ operator[](int i) {\n      assert(0 <= i and i < hsize_);\n      propagate_top_down(i\
    \ + hsize_);\n      return data_[i + hsize_];\n    }\n\n    template <typename\
    \ T>\n    void init_with_vector(const std::vector<T> &a) {\n      data_.assign(size_,\
    \ M_());\n      for (int i = 0; i < (int) a.size(); ++i) data_[hsize_ + i] = a[i];\n\
    \    }\n\n    template <typename T>\n    void init(const T &val) {\n      init_with_vector(std::vector<value_type>(hsize_,\
    \ val));\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename Monoid>\n  class dual_segment_tree {\n  public:\n  \
    \  using value_type = typename Monoid::value_type;\n\n  private:\n    Monoid M_;\n\
    \    int depth_, size_, hsize_;\n    std::vector<value_type> data_;\n\n    void\
    \ propagate(int i) {\n      if (i < hsize_) {\n        data_[i << 1 | 0] = M_(data_[i],\
    \ data_[i << 1 | 0]);\n        data_[i << 1 | 1] = M_(data_[i], data_[i << 1 |\
    \ 1]);\n        data_[i]          = M_();\n      }\n    }\n\n    void propagate_top_down(int\
    \ i) {\n      std::vector<int> temp;\n      while (i > 1) {\n        i >>= 1;\n\
    \        temp.push_back(i);\n      }\n\n      for (auto it = temp.rbegin(); it\
    \ != temp.rend(); ++it) propagate(*it);\n    }\n\n  public:\n    dual_segment_tree()\
    \ {}\n    dual_segment_tree(int n) : depth_(n > 1 ? 32 - __builtin_clz(n - 1)\
    \ + 1 : 1),\n                               size_(1 << depth_),\n            \
    \                   hsize_(size_ / 2),\n                               data_(size_,\
    \ M_()) {}\n\n    void update(int l, int r, const value_type &x) {\n      assert(0\
    \ <= l and l <= r and r <= hsize_);\n      propagate_top_down(l + hsize_);\n \
    \     propagate_top_down(r + hsize_);\n\n      int L = l + hsize_;\n      int\
    \ R = r + hsize_;\n\n      while (L < R) {\n        if (R & 1) --R, data_[R] =\
    \ M_(x, data_[R]);\n        if (L & 1) data_[L] = M_(x, data_[L]), ++L;\n    \
    \    L >>= 1, R >>= 1;\n      }\n    }\n\n    value_type operator[](int i) {\n\
    \      assert(0 <= i and i < hsize_);\n      propagate_top_down(i + hsize_);\n\
    \      return data_[i + hsize_];\n    }\n\n    template <typename T>\n    void\
    \ init_with_vector(const std::vector<T> &a) {\n      data_.assign(size_, M_());\n\
    \      for (int i = 0; i < (int) a.size(); ++i) data_[hsize_ + i] = a[i];\n  \
    \  }\n\n    template <typename T>\n    void init(const T &val) {\n      init_with_vector(std::vector<value_type>(hsize_,\
    \ val));\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/dual_segment_tree.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_2_E/main.test.cpp
  - test/aoj/DSL_2_D/main.test.cpp
documentation_of: Mylib/DataStructure/SegmentTree/dual_segment_tree.cpp
layout: document
title: Dual segment tree
---

## Operations
モノイド$(M, \circ, e)$上の列を扱う。
- `DualSegmentTree(n)`
- `update(l, r, v)`
	- `i in [l, r)`について$a_i \leftarrow v \circ a_i$に更新する。
- `get(i)`
	- $a_i$を返す。
- `init_with_vector(a)`
- `init(value)`

## Requirements

- `Monoid`は結合律を満たす演算`op`と単位元`id`をもつ。

## Notes

## Problems

## References
