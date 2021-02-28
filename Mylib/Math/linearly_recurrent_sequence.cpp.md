---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/kth_term_of_linearly_recurrent_sequence/main.test.cpp
    title: test/yosupo-judge/kth_term_of_linearly_recurrent_sequence/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Math/linearly_recurrent_sequence.cpp\"\n#include <cassert>\n\
    #include <vector>\n#include <cstdint>\n\nnamespace haar_lib {\n  template <typename\
    \ T, auto &convolve>\n  T linearly_recurrent_sequence(const std::vector<T> &a,\
    \ const std::vector<T> &c, int64_t k){\n    assert(a.size() == c.size());\n\n\
    \    const int d = a.size();\n\n    std::vector<T> Q(d + 1);\n    Q[0] = 1;\n\
    \    for(int i = 0; i < d; ++i) Q[d - i] = -c[i];\n\n    std::vector<T> P = convolve(a,\
    \ Q);\n    P.resize(d);\n\n    while(k > 0){\n      auto q = Q;\n      for(size_t\
    \ i = 1; i < q.size(); i += 2) q[i] = -q[i];\n      auto U = convolve(P, q);\n\
    \      auto A = convolve(Q, q);\n\n      if(k % 2 == 0){\n        for(int i =\
    \ 0; i < d; ++i) P[i] = i * 2 < (int)U.size() ? U[i * 2] : 0;\n      }else{\n\
    \        for(int i = 0; i < d; ++i) P[i] = i * 2 + 1 < (int)U.size() ? U[i * 2\
    \ + 1] : 0;\n      }\n\n      for(int i = 0; i <= d; ++i) Q[i] = i * 2 < (int)A.size()\
    \ ? A[i * 2] : 0;\n\n      k >>= 1;\n    }\n\n    return P[0];\n  }\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include <cstdint>\n\
    \nnamespace haar_lib {\n  template <typename T, auto &convolve>\n  T linearly_recurrent_sequence(const\
    \ std::vector<T> &a, const std::vector<T> &c, int64_t k){\n    assert(a.size()\
    \ == c.size());\n\n    const int d = a.size();\n\n    std::vector<T> Q(d + 1);\n\
    \    Q[0] = 1;\n    for(int i = 0; i < d; ++i) Q[d - i] = -c[i];\n\n    std::vector<T>\
    \ P = convolve(a, Q);\n    P.resize(d);\n\n    while(k > 0){\n      auto q = Q;\n\
    \      for(size_t i = 1; i < q.size(); i += 2) q[i] = -q[i];\n      auto U = convolve(P,\
    \ q);\n      auto A = convolve(Q, q);\n\n      if(k % 2 == 0){\n        for(int\
    \ i = 0; i < d; ++i) P[i] = i * 2 < (int)U.size() ? U[i * 2] : 0;\n      }else{\n\
    \        for(int i = 0; i < d; ++i) P[i] = i * 2 + 1 < (int)U.size() ? U[i * 2\
    \ + 1] : 0;\n      }\n\n      for(int i = 0; i <= d; ++i) Q[i] = i * 2 < (int)A.size()\
    \ ? A[i * 2] : 0;\n\n      k >>= 1;\n    }\n\n    return P[0];\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Math/linearly_recurrent_sequence.cpp
  requiredBy: []
  timestamp: '2021-02-28 17:34:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/kth_term_of_linearly_recurrent_sequence/main.test.cpp
documentation_of: Mylib/Math/linearly_recurrent_sequence.cpp
layout: document
title: Kth term of linearly recurrent sequence
---

## Operations

$a_i \equiv \sum_{j=0}^{d - 1}c_j a_{i - d + j}$を満たす数列aの$a_0 \ldots a_{d-1}$と係数$c_0 \ldots c_{d-1}$から$a_n$を求める。

## Requirements

## Notes

## Problems

## References

- [https://arxiv.org/abs/2008.08822](https://arxiv.org/abs/2008.08822)
