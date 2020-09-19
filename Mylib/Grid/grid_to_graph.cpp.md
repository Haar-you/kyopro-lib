---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Grid/grid.cpp
    title: Grid template
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0558/main.graph.test.cpp
    title: test/aoj/0558/main.graph.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Grid/grid_to_graph.cpp\"\n#include <vector>\n#line\
    \ 2 \"Mylib/Grid/grid.cpp\"\n#include <array>\n#include <iostream>\n#include <utility>\n\
    \nnamespace haar_lib {\n  struct cell {\n    int x, y;\n    cell(): x(0), y(0){}\n\
    \    cell(int x, int y): x(x), y(y){}\n    cell& operator+=(const cell &a){this->x\
    \ += a.x; this->y += a.y; return *this;}\n    cell& operator-=(const cell &a){this->x\
    \ -= a.x; this->y -= a.y; return *this;}\n  };\n\n  cell operator+(const cell\
    \ &a, const cell &b){return cell(a.x + b.x, a.y + b.y);}\n  cell operator-(const\
    \ cell &a, const cell &b){return cell(a.x - b.x, a.y - b.y);}\n  bool operator==(const\
    \ cell &a, const cell &b){return a.x == b.x and a.y == b.y;}\n  bool operator!=(const\
    \ cell &a, const cell &b){return !(a == b);}\n\n  bool operator<(const cell &a,\
    \ const cell &b){\n    return std::make_pair(a.x, a.y) < std::make_pair(b.x, b.y);\n\
    \  }\n\n  std::ostream& operator<<(std::ostream &os, const cell &a){\n    os <<\
    \ \"(\" << a.x << \",\" << a.y << \")\";\n    return os;\n  }\n\n  const auto\
    \ LEFT = cell(0, -1);\n  const auto RIGHT = cell(0, 1);\n  const auto UP = cell(-1,\
    \ 0);\n  const auto DOWN = cell(1, 0);\n\n  const std::array<cell, 4> dir4 = {LEFT,\
    \ RIGHT, UP, DOWN};\n  const std::array<cell, 8> dir8 = {LEFT, RIGHT, UP, DOWN,\
    \ LEFT + UP, LEFT + DOWN, RIGHT + UP, RIGHT + DOWN};\n}\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct edge {\n    int from,\
    \ to;\n    T cost;\n    int index = -1;\n    edge(){}\n    edge(int from, int\
    \ to, T cost): from(from), to(to), cost(cost){}\n    edge(int from, int to, T\
    \ cost, int index): from(from), to(to), cost(cost), index(index){}\n  };\n\n \
    \ template <typename T>\n  struct graph {\n    using weight_type = T;\n    using\
    \ edge_type = edge<T>;\n\n    std::vector<std::vector<edge<T>>> data;\n\n    auto&\
    \ operator[](size_t i){return data[i];}\n    const auto& operator[](size_t i)\
    \ const {return data[i];}\n\n    auto begin() const {return data.begin();}\n \
    \   auto end() const {return data.end();}\n\n    graph(){}\n    graph(int N):\
    \ data(N){}\n\n    bool empty() const {return data.empty();}\n    int size() const\
    \ {return data.size();}\n\n    void add_edge(int i, int j, T w, int index = -1){\n\
    \      data[i].emplace_back(i, j, w, index);\n    }\n\n    void add_undirected(int\
    \ i, int j, T w, int index = -1){\n      add_edge(i, j, w, index);\n      add_edge(j,\
    \ i, w, index);\n    }\n\n    template <size_t I, bool DIRECTED = true, bool WEIGHTED\
    \ = true>\n    void read(int M){\n      for(int i = 0; i < M; ++i){\n        int\
    \ u, v; std::cin >> u >> v;\n        u -= I;\n        v -= I;\n        T w = 1;\n\
    \        if(WEIGHTED) std::cin >> w;\n        if(DIRECTED) add_edge(u, v, w, i);\n\
    \        else add_undirected(u, v, w, i);\n      }\n    }\n  };\n\n  template\
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 5 \"Mylib/Grid/grid_to_graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, typename Directions, typename\
    \ Index, typename Checker, typename Generator>\n  graph<T> grid_to_graph(\n  \
    \  int H, int W,\n    const Directions &dir,\n    const Index &index,\n    const\
    \ Checker &check_passable,\n    const Generator &generate_edge_cost\n  ){\n  \
    \  graph<T> ret(H * W);\n\n    for(int i = 0; i < H; ++i){\n      for(int j =\
    \ 0; j < W; ++j){\n        auto p = cell(i, j);\n\n        for(auto &d : dir){\n\
    \          auto q = cell(i, j) + d;\n\n          if(q.x < 0 or q.x >= H or q.y\
    \ < 0 or q.y >= W or not check_passable(p, q)) continue;\n\n          ret.add_edge(index(p.x,\
    \ p.y), index(q.x, q.y), generate_edge_cost(p, q));\n        }\n      }\n    }\n\
    \n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"Mylib/Grid/grid.cpp\"\n#include\
    \ \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T, typename Directions, typename Index, typename Checker, typename Generator>\n\
    \  graph<T> grid_to_graph(\n    int H, int W,\n    const Directions &dir,\n  \
    \  const Index &index,\n    const Checker &check_passable,\n    const Generator\
    \ &generate_edge_cost\n  ){\n    graph<T> ret(H * W);\n\n    for(int i = 0; i\
    \ < H; ++i){\n      for(int j = 0; j < W; ++j){\n        auto p = cell(i, j);\n\
    \n        for(auto &d : dir){\n          auto q = cell(i, j) + d;\n\n        \
    \  if(q.x < 0 or q.x >= H or q.y < 0 or q.y >= W or not check_passable(p, q))\
    \ continue;\n\n          ret.add_edge(index(p.x, p.y), index(q.x, q.y), generate_edge_cost(p,\
    \ q));\n        }\n      }\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/Grid/grid.cpp
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Grid/grid_to_graph.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0558/main.graph.test.cpp
documentation_of: Mylib/Grid/grid_to_graph.cpp
layout: document
title: Convert grid to graph
---

## Operations

## Requirements

## Notes

## Problems

## References
