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
  bundledCode: "#line 2 \"Mylib/Misc/zip.cpp\"\n#include <algorithm>\n#include <tuple>\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename... Args>\n  auto\
    \ zip(std::vector<Args>... a) {\n    const int N = std::min({a.size()...});\n\
    \    std::vector<std::tuple<Args...>> ret(N);\n\n    for (int i = 0; i < N; ++i)\
    \ {\n      ret[i] = std::make_tuple(a[i]...);\n    }\n\n    return ret;\n  }\n\
    }  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <tuple>\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename... Args>\n  auto zip(std::vector<Args>...\
    \ a) {\n    const int N = std::min({a.size()...});\n    std::vector<std::tuple<Args...>>\
    \ ret(N);\n\n    for (int i = 0; i < N; ++i) {\n      ret[i] = std::make_tuple(a[i]...);\n\
    \    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Misc/zip.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Misc/zip.cpp
layout: document
title: Zip function
---

## Operations

## Requirements

## Notes

## Problems

## References
