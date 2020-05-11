#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 平行判定
 * @docs parallel.md
 */
template <typename T>
bool parallel(const Line<T> &a, const Line<T> &b){
  return abs(cross(a, b)) == 0;
}
