---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2293/main.test.cpp
    title: test/aoj/2293/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/assignment/main.test.cpp
    title: test/yosupo-judge/assignment/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/Matching/weighted_bipartite_matching.cpp\"\n\
    #include <vector>\n#include <tuple>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename MinCostFlow, bool MIN_MATCHING = false>\n\
    \  class weighted_bipartite_matching {\n    int L_, R_, s_, t_;\n    MinCostFlow\
    \ f_;\n\n  public:\n    weighted_bipartite_matching(){}\n    weighted_bipartite_matching(int\
    \ L, int R, bool arbitrary_flow = false):\n      L_(L), R_(R), s_(L + R), t_(s_\
    \ + 1), f_(L + R + 2)\n    {\n      for(int i = 0; i < L_; ++i) f_.add_edge(s_,\
    \ i, 1, 0);\n      for(int i = 0; i < R_; ++i) f_.add_edge(L_ + i, t_, 1, 0);\n\
    \      if(arbitrary_flow) f_.add_edge(s_, t_, std::numeric_limits<int>::max(),\
    \ 0);\n    }\n\n    void add_edge(int from, int to, T gain){\n      assert(0 <=\
    \ from and from < L_);\n      assert(0 <= to and to < R_);\n      f_.add_edge(from,\
    \ L_ + to, 1, gain * (MIN_MATCHING ? 1 : -1));\n    }\n\n    T match(int flow){\n\
    \      T ret = f_.min_cost_flow(s_, t_, flow).second;\n      return ret * (MIN_MATCHING\
    \ ? 1 : -1);\n    }\n\n    auto get_matching(){\n      const auto g = f_.edges();\n\
    \      std::vector<std::tuple<int, int, T>> ret;\n\n      for(auto &e : g){\n\
    \        if(not e.is_rev and e.from != s_ and e.to != t_ and e.cap == 0){\n  \
    \        ret.emplace_back(e.from, e.to - L_, e.cost * (MIN_MATCHING ? 1 : -1));\n\
    \        }\n      }\n\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <tuple>\n#include <cassert>\n\n\
    namespace haar_lib {\n  template <typename T, typename MinCostFlow, bool MIN_MATCHING\
    \ = false>\n  class weighted_bipartite_matching {\n    int L_, R_, s_, t_;\n \
    \   MinCostFlow f_;\n\n  public:\n    weighted_bipartite_matching(){}\n    weighted_bipartite_matching(int\
    \ L, int R, bool arbitrary_flow = false):\n      L_(L), R_(R), s_(L + R), t_(s_\
    \ + 1), f_(L + R + 2)\n    {\n      for(int i = 0; i < L_; ++i) f_.add_edge(s_,\
    \ i, 1, 0);\n      for(int i = 0; i < R_; ++i) f_.add_edge(L_ + i, t_, 1, 0);\n\
    \      if(arbitrary_flow) f_.add_edge(s_, t_, std::numeric_limits<int>::max(),\
    \ 0);\n    }\n\n    void add_edge(int from, int to, T gain){\n      assert(0 <=\
    \ from and from < L_);\n      assert(0 <= to and to < R_);\n      f_.add_edge(from,\
    \ L_ + to, 1, gain * (MIN_MATCHING ? 1 : -1));\n    }\n\n    T match(int flow){\n\
    \      T ret = f_.min_cost_flow(s_, t_, flow).second;\n      return ret * (MIN_MATCHING\
    \ ? 1 : -1);\n    }\n\n    auto get_matching(){\n      const auto g = f_.edges();\n\
    \      std::vector<std::tuple<int, int, T>> ret;\n\n      for(auto &e : g){\n\
    \        if(not e.is_rev and e.from != s_ and e.to != t_ and e.cap == 0){\n  \
    \        ret.emplace_back(e.from, e.to - L_, e.cost * (MIN_MATCHING ? 1 : -1));\n\
    \        }\n      }\n\n      return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/Matching/weighted_bipartite_matching.cpp
  requiredBy: []
  timestamp: '2020-10-10 11:12:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/assignment/main.test.cpp
  - test/aoj/2293/main.test.cpp
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
