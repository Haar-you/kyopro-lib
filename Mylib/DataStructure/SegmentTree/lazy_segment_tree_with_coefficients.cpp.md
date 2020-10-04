---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/235/main.test.cpp
    title: test/yukicoder/235/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/lazy_segment_tree_with_coefficients.cpp\"\
    \n#include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  class\
    \ lazy_segment_tree_with_coefficients {\n  public:\n    using value_type = T;\n\
    \n  private:\n    int depth_, size_, hsize_;\n    std::vector<T> data_, lazy_,\
    \ coeff_;\n\n    void propagate(int i){\n      if(lazy_[i] == 0) return;\n   \
    \   if(i < hsize_){\n        lazy_[i << 1 | 0] = lazy_[i] + lazy_[i << 1 | 0];\n\
    \        lazy_[i << 1 | 1] = lazy_[i] + lazy_[i << 1 | 1];\n      }\n      data_[i]\
    \ = data_[i] + lazy_[i] * coeff_[i];\n      lazy_[i] = 0;\n    }\n\n    T update(int\
    \ i, int l, int r, int s, int t, const T &x){\n      propagate(i);\n      if(r\
    \ <= s or t <= l) return data_[i];\n      if(s <= l and r <= t){\n        lazy_[i]\
    \ += x;\n        propagate(i);\n        return data_[i];\n      }\n      return\
    \ data_[i] =\n        update(i << 1 | 0, l, (l + r) / 2, s, t, x) +\n        update(i\
    \ << 1 | 1, (l + r) / 2, r, s, t, x);\n    }\n\n    T get(int i, int l, int r,\
    \ int x, int y){\n      propagate(i);\n      if(r <= x or y <= l) return 0;\n\
    \      if(x <= l and r <= y) return data_[i];\n      return get(i << 1 | 0, l,\
    \ (l + r) / 2, x, y) + get(i << 1 | 1, (l + r) / 2, r, x, y);\n    }\n\n  public:\n\
    \    lazy_segment_tree_with_coefficients(){}\n    lazy_segment_tree_with_coefficients(int\
    \ n, std::vector<T> coeff):\n      depth_(n > 1 ? 32 - __builtin_clz(n - 1) +\
    \ 1 : 1),\n      size_(1 << depth_),\n      hsize_(size_ / 2),\n      data_(size_,\
    \ 0),\n      lazy_(size_, 0),\n      coeff_(size_, 0)\n    {\n      for(int i\
    \ = hsize_; i < size_; ++i) coeff_[i] = coeff[i - hsize_];\n      for(int i =\
    \ hsize_; --i >= 1;) coeff_[i] = coeff_[i << 1 | 0] + coeff_[i << 1 | 1];\n  \
    \  }\n\n    void update(int l, int r, const T &x){update(1, 0, hsize_, l, r, x);}\n\
    \    void update(int i, const T &x){update(i, i + 1, x);}\n    T fold(int l, int\
    \ r){return get(1, 0, hsize_, l, r);}\n    T operator[](int i){return fold(i,\
    \ i + 1);}\n\n    void init(const T &val){\n      init_with_vector(std::vector<T>(hsize_,\
    \ val));\n    }\n\n    void init_with_vector(const std::vector<T> &val){\n   \
    \   data_.assign(size_, 0);\n      lazy_.assign(size_, 0);\n      for(int i =\
    \ 0; i < (int)val.size(); ++i) data_[hsize_ + i] = val[i];\n      for(int i =\
    \ hsize_; --i >= 0;) data_[i] = data_[i << 1 | 0] + data_[i << 1 | 1];\n    }\n\
    \  };\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class lazy_segment_tree_with_coefficients {\n  public:\n    using value_type\
    \ = T;\n\n  private:\n    int depth_, size_, hsize_;\n    std::vector<T> data_,\
    \ lazy_, coeff_;\n\n    void propagate(int i){\n      if(lazy_[i] == 0) return;\n\
    \      if(i < hsize_){\n        lazy_[i << 1 | 0] = lazy_[i] + lazy_[i << 1 |\
    \ 0];\n        lazy_[i << 1 | 1] = lazy_[i] + lazy_[i << 1 | 1];\n      }\n  \
    \    data_[i] = data_[i] + lazy_[i] * coeff_[i];\n      lazy_[i] = 0;\n    }\n\
    \n    T update(int i, int l, int r, int s, int t, const T &x){\n      propagate(i);\n\
    \      if(r <= s or t <= l) return data_[i];\n      if(s <= l and r <= t){\n \
    \       lazy_[i] += x;\n        propagate(i);\n        return data_[i];\n    \
    \  }\n      return data_[i] =\n        update(i << 1 | 0, l, (l + r) / 2, s, t,\
    \ x) +\n        update(i << 1 | 1, (l + r) / 2, r, s, t, x);\n    }\n\n    T get(int\
    \ i, int l, int r, int x, int y){\n      propagate(i);\n      if(r <= x or y <=\
    \ l) return 0;\n      if(x <= l and r <= y) return data_[i];\n      return get(i\
    \ << 1 | 0, l, (l + r) / 2, x, y) + get(i << 1 | 1, (l + r) / 2, r, x, y);\n \
    \   }\n\n  public:\n    lazy_segment_tree_with_coefficients(){}\n    lazy_segment_tree_with_coefficients(int\
    \ n, std::vector<T> coeff):\n      depth_(n > 1 ? 32 - __builtin_clz(n - 1) +\
    \ 1 : 1),\n      size_(1 << depth_),\n      hsize_(size_ / 2),\n      data_(size_,\
    \ 0),\n      lazy_(size_, 0),\n      coeff_(size_, 0)\n    {\n      for(int i\
    \ = hsize_; i < size_; ++i) coeff_[i] = coeff[i - hsize_];\n      for(int i =\
    \ hsize_; --i >= 1;) coeff_[i] = coeff_[i << 1 | 0] + coeff_[i << 1 | 1];\n  \
    \  }\n\n    void update(int l, int r, const T &x){update(1, 0, hsize_, l, r, x);}\n\
    \    void update(int i, const T &x){update(i, i + 1, x);}\n    T fold(int l, int\
    \ r){return get(1, 0, hsize_, l, r);}\n    T operator[](int i){return fold(i,\
    \ i + 1);}\n\n    void init(const T &val){\n      init_with_vector(std::vector<T>(hsize_,\
    \ val));\n    }\n\n    void init_with_vector(const std::vector<T> &val){\n   \
    \   data_.assign(size_, 0);\n      lazy_.assign(size_, 0);\n      for(int i =\
    \ 0; i < (int)val.size(); ++i) data_[hsize_ + i] = val[i];\n      for(int i =\
    \ hsize_; --i >= 0;) data_[i] = data_[i << 1 | 0] + data_[i << 1 | 1];\n    }\n\
    \  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/lazy_segment_tree_with_coefficients.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/235/main.test.cpp
documentation_of: Mylib/DataStructure/SegmentTree/lazy_segment_tree_with_coefficients.cpp
layout: document
title: Lazy segment tree (Range sum, Range add, With coefficients)
---

## Operations

## Requirements

## Notes

## Problems

## References
