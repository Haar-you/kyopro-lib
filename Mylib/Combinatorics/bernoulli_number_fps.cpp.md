---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/bernoulli_number/main.test.cpp
    title: test/yosupo-judge/bernoulli_number/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/bernoulli_number_fps.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename Fps, typename Ft>\n  auto bernoulli_number_fps(int\
    \ N, const Ft &ft){\n    Fps x(N + 1);\n\n    for(int i = 0; i <= N; ++i) x[i]\
    \ = ft.inv_factorial(i + 1);\n    x = x.inv();\n\n    for(int i = 0; i <= N; ++i)\
    \ x[i] *= ft.factorial(i);\n\n    return x;\n  }\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename Fps, typename\
    \ Ft>\n  auto bernoulli_number_fps(int N, const Ft &ft){\n    Fps x(N + 1);\n\n\
    \    for(int i = 0; i <= N; ++i) x[i] = ft.inv_factorial(i + 1);\n    x = x.inv();\n\
    \n    for(int i = 0; i <= N; ++i) x[i] *= ft.factorial(i);\n\n    return x;\n\
    \  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Combinatorics/bernoulli_number_fps.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/bernoulli_number/main.test.cpp
documentation_of: Mylib/Combinatorics/bernoulli_number_fps.cpp
layout: document
title: Bernoulli number (FPS)
---

## Operations

## Requirements

## Notes

## Problems

## References
