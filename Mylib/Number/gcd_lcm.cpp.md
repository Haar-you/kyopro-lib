---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Number/gcd_lcm.cpp\"\n#include <utility>\n#include\
    \ <cstdint>\n\nnamespace haar_lib {\n  int64_t gcd(int64_t a, int64_t b){\n  \
    \  if(a < b) std::swap(a, b);\n    if(b == 0) return a;\n\n    return gcd(b, a\
    \ % b);\n  }\n\n  int64_t lcm(int64_t a, int64_t b){\n    return a / gcd(a, b)\
    \ * b;\n  }\n}\n"
  code: "#pragma once\n#include <utility>\n#include <cstdint>\n\nnamespace haar_lib\
    \ {\n  int64_t gcd(int64_t a, int64_t b){\n    if(a < b) std::swap(a, b);\n  \
    \  if(b == 0) return a;\n\n    return gcd(b, a % b);\n  }\n\n  int64_t lcm(int64_t\
    \ a, int64_t b){\n    return a / gcd(a, b) * b;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/gcd_lcm.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
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
