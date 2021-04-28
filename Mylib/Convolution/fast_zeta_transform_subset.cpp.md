---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Convolution/convolution_or.cpp
    title: Convolution (Index bitwise OR)
  - icon: ':x:'
    path: Mylib/Convolution/subset_convolution.cpp
    title: Subset convolution
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/3134/main.test.cpp
    title: test/aoj/3134/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/bitwise_and_convolution/main.or.test.cpp
    title: test/yosupo-judge/bitwise_and_convolution/main.or.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/subset_convolution/main.test.cpp
    title: test/yosupo-judge/subset_convolution/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Convolution/fast_zeta_transform_subset.cpp\"\n#include\
    \ <cassert>\n#include <functional>\n#include <vector>\n\nnamespace haar_lib {\n\
    \  template <typename T, typename Func = std::plus<T>>\n  std::vector<T> fast_zeta_transform_subset(std::vector<T>\
    \ f, const Func &op = std::plus<T>()) {\n    const int N = f.size();\n    assert((N\
    \ & (N - 1)) == 0 && \"N must be a power of 2\");\n    for (int i = 1; i < N;\
    \ i <<= 1) {\n      for (int j = 0; j < N; ++j) {\n        if (j & i) f[j] = op(f[j],\
    \ f[j ^ i]);\n      }\n    }\n    return f;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cassert>\n#include <functional>\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Func = std::plus<T>>\n\
    \  std::vector<T> fast_zeta_transform_subset(std::vector<T> f, const Func &op\
    \ = std::plus<T>()) {\n    const int N = f.size();\n    assert((N & (N - 1)) ==\
    \ 0 && \"N must be a power of 2\");\n    for (int i = 1; i < N; i <<= 1) {\n \
    \     for (int j = 0; j < N; ++j) {\n        if (j & i) f[j] = op(f[j], f[j ^\
    \ i]);\n      }\n    }\n    return f;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Convolution/fast_zeta_transform_subset.cpp
  requiredBy:
  - Mylib/Convolution/subset_convolution.cpp
  - Mylib/Convolution/convolution_or.cpp
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
