---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/sliding_minmax.cpp\"\n#include <vector>\n\
    #include <deque>\n#include <utility>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  std::vector<std::pair<T, T>> sliding_minmax(const std::vector<T> &a, int\
    \ k){\n    int n = a.size();\n    std::deque<int> dq_min, dq_max;\n    std::vector<std::pair<T,\
    \ T>> ret;\n\n    for(int i = 0; i < k; ++i){\n      while(not dq_min.empty()\
    \ and a[dq_min.back()] >= a[i]){\n        dq_min.pop_back();\n      }\n\n    \
    \  dq_min.push_back(i);\n\n      while(not dq_max.empty() and a[dq_max.back()]\
    \ <= a[i]){\n        dq_max.pop_back();\n      }\n\n      dq_max.push_back(i);\n\
    \    }\n\n    for(int i = 0; i < n - k + 1; ++i){\n      while(dq_min.front()\
    \ < i){\n        dq_min.pop_front();\n      }\n\n      while(dq_max.front() <\
    \ i){\n        dq_max.pop_front();\n      }\n\n      ret.emplace_back(a[dq_min.front()],\
    \ a[dq_max.front()]);\n\n      while(not dq_min.empty() and i + k < n and a[dq_min.back()]\
    \ >= a[i + k]){\n        dq_min.pop_back();\n      }\n\n      while(not dq_max.empty()\
    \ and i + k < n and a[dq_max.back()] <= a[i + k]){\n        dq_max.pop_back();\n\
    \      }\n\n      dq_min.push_back(i + k);\n      dq_max.push_back(i + k);\n \
    \   }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <deque>\n#include <utility>\n\n\
    namespace haar_lib {\n  template <typename T>\n  std::vector<std::pair<T, T>>\
    \ sliding_minmax(const std::vector<T> &a, int k){\n    int n = a.size();\n   \
    \ std::deque<int> dq_min, dq_max;\n    std::vector<std::pair<T, T>> ret;\n\n \
    \   for(int i = 0; i < k; ++i){\n      while(not dq_min.empty() and a[dq_min.back()]\
    \ >= a[i]){\n        dq_min.pop_back();\n      }\n\n      dq_min.push_back(i);\n\
    \n      while(not dq_max.empty() and a[dq_max.back()] <= a[i]){\n        dq_max.pop_back();\n\
    \      }\n\n      dq_max.push_back(i);\n    }\n\n    for(int i = 0; i < n - k\
    \ + 1; ++i){\n      while(dq_min.front() < i){\n        dq_min.pop_front();\n\
    \      }\n\n      while(dq_max.front() < i){\n        dq_max.pop_front();\n  \
    \    }\n\n      ret.emplace_back(a[dq_min.front()], a[dq_max.front()]);\n\n  \
    \    while(not dq_min.empty() and i + k < n and a[dq_min.back()] >= a[i + k]){\n\
    \        dq_min.pop_back();\n      }\n\n      while(not dq_max.empty() and i +\
    \ k < n and a[dq_max.back()] <= a[i + k]){\n        dq_max.pop_back();\n     \
    \ }\n\n      dq_min.push_back(i + k);\n      dq_max.push_back(i + k);\n    }\n\
    \n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/sliding_minmax.cpp
  requiredBy: []
  timestamp: '2020-12-09 10:43:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Algorithm/sliding_minmax.cpp
layout: document
title: Sliding window minmax
---

## Operations

## Requirements

## Notes

## Problems

## References
