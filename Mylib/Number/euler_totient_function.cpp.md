---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Number/tetration.cpp
    title: Tetration
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/NTL_1_D/main.totient.test.cpp
    title: test/aoj/NTL_1_D/main.totient.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/tetration_mod/main.test.cpp
    title: test/yosupo-judge/tetration_mod/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Number/euler_totient_function.cpp\"\n#include <cstdint>\n\
    \nnamespace haar_lib {\n  int64_t totient(int64_t n){\n    int64_t ret = n;\n\n\
    \    for(int64_t i = 2; i * i <= n; ++i){\n      if(n % i == 0){\n        ret\
    \ -= ret / i;\n        while(n % i == 0) n /= i;\n      }\n    }\n\n    if(n !=\
    \ 1) ret -= ret / n;\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n\nnamespace haar_lib {\n  int64_t totient(int64_t\
    \ n){\n    int64_t ret = n;\n\n    for(int64_t i = 2; i * i <= n; ++i){\n    \
    \  if(n % i == 0){\n        ret -= ret / i;\n        while(n % i == 0) n /= i;\n\
    \      }\n    }\n\n    if(n != 1) ret -= ret / n;\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/euler_totient_function.cpp
  requiredBy:
  - Mylib/Number/tetration.cpp
  timestamp: '2020-09-25 03:54:08+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/NTL_1_D/main.totient.test.cpp
  - test/yosupo-judge/tetration_mod/main.test.cpp
documentation_of: Mylib/Number/euler_totient_function.cpp
layout: document
title: Euler's totient function
---

## Operations

## Requirements

## Notes

## Problems

## References
