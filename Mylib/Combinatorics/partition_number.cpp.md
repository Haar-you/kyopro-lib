---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_5_J/main.test.cpp
    title: test/aoj/DPL_5_J/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/partition_number.cpp\"\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  auto partition_number(int n,\
    \ int k) -> std::vector<std::vector<T>> {\n    std::vector<std::vector<T>> dp(n\
    \ + 1, std::vector<T>(k + 1));\n    dp[0][0] = 1;\n\n    for (int i = 0; i <=\
    \ n; ++i) {\n      for (int j = 1; j <= k; ++j) {\n        if (i - j >= 0)\n \
    \         dp[i][j] = dp[i][j - 1] + dp[i - j][j];\n        else\n          dp[i][j]\
    \ = dp[i][j - 1];\n      }\n    }\n\n    return dp;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  auto partition_number(int n, int k) -> std::vector<std::vector<T>> {\n\
    \    std::vector<std::vector<T>> dp(n + 1, std::vector<T>(k + 1));\n    dp[0][0]\
    \ = 1;\n\n    for (int i = 0; i <= n; ++i) {\n      for (int j = 1; j <= k; ++j)\
    \ {\n        if (i - j >= 0)\n          dp[i][j] = dp[i][j - 1] + dp[i - j][j];\n\
    \        else\n          dp[i][j] = dp[i][j - 1];\n      }\n    }\n\n    return\
    \ dp;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Combinatorics/partition_number.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DPL_5_J/main.test.cpp
documentation_of: Mylib/Combinatorics/partition_number.cpp
layout: document
title: Partition number (Enumerate $P(n, k)$)
---

## Operations

- `partition_number(int n, int k)`
	- $P(0,0)$ ~ $P(n,k)$を列挙する。
	- Time complexity $O(nk)$

## Requirements

## Notes

## Problems

## References

- [http://drken1215.hatenablog.com/entry/2018/01/16/222843](http://drken1215.hatenablog.com/entry/2018/01/16/222843)
- [https://mathtrain.jp/bunkatsu](https://mathtrain.jp/bunkatsu)