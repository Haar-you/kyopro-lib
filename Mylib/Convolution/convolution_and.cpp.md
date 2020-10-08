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
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Convolution/convolution_and.cpp\"\n#include <vector>\n\
    #line 3 \"Mylib/Convolution/fast_zeta_transform_superset.cpp\"\n#include <functional>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Func = std::plus<T>>\n\
    \  std::vector<T> fast_zeta_transform_superset(std::vector<T> f, const Func &op\
    \ = std::plus<T>()){\n    for(int i = 0; (1 << i) < (int)f.size(); ++i){\n   \
    \   for(int j = 0; j < (int)f.size(); ++j){\n        if(not (j & (1 << i))) f[j]\
    \ = op(f[j], f[j ^ (1 << i)]);\n      }\n    }\n    return f;\n  }\n}\n#line 4\
    \ \"Mylib/Convolution/fast_mobius_transform_superset.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Func = std::minus<T>>\n  std::vector<T>\
    \ fast_mobius_transform_superset(std::vector<T> f, const Func &op = std::minus<T>()){\n\
    \    for(int i = 0; (1 << i) < (int)f.size(); ++i){\n      for(int j = 0; j <\
    \ (int)f.size(); ++j){\n        if(not (j & (1 << i))) f[j] = op(f[j], f[j ^ (1\
    \ << i)]);\n      }\n    }\n    return f;\n  }\n}\n#line 5 \"Mylib/Convolution/convolution_and.cpp\"\
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
  timestamp: '2020-09-29 00:55:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
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
