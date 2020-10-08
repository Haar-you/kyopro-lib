---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_H/main.starry_sky.test.cpp
    title: test/aoj/DSL_2_H/main.starry_sky.test.cpp
  - icon: ':x:'
    path: test/yukicoder/631/main.starry_sky.test.cpp
    title: test/yukicoder/631/main.starry_sky.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp\"\n\
    #include <vector>\n#include <optional>\n#include <algorithm>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Compare>\n  class starry_sky_tree {\n  public:\n\
    \    using value_type = T;\n\n  private:\n    int depth_, size_, hsize_;\n   \
    \ std::vector<T> data_;\n    Compare compare_ = Compare();\n\n    T f(T a, T b)\
    \ const {\n      return compare_(a, b) ? a : b;\n    }\n\n    void bottom_up(int\
    \ i){\n      if(i > size_) return;\n\n      while(i >= 1){\n        if(i < hsize_){\n\
    \          const auto d = f(data_[i << 1 | 0], data_[i << 1 | 1]);\n\n       \
    \   data_[i << 1 | 0] -= d;\n          data_[i << 1 | 1] -= d;\n          data_[i]\
    \ += d;\n        }\n\n        i >>= 1;\n      }\n    }\n\n    std::optional<T>\
    \ get(int i, int l, int r, int s, int t, T val) const {\n      if(r <= s or t\
    \ <= l) return std::nullopt;\n      if(s <= l and r <= t) return val + data_[i];\n\
    \n      auto a = get(i << 1 | 0, l, (l + r) / 2, s, t, val + data_[i]);\n    \
    \  auto b = get(i << 1 | 1, (l + r) / 2, r, s, t, val + data_[i]);\n\n      if(not\
    \ a) return b;\n      if(not b) return a;\n      return f(*a, *b);\n    }\n\n\
    \  public:\n    starry_sky_tree(){}\n    starry_sky_tree(int n):\n      depth_(n\
    \ > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size_(1 << depth_),\n     \
    \ hsize_(size_ / 2),\n      data_(size_, 0)\n    {}\n\n    void update(int l,\
    \ int r, T val){\n      int L = l + hsize_;\n      int R = r + hsize_;\n\n   \
    \   while(L < R){\n        if(R & 1) --R, data_[R] += val;\n        if(L & 1)\
    \ data_[L] += val, ++L;\n        L >>= 1;\n        R >>= 1;\n      }\n\n     \
    \ bottom_up(l + hsize_);\n      bottom_up(r + hsize_);\n    }\n\n    T fold(int\
    \ l, int r) const {\n      return *get(1, 0, hsize_, l, r, 0);\n    }\n\n    T\
    \ fold_all() const {\n      return data_[1];\n    }\n\n    template <typename\
    \ U>\n    void init_with_vector(std::vector<U> &a){\n      for(int i = 0; i <\
    \ (int)a.size(); ++i){\n        data_[hsize_ + i] = a[i];\n      }\n\n      for(int\
    \ i = hsize_; --i >= 1;){\n        data_[i] = f(data_[i << 1 | 0], data_[i <<\
    \ 1 | 1]);\n      }\n\n      for(int i = size_; --i > 1;){\n        data_[i] -=\
    \ data_[i >> 1];\n      }\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <optional>\n#include <algorithm>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Compare>\n  class starry_sky_tree\
    \ {\n  public:\n    using value_type = T;\n\n  private:\n    int depth_, size_,\
    \ hsize_;\n    std::vector<T> data_;\n    Compare compare_ = Compare();\n\n  \
    \  T f(T a, T b) const {\n      return compare_(a, b) ? a : b;\n    }\n\n    void\
    \ bottom_up(int i){\n      if(i > size_) return;\n\n      while(i >= 1){\n   \
    \     if(i < hsize_){\n          const auto d = f(data_[i << 1 | 0], data_[i <<\
    \ 1 | 1]);\n\n          data_[i << 1 | 0] -= d;\n          data_[i << 1 | 1] -=\
    \ d;\n          data_[i] += d;\n        }\n\n        i >>= 1;\n      }\n    }\n\
    \n    std::optional<T> get(int i, int l, int r, int s, int t, T val) const {\n\
    \      if(r <= s or t <= l) return std::nullopt;\n      if(s <= l and r <= t)\
    \ return val + data_[i];\n\n      auto a = get(i << 1 | 0, l, (l + r) / 2, s,\
    \ t, val + data_[i]);\n      auto b = get(i << 1 | 1, (l + r) / 2, r, s, t, val\
    \ + data_[i]);\n\n      if(not a) return b;\n      if(not b) return a;\n     \
    \ return f(*a, *b);\n    }\n\n  public:\n    starry_sky_tree(){}\n    starry_sky_tree(int\
    \ n):\n      depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size_(1\
    \ << depth_),\n      hsize_(size_ / 2),\n      data_(size_, 0)\n    {}\n\n   \
    \ void update(int l, int r, T val){\n      int L = l + hsize_;\n      int R =\
    \ r + hsize_;\n\n      while(L < R){\n        if(R & 1) --R, data_[R] += val;\n\
    \        if(L & 1) data_[L] += val, ++L;\n        L >>= 1;\n        R >>= 1;\n\
    \      }\n\n      bottom_up(l + hsize_);\n      bottom_up(r + hsize_);\n    }\n\
    \n    T fold(int l, int r) const {\n      return *get(1, 0, hsize_, l, r, 0);\n\
    \    }\n\n    T fold_all() const {\n      return data_[1];\n    }\n\n    template\
    \ <typename U>\n    void init_with_vector(std::vector<U> &a){\n      for(int i\
    \ = 0; i < (int)a.size(); ++i){\n        data_[hsize_ + i] = a[i];\n      }\n\n\
    \      for(int i = hsize_; --i >= 1;){\n        data_[i] = f(data_[i << 1 | 0],\
    \ data_[i << 1 | 1]);\n      }\n\n      for(int i = size_; --i > 1;){\n      \
    \  data_[i] -= data_[i >> 1];\n      }\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp
  requiredBy: []
  timestamp: '2020-09-28 13:26:18+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/631/main.starry_sky.test.cpp
  - test/aoj/DSL_2_H/main.starry_sky.test.cpp
documentation_of: Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp
layout: document
title: Starry-sky tree
---

## Operations

- `StarrySkyTree(n)`
- `update(l, r, val)`
	- `i in [l, r)`について$a_i \leftarrow a_i + v$に更新する。
- `get(l, r)`
	- `Compare = less<T>`
		- $\min_{l \le i \lt r} a_i$を返す。
	- `Compare = greater<T>`
		- $\max_{l \le i \lt r} a_i$を返す。
- `init_with_vector(a)`

## Requirements

## Notes

## Problems

- [starry_sky - 星空 (Starry Sky)](https://atcoder.jp/contests/joisc2009/tasks/joisc2009_starry_sky)
- [yukicoder No.631 Noelちゃんと電車旅行](https://yukicoder.me/problems/no/631)

## References

- [https://qnighy.github.io/informatics-olympiad/joi2009-day4-starry_sky-comment.html](https://qnighy.github.io/informatics-olympiad/joi2009-day4-starry_sky-comment.html)

