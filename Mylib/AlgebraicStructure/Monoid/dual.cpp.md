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
    path: test/yosupo-judge/vertex_set_path_composite/main.test.cpp
    title: test/yosupo-judge/vertex_set_path_composite/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/510/main.test.cpp
    title: test/yukicoder/510/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/dual.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename Monoid>\n  struct dual_monoid {\n    using\
    \ value_type = typename Monoid::value_type;\n    const static Monoid M;\n    value_type\
    \ operator()() const { return M(); }\n    value_type operator()(const value_type\
    \ &a, const value_type &b) const { return M(b, a); }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename Monoid>\n  struct\
    \ dual_monoid {\n    using value_type = typename Monoid::value_type;\n    const\
    \ static Monoid M;\n    value_type operator()() const { return M(); }\n    value_type\
    \ operator()(const value_type &a, const value_type &b) const { return M(b, a);\
    \ }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/dual.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/510/main.test.cpp
  - test/yosupo-judge/queue_operate_all_composite/main.test.cpp
  - test/yosupo-judge/vertex_set_path_composite/main.test.cpp
  - test/yosupo-judge/point_set_range_composite/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/Monoid/dual.cpp
layout: document
title: Dual monoid
---

## Operations

## Requirements

## Notes

## Problems

## References
