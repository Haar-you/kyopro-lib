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
  bundledCode: "#line 2 \"Mylib/Typical/interval_scheduling_weighted.cpp\"\n#include\
    \ <algorithm>\n#include <utility>\n#include <vector>\n\nnamespace haar_lib {\n\
    \  template <typename T, typename U>\n  U weighted_interval_scheduling(std::vector<T>\
    \ from, std::vector<T> to, std::vector<U> value) {\n    int n = from.size();\n\
    \n    std::vector<T> c(from);\n    c.insert(c.end(), to.begin(), to.end());\n\n\
    \    std::sort(c.begin(), c.end());\n    c.erase(std::unique(c.begin(), c.end()),\
    \ c.end());\n\n    for (int i = 0; i < n; ++i) {\n      from[i] = lower_bound(c.begin(),\
    \ c.end(), from[i]) - c.begin();\n      to[i]   = lower_bound(c.begin(), c.end(),\
    \ to[i]) - c.begin();\n    }\n\n    int m = c.size();\n\n    std::vector<U> dp(m\
    \ + 1);\n\n    std::vector<std::vector<std::pair<int, U>>> memo(m);\n    for (int\
    \ i = 0; i < n; ++i) {\n      memo[to[i]].emplace_back(from[i], value[i]);\n \
    \   }\n\n    for (int i = 0; i < m; ++i) {\n      dp[i + 1] = dp[i];\n\n     \
    \ for (auto &p : memo[i]) {\n        dp[i + 1] = std::max(dp[i + 1], dp[p.first]\
    \ + p.second);\n      }\n    }\n\n    return dp[m];\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T, typename U>\n  U weighted_interval_scheduling(std::vector<T>\
    \ from, std::vector<T> to, std::vector<U> value) {\n    int n = from.size();\n\
    \n    std::vector<T> c(from);\n    c.insert(c.end(), to.begin(), to.end());\n\n\
    \    std::sort(c.begin(), c.end());\n    c.erase(std::unique(c.begin(), c.end()),\
    \ c.end());\n\n    for (int i = 0; i < n; ++i) {\n      from[i] = lower_bound(c.begin(),\
    \ c.end(), from[i]) - c.begin();\n      to[i]   = lower_bound(c.begin(), c.end(),\
    \ to[i]) - c.begin();\n    }\n\n    int m = c.size();\n\n    std::vector<U> dp(m\
    \ + 1);\n\n    std::vector<std::vector<std::pair<int, U>>> memo(m);\n    for (int\
    \ i = 0; i < n; ++i) {\n      memo[to[i]].emplace_back(from[i], value[i]);\n \
    \   }\n\n    for (int i = 0; i < m; ++i) {\n      dp[i + 1] = dp[i];\n\n     \
    \ for (auto &p : memo[i]) {\n        dp[i + 1] = std::max(dp[i + 1], dp[p.first]\
    \ + p.second);\n      }\n    }\n\n    return dp[m];\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/interval_scheduling_weighted.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Typical/interval_scheduling_weighted.cpp
layout: document
title: Weighted interval scheduling problem
---

## Operations

## Requirements

## Notes

## Problems

- [J - 異世界転生2](https://www.hackerrank.com/contests/kodamanwithothers/challenges/2-82/problem)

## References