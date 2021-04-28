---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/NTL_1_C/main.test.cpp
    title: test/aoj/NTL_1_C/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/binary_gcd.cpp\"\n#include <cmath>\n#include\
    \ <utility>\n\nnamespace haar_lib {\n  int64_t binary_gcd(int64_t a, int64_t b)\
    \ {\n    int64_t g = 1;\n\n    while (1) {\n      if (a > b) std::swap(a, b);\n\
    \n      if (a == 0) {\n        break;\n      } else {\n        if ((a & 1) ==\
    \ 0 and (b & 1) == 0) {\n          a >>= 1;\n          b >>= 1;\n          g <<=\
    \ 1;\n        } else if ((a & 1) == 0) {\n          a >>= 1;\n        } else if\
    \ ((b & 1) == 0) {\n          b >>= 1;\n        } else {\n          int64_t t\
    \ = std::abs(a - b) >> 1;\n          b         = t;\n        }\n      }\n    }\n\
    \n    return g * b;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cmath>\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  int64_t binary_gcd(int64_t a, int64_t b) {\n    int64_t g = 1;\n\n    while\
    \ (1) {\n      if (a > b) std::swap(a, b);\n\n      if (a == 0) {\n        break;\n\
    \      } else {\n        if ((a & 1) == 0 and (b & 1) == 0) {\n          a >>=\
    \ 1;\n          b >>= 1;\n          g <<= 1;\n        } else if ((a & 1) == 0)\
    \ {\n          a >>= 1;\n        } else if ((b & 1) == 0) {\n          b >>= 1;\n\
    \        } else {\n          int64_t t = std::abs(a - b) >> 1;\n          b  \
    \       = t;\n        }\n      }\n    }\n\n    return g * b;\n  }\n}  // namespace\
    \ haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/binary_gcd.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/NTL_1_C/main.test.cpp
documentation_of: Mylib/Number/binary_gcd.cpp
layout: document
title: Binary GCD
---

## Operations

## Requirements

## Notes

## Problems

## References
