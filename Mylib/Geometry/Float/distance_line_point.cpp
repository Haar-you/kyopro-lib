#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title Distance between a line and a point
 * @docs distance_line_point.md
 */
template <typename T>
T distance_line_point(const Line<T> &l, const Point<T> &p){
  return abs(cross(diff(l), p - l.from) / abs(l));
}
