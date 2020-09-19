---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Combinatorics/bernoulli_number.cpp
    title: Bernoulli number
  - icon: ':x:'
    path: Mylib/Combinatorics/bell_number.cpp
    title: Bell number
  - icon: ':x:'
    path: Mylib/Combinatorics/catalan_number.cpp
    title: Catalan number
  - icon: ':x:'
    path: Mylib/Combinatorics/stirling_number_second.cpp
    title: Stirling numbers of the second kind
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_5_I/main.test.cpp
    title: test/aoj/DPL_5_I/main.test.cpp
  - icon: ':x:'
    path: test/aoj/DPL_5_G/main.test.cpp
    title: test/aoj/DPL_5_G/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/bernoulli_number/main.test.cpp
    title: test/yosupo-judge/bernoulli_number/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/660/main.test.cpp
    title: test/yukicoder/660/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/665/main.test.cpp
    title: test/yukicoder/665/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/117/main.test.cpp
    title: test/yukicoder/117/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/factorial_table.cpp\"\n#include <vector>\n\
    #include <cassert>\n#include <cstdint>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class factorial_table {\n  public:\n    using value_type = T;\n\n  private:\n\
    \    std::vector<T> f_table;\n    std::vector<T> if_table;\n\n  public:\n    factorial_table(int\
    \ N){\n      f_table.assign(N + 1, 1);\n      if_table.assign(N + 1, 1);\n\n \
    \     for(int i = 1; i <= N; ++i){\n        f_table[i] = f_table[i - 1] * i;\n\
    \      }\n\n      if_table[N] = f_table[N].inv();\n\n      for(int i = N; --i\
    \ >= 0;){\n        if_table[i] = if_table[i + 1] * (i + 1);\n      }\n    }\n\n\
    \    T factorial(int64_t i) const {\n      assert(i < (int)f_table.size());\n\
    \      return f_table[i];\n    }\n\n    T inv_factorial(int64_t i) const {\n \
    \     assert(i < (int)if_table.size());\n      return if_table[i];\n    }\n\n\
    \    T P(int64_t n, int64_t k) const {\n      if(n < k or n < 0 or k < 0) return\
    \ 0;\n      return factorial(n) * inv_factorial(n - k);\n    }\n\n    T C(int64_t\
    \ n, int64_t k) const {\n      if(n < k or n < 0 or k < 0) return 0;\n      return\
    \ P(n, k) * inv_factorial(k);\n    }\n\n    T H(int64_t n, int64_t k) const {\n\
    \      if(n == 0 and k == 0) return 1;\n      return C(n + k - 1, k);\n    }\n\
    \  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n#include <cstdint>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  class factorial_table {\n \
    \ public:\n    using value_type = T;\n\n  private:\n    std::vector<T> f_table;\n\
    \    std::vector<T> if_table;\n\n  public:\n    factorial_table(int N){\n    \
    \  f_table.assign(N + 1, 1);\n      if_table.assign(N + 1, 1);\n\n      for(int\
    \ i = 1; i <= N; ++i){\n        f_table[i] = f_table[i - 1] * i;\n      }\n\n\
    \      if_table[N] = f_table[N].inv();\n\n      for(int i = N; --i >= 0;){\n \
    \       if_table[i] = if_table[i + 1] * (i + 1);\n      }\n    }\n\n    T factorial(int64_t\
    \ i) const {\n      assert(i < (int)f_table.size());\n      return f_table[i];\n\
    \    }\n\n    T inv_factorial(int64_t i) const {\n      assert(i < (int)if_table.size());\n\
    \      return if_table[i];\n    }\n\n    T P(int64_t n, int64_t k) const {\n \
    \     if(n < k or n < 0 or k < 0) return 0;\n      return factorial(n) * inv_factorial(n\
    \ - k);\n    }\n\n    T C(int64_t n, int64_t k) const {\n      if(n < k or n <\
    \ 0 or k < 0) return 0;\n      return P(n, k) * inv_factorial(k);\n    }\n\n \
    \   T H(int64_t n, int64_t k) const {\n      if(n == 0 and k == 0) return 1;\n\
    \      return C(n + k - 1, k);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Combinatorics/factorial_table.cpp
  requiredBy:
  - Mylib/Combinatorics/bernoulli_number.cpp
  - Mylib/Combinatorics/bell_number.cpp
  - Mylib/Combinatorics/catalan_number.cpp
  - Mylib/Combinatorics/stirling_number_second.cpp
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DPL_5_I/main.test.cpp
  - test/aoj/DPL_5_G/main.test.cpp
  - test/yosupo-judge/bernoulli_number/main.test.cpp
  - test/yukicoder/660/main.test.cpp
  - test/yukicoder/665/main.test.cpp
  - test/yukicoder/117/main.test.cpp
documentation_of: Mylib/Combinatorics/factorial_table.cpp
layout: document
title: Factorial table
---

## Operations

- `FactorialTable(int N)`
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
