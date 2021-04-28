---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Convolution/convolution_gcd.cpp\"\n#include <cassert>\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  auto divisor_zeta_transform(std::vector<T>\
    \ f) {\n    const int N = f.size();\n    std::vector<bool> check(N, true);\n \
    \   for (int i = 2; i < N; ++i) {\n      if (check[i]) {\n        for (int j =\
    \ (N - 1) / i; j > 0; --j) {\n          check[j * i] = false;\n          f[j]\
    \ += f[j * i];\n        }\n      }\n    }\n    return f;\n  }\n\n  template <typename\
    \ T>\n  auto divisor_mobius_transform(std::vector<T> f) {\n    const int N = f.size();\n\
    \    std::vector<bool> check(N, true);\n    for (int i = 2; i < N; ++i) {\n  \
    \    if (check[i]) {\n        for (int j = 1; j * i < N; ++j) {\n          check[j\
    \ * i] = false;\n          f[j] -= f[j * i];\n        }\n      }\n    }\n    return\
    \ f;\n  }\n\n  template <typename T>\n  std::vector<T> convolution_gcd(std::vector<T>\
    \ f, std::vector<T> g) {\n    const int N = f.size();\n    assert(f.size() ==\
    \ g.size());\n\n    std::vector<T> ret(N);\n    for (int i = 1; i < N; ++i) ret[i]\
    \ += f[i] + g[i];\n\n    f = divisor_zeta_transform(f);\n    g = divisor_zeta_transform(g);\n\
    \    for (int i = 0; i < N; ++i) f[i] *= g[i];\n    f = divisor_mobius_transform(f);\n\
    \    for (int i = 0; i < N; ++i) ret[i] += f[i];\n    return ret;\n  }\n}  //\
    \ namespace haar_lib\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  auto divisor_zeta_transform(std::vector<T> f)\
    \ {\n    const int N = f.size();\n    std::vector<bool> check(N, true);\n    for\
    \ (int i = 2; i < N; ++i) {\n      if (check[i]) {\n        for (int j = (N -\
    \ 1) / i; j > 0; --j) {\n          check[j * i] = false;\n          f[j] += f[j\
    \ * i];\n        }\n      }\n    }\n    return f;\n  }\n\n  template <typename\
    \ T>\n  auto divisor_mobius_transform(std::vector<T> f) {\n    const int N = f.size();\n\
    \    std::vector<bool> check(N, true);\n    for (int i = 2; i < N; ++i) {\n  \
    \    if (check[i]) {\n        for (int j = 1; j * i < N; ++j) {\n          check[j\
    \ * i] = false;\n          f[j] -= f[j * i];\n        }\n      }\n    }\n    return\
    \ f;\n  }\n\n  template <typename T>\n  std::vector<T> convolution_gcd(std::vector<T>\
    \ f, std::vector<T> g) {\n    const int N = f.size();\n    assert(f.size() ==\
    \ g.size());\n\n    std::vector<T> ret(N);\n    for (int i = 1; i < N; ++i) ret[i]\
    \ += f[i] + g[i];\n\n    f = divisor_zeta_transform(f);\n    g = divisor_zeta_transform(g);\n\
    \    for (int i = 0; i < N; ++i) f[i] *= g[i];\n    f = divisor_mobius_transform(f);\n\
    \    for (int i = 0; i < N; ++i) ret[i] += f[i];\n    return ret;\n  }\n}  //\
    \ namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Convolution/convolution_gcd.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Convolution/convolution_gcd.cpp
layout: document
title: Convolution (Index GCD)
---

## Operations

- `convolution_gcd(f, g)`
  - $h_k = \sum_{k = gcd(i, j)} f_i * g_j$

## Requirements

## Notes

## Problems

- [GCD Sum](https://www.codechef.com/problems/GCDSUM/)

## References

- [https://kazuma8128.hatenablog.com/entry/2018/07/29/231819](https://kazuma8128.hatenablog.com/entry/2018/07/29/231819)
- [https://noshi91.hatenablog.com/entry/2018/12/27/121649](https://noshi91.hatenablog.com/entry/2018/12/27/121649)
- [https://aprilganmo.hatenablog.com/entry/2020/07/24/190816](https://aprilganmo.hatenablog.com/entry/2020/07/24/190816)
