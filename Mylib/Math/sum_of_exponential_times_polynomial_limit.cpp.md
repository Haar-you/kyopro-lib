---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/sum_of_exponential_times_polynomial_limit/main.test.cpp
    title: test/yosupo-judge/sum_of_exponential_times_polynomial_limit/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Math/sum_of_exponential_times_polynomial_limit.cpp\"\
    \n#include <cstdint>\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  T sum_of_exponential_times_polynomial_limit(int64_t r, int d) {\n    T\
    \ ret   = 0;\n    T r_pow = 1;\n    int m   = T::mod();\n\n    std::vector<T>\
    \ s(d + 1);\n    std::vector<T> invs(d + 2);\n    invs[1] = 1;\n\n    for (int\
    \ i = 2; i <= d + 1; ++i) {\n      invs[i] = (m / i) * (m - invs[m % i]);\n  \
    \  }\n\n    for (int i = 0; i <= d; ++i) {\n      if (i > 0) s[i] += s[i - 1];\n\
    \      s[i] += T::pow(i, d) * r_pow;\n      r_pow *= r;\n    }\n\n    T t = 1;\n\
    \    for (int i = 0; i <= d; ++i) {\n      ret += t * s[d - i];\n      t *= invs[i\
    \ + 1] * (-r) * (d + 1 - i);\n    }\n\n    ret /= T::pow(1 - r, d + 1);\n\n  \
    \  return ret;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  T sum_of_exponential_times_polynomial_limit(int64_t\
    \ r, int d) {\n    T ret   = 0;\n    T r_pow = 1;\n    int m   = T::mod();\n\n\
    \    std::vector<T> s(d + 1);\n    std::vector<T> invs(d + 2);\n    invs[1] =\
    \ 1;\n\n    for (int i = 2; i <= d + 1; ++i) {\n      invs[i] = (m / i) * (m -\
    \ invs[m % i]);\n    }\n\n    for (int i = 0; i <= d; ++i) {\n      if (i > 0)\
    \ s[i] += s[i - 1];\n      s[i] += T::pow(i, d) * r_pow;\n      r_pow *= r;\n\
    \    }\n\n    T t = 1;\n    for (int i = 0; i <= d; ++i) {\n      ret += t * s[d\
    \ - i];\n      t *= invs[i + 1] * (-r) * (d + 1 - i);\n    }\n\n    ret /= T::pow(1\
    \ - r, d + 1);\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Math/sum_of_exponential_times_polynomial_limit.cpp
  requiredBy: []
  timestamp: '2021-05-10 06:09:59+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/sum_of_exponential_times_polynomial_limit/main.test.cpp
documentation_of: Mylib/Math/sum_of_exponential_times_polynomial_limit.cpp
layout: document
title: Sum of exponential times polynomial limit (\sum_{i=0}^{\infty} r^i i^d)
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://kyopro-friends.hatenablog.com/entry/2020/03/11/073122](https://kyopro-friends.hatenablog.com/entry/2020/03/11/073122)
