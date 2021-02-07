---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Grid/grid.cpp
    title: Grid template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0558/main.test.cpp
    title: test/aoj/0558/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Grid/grid_bfs.cpp\"\n#include <vector>\n#include <queue>\n\
    #include <optional>\n#line 2 \"Mylib/Grid/grid.cpp\"\n#include <array>\n#include\
    \ <iostream>\n#include <utility>\n\nnamespace haar_lib {\n  struct cell {\n  \
    \  int x, y;\n    cell(): x(0), y(0){}\n    cell(int x, int y): x(x), y(y){}\n\
    \    cell& operator+=(const cell &a){this->x += a.x; this->y += a.y; return *this;}\n\
    \    cell& operator-=(const cell &a){this->x -= a.x; this->y -= a.y; return *this;}\n\
    \  };\n\n  cell operator+(const cell &a, const cell &b){return cell(a.x + b.x,\
    \ a.y + b.y);}\n  cell operator-(const cell &a, const cell &b){return cell(a.x\
    \ - b.x, a.y - b.y);}\n  bool operator==(const cell &a, const cell &b){return\
    \ a.x == b.x and a.y == b.y;}\n  bool operator!=(const cell &a, const cell &b){return\
    \ !(a == b);}\n\n  bool operator<(const cell &a, const cell &b){\n    return std::make_pair(a.x,\
    \ a.y) < std::make_pair(b.x, b.y);\n  }\n\n  std::ostream& operator<<(std::ostream\
    \ &os, const cell &a){\n    os << \"(\" << a.x << \",\" << a.y << \")\";\n   \
    \ return os;\n  }\n\n  const auto LEFT = cell(0, -1);\n  const auto RIGHT = cell(0,\
    \ 1);\n  const auto UP = cell(-1, 0);\n  const auto DOWN = cell(1, 0);\n\n  const\
    \ std::array<cell, 4> dir4 = {LEFT, RIGHT, UP, DOWN};\n  const std::array<cell,\
    \ 8> dir8 = {LEFT, RIGHT, UP, DOWN, LEFT + UP, LEFT + DOWN, RIGHT + UP, RIGHT\
    \ + DOWN};\n}\n#line 6 \"Mylib/Grid/grid_bfs.cpp\"\n\nnamespace haar_lib {\n \
    \ template <typename Directions, typename Checker>\n  auto grid_bfs(\n    const\
    \ int H, const int W,\n    const std::vector<cell> &starting_points,\n    const\
    \ Directions &dir,\n    const Checker &check_passable\n  ){\n    std::vector<std::vector<std::optional<int>>>\
    \ dist(H, std::vector<std::optional<int>>(W));\n    std::vector<std::vector<bool>>\
    \ visited(H, std::vector<bool>(W));\n\n    std::queue<cell> q;\n    for(auto &p\
    \ : starting_points){\n      dist[p.x][p.y] = 0;\n      q.push(p);\n    }\n\n\
    \    while(not q.empty()){\n      auto cur = q.front(); q.pop();\n\n      if(visited[cur.x][cur.y])\
    \ continue;\n      visited[cur.x][cur.y] = true;\n\n      for(auto &d : dir){\n\
    \        auto nxt = cur + d;\n\n        if(nxt.x < 0 or nxt.x >= H or nxt.y <\
    \ 0 or nxt.y >= W or not check_passable(cur, nxt)) continue;\n\n        if(not\
    \ dist[nxt.x][nxt.y]){\n          dist[nxt.x][nxt.y] = *dist[cur.x][cur.y] + 1;\n\
    \          q.push(nxt);\n        }else{\n          if(*dist[nxt.x][nxt.y] > *dist[cur.x][cur.y]\
    \ + 1){\n            dist[nxt.x][nxt.y] = *dist[cur.x][cur.y] + 1;\n         \
    \   q.push(nxt);\n          }\n        }\n      }\n    }\n\n    return dist;\n\
    \  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <queue>\n#include <optional>\n\
    #include \"Mylib/Grid/grid.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ Directions, typename Checker>\n  auto grid_bfs(\n    const int H, const int\
    \ W,\n    const std::vector<cell> &starting_points,\n    const Directions &dir,\n\
    \    const Checker &check_passable\n  ){\n    std::vector<std::vector<std::optional<int>>>\
    \ dist(H, std::vector<std::optional<int>>(W));\n    std::vector<std::vector<bool>>\
    \ visited(H, std::vector<bool>(W));\n\n    std::queue<cell> q;\n    for(auto &p\
    \ : starting_points){\n      dist[p.x][p.y] = 0;\n      q.push(p);\n    }\n\n\
    \    while(not q.empty()){\n      auto cur = q.front(); q.pop();\n\n      if(visited[cur.x][cur.y])\
    \ continue;\n      visited[cur.x][cur.y] = true;\n\n      for(auto &d : dir){\n\
    \        auto nxt = cur + d;\n\n        if(nxt.x < 0 or nxt.x >= H or nxt.y <\
    \ 0 or nxt.y >= W or not check_passable(cur, nxt)) continue;\n\n        if(not\
    \ dist[nxt.x][nxt.y]){\n          dist[nxt.x][nxt.y] = *dist[cur.x][cur.y] + 1;\n\
    \          q.push(nxt);\n        }else{\n          if(*dist[nxt.x][nxt.y] > *dist[cur.x][cur.y]\
    \ + 1){\n            dist[nxt.x][nxt.y] = *dist[cur.x][cur.y] + 1;\n         \
    \   q.push(nxt);\n          }\n        }\n      }\n    }\n\n    return dist;\n\
    \  }\n}\n"
  dependsOn:
  - Mylib/Grid/grid.cpp
  isVerificationFile: false
  path: Mylib/Grid/grid_bfs.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0558/main.test.cpp
documentation_of: Mylib/Grid/grid_bfs.cpp
layout: document
title: BFS on a grid
---

## Operations

## Requirements

## Notes

## Problems

- [AGC 033 A - Darker and Darker](https://atcoder.jp/contests/agc033/tasks/agc033_a)
- [QUPC 2018 C - Ito Campus](https://atcoder.jp/contests/qupc2018/tasks/qupc2018_c)

## References
