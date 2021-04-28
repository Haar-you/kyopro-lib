---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/point_set_range_composite/main.test.cpp
    title: test/yosupo-judge/point_set_range_composite/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/queue_operate_all_composite/main.test.cpp
    title: test/yosupo-judge/queue_operate_all_composite/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/range_affine_range_sum/main.test.cpp
    title: test/yosupo-judge/range_affine_range_sum/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/vertex_set_path_composite/main.test.cpp
    title: test/yosupo-judge/vertex_set_path_composite/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/affine.cpp\"\n#include <utility>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  struct affine_monoid {\n  \
    \  using value_type = std::pair<T, T>;\n    value_type operator()() const { return\
    \ std::make_pair(1, 0); }\n    value_type operator()(const value_type &a, const\
    \ value_type &b) const {\n      return std::make_pair(a.first * b.first, a.first\
    \ * b.second + a.second);\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <utility>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct affine_monoid {\n    using value_type = std::pair<T, T>;\n    value_type\
    \ operator()() const { return std::make_pair(1, 0); }\n    value_type operator()(const\
    \ value_type &a, const value_type &b) const {\n      return std::make_pair(a.first\
    \ * b.first, a.first * b.second + a.second);\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/affine.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/queue_operate_all_composite/main.test.cpp
  - test/yosupo-judge/vertex_set_path_composite/main.test.cpp
  - test/yosupo-judge/point_set_range_composite/main.test.cpp
  - test/yosupo-judge/range_affine_range_sum/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/Monoid/affine.cpp
layout: document
title: Affine monoid
---

## Operations

- `id()`
	- 恒等関数 $f(x) = x$ を返す。
	- `return (1, 0)`
- `op(a, b)`
	- 合成した関数 $a \circ b$ を返す。

## Requirements

## Notes

## Problems

- [ARC 008 D - タコヤキオイシクナール](https://atcoder.jp/contests/arc008/tasks/arc008_4)
- [Point Set Range Composite](https://judge.yosupo.jp/problem/point_set_range_composite)

## References

