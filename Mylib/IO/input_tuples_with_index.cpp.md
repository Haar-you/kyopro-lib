---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508/main.splay_tree.test.cpp
    title: test/aoj/1508/main.splay_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508/main.treap.test.cpp
    title: test/aoj/1508/main.treap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2136/main.test.cpp
    title: test/aoj/2136/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_C/main.test.cpp
    title: test/aoj/DSL_2_C/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C/main.doubling.test.cpp
    title: test/aoj/GRL_5_C/main.doubling.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C/main.hld.test.cpp
    title: test/aoj/GRL_5_C/main.hld.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp
    title: test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/persistent_unionfind/main.test.cpp
    title: test/yosupo-judge/persistent_unionfind/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/point_set_range_composite/main.test.cpp
    title: test/yosupo-judge/point_set_range_composite/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/875/main.test.cpp
    title: test/yukicoder/875/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/IO/input_tuples_with_index.cpp\"\n#include <iostream>\n\
    #include <vector>\n#include <tuple>\n#include <utility>\n#include <initializer_list>\n\
    #line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T, size_t ... I>\n  static void input_tuple_helper(std::istream &s, T &val,\
    \ std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(s >>\
    \ std::get<I>(val)), 0) ...};\n  }\n\n  template <typename T, typename U>\n  std::istream&\
    \ operator>>(std::istream &s, std::pair<T, U> &value){\n    s >> value.first >>\
    \ value.second;\n    return s;\n  }\n\n  template <typename ... Args>\n  std::istream&\
    \ operator>>(std::istream &s, std::tuple<Args ...> &value){\n    input_tuple_helper(s,\
    \ value, std::make_index_sequence<sizeof ... (Args)>());\n    return s;\n  }\n\
    }\n#line 8 \"Mylib/IO/input_tuples_with_index.cpp\"\n\nnamespace haar_lib {\n\
    \  template <typename ... Args>\n  class InputTuplesWithIndex {\n    struct iter\
    \ {\n      using value_type = std::tuple<int, Args ...>;\n      value_type value;\n\
    \      bool fetched = false;\n      int N;\n      int c = 0;\n\n      value_type\
    \ operator*(){\n        if(not fetched){\n          std::tuple<Args ...> temp;\
    \ std::cin >> temp;\n          value = std::tuple_cat(std::make_tuple(c), temp);\n\
    \        }\n        return value;\n      }\n\n      void operator++(){\n     \
    \   ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter &) const\
    \ {\n        return c < N;\n      }\n\n      iter(int N): N(N){}\n    };\n\n \
    \   int N;\n\n  public:\n    InputTuplesWithIndex(int N): N(N){}\n\n    iter begin()\
    \ const {return iter(N);}\n    iter end() const {return iter(N);}\n  };\n\n  template\
    \ <typename ... Args>\n  auto input_tuples_with_index(int N){\n    return InputTuplesWithIndex<Args\
    \ ...>(N);\n  }\n}\n"
  code: "#pragma once\n#include <iostream>\n#include <vector>\n#include <tuple>\n\
    #include <utility>\n#include <initializer_list>\n#include \"Mylib/IO/input_tuple.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename ... Args>\n  class InputTuplesWithIndex\
    \ {\n    struct iter {\n      using value_type = std::tuple<int, Args ...>;\n\
    \      value_type value;\n      bool fetched = false;\n      int N;\n      int\
    \ c = 0;\n\n      value_type operator*(){\n        if(not fetched){\n        \
    \  std::tuple<Args ...> temp; std::cin >> temp;\n          value = std::tuple_cat(std::make_tuple(c),\
    \ temp);\n        }\n        return value;\n      }\n\n      void operator++(){\n\
    \        ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter\
    \ &) const {\n        return c < N;\n      }\n\n      iter(int N): N(N){}\n  \
    \  };\n\n    int N;\n\n  public:\n    InputTuplesWithIndex(int N): N(N){}\n\n\
    \    iter begin() const {return iter(N);}\n    iter end() const {return iter(N);}\n\
    \  };\n\n  template <typename ... Args>\n  auto input_tuples_with_index(int N){\n\
    \    return InputTuplesWithIndex<Args ...>(N);\n  }\n}\n"
  dependsOn:
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: false
  path: Mylib/IO/input_tuples_with_index.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/875/main.test.cpp
  - test/aoj/1508/main.splay_tree.test.cpp
  - test/aoj/1508/main.treap.test.cpp
  - test/aoj/GRL_5_C/main.doubling.test.cpp
  - test/aoj/GRL_5_C/main.hld.test.cpp
  - test/aoj/2136/main.test.cpp
  - test/aoj/DSL_2_C/main.test.cpp
  - test/yosupo-judge/point_set_range_composite/main.test.cpp
  - test/yosupo-judge/persistent_unionfind/main.test.cpp
  - test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp
documentation_of: Mylib/IO/input_tuples_with_index.cpp
layout: document
title: Input tuples with index
---

## Operations

## Requirements

## Notes

## Problems

## References
