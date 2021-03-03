---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Mylib/Grid/grid_bfs.cpp
    title: BFS on a grid
  - icon: ':heavy_check_mark:'
    path: Mylib/Grid/grid_find.cpp
    title: Enumerate points satisfying conditions
  - icon: ':heavy_check_mark:'
    path: Mylib/Grid/grid_to_graph.cpp
    title: Convert grid to graph
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0558/main.graph.test.cpp
    title: test/aoj/0558/main.graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0558/main.test.cpp
    title: test/aoj/0558/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Grid/grid.cpp\"\n#include <array>\n#include <iostream>\n\
    #include <utility>\n\nnamespace haar_lib {\n  struct cell {\n    int x, y;\n \
    \   cell(): x(0), y(0){}\n    cell(int x, int y): x(x), y(y){}\n    cell& operator+=(const\
    \ cell &a){this->x += a.x; this->y += a.y; return *this;}\n    cell& operator-=(const\
    \ cell &a){this->x -= a.x; this->y -= a.y; return *this;}\n  };\n\n  cell operator+(const\
    \ cell &a, const cell &b){return cell(a.x + b.x, a.y + b.y);}\n  cell operator-(const\
    \ cell &a, const cell &b){return cell(a.x - b.x, a.y - b.y);}\n  bool operator==(const\
    \ cell &a, const cell &b){return a.x == b.x and a.y == b.y;}\n  bool operator!=(const\
    \ cell &a, const cell &b){return !(a == b);}\n\n  bool operator<(const cell &a,\
    \ const cell &b){\n    return std::make_pair(a.x, a.y) < std::make_pair(b.x, b.y);\n\
    \  }\n\n  std::ostream& operator<<(std::ostream &os, const cell &a){\n    os <<\
    \ \"(\" << a.x << \",\" << a.y << \")\";\n    return os;\n  }\n\n  const auto\
    \ LEFT = cell(0, -1);\n  const auto RIGHT = cell(0, 1);\n  const auto UP = cell(-1,\
    \ 0);\n  const auto DOWN = cell(1, 0);\n\n  const std::array<cell, 4> dir4 = {LEFT,\
    \ RIGHT, UP, DOWN};\n  const std::array<cell, 8> dir8 = {LEFT, RIGHT, UP, DOWN,\
    \ LEFT + UP, LEFT + DOWN, RIGHT + UP, RIGHT + DOWN};\n}\n"
  code: "#pragma once\n#include <array>\n#include <iostream>\n#include <utility>\n\
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
    \ LEFT + UP, LEFT + DOWN, RIGHT + UP, RIGHT + DOWN};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Grid/grid.cpp
  requiredBy:
  - Mylib/Grid/grid_bfs.cpp
  - Mylib/Grid/grid_find.cpp
  - Mylib/Grid/grid_to_graph.cpp
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0558/main.graph.test.cpp
  - test/aoj/0558/main.test.cpp
documentation_of: Mylib/Grid/grid.cpp
layout: document
title: Grid template
---

## Operations

## Requirements

## Notes

## Problems

## References
