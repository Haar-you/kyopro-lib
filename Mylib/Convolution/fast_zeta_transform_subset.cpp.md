---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Mylib/Convolution/convolution_or.cpp
    title: Convolution (Index bitwise OR)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3134/main.test.cpp
    title: test/aoj/3134/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Convolution/fast_zeta_transform_subset.cpp\"\n#include\
    \ <vector>\n#include <functional>\n\nnamespace haar_lib {\n  template <typename\
    \ T, typename Func = std::plus<T>>\n  std::vector<T> fast_zeta_transform_subset(std::vector<T>\
    \ f, const Func &op = std::plus<T>()){\n    for(int i = 0; (1 << i) < (int)f.size();\
    \ ++i){\n      for(int j = 0; j < (int)f.size(); ++j){\n        if(j & (1 << i))\
    \ f[j] = op(f[j], f[j ^ (1 << i)]);\n      }\n    }\n    return f;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <functional>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Func = std::plus<T>>\n  std::vector<T> fast_zeta_transform_subset(std::vector<T>\
    \ f, const Func &op = std::plus<T>()){\n    for(int i = 0; (1 << i) < (int)f.size();\
    \ ++i){\n      for(int j = 0; j < (int)f.size(); ++j){\n        if(j & (1 << i))\
    \ f[j] = op(f[j], f[j ^ (1 << i)]);\n      }\n    }\n    return f;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Convolution/fast_zeta_transform_subset.cpp
  requiredBy:
  - Mylib/Convolution/convolution_or.cpp
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
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
