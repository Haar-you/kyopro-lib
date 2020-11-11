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
    \    Value ret = 0;\n\n    const int p = N / 2;\n    const int q = N - p;\n\n\
    \    std::map<Weight, Value> a;\n    for(int i = 0; i < 1 << p; ++i){\n      Weight\
    \ weight = 0;\n      Value value = 0;\n      for(int j = 0; j < p; ++j){\n   \
    \     if(i & (1 << j)){\n          weight += w[j];\n          value += v[j];\n\
    \        }\n      }\n\n      a[weight] = std::max(a[weight], value);\n    }\n\n\
    \    Value m = 0;\n    for(auto &kv : a){\n      kv.second = std::max(kv.second,\
    \ m);\n      m = kv.second;\n    }\n\n    for(int i = 0; i < 1 << q; ++i){\n \
    \     Weight weight = 0;\n      Value value = 0;\n      for(int j = 0; j < q;\
    \ ++j){\n        if(i & (1 << j)){\n          weight += w[j + p];\n          value\
    \ += v[j + p];\n        }\n      }\n\n      auto itr = a.upper_bound(std::max((Weight)0,\
    \ cap - weight));\n\n      itr = std::prev(itr);\n      if(weight + itr->first\
    \ <= cap) ret = std::max(ret, value + itr->second);\n    }\n\n    return ret;\n\
    \  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <map>\n#include <algorithm>\n#include\
    \ <iterator>\n\nnamespace haar_lib {\n  template <typename Weight, typename Value>\n\
    \  Value knapsack_small_quantity(int N, Weight cap, const std::vector<Weight>\
    \ &w, const std::vector<Value> &v){\n    Value ret = 0;\n\n    const int p = N\
    \ / 2;\n    const int q = N - p;\n\n    std::map<Weight, Value> a;\n    for(int\
    \ i = 0; i < 1 << p; ++i){\n      Weight weight = 0;\n      Value value = 0;\n\
    \      for(int j = 0; j < p; ++j){\n        if(i & (1 << j)){\n          weight\
    \ += w[j];\n          value += v[j];\n        }\n      }\n\n      a[weight] =\
    \ std::max(a[weight], value);\n    }\n\n    Value m = 0;\n    for(auto &kv : a){\n\
    \      kv.second = std::max(kv.second, m);\n      m = kv.second;\n    }\n\n  \
    \  for(int i = 0; i < 1 << q; ++i){\n      Weight weight = 0;\n      Value value\
    \ = 0;\n      for(int j = 0; j < q; ++j){\n        if(i & (1 << j)){\n       \
    \   weight += w[j + p];\n          value += v[j + p];\n        }\n      }\n\n\
    \      auto itr = a.upper_bound(std::max((Weight)0, cap - weight));\n\n      itr\
    \ = std::prev(itr);\n      if(weight + itr->first <= cap) ret = std::max(ret,\
    \ value + itr->second);\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/knapsack_small_quantity.cpp
  requiredBy: []
  timestamp: '2020-11-07 03:03:04+09:00'
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

