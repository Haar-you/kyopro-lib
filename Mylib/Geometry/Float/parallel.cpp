#pragma once
#include <cmath>
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 平行判定
 * @docs parallel.md
 */
template <typename T, typename U = typename T::value_type>
bool parallel(const Line<T> &a, const Line<T> &b){
  return (T)std::abs((U)cross(a.diff(), b.diff())) == 0;
}
