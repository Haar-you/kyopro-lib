#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title Parallel
 * @docs parallel.md
 */
namespace haar_lib {
  template <typename T>
  bool parallel(const Line<T> &a, const Line<T> &b){
    return abs(cross(a, b)) == 0;
  }
}
