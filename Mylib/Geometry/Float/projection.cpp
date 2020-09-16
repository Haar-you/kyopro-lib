#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

namespace haar_lib {
  template <typename T>
  point<T> projection(const line<T> &l, const point<T> &p){
    return l.from + dot(unit(l), p - l.from) * unit(l);
  }
}
