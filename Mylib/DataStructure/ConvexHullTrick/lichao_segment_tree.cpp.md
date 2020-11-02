---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/line_add_get_min/main.test.cpp
    title: test/yosupo-judge/line_add_get_min/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/segment_add_get_min/main.test.cpp
    title: test/yosupo-judge/segment_add_get_min/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/ConvexHullTrick/lichao_segment_tree.cpp\"\
    \n#include <utility>\n#include <vector>\n#include <algorithm>\n#include <optional>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Comparator>\n  class\
    \ lichao_segment_tree {\n  public:\n    using value_type = T;\n\n  private:\n\
    \    using line = std::pair<T, T>;\n\n    Comparator cmp_ = Comparator();\n  \
    \  std::vector<T> xs_;\n    int n_;\n    std::vector<std::optional<line>> data_;\n\
    \    std::vector<std::pair<int, int>> range_;\n\n    T chm(const T &a, const T\
    \ &b) const {\n      return cmp_(a, b) ? a : b;\n    }\n\n    void init_range_(int\
    \ i, int left, int right){\n      if(i >= 2 * n_) return;\n\n      range_[i] =\
    \ std::make_pair(left, right);\n      const int mid = (left + right) / 2;\n  \
    \    init_range_(i << 1 | 0, left, mid);\n      init_range_(i << 1 | 1, mid, right);\n\
    \    }\n\n  public:\n    lichao_segment_tree(){}\n    lichao_segment_tree(std::vector<T>\
    \ xs): xs_(xs){\n      std::sort(xs_.begin(), xs_.end());\n      xs_.erase(std::unique(xs_.begin(),\
    \ xs_.end()), xs_.end());\n\n      n_ = 1;\n      while(n_ < (int)xs_.size())\
    \ n_ *= 2;\n\n      const auto m = xs_.back();\n      xs_.resize(n_, m);\n\n \
    \     data_.assign(2 * n_, std::nullopt);\n\n      range_.resize(2 * n_);\n  \
    \    init_range_(1, 0, n_);\n    }\n\n    T apply(const line &l, const T &x) const\
    \ {\n      return l.first * x + l.second;\n    }\n\n  private:\n    void update(int\
    \ i, line new_line, int l, int r){\n      if(not data_[i]){\n        data_[i]\
    \ = new_line;\n        return;\n      }\n\n      const int m = (l + r) / 2;\n\n\
    \      auto lx = xs_[l], mx = xs_[m], rx = xs_[r - 1];\n\n      bool left = cmp_(apply(new_line,\
    \ lx), apply(*data_[i], lx));\n      bool mid = cmp_(apply(new_line, mx), apply(*data_[i],\
    \ mx));\n      bool right = cmp_(apply(new_line, rx), apply(*data_[i], rx));\n\
    \n      if(left and right){\n        data_[i] = new_line;\n        return;\n \
    \     }\n\n      if(not left and not right){\n        return;\n      }\n\n   \
    \   if(mid){\n        std::swap(*data_[i], new_line);\n      }\n\n      if(left\
    \ != mid){\n        update(i << 1 | 0, new_line, l, m);\n      }else{\n      \
    \  update(i << 1 | 1, new_line, m, r);\n      }\n    }\n\n  public:\n    void\
    \ add_line(T a, T b){\n      update(1, std::make_pair(a, b), 0, n_);\n    }\n\n\
    \    // [l, r)\n    void add_segment(T l, T r, T a, T b){\n      int left = std::lower_bound(xs_.begin(),\
    \ xs_.end(), l) - xs_.begin();\n      int right = std::lower_bound(xs_.begin(),\
    \ xs_.end(), r) - xs_.begin();\n\n      int L = left + n_;\n      int R = right\
    \ + n_;\n\n      while(L < R){\n        if(R & 1){\n          --R;\n         \
    \ update(R, std::make_pair(a, b), range_[R].first, range_[R].second);\n      \
    \  }\n\n        if(L & 1){\n          update(L, std::make_pair(a, b), range_[L].first,\
    \ range_[L].second);\n          ++L;\n        }\n\n        L >>= 1;\n        R\
    \ >>= 1;\n      }\n    }\n\n  public:\n    auto operator()(const T &x) const {\n\
    \      const int i = std::lower_bound(xs_.begin(), xs_.end(), x) - xs_.begin();\n\
    \      int k = i + n_;\n\n      std::optional<T> ret;\n\n      while(k > 0){\n\
    \        if(data_[k]){\n          if(not ret) ret = apply(*data_[k], xs_[i]);\n\
    \          else ret = chm(*ret, apply(*data_[k], xs_[i]));\n        }\n      \
    \  k >>= 1;\n      }\n\n      return ret;\n    }\n  };\n\n  template <typename\
    \ T>\n  auto make_lichao_min(const std::vector<T> &xs){\n    return lichao_segment_tree<T,\
    \ std::less<T>>(xs);\n  }\n\n  template <typename T>\n  auto make_lichao_max(const\
    \ std::vector<T> &xs){\n    return lichao_segment_tree<T, std::greater<T>>(xs);\n\
    \  }\n}\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\n#include <algorithm>\n\
    #include <optional>\n\nnamespace haar_lib {\n  template <typename T, typename\
    \ Comparator>\n  class lichao_segment_tree {\n  public:\n    using value_type\
    \ = T;\n\n  private:\n    using line = std::pair<T, T>;\n\n    Comparator cmp_\
    \ = Comparator();\n    std::vector<T> xs_;\n    int n_;\n    std::vector<std::optional<line>>\
    \ data_;\n    std::vector<std::pair<int, int>> range_;\n\n    T chm(const T &a,\
    \ const T &b) const {\n      return cmp_(a, b) ? a : b;\n    }\n\n    void init_range_(int\
    \ i, int left, int right){\n      if(i >= 2 * n_) return;\n\n      range_[i] =\
    \ std::make_pair(left, right);\n      const int mid = (left + right) / 2;\n  \
    \    init_range_(i << 1 | 0, left, mid);\n      init_range_(i << 1 | 1, mid, right);\n\
    \    }\n\n  public:\n    lichao_segment_tree(){}\n    lichao_segment_tree(std::vector<T>\
    \ xs): xs_(xs){\n      std::sort(xs_.begin(), xs_.end());\n      xs_.erase(std::unique(xs_.begin(),\
    \ xs_.end()), xs_.end());\n\n      n_ = 1;\n      while(n_ < (int)xs_.size())\
    \ n_ *= 2;\n\n      const auto m = xs_.back();\n      xs_.resize(n_, m);\n\n \
    \     data_.assign(2 * n_, std::nullopt);\n\n      range_.resize(2 * n_);\n  \
    \    init_range_(1, 0, n_);\n    }\n\n    T apply(const line &l, const T &x) const\
    \ {\n      return l.first * x + l.second;\n    }\n\n  private:\n    void update(int\
    \ i, line new_line, int l, int r){\n      if(not data_[i]){\n        data_[i]\
    \ = new_line;\n        return;\n      }\n\n      const int m = (l + r) / 2;\n\n\
    \      auto lx = xs_[l], mx = xs_[m], rx = xs_[r - 1];\n\n      bool left = cmp_(apply(new_line,\
    \ lx), apply(*data_[i], lx));\n      bool mid = cmp_(apply(new_line, mx), apply(*data_[i],\
    \ mx));\n      bool right = cmp_(apply(new_line, rx), apply(*data_[i], rx));\n\
    \n      if(left and right){\n        data_[i] = new_line;\n        return;\n \
    \     }\n\n      if(not left and not right){\n        return;\n      }\n\n   \
    \   if(mid){\n        std::swap(*data_[i], new_line);\n      }\n\n      if(left\
    \ != mid){\n        update(i << 1 | 0, new_line, l, m);\n      }else{\n      \
    \  update(i << 1 | 1, new_line, m, r);\n      }\n    }\n\n  public:\n    void\
    \ add_line(T a, T b){\n      update(1, std::make_pair(a, b), 0, n_);\n    }\n\n\
    \    // [l, r)\n    void add_segment(T l, T r, T a, T b){\n      int left = std::lower_bound(xs_.begin(),\
    \ xs_.end(), l) - xs_.begin();\n      int right = std::lower_bound(xs_.begin(),\
    \ xs_.end(), r) - xs_.begin();\n\n      int L = left + n_;\n      int R = right\
    \ + n_;\n\n      while(L < R){\n        if(R & 1){\n          --R;\n         \
    \ update(R, std::make_pair(a, b), range_[R].first, range_[R].second);\n      \
    \  }\n\n        if(L & 1){\n          update(L, std::make_pair(a, b), range_[L].first,\
    \ range_[L].second);\n          ++L;\n        }\n\n        L >>= 1;\n        R\
    \ >>= 1;\n      }\n    }\n\n  public:\n    auto operator()(const T &x) const {\n\
    \      const int i = std::lower_bound(xs_.begin(), xs_.end(), x) - xs_.begin();\n\
    \      int k = i + n_;\n\n      std::optional<T> ret;\n\n      while(k > 0){\n\
    \        if(data_[k]){\n          if(not ret) ret = apply(*data_[k], xs_[i]);\n\
    \          else ret = chm(*ret, apply(*data_[k], xs_[i]));\n        }\n      \
    \  k >>= 1;\n      }\n\n      return ret;\n    }\n  };\n\n  template <typename\
    \ T>\n  auto make_lichao_min(const std::vector<T> &xs){\n    return lichao_segment_tree<T,\
    \ std::less<T>>(xs);\n  }\n\n  template <typename T>\n  auto make_lichao_max(const\
    \ std::vector<T> &xs){\n    return lichao_segment_tree<T, std::greater<T>>(xs);\n\
    \  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/ConvexHullTrick/lichao_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/line_add_get_min/main.test.cpp
  - test/yosupo-judge/segment_add_get_min/main.test.cpp
documentation_of: Mylib/DataStructure/ConvexHullTrick/lichao_segment_tree.cpp
layout: document
title: LiChao segment tree
---

## Operations

- `LiChaoSegmentTree(xs)`
- `add_line(T a, T b)`
	- 直線`f(x) = a*x + b`を追加する。
	- Time complexity $O(\log N)$
- `add_segment(T l, T r, T a, T b)`
	- 線分`x in [l, r), f(x) = a*x + b`を追加する。
	- Time complexity $O(\log^2 N)$
- `query(T x)`
	- `Comparator = std::greater<T>`の場合は、`x`での最大値
	- `Comparator = std::less<T>`の場合は、`x`での最小値
	- Time complexity $O(\log N)$

## Requirements

## Notes

## Problems

- [Line Add Get Min](https://judge.yosupo.jp/problem/line_add_get_min)
- [Segment Add Get Min](https://judge.yosupo.jp/problem/segment_add_get_min)

## References

- [https://smijake3.hatenablog.com/entry/2018/06/16/144548](https://smijake3.hatenablog.com/entry/2018/06/16/144548)
