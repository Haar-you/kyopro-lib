---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Misc/unzip.cpp\"\n#include <initializer_list>\n#include\
    \ <tuple>\n#include <utility>\n#include <vector>\n\nnamespace haar_lib {\n  template\
    \ <typename T, typename U, size_t... I>\n  void unzip_helper(T &ret, U &a, std::index_sequence<I...>)\
    \ {\n    (void) std::initializer_list<int>{(void(std::get<I>(ret).push_back(std::get<I>(a))),\
    \ 0)...};\n  }\n\n  template <typename... Args>\n  auto unzip(std::vector<std::tuple<Args...>>\
    \ a) {\n    const int N = a.size();\n    std::tuple<std::vector<Args>...> ret;\n\
    \n    for (int i = 0; i < N; ++i) {\n      unzip_helper(ret, a[i], std::make_index_sequence<sizeof...(Args)>());\n\
    \    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <initializer_list>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename T, typename U,\
    \ size_t... I>\n  void unzip_helper(T &ret, U &a, std::index_sequence<I...>) {\n\
    \    (void) std::initializer_list<int>{(void(std::get<I>(ret).push_back(std::get<I>(a))),\
    \ 0)...};\n  }\n\n  template <typename... Args>\n  auto unzip(std::vector<std::tuple<Args...>>\
    \ a) {\n    const int N = a.size();\n    std::tuple<std::vector<Args>...> ret;\n\
    \n    for (int i = 0; i < N; ++i) {\n      unzip_helper(ret, a[i], std::make_index_sequence<sizeof...(Args)>());\n\
    \    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Misc/unzip.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Misc/unzip.cpp
layout: document
title: Unzip function
---

## Operations

## Requirements

## Notes

## Problems

## References
