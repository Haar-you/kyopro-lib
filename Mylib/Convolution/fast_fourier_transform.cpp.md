---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Convolution/fast_fourier_transform.cpp\"\n#include\
    \ <vector>\n#include <complex>\n#include <cassert>\n#include <utility>\n\nnamespace\
    \ haar_lib {\n  template <typename T = double, bool INVERSE = false>\n  auto fast_fourier_transform(std::vector<std::complex<T>>\
    \ f){\n    const int n = f.size();\n    assert((n & (n - 1)) == 0); // \u30C7\u30FC\
    \u30BF\u6570\u306F2\u306E\u51AA\u4E57\u500B\n\n    const int p = __builtin_ctz(n);\n\
    \n    for(int i = 0; i < n; ++i){\n      int j = 0;\n      for(int k = 0; k <\
    \ p; ++k) j |= (i >> k & 1) << (p - 1 - k);\n      if(i < j) std::swap(f[i], f[j]);\n\
    \    }\n\n    for(int b = 1; b < n; b <<= 1){\n      for(int i = 0; i < b; ++i){\n\
    \        T angle = 2.0 * M_PI * i / (2 * b);\n        if(INVERSE) angle = -angle;\n\
    \        std::complex<T> w = std::polar(1.0, angle);\n\n        for(int j = 0;\
    \ j < n; j += 2 * b){\n          auto s = f[i + j];\n          auto t = f[i +\
    \ j + b] * w;\n\n          f[i + j] = s + t;\n          f[i + j + b] = s - t;\n\
    \        }\n      }\n    }\n\n    if(INVERSE) for(auto &x : f) x /= n;\n\n   \
    \ return f;\n  }\n\n  template <typename T = double>\n  std::vector<std::complex<T>>\
    \ fft_convolution(std::vector<std::complex<T>> f, std::vector<std::complex<T>>\
    \ g){\n    const int m = f.size() + g.size() - 1;\n    int n = 1;\n    while(n\
    \ < m) n *= 2;\n\n    f.resize(n);\n    g.resize(n);\n\n    f = fast_fourier_transform<T>(f);\n\
    \    g = fast_fourier_transform<T>(g);\n\n    std::vector<std::complex<T>> ret(n);\n\
    \    for(int i = 0; i < n; ++i) ret[i] = f[i] * g[i];\n    ret = fast_fourier_transform<T,\
    \ true>(ret);\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <complex>\n#include <cassert>\n\
    #include <utility>\n\nnamespace haar_lib {\n  template <typename T = double, bool\
    \ INVERSE = false>\n  auto fast_fourier_transform(std::vector<std::complex<T>>\
    \ f){\n    const int n = f.size();\n    assert((n & (n - 1)) == 0); // \u30C7\u30FC\
    \u30BF\u6570\u306F2\u306E\u51AA\u4E57\u500B\n\n    const int p = __builtin_ctz(n);\n\
    \n    for(int i = 0; i < n; ++i){\n      int j = 0;\n      for(int k = 0; k <\
    \ p; ++k) j |= (i >> k & 1) << (p - 1 - k);\n      if(i < j) std::swap(f[i], f[j]);\n\
    \    }\n\n    for(int b = 1; b < n; b <<= 1){\n      for(int i = 0; i < b; ++i){\n\
    \        T angle = 2.0 * M_PI * i / (2 * b);\n        if(INVERSE) angle = -angle;\n\
    \        std::complex<T> w = std::polar(1.0, angle);\n\n        for(int j = 0;\
    \ j < n; j += 2 * b){\n          auto s = f[i + j];\n          auto t = f[i +\
    \ j + b] * w;\n\n          f[i + j] = s + t;\n          f[i + j + b] = s - t;\n\
    \        }\n      }\n    }\n\n    if(INVERSE) for(auto &x : f) x /= n;\n\n   \
    \ return f;\n  }\n\n  template <typename T = double>\n  std::vector<std::complex<T>>\
    \ fft_convolution(std::vector<std::complex<T>> f, std::vector<std::complex<T>>\
    \ g){\n    const int m = f.size() + g.size() - 1;\n    int n = 1;\n    while(n\
    \ < m) n *= 2;\n\n    f.resize(n);\n    g.resize(n);\n\n    f = fast_fourier_transform<T>(f);\n\
    \    g = fast_fourier_transform<T>(g);\n\n    std::vector<std::complex<T>> ret(n);\n\
    \    for(int i = 0; i < n; ++i) ret[i] = f[i] * g[i];\n    ret = fast_fourier_transform<T,\
    \ true>(ret);\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Convolution/fast_fourier_transform.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Convolution/fast_fourier_transform.cpp
layout: document
title: Fast Fourier transform
---

## Operations

## Requirements

## Notes

## Problems

- [ATC 001 C - 高速フーリエ変換](https://atcoder.jp/contests/atc001/tasks/fft_c)

## References
