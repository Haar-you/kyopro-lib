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
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/lazy_segment_tree_with_coefficients.cpp\"\
    \n#include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  class\
    \ lazy_segment_tree_with_coefficients {\n    const int depth, size, hsize;\n \
    \   std::vector<T> data, lazy, coeff;\n\n    void propagate(int i){\n      if(lazy[i]\
    \ == 0) return;\n      if(i < hsize){\n        lazy[i << 1 | 0] = lazy[i] + lazy[i\
    \ << 1 | 0];\n        lazy[i << 1 | 1] = lazy[i] + lazy[i << 1 | 1];\n      }\n\
    \      data[i] = data[i] + lazy[i] * coeff[i];\n      lazy[i] = 0;\n    }\n\n\
    \    T update(int i, int l, int r, int s, int t, const T &x){\n      propagate(i);\n\
    \      if(r <= s || t <= l) return data[i];\n      if(s <= l && r <= t){\n   \
    \     lazy[i] += x;\n        propagate(i);\n        return data[i];\n      }\n\
    \      return data[i] =\n        update(i << 1 | 0, l, (l + r) / 2, s, t, x) +\n\
    \        update(i << 1 | 1, (l + r) / 2, r, s, t, x);\n    }\n\n    T get(int\
    \ i, int l, int r, int x, int y){\n      propagate(i);\n      if(r <= x || y <=\
    \ l) return 0;\n      if(x <= l && r <= y) return data[i];\n      return get(i\
    \ << 1 | 0, l, (l + r) / 2, x, y) + get(i << 1 | 1, (l + r) / 2, r, x, y);\n \
    \   }\n\n  public:\n    lazy_segment_tree_with_coefficients(){}\n    lazy_segment_tree_with_coefficients(int\
    \ n, std::vector<T> coeff_):\n      depth(n > 1 ? 32 - __builtin_clz(n - 1) +\
    \ 1 : 1),\n      size(1 << depth),\n      hsize(size / 2),\n      data(size, 0),\n\
    \      lazy(size, 0),\n      coeff(size, 0)\n    {\n      for(int i = hsize; i\
    \ < size; ++i) coeff[i] = coeff_[i - hsize];\n      for(int i = hsize; --i >=\
    \ 1;) coeff[i] = coeff[i << 1 | 0] + coeff[i << 1 | 1];\n    }\n\n    void update(int\
    \ l, int r, const T &x){update(1, 0, hsize, l, r, x);}\n    void update_at(int\
    \ i, const T &x){update(i, i + 1, x);}\n    T get(int l, int r){return get(1,\
    \ 0, hsize, l, r);}\n    T operator[](int i){return get(i, i + 1);}\n\n    void\
    \ init(const T &val){\n      init_with_vector(std::vector<T>(hsize, val));\n \
    \   }\n\n    void init_with_vector(const std::vector<T> &val){\n      data.assign(size,\
    \ 0);\n      lazy.assign(size, 0);\n      for(int i = 0; i < (int)val.size();\
    \ ++i) data[hsize + i] = val[i];\n      for(int i = hsize; --i >= 0;) data[i]\
    \ = data[i << 1 | 0] + data[i << 1 | 1];\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class lazy_segment_tree_with_coefficients {\n    const int depth, size,\
    \ hsize;\n    std::vector<T> data, lazy, coeff;\n\n    void propagate(int i){\n\
    \      if(lazy[i] == 0) return;\n      if(i < hsize){\n        lazy[i << 1 | 0]\
    \ = lazy[i] + lazy[i << 1 | 0];\n        lazy[i << 1 | 1] = lazy[i] + lazy[i <<\
    \ 1 | 1];\n      }\n      data[i] = data[i] + lazy[i] * coeff[i];\n      lazy[i]\
    \ = 0;\n    }\n\n    T update(int i, int l, int r, int s, int t, const T &x){\n\
    \      propagate(i);\n      if(r <= s || t <= l) return data[i];\n      if(s <=\
    \ l && r <= t){\n        lazy[i] += x;\n        propagate(i);\n        return\
    \ data[i];\n      }\n      return data[i] =\n        update(i << 1 | 0, l, (l\
    \ + r) / 2, s, t, x) +\n        update(i << 1 | 1, (l + r) / 2, r, s, t, x);\n\
    \    }\n\n    T get(int i, int l, int r, int x, int y){\n      propagate(i);\n\
    \      if(r <= x || y <= l) return 0;\n      if(x <= l && r <= y) return data[i];\n\
    \      return get(i << 1 | 0, l, (l + r) / 2, x, y) + get(i << 1 | 1, (l + r)\
    \ / 2, r, x, y);\n    }\n\n  public:\n    lazy_segment_tree_with_coefficients(){}\n\
    \    lazy_segment_tree_with_coefficients(int n, std::vector<T> coeff_):\n    \
    \  depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 << depth),\n\
    \      hsize(size / 2),\n      data(size, 0),\n      lazy(size, 0),\n      coeff(size,\
    \ 0)\n    {\n      for(int i = hsize; i < size; ++i) coeff[i] = coeff_[i - hsize];\n\
    \      for(int i = hsize; --i >= 1;) coeff[i] = coeff[i << 1 | 0] + coeff[i <<\
    \ 1 | 1];\n    }\n\n    void update(int l, int r, const T &x){update(1, 0, hsize,\
    \ l, r, x);}\n    void update_at(int i, const T &x){update(i, i + 1, x);}\n  \
    \  T get(int l, int r){return get(1, 0, hsize, l, r);}\n    T operator[](int i){return\
    \ get(i, i + 1);}\n\n    void init(const T &val){\n      init_with_vector(std::vector<T>(hsize,\
    \ val));\n    }\n\n    void init_with_vector(const std::vector<T> &val){\n   \
    \   data.assign(size, 0);\n      lazy.assign(size, 0);\n      for(int i = 0; i\
    \ < (int)val.size(); ++i) data[hsize + i] = val[i];\n      for(int i = hsize;\
    \ --i >= 0;) data[i] = data[i << 1 | 0] + data[i << 1 | 1];\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/lazy_segment_tree_with_coefficients.cpp
  requiredBy: []
  timestamp: '2020-09-16 21:53:52+09:00'
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
