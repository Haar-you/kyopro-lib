---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Convolution/fast_zeta_transform_subset.cpp
    title: Fast Zeta transform (Subsets)
  - icon: ':heavy_check_mark:'
    path: Mylib/Convolution/fast_mobius_transform_subset.cpp
    title: "Fast M\xF6bius transform (Subsets)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Convolution/convolution_or.cpp\"\n#include <vector>\n\
    #line 3 \"Mylib/Convolution/fast_zeta_transform_subset.cpp\"\n#include <functional>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Func = std::plus<T>>\n\
    \  std::vector<T> fast_zeta_transform_subset(std::vector<T> f, const Func &op\
    \ = std::plus<T>()){\n    for(int i = 0; (1 << i) < (int)f.size(); ++i){\n   \
    \   for(int j = 0; j < (int)f.size(); ++j){\n        if(j & (1 << i)) f[j] = op(f[j],\
    \ f[j ^ (1 << i)]);\n      }\n    }\n    return f;\n  }\n}\n#line 4 \"Mylib/Convolution/fast_mobius_transform_subset.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, typename Func = std::minus<T>>\n\
    \  std::vector<T> fast_mobius_transform_subset(std::vector<T> f, const Func &op\
    \ = std::minus<T>()){\n    for(int i = 0; (1 << i) < (int)f.size(); ++i){\n  \
    \    for(int j = 0; j < (int)f.size(); ++j){\n        if(j & (1 << i)) f[j] =\
    \ op(f[j], f[j ^ (1 << i)]);\n      }\n    }\n    return f;\n  }\n}\n#line 5 \"\
    Mylib/Convolution/convolution_or.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  std::vector<T> convolution_or(std::vector<T> f, std::vector<T> g){\n \
    \   f = fast_zeta_transform_subset(f);\n    g = fast_zeta_transform_subset(g);\n\
    \    for(size_t i = 0; i < f.size(); ++i) f[i] *= g[i];\n    f = fast_mobius_transform_subset(f);\n\
    \    return f;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"Mylib/Convolution/fast_zeta_transform_subset.cpp\"\
    \n#include \"Mylib/Convolution/fast_mobius_transform_subset.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  std::vector<T> convolution_or(std::vector<T>\
    \ f, std::vector<T> g){\n    f = fast_zeta_transform_subset(f);\n    g = fast_zeta_transform_subset(g);\n\
    \    for(size_t i = 0; i < f.size(); ++i) f[i] *= g[i];\n    f = fast_mobius_transform_subset(f);\n\
    \    return f;\n  }\n}\n"
  dependsOn:
  - Mylib/Convolution/fast_zeta_transform_subset.cpp
  - Mylib/Convolution/fast_mobius_transform_subset.cpp
  isVerificationFile: false
  path: Mylib/Convolution/convolution_or.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
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
