---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Combinatorics/bell_number.cpp
    title: Bell number
  - icon: ':x:'
    path: Mylib/Combinatorics/bernoulli_number.cpp
    title: Bernoulli number
  - icon: ':x:'
    path: Mylib/Combinatorics/catalan_number.cpp
    title: Catalan number
  - icon: ':x:'
    path: Mylib/Combinatorics/stirling_number_second.cpp
    title: Stirling numbers of the second kind
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_5_G/main.test.cpp
    title: test/aoj/DPL_5_G/main.test.cpp
  - icon: ':x:'
    path: test/aoj/DPL_5_I/main.test.cpp
    title: test/aoj/DPL_5_I/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/bernoulli_number/main.test.cpp
    title: test/yosupo-judge/bernoulli_number/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/117/main.test.cpp
    title: test/yukicoder/117/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/660/main.test.cpp
    title: test/yukicoder/660/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/665/main.test.cpp
    title: test/yukicoder/665/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/factorial_table.cpp\"\n#include <cassert>\n\
    #include <cstdint>\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class factorial_table {\n  public:\n    using value_type = T;\n\n  private:\n\
    \    int N_;\n    std::vector<T> f_table_, if_table_;\n\n  public:\n    factorial_table()\
    \ {}\n    factorial_table(int N) : N_(N) {\n      f_table_.assign(N + 1, 1);\n\
    \      if_table_.assign(N + 1, 1);\n\n      for (int i = 1; i <= N; ++i) {\n \
    \       f_table_[i] = f_table_[i - 1] * i;\n      }\n\n      if_table_[N] = f_table_[N].inv();\n\
    \n      for (int i = N; --i >= 0;) {\n        if_table_[i] = if_table_[i + 1]\
    \ * (i + 1);\n      }\n    }\n\n    T factorial(int64_t i) const {\n      assert(0\
    \ <= i and i <= N_);\n      return f_table_[i];\n    }\n\n    T inv_factorial(int64_t\
    \ i) const {\n      assert(0 <= i and i <= N_);\n      return if_table_[i];\n\
    \    }\n\n    T P(int64_t n, int64_t k) const {\n      if (n < k or n < 0 or k\
    \ < 0) return 0;\n      return factorial(n) * inv_factorial(n - k);\n    }\n\n\
    \    T C(int64_t n, int64_t k) const {\n      if (n < k or n < 0 or k < 0) return\
    \ 0;\n      return P(n, k) * inv_factorial(k);\n    }\n\n    T H(int64_t n, int64_t\
    \ k) const {\n      if (n == 0 and k == 0) return 1;\n      return C(n + k - 1,\
    \ k);\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  class factorial_table {\n \
    \ public:\n    using value_type = T;\n\n  private:\n    int N_;\n    std::vector<T>\
    \ f_table_, if_table_;\n\n  public:\n    factorial_table() {}\n    factorial_table(int\
    \ N) : N_(N) {\n      f_table_.assign(N + 1, 1);\n      if_table_.assign(N + 1,\
    \ 1);\n\n      for (int i = 1; i <= N; ++i) {\n        f_table_[i] = f_table_[i\
    \ - 1] * i;\n      }\n\n      if_table_[N] = f_table_[N].inv();\n\n      for (int\
    \ i = N; --i >= 0;) {\n        if_table_[i] = if_table_[i + 1] * (i + 1);\n  \
    \    }\n    }\n\n    T factorial(int64_t i) const {\n      assert(0 <= i and i\
    \ <= N_);\n      return f_table_[i];\n    }\n\n    T inv_factorial(int64_t i)\
    \ const {\n      assert(0 <= i and i <= N_);\n      return if_table_[i];\n   \
    \ }\n\n    T P(int64_t n, int64_t k) const {\n      if (n < k or n < 0 or k <\
    \ 0) return 0;\n      return factorial(n) * inv_factorial(n - k);\n    }\n\n \
    \   T C(int64_t n, int64_t k) const {\n      if (n < k or n < 0 or k < 0) return\
    \ 0;\n      return P(n, k) * inv_factorial(k);\n    }\n\n    T H(int64_t n, int64_t\
    \ k) const {\n      if (n == 0 and k == 0) return 1;\n      return C(n + k - 1,\
    \ k);\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Combinatorics/factorial_table.cpp
  requiredBy:
  - Mylib/Combinatorics/bell_number.cpp
  - Mylib/Combinatorics/catalan_number.cpp
  - Mylib/Combinatorics/stirling_number_second.cpp
  - Mylib/Combinatorics/bernoulli_number.cpp
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/bernoulli_number/main.test.cpp
  - test/aoj/DPL_5_I/main.test.cpp
  - test/aoj/DPL_5_G/main.test.cpp
  - test/yukicoder/665/main.test.cpp
  - test/yukicoder/117/main.test.cpp
  - test/yukicoder/660/main.test.cpp
documentation_of: Mylib/Combinatorics/factorial_table.cpp
layout: document
title: Factorial table
---

## Operations

- `factorial_table(int N)`
	- $0!$ ~ $N!$とその逆数を計算する。
	- Time complexity $O(N)$
- `factorial(int i)` : return $i!$
- `inv_factorial(int i)` : return $\frac{1}{i!}$
- `P(int n, int k)` : return $_nP_k$
- `C(int n, int k)` : return $_nC_k$
- `H(int n, int k)` : return $_nH_k = _{n+k-1}C_k$

## Requirements

## Notes

## Problems

## References