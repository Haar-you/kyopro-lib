---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1615/main.test.cpp
    title: test/aoj/1615/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/Flow/max_flow_with_lower_bound.cpp\"\n#include\
    \ <optional>\n#include <cassert>\n\nnamespace haar_lib {\n  template <typename\
    \ Flow>\n  class max_flow_with_lower_bound {\n    using edge = typename Flow::edge;\n\
    \    using capacity_type = typename Flow::capacity_type;\n\n    int N_, S_, T_;\n\
    \    Flow flow_;\n    capacity_type min_sum_;\n\n  public:\n    max_flow_with_lower_bound(){}\n\
    \    max_flow_with_lower_bound(int N): N_(N), S_(N), T_(N + 1), flow_(N + 2),\
    \ min_sum_(0){}\n\n    void add_edge(int from, int to, capacity_type lb, capacity_type\
    \ ub){\n      assert(0 <= from and from < N_);\n      assert(0 <= to and to <\
    \ N_);\n      assert(0 <= lb and lb <= ub);\n\n      flow_.add_edge(from, to,\
    \ ub - lb);\n      flow_.add_edge(from, T_, lb);\n      flow_.add_edge(S_, to,\
    \ lb);\n\n      min_sum_ += lb;\n    }\n\n    std::optional<capacity_type> max_flow(int\
    \ s, int t){\n      assert(0 <= s and s < N_);\n      assert(0 <= t and t < N_);\n\
    \n      auto a = flow_.max_flow(S_, T_);\n      auto b = flow_.max_flow(s, T_);\n\
    \      auto c = flow_.max_flow(S_, t);\n      auto d = flow_.max_flow(s, t);\n\
    \n      if(a + b == min_sum_ and a + c == min_sum_) return b + d;\n      return\
    \ std::nullopt;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <optional>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  template <typename Flow>\n  class max_flow_with_lower_bound {\n    using\
    \ edge = typename Flow::edge;\n    using capacity_type = typename Flow::capacity_type;\n\
    \n    int N_, S_, T_;\n    Flow flow_;\n    capacity_type min_sum_;\n\n  public:\n\
    \    max_flow_with_lower_bound(){}\n    max_flow_with_lower_bound(int N): N_(N),\
    \ S_(N), T_(N + 1), flow_(N + 2), min_sum_(0){}\n\n    void add_edge(int from,\
    \ int to, capacity_type lb, capacity_type ub){\n      assert(0 <= from and from\
    \ < N_);\n      assert(0 <= to and to < N_);\n      assert(0 <= lb and lb <= ub);\n\
    \n      flow_.add_edge(from, to, ub - lb);\n      flow_.add_edge(from, T_, lb);\n\
    \      flow_.add_edge(S_, to, lb);\n\n      min_sum_ += lb;\n    }\n\n    std::optional<capacity_type>\
    \ max_flow(int s, int t){\n      assert(0 <= s and s < N_);\n      assert(0 <=\
    \ t and t < N_);\n\n      auto a = flow_.max_flow(S_, T_);\n      auto b = flow_.max_flow(s,\
    \ T_);\n      auto c = flow_.max_flow(S_, t);\n      auto d = flow_.max_flow(s,\
    \ t);\n\n      if(a + b == min_sum_ and a + c == min_sum_) return b + d;\n   \
    \   return std::nullopt;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/Flow/max_flow_with_lower_bound.cpp
  requiredBy: []
  timestamp: '2020-09-27 06:31:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1615/main.test.cpp
documentation_of: Mylib/Graph/Flow/max_flow_with_lower_bound.cpp
layout: document
title: Maximum flow with lower bound
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://snuke.hatenablog.com/entry/2016/07/10/043918](https://snuke.hatenablog.com/entry/2016/07/10/043918)
- [https://ei1333.github.io/luzhiled/snippets/graph/maxflow-lower-bound.html](https://ei1333.github.io/luzhiled/snippets/graph/maxflow-lower-bound.html)
- [https://tubo28.me/compprog/algorithm/flow_with_lu_bound/](https://tubo28.me/compprog/algorithm/flow_with_lu_bound/)
