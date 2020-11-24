---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559/main.binomial_heap.test.cpp
    title: test/aoj/2559/main.binomial_heap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559/main.leftist_heap.test.cpp
    title: test/aoj/2559/main.leftist_heap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559/main.skew_heap.test.cpp
    title: test/aoj/2559/main.skew_heap.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Misc/merge_technique.cpp\"\n#include <set>\n#include\
    \ <utility>\n\nnamespace haar_lib {\n  template <typename T>\n  void merge_technique(std::set<T>\
    \ &res, std::set<T> &a, std::set<T> &b){\n    if(a.size() > b.size()){\n     \
    \ a.insert(b.begin(), b.end());\n      std::swap(res, a);\n    }else{\n      b.insert(a.begin(),\
    \ a.end());\n      std::swap(res, b);\n    }\n  }\n}\n"
  code: "#pragma once\n#include <set>\n#include <utility>\n\nnamespace haar_lib {\n\
    \  template <typename T>\n  void merge_technique(std::set<T> &res, std::set<T>\
    \ &a, std::set<T> &b){\n    if(a.size() > b.size()){\n      a.insert(b.begin(),\
    \ b.end());\n      std::swap(res, a);\n    }else{\n      b.insert(a.begin(), a.end());\n\
    \      std::swap(res, b);\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Misc/merge_technique.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2559/main.leftist_heap.test.cpp
  - test/aoj/2559/main.skew_heap.test.cpp
  - test/aoj/2559/main.binomial_heap.test.cpp
documentation_of: Mylib/Misc/merge_technique.cpp
layout: document
title: Merge technique
---

## Operations

## Requirements

## Notes

## Problems

## References
