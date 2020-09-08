#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/projection.cpp"

/**
 * @title Reflection
 * @docs reflection.md
 */
namespace haar_lib {
  template <typename T>
  point<T> reflection(const line<T> &l, const point<T> &p){
    return p + (projection(l, p) - p) * 2.0;
  }
}
