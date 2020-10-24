---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Combinatorics/stirling_number_first_fft.cpp
    title: Stirling numbers of the first kind (FFT)
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/polynomial_taylor_shift/main.test.cpp
    title: test/yosupo-judge/polynomial_taylor_shift/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp
    title: test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Math/polynomial_taylor_shift.cpp\"\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Conv>\n  auto polynomial_taylor_shift(std::vector<T>\
    \ a, T c, const Conv &convolve){\n    const int N = a.size();\n    T f = 1;\n\
    \    std::vector<T> A(2 * N - 1);\n    for(int i = 0; i < N; ++i){\n      if(i)\
    \ f *= i;\n      A[i + N - 1] = a[i] * f;\n    }\n\n    T d = 1;\n\n    std::vector<T>\
    \ g(N);\n    g[N - 1] = f.inv();\n    for(int i = N - 2; i >= 0; --i) g[i] = g[i\
    \ + 1] * (i + 1);\n\n    std::vector<T> B(2 * N - 1);\n    for(int i = 0; i <\
    \ N; ++i){\n      B[N - i - 1] = d * g[i];\n      d *= c;\n    }\n\n    auto C\
    \ = convolve(A, B);\n\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i)\
    \ ret[i] = C[(N - 1) * 2 + i] * g[i];\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T, typename Conv>\n  auto polynomial_taylor_shift(std::vector<T> a, T c, const\
    \ Conv &convolve){\n    const int N = a.size();\n    T f = 1;\n    std::vector<T>\
    \ A(2 * N - 1);\n    for(int i = 0; i < N; ++i){\n      if(i) f *= i;\n      A[i\
    \ + N - 1] = a[i] * f;\n    }\n\n    T d = 1;\n\n    std::vector<T> g(N);\n  \
    \  g[N - 1] = f.inv();\n    for(int i = N - 2; i >= 0; --i) g[i] = g[i + 1] *\
    \ (i + 1);\n\n    std::vector<T> B(2 * N - 1);\n    for(int i = 0; i < N; ++i){\n\
    \      B[N - i - 1] = d * g[i];\n      d *= c;\n    }\n\n    auto C = convolve(A,\
    \ B);\n\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) ret[i] = C[(N\
    \ - 1) * 2 + i] * g[i];\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Math/polynomial_taylor_shift.cpp
  requiredBy:
  - Mylib/Combinatorics/stirling_number_first_fft.cpp
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/polynomial_taylor_shift/main.test.cpp
  - test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp
documentation_of: Mylib/Math/polynomial_taylor_shift.cpp
layout: document
title: Polynomial taylor shift
---

## Operations

## Requirements

## Notes

## Problems

## References
