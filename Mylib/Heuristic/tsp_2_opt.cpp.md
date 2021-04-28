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
  bundledCode: "#line 2 \"Mylib/Heuristic/tsp_2_opt.cpp\"\n#include <algorithm>\n\
    #include <random>\n#include <unordered_set>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename F>\n  std::vector<int> tsp_2_opt(int N, int src, F dist)\
    \ {\n    std::mt19937 rand(0);\n    std::vector<int> path(N, -1);\n\n    std::unordered_set<int>\
    \ nodes;\n    for (int i = 0; i < N; ++i)\n      if (i != src) nodes.insert(i);\n\
    \n    int cur = src;\n    for (int i = 0; i < N - 1; ++i) {\n      auto it = std::min_element(\n\
    \          nodes.begin(), nodes.end(),\n          [&](const auto &a, const auto\
    \ &b) { return dist(cur, a) < dist(cur, b); });\n\n      path[cur] = *it;\n  \
    \    cur       = *it;\n\n      nodes.erase(it);\n    }\n\n    path[cur] = src;\n\
    \n    {\n      int LOOP = 10000;\n\n      while (LOOP--) {\n        int i = rand()\
    \ % N;\n        int j = rand() % N;\n\n        int a = path[i];\n        int b\
    \ = path[j];\n\n        if (a == b or i == j or i == a or i == b or j == a or\
    \ j == b) continue;\n\n        if (dist(i, j) + dist(a, b) < dist(i, a) + dist(j,\
    \ b)) {\n          int x = a;\n          int y;\n          int z = path[x];\n\n\
    \          while (true) {\n            y = z;\n            z = path[y];\n\n  \
    \          path[y] = x;\n\n            x = y;\n\n            if (x == j) break;\n\
    \          }\n\n          path[i] = j;\n          path[a] = b;\n        }\n  \
    \    }\n    }\n\n    std::vector<int> ret;\n\n    {\n      int cur = src;\n  \
    \    std::vector<bool> check(N);\n\n      do {\n        ret.push_back(cur);\n\
    \        check[cur] = true;\n\n        int next = path[cur];\n        cur    \
    \  = next;\n      } while ((int) ret.size() < N);\n    }\n\n    return ret;\n\
    \  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <random>\n#include <unordered_set>\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename F>\n  std::vector<int>\
    \ tsp_2_opt(int N, int src, F dist) {\n    std::mt19937 rand(0);\n    std::vector<int>\
    \ path(N, -1);\n\n    std::unordered_set<int> nodes;\n    for (int i = 0; i <\
    \ N; ++i)\n      if (i != src) nodes.insert(i);\n\n    int cur = src;\n    for\
    \ (int i = 0; i < N - 1; ++i) {\n      auto it = std::min_element(\n         \
    \ nodes.begin(), nodes.end(),\n          [&](const auto &a, const auto &b) { return\
    \ dist(cur, a) < dist(cur, b); });\n\n      path[cur] = *it;\n      cur      \
    \ = *it;\n\n      nodes.erase(it);\n    }\n\n    path[cur] = src;\n\n    {\n \
    \     int LOOP = 10000;\n\n      while (LOOP--) {\n        int i = rand() % N;\n\
    \        int j = rand() % N;\n\n        int a = path[i];\n        int b = path[j];\n\
    \n        if (a == b or i == j or i == a or i == b or j == a or j == b) continue;\n\
    \n        if (dist(i, j) + dist(a, b) < dist(i, a) + dist(j, b)) {\n         \
    \ int x = a;\n          int y;\n          int z = path[x];\n\n          while\
    \ (true) {\n            y = z;\n            z = path[y];\n\n            path[y]\
    \ = x;\n\n            x = y;\n\n            if (x == j) break;\n          }\n\n\
    \          path[i] = j;\n          path[a] = b;\n        }\n      }\n    }\n\n\
    \    std::vector<int> ret;\n\n    {\n      int cur = src;\n      std::vector<bool>\
    \ check(N);\n\n      do {\n        ret.push_back(cur);\n        check[cur] = true;\n\
    \n        int next = path[cur];\n        cur      = next;\n      } while ((int)\
    \ ret.size() < N);\n    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Heuristic/tsp_2_opt.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Heuristic/tsp_2_opt.cpp
layout: document
title: TSP 2-opt
---

## Operations

## Requirements

## Notes

## Problems

## References
