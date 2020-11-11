---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/580/main.test.cpp
    title: test/yukicoder/580/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/interval_scheduling_k.cpp\"\n#include <vector>\n\
    #include <set>\n#include <iterator>\n#include <algorithm>\n#include <utility>\n\
    #include <numeric>\n\nnamespace haar_lib {\n  auto interval_scheduling_k(std::vector<int>\
    \ l, std::vector<int> r, int k){\n    const int N = l.size();\n\n    std::vector<int>\
    \ ord(N);\n    std::iota(ord.begin(), ord.end(), 0);\n    std::sort(ord.begin(),\
    \ ord.end(), [&](int i, int j){return r[i] < r[j];});\n\n    std::multiset<int>\
    \ a;\n    std::vector<std::pair<int, int>> ret;\n\n    for(int i : ord){\n   \
    \   auto it = a.upper_bound(l[i]);\n\n      if(it != a.begin()){\n        it =\
    \ std::prev(it);\n        a.erase(it);\n      }\n\n      if((int)a.size() < k){\n\
    \        a.insert(r[i]);\n        ret.emplace_back(l[i], r[i]);\n      }\n   \
    \ }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <set>\n#include <iterator>\n#include\
    \ <algorithm>\n#include <utility>\n#include <numeric>\n\nnamespace haar_lib {\n\
    \  auto interval_scheduling_k(std::vector<int> l, std::vector<int> r, int k){\n\
    \    const int N = l.size();\n\n    std::vector<int> ord(N);\n    std::iota(ord.begin(),\
    \ ord.end(), 0);\n    std::sort(ord.begin(), ord.end(), [&](int i, int j){return\
    \ r[i] < r[j];});\n\n    std::multiset<int> a;\n    std::vector<std::pair<int,\
    \ int>> ret;\n\n    for(int i : ord){\n      auto it = a.upper_bound(l[i]);\n\n\
    \      if(it != a.begin()){\n        it = std::prev(it);\n        a.erase(it);\n\
    \      }\n\n      if((int)a.size() < k){\n        a.insert(r[i]);\n        ret.emplace_back(l[i],\
    \ r[i]);\n      }\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/interval_scheduling_k.cpp
  requiredBy: []
  timestamp: '2020-11-07 03:03:04+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/580/main.test.cpp
documentation_of: Mylib/Typical/interval_scheduling_k.cpp
layout: document
title: Interval scheduling problem (Allow no more than k intervals to overlap)
---

## Operations

- `interval_scheduling_k(l[N], r[N], k)`
	- `N`個の半開区間`[l[i], r[i])`を、ある点で最大`k`個までの重複を許して選ぶときに、選べる個数を最大化する方法を返す。
	- Time complexity $O(N \log N)$

## Requirements

## Notes

## Problems

- [yukicoder No.580 旅館の予約計画](https://yukicoder.me/problems/no/580)
- [Codeforces Round #595 (Div. 3) D2. Too Many Segments (hard version)](https://codeforces.com/contest/1249/problem/D2)

## References

- [http://buyoh.hateblo.jp/entry/2017/10/25/160236](http://buyoh.hateblo.jp/entry/2017/10/25/160236)
