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
  bundledCode: "#line 2 \"Mylib/String/starts_with.cpp\"\n#include <cstddef>\n\nnamespace\
    \ haar_lib {\n  template <typename Container, typename T = typename Container::value_type>\n\
    \  bool starts_with(const Container &str, const Container &prefix) {\n    if (str.size()\
    \ < prefix.size()) return false;\n    for (size_t i = 0; i < prefix.size(); ++i)\
    \ {\n      if (str[i] != prefix[i]) return false;\n    }\n    return true;\n \
    \ }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cstddef>\n\nnamespace haar_lib {\n  template <typename\
    \ Container, typename T = typename Container::value_type>\n  bool starts_with(const\
    \ Container &str, const Container &prefix) {\n    if (str.size() < prefix.size())\
    \ return false;\n    for (size_t i = 0; i < prefix.size(); ++i) {\n      if (str[i]\
    \ != prefix[i]) return false;\n    }\n    return true;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/starts_with.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/String/starts_with.cpp
layout: document
title: starts_with
---

## Operations

## Requirements

## Notes

## Problems

## References
