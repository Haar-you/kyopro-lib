---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Mylib/Convolution/convolution_or.cpp
    title: Convolution (Index bitwise OR)
  - icon: ':heavy_check_mark:'
    path: Mylib/Convolution/subset_convolution.cpp
    title: Subset convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2446/main.test.cpp
    title: test/aoj/2446/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/subset_convolution/main.test.cpp
    title: test/yosupo-judge/subset_convolution/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Convolution/fast_mobius_transform_subset.cpp\"\n#include\
    \ <vector>\n#include <functional>\n#include <cassert>\n\nnamespace haar_lib {\n\
    \  template <typename T, typename Func = std::minus<T>>\n  std::vector<T> fast_mobius_transform_subset(std::vector<T>\
    \ f, const Func &op = std::minus<T>()){\n    const int N = f.size();\n    assert((N\
    \ & (N - 1)) == 0 && \"N must be a power of 2\");\n    for(int i = 1; i < N; i\
    \ <<= 1){\n      for(int j = 0; j < N; ++j){\n        if(j & i) f[j] = op(f[j],\
    \ f[j ^ i]);\n      }\n    }\n    return f;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <functional>\n#include <cassert>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Func = std::minus<T>>\n\
    \  std::vector<T> fast_mobius_transform_subset(std::vector<T> f, const Func &op\
    \ = std::minus<T>()){\n    const int N = f.size();\n    assert((N & (N - 1)) ==\
    \ 0 && \"N must be a power of 2\");\n    for(int i = 1; i < N; i <<= 1){\n   \
    \   for(int j = 0; j < N; ++j){\n        if(j & i) f[j] = op(f[j], f[j ^ i]);\n\
    \      }\n    }\n    return f;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Convolution/fast_mobius_transform_subset.cpp
  requiredBy:
  - Mylib/Convolution/subset_convolution.cpp
  - Mylib/Convolution/convolution_or.cpp
  timestamp: '2020-10-30 23:28:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/subset_convolution/main.test.cpp
  - test/aoj/2446/main.test.cpp
documentation_of: Mylib/Convolution/fast_mobius_transform_subset.cpp
layout: document
title: "Fast M\xF6bius transform (Subsets)"
---

## Operations

- `fast_mobius_transform_subset(f[N], op = std::minus())`
	- `N`は2の累乗
	- $g(S) = \sum_{T \subseteq S} f(T) * (-1) ^ {\vert S \vert - \vert T \vert}$

## Requirements

## Notes

## Problems

- [AOJ 2446 Enumeration](https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2446)

## References
