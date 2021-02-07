---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/306/main.ternary.test.cpp
    title: test/yukicoder/306/main.ternary.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/ternary_search_downwards.cpp\"\n#include\
    \ <functional>\n\nnamespace haar_lib {\n  template <typename T = double, typename\
    \ Func = std::function<T(T)>>\n  T ternary_search_downwards(T lb, T ub, const\
    \ Func &f, int LOOP_COUNT = 100){\n    T t1 = 0, t2 = 0;\n\n    while(LOOP_COUNT--){\n\
    \      t1 = lb + (ub - lb) / 3;\n      t2 = lb + (ub - lb) / 3 * 2;\n\n      if(f(t1)\
    \ < f(t2)){\n        ub = t2;\n      }else{\n        lb = t1;\n      }\n    }\n\
    \n    return lb;\n  }\n}\n"
  code: "#pragma once\n#include <functional>\n\nnamespace haar_lib {\n  template <typename\
    \ T = double, typename Func = std::function<T(T)>>\n  T ternary_search_downwards(T\
    \ lb, T ub, const Func &f, int LOOP_COUNT = 100){\n    T t1 = 0, t2 = 0;\n\n \
    \   while(LOOP_COUNT--){\n      t1 = lb + (ub - lb) / 3;\n      t2 = lb + (ub\
    \ - lb) / 3 * 2;\n\n      if(f(t1) < f(t2)){\n        ub = t2;\n      }else{\n\
    \        lb = t1;\n      }\n    }\n\n    return lb;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/ternary_search_downwards.cpp
  requiredBy: []
  timestamp: '2020-12-09 10:43:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/306/main.ternary.test.cpp
documentation_of: Mylib/Algorithm/ternary_search_downwards.cpp
layout: document
title: Ternary search (Convex downwards)
---

## Operations

## Requirements

## Notes

## Problems

## References
