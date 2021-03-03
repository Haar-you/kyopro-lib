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
  bundledCode: "#line 2 \"Mylib/Wrapper/rotate.cpp\"\n#include <algorithm>\n\nnamespace\
    \ haar_lib {\n  template <typename Iter>\n  void rotate_right(Iter first, Iter\
    \ last, int d){\n    std::rotate(first, last - d, last);\n  }\n\n  template <typename\
    \ Iter>\n  void rotate_left(Iter first, Iter last, int d){\n    std::rotate(first,\
    \ first + d, last);\n  }\n}\n"
  code: "#pragma once\n#include <algorithm>\n\nnamespace haar_lib {\n  template <typename\
    \ Iter>\n  void rotate_right(Iter first, Iter last, int d){\n    std::rotate(first,\
    \ last - d, last);\n  }\n\n  template <typename Iter>\n  void rotate_left(Iter\
    \ first, Iter last, int d){\n    std::rotate(first, first + d, last);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Wrapper/rotate.cpp
  requiredBy: []
  timestamp: '2021-03-04 02:55:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Wrapper/rotate.cpp
layout: document
title: null
---

## Operations

## Requirements

## Notes

## Problems

## References
