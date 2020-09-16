#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

namespace haar_lib {
  template <typename T>
  T distance_segment_point(const segment<T> &l, const point<T> &p){
    if(dot(diff(l), p - l.from) < 0) return abs(p - l.from);
    if(dot(-diff(l), p - l.to) < 0) return abs(p - l.to);
    return abs(cross(diff(l), p - l.from)) / abs(l);
  }
}
