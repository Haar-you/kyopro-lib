---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/SlidingWindow/sliding_maximum.cpp\"\n#include\
    \ <vector>\n#include <deque>\n\nnamespace haar_lib {\n  template <typename T>\n\
    \  std::vector<T> sliding_maximum(const std::vector<T> &a, int k){\n    const\
    \ int n = a.size();\n    std::deque<int> dq;\n    std::vector<T> ret;\n\n    for(int\
    \ i = 0; i < k; ++i){\n      while(not dq.empty() and a[dq.back()] <= a[i]){\n\
    \        dq.pop_back();\n      }\n\n      dq.push_back(i);\n    }\n\n    for(int\
    \ i = 0; i < n - k + 1; ++i){\n      while(dq.front() < i){\n        dq.pop_front();\n\
    \      }\n\n      ret.push_back(a[dq.front()]);\n\n      while(not dq.empty()\
    \ and i + k < n and a[dq.back()] <= a[i + k]){\n        dq.pop_back();\n     \
    \ }\n\n      dq.push_back(i + k);\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <deque>\n\nnamespace haar_lib {\n\
    \  template <typename T>\n  std::vector<T> sliding_maximum(const std::vector<T>\
    \ &a, int k){\n    const int n = a.size();\n    std::deque<int> dq;\n    std::vector<T>\
    \ ret;\n\n    for(int i = 0; i < k; ++i){\n      while(not dq.empty() and a[dq.back()]\
    \ <= a[i]){\n        dq.pop_back();\n      }\n\n      dq.push_back(i);\n    }\n\
    \n    for(int i = 0; i < n - k + 1; ++i){\n      while(dq.front() < i){\n    \
    \    dq.pop_front();\n      }\n\n      ret.push_back(a[dq.front()]);\n\n     \
    \ while(not dq.empty() and i + k < n and a[dq.back()] <= a[i + k]){\n        dq.pop_back();\n\
    \      }\n\n      dq.push_back(i + k);\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/SlidingWindow/sliding_maximum.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Algorithm/SlidingWindow/sliding_maximum.cpp
layout: document
title: Sliding window maximum
---

## Operations

## Requirements

## Notes

## Problems

- [CODE FESTIVAL 2016 Tournament Round 3 A - ストラックアウト](https://atcoder.jp/contests/cf16-tournament-round3-open/tasks/asaporo_d)

## References
