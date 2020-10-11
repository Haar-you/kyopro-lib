---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Combinatorics/factorial_table.cpp
    title: Factorial table
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_I/main.test.cpp
    title: test/aoj/DPL_5_I/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/stirling_number_second.cpp\"\n#include\
    \ <cstdint>\n#line 2 \"Mylib/Combinatorics/factorial_table.cpp\"\n#include <vector>\n\
    #include <cassert>\n#line 5 \"Mylib/Combinatorics/factorial_table.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  class factorial_table {\n  public:\n\
    \    using value_type = T;\n\n  private:\n    int N_;\n    std::vector<T> f_table_,\
    \ if_table_;\n\n  public:\n    factorial_table(){}\n    factorial_table(int N):\
    \ N_(N){\n      f_table_.assign(N + 1, 1);\n      if_table_.assign(N + 1, 1);\n\
    \n      for(int i = 1; i <= N; ++i){\n        f_table_[i] = f_table_[i - 1] *\
    \ i;\n      }\n\n      if_table_[N] = f_table_[N].inv();\n\n      for(int i =\
    \ N; --i >= 0;){\n        if_table_[i] = if_table_[i + 1] * (i + 1);\n      }\n\
    \    }\n\n    T factorial(int64_t i) const {\n      assert(0 <= i and i <= N_);\n\
    \      return f_table_[i];\n    }\n\n    T inv_factorial(int64_t i) const {\n\
    \      assert(0 <= i and i <= N_);\n      return if_table_[i];\n    }\n\n    T\
    \ P(int64_t n, int64_t k) const {\n      if(n < k or n < 0 or k < 0) return 0;\n\
    \      return factorial(n) * inv_factorial(n - k);\n    }\n\n    T C(int64_t n,\
    \ int64_t k) const {\n      if(n < k or n < 0 or k < 0) return 0;\n      return\
    \ P(n, k) * inv_factorial(k);\n    }\n\n    T H(int64_t n, int64_t k) const {\n\
    \      if(n == 0 and k == 0) return 1;\n      return C(n + k - 1, k);\n    }\n\
    \  };\n}\n#line 4 \"Mylib/Combinatorics/stirling_number_second.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <const auto &ft>\n  auto stirling_number_of_second_kind(int64_t\
    \ n, int64_t k){\n    using T = typename std::remove_reference_t<decltype(ft)>::value_type;\n\
    \n    if(n == 0 and k == 0) return T(1);\n\n    T ret = 0;\n    for(int i = 1;\
    \ i <= k; ++i){\n      if((k - i) % 2 == 0) ret += ft.C(k, i) * T::pow(i, n);\n\
    \      else ret -= ft.C(k, i) * T::pow(i, n);\n    }\n    ret *= ft.inv_factorial(k);\n\
    \    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include \"Mylib/Combinatorics/factorial_table.cpp\"\
    \n\nnamespace haar_lib {\n  template <const auto &ft>\n  auto stirling_number_of_second_kind(int64_t\
    \ n, int64_t k){\n    using T = typename std::remove_reference_t<decltype(ft)>::value_type;\n\
    \n    if(n == 0 and k == 0) return T(1);\n\n    T ret = 0;\n    for(int i = 1;\
    \ i <= k; ++i){\n      if((k - i) % 2 == 0) ret += ft.C(k, i) * T::pow(i, n);\n\
    \      else ret -= ft.C(k, i) * T::pow(i, n);\n    }\n    ret *= ft.inv_factorial(k);\n\
    \    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/Combinatorics/factorial_table.cpp
  isVerificationFile: false
  path: Mylib/Combinatorics/stirling_number_second.cpp
  requiredBy: []
  timestamp: '2020-10-10 12:47:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_I/main.test.cpp
documentation_of: Mylib/Combinatorics/stirling_number_second.cpp
layout: document
title: Stirling numbers of the second kind
---

## Operations

- `stirling_number(Ft, int n, int k)`
	- n個の区別するボールをk個の区別しない箱に分配する(但し、すべての箱には1つ以上のボールが入る)ような方法の総数。
	- Time complexity $O(k\log n)$

## Requirements

## Notes

## Problems

## References

- [https://drken1215.hatenablog.com/entry/2018/02/01/200628](https://drken1215.hatenablog.com/entry/2018/02/01/200628)
