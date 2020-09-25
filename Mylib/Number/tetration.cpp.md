---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Number/euler_totient_function.cpp
    title: Euler's totient function
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    \ 1) ret -= ret / n;\n\n    return ret;\n  }\n}\n#line 3 \"Mylib/Number/tetration.cpp\"\
    \n\nnamespace haar_lib {\n  namespace tetration_impl {\n    int rec(int64_t a,\
    \ int64_t b, int64_t m){\n      if(b == 1) return a % m;\n      if(b == 0) return\
    \ 1 % m;\n      if(b == 2){\n        bool c = a >= m;\n        int64_t ret = 1;\n\
    \        int64_t p = a;\n        a %= m;\n\n        while(p > 0){\n          if(p\
    \ & 1) if((ret *= a) >= m) ret %= m, c = true;\n          if((a *= a) >= m) a\
    \ %= m, c = true;\n          p >>= 1;\n        }\n\n        if(c) ret += m;\n\
    \        return ret;\n      }\n      if(a == 0) return b % 2 == 1 ? 0 : 1;\n \
    \     if(m == 1) return 1;\n\n      int phi = totient(m);\n      int p = rec(a,\
    \ b - 1, phi);\n\n      bool c = p >= phi;\n      int64_t ret = 1;\n\n      while(p\
    \ > 0){\n        if(p & 1) if((ret *= a) >= m) ret %= m, c = true;\n        if((a\
    \ *= a) >= m) a %= m, c = true;\n        p >>= 1;\n      }\n\n      if(c) ret\
    \ += m;\n      return ret;\n    }\n  }\n\n  int tetration(int64_t a, int64_t b,\
    \ int64_t m){\n    return tetration_impl::rec(a, b, m) % m;\n  }\n}\n"
  code: "#pragma once\n#include \"Mylib/Number/euler_totient_function.cpp\"\n\nnamespace\
    \ haar_lib {\n  namespace tetration_impl {\n    int rec(int64_t a, int64_t b,\
    \ int64_t m){\n      if(b == 1) return a % m;\n      if(b == 0) return 1 % m;\n\
    \      if(b == 2){\n        bool c = a >= m;\n        int64_t ret = 1;\n     \
    \   int64_t p = a;\n        a %= m;\n\n        while(p > 0){\n          if(p &\
    \ 1) if((ret *= a) >= m) ret %= m, c = true;\n          if((a *= a) >= m) a %=\
    \ m, c = true;\n          p >>= 1;\n        }\n\n        if(c) ret += m;\n   \
    \     return ret;\n      }\n      if(a == 0) return b % 2 == 1 ? 0 : 1;\n    \
    \  if(m == 1) return 1;\n\n      int phi = totient(m);\n      int p = rec(a, b\
    \ - 1, phi);\n\n      bool c = p >= phi;\n      int64_t ret = 1;\n\n      while(p\
    \ > 0){\n        if(p & 1) if((ret *= a) >= m) ret %= m, c = true;\n        if((a\
    \ *= a) >= m) a %= m, c = true;\n        p >>= 1;\n      }\n\n      if(c) ret\
    \ += m;\n      return ret;\n    }\n  }\n\n  int tetration(int64_t a, int64_t b,\
    \ int64_t m){\n    return tetration_impl::rec(a, b, m) % m;\n  }\n}\n"
  dependsOn:
  - Mylib/Number/euler_totient_function.cpp
  isVerificationFile: false
  path: Mylib/Number/tetration.cpp
  requiredBy: []
  timestamp: '2020-09-26 05:28:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/tetration_mod/main.test.cpp
documentation_of: Mylib/Number/tetration.cpp
layout: document
title: Tetration
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://kopricky.github.io/code/Computation_Advanced/tetration.html](https://kopricky.github.io/code/Computation_Advanced/tetration.html)
