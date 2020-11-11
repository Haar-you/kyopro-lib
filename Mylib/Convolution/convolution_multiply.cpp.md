---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Number/Mod/mod_pow.cpp
    title: Mod pow
  - icon: ':question:'
    path: Mylib/Number/Prime/primitive_root.cpp
    title: Primitive root
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/931/main.test.cpp
    title: test/yukicoder/931/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Convolution/convolution_multiply.cpp\"\n#include <vector>\n\
    #line 2 \"Mylib/Number/Mod/mod_pow.cpp\"\n#include <cstdint>\n\nnamespace haar_lib\
    \ {\n  constexpr int64_t mod_pow(int64_t n, int64_t p, int64_t m){\n    int64_t\
    \ ret = 1;\n    while(p > 0){\n      if(p & 1) (ret *= n) %= m;\n      (n *= n)\
    \ %= m;\n      p >>= 1;\n    }\n    return ret;\n  }\n}\n#line 3 \"Mylib/Number/Prime/primitive_root.cpp\"\
    \n\nnamespace haar_lib {\n  constexpr int primitive_root(int p){\n    int pf[30]\
    \ = {};\n    int k = 0;\n    {\n      int n = p - 1;\n      for(int64_t i = 2;\
    \ i * i <= p; ++i){\n        if(n % i == 0){\n          pf[k++] = i;\n       \
    \   while(n % i == 0) n /= i;\n        }\n      }\n      if(n != 1)\n        pf[k++]\
    \ = n;\n    }\n\n    for(int g = 2; g <= p; ++g){\n      bool ok = true;\n   \
    \   for(int i = 0; i < k; ++i){\n        if(mod_pow(g, (p - 1) / pf[i], p) ==\
    \ 1){\n          ok = false;\n          break;\n        }\n      }\n\n      if(not\
    \ ok) continue;\n\n      return g;\n    }\n    return -1;\n  }\n}\n#line 4 \"\
    Mylib/Convolution/convolution_multiply.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T, const auto &convolve>\n  auto convolution_multiply(const std::vector<T>\
    \ &A, const std::vector<T> &B, int P){\n    const int p_root = primitive_root(P);\n\
    \n    std::vector<int> index(P);\n\n    {\n      int64_t s = 1;\n\n      for(int\
    \ i = 0; i < P; ++i){\n        index[s] = i;\n        s *= p_root;\n        if(s\
    \ >= P) s %= P;\n      }\n    }\n\n    std::vector<T> a(P), b(P);\n    for(int\
    \ i = 0; i < (int)A.size(); ++i) a[index[i % P]] = A[i];\n    for(int i = 0; i\
    \ < (int)B.size(); ++i) b[index[i % P]] = B[i];\n\n    auto c = convolve(a, b);\n\
    \    std::vector<T> ret(P);\n\n    {\n      int64_t s = 1;\n\n      for(auto x\
    \ : c){\n        ret[s] += x;\n        s *= p_root;\n        if(s >= P) s %= P;\n\
    \      }\n    }\n\n    return ret;\n  }\n};\n"
  code: "#pragma once\n#include <vector>\n#include \"Mylib/Number/Prime/primitive_root.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, const auto &convolve>\n  auto\
    \ convolution_multiply(const std::vector<T> &A, const std::vector<T> &B, int P){\n\
    \    const int p_root = primitive_root(P);\n\n    std::vector<int> index(P);\n\
    \n    {\n      int64_t s = 1;\n\n      for(int i = 0; i < P; ++i){\n        index[s]\
    \ = i;\n        s *= p_root;\n        if(s >= P) s %= P;\n      }\n    }\n\n \
    \   std::vector<T> a(P), b(P);\n    for(int i = 0; i < (int)A.size(); ++i) a[index[i\
    \ % P]] = A[i];\n    for(int i = 0; i < (int)B.size(); ++i) b[index[i % P]] =\
    \ B[i];\n\n    auto c = convolve(a, b);\n    std::vector<T> ret(P);\n\n    {\n\
    \      int64_t s = 1;\n\n      for(auto x : c){\n        ret[s] += x;\n      \
    \  s *= p_root;\n        if(s >= P) s %= P;\n      }\n    }\n\n    return ret;\n\
    \  }\n};\n"
  dependsOn:
  - Mylib/Number/Prime/primitive_root.cpp
  - Mylib/Number/Mod/mod_pow.cpp
  isVerificationFile: false
  path: Mylib/Convolution/convolution_multiply.cpp
  requiredBy: []
  timestamp: '2020-11-09 03:20:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/931/main.test.cpp
documentation_of: Mylib/Convolution/convolution_multiply.cpp
layout: document
title: Convolution (Index multiplication mod P)
---

## Operations

- `convolution_multiply(f, g, P)`
  - `P`は素数
  - $h_k = \sum_{k = i * j \pmod{P}} f_i * g_j$

## Requirements

## Notes

## Problems

## References

- [https://drken1215.hatenablog.com/entry/2020/11/04/172300](https://drken1215.hatenablog.com/entry/2020/11/04/172300)
