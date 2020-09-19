---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1327/main.test.cpp
    title: test/aoj/1327/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/194/main.test.cpp
    title: test/yukicoder/194/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/LinearAlgebra/Square/power.cpp\"\n#include <cstdint>\n\
    \nnamespace haar_lib {\n  template <typename M>\n  M power(M a, uint64_t p){\n\
    \    if(p == 0) return M::make_unit();\n    if(p == 1) return a;\n\n    M temp\
    \ = power(a, p >> 1);\n    auto ret = temp * temp;\n\n    if(p & 1) ret *= a;\n\
    \n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n\nnamespace haar_lib {\n  template <typename\
    \ M>\n  M power(M a, uint64_t p){\n    if(p == 0) return M::make_unit();\n   \
    \ if(p == 1) return a;\n\n    M temp = power(a, p >> 1);\n    auto ret = temp\
    \ * temp;\n\n    if(p & 1) ret *= a;\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/LinearAlgebra/Square/power.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/1327/main.test.cpp
  - test/yukicoder/194/main.test.cpp
documentation_of: Mylib/LinearAlgebra/Square/power.cpp
layout: document
title: Power of a matrix
---

## Operations

## Requirements

## Notes

## Problems

## References
