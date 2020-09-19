---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/306/main.golden.test.cpp
    title: test/yukicoder/306/main.golden.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/Search/golden_section_search_downwards.cpp\"\
    \n#include <functional>\n#include <cmath>\n\nnamespace haar_lib {\n  template\
    \ <typename T = double, typename Func = std::function<T(T)>>\n  T golden_section_search_downwards(T\
    \ lb, T ub, const Func &f, int LOOP_COUNT = 100){\n    static const T phi = (1.0\
    \ + std::sqrt(5)) / 2;\n\n    T t1 = 0, t2 = 0;\n\n    while(LOOP_COUNT--){\n\
    \      t1 = (lb * phi + ub) / (phi + 1.0);\n      t2 = (lb + ub * phi) / (phi\
    \ + 1.0);\n\n      if(f(t1) < f(t2)){\n        ub = t2;\n      }else{\n      \
    \  lb = t1;\n      }\n    }\n\n    return lb;\n  }\n}\n"
  code: "#pragma once\n#include <functional>\n#include <cmath>\n\nnamespace haar_lib\
    \ {\n  template <typename T = double, typename Func = std::function<T(T)>>\n \
    \ T golden_section_search_downwards(T lb, T ub, const Func &f, int LOOP_COUNT\
    \ = 100){\n    static const T phi = (1.0 + std::sqrt(5)) / 2;\n\n    T t1 = 0,\
    \ t2 = 0;\n\n    while(LOOP_COUNT--){\n      t1 = (lb * phi + ub) / (phi + 1.0);\n\
    \      t2 = (lb + ub * phi) / (phi + 1.0);\n\n      if(f(t1) < f(t2)){\n     \
    \   ub = t2;\n      }else{\n        lb = t1;\n      }\n    }\n\n    return lb;\n\
    \  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/Search/golden_section_search_downwards.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/306/main.golden.test.cpp
documentation_of: Mylib/Algorithm/Search/golden_section_search_downwards.cpp
layout: document
title: Golden section search (Convex downwards)
---

## Operations

## Requirements

## Notes

## Problems

## References
