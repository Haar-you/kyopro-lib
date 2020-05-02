#pragma once
#include <vector>
#include <cmath>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/distance_line_point.cpp"

/**
 * @title 円と直線の交差
 * @docs intersect_circle_line.md
 */
namespace intersect_circle_line{
  enum Status{
              OUTSIDE = 0b001,
              TANGENT = 0b010,
              CROSSED = 0b100
  };

  template <typename T>
  struct Result{
    Status status;
    std::vector<Point<T>> crosspoints;
  };
  
  template <typename T, typename U = typename T::value_type>
  auto check(const Circle<T> &c, const Line<T> &l){
    Result<T> ret;
    
    const T d = distance_line_point(l, c.center);

    if(d > c.radius){
      ret.status = OUTSIDE;
      return ret;
    }

    const auto n = normal(l.diff());
    const auto b = l.from + l.diff() * cross(n, c.center + n - l.from) / cross(n, l.diff());

    if(d == c.radius){
      ret.crosspoints.emplace_back(b);
      ret.status = TANGENT;
      return ret;
    }
    
    const T a = std::sqrt((U)(c.radius * c.radius - d * d));
    ret.crosspoints.emplace_back(b + unit(l.diff()) * a);
    ret.crosspoints.emplace_back(b - unit(l.diff()) * a);
    ret.status = CROSSED;
    return ret;
  }
}
