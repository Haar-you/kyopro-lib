---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_1_D/main.test.cpp
    title: test/aoj/DPL_1_D/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DynamicProgramming/longest_increasing_subsequence.cpp\"\
    \n#include <vector>\n#include <algorithm>\n\nnamespace haar_lib {\n  template\
    \ <typename Container, typename T = typename Container::value_type>\n  int lis(const\
    \ Container &xs){\n    std::vector<T> dp;\n    dp.reserve(xs.size());\n\n    for(auto\
    \ x : xs){\n      if(dp.empty() or dp.back() < x){\n        dp.push_back(x);\n\
    \      }else{\n        dp[std::lower_bound(dp.begin(), dp.end(), x) - dp.begin()]\
    \ = x;\n      }\n    }\n\n    return dp.size();\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n\nnamespace haar_lib\
    \ {\n  template <typename Container, typename T = typename Container::value_type>\n\
    \  int lis(const Container &xs){\n    std::vector<T> dp;\n    dp.reserve(xs.size());\n\
    \n    for(auto x : xs){\n      if(dp.empty() or dp.back() < x){\n        dp.push_back(x);\n\
    \      }else{\n        dp[std::lower_bound(dp.begin(), dp.end(), x) - dp.begin()]\
    \ = x;\n      }\n    }\n\n    return dp.size();\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DynamicProgramming/longest_increasing_subsequence.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DPL_1_D/main.test.cpp
documentation_of: Mylib/DynamicProgramming/longest_increasing_subsequence.cpp
layout: document
title: Longest increasing subsequence
---

## Operations

- `lis(a[N])`
	- `a`の最長増加部分列の長さを返す。
	- Time complexity $O(N \log N)$

## Requirements

## Notes

## Problems

## References
