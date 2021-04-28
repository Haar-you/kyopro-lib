---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2171/main.test.cpp
    title: test/aoj/2171/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/ShortestPath/warshall_floyd_for_matrix_graph.cpp\"\
    \n#include <optional>\n#include <vector>\n\nnamespace haar_lib {\n  namespace\
    \ warshall_floyd_for_matrix_impl {\n    template <typename T>\n    struct result\
    \ {\n      std::vector<std::vector<std::optional<T>>> dist;\n      bool has_negative_cycle;\n\
    \      const auto& operator[](int i) const { return dist[i]; }\n    };\n  }  //\
    \ namespace warshall_floyd_for_matrix_impl\n\n  template <typename T, T INVALID>\n\
    \  auto warshall_floyd_for_matrix(const std::vector<std::vector<T>>& g) {\n  \
    \  const int n = g.size();\n    auto dist   = std::vector(n, std::vector<std::optional<T>>(n));\n\
    \n    for (int i = 0; i < n; ++i) dist[i][i] = 0;\n\n    for (int i = 0; i < n;\
    \ ++i) {\n      for (int j = 0; j < n; ++j) {\n        if (g[i][j] != INVALID)\
    \ {\n          dist[i][j] = g[i][j];\n        }\n      }\n    }\n\n    for (int\
    \ k = 0; k < n; ++k) {\n      for (int i = 0; i < n; ++i) {\n        for (int\
    \ j = 0; j < n; ++j) {\n          if (dist[i][k] and dist[k][j]) {\n         \
    \   if (not dist[i][j]) {\n              dist[i][j] = *dist[i][k] + *dist[k][j];\n\
    \            } else {\n              dist[i][j] = std::min(*dist[i][j], *dist[i][k]\
    \ + *dist[k][j]);\n            }\n          }\n        }\n      }\n    }\n\n \
    \   bool has_negative_cycle = false;\n    for (int i = 0; i < n; ++i)\n      if\
    \ (*dist[i][i] < 0) has_negative_cycle = true;\n\n    return warshall_floyd_for_matrix_impl::result<T>{dist,\
    \ has_negative_cycle};\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <optional>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  namespace warshall_floyd_for_matrix_impl {\n    template <typename T>\n\
    \    struct result {\n      std::vector<std::vector<std::optional<T>>> dist;\n\
    \      bool has_negative_cycle;\n      const auto& operator[](int i) const { return\
    \ dist[i]; }\n    };\n  }  // namespace warshall_floyd_for_matrix_impl\n\n  template\
    \ <typename T, T INVALID>\n  auto warshall_floyd_for_matrix(const std::vector<std::vector<T>>&\
    \ g) {\n    const int n = g.size();\n    auto dist   = std::vector(n, std::vector<std::optional<T>>(n));\n\
    \n    for (int i = 0; i < n; ++i) dist[i][i] = 0;\n\n    for (int i = 0; i < n;\
    \ ++i) {\n      for (int j = 0; j < n; ++j) {\n        if (g[i][j] != INVALID)\
    \ {\n          dist[i][j] = g[i][j];\n        }\n      }\n    }\n\n    for (int\
    \ k = 0; k < n; ++k) {\n      for (int i = 0; i < n; ++i) {\n        for (int\
    \ j = 0; j < n; ++j) {\n          if (dist[i][k] and dist[k][j]) {\n         \
    \   if (not dist[i][j]) {\n              dist[i][j] = *dist[i][k] + *dist[k][j];\n\
    \            } else {\n              dist[i][j] = std::min(*dist[i][j], *dist[i][k]\
    \ + *dist[k][j]);\n            }\n          }\n        }\n      }\n    }\n\n \
    \   bool has_negative_cycle = false;\n    for (int i = 0; i < n; ++i)\n      if\
    \ (*dist[i][i] < 0) has_negative_cycle = true;\n\n    return warshall_floyd_for_matrix_impl::result<T>{dist,\
    \ has_negative_cycle};\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/ShortestPath/warshall_floyd_for_matrix_graph.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2171/main.test.cpp
documentation_of: Mylib/Graph/ShortestPath/warshall_floyd_for_matrix_graph.cpp
layout: document
title: Warshall-Floyd algorithm (For adjacency matrix graph)
---

## Operations

## Requirements

## Notes

## Problems

## References
