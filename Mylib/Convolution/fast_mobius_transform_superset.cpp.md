---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Mylib/Convolution/convolution_and.cpp
    title: Convolution (Index bitwise AND)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3119/main.test.cpp
    title: test/aoj/3119/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Convolution/fast_mobius_transform_superset.cpp\"\n\
    #include <vector>\n#include <functional>\n\nnamespace haar_lib {\n  template <typename\
    \ T, typename Func = std::minus<T>>\n  std::vector<T> fast_mobius_transform_superset(std::vector<T>\
    \ f, const Func &op = std::minus<T>()){\n    for(int i = 0; (1 << i) < (int)f.size();\
    \ ++i){\n      for(int j = 0; j < (int)f.size(); ++j){\n        if(not (j & (1\
    \ << i))) f[j] = op(f[j], f[j ^ (1 << i)]);\n      }\n    }\n    return f;\n \
    \ }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <functional>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Func = std::minus<T>>\n  std::vector<T>\
    \ fast_mobius_transform_superset(std::vector<T> f, const Func &op = std::minus<T>()){\n\
    \    for(int i = 0; (1 << i) < (int)f.size(); ++i){\n      for(int j = 0; j <\
    \ (int)f.size(); ++j){\n        if(not (j & (1 << i))) f[j] = op(f[j], f[j ^ (1\
    \ << i)]);\n      }\n    }\n    return f;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Convolution/fast_mobius_transform_superset.cpp
  requiredBy:
  - Mylib/Convolution/convolution_and.cpp
  timestamp: '2020-09-29 00:55:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
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
