---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/multipoint_evaluation/main.test.cpp
    title: test/yosupo-judge/multipoint_evaluation/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Math/multipoint_evaluation.cpp\"\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Poly>\n  auto multipoint_evaluation(Poly\
    \ a, std::vector<T> p){\n    const int M = p.size();\n    std::vector<T> ret(M);\n\
    \n    int k = 1;\n    while(k < M) k *= 2;\n\n    std::vector<Poly> f(k * 2, {1});\n\
    \n    for(int i = 0; i < M; ++i) f[i + k] = {-p[i], 1};\n    for(int i = k - 1;\
    \ i >= 1; --i) f[i] = f[i << 1 | 0] * f[i << 1 | 1];\n\n    f[1] = a.divmod(f[1]).second;\n\
    \n    for(int i = 2; i < k + M; ++i) f[i] = f[i >> 1].divmod(f[i]).second;\n \
    \   for(int i = 0; i < M; ++i) ret[i] = f[k + i][0];\n\n    return ret;\n  }\n\
    }\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T, typename Poly>\n  auto multipoint_evaluation(Poly a, std::vector<T> p){\n\
    \    const int M = p.size();\n    std::vector<T> ret(M);\n\n    int k = 1;\n \
    \   while(k < M) k *= 2;\n\n    std::vector<Poly> f(k * 2, {1});\n\n    for(int\
    \ i = 0; i < M; ++i) f[i + k] = {-p[i], 1};\n    for(int i = k - 1; i >= 1; --i)\
    \ f[i] = f[i << 1 | 0] * f[i << 1 | 1];\n\n    f[1] = a.divmod(f[1]).second;\n\
    \n    for(int i = 2; i < k + M; ++i) f[i] = f[i >> 1].divmod(f[i]).second;\n \
    \   for(int i = 0; i < M; ++i) ret[i] = f[k + i][0];\n\n    return ret;\n  }\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Math/multipoint_evaluation.cpp
  requiredBy: []
  timestamp: '2020-11-05 01:04:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/multipoint_evaluation/main.test.cpp
documentation_of: Mylib/Math/multipoint_evaluation.cpp
layout: document
title: Multipoint evaluation
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://rsk0315.hatenablog.com/entry/2020/04/05/190941](https://rsk0315.hatenablog.com/entry/2020/04/05/190941)
