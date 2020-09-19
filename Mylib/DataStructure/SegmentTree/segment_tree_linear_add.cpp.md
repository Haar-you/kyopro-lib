---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1084/main.segment_tree.test.cpp
    title: test/yukicoder/1084/main.segment_tree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/segment_tree_linear_add.cpp\"\
    \n#include <vector>\n#include <utility>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class segment_tree_linear_add {\n    using value_type = T;\n    using\
    \ P = std::pair<T, T>;\n\n    int depth, size, hsize;\n\n    std::vector<P> data;\n\
    \    std::vector<int> from;\n\n    P add(P a, P b){\n      return {a.first + b.first,\
    \ a.second + b.second};\n    }\n\n    void propagate(int i){\n      if(i < hsize){\n\
    \        data[i << 1 | 0] = add(data[i << 1 | 0], data[i]);\n\n        int len\
    \ = hsize >> (31 - __builtin_clz(i) + 1);\n        data[i].first += data[i].second\
    \ * len;\n        data[i << 1 | 1] = add(data[i << 1 | 1], data[i]);\n\n     \
    \   data[i] = P();\n      }\n    }\n\n    void propagate_top_down(int i){\n  \
    \    std::vector<int> temp;\n      while(i > 1){\n        i >>= 1;\n        temp.push_back(i);\n\
    \      }\n\n      for(auto it = temp.rbegin(); it != temp.rend(); ++it) propagate(*it);\n\
    \    }\n\n  public:\n    segment_tree_linear_add(){}\n    segment_tree_linear_add(int\
    \ n):\n      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 <<\
    \ depth), hsize(size / 2),\n      data(size, P()),\n      from(size)\n    {\n\
    \      int s = 0;\n      for(int i = 1; i < size; ++i){\n        from[i] = s;\n\
    \        int l = hsize >> (31 - __builtin_clz(i));\n        s += l;\n        if(s\
    \ == hsize) s = 0;\n      }\n    }\n\n    void update(int l, int r, T a, T b){\n\
    \      int L = l + hsize;\n      int R = r + hsize;\n\n      while(L < R){\n \
    \       if(R & 1){\n          --R;\n          data[R] = add(std::make_pair(b +\
    \ a * (from[R] - l), a), data[R]);\n        }\n        if(L & 1){\n          data[L]\
    \ = add(std::make_pair(b + a * (from[L] - l), a), data[L]);\n          ++L;\n\
    \        }\n        L >>= 1;\n        R >>= 1;\n      }\n    }\n\n    T operator[](int\
    \ i){\n      propagate_top_down(i + hsize);\n      return data[i + hsize].first;\n\
    \    }\n\n    std::vector<T> get_all(int n){\n      std::vector<T> ret(n);\n \
    \     for(int i = 1; i < hsize; ++i) propagate(i);\n      for(int i = hsize; i\
    \ < hsize + n; ++i) ret[i - hsize] = data[i].first;\n      return ret;\n    }\n\
    \  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  class segment_tree_linear_add {\n    using value_type\
    \ = T;\n    using P = std::pair<T, T>;\n\n    int depth, size, hsize;\n\n    std::vector<P>\
    \ data;\n    std::vector<int> from;\n\n    P add(P a, P b){\n      return {a.first\
    \ + b.first, a.second + b.second};\n    }\n\n    void propagate(int i){\n    \
    \  if(i < hsize){\n        data[i << 1 | 0] = add(data[i << 1 | 0], data[i]);\n\
    \n        int len = hsize >> (31 - __builtin_clz(i) + 1);\n        data[i].first\
    \ += data[i].second * len;\n        data[i << 1 | 1] = add(data[i << 1 | 1], data[i]);\n\
    \n        data[i] = P();\n      }\n    }\n\n    void propagate_top_down(int i){\n\
    \      std::vector<int> temp;\n      while(i > 1){\n        i >>= 1;\n       \
    \ temp.push_back(i);\n      }\n\n      for(auto it = temp.rbegin(); it != temp.rend();\
    \ ++it) propagate(*it);\n    }\n\n  public:\n    segment_tree_linear_add(){}\n\
    \    segment_tree_linear_add(int n):\n      depth(n > 1 ? 32 - __builtin_clz(n\
    \ - 1) + 1 : 1),\n      size(1 << depth), hsize(size / 2),\n      data(size, P()),\n\
    \      from(size)\n    {\n      int s = 0;\n      for(int i = 1; i < size; ++i){\n\
    \        from[i] = s;\n        int l = hsize >> (31 - __builtin_clz(i));\n   \
    \     s += l;\n        if(s == hsize) s = 0;\n      }\n    }\n\n    void update(int\
    \ l, int r, T a, T b){\n      int L = l + hsize;\n      int R = r + hsize;\n\n\
    \      while(L < R){\n        if(R & 1){\n          --R;\n          data[R] =\
    \ add(std::make_pair(b + a * (from[R] - l), a), data[R]);\n        }\n       \
    \ if(L & 1){\n          data[L] = add(std::make_pair(b + a * (from[L] - l), a),\
    \ data[L]);\n          ++L;\n        }\n        L >>= 1;\n        R >>= 1;\n \
    \     }\n    }\n\n    T operator[](int i){\n      propagate_top_down(i + hsize);\n\
    \      return data[i + hsize].first;\n    }\n\n    std::vector<T> get_all(int\
    \ n){\n      std::vector<T> ret(n);\n      for(int i = 1; i < hsize; ++i) propagate(i);\n\
    \      for(int i = hsize; i < hsize + n; ++i) ret[i - hsize] = data[i].first;\n\
    \      return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/segment_tree_linear_add.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1084/main.segment_tree.test.cpp
documentation_of: Mylib/DataStructure/SegmentTree/segment_tree_linear_add.cpp
layout: document
title: Segment tree (Add $ai + b$)
---

## Operations

- `update(l, r, a, b)`
  - `[l, r)`に`a * i + b`(`a`を公差、`b`を初項とする等差数列)を加算する。

## Requirements

## Notes

## Problems

- [HUPC2020Day1 B Triangle Addition](https://onlinejudge.u-aizu.ac.jp/beta/room.html#HUPC2020Day1/problems/B)

## References
