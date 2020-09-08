#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title Distance between a line and a point
 * @docs distance_line_point.md
 */
namespace haar_lib {
  template <typename T>
  T distance_line_point(const line<T> &l, const point<T> &p){
    return abs(cross(diff(l), p - l.from) / abs(l));
  }
}
