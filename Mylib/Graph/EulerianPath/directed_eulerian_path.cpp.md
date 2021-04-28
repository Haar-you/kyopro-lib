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
  bundledCode: "#line 2 \"Mylib/Graph/EulerianPath/directed_eulerian_path.cpp\"\n\
    #include <algorithm>\n#include <map>\n#include <optional>\n#include <vector>\n\
    \nnamespace haar_lib {\n  class directed_eulerian_path {\n    int n_, edges_;\n\
    \    std::vector<std::map<int, int>> g_;\n    std::vector<int> indeg_, outdeg_;\n\
    \n    void del(int i, int j) {\n      if (g_[i][j] == 1)\n        g_[i].erase(j);\n\
    \      else\n        --g_[i][j];\n    }\n\n    void dfs(int cur, std::vector<int>\
    \ &path) {\n      if (not g_[cur].empty()) {\n        const int next = g_[cur].begin()->first;\n\
    \        del(cur, next);\n        dfs(next, path);\n      }\n\n      while (not\
    \ g_[cur].empty()) {\n        const int next = g_[cur].begin()->first;\n     \
    \   del(cur, next);\n        std::vector<int> temp;\n        dfs(next, temp);\n\
    \        path.insert(path.end(), temp.begin(), temp.end());\n      }\n\n     \
    \ path.push_back(cur);\n    }\n\n  public:\n    directed_eulerian_path() {}\n\
    \    directed_eulerian_path(int n) : n_(n), edges_(0), g_(n), indeg_(n), outdeg_(n)\
    \ {}\n\n    void add_edge(int i, int j) {\n      ++g_[i][j];\n      ++outdeg_[i];\n\
    \      ++indeg_[j];\n      ++edges_;\n    }\n\n    std::optional<std::vector<int>>\
    \ eulerian_path() {\n      int in = 0, out = 0, start = 0;\n\n      for (int i\
    \ = 0; i < n_; ++i) {\n        const int d = outdeg_[i] - indeg_[i];\n       \
    \ if (std::abs(d) > 1) return std::nullopt;\n        if (d == 1) {\n         \
    \ ++out;\n          start = i;\n        } else if (d == -1) {\n          ++in;\n\
    \        }\n      }\n\n      if (not((in == 0 and out == 0) or (in == 1 and out\
    \ == 1))) return std::nullopt;\n\n      std::vector<int> ret;\n\n      dfs(start,\
    \ ret);\n      std::reverse(ret.begin(), ret.end());\n      if ((int) ret.size()\
    \ == edges_ + 1) {\n        return ret;\n      } else {\n        return std::nullopt;\n\
    \      }\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <map>\n#include <optional>\n\
    #include <vector>\n\nnamespace haar_lib {\n  class directed_eulerian_path {\n\
    \    int n_, edges_;\n    std::vector<std::map<int, int>> g_;\n    std::vector<int>\
    \ indeg_, outdeg_;\n\n    void del(int i, int j) {\n      if (g_[i][j] == 1)\n\
    \        g_[i].erase(j);\n      else\n        --g_[i][j];\n    }\n\n    void dfs(int\
    \ cur, std::vector<int> &path) {\n      if (not g_[cur].empty()) {\n        const\
    \ int next = g_[cur].begin()->first;\n        del(cur, next);\n        dfs(next,\
    \ path);\n      }\n\n      while (not g_[cur].empty()) {\n        const int next\
    \ = g_[cur].begin()->first;\n        del(cur, next);\n        std::vector<int>\
    \ temp;\n        dfs(next, temp);\n        path.insert(path.end(), temp.begin(),\
    \ temp.end());\n      }\n\n      path.push_back(cur);\n    }\n\n  public:\n  \
    \  directed_eulerian_path() {}\n    directed_eulerian_path(int n) : n_(n), edges_(0),\
    \ g_(n), indeg_(n), outdeg_(n) {}\n\n    void add_edge(int i, int j) {\n     \
    \ ++g_[i][j];\n      ++outdeg_[i];\n      ++indeg_[j];\n      ++edges_;\n    }\n\
    \n    std::optional<std::vector<int>> eulerian_path() {\n      int in = 0, out\
    \ = 0, start = 0;\n\n      for (int i = 0; i < n_; ++i) {\n        const int d\
    \ = outdeg_[i] - indeg_[i];\n        if (std::abs(d) > 1) return std::nullopt;\n\
    \        if (d == 1) {\n          ++out;\n          start = i;\n        } else\
    \ if (d == -1) {\n          ++in;\n        }\n      }\n\n      if (not((in ==\
    \ 0 and out == 0) or (in == 1 and out == 1))) return std::nullopt;\n\n      std::vector<int>\
    \ ret;\n\n      dfs(start, ret);\n      std::reverse(ret.begin(), ret.end());\n\
    \      if ((int) ret.size() == edges_ + 1) {\n        return ret;\n      } else\
    \ {\n        return std::nullopt;\n      }\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/EulerianPath/directed_eulerian_path.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/EulerianPath/directed_eulerian_path.cpp
layout: document
title: Directed Eulerian path
---

## Operations

## Requirements

## Notes

## Problems

- [Codeforces Round #288 (Div. 2) D. Tanya and Password](https://codeforces.com/contest/508/problem/D)

## References

