#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 直行判定
 * @docs orthogonal.md
 */
template <typename T>
bool orthogonal(const Line<T> &a, const Line<T> &b){
  return abs(dot(a, b)) == 0;
}
