#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title Orthogonal
 * @docs orthogonal.md
 */
namespace haar_lib {
  template <typename T>
  bool orthogonal(const line<T> &a, const line<T> &b){
    return abs(dot(a, b)) == 0;
  }
}
