---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/bernoulli_number/main.test.cpp
    title: test/yosupo-judge/bernoulli_number/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/bernoulli_number_fps.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename Fps, const auto &ft>\n  Fps bernoulli_number_fps(int\
    \ N) {\n    Fps x(N + 1);\n\n    for (int i = 0; i <= N; ++i) x[i] = ft.inv_factorial(i\
    \ + 1);\n    x = x.inv();\n\n    for (int i = 0; i <= N; ++i) x[i] *= ft.factorial(i);\n\
    \n    return x;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename Fps, const auto\
    \ &ft>\n  Fps bernoulli_number_fps(int N) {\n    Fps x(N + 1);\n\n    for (int\
    \ i = 0; i <= N; ++i) x[i] = ft.inv_factorial(i + 1);\n    x = x.inv();\n\n  \
    \  for (int i = 0; i <= N; ++i) x[i] *= ft.factorial(i);\n\n    return x;\n  }\n\
    }  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Combinatorics/bernoulli_number_fps.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
