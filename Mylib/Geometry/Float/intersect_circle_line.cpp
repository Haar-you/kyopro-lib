#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/distance_line_point.cpp"

/**
 * @title Intersection between a cirlce and a line
 * @docs intersect_circle_line.md
 */
namespace intersect_circle_line {
  enum Status {
              OUTSIDE = 0b001,
              TANGENT = 0b010,
              CROSSED = 0b100
  };

  template <typename T>
  struct Result {
    Status status;
    std::vector<Point<T>> crosspoints;
  };

  template <typename T>
  auto check(const Circle<T> &c, const Line<T> &l){
    const T d = distance_line_point(l, c.center);

    if(d > c.radius){
      return Result<T>({OUTSIDE, {}});
    }

    const auto n = normal(l);
    const auto b = l.from + diff(l) * cross(n, c.center + n - l.from) / cross(n, diff(l));

    if(d == c.radius){
      return Result<T>({TANGENT, {b}});
    }

    const T a = sqrt(c.radius * c.radius - d * d);
    return Result<T>({CROSSED, {b + unit(l) * a, b - unit(l) * a}});
  }
}
