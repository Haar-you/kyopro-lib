#pragma once
#include <array>
#include <iostream>
#include <utility>

namespace haar_lib {
  struct cell {
    int x, y;
    cell(): x(0), y(0){}
    cell(int x, int y): x(x), y(y){}
    cell& operator+=(const cell &a){this->x += a.x; this->y += a.y; return *this;}
    cell& operator-=(const cell &a){this->x -= a.x; this->y -= a.y; return *this;}
  };

  cell operator+(const cell &a, const cell &b){return cell(a.x + b.x, a.y + b.y);}
  cell operator-(const cell &a, const cell &b){return cell(a.x - b.x, a.y - b.y);}
  bool operator==(const cell &a, const cell &b){return a.x == b.x and a.y == b.y;}
  bool operator!=(const cell &a, const cell &b){return !(a == b);}

  bool operator<(const cell &a, const cell &b){
    return std::make_pair(a.x, a.y) < std::make_pair(b.x, b.y);
  }

  std::ostream& operator<<(std::ostream &os, const cell &a){
    os << "(" << a.x << "," << a.y << ")";
    return os;
  }

  const auto LEFT = cell(0, -1);
  const auto RIGHT = cell(0, 1);
  const auto UP = cell(-1, 0);
  const auto DOWN = cell(1, 0);

  const std::array<cell, 4> dir4 = {LEFT, RIGHT, UP, DOWN};
  const std::array<cell, 8> dir8 = {LEFT, RIGHT, UP, DOWN, LEFT + UP, LEFT + DOWN, RIGHT + UP, RIGHT + DOWN};
}
