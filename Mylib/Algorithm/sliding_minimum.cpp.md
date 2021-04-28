---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_3_D/main.test.cpp
    title: test/aoj/DSL_3_D/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/sliding_minimum.cpp\"\n#include <deque>\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T>\
    \ sliding_minimum(const std::vector<T> &a, int k) {\n    const int n = a.size();\n\
    \    std::deque<int> dq;\n    std::vector<T> ret;\n\n    for (int i = 0; i < k;\
    \ ++i) {\n      while (not dq.empty() and a[dq.back()] >= a[i]) {\n        dq.pop_back();\n\
    \      }\n\n      dq.push_back(i);\n    }\n\n    for (int i = 0; i < n - k + 1;\
    \ ++i) {\n      while (dq.front() < i) {\n        dq.pop_front();\n      }\n\n\
    \      ret.push_back(a[dq.front()]);\n\n      while (not dq.empty() and i + k\
    \ < n and a[dq.back()] >= a[i + k]) {\n        dq.pop_back();\n      }\n\n   \
    \   dq.push_back(i + k);\n    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <deque>\n#include <vector>\n\nnamespace haar_lib {\n\
    \  template <typename T>\n  std::vector<T> sliding_minimum(const std::vector<T>\
    \ &a, int k) {\n    const int n = a.size();\n    std::deque<int> dq;\n    std::vector<T>\
    \ ret;\n\n    for (int i = 0; i < k; ++i) {\n      while (not dq.empty() and a[dq.back()]\
    \ >= a[i]) {\n        dq.pop_back();\n      }\n\n      dq.push_back(i);\n    }\n\
    \n    for (int i = 0; i < n - k + 1; ++i) {\n      while (dq.front() < i) {\n\
    \        dq.pop_front();\n      }\n\n      ret.push_back(a[dq.front()]);\n\n \
    \     while (not dq.empty() and i + k < n and a[dq.back()] >= a[i + k]) {\n  \
    \      dq.pop_back();\n      }\n\n      dq.push_back(i + k);\n    }\n\n    return\
    \ ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/sliding_minimum.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_3_D/main.test.cpp
documentation_of: Mylib/Algorithm/sliding_minimum.cpp
layout: document
title: Sliding window minimum
---

## Operations

## Requirements

## Notes

## Problems

- [Codeforces Round #574 (Div. 2) E. OpenStreetMap](https://codeforces.com/contest/1195/problem/E)

## References
