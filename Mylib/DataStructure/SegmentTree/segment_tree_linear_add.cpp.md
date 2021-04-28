---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/3165/main.test.cpp
    title: test/aoj/3165/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/segment_tree_linear_add.cpp\"\
    \n#include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  class segment_tree_linear_add {\n  public:\n \
    \   using value_type = T;\n\n  private:\n    using P = std::pair<T, T>;\n\n  \
    \  int depth_, size_, hsize_;\n    std::vector<P> data_;\n    std::vector<int>\
    \ from_;\n\n    P add(P a, P b) {\n      return {a.first + b.first, a.second +\
    \ b.second};\n    }\n\n    void propagate(int i) {\n      if (i < hsize_) {\n\
    \        data_[i << 1 | 0] = add(data_[i << 1 | 0], data_[i]);\n\n        const\
    \ int len = hsize_ >> (31 - __builtin_clz(i) + 1);\n        data_[i].first +=\
    \ data_[i].second * len;\n        data_[i << 1 | 1] = add(data_[i << 1 | 1], data_[i]);\n\
    \n        data_[i] = P();\n      }\n    }\n\n    void propagate_top_down(int i)\
    \ {\n      std::vector<int> temp;\n      while (i > 1) {\n        i >>= 1;\n \
    \       temp.push_back(i);\n      }\n\n      for (auto it = temp.rbegin(); it\
    \ != temp.rend(); ++it) propagate(*it);\n    }\n\n  public:\n    segment_tree_linear_add()\
    \ {}\n    segment_tree_linear_add(int n) : depth_(n > 1 ? 32 - __builtin_clz(n\
    \ - 1) + 1 : 1),\n                                     size_(1 << depth_),\n \
    \                                    hsize_(size_ / 2),\n                    \
    \                 data_(size_, P()),\n                                     from_(size_)\
    \ {\n      int s = 0;\n      for (int i = 1; i < size_; ++i) {\n        from_[i]\
    \ = s;\n        int l    = hsize_ >> (31 - __builtin_clz(i));\n        s += l;\n\
    \        if (s == hsize_) s = 0;\n      }\n    }\n\n    void update(int l, int\
    \ r, T a, T b) {\n      assert(0 <= l and l <= r and r <= hsize_);\n      int\
    \ L = l + hsize_;\n      int R = r + hsize_;\n\n      while (L < R) {\n      \
    \  if (R & 1) {\n          --R;\n          data_[R] = add(std::make_pair(b + a\
    \ * (from_[R] - l), a), data_[R]);\n        }\n        if (L & 1) {\n        \
    \  data_[L] = add(std::make_pair(b + a * (from_[L] - l), a), data_[L]);\n    \
    \      ++L;\n        }\n        L >>= 1;\n        R >>= 1;\n      }\n    }\n\n\
    \    T operator[](int i) {\n      assert(0 <= i and i < hsize_);\n      propagate_top_down(i\
    \ + hsize_);\n      return data_[i + hsize_].first;\n    }\n\n    std::vector<T>\
    \ get_all(int n) {\n      std::vector<T> ret(n);\n      for (int i = 1; i < hsize_;\
    \ ++i) propagate(i);\n      for (int i = hsize_; i < hsize_ + n; ++i) ret[i -\
    \ hsize_] = data_[i].first;\n      return ret;\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  class segment_tree_linear_add\
    \ {\n  public:\n    using value_type = T;\n\n  private:\n    using P = std::pair<T,\
    \ T>;\n\n    int depth_, size_, hsize_;\n    std::vector<P> data_;\n    std::vector<int>\
    \ from_;\n\n    P add(P a, P b) {\n      return {a.first + b.first, a.second +\
    \ b.second};\n    }\n\n    void propagate(int i) {\n      if (i < hsize_) {\n\
    \        data_[i << 1 | 0] = add(data_[i << 1 | 0], data_[i]);\n\n        const\
    \ int len = hsize_ >> (31 - __builtin_clz(i) + 1);\n        data_[i].first +=\
    \ data_[i].second * len;\n        data_[i << 1 | 1] = add(data_[i << 1 | 1], data_[i]);\n\
    \n        data_[i] = P();\n      }\n    }\n\n    void propagate_top_down(int i)\
    \ {\n      std::vector<int> temp;\n      while (i > 1) {\n        i >>= 1;\n \
    \       temp.push_back(i);\n      }\n\n      for (auto it = temp.rbegin(); it\
    \ != temp.rend(); ++it) propagate(*it);\n    }\n\n  public:\n    segment_tree_linear_add()\
    \ {}\n    segment_tree_linear_add(int n) : depth_(n > 1 ? 32 - __builtin_clz(n\
    \ - 1) + 1 : 1),\n                                     size_(1 << depth_),\n \
    \                                    hsize_(size_ / 2),\n                    \
    \                 data_(size_, P()),\n                                     from_(size_)\
    \ {\n      int s = 0;\n      for (int i = 1; i < size_; ++i) {\n        from_[i]\
    \ = s;\n        int l    = hsize_ >> (31 - __builtin_clz(i));\n        s += l;\n\
    \        if (s == hsize_) s = 0;\n      }\n    }\n\n    void update(int l, int\
    \ r, T a, T b) {\n      assert(0 <= l and l <= r and r <= hsize_);\n      int\
    \ L = l + hsize_;\n      int R = r + hsize_;\n\n      while (L < R) {\n      \
    \  if (R & 1) {\n          --R;\n          data_[R] = add(std::make_pair(b + a\
    \ * (from_[R] - l), a), data_[R]);\n        }\n        if (L & 1) {\n        \
    \  data_[L] = add(std::make_pair(b + a * (from_[L] - l), a), data_[L]);\n    \
    \      ++L;\n        }\n        L >>= 1;\n        R >>= 1;\n      }\n    }\n\n\
    \    T operator[](int i) {\n      assert(0 <= i and i < hsize_);\n      propagate_top_down(i\
    \ + hsize_);\n      return data_[i + hsize_].first;\n    }\n\n    std::vector<T>\
    \ get_all(int n) {\n      std::vector<T> ret(n);\n      for (int i = 1; i < hsize_;\
    \ ++i) propagate(i);\n      for (int i = hsize_; i < hsize_ + n; ++i) ret[i -\
    \ hsize_] = data_[i].first;\n      return ret;\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/segment_tree_linear_add.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/3165/main.test.cpp
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
