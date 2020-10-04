---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/EulerianPath/undirected_eulerian_path.cpp\"\n\
    #include <vector>\n#include <map>\n#include <optional>\n\nnamespace haar_lib {\n\
    \  class undirected_eulerian_path {\n    int n_, edges_;\n    std::vector<std::map<int,\
    \ int>> g_;\n    std::vector<int> deg_;\n\n    void del(int i, int j){\n     \
    \ if(g_[i][j] == 1) g_[i].erase(j);\n      else --g_[i][j];\n\n      if(g_[j][i]\
    \ == 1) g_[j].erase(i);\n      else --g_[j][i];\n    }\n\n    void dfs(int cur,\
    \ std::vector<int> &path){\n      if(not g_[cur].empty()){\n        int next =\
    \ g_[cur].begin()->first;\n        del(cur, next);\n        dfs(next, path);\n\
    \      }\n\n      while(not g_[cur].empty()){\n        int next = g_[cur].begin()->first;\n\
    \        del(cur, next);\n        std::vector<int> temp;\n        dfs(next, temp);\n\
    \        path.insert(path.end(), temp.begin(), temp.end());\n      }\n\n     \
    \ path.push_back(cur);\n    }\n\n  public:\n    undirected_eulerian_path(){}\n\
    \    undirected_eulerian_path(int n): n_(n), edges_(0), g_(n), deg_(n){}\n\n \
    \   void add_edge(int i, int j){\n      ++g_[i][j];\n      ++g_[j][i];\n     \
    \ ++deg_[i];\n      ++deg_[j];\n      ++edges_;\n    }\n\n    std::optional<std::vector<int>>\
    \ eulerian_path(){\n      std::vector<int> ret;\n\n      int odd = 0, start =\
    \ 0;\n      for(int i = 0; i < n_; ++i){\n        if(deg_[i] % 2 == 1){\n    \
    \      ++odd;\n          start = i;\n        }\n      }\n\n      if(odd != 0 and\
    \ odd != 2) return std::nullopt;\n\n      dfs(start, ret);\n\n      if((int)ret.size()\
    \ == edges_ + 1){\n        return ret;\n      }else{\n        return std::nullopt;\n\
    \      }\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <map>\n#include <optional>\n\n\
    namespace haar_lib {\n  class undirected_eulerian_path {\n    int n_, edges_;\n\
    \    std::vector<std::map<int, int>> g_;\n    std::vector<int> deg_;\n\n    void\
    \ del(int i, int j){\n      if(g_[i][j] == 1) g_[i].erase(j);\n      else --g_[i][j];\n\
    \n      if(g_[j][i] == 1) g_[j].erase(i);\n      else --g_[j][i];\n    }\n\n \
    \   void dfs(int cur, std::vector<int> &path){\n      if(not g_[cur].empty()){\n\
    \        int next = g_[cur].begin()->first;\n        del(cur, next);\n       \
    \ dfs(next, path);\n      }\n\n      while(not g_[cur].empty()){\n        int\
    \ next = g_[cur].begin()->first;\n        del(cur, next);\n        std::vector<int>\
    \ temp;\n        dfs(next, temp);\n        path.insert(path.end(), temp.begin(),\
    \ temp.end());\n      }\n\n      path.push_back(cur);\n    }\n\n  public:\n  \
    \  undirected_eulerian_path(){}\n    undirected_eulerian_path(int n): n_(n), edges_(0),\
    \ g_(n), deg_(n){}\n\n    void add_edge(int i, int j){\n      ++g_[i][j];\n  \
    \    ++g_[j][i];\n      ++deg_[i];\n      ++deg_[j];\n      ++edges_;\n    }\n\
    \n    std::optional<std::vector<int>> eulerian_path(){\n      std::vector<int>\
    \ ret;\n\n      int odd = 0, start = 0;\n      for(int i = 0; i < n_; ++i){\n\
    \        if(deg_[i] % 2 == 1){\n          ++odd;\n          start = i;\n     \
    \   }\n      }\n\n      if(odd != 0 and odd != 2) return std::nullopt;\n\n   \
    \   dfs(start, ret);\n\n      if((int)ret.size() == edges_ + 1){\n        return\
    \ ret;\n      }else{\n        return std::nullopt;\n      }\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/EulerianPath/undirected_eulerian_path.cpp
  requiredBy: []
  timestamp: '2020-10-03 19:28:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/EulerianPath/undirected_eulerian_path.cpp
layout: document
title: Undirected Eulerian path
---

## Operations

## Requirements

## Notes

## Problems

- [Codeforces Round #554 (Div. 2) E. Neko and Flashback](https://codeforces.com/contest/1152/problem/E)

## References

