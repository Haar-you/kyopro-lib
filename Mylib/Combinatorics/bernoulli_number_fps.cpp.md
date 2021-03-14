---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/bernoulli_number/main.test.cpp
    title: test/yosupo-judge/bernoulli_number/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/bernoulli_number_fps.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename Fps, const auto &ft>\n  Fps bernoulli_number_fps(int\
    \ N){\n    Fps x(N + 1);\n\n    for(int i = 0; i <= N; ++i) x[i] = ft.inv_factorial(i\
    \ + 1);\n    x = x.inv();\n\n    for(int i = 0; i <= N; ++i) x[i] *= ft.factorial(i);\n\
    \n    return x;\n  }\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename Fps, const auto\
    \ &ft>\n  Fps bernoulli_number_fps(int N){\n    Fps x(N + 1);\n\n    for(int i\
    \ = 0; i <= N; ++i) x[i] = ft.inv_factorial(i + 1);\n    x = x.inv();\n\n    for(int\
    \ i = 0; i <= N; ++i) x[i] *= ft.factorial(i);\n\n    return x;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Combinatorics/bernoulli_number_fps.cpp
  requiredBy: []
  timestamp: '2021-03-13 04:56:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/bernoulli_number/main.test.cpp
documentation_of: Mylib/Combinatorics/bernoulli_number_fps.cpp
layout: document
title: Bernoulli number (FPS)
---

## Operations
- `bernoulli_number_fps<Fps, ft>(int N) -> Fps`

## Requirements

## Notes

## Problems

## References
