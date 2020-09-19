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
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/bernoulli_number.cpp\"\n#include <vector>\n\
    #include <cstdint>\n#line 3 \"Mylib/Combinatorics/factorial_table.cpp\"\n#include\
    \ <cassert>\n#line 5 \"Mylib/Combinatorics/factorial_table.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  class factorial_table {\n  public:\n\
    \    using value_type = T;\n\n  private:\n    std::vector<T> f_table;\n    std::vector<T>\
    \ if_table;\n\n  public:\n    factorial_table(int N){\n      f_table.assign(N\
    \ + 1, 1);\n      if_table.assign(N + 1, 1);\n\n      for(int i = 1; i <= N; ++i){\n\
    \        f_table[i] = f_table[i - 1] * i;\n      }\n\n      if_table[N] = f_table[N].inv();\n\
    \n      for(int i = N; --i >= 0;){\n        if_table[i] = if_table[i + 1] * (i\
    \ + 1);\n      }\n    }\n\n    T factorial(int64_t i) const {\n      assert(i\
    \ < (int)f_table.size());\n      return f_table[i];\n    }\n\n    T inv_factorial(int64_t\
    \ i) const {\n      assert(i < (int)if_table.size());\n      return if_table[i];\n\
    \    }\n\n    T P(int64_t n, int64_t k) const {\n      if(n < k or n < 0 or k\
    \ < 0) return 0;\n      return factorial(n) * inv_factorial(n - k);\n    }\n\n\
    \    T C(int64_t n, int64_t k) const {\n      if(n < k or n < 0 or k < 0) return\
    \ 0;\n      return P(n, k) * inv_factorial(k);\n    }\n\n    T H(int64_t n, int64_t\
    \ k) const {\n      if(n == 0 and k == 0) return 1;\n      return C(n + k - 1,\
    \ k);\n    }\n  };\n}\n#line 5 \"Mylib/Combinatorics/bernoulli_number.cpp\"\n\n\
    namespace haar_lib {\n  template <typename Ft, typename T = typename Ft::value_type>\n\
    \  std::vector<T> bernoulli_number(int64_t n, const Ft &ft){\n    std::vector<T>\
    \ ret(n + 1);\n\n    ret[0] = 1;\n\n    for(int64_t i = 1; i <= n; ++i){\n   \
    \   for(int k = 0; k <= i - 1; ++k){\n        ret[i] += ft.C(i + 1, k) * ret[k];\n\
    \      }\n      ret[i] /= i + 1;\n      ret[i] = -ret[i];\n    }\n\n    return\
    \ ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cstdint>\n#include \"Mylib/Combinatorics/factorial_table.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Ft, typename T = typename Ft::value_type>\n\
    \  std::vector<T> bernoulli_number(int64_t n, const Ft &ft){\n    std::vector<T>\
    \ ret(n + 1);\n\n    ret[0] = 1;\n\n    for(int64_t i = 1; i <= n; ++i){\n   \
    \   for(int k = 0; k <= i - 1; ++k){\n        ret[i] += ft.C(i + 1, k) * ret[k];\n\
    \      }\n      ret[i] /= i + 1;\n      ret[i] = -ret[i];\n    }\n\n    return\
    \ ret;\n  }\n}\n"
  dependsOn:
  - Mylib/Combinatorics/factorial_table.cpp
  isVerificationFile: false
  path: Mylib/Combinatorics/bernoulli_number.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/665/main.test.cpp
documentation_of: Mylib/Combinatorics/bernoulli_number.cpp
layout: document
title: Bernoulli number
---

## Operations

- `bernoulli_number(Ft, int n)`
	- $B_0$ ~ $B_n$を列挙する。
	- Time complexity $O(N^2)$

## Requirements

## Notes

## Problems

## References

- [https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%8C%E3%83%BC%E3%82%A4%E6%95%B0](https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%8C%E3%83%BC%E3%82%A4%E6%95%B0)
