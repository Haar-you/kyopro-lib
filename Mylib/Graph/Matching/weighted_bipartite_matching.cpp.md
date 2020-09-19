---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2293/main.test.cpp
    title: test/aoj/2293/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/assignment/main.test.cpp
    title: test/yosupo-judge/assignment/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/Matching/weighted_bipartite_matching.cpp\"\n\
    #include <vector>\n#include <tuple>\n\nnamespace haar_lib {\n  template <typename\
    \ T, typename MinCostFlow, bool MIN_MATCHING = false>\n  class weighted_bipartite_matching\
    \ {\n  public:\n    int L, R, s, t;\n    MinCostFlow f;\n\n    weighted_bipartite_matching(int\
    \ L, int R, bool arbitrary_flow = false):\n      L(L), R(R), s(L + R), t(s + 1),\
    \ f(L + R + 2)\n    {\n      for(int i = 0; i < L; ++i) f.add_edge(s, i, 1, 0);\n\
    \      for(int i = 0; i < R; ++i) f.add_edge(L + i, t, 1, 0);\n      if(arbitrary_flow)\
    \ f.add_edge(s, t, std::numeric_limits<int>::max(), 0);\n    }\n\n    void add_edge(int\
    \ from, int to, T gain){\n      f.add_edge(from, L + to, 1, gain * (MIN_MATCHING\
    \ ? 1 : -1));\n    }\n\n    T solve(int flow){\n      T ret = f.solve(s, t, flow).second;\n\
    \      return ret * (MIN_MATCHING ? 1 : -1);\n    }\n\n    auto get_matching(){\n\
    \      const auto g = f.edges();\n      std::vector<std::tuple<int, int, T>> ret;\n\
    \n      for(auto &e : g){\n        if(not e.is_rev and e.from != s and e.to !=\
    \ t and e.cap == 0){\n          ret.emplace_back(e.from, e.to - L, e.cost * (MIN_MATCHING\
    \ ? 1 : -1));\n        }\n      }\n\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <tuple>\n\nnamespace haar_lib {\n\
    \  template <typename T, typename MinCostFlow, bool MIN_MATCHING = false>\n  class\
    \ weighted_bipartite_matching {\n  public:\n    int L, R, s, t;\n    MinCostFlow\
    \ f;\n\n    weighted_bipartite_matching(int L, int R, bool arbitrary_flow = false):\n\
    \      L(L), R(R), s(L + R), t(s + 1), f(L + R + 2)\n    {\n      for(int i =\
    \ 0; i < L; ++i) f.add_edge(s, i, 1, 0);\n      for(int i = 0; i < R; ++i) f.add_edge(L\
    \ + i, t, 1, 0);\n      if(arbitrary_flow) f.add_edge(s, t, std::numeric_limits<int>::max(),\
    \ 0);\n    }\n\n    void add_edge(int from, int to, T gain){\n      f.add_edge(from,\
    \ L + to, 1, gain * (MIN_MATCHING ? 1 : -1));\n    }\n\n    T solve(int flow){\n\
    \      T ret = f.solve(s, t, flow).second;\n      return ret * (MIN_MATCHING ?\
    \ 1 : -1);\n    }\n\n    auto get_matching(){\n      const auto g = f.edges();\n\
    \      std::vector<std::tuple<int, int, T>> ret;\n\n      for(auto &e : g){\n\
    \        if(not e.is_rev and e.from != s and e.to != t and e.cap == 0){\n    \
    \      ret.emplace_back(e.from, e.to - L, e.cost * (MIN_MATCHING ? 1 : -1));\n\
    \        }\n      }\n\n      return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/Matching/weighted_bipartite_matching.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/2293/main.test.cpp
  - test/yosupo-judge/assignment/main.test.cpp
documentation_of: Mylib/Graph/Matching/weighted_bipartite_matching.cpp
layout: document
title: Weighted maximum bipartite matching
---

## Operations

## Requirements

## Notes

## Problems

- [AOJ 2581 Derangement](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2581)
- [AOJ 2429 marukaite](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2429)

## References
