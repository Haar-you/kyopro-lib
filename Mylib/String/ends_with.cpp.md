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
  bundledCode: "#line 2 \"Mylib/String/ends_with.cpp\"\n#include <cstddef>\n\nnamespace\
    \ haar_lib {\n  template <typename Container, typename T = typename Container::value_type>\n\
    \  bool ends_with(const Container &str, const Container &suffix) {\n    if (str.size()\
    \ < suffix.size()) return false;\n    int n = str.size(), m = suffix.size();\n\
    \    for (size_t i = 0; i < suffix.size(); ++i) {\n      if (str[n - 1 - i] !=\
    \ suffix[m - 1 - i]) return false;\n    }\n    return true;\n  }\n}  // namespace\
    \ haar_lib\n"
  code: "#pragma once\n#include <cstddef>\n\nnamespace haar_lib {\n  template <typename\
    \ Container, typename T = typename Container::value_type>\n  bool ends_with(const\
    \ Container &str, const Container &suffix) {\n    if (str.size() < suffix.size())\
    \ return false;\n    int n = str.size(), m = suffix.size();\n    for (size_t i\
    \ = 0; i < suffix.size(); ++i) {\n      if (str[n - 1 - i] != suffix[m - 1 - i])\
    \ return false;\n    }\n    return true;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/ends_with.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/String/ends_with.cpp
layout: document
title: ends_with
---

## Operations

## Requirements

## Notes

## Problems

## References
