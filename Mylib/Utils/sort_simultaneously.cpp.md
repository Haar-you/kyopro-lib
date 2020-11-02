---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2426/main.test.cpp
    title: test/aoj/2426/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
    title: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235/main.test.cpp
    title: test/yukicoder/235/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Utils/sort_simultaneously.cpp\"\n#include <vector>\n\
    #include <utility>\n#include <algorithm>\n#include <numeric>\n#include <initializer_list>\n\
    #include <cassert>\n\nnamespace haar_lib {\n  namespace sort_simultaneously_impl\
    \ {\n    template <typename T>\n    void sub(int N, const std::vector<int> &ord,\
    \ std::vector<T> &a){\n      std::vector<T> temp(N);\n      for(int i = 0; i <\
    \ N; ++i) temp[i] = a[ord[i]];\n      std::swap(temp, a);\n    }\n  }\n\n  template\
    \ <typename Compare, typename ... Args>\n  void sort_simultaneously(const Compare\
    \ &compare, std::vector<Args> &... args){\n    const int N = std::max({args.size()\
    \ ...});\n    assert((int)std::min({args.size() ...}) == N);\n    std::vector<int>\
    \ ord(N);\n    std::iota(ord.begin(), ord.end(), 0);\n    std::sort(ord.begin(),\
    \ ord.end(), compare);\n\n    (void)std::initializer_list<int>{\n      (void(sort_simultaneously_impl::sub(N,\
    \ ord, args)), 0) ...};\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include <numeric>\n#include <initializer_list>\n#include <cassert>\n\nnamespace\
    \ haar_lib {\n  namespace sort_simultaneously_impl {\n    template <typename T>\n\
    \    void sub(int N, const std::vector<int> &ord, std::vector<T> &a){\n      std::vector<T>\
    \ temp(N);\n      for(int i = 0; i < N; ++i) temp[i] = a[ord[i]];\n      std::swap(temp,\
    \ a);\n    }\n  }\n\n  template <typename Compare, typename ... Args>\n  void\
    \ sort_simultaneously(const Compare &compare, std::vector<Args> &... args){\n\
    \    const int N = std::max({args.size() ...});\n    assert((int)std::min({args.size()\
    \ ...}) == N);\n    std::vector<int> ord(N);\n    std::iota(ord.begin(), ord.end(),\
    \ 0);\n    std::sort(ord.begin(), ord.end(), compare);\n\n    (void)std::initializer_list<int>{\n\
    \      (void(sort_simultaneously_impl::sub(N, ord, args)), 0) ...};\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Utils/sort_simultaneously.cpp
  requiredBy: []
  timestamp: '2020-10-10 11:12:55+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/235/main.test.cpp
  - test/aoj/2426/main.test.cpp
  - test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
documentation_of: Mylib/Utils/sort_simultaneously.cpp
layout: document
title: Sort simultaneously
---

## Operations

## Requirements

## Notes

## Problems

## References
