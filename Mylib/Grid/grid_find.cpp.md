---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Grid/grid.cpp
    title: Grid template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0558/main.graph.test.cpp
    title: test/aoj/0558/main.graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0558/main.test.cpp
    title: test/aoj/0558/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Grid/grid_find.cpp\"\n#include <vector>\n#line 2 \"\
    Mylib/Grid/grid.cpp\"\n#include <array>\n#include <iostream>\n#include <utility>\n\
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
    \ LEFT + UP, LEFT + DOWN, RIGHT + UP, RIGHT + DOWN};\n}\n#line 4 \"Mylib/Grid/grid_find.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename C, typename T = typename C::value_type>\n\
    \  auto grid_find(const std::vector<C> &A, T value){\n    const int H = A.size(),\
    \ W = A[0].size();\n\n    std::vector<cell> ret;\n    for(int i = 0; i < H; ++i){\n\
    \      for(int j = 0; j < W; ++j){\n        if(A[i][j] == value){\n          ret.emplace_back(i,\
    \ j);\n        }\n      }\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"Mylib/Grid/grid.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename C, typename T = typename C::value_type>\n \
    \ auto grid_find(const std::vector<C> &A, T value){\n    const int H = A.size(),\
    \ W = A[0].size();\n\n    std::vector<cell> ret;\n    for(int i = 0; i < H; ++i){\n\
    \      for(int j = 0; j < W; ++j){\n        if(A[i][j] == value){\n          ret.emplace_back(i,\
    \ j);\n        }\n      }\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/Grid/grid.cpp
  isVerificationFile: false
  path: Mylib/Grid/grid_find.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0558/main.graph.test.cpp
  - test/aoj/0558/main.test.cpp
documentation_of: Mylib/Grid/grid_find.cpp
layout: document
title: Enumerate points satisfying conditions
---

## Operations

## Requirements

## Notes

## Problems

## References
