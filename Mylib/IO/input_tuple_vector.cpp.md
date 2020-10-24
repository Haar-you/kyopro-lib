---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0323/main.golden.test.cpp
    title: test/aoj/0323/main.golden.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0323/main.ternary.test.cpp
    title: test/aoj/0323/main.ternary.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0425/main.test.cpp
    title: test/aoj/0425/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0575/main.test.cpp
    title: test/aoj/0575/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1337/main.test.cpp
    title: test/aoj/1337/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1615/main.test.cpp
    title: test/aoj/1615/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2293/main.test.cpp
    title: test/aoj/2293/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2426/main.test.cpp
    title: test/aoj/2426/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3118/main.test.cpp
    title: test/aoj/3118/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3132/main.test.cpp
    title: test/aoj/3132/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_15_C/main.test.cpp
    title: test/aoj/ALDS1_15_C/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_1_B/main.test.cpp
    title: test/aoj/DPL_1_B/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_1_C/main.test.cpp
    title: test/aoj/DPL_1_C/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_1_F/main.test.cpp
    title: test/aoj/DPL_1_F/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_1_G/main.test.cpp
    title: test/aoj/DPL_1_G/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_1_H/main.test.cpp
    title: test/aoj/DPL_1_H/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_2_C/main.test.cpp
    title: test/aoj/DPL_2_C/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/manhattanmst/main.test.cpp
    title: test/yosupo-judge/manhattanmst/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/point_add_rectangle_sum/main.test.cpp
    title: test/yosupo-judge/point_add_rectangle_sum/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp
    title: test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
    title: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp
    title: test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1069/main.test.cpp
    title: test/yukicoder/1069/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/IO/input_tuple_vector.cpp\"\n#include <iostream>\n\
    #include <vector>\n#include <tuple>\n#include <utility>\n#include <initializer_list>\n\
    \nnamespace haar_lib {\n  template <typename T, size_t ... I>\n  void input_tuple_vector_init(T\
    \ &val, int N, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0) ...};\n  }\n\n  template <typename T, size_t ... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0) ...};\n  }\n\n  template <typename ... Args>\n \
    \ auto input_tuple_vector(int N){\n    std::tuple<std::vector<Args> ...> ret;\n\
    \n    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    for(int i = 0; i < N; ++i){\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <iostream>\n#include <vector>\n#include <tuple>\n\
    #include <utility>\n#include <initializer_list>\n\nnamespace haar_lib {\n  template\
    \ <typename T, size_t ... I>\n  void input_tuple_vector_init(T &val, int N, std::index_sequence<I\
    \ ...>){\n    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0) ...};\n  }\n\n  template <typename T, size_t ... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0) ...};\n  }\n\n  template <typename ... Args>\n \
    \ auto input_tuple_vector(int N){\n    std::tuple<std::vector<Args> ...> ret;\n\
    \n    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    for(int i = 0; i < N; ++i){\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/IO/input_tuple_vector.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1069/main.test.cpp
  - test/aoj/3132/main.test.cpp
  - test/aoj/0575/main.test.cpp
  - test/aoj/DPL_2_C/main.test.cpp
  - test/aoj/DPL_1_G/main.test.cpp
  - test/aoj/DPL_1_F/main.test.cpp
  - test/aoj/ALDS1_15_C/main.test.cpp
  - test/aoj/1337/main.test.cpp
  - test/aoj/1615/main.test.cpp
  - test/aoj/3118/main.test.cpp
  - test/aoj/DPL_1_C/main.test.cpp
  - test/aoj/0425/main.test.cpp
  - test/aoj/2293/main.test.cpp
  - test/aoj/2426/main.test.cpp
  - test/aoj/DPL_1_H/main.test.cpp
  - test/aoj/DPL_1_B/main.test.cpp
  - test/aoj/0323/main.golden.test.cpp
  - test/aoj/0323/main.ternary.test.cpp
  - test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp
  - test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp
  - test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
  - test/yosupo-judge/manhattanmst/main.test.cpp
  - test/yosupo-judge/point_add_rectangle_sum/main.test.cpp
documentation_of: Mylib/IO/input_tuple_vector.cpp
layout: document
title: Input tuple vector
---

## Operations

## Requirements

## Notes

## Problems

## References
