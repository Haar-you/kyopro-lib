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
  bundledCode: "#line 2 \"Mylib/Graph/DAG/dag_longest_path.cpp\"\n#include <vector>\n\
    #include <algorithm>\n\nnamespace haar_lib {\n  int dag_longest_path(const std::vector<std::vector<int>>\
    \ &g){\n    const int n = g.size();\n    std::vector<int> ret(n);\n    std::vector<bool>\
    \ visited(n);\n\n    auto dfs =\n      [&](auto &f, int cur) -> int {\n      \
    \  if(visited[cur]) return ret[cur];\n        visited[cur] = true;\n\n       \
    \ for(auto &nxt : g[cur]){\n          ret[cur] = std::max(ret[cur], f(f, nxt)\
    \ + 1);\n        }\n\n        return ret[cur];\n      };\n\n    for(int i = 0;\
    \ i < n; ++i) if(not visited[i]) dfs(dfs, i);\n\n    return *std::max_element(ret.begin(),\
    \ ret.end());\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n\nnamespace haar_lib\
    \ {\n  int dag_longest_path(const std::vector<std::vector<int>> &g){\n    const\
    \ int n = g.size();\n    std::vector<int> ret(n);\n    std::vector<bool> visited(n);\n\
    \n    auto dfs =\n      [&](auto &f, int cur) -> int {\n        if(visited[cur])\
    \ return ret[cur];\n        visited[cur] = true;\n\n        for(auto &nxt : g[cur]){\n\
    \          ret[cur] = std::max(ret[cur], f(f, nxt) + 1);\n        }\n\n      \
    \  return ret[cur];\n      };\n\n    for(int i = 0; i < n; ++i) if(not visited[i])\
    \ dfs(dfs, i);\n\n    return *std::max_element(ret.begin(), ret.end());\n  }\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/DAG/dag_longest_path.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
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
