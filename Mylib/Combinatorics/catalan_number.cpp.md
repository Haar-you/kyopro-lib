---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Combinatorics/factorial_table.cpp
    title: Factorial table
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/660/main.test.cpp
    title: test/yukicoder/660/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/catalan_number.cpp\"\n#include <cstdint>\n\
    #line 2 \"Mylib/Combinatorics/factorial_table.cpp\"\n#include <vector>\n#include\
    \ <cassert>\n#line 5 \"Mylib/Combinatorics/factorial_table.cpp\"\n\nnamespace\
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
    \  };\n}\n#line 4 \"Mylib/Combinatorics/catalan_number.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <const auto &ft>\n  auto catalan_number(int64_t n){\n    return\
    \ ft.C(2 * n, n) - ft.C(2 * n, n - 1);\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include \"Mylib/Combinatorics/factorial_table.cpp\"\
    \n\nnamespace haar_lib {\n  template <const auto &ft>\n  auto catalan_number(int64_t\
    \ n){\n    return ft.C(2 * n, n) - ft.C(2 * n, n - 1);\n  }\n}\n"
  dependsOn:
  - Mylib/Combinatorics/factorial_table.cpp
  isVerificationFile: false
  path: Mylib/Combinatorics/catalan_number.cpp
  requiredBy: []
  timestamp: '2020-10-10 12:47:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/660/main.test.cpp
documentation_of: Mylib/Combinatorics/catalan_number.cpp
layout: document
title: Catalan number
---

## Operations

- `catalan_number(Ft, int n)`
	-  $c_0 = 1, c_{n+1} = \sum_{i=0}^n c_i * c_{n-i}$ を満たす数列の第n項を返す。

## Requirements

## Notes

## Problems

- [KUPC2019 D - Maximin Game](https://atcoder.jp/contests/kupc2019/tasks/kupc2019_d)
- [yukicoder No.660 家を通り過ぎないランダムウォーク問題](https://yukicoder.me/problems/no/660)

## References

- [https://en.wikipedia.org/wiki/Catalan_number](https://en.wikipedia.org/wiki/Catalan_number)
- [https://mathtrain.jp/catalan](https://mathtrain.jp/catalan)
