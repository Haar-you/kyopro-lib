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
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/Matching/bipartite_matching.cpp\"\n#include\
    \ <vector>\n#include <utility>\n#include <climits>\n#include <cassert>\n\nnamespace\
    \ haar_lib {\n  template <typename MaxFlow>\n  class bipartite_matching {\n  \
    \  int L, R, s, t;\n    MaxFlow f;\n\n  public:\n    bipartite_matching(int L,\
    \ int R): L(L), R(R), s(L + R), t(s + 1), f(L + R + 2){\n      for(int i = 0;\
    \ i < L; ++i) f.add_edge(s, i, 1);\n      for(int i = 0; i < R; ++i) f.add_edge(L\
    \ + i, t, 1);\n    }\n\n    void add_edge(int i, int j){\n      assert(0 <= i\
    \ and i < L and 0 <= j and j < R);\n      f.add_edge(i, L + j, 1);\n    }\n\n\
    \    int solve(){\n      return f.solve(s, t);\n    }\n\n    auto get_matching(){\n\
    \      const auto g = f.edges();\n      std::vector<std::pair<int, int>> ret;\n\
    \n      for(auto &e : g){\n        if(not e.is_rev and e.cap == 0 and e.from !=\
    \ s and e.to != t){\n          ret.emplace_back(e.from, e.to - L);\n        }\n\
    \      }\n\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <climits>\n\
    #include <cassert>\n\nnamespace haar_lib {\n  template <typename MaxFlow>\n  class\
    \ bipartite_matching {\n    int L, R, s, t;\n    MaxFlow f;\n\n  public:\n   \
    \ bipartite_matching(int L, int R): L(L), R(R), s(L + R), t(s + 1), f(L + R +\
    \ 2){\n      for(int i = 0; i < L; ++i) f.add_edge(s, i, 1);\n      for(int i\
    \ = 0; i < R; ++i) f.add_edge(L + i, t, 1);\n    }\n\n    void add_edge(int i,\
    \ int j){\n      assert(0 <= i and i < L and 0 <= j and j < R);\n      f.add_edge(i,\
    \ L + j, 1);\n    }\n\n    int solve(){\n      return f.solve(s, t);\n    }\n\n\
    \    auto get_matching(){\n      const auto g = f.edges();\n      std::vector<std::pair<int,\
    \ int>> ret;\n\n      for(auto &e : g){\n        if(not e.is_rev and e.cap ==\
    \ 0 and e.from != s and e.to != t){\n          ret.emplace_back(e.from, e.to -\
    \ L);\n        }\n      }\n\n      return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/Matching/bipartite_matching.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
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
