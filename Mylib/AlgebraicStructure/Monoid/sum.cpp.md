---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2667/main.test.cpp
    title: test/aoj/2667/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2842/main.segment_tree.test.cpp
    title: test/aoj/2842/main.segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3035/main.test.cpp
    title: test/aoj/3035/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B/main.test.cpp
    title: test/aoj/DSL_2_B/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E/main.dynamic.test.cpp
    title: test/aoj/DSL_2_E/main.dynamic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E/main.test.cpp
    title: test/aoj/DSL_2_E/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G/main.test.cpp
    title: test/aoj/DSL_2_G/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H/main.test.cpp
    title: test/aoj/DSL_2_H/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I/main.test.cpp
    title: test/aoj/DSL_2_I/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp
    title: test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/point_add_rectangle_sum/main.test.cpp
    title: test/yosupo-judge/point_add_rectangle_sum/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/range_affine_range_sum/main.test.cpp
    title: test/yosupo-judge/range_affine_range_sum/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
    title: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp
    title: test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/vertex_add_path_sum/main.test.cpp
    title: test/yosupo-judge/vertex_add_path_sum/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp
    title: test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp
    title: test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1099/main.test.cpp
    title: test/yukicoder/1099/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/631/main.test.cpp
    title: test/yukicoder/631/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/789/main.test.cpp
    title: test/yukicoder/789/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/899/main.test.cpp
    title: test/yukicoder/899/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct sum_monoid {\n    using value_type = T;\n\
    \    value_type operator()() const {return 0;}\n    value_type operator()(value_type\
    \ a, value_type b) const {return a + b;}\n  };\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename T>\n  struct sum_monoid\
    \ {\n    using value_type = T;\n    value_type operator()() const {return 0;}\n\
    \    value_type operator()(value_type a, value_type b) const {return a + b;}\n\
    \  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/sum.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1099/main.test.cpp
  - test/yukicoder/899/main.test.cpp
  - test/yukicoder/789/main.test.cpp
  - test/yukicoder/631/main.test.cpp
  - test/aoj/DSL_2_B/main.test.cpp
  - test/aoj/DSL_2_I/main.test.cpp
  - test/aoj/2842/main.segment_tree.test.cpp
  - test/aoj/DSL_2_G/main.test.cpp
  - test/aoj/DSL_2_E/main.test.cpp
  - test/aoj/DSL_2_E/main.dynamic.test.cpp
  - test/aoj/2667/main.test.cpp
  - test/aoj/DSL_2_H/main.test.cpp
  - test/aoj/3035/main.test.cpp
  - test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp
  - test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
  - test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp
  - test/yosupo-judge/vertex_add_path_sum/main.test.cpp
  - test/yosupo-judge/range_affine_range_sum/main.test.cpp
  - test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp
  - test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp
  - test/yosupo-judge/point_add_rectangle_sum/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/Monoid/sum.cpp
layout: document
title: Sum monoid
---

## Operations

## Requirements

## Notes

## Problems

## References
