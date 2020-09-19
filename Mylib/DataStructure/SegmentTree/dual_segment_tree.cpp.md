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
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/dual_segment_tree.cpp\"\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename Monoid>\n  class\
    \ dual_segment_tree {\n    using value_type = typename Monoid::value_type;\n \
    \   const static Monoid M;\n\n    const int depth, size, hsize;\n    std::vector<value_type>\
    \ data;\n\n    void propagate(int i){\n      if(i < hsize){\n        data[i <<\
    \ 1 | 0] = M(data[i], data[i << 1 | 0]);\n        data[i << 1 | 1] = M(data[i],\
    \ data[i << 1 | 1]);\n        data[i] = M();\n      }\n    }\n\n    void propagate_top_down(int\
    \ i){\n      std::vector<int> temp;\n      while(i > 1){\n        i >>= 1;\n \
    \       temp.push_back(i);\n      }\n\n      for(auto it = temp.rbegin(); it !=\
    \ temp.rend(); ++it) propagate(*it);\n    }\n\n  public:\n    dual_segment_tree(int\
    \ n):\n      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 <<\
    \ depth), hsize(size / 2),\n      data(size, M())\n    {}\n\n    void update(int\
    \ l, int r, const value_type &x){\n      propagate_top_down(l + hsize);\n    \
    \  propagate_top_down(r + hsize);\n\n      int L = l + hsize;\n      int R = r\
    \ + hsize;\n\n      while(L < R){\n        if(R & 1) --R, data[R] = M(x, data[R]);\n\
    \        if(L & 1) data[L] = M(x, data[L]), ++L;\n        L >>= 1, R >>= 1;\n\
    \      }\n    }\n\n    value_type operator[](int i){\n      propagate_top_down(i\
    \ + hsize);\n      return data[i + hsize];\n    }\n\n    template <typename T>\n\
    \    void init_with_vector(const std::vector<T> &a){\n      data.assign(size,\
    \ M());\n      for(int i = 0; i < (int)a.size(); ++i) data[hsize + i] = a[i];\n\
    \    }\n\n    template <typename T>\n    void init(const T &val){\n      init_with_vector(std::vector<value_type>(hsize,\
    \ val));\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ Monoid>\n  class dual_segment_tree {\n    using value_type = typename Monoid::value_type;\n\
    \    const static Monoid M;\n\n    const int depth, size, hsize;\n    std::vector<value_type>\
    \ data;\n\n    void propagate(int i){\n      if(i < hsize){\n        data[i <<\
    \ 1 | 0] = M(data[i], data[i << 1 | 0]);\n        data[i << 1 | 1] = M(data[i],\
    \ data[i << 1 | 1]);\n        data[i] = M();\n      }\n    }\n\n    void propagate_top_down(int\
    \ i){\n      std::vector<int> temp;\n      while(i > 1){\n        i >>= 1;\n \
    \       temp.push_back(i);\n      }\n\n      for(auto it = temp.rbegin(); it !=\
    \ temp.rend(); ++it) propagate(*it);\n    }\n\n  public:\n    dual_segment_tree(int\
    \ n):\n      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 <<\
    \ depth), hsize(size / 2),\n      data(size, M())\n    {}\n\n    void update(int\
    \ l, int r, const value_type &x){\n      propagate_top_down(l + hsize);\n    \
    \  propagate_top_down(r + hsize);\n\n      int L = l + hsize;\n      int R = r\
    \ + hsize;\n\n      while(L < R){\n        if(R & 1) --R, data[R] = M(x, data[R]);\n\
    \        if(L & 1) data[L] = M(x, data[L]), ++L;\n        L >>= 1, R >>= 1;\n\
    \      }\n    }\n\n    value_type operator[](int i){\n      propagate_top_down(i\
    \ + hsize);\n      return data[i + hsize];\n    }\n\n    template <typename T>\n\
    \    void init_with_vector(const std::vector<T> &a){\n      data.assign(size,\
    \ M());\n      for(int i = 0; i < (int)a.size(); ++i) data[hsize + i] = a[i];\n\
    \    }\n\n    template <typename T>\n    void init(const T &val){\n      init_with_vector(std::vector<value_type>(hsize,\
    \ val));\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/dual_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_2_D/main.test.cpp
  - test/aoj/DSL_2_E/main.test.cpp
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

