---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Convolution/fast_mobius_transform_superset.cpp
    title: "Fast M\xF6bius transform (Supersets)"
  - icon: ':heavy_check_mark:'
    path: Mylib/Convolution/fast_zeta_transform_superset.cpp
    title: Fast Zeta transform (Supersets)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/bitwise_and_convolution/main.test.cpp
    title: test/yosupo-judge/bitwise_and_convolution/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Convolution/convolution_and.cpp\"\n#include <vector>\n\
    #line 3 \"Mylib/Convolution/fast_zeta_transform_superset.cpp\"\n#include <functional>\n\
    #include <cassert>\n\nnamespace haar_lib {\n  template <typename T, typename Func\
    \ = std::plus<T>>\n  std::vector<T> fast_zeta_transform_superset(std::vector<T>\
    \ f, const Func &op = std::plus<T>()){\n    const int N = f.size();\n    assert((N\
    \ & (N - 1)) == 0 && \"N must be a power of 2\");\n    for(int i = 1; i < N; i\
    \ <<= 1){\n      for(int j = 0; j < N; ++j){\n        if(not (j & i)) f[j] = op(f[j],\
    \ f[j ^ i]);\n      }\n    }\n    return f;\n  }\n}\n#line 5 \"Mylib/Convolution/fast_mobius_transform_superset.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, typename Func = std::minus<T>>\n\
    \  std::vector<T> fast_mobius_transform_superset(std::vector<T> f, const Func\
    \ &op = std::minus<T>()){\n    const int N = f.size();\n    assert((N & (N - 1))\
    \ == 0 && \"N must be a power of 2\");\n    for(int i = 1; i < N; i <<= 1){\n\
    \      for(int j = 0; j < N; ++j){\n        if(not (j & i)) f[j] = op(f[j], f[j\
    \ ^ i]);\n      }\n    }\n    return f;\n  }\n}\n#line 5 \"Mylib/Convolution/convolution_and.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> convolution_and(std::vector<T>\
    \ f, std::vector<T> g){\n    f = fast_zeta_transform_superset(f);\n    g = fast_zeta_transform_superset(g);\n\
    \    for(size_t i = 0; i < f.size(); ++i) f[i] *= g[i];\n    f = fast_mobius_transform_superset(f);\n\
    \    return f;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"Mylib/Convolution/fast_zeta_transform_superset.cpp\"\
    \n#include \"Mylib/Convolution/fast_mobius_transform_superset.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  std::vector<T> convolution_and(std::vector<T>\
    \ f, std::vector<T> g){\n    f = fast_zeta_transform_superset(f);\n    g = fast_zeta_transform_superset(g);\n\
    \    for(size_t i = 0; i < f.size(); ++i) f[i] *= g[i];\n    f = fast_mobius_transform_superset(f);\n\
    \    return f;\n  }\n}\n"
  dependsOn:
  - Mylib/Convolution/fast_zeta_transform_superset.cpp
  - Mylib/Convolution/fast_mobius_transform_superset.cpp
  isVerificationFile: false
  path: Mylib/Convolution/convolution_and.cpp
  requiredBy: []
  timestamp: '2020-10-30 23:28:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/bitwise_and_convolution/main.test.cpp
documentation_of: Mylib/Convolution/convolution_and.cpp
layout: document
title: Convolution (Index bitwise AND)
---

## Operations

- `convolution_and(f[N], g[N])`
	- `N`は2の累乗
	- `k in [0, N)`について、$h_k = \sum_{k=i \cap j} f_i * g_j$を求める。

## Requirements

## Notes

## Problems

## References
