---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/maximum_independent_set/main.test.cpp
    title: test/yosupo-judge/maximum_independent_set/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/maximum_independent_set.cpp\"\n#include <vector>\n\
    #include <cassert>\n#include <cstdint>\n\nnamespace haar_lib {\n  int64_t maximum_independent_set(const\
    \ std::vector<std::vector<int>> &g){\n    const int n = g.size();\n\n    for(int\
    \ i = 0; i < n; ++i){\n      for(int j = 0; j < n; ++j){\n        assert((int)g[i].size()\
    \ == n);\n        assert(g[i][j] == g[j][i]);\n      }\n    }\n\n    const int\
    \ h1 = n / 2; // V1\n    const int h2 = n - h1; // V2\n\n    std::vector<bool>\
    \ dp1(1 << h1, true); // dp1[S] := S\u304C\u72EC\u7ACB\u96C6\u5408\u304B?\n  \
    \  for(int i = 0; i < h1; ++i){\n      for(int j = 0; j < h1; ++j){\n        if(g[i][j])\
    \ dp1[(1 << i) | (1 << j)] = false;\n      }\n    }\n\n    for(int s = 0; s <\
    \ (1 << h1); ++s){\n      if(not dp1[s]){\n        for(int j = 0; j < h1; ++j){\n\
    \          dp1[s | (1 << j)] = false;\n        }\n      }\n    }\n\n    std::vector<bool>\
    \ dp2(1 << h2, true); // dp2[S] := S\u304C\u72EC\u7ACB\u96C6\u5408\u304B?\n  \
    \  for(int i = h1; i < n; ++i){\n      for(int j = h1; j < n; ++j){\n        if(g[i][j])\
    \ dp2[(1 << (i - h1)) | (1 << (j - h1))] = false;\n      }\n    }\n\n    for(int\
    \ s = 0; s < (1 << h2); ++s){\n      if(!dp2[s]){\n        for(int j = 0; j <\
    \ h2; ++j){\n          dp2[s | (1 << j)] = false;\n        }\n      }\n    }\n\
    \n    std::vector<int> dp3(1 << h1, 0); // S1\u3068\u63A5\u7D9A\u3057\u306A\u3044\
    V2\u306E\u6700\u5927\u306E\u90E8\u5206\u96C6\u5408\n    dp3[0] = (1 << h2) - 1;\n\
    \    for(int i = 0; i < h1; ++i){\n      int t = 0;\n      for(int j = h1; j <\
    \ n; ++j){\n        if(g[i][j]){\n          t |= (1 << (j - h1));\n        }\n\
    \      }\n      dp3[1 << i] = t ^ ((1 << h2) - 1);\n    }\n\n    for(int s = 0;\
    \ s < (1 << h1); ++s){\n      for(int j = 0; j < h1; ++j){\n        if((s & (1\
    \ << j)) == 0){\n          dp3[s | (1 << j)] = dp3[s] & dp3[1 << j];\n       \
    \ }\n      }\n    }\n\n    std::vector<int> dp4(1 << h2, 0); // S2\u306E\u6700\
    \u5927\u72EC\u7ACB\u96C6\u5408\n    for(int i = 0; i < (1 << h2); ++i){\n    \
    \  if(dp2[i]){\n        dp4[i] = i;\n      }\n    }\n\n    for(int s = 0; s <\
    \ (1 << h2); ++s){\n      for(int j = 0; j < h2; ++j){\n        if((s & (1 <<\
    \ j)) == 0){\n          if(__builtin_popcount(dp4[s | (1 << j)]) > __builtin_popcount(dp4[s])){\n\
    \            dp4[s | (1 << j)] = dp4[s | (1 << j)];\n          }else{\n      \
    \      dp4[s | (1 << j)] = dp4[s];\n          }\n        }\n      }\n    }\n\n\
    \    int64_t ans = 0;\n    int size = 0;\n\n    for(int s = 0; s < (1 << h1);\
    \ ++s){\n      if(dp1[s]){\n        int64_t t = (int64_t)s | (((int64_t)dp4[dp3[s]])\
    \ << h1);\n\n        if(__builtin_popcountll(t) > size){\n          size = __builtin_popcountll(t);\n\
    \          ans = t;\n        }\n      }\n    }\n\n    return ans;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n#include <cstdint>\n\
    \nnamespace haar_lib {\n  int64_t maximum_independent_set(const std::vector<std::vector<int>>\
    \ &g){\n    const int n = g.size();\n\n    for(int i = 0; i < n; ++i){\n     \
    \ for(int j = 0; j < n; ++j){\n        assert((int)g[i].size() == n);\n      \
    \  assert(g[i][j] == g[j][i]);\n      }\n    }\n\n    const int h1 = n / 2; //\
    \ V1\n    const int h2 = n - h1; // V2\n\n    std::vector<bool> dp1(1 << h1, true);\
    \ // dp1[S] := S\u304C\u72EC\u7ACB\u96C6\u5408\u304B?\n    for(int i = 0; i <\
    \ h1; ++i){\n      for(int j = 0; j < h1; ++j){\n        if(g[i][j]) dp1[(1 <<\
    \ i) | (1 << j)] = false;\n      }\n    }\n\n    for(int s = 0; s < (1 << h1);\
    \ ++s){\n      if(not dp1[s]){\n        for(int j = 0; j < h1; ++j){\n       \
    \   dp1[s | (1 << j)] = false;\n        }\n      }\n    }\n\n    std::vector<bool>\
    \ dp2(1 << h2, true); // dp2[S] := S\u304C\u72EC\u7ACB\u96C6\u5408\u304B?\n  \
    \  for(int i = h1; i < n; ++i){\n      for(int j = h1; j < n; ++j){\n        if(g[i][j])\
    \ dp2[(1 << (i - h1)) | (1 << (j - h1))] = false;\n      }\n    }\n\n    for(int\
    \ s = 0; s < (1 << h2); ++s){\n      if(!dp2[s]){\n        for(int j = 0; j <\
    \ h2; ++j){\n          dp2[s | (1 << j)] = false;\n        }\n      }\n    }\n\
    \n    std::vector<int> dp3(1 << h1, 0); // S1\u3068\u63A5\u7D9A\u3057\u306A\u3044\
    V2\u306E\u6700\u5927\u306E\u90E8\u5206\u96C6\u5408\n    dp3[0] = (1 << h2) - 1;\n\
    \    for(int i = 0; i < h1; ++i){\n      int t = 0;\n      for(int j = h1; j <\
    \ n; ++j){\n        if(g[i][j]){\n          t |= (1 << (j - h1));\n        }\n\
    \      }\n      dp3[1 << i] = t ^ ((1 << h2) - 1);\n    }\n\n    for(int s = 0;\
    \ s < (1 << h1); ++s){\n      for(int j = 0; j < h1; ++j){\n        if((s & (1\
    \ << j)) == 0){\n          dp3[s | (1 << j)] = dp3[s] & dp3[1 << j];\n       \
    \ }\n      }\n    }\n\n    std::vector<int> dp4(1 << h2, 0); // S2\u306E\u6700\
    \u5927\u72EC\u7ACB\u96C6\u5408\n    for(int i = 0; i < (1 << h2); ++i){\n    \
    \  if(dp2[i]){\n        dp4[i] = i;\n      }\n    }\n\n    for(int s = 0; s <\
    \ (1 << h2); ++s){\n      for(int j = 0; j < h2; ++j){\n        if((s & (1 <<\
    \ j)) == 0){\n          if(__builtin_popcount(dp4[s | (1 << j)]) > __builtin_popcount(dp4[s])){\n\
    \            dp4[s | (1 << j)] = dp4[s | (1 << j)];\n          }else{\n      \
    \      dp4[s | (1 << j)] = dp4[s];\n          }\n        }\n      }\n    }\n\n\
    \    int64_t ans = 0;\n    int size = 0;\n\n    for(int s = 0; s < (1 << h1);\
    \ ++s){\n      if(dp1[s]){\n        int64_t t = (int64_t)s | (((int64_t)dp4[dp3[s]])\
    \ << h1);\n\n        if(__builtin_popcountll(t) > size){\n          size = __builtin_popcountll(t);\n\
    \          ans = t;\n        }\n      }\n    }\n\n    return ans;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/maximum_independent_set.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/maximum_independent_set/main.test.cpp
documentation_of: Mylib/Graph/maximum_independent_set.cpp
layout: document
title: Maximum independent set
---

## Operations

- `maximum_independent_set(g[n][n])`
	- 最大独立集合の一つを64bit整数で表記して返す。
	- Time complexity $O(2^{n/2} n)$

## Requirements

## Notes
- 二部グラフでは、(最大独立集合の大きさ) = (グラフの頂点数) - (最大二部マッチングの大きさ)となるので、最大二部マッチングを用いる方が良い。
	- [https://qiita.com/drken/items/7f98315b56c95a6181a4](https://qiita.com/drken/items/7f98315b56c95a6181a4)

## Problems

- [CODE THANKS FESTIVAL 2017 G - Mixture Drug](https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_g)
- [Codeforces Round #533 (Div. 2) E. Helping Hiasat](https://codeforces.com/contest/1105/problem/E)
- [Maximum Independent Set](https://judge.yosupo.jp/problem/maximum_independent_set)


## References

