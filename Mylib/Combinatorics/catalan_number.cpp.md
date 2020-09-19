---
data:
  _extendedDependsOn:
  - icon: ':x:'
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
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/catalan_number.cpp\"\n#include <cstdint>\n\
    #line 2 \"Mylib/Combinatorics/factorial_table.cpp\"\n#include <vector>\n#include\
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
    \ k);\n    }\n  };\n}\n#line 4 \"Mylib/Combinatorics/catalan_number.cpp\"\n\n\
    namespace haar_lib {\n  template <typename Ft, typename T = typename Ft::value_type>\n\
    \  T catalan_number(int64_t n, const Ft &ft){\n    return ft.C(2 * n, n) - ft.C(2\
    \ * n, n - 1);\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include \"Mylib/Combinatorics/factorial_table.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Ft, typename T = typename Ft::value_type>\n\
    \  T catalan_number(int64_t n, const Ft &ft){\n    return ft.C(2 * n, n) - ft.C(2\
    \ * n, n - 1);\n  }\n}\n"
  dependsOn:
  - Mylib/Combinatorics/factorial_table.cpp
  isVerificationFile: false
  path: Mylib/Combinatorics/catalan_number.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
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
