---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Math/polynomial_taylor_shift.cpp
    title: Polynomial taylor shift
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp
    title: test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/stirling_number_first_fft.cpp\"\n#include\
    \ <vector>\n#include <algorithm>\n#line 3 \"Mylib/Math/polynomial_taylor_shift.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, const auto &convolve>\n  auto\
    \ polynomial_taylor_shift(std::vector<T> a, T c){\n    const int N = a.size();\n\
    \    T f = 1;\n\n    std::vector<T> A(2 * N - 1);\n    for(int i = 0; i < N; ++i){\n\
    \      if(i) f *= i;\n      A[i + N - 1] = a[i] * f;\n    }\n\n    T d = 1;\n\n\
    \    std::vector<T> g(N);\n    g[N - 1] = f.inv();\n    for(int i = N - 2; i >=\
    \ 0; --i) g[i] = g[i + 1] * (i + 1);\n\n    std::vector<T> B(2 * N - 1);\n   \
    \ for(int i = 0; i < N; ++i){\n      B[N - i - 1] = d * g[i];\n      d *= c;\n\
    \    }\n\n    auto C = convolve(A, B);\n\n    std::vector<T> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = C[(N - 1) * 2 + i] * g[i];\n\n    return ret;\n\
    \  }\n}\n#line 5 \"Mylib/Combinatorics/stirling_number_first_fft.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T, const auto &convolve>\n  std::vector<T>\
    \ stirling_number_of_first_kind_fft(int N){\n    if(N == 0) return {1};\n\n  \
    \  std::vector<int> p;\n    {\n      int a = N;\n\n      while(a > 0){\n     \
    \   if(a & 1) p.push_back(1);\n        p.push_back(2);\n        a >>= 1;\n   \
    \   }\n    }\n\n    std::vector<T> ret = {1};\n\n    std::reverse(p.begin(), p.end());\n\
    \    int t = 0;\n    for(int x : p){\n      if(x == 1){\n        std::vector<T>\
    \ a = {-t, 1};\n        ret = convolve(ret, a);\n\n        t += 1;\n      }else{\n\
    \        auto s = polynomial_taylor_shift<T, convolve>(ret, -t);\n        ret\
    \ = convolve(ret, s);\n        ret.resize(t * 2 + 1);\n\n        t *= 2;\n   \
    \   }\n    }\n\n    ret.resize(N + 1);\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include \"Mylib/Math/polynomial_taylor_shift.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, const auto &convolve>\n  std::vector<T>\
    \ stirling_number_of_first_kind_fft(int N){\n    if(N == 0) return {1};\n\n  \
    \  std::vector<int> p;\n    {\n      int a = N;\n\n      while(a > 0){\n     \
    \   if(a & 1) p.push_back(1);\n        p.push_back(2);\n        a >>= 1;\n   \
    \   }\n    }\n\n    std::vector<T> ret = {1};\n\n    std::reverse(p.begin(), p.end());\n\
    \    int t = 0;\n    for(int x : p){\n      if(x == 1){\n        std::vector<T>\
    \ a = {-t, 1};\n        ret = convolve(ret, a);\n\n        t += 1;\n      }else{\n\
    \        auto s = polynomial_taylor_shift<T, convolve>(ret, -t);\n        ret\
    \ = convolve(ret, s);\n        ret.resize(t * 2 + 1);\n\n        t *= 2;\n   \
    \   }\n    }\n\n    ret.resize(N + 1);\n\n    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/Math/polynomial_taylor_shift.cpp
  isVerificationFile: false
  path: Mylib/Combinatorics/stirling_number_first_fft.cpp
  requiredBy: []
  timestamp: '2020-11-04 17:40:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp
documentation_of: Mylib/Combinatorics/stirling_number_first_fft.cpp
layout: document
title: Stirling numbers of the first kind (FFT)
---

## Operations

## Requirements

## Notes

## Problems

## References
