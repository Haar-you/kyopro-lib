---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_1_G/main.test.cpp
    title: test/aoj/DPL_1_G/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/knapsack_limited.cpp\"\n#include <algorithm>\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename Weight, typename\
    \ Value>\n  Value knapsack_limited(int N, Weight cap, const std::vector<Weight>\
    \ &w, const std::vector<Value> &v, const std::vector<int> &m) {\n    std::vector<Value>\
    \ dp(cap + 1);\n\n    for (int i = 0; i < N; ++i) {\n      for (int64_t a = 1,\
    \ x = m[i], k; k = std::min(x, a), x > 0; x -= k, a *= 2) {\n        for (int\
    \ j = cap; j >= 0; --j) {\n          if (j - k * w[i] >= 0) {\n            dp[j]\
    \ = std::max(dp[j], dp[j - k * w[i]] + (Weight) k * v[i]);\n          }\n    \
    \    }\n      }\n    }\n\n    return dp[cap];\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename Weight, typename Value>\n  Value knapsack_limited(int\
    \ N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v, const\
    \ std::vector<int> &m) {\n    std::vector<Value> dp(cap + 1);\n\n    for (int\
    \ i = 0; i < N; ++i) {\n      for (int64_t a = 1, x = m[i], k; k = std::min(x,\
    \ a), x > 0; x -= k, a *= 2) {\n        for (int j = cap; j >= 0; --j) {\n   \
    \       if (j - k * w[i] >= 0) {\n            dp[j] = std::max(dp[j], dp[j - k\
    \ * w[i]] + (Weight) k * v[i]);\n          }\n        }\n      }\n    }\n\n  \
    \  return dp[cap];\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/knapsack_limited.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DPL_1_G/main.test.cpp
documentation_of: Mylib/Typical/knapsack_limited.cpp
layout: document
title: Knapsack problem (With quantity limitations)
---

## Operations

- `knapsack_limited(int N, Weight cap, Weight w[N], Value v[N], int m[N])`
	- 個数制限ナップサック問題を解く。
	- Time complexity $O(N cap \log \max m)$

## Requirements

## Notes

## Problems

- [AOJ DPL_1_G Knapsack Problem with Limitations](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G)

## References

