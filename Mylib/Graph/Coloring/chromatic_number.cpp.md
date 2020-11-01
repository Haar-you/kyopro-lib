---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Number/Mod/mod_pow.cpp
    title: Mod pow
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2136/main.test.cpp
    title: test/aoj/2136/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/Coloring/chromatic_number.cpp\"\n#include <vector>\n\
    #include <cstdint>\n#include <cmath>\n#line 3 \"Mylib/Number/Mod/mod_pow.cpp\"\
    \n\nnamespace haar_lib {\n  constexpr int64_t mod_pow(int64_t n, int64_t p, int64_t\
    \ m){\n    int64_t ret = 1;\n    while(p > 0){\n      if(p & 1) (ret *= n) %=\
    \ m;\n      (n *= n) %= m;\n      p >>= 1;\n    }\n    return ret;\n  }\n}\n#line\
    \ 6 \"Mylib/Graph/Coloring/chromatic_number.cpp\"\n\nnamespace haar_lib {\n  int\
    \ chromatic_number(const std::vector<std::vector<int>> &graph){\n    static constexpr\
    \ int mod = 1000000007;\n    const int N = graph.size();\n\n    std::vector<int>\
    \ g(N);\n    for(int i = 0; i < N; ++i){\n      for(auto j : graph[i]){\n    \
    \    g[i] |= (1 << j);\n      }\n    }\n\n    std::vector<int64_t> I(1 << N);\n\
    \    I[0] = 1;\n    for(int i = 1; i < (1 << N); ++i){\n      int c = __builtin_ctz(i);\n\
    \      I[i] = I[i - (1 << c)] + I[(i - (1 << c)) & (~g[c])];\n      if(I[i] >=\
    \ mod) I[i] -= mod;\n    }\n\n    const auto check =\n      [&](int k){\n    \
    \    int64_t t = 0;\n        for(int i = 0; i < (1 << N); ++i){\n          if(__builtin_popcount(i)\
    \ % 2 == 1) t -= mod_pow(I[i], k, mod);\n          else t += mod_pow(I[i], k,\
    \ mod);\n          if(t < 0) t += mod;\n          if(t >= mod) t -= mod;\n   \
    \     }\n        return (t % mod != 0);\n      };\n\n    int lb = 0, ub = N;\n\
    \    while(std::abs(lb - ub) > 1){\n      const auto mid = (lb + ub) / 2;\n\n\
    \      if(check(mid)){\n        ub = mid;\n      }else{\n        lb = mid;\n \
    \     }\n    }\n\n    return ub;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cstdint>\n#include <cmath>\n#include\
    \ \"Mylib/Number/Mod/mod_pow.cpp\"\n\nnamespace haar_lib {\n  int chromatic_number(const\
    \ std::vector<std::vector<int>> &graph){\n    static constexpr int mod = 1000000007;\n\
    \    const int N = graph.size();\n\n    std::vector<int> g(N);\n    for(int i\
    \ = 0; i < N; ++i){\n      for(auto j : graph[i]){\n        g[i] |= (1 << j);\n\
    \      }\n    }\n\n    std::vector<int64_t> I(1 << N);\n    I[0] = 1;\n    for(int\
    \ i = 1; i < (1 << N); ++i){\n      int c = __builtin_ctz(i);\n      I[i] = I[i\
    \ - (1 << c)] + I[(i - (1 << c)) & (~g[c])];\n      if(I[i] >= mod) I[i] -= mod;\n\
    \    }\n\n    const auto check =\n      [&](int k){\n        int64_t t = 0;\n\
    \        for(int i = 0; i < (1 << N); ++i){\n          if(__builtin_popcount(i)\
    \ % 2 == 1) t -= mod_pow(I[i], k, mod);\n          else t += mod_pow(I[i], k,\
    \ mod);\n          if(t < 0) t += mod;\n          if(t >= mod) t -= mod;\n   \
    \     }\n        return (t % mod != 0);\n      };\n\n    int lb = 0, ub = N;\n\
    \    while(std::abs(lb - ub) > 1){\n      const auto mid = (lb + ub) / 2;\n\n\
    \      if(check(mid)){\n        ub = mid;\n      }else{\n        lb = mid;\n \
    \     }\n    }\n\n    return ub;\n  }\n}\n"
  dependsOn:
  - Mylib/Number/Mod/mod_pow.cpp
  isVerificationFile: false
  path: Mylib/Graph/Coloring/chromatic_number.cpp
  requiredBy: []
  timestamp: '2020-10-28 03:22:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2136/main.test.cpp
documentation_of: Mylib/Graph/Coloring/chromatic_number.cpp
layout: document
title: Graph vertex coloring
---

## Operations

- `chromatic_number(g)`
	- Time complexity $O(2^n \log^2 n)$

## Requirements

## Notes

## Problems

- [AOJ 2136 Webby Subway](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2136)
- [AOJ 1254 Color the Map](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1254)

## References

