---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/DAG/dag_longest_path.cpp\"\n#include <algorithm>\n\
    #include <vector>\n\nnamespace haar_lib {\n  int dag_longest_path(const std::vector<std::vector<int>>\
    \ &g) {\n    const int n = g.size();\n    std::vector<int> ret(n);\n    std::vector<bool>\
    \ visited(n);\n\n    auto dfs =\n        [&](auto &f, int cur) -> int {\n    \
    \  if (visited[cur]) return ret[cur];\n      visited[cur] = true;\n\n      for\
    \ (auto &nxt : g[cur]) {\n        ret[cur] = std::max(ret[cur], f(f, nxt) + 1);\n\
    \      }\n\n      return ret[cur];\n    };\n\n    for (int i = 0; i < n; ++i)\n\
    \      if (not visited[i]) dfs(dfs, i);\n\n    return *std::max_element(ret.begin(),\
    \ ret.end());\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  int dag_longest_path(const std::vector<std::vector<int>> &g) {\n    const\
    \ int n = g.size();\n    std::vector<int> ret(n);\n    std::vector<bool> visited(n);\n\
    \n    auto dfs =\n        [&](auto &f, int cur) -> int {\n      if (visited[cur])\
    \ return ret[cur];\n      visited[cur] = true;\n\n      for (auto &nxt : g[cur])\
    \ {\n        ret[cur] = std::max(ret[cur], f(f, nxt) + 1);\n      }\n\n      return\
    \ ret[cur];\n    };\n\n    for (int i = 0; i < n; ++i)\n      if (not visited[i])\
    \ dfs(dfs, i);\n\n    return *std::max_element(ret.begin(), ret.end());\n  }\n\
    }  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/DAG/dag_longest_path.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/DAG/dag_longest_path.cpp
layout: document
title: Longest path on DAG
---

## Operations

## Requirements

## Notes

## Problems

## References
