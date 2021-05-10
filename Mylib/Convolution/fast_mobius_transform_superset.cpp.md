---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Convolution/convolution_and.cpp
    title: Convolution (Index bitwise AND)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3119/main.test.cpp
    title: test/aoj/3119/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/bitwise_and_convolution/main.test.cpp
    title: test/yosupo-judge/bitwise_and_convolution/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Convolution/fast_mobius_transform_superset.cpp\"\n\
    #include <cassert>\n#include <functional>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Func = std::minus<T>>\n  std::vector<T>\
    \ fast_mobius_transform_superset(std::vector<T> f, const Func &op = std::minus<T>())\
    \ {\n    const int N = f.size();\n    assert((N & (N - 1)) == 0 && \"N must be\
    \ a power of 2\");\n    for (int i = 1; i < N; i <<= 1) {\n      for (int j =\
    \ 0; j < N; ++j) {\n        if (not(j & i)) f[j] = op(f[j], f[j ^ i]);\n     \
    \ }\n    }\n    return f;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cassert>\n#include <functional>\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Func = std::minus<T>>\n\
    \  std::vector<T> fast_mobius_transform_superset(std::vector<T> f, const Func\
    \ &op = std::minus<T>()) {\n    const int N = f.size();\n    assert((N & (N -\
    \ 1)) == 0 && \"N must be a power of 2\");\n    for (int i = 1; i < N; i <<= 1)\
    \ {\n      for (int j = 0; j < N; ++j) {\n        if (not(j & i)) f[j] = op(f[j],\
    \ f[j ^ i]);\n      }\n    }\n    return f;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Convolution/fast_mobius_transform_superset.cpp
  requiredBy:
  - Mylib/Convolution/convolution_and.cpp
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo-judge/bitwise_and_convolution/main.test.cpp
  - test/aoj/3119/main.test.cpp
documentation_of: Mylib/Convolution/fast_mobius_transform_superset.cpp
layout: document
title: "Fast M\xF6bius transform (Supersets)"
---

## Operations

- `fast_mobius_transform_superset(f[N], op = std::minus())`
	- `N`は2の累乗
    - $g(S) = \sum_{T \subseteq S} f(T) * (-1) ^ {\vert S \vert - \vert T \vert}$

## Requirements

## Notes

## Problems

## References