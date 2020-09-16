#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

namespace haar_lib {
  template <typename T>
  T distance_line_point(const line<T> &l, const point<T> &p){
    return abs(cross(diff(l), p - l.from) / abs(l));
  }
}
