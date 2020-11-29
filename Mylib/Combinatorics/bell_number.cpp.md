---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Combinatorics/factorial_table.cpp
    title: Factorial table
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_G/main.test.cpp
    title: test/aoj/DPL_5_G/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/bell_number.cpp\"\n#include <vector>\n\
    #include <algorithm>\n#line 3 \"Mylib/Combinatorics/factorial_table.cpp\"\n#include\
    \ <cassert>\n#include <cstdint>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class factorial_table {\n  public:\n    using value_type = T;\n\n  private:\n\
    \    int N_;\n    std::vector<T> f_table_, if_table_;\n\n  public:\n    factorial_table(){}\n\
    \    factorial_table(int N): N_(N){\n      f_table_.assign(N + 1, 1);\n      if_table_.assign(N\
    \ + 1, 1);\n\n      for(int i = 1; i <= N; ++i){\n        f_table_[i] = f_table_[i\
    \ - 1] * i;\n      }\n\n      if_table_[N] = f_table_[N].inv();\n\n      for(int\
    \ i = N; --i >= 0;){\n        if_table_[i] = if_table_[i + 1] * (i + 1);\n   \
    \   }\n    }\n\n    T factorial(int64_t i) const {\n      assert(0 <= i and i\
    \ <= N_);\n      return f_table_[i];\n    }\n\n    T inv_factorial(int64_t i)\
    \ const {\n      assert(0 <= i and i <= N_);\n      return if_table_[i];\n   \
    \ }\n\n    T P(int64_t n, int64_t k) const {\n      if(n < k or n < 0 or k < 0)\
    \ return 0;\n      return factorial(n) * inv_factorial(n - k);\n    }\n\n    T\
    \ C(int64_t n, int64_t k) const {\n      if(n < k or n < 0 or k < 0) return 0;\n\
    \      return P(n, k) * inv_factorial(k);\n    }\n\n    T H(int64_t n, int64_t\
    \ k) const {\n      if(n == 0 and k == 0) return 1;\n      return C(n + k - 1,\
    \ k);\n    }\n  };\n}\n#line 5 \"Mylib/Combinatorics/bell_number.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <const auto &ft>\n  auto bell_number(int n, int k){\n\
    \    using T = typename std::remove_reference_t<decltype(ft)>::value_type;\n \
    \   if(n == 0) return T(1);\n\n    k = std::min(k, n);\n\n    std::vector<T> t(k,\
    \ 1);\n\n    for(int i = 1; i < k; ++i){\n      if(i % 2 == 0) t[i] = t[i - 1]\
    \ + ft.inv_factorial(i);\n      else t[i] = t[i - 1] - ft.inv_factorial(i);\n\
    \    }\n\n    T ret = 0;\n    for(int i = 1; i <= k; ++i){\n      ret += t[k -\
    \ i] * T::pow(i, n) * ft.inv_factorial(i);\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include \"Mylib/Combinatorics/factorial_table.cpp\"\
    \n\nnamespace haar_lib {\n  template <const auto &ft>\n  auto bell_number(int\
    \ n, int k){\n    using T = typename std::remove_reference_t<decltype(ft)>::value_type;\n\
    \    if(n == 0) return T(1);\n\n    k = std::min(k, n);\n\n    std::vector<T>\
    \ t(k, 1);\n\n    for(int i = 1; i < k; ++i){\n      if(i % 2 == 0) t[i] = t[i\
    \ - 1] + ft.inv_factorial(i);\n      else t[i] = t[i - 1] - ft.inv_factorial(i);\n\
    \    }\n\n    T ret = 0;\n    for(int i = 1; i <= k; ++i){\n      ret += t[k -\
    \ i] * T::pow(i, n) * ft.inv_factorial(i);\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/Combinatorics/factorial_table.cpp
  isVerificationFile: false
  path: Mylib/Combinatorics/bell_number.cpp
  requiredBy: []
  timestamp: '2020-11-04 18:00:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_G/main.test.cpp
documentation_of: Mylib/Combinatorics/bell_number.cpp
layout: document
title: Bell number
---

## Operations

- `bell_number<ft>(int n, int k) -> T`
	- Time complexity $O(\min(k, n)\ \log n)$

## Requirements

## Notes

## Problems

## References

- [https://mathtrain.jp/zensya](https://mathtrain.jp/zensya)
- [https://mathtrain.jp/twelveway](https://mathtrain.jp/twelveway)
- [https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E6%95%B0](https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E6%95%B0)
