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
  bundledCode: "#line 2 \"Mylib/Misc/xor_shift.cpp\"\n#include <cstdint>\n\nnamespace\
    \ haar_lib {\n  struct xor_shift {\n    static uint64_t rand(){\n      static\
    \ uint64_t x = 1234567889, y = 362436069, z = 521288629, w = 88675123;\n\n   \
    \   uint64_t t = (x ^ (x << 11));\n      x = y;\n      y = z;\n      z = w;\n\
    \      w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n      return w;\n    }\n\n    static\
    \ uint64_t rand(uint64_t s, uint64_t t){ // [s, t)\n      return s + rand() %\
    \ (t - s);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <cstdint>\n\nnamespace haar_lib {\n  struct xor_shift\
    \ {\n    static uint64_t rand(){\n      static uint64_t x = 1234567889, y = 362436069,\
    \ z = 521288629, w = 88675123;\n\n      uint64_t t = (x ^ (x << 11));\n      x\
    \ = y;\n      y = z;\n      z = w;\n      w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n\
    \      return w;\n    }\n\n    static uint64_t rand(uint64_t s, uint64_t t){ //\
    \ [s, t)\n      return s + rand() % (t - s);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Misc/xor_shift.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Misc/xor_shift.cpp
layout: document
title: Xorshift
---

## Operations

## Requirements

## Notes

## Problems

## References
