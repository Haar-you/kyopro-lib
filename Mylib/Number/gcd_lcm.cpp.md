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
  bundledCode: "#line 2 \"Mylib/Number/gcd_lcm.cpp\"\n#include <cstdint>\n#include\
    \ <utility>\n\nnamespace haar_lib {\n  int64_t gcd(int64_t a, int64_t b) {\n \
    \   if (a < b) std::swap(a, b);\n    if (b == 0) return a;\n\n    return gcd(b,\
    \ a % b);\n  }\n\n  int64_t lcm(int64_t a, int64_t b) {\n    return a / gcd(a,\
    \ b) * b;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cstdint>\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  int64_t gcd(int64_t a, int64_t b) {\n    if (a < b) std::swap(a, b);\n\
    \    if (b == 0) return a;\n\n    return gcd(b, a % b);\n  }\n\n  int64_t lcm(int64_t\
    \ a, int64_t b) {\n    return a / gcd(a, b) * b;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/gcd_lcm.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Number/gcd_lcm.cpp
layout: document
title: Greatest common divisor / Least common multiple
---

## Operations

## Requirements

## Notes

## Problems

## References
