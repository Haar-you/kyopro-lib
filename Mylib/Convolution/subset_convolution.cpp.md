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
    path: test/yosupo-judge/subset_convolution/main.test.cpp
    title: test/yosupo-judge/subset_convolution/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Convolution/subset_convolution.cpp\"\n#include <cassert>\n\
    #include <vector>\n#line 3 \"Mylib/Convolution/fast_mobius_transform_subset.cpp\"\
    \n#include <functional>\n#line 5 \"Mylib/Convolution/fast_mobius_transform_subset.cpp\"\
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
    \ 6 \"Mylib/Convolution/subset_convolution.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  std::vector<T> subset_convolution(std::vector<T> f, std::vector<T>\
    \ g) {\n    const int N = f.size();\n    assert((N & (N - 1)) == 0 && \"N must\
    \ be a power of 2\");\n    assert(f.size() == g.size());\n\n    const int K =\
    \ __builtin_ctz(N);\n\n    std::vector<std::vector<T>> F(K + 1), G(K + 1);\n\n\
    \    for (int i = 0; i <= K; ++i) {\n      F[i].resize(N);\n      G[i].resize(N);\n\
    \n      for (int j = 0; j < N; ++j) {\n        if (__builtin_popcount(j) == i)\
    \ {\n          F[i][j] = f[j];\n          G[i][j] = g[j];\n        }\n      }\n\
    \n      F[i] = fast_zeta_transform_subset(F[i]);\n      G[i] = fast_zeta_transform_subset(G[i]);\n\
    \    }\n\n    std::vector<std::vector<T>> H(K + 1, std::vector<T>(N));\n    for\
    \ (int i = 0; i <= K; ++i) {\n      for (int j = 0; j < N; ++j) {\n        for\
    \ (int s = 0; s <= i; ++s) {\n          H[i][j] += F[s][j] * G[i - s][j];\n  \
    \      }\n      }\n    }\n\n    std::vector<T> ret(N);\n\n    for (int i = 0;\
    \ i <= K; ++i) {\n      auto h = fast_mobius_transform_subset(H[i]);\n      for\
    \ (int j = 0; j < N; ++j) {\n        if (__builtin_popcount(j) == i) ret[j] +=\
    \ h[j];\n      }\n    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"Mylib/Convolution/fast_mobius_transform_subset.cpp\"\
    \n#include \"Mylib/Convolution/fast_zeta_transform_subset.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  std::vector<T> subset_convolution(std::vector<T>\
    \ f, std::vector<T> g) {\n    const int N = f.size();\n    assert((N & (N - 1))\
    \ == 0 && \"N must be a power of 2\");\n    assert(f.size() == g.size());\n\n\
    \    const int K = __builtin_ctz(N);\n\n    std::vector<std::vector<T>> F(K +\
    \ 1), G(K + 1);\n\n    for (int i = 0; i <= K; ++i) {\n      F[i].resize(N);\n\
    \      G[i].resize(N);\n\n      for (int j = 0; j < N; ++j) {\n        if (__builtin_popcount(j)\
    \ == i) {\n          F[i][j] = f[j];\n          G[i][j] = g[j];\n        }\n \
    \     }\n\n      F[i] = fast_zeta_transform_subset(F[i]);\n      G[i] = fast_zeta_transform_subset(G[i]);\n\
    \    }\n\n    std::vector<std::vector<T>> H(K + 1, std::vector<T>(N));\n    for\
    \ (int i = 0; i <= K; ++i) {\n      for (int j = 0; j < N; ++j) {\n        for\
    \ (int s = 0; s <= i; ++s) {\n          H[i][j] += F[s][j] * G[i - s][j];\n  \
    \      }\n      }\n    }\n\n    std::vector<T> ret(N);\n\n    for (int i = 0;\
    \ i <= K; ++i) {\n      auto h = fast_mobius_transform_subset(H[i]);\n      for\
    \ (int j = 0; j < N; ++j) {\n        if (__builtin_popcount(j) == i) ret[j] +=\
    \ h[j];\n      }\n    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn:
  - Mylib/Convolution/fast_mobius_transform_subset.cpp
  - Mylib/Convolution/fast_zeta_transform_subset.cpp
  isVerificationFile: false
  path: Mylib/Convolution/subset_convolution.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/subset_convolution/main.test.cpp
documentation_of: Mylib/Convolution/subset_convolution.cpp
layout: document
title: Subset convolution
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://arxiv.org/abs/cs/0611101](https://arxiv.org/abs/cs/0611101)
