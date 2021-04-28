---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Combinatorics/factorial_table.cpp
    title: Factorial table
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/665/main.test.cpp
    title: test/yukicoder/665/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/bernoulli_number.cpp\"\n#include <cstdint>\n\
    #include <vector>\n#line 2 \"Mylib/Combinatorics/factorial_table.cpp\"\n#include\
    \ <cassert>\n#line 5 \"Mylib/Combinatorics/factorial_table.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  class factorial_table {\n  public:\n\
    \    using value_type = T;\n\n  private:\n    int N_;\n    std::vector<T> f_table_,\
    \ if_table_;\n\n  public:\n    factorial_table() {}\n    factorial_table(int N)\
    \ : N_(N) {\n      f_table_.assign(N + 1, 1);\n      if_table_.assign(N + 1, 1);\n\
    \n      for (int i = 1; i <= N; ++i) {\n        f_table_[i] = f_table_[i - 1]\
    \ * i;\n      }\n\n      if_table_[N] = f_table_[N].inv();\n\n      for (int i\
    \ = N; --i >= 0;) {\n        if_table_[i] = if_table_[i + 1] * (i + 1);\n    \
    \  }\n    }\n\n    T factorial(int64_t i) const {\n      assert(0 <= i and i <=\
    \ N_);\n      return f_table_[i];\n    }\n\n    T inv_factorial(int64_t i) const\
    \ {\n      assert(0 <= i and i <= N_);\n      return if_table_[i];\n    }\n\n\
    \    T P(int64_t n, int64_t k) const {\n      if (n < k or n < 0 or k < 0) return\
    \ 0;\n      return factorial(n) * inv_factorial(n - k);\n    }\n\n    T C(int64_t\
    \ n, int64_t k) const {\n      if (n < k or n < 0 or k < 0) return 0;\n      return\
    \ P(n, k) * inv_factorial(k);\n    }\n\n    T H(int64_t n, int64_t k) const {\n\
    \      if (n == 0 and k == 0) return 1;\n      return C(n + k - 1, k);\n    }\n\
    \  };\n}  // namespace haar_lib\n#line 5 \"Mylib/Combinatorics/bernoulli_number.cpp\"\
    \n\nnamespace haar_lib {\n  template <\n      const auto &ft,\n      typename\
    \ T = typename std::remove_reference_t<decltype(ft)>::value_type>\n  std::vector<T>\
    \ bernoulli_number(int n) {\n    std::vector<T> ret(n + 1);\n\n    ret[0] = 1;\n\
    \n    for (int64_t i = 1; i <= n; ++i) {\n      for (int k = 0; k <= i - 1; ++k)\
    \ {\n        ret[i] += ft.C(i + 1, k) * ret[k];\n      }\n      ret[i] /= i +\
    \ 1;\n      ret[i] = -ret[i];\n    }\n\n    return ret;\n  }\n}  // namespace\
    \ haar_lib\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\n#include \"Mylib/Combinatorics/factorial_table.cpp\"\
    \n\nnamespace haar_lib {\n  template <\n      const auto &ft,\n      typename\
    \ T = typename std::remove_reference_t<decltype(ft)>::value_type>\n  std::vector<T>\
    \ bernoulli_number(int n) {\n    std::vector<T> ret(n + 1);\n\n    ret[0] = 1;\n\
    \n    for (int64_t i = 1; i <= n; ++i) {\n      for (int k = 0; k <= i - 1; ++k)\
    \ {\n        ret[i] += ft.C(i + 1, k) * ret[k];\n      }\n      ret[i] /= i +\
    \ 1;\n      ret[i] = -ret[i];\n    }\n\n    return ret;\n  }\n}  // namespace\
    \ haar_lib\n"
  dependsOn:
  - Mylib/Combinatorics/factorial_table.cpp
  isVerificationFile: false
  path: Mylib/Combinatorics/bernoulli_number.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/665/main.test.cpp
documentation_of: Mylib/Combinatorics/bernoulli_number.cpp
layout: document
title: Bernoulli number
---

## Operations

- `bernoulli_number<ft>(int n) -> [T]`
	- $B_0$ ~ $B_n$を列挙する。
	- Time complexity $O(N^2)$

## Requirements

## Notes

## Problems

## References

- [https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%8C%E3%83%BC%E3%82%A4%E6%95%B0](https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%8C%E3%83%BC%E3%82%A4%E6%95%B0)
