---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_1_H/main.test.cpp
    title: test/aoj/DPL_1_H/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/knapsack_small_quantity.cpp\"\n#include <vector>\n\
    #include <map>\n#include <algorithm>\n#include <iterator>\n\nnamespace haar_lib\
    \ {\n  template <typename Weight, typename Value>\n  Value knapsack_small_quantity(int\
    \ N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v){\n\
    \    const int p = N / 2;\n    const int q = N - p;\n\n    std::vector<std::pair<Weight,\
    \ Value>> a, b;\n    a.reserve(1 << p);\n    b.reserve(1 << q);\n\n    a.emplace_back(0,\
    \ 0);\n    b.emplace_back(0, 0);\n\n    for(int i = 0; i < p; ++i){\n      const\
    \ int k = a.size();\n      const auto begin = a.begin();\n      const auto end\
    \ = a.end();\n\n      for(auto it = begin; it != end; ++it){\n        a.emplace_back(it->first\
    \ + w[i], it->second + v[i]);\n      }\n\n      std::inplace_merge(a.begin(),\
    \ a.begin() + k, a.end());\n    }\n\n    for(int i = p; i < p + q; ++i){\n   \
    \   const int k = b.size();\n      const auto begin = b.begin();\n      const\
    \ auto end = b.end();\n\n      for(auto it = begin; it != end; ++it){\n      \
    \  b.emplace_back(it->first + w[i], it->second + v[i]);\n      }\n\n      std::inplace_merge(b.begin(),\
    \ b.begin() + k, b.end());\n    }\n\n    for(size_t i = 1; i < a.size(); ++i){\n\
    \      a[i].second = std::max(a[i].second, a[i - 1].second);\n    }\n\n    for(size_t\
    \ i = 1; i < b.size(); ++i){\n      b[i].second = std::max(b[i].second, b[i -\
    \ 1].second);\n    }\n\n    Value ret = 0;\n\n    for(int i = 0, j = (int)b.size()\
    \ - 1; i < (int)a.size(); ++i){\n      while(j >= 0 and a[i].first + b[j].first\
    \ > cap) --j;\n      if(j < 0) break;\n      ret = std::max(ret, a[i].second +\
    \ b[j].second);\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <map>\n#include <algorithm>\n#include\
    \ <iterator>\n\nnamespace haar_lib {\n  template <typename Weight, typename Value>\n\
    \  Value knapsack_small_quantity(int N, Weight cap, const std::vector<Weight>\
    \ &w, const std::vector<Value> &v){\n    const int p = N / 2;\n    const int q\
    \ = N - p;\n\n    std::vector<std::pair<Weight, Value>> a, b;\n    a.reserve(1\
    \ << p);\n    b.reserve(1 << q);\n\n    a.emplace_back(0, 0);\n    b.emplace_back(0,\
    \ 0);\n\n    for(int i = 0; i < p; ++i){\n      const int k = a.size();\n    \
    \  const auto begin = a.begin();\n      const auto end = a.end();\n\n      for(auto\
    \ it = begin; it != end; ++it){\n        a.emplace_back(it->first + w[i], it->second\
    \ + v[i]);\n      }\n\n      std::inplace_merge(a.begin(), a.begin() + k, a.end());\n\
    \    }\n\n    for(int i = p; i < p + q; ++i){\n      const int k = b.size();\n\
    \      const auto begin = b.begin();\n      const auto end = b.end();\n\n    \
    \  for(auto it = begin; it != end; ++it){\n        b.emplace_back(it->first +\
    \ w[i], it->second + v[i]);\n      }\n\n      std::inplace_merge(b.begin(), b.begin()\
    \ + k, b.end());\n    }\n\n    for(size_t i = 1; i < a.size(); ++i){\n      a[i].second\
    \ = std::max(a[i].second, a[i - 1].second);\n    }\n\n    for(size_t i = 1; i\
    \ < b.size(); ++i){\n      b[i].second = std::max(b[i].second, b[i - 1].second);\n\
    \    }\n\n    Value ret = 0;\n\n    for(int i = 0, j = (int)b.size() - 1; i <\
    \ (int)a.size(); ++i){\n      while(j >= 0 and a[i].first + b[j].first > cap)\
    \ --j;\n      if(j < 0) break;\n      ret = std::max(ret, a[i].second + b[j].second);\n\
    \    }\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/knapsack_small_quantity.cpp
  requiredBy: []
  timestamp: '2020-11-23 21:23:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_1_H/main.test.cpp
documentation_of: Mylib/Typical/knapsack_small_quantity.cpp
layout: document
title: 0-1 Knapsack problem (Small quantity)
---

## Operations

- `knapsack_small_quantity(int N, Weight cap, Weight w[N], Value v[N])`
	- 0-1ナップサック問題を解く。
	- Time complexity $O(2^{N/2} N)$

## Requirements

## Notes

## Problems

- [AOJ DPL_1_H Huge Knapsack Problem](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H)

## References

