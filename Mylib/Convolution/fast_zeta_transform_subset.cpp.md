---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Mylib/Convolution/convolution_or.cpp
    title: Convolution (Index bitwise OR)
  - icon: ':heavy_check_mark:'
    path: Mylib/Convolution/subset_convolution.cpp
    title: Subset convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3134/main.test.cpp
    title: test/aoj/3134/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/bitwise_and_convolution/main.or.test.cpp
    title: test/yosupo-judge/bitwise_and_convolution/main.or.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/subset_convolution/main.test.cpp
    title: test/yosupo-judge/subset_convolution/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Convolution/fast_zeta_transform_subset.cpp\"\n#include\
    \ <vector>\n#include <functional>\n#include <cassert>\n\nnamespace haar_lib {\n\
    \  template <typename T, typename Func = std::plus<T>>\n  std::vector<T> fast_zeta_transform_subset(std::vector<T>\
    \ f, const Func &op = std::plus<T>()){\n    const int N = f.size();\n    assert((N\
    \ & (N - 1)) == 0 && \"N must be a power of 2\");\n    for(int i = 1; i < N; i\
    \ <<= 1){\n      for(int j = 0; j < N; ++j){\n        if(j & i) f[j] = op(f[j],\
    \ f[j ^ i]);\n      }\n    }\n    return f;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <functional>\n#include <cassert>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Func = std::plus<T>>\n\
    \  std::vector<T> fast_zeta_transform_subset(std::vector<T> f, const Func &op\
    \ = std::plus<T>()){\n    const int N = f.size();\n    assert((N & (N - 1)) ==\
    \ 0 && \"N must be a power of 2\");\n    for(int i = 1; i < N; i <<= 1){\n   \
    \   for(int j = 0; j < N; ++j){\n        if(j & i) f[j] = op(f[j], f[j ^ i]);\n\
    \      }\n    }\n    return f;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Convolution/fast_zeta_transform_subset.cpp
  requiredBy:
  - Mylib/Convolution/subset_convolution.cpp
  - Mylib/Convolution/convolution_or.cpp
  timestamp: '2020-10-30 23:28:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/subset_convolution/main.test.cpp
  - test/yosupo-judge/bitwise_and_convolution/main.or.test.cpp
  - test/aoj/3134/main.test.cpp
documentation_of: Mylib/Convolution/fast_zeta_transform_subset.cpp
layout: document
title: Fast Zeta transform (Subsets)
---

## Operations

- `fast_zeta_transform_subset(f[N], op = std::plus())`
	- `N`は2の累乗
	- $g(S) = \sum_{T \subseteq S} f(T)$

## Requirements

## Notes

## Problems

- [ARC 100 E - Or Plus Max](https://atcoder.jp/contests/arc100/tasks/arc100_c) (演算がやや特殊)

## References
