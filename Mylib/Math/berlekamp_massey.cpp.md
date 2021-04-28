---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/find_linear_recurrence/main.test.cpp
    title: test/yosupo-judge/find_linear_recurrence/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Math/berlekamp_massey.cpp\"\n#include <vector>\n\n\
    namespace haar_lib {\n  template <typename T>\n  std::vector<T> berlekamp_massey(const\
    \ std::vector<T> &s) {\n    const int N = s.size();\n\n    std::vector<T> C =\
    \ {1}, B = {1};\n    int L = 0, m = 1;\n    T b = 1;\n\n    for (int n = 0; n\
    \ < N; ++n) {\n      T d = s[n];\n      for (size_t i = 1; i < C.size(); ++i)\
    \ d += C[i] * s[n - i];\n\n      if (d == 0) {\n        m += 1;\n      } else\
    \ if (2 * L <= n) {\n        auto temp = C;\n        if (C.size() < B.size() +\
    \ m) C.resize(B.size() + m);\n        const T t = d / b;\n        for (int i =\
    \ 0; i < (int) B.size(); ++i) C[i + m] -= t * B[i];\n        L = n + 1 - L;\n\
    \        B = temp;\n        b = d;\n        m = 1;\n      } else {\n        if\
    \ (C.size() < B.size() + m) C.resize(B.size() + m);\n        const T t = d / b;\n\
    \        for (int i = 0; i < (int) B.size(); ++i) C[i + m] -= t * B[i];\n    \
    \    m += 1;\n      }\n    }\n\n    std::vector<T> ret(L);\n    for (int i = 0;\
    \ i < L; ++i) ret[i] = -C[i + 1];\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  std::vector<T> berlekamp_massey(const std::vector<T> &s) {\n    const\
    \ int N = s.size();\n\n    std::vector<T> C = {1}, B = {1};\n    int L = 0, m\
    \ = 1;\n    T b = 1;\n\n    for (int n = 0; n < N; ++n) {\n      T d = s[n];\n\
    \      for (size_t i = 1; i < C.size(); ++i) d += C[i] * s[n - i];\n\n      if\
    \ (d == 0) {\n        m += 1;\n      } else if (2 * L <= n) {\n        auto temp\
    \ = C;\n        if (C.size() < B.size() + m) C.resize(B.size() + m);\n       \
    \ const T t = d / b;\n        for (int i = 0; i < (int) B.size(); ++i) C[i + m]\
    \ -= t * B[i];\n        L = n + 1 - L;\n        B = temp;\n        b = d;\n  \
    \      m = 1;\n      } else {\n        if (C.size() < B.size() + m) C.resize(B.size()\
    \ + m);\n        const T t = d / b;\n        for (int i = 0; i < (int) B.size();\
    \ ++i) C[i + m] -= t * B[i];\n        m += 1;\n      }\n    }\n\n    std::vector<T>\
    \ ret(L);\n    for (int i = 0; i < L; ++i) ret[i] = -C[i + 1];\n\n    return ret;\n\
    \  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Math/berlekamp_massey.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/find_linear_recurrence/main.test.cpp
documentation_of: Mylib/Math/berlekamp_massey.cpp
layout: document
title: Berlekamp-Massey
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://en.wikipedia.org/wiki/Berlekamp%E2%80%93Massey_algorithm](https://en.wikipedia.org/wiki/Berlekamp%E2%80%93Massey_algorithm)
