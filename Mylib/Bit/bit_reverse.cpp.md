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
  bundledCode: "#line 2 \"Mylib/Bit/bit_reverse.cpp\"\n#include <cstdint>\n\nnamespace\
    \ haar_lib {\n  constexpr uint32_t bit_reverse(uint32_t a){\n    a = ((a & 0x55555555)\
    \ << 1) | ((a & 0xaaaaaaaa) >> 1);\n    a = ((a & 0x33333333) << 2) | ((a & 0xcccccccc)\
    \ >> 2);\n    a = ((a & 0x0f0f0f0f) << 4) | ((a & 0xf0f0f0f0) >> 4);\n    a =\
    \ ((a & 0x00ff00ff) << 8) | ((a & 0xff00ff00) >> 8);\n    a = (a << 16) | (a >>\
    \ 16);\n    return a;\n  }\n\n  constexpr uint64_t bit_reverse_ll(uint64_t a){\n\
    \    a = ((a & 0x5555555555555555) << 1) | ((a & 0xaaaaaaaaaaaaaaaa) >> 1);\n\
    \    a = ((a & 0x3333333333333333) << 2) | ((a & 0xcccccccccccccccc) >> 2);\n\
    \    a = ((a & 0x0f0f0f0f0f0f0f0f) << 4) | ((a & 0xf0f0f0f0f0f0f0f0) >> 4);\n\
    \    a = ((a & 0x00ff00ff00ff00ff) << 8) | ((a & 0xff00ff00ff00ff00) >> 8);\n\
    \    a = ((a & 0x0000ffff0000ffff) << 16) | ((a & 0xffff0000ffff0000) >> 16);\n\
    \    a = (a << 32) | (a >> 32);\n    return a;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n\nnamespace haar_lib {\n  constexpr uint32_t\
    \ bit_reverse(uint32_t a){\n    a = ((a & 0x55555555) << 1) | ((a & 0xaaaaaaaa)\
    \ >> 1);\n    a = ((a & 0x33333333) << 2) | ((a & 0xcccccccc) >> 2);\n    a =\
    \ ((a & 0x0f0f0f0f) << 4) | ((a & 0xf0f0f0f0) >> 4);\n    a = ((a & 0x00ff00ff)\
    \ << 8) | ((a & 0xff00ff00) >> 8);\n    a = (a << 16) | (a >> 16);\n    return\
    \ a;\n  }\n\n  constexpr uint64_t bit_reverse_ll(uint64_t a){\n    a = ((a & 0x5555555555555555)\
    \ << 1) | ((a & 0xaaaaaaaaaaaaaaaa) >> 1);\n    a = ((a & 0x3333333333333333)\
    \ << 2) | ((a & 0xcccccccccccccccc) >> 2);\n    a = ((a & 0x0f0f0f0f0f0f0f0f)\
    \ << 4) | ((a & 0xf0f0f0f0f0f0f0f0) >> 4);\n    a = ((a & 0x00ff00ff00ff00ff)\
    \ << 8) | ((a & 0xff00ff00ff00ff00) >> 8);\n    a = ((a & 0x0000ffff0000ffff)\
    \ << 16) | ((a & 0xffff0000ffff0000) >> 16);\n    a = (a << 32) | (a >> 32);\n\
    \    return a;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Bit/bit_reverse.cpp
  requiredBy: []
  timestamp: '2021-03-13 04:04:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Bit/bit_reverse.cpp
layout: document
title: Bit reverse
---

## Operations

## Requirements

## Notes

## Problems

## References
