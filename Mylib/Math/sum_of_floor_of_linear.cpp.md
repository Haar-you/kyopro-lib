---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/sum_of_floor_of_linear/main.test.cpp
    title: test/yosupo-judge/sum_of_floor_of_linear/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Math/sum_of_floor_of_linear.cpp\"\n#include <cstdint>\n\
    \nnamespace haar_lib {\n  int64_t sum_of_floor_of_linear(int64_t N, int64_t M,\
    \ int64_t A, int64_t B){\n    int64_t ret = 0;\n\n    if(B >= M){\n      ret +=\
    \ N * (B / M);\n      B %= M;\n    }\n\n    if(A >= M){\n      ret += N * (N -\
    \ 1) * (A / M) / 2;\n      A %= M;\n    }\n\n    int64_t y_max = (A * N + B) /\
    \ M;\n    int64_t x_max = y_max * M - B;\n    if(y_max == 0) return ret;\n\n \
    \   ret += (N - (x_max + A - 1) / A) * y_max;\n    ret += sum_of_floor_of_linear(y_max,\
    \ A, M, (A - x_max % A) % A);\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n\nnamespace haar_lib {\n  int64_t sum_of_floor_of_linear(int64_t\
    \ N, int64_t M, int64_t A, int64_t B){\n    int64_t ret = 0;\n\n    if(B >= M){\n\
    \      ret += N * (B / M);\n      B %= M;\n    }\n\n    if(A >= M){\n      ret\
    \ += N * (N - 1) * (A / M) / 2;\n      A %= M;\n    }\n\n    int64_t y_max = (A\
    \ * N + B) / M;\n    int64_t x_max = y_max * M - B;\n    if(y_max == 0) return\
    \ ret;\n\n    ret += (N - (x_max + A - 1) / A) * y_max;\n    ret += sum_of_floor_of_linear(y_max,\
    \ A, M, (A - x_max % A) % A);\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Math/sum_of_floor_of_linear.cpp
  requiredBy: []
  timestamp: '2020-09-27 07:43:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/sum_of_floor_of_linear/main.test.cpp
documentation_of: Mylib/Math/sum_of_floor_of_linear.cpp
layout: document
title: Sum of floor of linear
---

## Operations

## Requirements

## Notes

## Problems

## References
