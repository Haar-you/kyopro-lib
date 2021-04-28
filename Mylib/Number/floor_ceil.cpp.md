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
  bundledCode: "#line 2 \"Mylib/Number/floor_ceil.cpp\"\n#include <cmath>\n#include\
    \ <cstdint>\n\nnamespace haar_lib {\n  int64_t ceil(int64_t a, int64_t b) {\n\
    \    if ((a <= 0 and b < 0) or (a >= 0 and b > 0)) return (std::abs(a) + std::abs(b)\
    \ - 1) / std::abs(b);\n    return -(std::abs(a) / std::abs(b));\n  }\n\n  int64_t\
    \ floor(int64_t a, int64_t b) {\n    if ((a <= 0 and b < 0) or (a >= 0 and b >\
    \ 0)) return a / b;\n    return -(std::abs(a) + std::abs(b) - 1) / std::abs(b);\n\
    \  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cmath>\n#include <cstdint>\n\nnamespace haar_lib\
    \ {\n  int64_t ceil(int64_t a, int64_t b) {\n    if ((a <= 0 and b < 0) or (a\
    \ >= 0 and b > 0)) return (std::abs(a) + std::abs(b) - 1) / std::abs(b);\n   \
    \ return -(std::abs(a) / std::abs(b));\n  }\n\n  int64_t floor(int64_t a, int64_t\
    \ b) {\n    if ((a <= 0 and b < 0) or (a >= 0 and b > 0)) return a / b;\n    return\
    \ -(std::abs(a) + std::abs(b) - 1) / std::abs(b);\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/floor_ceil.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Number/floor_ceil.cpp
layout: document
title: Floor function / Ceiling function
---

## Operations

## Requirements

## Notes

## Problems

## References
