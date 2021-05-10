---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/multipoint_evaluation/main.test.cpp
    title: test/yosupo-judge/multipoint_evaluation/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Math/multipoint_evaluation.cpp\"\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Poly>\n  auto multipoint_evaluation(Poly\
    \ a, std::vector<T> p) {\n    const int M = p.size();\n    std::vector<T> ret(M);\n\
    \n    int k = 1;\n    while (k < M) k *= 2;\n\n    std::vector<Poly> f(k * 2,\
    \ {1});\n\n    for (int i = 0; i < M; ++i) f[i + k] = {-p[i], 1};\n    for (int\
    \ i = k - 1; i >= 1; --i) f[i] = f[i << 1 | 0] * f[i << 1 | 1];\n\n    f[1] =\
    \ a % f[1];\n\n    for (int i = 2; i < k + M; ++i) f[i] = f[i >> 1] % f[i];\n\
    \    for (int i = 0; i < M; ++i) ret[i] = f[k + i][0];\n\n    return ret;\n  }\n\
    }  // namespace haar_lib\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T, typename Poly>\n  auto multipoint_evaluation(Poly a, std::vector<T> p) {\n\
    \    const int M = p.size();\n    std::vector<T> ret(M);\n\n    int k = 1;\n \
    \   while (k < M) k *= 2;\n\n    std::vector<Poly> f(k * 2, {1});\n\n    for (int\
    \ i = 0; i < M; ++i) f[i + k] = {-p[i], 1};\n    for (int i = k - 1; i >= 1; --i)\
    \ f[i] = f[i << 1 | 0] * f[i << 1 | 1];\n\n    f[1] = a % f[1];\n\n    for (int\
    \ i = 2; i < k + M; ++i) f[i] = f[i >> 1] % f[i];\n    for (int i = 0; i < M;\
    \ ++i) ret[i] = f[k + i][0];\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Math/multipoint_evaluation.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
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