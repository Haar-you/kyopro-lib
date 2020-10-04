---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/kth_root_integer/main.test.cpp
    title: test/yosupo-judge/kth_root_integer/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/kth_root_integer.cpp\"\n#include <cassert>\n\
    #include <cstdint>\n\nnamespace haar_lib {\n  uint64_t kth_root(uint64_t a, int\
    \ k){\n    assert(k >= 1);\n    if(k == 1) return a;\n    if(a == 1) return 1;\n\
    \n    uint64_t lb = 0, ub = a;\n\n    auto check =\n      [](uint64_t a, int k,\
    \ uint64_t n){\n        uint64_t r = 1;\n\n        while(k > 0){\n          if(k\
    \ & 1){\n            if(__builtin_umulll_overflow(r, a, (unsigned long long int*)&r))\
    \ return false;\n          }\n          if(__builtin_umulll_overflow(a, a, (unsigned\
    \ long long int*)&a) and k > 1) return false;\n          k >>= 1;\n        }\n\
    \n        return r <= n;\n      };\n\n    while(ub - lb > 1){\n      uint64_t\
    \ mid = lb + (ub - lb) / 2;\n\n      if(check(mid, k, a)){\n        lb = mid;\n\
    \      }else{\n        ub = mid;\n      }\n    }\n\n    return lb;\n  }\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n\nnamespace haar_lib\
    \ {\n  uint64_t kth_root(uint64_t a, int k){\n    assert(k >= 1);\n    if(k ==\
    \ 1) return a;\n    if(a == 1) return 1;\n\n    uint64_t lb = 0, ub = a;\n\n \
    \   auto check =\n      [](uint64_t a, int k, uint64_t n){\n        uint64_t r\
    \ = 1;\n\n        while(k > 0){\n          if(k & 1){\n            if(__builtin_umulll_overflow(r,\
    \ a, (unsigned long long int*)&r)) return false;\n          }\n          if(__builtin_umulll_overflow(a,\
    \ a, (unsigned long long int*)&a) and k > 1) return false;\n          k >>= 1;\n\
    \        }\n\n        return r <= n;\n      };\n\n    while(ub - lb > 1){\n  \
    \    uint64_t mid = lb + (ub - lb) / 2;\n\n      if(check(mid, k, a)){\n     \
    \   lb = mid;\n      }else{\n        ub = mid;\n      }\n    }\n\n    return lb;\n\
    \  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/kth_root_integer.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/kth_root_integer/main.test.cpp
documentation_of: Mylib/Number/kth_root_integer.cpp
layout: document
title: Kth root integer
---

## Operations

## Requirements

## Notes

## Problems

## References
