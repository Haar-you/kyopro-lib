---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_7_A/main.test.cpp
    title: test/aoj/GRL_7_A/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/Matching/bipartite_matching.cpp\"\n#include\
    \ <vector>\n#include <utility>\n#include <cassert>\n\nnamespace haar_lib {\n \
    \ template <typename MaxFlow>\n  class bipartite_matching {\n    int L_, R_, s_,\
    \ t_;\n    MaxFlow f_;\n\n  public:\n    bipartite_matching(){}\n    bipartite_matching(int\
    \ L, int R):\n      L_(L), R_(R), s_(L + R), t_(s_ + 1), f_(L + R + 2){\n    \
    \  for(int i = 0; i < L_; ++i) f_.add_edge(s_, i, 1);\n      for(int i = 0; i\
    \ < R_; ++i) f_.add_edge(L_ + i, t_, 1);\n    }\n\n    void add_edge(int i, int\
    \ j){\n      assert(0 <= i and i < L_ and 0 <= j and j < R_);\n      f_.add_edge(i,\
    \ L_ + j, 1);\n    }\n\n    int match(){\n      return f_.max_flow(s_, t_);\n\
    \    }\n\n    auto get_matching(){\n      const auto g = f_.edges();\n      std::vector<std::pair<int,\
    \ int>> ret;\n\n      for(auto &e : g){\n        if(not e.is_rev and e.cap ==\
    \ 0 and e.from != s_ and e.to != t_){\n          ret.emplace_back(e.from, e.to\
    \ - L_);\n        }\n      }\n\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <cassert>\n\
    \nnamespace haar_lib {\n  template <typename MaxFlow>\n  class bipartite_matching\
    \ {\n    int L_, R_, s_, t_;\n    MaxFlow f_;\n\n  public:\n    bipartite_matching(){}\n\
    \    bipartite_matching(int L, int R):\n      L_(L), R_(R), s_(L + R), t_(s_ +\
    \ 1), f_(L + R + 2){\n      for(int i = 0; i < L_; ++i) f_.add_edge(s_, i, 1);\n\
    \      for(int i = 0; i < R_; ++i) f_.add_edge(L_ + i, t_, 1);\n    }\n\n    void\
    \ add_edge(int i, int j){\n      assert(0 <= i and i < L_ and 0 <= j and j < R_);\n\
    \      f_.add_edge(i, L_ + j, 1);\n    }\n\n    int match(){\n      return f_.max_flow(s_,\
    \ t_);\n    }\n\n    auto get_matching(){\n      const auto g = f_.edges();\n\
    \      std::vector<std::pair<int, int>> ret;\n\n      for(auto &e : g){\n    \
    \    if(not e.is_rev and e.cap == 0 and e.from != s_ and e.to != t_){\n      \
    \    ret.emplace_back(e.from, e.to - L_);\n        }\n      }\n\n      return\
    \ ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/Matching/bipartite_matching.cpp
  requiredBy: []
  timestamp: '2020-10-10 11:12:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_7_A/main.test.cpp
documentation_of: Mylib/Graph/Matching/bipartite_matching.cpp
layout: document
title: Maximum bipartite matching
---

## Operations

## Requirements

## Notes

## Problems

## References
