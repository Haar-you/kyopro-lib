---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_1_D/main.test.cpp
    title: test/aoj/DPL_1_D/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/longest_increasing_subsequence.cpp\"\n#include\
    \ <algorithm>\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ Container>\n  std::vector<int> longest_increasing_subsequence(const Container\
    \ &a) {\n    using T = typename Container::value_type;\n\n    const int N = a.size();\n\
    \n    std::vector<T> dp;\n    dp.reserve(N);\n    std::vector<int> prev(N, -1),\
    \ pos, ret;\n    pos.reserve(N);\n\n    for (int i = 0; i < N; ++i) {\n      auto\
    \ x = a[i];\n      if (dp.empty() or dp.back() < x) {\n        dp.push_back(x);\n\
    \        if (pos.size()) prev[i] = pos.back();\n        pos.push_back(i);\n  \
    \    } else {\n        const int k = std::lower_bound(dp.begin(), dp.end(), x)\
    \ - dp.begin();\n        dp[k]       = x;\n        if (k > 0) prev[i] = pos[k\
    \ - 1];\n        pos[k] = i;\n      }\n    }\n\n    int i = pos.back();\n    while\
    \ (i != -1) {\n      ret.push_back(i);\n      i = prev[i];\n    }\n\n    std::reverse(ret.begin(),\
    \ ret.end());\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename Container>\n  std::vector<int> longest_increasing_subsequence(const\
    \ Container &a) {\n    using T = typename Container::value_type;\n\n    const\
    \ int N = a.size();\n\n    std::vector<T> dp;\n    dp.reserve(N);\n    std::vector<int>\
    \ prev(N, -1), pos, ret;\n    pos.reserve(N);\n\n    for (int i = 0; i < N; ++i)\
    \ {\n      auto x = a[i];\n      if (dp.empty() or dp.back() < x) {\n        dp.push_back(x);\n\
    \        if (pos.size()) prev[i] = pos.back();\n        pos.push_back(i);\n  \
    \    } else {\n        const int k = std::lower_bound(dp.begin(), dp.end(), x)\
    \ - dp.begin();\n        dp[k]       = x;\n        if (k > 0) prev[i] = pos[k\
    \ - 1];\n        pos[k] = i;\n      }\n    }\n\n    int i = pos.back();\n    while\
    \ (i != -1) {\n      ret.push_back(i);\n      i = prev[i];\n    }\n\n    std::reverse(ret.begin(),\
    \ ret.end());\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/longest_increasing_subsequence.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DPL_1_D/main.test.cpp
documentation_of: Mylib/Typical/longest_increasing_subsequence.cpp
layout: document
title: Longest increasing subsequence
---

## Operations

- `longest_increasing_subsequence(a[N])`
	- `a`の最長増加部分列を返す。
	- Time complexity $O(N \log N)$

## Requirements

## Notes

## Problems

## References
