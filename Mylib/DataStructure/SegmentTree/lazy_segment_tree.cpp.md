---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2667/main.test.cpp
    title: test/aoj/2667/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3035/main.test.cpp
    title: test/aoj/3035/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F/main.test.cpp
    title: test/aoj/DSL_2_F/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G/main.test.cpp
    title: test/aoj/DSL_2_G/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H/main.test.cpp
    title: test/aoj/DSL_2_H/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I/main.test.cpp
    title: test/aoj/DSL_2_I/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/range_affine_range_sum/main.test.cpp
    title: test/yosupo-judge/range_affine_range_sum/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1099/main.test.cpp
    title: test/yukicoder/1099/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/631/main.test.cpp
    title: test/yukicoder/631/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/899/main.test.cpp
    title: test/yukicoder/899/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\n\
    #include <vector>\n#include <cassert>\n\nnamespace haar_lib {\n  template <typename\
    \ Monoid>\n  class lazy_segment_tree {\n  public:\n    using monoid_get = typename\
    \ Monoid::monoid_get;\n    using monoid_update = typename Monoid::monoid_update;\n\
    \    using value_type_get = typename monoid_get::value_type;\n    using value_type_update\
    \ = typename monoid_update::value_type;\n\n  private:\n    Monoid M_;\n    monoid_get\
    \ M_get_;\n    monoid_update M_update_;\n\n    int depth_, size_, hsize_;\n  \
    \  std::vector<value_type_get> data_;\n    std::vector<value_type_update> lazy_;\n\
    \n    void propagate(int i){\n      if(lazy_[i] == M_update_()) return;\n    \
    \  if(i < hsize_){\n        lazy_[i << 1 | 0] = M_update_(lazy_[i], lazy_[i <<\
    \ 1 | 0]);\n        lazy_[i << 1 | 1] = M_update_(lazy_[i], lazy_[i << 1 | 1]);\n\
    \      }\n      const int len = hsize_ >> (31 - __builtin_clz(i));\n      data_[i]\
    \ = M_(data_[i], lazy_[i], len);\n      lazy_[i] = M_update_();\n    }\n\n   \
    \ void propagate_top_down(int i){\n      std::vector<int> temp;\n      while(i\
    \ > 1){\n        i >>= 1;\n        temp.push_back(i);\n      }\n\n      for(auto\
    \ it = temp.rbegin(); it != temp.rend(); ++it) propagate(*it);\n    }\n\n    void\
    \ bottom_up(int i){\n      while(i > 1){\n        i >>= 1;\n        propagate(i\
    \ << 1 | 0);\n        propagate(i << 1 | 1);\n        data_[i] = M_get_(data_[i\
    \ << 1 | 0], data_[i << 1 | 1]);\n      }\n    }\n\n  public:\n    lazy_segment_tree(){}\n\
    \    lazy_segment_tree(int n):\n      depth_(n > 1 ? 32 - __builtin_clz(n - 1)\
    \ + 1 : 1),\n      size_(1 << depth_),\n      hsize_(size_ / 2),\n      data_(size_,\
    \ M_get_()),\n      lazy_(size_, M_update_())\n    {}\n\n    void update(int l,\
    \ int r, const value_type_update &x){\n      assert(0 <= l and l <= r and r <=\
    \ hsize_);\n      propagate_top_down(l + hsize_);\n      if(r < hsize_) propagate_top_down(r\
    \ + hsize_);\n\n      int L = l + hsize_, R = r + hsize_;\n\n      while(L < R){\n\
    \        if(R & 1){\n          --R;\n          lazy_[R] = M_update_(x, lazy_[R]);\n\
    \          propagate(R);\n        }\n        if(L & 1){\n          lazy_[L] =\
    \ M_update_(x, lazy_[L]);\n          propagate(L);\n          ++L;\n        }\n\
    \        L >>= 1;\n        R >>= 1;\n      }\n\n      bottom_up(l + hsize_);\n\
    \      if(r < hsize_) bottom_up(r + hsize_);\n    }\n\n    void update(int i,\
    \ const value_type_update &x){update(i, i + 1, x);}\n\n    value_type_get fold(int\
    \ l, int r){\n      assert(0 <= l and l <= r and r <= hsize_);\n      propagate_top_down(l\
    \ + hsize_);\n      if(r < hsize_) propagate_top_down(r + hsize_);\n\n      value_type_get\
    \ ret_left = M_get_(), ret_right = M_get_();\n\n      int L = l + hsize_, R =\
    \ r + hsize_;\n\n      while(L < R){\n        if(R & 1){\n          --R;\n   \
    \       propagate(R);\n          ret_right = M_get_(data_[R], ret_right);\n  \
    \      }\n        if(L & 1){\n          propagate(L);\n          ret_left = M_get_(ret_left,\
    \ data_[L]);\n          ++L;\n        }\n        L >>= 1;\n        R >>= 1;\n\
    \      }\n\n      return M_get_(ret_left, ret_right);\n    }\n\n    value_type_get\
    \ fold_all(){\n      return fold(0, hsize_);\n    }\n\n    value_type_get operator[](int\
    \ i){return fold(i, i + 1);}\n\n    template <typename T>\n    void init(const\
    \ T &val){\n      init_with_vector(std::vector<T>(hsize_, val));\n    }\n\n  \
    \  template <typename T>\n    void init_with_vector(const std::vector<T> &val){\n\
    \      data_.assign(size_, M_get_());\n      lazy_.assign(size_, M_update_());\n\
    \      for(int i = 0; i < (int)val.size(); ++i) data_[hsize_ + i] = (value_type_get)val[i];\n\
    \      for(int i = hsize_; --i > 0;) data_[i] = M_get_(data_[i << 1 | 0], data_[i\
    \ << 1 | 1]);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  template <typename Monoid>\n  class lazy_segment_tree {\n  public:\n  \
    \  using monoid_get = typename Monoid::monoid_get;\n    using monoid_update =\
    \ typename Monoid::monoid_update;\n    using value_type_get = typename monoid_get::value_type;\n\
    \    using value_type_update = typename monoid_update::value_type;\n\n  private:\n\
    \    Monoid M_;\n    monoid_get M_get_;\n    monoid_update M_update_;\n\n    int\
    \ depth_, size_, hsize_;\n    std::vector<value_type_get> data_;\n    std::vector<value_type_update>\
    \ lazy_;\n\n    void propagate(int i){\n      if(lazy_[i] == M_update_()) return;\n\
    \      if(i < hsize_){\n        lazy_[i << 1 | 0] = M_update_(lazy_[i], lazy_[i\
    \ << 1 | 0]);\n        lazy_[i << 1 | 1] = M_update_(lazy_[i], lazy_[i << 1 |\
    \ 1]);\n      }\n      const int len = hsize_ >> (31 - __builtin_clz(i));\n  \
    \    data_[i] = M_(data_[i], lazy_[i], len);\n      lazy_[i] = M_update_();\n\
    \    }\n\n    void propagate_top_down(int i){\n      std::vector<int> temp;\n\
    \      while(i > 1){\n        i >>= 1;\n        temp.push_back(i);\n      }\n\n\
    \      for(auto it = temp.rbegin(); it != temp.rend(); ++it) propagate(*it);\n\
    \    }\n\n    void bottom_up(int i){\n      while(i > 1){\n        i >>= 1;\n\
    \        propagate(i << 1 | 0);\n        propagate(i << 1 | 1);\n        data_[i]\
    \ = M_get_(data_[i << 1 | 0], data_[i << 1 | 1]);\n      }\n    }\n\n  public:\n\
    \    lazy_segment_tree(){}\n    lazy_segment_tree(int n):\n      depth_(n > 1\
    \ ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size_(1 << depth_),\n      hsize_(size_\
    \ / 2),\n      data_(size_, M_get_()),\n      lazy_(size_, M_update_())\n    {}\n\
    \n    void update(int l, int r, const value_type_update &x){\n      assert(0 <=\
    \ l and l <= r and r <= hsize_);\n      propagate_top_down(l + hsize_);\n    \
    \  if(r < hsize_) propagate_top_down(r + hsize_);\n\n      int L = l + hsize_,\
    \ R = r + hsize_;\n\n      while(L < R){\n        if(R & 1){\n          --R;\n\
    \          lazy_[R] = M_update_(x, lazy_[R]);\n          propagate(R);\n     \
    \   }\n        if(L & 1){\n          lazy_[L] = M_update_(x, lazy_[L]);\n    \
    \      propagate(L);\n          ++L;\n        }\n        L >>= 1;\n        R >>=\
    \ 1;\n      }\n\n      bottom_up(l + hsize_);\n      if(r < hsize_) bottom_up(r\
    \ + hsize_);\n    }\n\n    void update(int i, const value_type_update &x){update(i,\
    \ i + 1, x);}\n\n    value_type_get fold(int l, int r){\n      assert(0 <= l and\
    \ l <= r and r <= hsize_);\n      propagate_top_down(l + hsize_);\n      if(r\
    \ < hsize_) propagate_top_down(r + hsize_);\n\n      value_type_get ret_left =\
    \ M_get_(), ret_right = M_get_();\n\n      int L = l + hsize_, R = r + hsize_;\n\
    \n      while(L < R){\n        if(R & 1){\n          --R;\n          propagate(R);\n\
    \          ret_right = M_get_(data_[R], ret_right);\n        }\n        if(L &\
    \ 1){\n          propagate(L);\n          ret_left = M_get_(ret_left, data_[L]);\n\
    \          ++L;\n        }\n        L >>= 1;\n        R >>= 1;\n      }\n\n  \
    \    return M_get_(ret_left, ret_right);\n    }\n\n    value_type_get fold_all(){\n\
    \      return fold(0, hsize_);\n    }\n\n    value_type_get operator[](int i){return\
    \ fold(i, i + 1);}\n\n    template <typename T>\n    void init(const T &val){\n\
    \      init_with_vector(std::vector<T>(hsize_, val));\n    }\n\n    template <typename\
    \ T>\n    void init_with_vector(const std::vector<T> &val){\n      data_.assign(size_,\
    \ M_get_());\n      lazy_.assign(size_, M_update_());\n      for(int i = 0; i\
    \ < (int)val.size(); ++i) data_[hsize_ + i] = (value_type_get)val[i];\n      for(int\
    \ i = hsize_; --i > 0;) data_[i] = M_get_(data_[i << 1 | 0], data_[i << 1 | 1]);\n\
    \    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-10-15 01:51:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1099/main.test.cpp
  - test/yukicoder/631/main.test.cpp
  - test/yukicoder/899/main.test.cpp
  - test/yosupo-judge/range_affine_range_sum/main.test.cpp
  - test/aoj/DSL_2_F/main.test.cpp
  - test/aoj/DSL_2_H/main.test.cpp
  - test/aoj/2667/main.test.cpp
  - test/aoj/3035/main.test.cpp
  - test/aoj/DSL_2_I/main.test.cpp
  - test/aoj/DSL_2_G/main.test.cpp
documentation_of: Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
layout: document
title: Lazy segment tree
---

## Operations

## Requirements

## Notes

## Problems

## References
