---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Convolution/fast_mobius_transform_subset.cpp
    title: "Fast M\xF6bius transform (Subsets)"
  - icon: ':question:'
    path: Mylib/Convolution/fast_zeta_transform_subset.cpp
    title: Fast Zeta transform (Subsets)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/bitwise_and_convolution/main.or.test.cpp
    title: test/yosupo-judge/bitwise_and_convolution/main.or.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Convolution/convolution_or.cpp\"\n#include <vector>\n\
    #line 2 \"Mylib/Convolution/fast_mobius_transform_subset.cpp\"\n#include <cassert>\n\
    #include <functional>\n#line 5 \"Mylib/Convolution/fast_mobius_transform_subset.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, typename Func = std::minus<T>>\n\
    \  std::vector<T> fast_mobius_transform_subset(std::vector<T> f, const Func &op\
    \ = std::minus<T>()) {\n    const int N = f.size();\n    assert((N & (N - 1))\
    \ == 0 && \"N must be a power of 2\");\n    for (int i = 1; i < N; i <<= 1) {\n\
    \      for (int j = 0; j < N; ++j) {\n        if (j & i) f[j] = op(f[j], f[j ^\
    \ i]);\n      }\n    }\n    return f;\n  }\n}  // namespace haar_lib\n#line 5\
    \ \"Mylib/Convolution/fast_zeta_transform_subset.cpp\"\n\nnamespace haar_lib {\n\
    \  template <typename T, typename Func = std::plus<T>>\n  std::vector<T> fast_zeta_transform_subset(std::vector<T>\
    \ f, const Func &op = std::plus<T>()) {\n    const int N = f.size();\n    assert((N\
    \ & (N - 1)) == 0 && \"N must be a power of 2\");\n    for (int i = 1; i < N;\
    \ i <<= 1) {\n      for (int j = 0; j < N; ++j) {\n        if (j & i) f[j] = op(f[j],\
    \ f[j ^ i]);\n      }\n    }\n    return f;\n  }\n}  // namespace haar_lib\n#line\
    \ 5 \"Mylib/Convolution/convolution_or.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  std::vector<T> convolution_or(std::vector<T> f, std::vector<T>\
    \ g) {\n    f = fast_zeta_transform_subset(f);\n    g = fast_zeta_transform_subset(g);\n\
    \    for (size_t i = 0; i < f.size(); ++i) f[i] *= g[i];\n    f = fast_mobius_transform_subset(f);\n\
    \    return f;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <vector>\n#include \"Mylib/Convolution/fast_mobius_transform_subset.cpp\"\
    \n#include \"Mylib/Convolution/fast_zeta_transform_subset.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  std::vector<T> convolution_or(std::vector<T> f,\
    \ std::vector<T> g) {\n    f = fast_zeta_transform_subset(f);\n    g = fast_zeta_transform_subset(g);\n\
    \    for (size_t i = 0; i < f.size(); ++i) f[i] *= g[i];\n    f = fast_mobius_transform_subset(f);\n\
    \    return f;\n  }\n}  // namespace haar_lib\n"
  dependsOn:
  - Mylib/Convolution/fast_mobius_transform_subset.cpp
  - Mylib/Convolution/fast_zeta_transform_subset.cpp
  isVerificationFile: false
  path: Mylib/Convolution/convolution_or.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/bitwise_and_convolution/main.or.test.cpp
documentation_of: Mylib/Convolution/convolution_or.cpp
layout: document
title: Convolution (Index bitwise OR)
---

## Operations

- `convolution_or(f[N], g[N])`
	- `N`は2の累乗
	- `k in [0, N)`について、$h_k = \sum_{k=i \cup j} f_i * g_j$を求める。

## Requirements

## Notes

## Problems

- [CSA Maxor](https://csacademy.com/contest/archive/task/maxor/)

## References