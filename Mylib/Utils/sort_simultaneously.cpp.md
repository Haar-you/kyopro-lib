---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2426/main.test.cpp
    title: test/aoj/2426/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
    title: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235/main.test.cpp
    title: test/yukicoder/235/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Utils/sort_simultaneously.cpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <initializer_list>\n#include <numeric>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace haar_lib {\n  namespace sort_simultaneously_impl\
    \ {\n    template <typename T>\n    void helper(int N, const std::vector<int>\
    \ &ord, std::vector<T> &a) {\n      std::vector<T> temp(N);\n      for (int i\
    \ = 0; i < N; ++i) temp[i] = a[ord[i]];\n      std::swap(temp, a);\n    }\n  }\
    \  // namespace sort_simultaneously_impl\n\n  template <typename Compare, typename...\
    \ Args>\n  void sort_simultaneously(const Compare &compare, std::vector<Args>\
    \ &... args) {\n    const int N = std::max({args.size()...});\n    assert((int)\
    \ std::min({args.size()...}) == N);\n    std::vector<int> ord(N);\n    std::iota(ord.begin(),\
    \ ord.end(), 0);\n    std::sort(ord.begin(), ord.end(), compare);\n\n    (void)\
    \ std::initializer_list<int>{\n        (void(sort_simultaneously_impl::helper(N,\
    \ ord, args)), 0)...};\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <initializer_list>\n\
    #include <numeric>\n#include <utility>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  namespace sort_simultaneously_impl {\n    template <typename T>\n    void\
    \ helper(int N, const std::vector<int> &ord, std::vector<T> &a) {\n      std::vector<T>\
    \ temp(N);\n      for (int i = 0; i < N; ++i) temp[i] = a[ord[i]];\n      std::swap(temp,\
    \ a);\n    }\n  }  // namespace sort_simultaneously_impl\n\n  template <typename\
    \ Compare, typename... Args>\n  void sort_simultaneously(const Compare &compare,\
    \ std::vector<Args> &... args) {\n    const int N = std::max({args.size()...});\n\
    \    assert((int) std::min({args.size()...}) == N);\n    std::vector<int> ord(N);\n\
    \    std::iota(ord.begin(), ord.end(), 0);\n    std::sort(ord.begin(), ord.end(),\
    \ compare);\n\n    (void) std::initializer_list<int>{\n        (void(sort_simultaneously_impl::helper(N,\
    \ ord, args)), 0)...};\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Utils/sort_simultaneously.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
  - test/aoj/2426/main.test.cpp
  - test/yukicoder/235/main.test.cpp
documentation_of: Mylib/Utils/sort_simultaneously.cpp
layout: document
title: Sort simultaneously
---

## Operations

## Requirements

## Notes

## Problems

## References
