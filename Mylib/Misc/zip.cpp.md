---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Misc/zip.cpp\"\n#include <vector>\n#include <tuple>\n\
    #include <algorithm>\n\nnamespace haar_lib {\n  template <typename ... Args>\n\
    \  auto zip(std::vector<Args> ... a){\n    const int N = std::min({a.size() ...});\n\
    \    std::vector<std::tuple<Args ...>> ret(N);\n\n    for(int i = 0; i < N; ++i){\n\
    \      ret[i] = std::make_tuple(a[i] ...);\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <tuple>\n#include <algorithm>\n\
    \nnamespace haar_lib {\n  template <typename ... Args>\n  auto zip(std::vector<Args>\
    \ ... a){\n    const int N = std::min({a.size() ...});\n    std::vector<std::tuple<Args\
    \ ...>> ret(N);\n\n    for(int i = 0; i < N; ++i){\n      ret[i] = std::make_tuple(a[i]\
    \ ...);\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Misc/zip.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
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
