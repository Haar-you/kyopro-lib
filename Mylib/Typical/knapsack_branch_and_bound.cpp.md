---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_1_H/main.test.bb.cpp
    title: test/aoj/DPL_1_H/main.test.bb.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/knapsack_branch_and_bound.cpp\"\n\n#include\
    \ <algorithm>\n#include <numeric>\n#include <vector>\n\nnamespace haar_lib {\n\
    \  template <typename Weight, typename Value>\n  Value knapsack_branch_and_bound(\n\
    \      int N, Weight cap, const std::vector<Weight> &weight, const std::vector<Value>\
    \ &value) {\n    std::vector<int> ord(N);\n    std::iota(ord.begin(), ord.end(),\
    \ 0);\n\n    std::sort(\n        ord.begin(), ord.end(),\n        [&](int i, int\
    \ j) {\n          return (double) value[i] / weight[i] > (double) value[j] / weight[j];\n\
    \        });\n\n    Value feasible_sol = 0;\n\n    auto dfs =\n        [&](auto\
    \ &dfs, int k, Weight w, Value v) -> Value {\n      if (w > cap) return 0;\n \
    \     if (k == N) {\n        feasible_sol = std::max(feasible_sol, v);\n     \
    \   return v;\n      }\n\n      bool is_opt  = true;\n      Value sol    = 0;\n\
    \      Weight w_sum = 0;\n      int p        = 0;\n\n      for (p = k; p < N;\
    \ ++p) {\n        if (w_sum + weight[ord[p]] >= cap - w) {\n          if (w_sum\
    \ + weight[ord[p]] == cap - w) {\n            w_sum += weight[ord[p]];\n     \
    \       sol += value[ord[p]];\n          } else {\n            is_opt = false;\n\
    \          }\n\n          break;\n        } else {\n          w_sum += weight[ord[p]];\n\
    \          sol += value[ord[p]];\n        }\n      }\n\n      if (is_opt) return\
    \ feasible_sol = std::max(feasible_sol, v + sol);\n\n      double d = (double)\
    \ value[ord[p]] / weight[ord[p]] * (cap - w - w_sum);\n      if ((double) v +\
    \ sol + d < feasible_sol) {\n        return 0;\n      }\n\n      Value ret = 0;\n\
    \n      if (w + weight[ord[k]] <= cap) {\n        ret          = std::max(ret,\
    \ dfs(dfs, k + 1, w + weight[ord[k]], v + value[ord[k]]));\n        feasible_sol\
    \ = std::max(feasible_sol, ret);\n      }\n\n      ret          = std::max(ret,\
    \ dfs(dfs, k + 1, w, v));\n      feasible_sol = std::max(feasible_sol, ret);\n\
    \n      return ret;\n    };\n\n    auto ret = dfs(dfs, 0, 0, 0);\n    return ret;\n\
    \  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <numeric>\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename Weight, typename Value>\n  Value\
    \ knapsack_branch_and_bound(\n      int N, Weight cap, const std::vector<Weight>\
    \ &weight, const std::vector<Value> &value) {\n    std::vector<int> ord(N);\n\
    \    std::iota(ord.begin(), ord.end(), 0);\n\n    std::sort(\n        ord.begin(),\
    \ ord.end(),\n        [&](int i, int j) {\n          return (double) value[i]\
    \ / weight[i] > (double) value[j] / weight[j];\n        });\n\n    Value feasible_sol\
    \ = 0;\n\n    auto dfs =\n        [&](auto &dfs, int k, Weight w, Value v) ->\
    \ Value {\n      if (w > cap) return 0;\n      if (k == N) {\n        feasible_sol\
    \ = std::max(feasible_sol, v);\n        return v;\n      }\n\n      bool is_opt\
    \  = true;\n      Value sol    = 0;\n      Weight w_sum = 0;\n      int p    \
    \    = 0;\n\n      for (p = k; p < N; ++p) {\n        if (w_sum + weight[ord[p]]\
    \ >= cap - w) {\n          if (w_sum + weight[ord[p]] == cap - w) {\n        \
    \    w_sum += weight[ord[p]];\n            sol += value[ord[p]];\n          }\
    \ else {\n            is_opt = false;\n          }\n\n          break;\n     \
    \   } else {\n          w_sum += weight[ord[p]];\n          sol += value[ord[p]];\n\
    \        }\n      }\n\n      if (is_opt) return feasible_sol = std::max(feasible_sol,\
    \ v + sol);\n\n      double d = (double) value[ord[p]] / weight[ord[p]] * (cap\
    \ - w - w_sum);\n      if ((double) v + sol + d < feasible_sol) {\n        return\
    \ 0;\n      }\n\n      Value ret = 0;\n\n      if (w + weight[ord[k]] <= cap)\
    \ {\n        ret          = std::max(ret, dfs(dfs, k + 1, w + weight[ord[k]],\
    \ v + value[ord[k]]));\n        feasible_sol = std::max(feasible_sol, ret);\n\
    \      }\n\n      ret          = std::max(ret, dfs(dfs, k + 1, w, v));\n     \
    \ feasible_sol = std::max(feasible_sol, ret);\n\n      return ret;\n    };\n\n\
    \    auto ret = dfs(dfs, 0, 0, 0);\n    return ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/knapsack_branch_and_bound.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DPL_1_H/main.test.bb.cpp
documentation_of: Mylib/Typical/knapsack_branch_and_bound.cpp
layout: document
title: 0-1 Knapsack problem (Branch and bound)
---

## Operations

## Requirements

## Notes

## Problems

- [ABC032 D - ナップサック問題](https://atcoder.jp/contests/abc032/tasks/abc032_d)
- [ABC184 F - Programming Contest](https://atcoder.jp/contests/abc184/tasks/abc184_f) (TLE)

## References

- [https://qiita.com/hamko/items/cceb1a92da14e2755527](https://qiita.com/hamko/items/cceb1a92da14e2755527)
