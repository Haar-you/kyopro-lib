#pragma once
#include <array>
#include <iostream>
#include <utility>

/**
 * @title Grid template
 * @docs grid.md
 */
namespace haar_lib {
  struct point {
    int x, y;
    point(): x(0), y(0){}
    point(int x, int y): x(x), y(y){}
    point& operator+=(const point &a){this->x += a.x; this->y += a.y; return *this;}
    point& operator-=(const point &a){this->x -= a.x; this->y -= a.y; return *this;}
  };

  point operator+(const point &a, const point &b){return point(a.x + b.x, a.y + b.y);}
  point operator-(const point &a, const point &b){return point(a.x - b.x, a.y - b.y);}
  bool operator==(const point &a, const point &b){return a.x == b.x and a.y == b.y;}
  bool operator!=(const point &a, const point &b){return !(a == b);}

  bool operator<(const point &a, const point &b){
    return std::make_pair(a.x, a.y) < std::make_pair(b.x, b.y);
  }

  std::ostream& operator<<(std::ostream &os, const point &a){
    os << "(" << a.x << "," << a.y << ")";
    return os;
  }

  const auto LEFT = point(0, -1);
  const auto RIGHT = point(0, 1);
  const auto UP = point(-1, 0);
  const auto DOWN = point(1, 0);

  const std::array<point, 4> dir4 = {LEFT, RIGHT, UP, DOWN};
  const std::array<point, 8> dir8 = {LEFT, RIGHT, UP, DOWN, LEFT + UP, LEFT + DOWN, RIGHT + UP, RIGHT + DOWN};
}
