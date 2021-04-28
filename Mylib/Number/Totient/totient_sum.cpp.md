---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Number/Totient/totient_table.cpp
    title: Euler's totient function (Table)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/sum_of_totient_function/main.test.cpp
    title: test/yosupo-judge/sum_of_totient_function/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Totient/totient_sum.cpp\"\n#include <cmath>\n\
    #include <unordered_map>\n#include <vector>\n#line 2 \"Mylib/Number/Totient/totient_table.cpp\"\
    \n#include <numeric>\n#line 4 \"Mylib/Number/Totient/totient_table.cpp\"\n\nnamespace\
    \ haar_lib {\n  std::vector<int> totient_table(int n) {\n    std::vector<int>\
    \ ret(n + 1);\n    std::iota(ret.begin(), ret.end(), 0);\n\n    for (int i = 2;\
    \ i <= n; ++i) {\n      if (ret[i] == i) {\n        for (int j = i; j <= n; j\
    \ += i) {\n          ret[j] = ret[j] / i * (i - 1);\n        }\n      }\n    }\n\
    \n    return ret;\n  }\n}  // namespace haar_lib\n#line 6 \"Mylib/Number/Totient/totient_sum.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  T totient_sum(int64_t N)\
    \ {\n    const int64_t K = (int64_t) pow(N, 0.66);\n\n    std::vector<T> memo1(K\
    \ + 1);\n    auto table = totient_table(K);\n    T sum      = 0;\n    for (int\
    \ i = 1; i <= K; ++i) {\n      sum += table[i];\n      memo1[i] = sum;\n    }\n\
    \n    std::unordered_map<int64_t, T> memo2;\n\n    auto f =\n        [&](auto\
    \ &f, int64_t x) -> T {\n      if (x <= K) return memo1[x];\n      if (memo2.find(x)\
    \ != memo2.end()) return memo2[x];\n\n      T ret = 0;\n\n      const int64_t\
    \ s = sqrt(x);\n\n      for (int i = 2; i <= s; ++i) {\n        if (x / i <= s)\
    \ continue;\n        ret -= f(f, x / i);\n      }\n\n      for (int i = 1; i <=\
    \ s; ++i) {\n        ret -= f(f, i) * (x / i - x / (i + 1));\n      }\n\n    \
    \  ret += (T) x * (x + 1) / 2;\n\n      return memo2[x] = ret;\n    };\n\n   \
    \ return f(f, N);\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cmath>\n#include <unordered_map>\n#include <vector>\n\
    #include \"Mylib/Number/Totient/totient_table.cpp\"\n\nnamespace haar_lib {\n\
    \  template <typename T>\n  T totient_sum(int64_t N) {\n    const int64_t K =\
    \ (int64_t) pow(N, 0.66);\n\n    std::vector<T> memo1(K + 1);\n    auto table\
    \ = totient_table(K);\n    T sum      = 0;\n    for (int i = 1; i <= K; ++i) {\n\
    \      sum += table[i];\n      memo1[i] = sum;\n    }\n\n    std::unordered_map<int64_t,\
    \ T> memo2;\n\n    auto f =\n        [&](auto &f, int64_t x) -> T {\n      if\
    \ (x <= K) return memo1[x];\n      if (memo2.find(x) != memo2.end()) return memo2[x];\n\
    \n      T ret = 0;\n\n      const int64_t s = sqrt(x);\n\n      for (int i = 2;\
    \ i <= s; ++i) {\n        if (x / i <= s) continue;\n        ret -= f(f, x / i);\n\
    \      }\n\n      for (int i = 1; i <= s; ++i) {\n        ret -= f(f, i) * (x\
    \ / i - x / (i + 1));\n      }\n\n      ret += (T) x * (x + 1) / 2;\n\n      return\
    \ memo2[x] = ret;\n    };\n\n    return f(f, N);\n  }\n}  // namespace haar_lib\n"
  dependsOn:
  - Mylib/Number/Totient/totient_table.cpp
  isVerificationFile: false
  path: Mylib/Number/Totient/totient_sum.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/sum_of_totient_function/main.test.cpp
documentation_of: Mylib/Number/Totient/totient_sum.cpp
layout: document
title: Sum of totient function
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://yukicoder.me/wiki/sum_totient](https://yukicoder.me/wiki/sum_totient)
