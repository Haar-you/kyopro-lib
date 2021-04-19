---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp
    title: test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/stirling_number_second_fft.cpp\"\n#include\
    \ <vector>\n\nnamespace haar_lib {\n  template <typename T, const auto &convolve>\n\
    \  std::vector<T> stirling_number_of_second_kind_fft(int N){\n    std::vector<T>\
    \ a(N + 1), b(N + 1);\n\n    std::vector<int> m(N + 1, 0);\n    for(int i = 2;\
    \ i <= N; ++i){\n      if(m[i] != 0) continue;\n      for(int j = 2 * i; j <=\
    \ N; j += i){\n        m[j] = i;\n      }\n    }\n\n    for(int i = 0; i <= N;\
    \ ++i){\n      if(m[i] == 0){\n        a[i] = T::pow(i, N);\n      }else{\n  \
    \      a[i] = a[m[i]] * a[i / m[i]];\n      }\n    }\n\n    T f = 1;\n    for(int\
    \ i = 1; i <= N; ++i) f *= i;\n    f = f.inv();\n\n    for(int i = N; i >= 0;\
    \ --i){\n      a[i] *= f;\n      b[i] = f;\n      f *= i;\n\n      if(i % 2 ==\
    \ 1){\n        b[i] = -b[i];\n      }\n    }\n\n    auto ret = convolve(a, b);\n\
    \    ret.resize(N + 1);\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T, const auto &convolve>\n  std::vector<T> stirling_number_of_second_kind_fft(int\
    \ N){\n    std::vector<T> a(N + 1), b(N + 1);\n\n    std::vector<int> m(N + 1,\
    \ 0);\n    for(int i = 2; i <= N; ++i){\n      if(m[i] != 0) continue;\n     \
    \ for(int j = 2 * i; j <= N; j += i){\n        m[j] = i;\n      }\n    }\n\n \
    \   for(int i = 0; i <= N; ++i){\n      if(m[i] == 0){\n        a[i] = T::pow(i,\
    \ N);\n      }else{\n        a[i] = a[m[i]] * a[i / m[i]];\n      }\n    }\n\n\
    \    T f = 1;\n    for(int i = 1; i <= N; ++i) f *= i;\n    f = f.inv();\n\n \
    \   for(int i = N; i >= 0; --i){\n      a[i] *= f;\n      b[i] = f;\n      f *=\
    \ i;\n\n      if(i % 2 == 1){\n        b[i] = -b[i];\n      }\n    }\n\n    auto\
    \ ret = convolve(a, b);\n    ret.resize(N + 1);\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Combinatorics/stirling_number_second_fft.cpp
  requiredBy: []
  timestamp: '2021-03-13 04:56:32+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp
documentation_of: Mylib/Combinatorics/stirling_number_second_fft.cpp
layout: document
title: Stirling numbers of the second kind (FFT)
---

## Operations

## Requirements

## Notes

## Problems

## References
