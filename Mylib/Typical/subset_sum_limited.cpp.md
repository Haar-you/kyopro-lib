---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2370/main.test.cpp
    title: test/aoj/2370/main.test.cpp
  - icon: ':x:'
    path: test/aoj/2955/main.test.cpp
    title: test/aoj/2955/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/subset_sum_limited.cpp\"\n#include <cassert>\n\
    #include <vector>\n\nnamespace haar_lib {\n  auto subset_sum_limited(int N, int\
    \ K, const std::vector<int> &a, const std::vector<int> &m) {\n    assert((int)\
    \ a.size() == N and (int) m.size() == N);\n    std::vector<int> dp(K + 1, -1);\n\
    \n    dp[0] = 0;\n    for (int i = 0; i < N; ++i) {\n      for (int j = 0; j <=\
    \ K; ++j) {\n        if (dp[j] >= 0) {\n          dp[j] = m[i];\n        } else\
    \ if (j < a[i] or dp[j - a[i]] <= 0) {\n          dp[j] = -1;\n        } else\
    \ {\n          dp[j] = dp[j - a[i]] - 1;\n        }\n      }\n    }\n\n    for\
    \ (int i = 0; i <= K; ++i) dp[i] = dp[i] >= 0;\n\n    return dp;\n  }\n}  // namespace\
    \ haar_lib\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  auto subset_sum_limited(int N, int K, const std::vector<int> &a, const\
    \ std::vector<int> &m) {\n    assert((int) a.size() == N and (int) m.size() ==\
    \ N);\n    std::vector<int> dp(K + 1, -1);\n\n    dp[0] = 0;\n    for (int i =\
    \ 0; i < N; ++i) {\n      for (int j = 0; j <= K; ++j) {\n        if (dp[j] >=\
    \ 0) {\n          dp[j] = m[i];\n        } else if (j < a[i] or dp[j - a[i]] <=\
    \ 0) {\n          dp[j] = -1;\n        } else {\n          dp[j] = dp[j - a[i]]\
    \ - 1;\n        }\n      }\n    }\n\n    for (int i = 0; i <= K; ++i) dp[i] =\
    \ dp[i] >= 0;\n\n    return dp;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/subset_sum_limited.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/2370/main.test.cpp
  - test/aoj/2955/main.test.cpp
documentation_of: Mylib/Typical/subset_sum_limited.cpp
layout: document
title: Subset sum problem (With quantity limitations)
---

## Operations

- `subset_sum_limited(N, K, a[N], m[N])`
	- Time complexity $O(NK)$

## Requirements

## Notes

## Problems

- [AOJ 2955 Two Colors Sort](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2955)

## References

- 蟻本第2版 P62~63
