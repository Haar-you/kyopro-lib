#pragma once
#include <cmath>
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 直線と点間の距離
 * @docs distance_line_point.md
 */
template <typename T, typename U = typename T::value_type>
T distance_line_point(const Line<T> &l, const Point<T> &p){
  return std::fabs((U)(cross(l.diff(),p - l.from) / l.size()));
}
