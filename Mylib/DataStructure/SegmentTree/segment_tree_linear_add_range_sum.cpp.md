---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/segment_tree_linear_add_range_sum.cpp\"\
    \n#include <vector>\n#include <utility>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class segment_tree_linear_add_range_sum {\n    using P = std::pair<T,\
    \ T>;\n\n    int depth, size, hsize;\n    std::vector<T> data;\n    std::vector<P>\
    \ lazy;\n\n  public:\n    segment_tree_linear_add_range_sum(){}\n    segment_tree_linear_add_range_sum(int\
    \ n):\n      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 <<\
    \ depth), hsize(size / 2),\n      data(size, T()),\n      lazy(size, P())\n  \
    \  {}\n\n  private:\n    P add(P a, P b){\n      return {a.first + b.first, a.second\
    \ + b.second};\n    }\n\n    void propagate(int i, int l, int r){\n      if(lazy[i]\
    \ == P()) return;\n      if(i < hsize){\n        auto t = lazy[i];\n        lazy[i\
    \ << 1 | 0] = add(t, lazy[i << 1 | 0]);\n        t.first += t.second * ((r - l)\
    \ / 2);\n        lazy[i << 1 | 1] = add(t, lazy[i << 1 | 1]);\n      }\n     \
    \ const int len = r - l;\n      const auto [s, d] = lazy[i];\n      data[i] +=\
    \ len * (s * 2 + d * (len - 1)) / 2;\n      lazy[i] = P();\n    }\n\n    T update(int\
    \ i, int l, int r, int s, int t, T a, T b){\n      propagate(i, l, r);\n     \
    \ if(r <= s or t <= l) return data[i];\n      if(s <= l and r <= t){\n       \
    \ lazy[i] = add(lazy[i], std::make_pair(b + (l - s) * a, a));\n        propagate(i,\
    \ l, r);\n        return data[i];\n      }\n      return data[i] =\n        update(i\
    \ << 1 | 0, l, (l + r) / 2, s, t, a, b) +\n        update(i << 1 | 1, (l + r)\
    \ / 2, r, s, t, a, b);\n    }\n\n    T get(int i, int l, int r, int x, int y){\n\
    \      propagate(i, l, r);\n      if(r <= x or y <= l) return 0;\n      if(x <=\
    \ l and r <= y) return data[i];\n      return\n        get(i << 1 | 0, l, (l +\
    \ r) / 2, x, y) +\n        get(i << 1 | 1, (l + r) / 2, r, x, y);\n    }\n\n \
    \ public:\n    void update(int l, int r, T a, T b){\n      update(1, 0, hsize,\
    \ l, r, a, b);\n    }\n\n    T fold(int l, int r){\n      return get(1, 0, hsize,\
    \ l, r);\n    }\n\n    T operator[](int i){\n      return fold(i, i + 1);\n  \
    \  }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  class segment_tree_linear_add_range_sum {\n  \
    \  using P = std::pair<T, T>;\n\n    int depth, size, hsize;\n    std::vector<T>\
    \ data;\n    std::vector<P> lazy;\n\n  public:\n    segment_tree_linear_add_range_sum(){}\n\
    \    segment_tree_linear_add_range_sum(int n):\n      depth(n > 1 ? 32 - __builtin_clz(n\
    \ - 1) + 1 : 1),\n      size(1 << depth), hsize(size / 2),\n      data(size, T()),\n\
    \      lazy(size, P())\n    {}\n\n  private:\n    P add(P a, P b){\n      return\
    \ {a.first + b.first, a.second + b.second};\n    }\n\n    void propagate(int i,\
    \ int l, int r){\n      if(lazy[i] == P()) return;\n      if(i < hsize){\n   \
    \     auto t = lazy[i];\n        lazy[i << 1 | 0] = add(t, lazy[i << 1 | 0]);\n\
    \        t.first += t.second * ((r - l) / 2);\n        lazy[i << 1 | 1] = add(t,\
    \ lazy[i << 1 | 1]);\n      }\n      const int len = r - l;\n      const auto\
    \ [s, d] = lazy[i];\n      data[i] += len * (s * 2 + d * (len - 1)) / 2;\n   \
    \   lazy[i] = P();\n    }\n\n    T update(int i, int l, int r, int s, int t, T\
    \ a, T b){\n      propagate(i, l, r);\n      if(r <= s or t <= l) return data[i];\n\
    \      if(s <= l and r <= t){\n        lazy[i] = add(lazy[i], std::make_pair(b\
    \ + (l - s) * a, a));\n        propagate(i, l, r);\n        return data[i];\n\
    \      }\n      return data[i] =\n        update(i << 1 | 0, l, (l + r) / 2, s,\
    \ t, a, b) +\n        update(i << 1 | 1, (l + r) / 2, r, s, t, a, b);\n    }\n\
    \n    T get(int i, int l, int r, int x, int y){\n      propagate(i, l, r);\n \
    \     if(r <= x or y <= l) return 0;\n      if(x <= l and r <= y) return data[i];\n\
    \      return\n        get(i << 1 | 0, l, (l + r) / 2, x, y) +\n        get(i\
    \ << 1 | 1, (l + r) / 2, r, x, y);\n    }\n\n  public:\n    void update(int l,\
    \ int r, T a, T b){\n      update(1, 0, hsize, l, r, a, b);\n    }\n\n    T fold(int\
    \ l, int r){\n      return get(1, 0, hsize, l, r);\n    }\n\n    T operator[](int\
    \ i){\n      return fold(i, i + 1);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/segment_tree_linear_add_range_sum.cpp
  requiredBy: []
  timestamp: '2020-09-25 01:38:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/DataStructure/SegmentTree/segment_tree_linear_add_range_sum.cpp
layout: document
title: Segment tree (Add $ai + b$, Range sum)
---

## Operations

## Requirements

## Notes

## Problems

- [Heavy Light 2 White Falcon](https://www.hackerrank.com/challenges/heavy-light-2-white-falcon/problem)

## References
