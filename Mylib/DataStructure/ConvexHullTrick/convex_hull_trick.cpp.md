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
  bundledCode: "#line 2 \"Mylib/DataStructure/ConvexHullTrick/convex_hull_trick.cpp\"\
    \n#include <deque>\n#include <utility>\n#include <functional>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Comparator = std::greater<T>>\n  class convex_hull_trick\
    \ {\n    using line = std::pair<T, T>;\n    std::deque<line> lines;\n    bool\
    \ is_needless(const line &a, const line &b, const line &c){\n      return (a.second\
    \ - b.second) * (a.first - c.first) >= (a.second - c.second) * (a.first - b.first);\n\
    \    }\n\n    T apply(const line &f, const T &x){\n      return f.first * x +\
    \ f.second;\n    }\n\n    Comparator comp = Comparator();\n\n  public:\n    convex_hull_trick(){}\n\
    \n    void add(const T &a, const T &b){\n      if(!lines.empty()){\n        auto\
    \ l = lines.back();\n\n        if(l.first == a){\n          if(not comp(l.second,\
    \ b)) return;\n          lines.pop_back();\n        }\n      }\n      while(lines.size()\
    \ >= 2 and is_needless(std::make_pair(a, b), lines.back(), *(lines.end() - 2))){\n\
    \        lines.pop_back();\n      }\n      lines.emplace_back(a, b);\n    }\n\n\
    \    T operator()(const T &x){\n      while(lines.size() >= 2 and comp(apply(lines[0],\
    \ x), apply(lines[1], x))){\n        lines.pop_front();\n      }\n      return\
    \ apply(lines[0], x);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <deque>\n#include <utility>\n#include <functional>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Comparator = std::greater<T>>\n\
    \  class convex_hull_trick {\n    using line = std::pair<T, T>;\n    std::deque<line>\
    \ lines;\n    bool is_needless(const line &a, const line &b, const line &c){\n\
    \      return (a.second - b.second) * (a.first - c.first) >= (a.second - c.second)\
    \ * (a.first - b.first);\n    }\n\n    T apply(const line &f, const T &x){\n \
    \     return f.first * x + f.second;\n    }\n\n    Comparator comp = Comparator();\n\
    \n  public:\n    convex_hull_trick(){}\n\n    void add(const T &a, const T &b){\n\
    \      if(!lines.empty()){\n        auto l = lines.back();\n\n        if(l.first\
    \ == a){\n          if(not comp(l.second, b)) return;\n          lines.pop_back();\n\
    \        }\n      }\n      while(lines.size() >= 2 and is_needless(std::make_pair(a,\
    \ b), lines.back(), *(lines.end() - 2))){\n        lines.pop_back();\n      }\n\
    \      lines.emplace_back(a, b);\n    }\n\n    T operator()(const T &x){\n   \
    \   while(lines.size() >= 2 and comp(apply(lines[0], x), apply(lines[1], x))){\n\
    \        lines.pop_front();\n      }\n      return apply(lines[0], x);\n    }\n\
    \  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/ConvexHullTrick/convex_hull_trick.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/DataStructure/ConvexHullTrick/convex_hull_trick.cpp
layout: document
title: Convex hull trick
---

## Operations

- `Comparator = std::greater<T>`の場合
	- `add(T a, T b)`
		- `a`は単調減少
		- 直線`f(x) = a*x + b`を追加する。
	- `query(T x)`
		- `x`は単調増加
		- `f(x)`の最小値を得る。

- `Comparator = std::less<T>`の場合
	- `add(T a, T b)`
		- `a`は単調増加
		- 直線`f(x) = a*x + b`を追加する。
	- `query(T x)`
		- `x`は単調増加
		- `f(x)`の最大値を得る。

## Requirements

## Notes

## Problems

- [EDPC Z - Frog 3](https://atcoder.jp/contests/dp/tasks/dp_z) (Minクエリ)
- [Codeforces Round #464 (Div. 2) E. Maximize!](https://codeforces.com/contest/939/problem/E) (Maxクエリ)

## References

- [http://satanic0258.hatenablog.com/entry/2016/08/16/181331](http://satanic0258.hatenablog.com/entry/2016/08/16/181331)
