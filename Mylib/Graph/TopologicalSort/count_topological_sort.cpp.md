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
  bundledCode: "#line 2 \"Mylib/Graph/TopologicalSort/count_topological_sort.cpp\"\
    \n#include <vector>\n#include <cstdint>\n\nnamespace haar_lib {\n  int64_t count_topological_sort(const\
    \ std::vector<int> &g){\n    const int n = g.size();\n    std::vector<int64_t>\
    \ dp(1 << n);\n\n    dp[0] = 1;\n\n    for(int s = 0; s < (1 << n); ++s){\n  \
    \    for(int i = 0; i < n; ++i){\n        if(s & (1 << i)){\n          if((s ^\
    \ (1 << i)) & g[i]) continue;\n          dp[s] += dp[s ^ (1 << i)];\n        }\n\
    \      }\n    }\n\n    return dp[(1 << n) - 1];\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cstdint>\n\nnamespace haar_lib\
    \ {\n  int64_t count_topological_sort(const std::vector<int> &g){\n    const int\
    \ n = g.size();\n    std::vector<int64_t> dp(1 << n);\n\n    dp[0] = 1;\n\n  \
    \  for(int s = 0; s < (1 << n); ++s){\n      for(int i = 0; i < n; ++i){\n   \
    \     if(s & (1 << i)){\n          if((s ^ (1 << i)) & g[i]) continue;\n     \
    \     dp[s] += dp[s ^ (1 << i)];\n        }\n      }\n    }\n\n    return dp[(1\
    \ << n) - 1];\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/TopologicalSort/count_topological_sort.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/TopologicalSort/count_topological_sort.cpp
layout: document
title: Count topological sort
---

## Operations

- `count_topological_sort(g)`
	- Time complexity $O(n 2^n)$

## Requirements

## Notes

## Problems

- [ABC 041 D - 徒競走](https://atcoder.jp/contests/abc041/tasks/abc041_d)

## References
