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
  bundledCode: "#line 2 \"Mylib/DynamicProgramming/max_partial_sum.cpp\"\n#include\
    \ <vector>\n#include <algorithm>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  T max_partial_sum(const std::vector<T> &v){\n    T t = v[0], ret = t;\n\
    \    for(int i = 1; i < (int)v.size(); ++i){\n      t = std::max(t + v[i], v[i]);\n\
    \      ret = std::max(ret, t);\n    }\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  T max_partial_sum(const std::vector<T> &v){\n\
    \    T t = v[0], ret = t;\n    for(int i = 1; i < (int)v.size(); ++i){\n     \
    \ t = std::max(t + v[i], v[i]);\n      ret = std::max(ret, t);\n    }\n    return\
    \ ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DynamicProgramming/max_partial_sum.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/DynamicProgramming/max_partial_sum.cpp
layout: document
title: Maximum subarray problem
---

## Operations

## Requirements

## Notes

## Problems

## References
