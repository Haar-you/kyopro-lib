#pragma once
#include <cmath>
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 直行判定
 * @docs orthogonal.md
 */
template <typename T, typename U = typename T::value_type>
bool orthogonal(const Line<T> &a, const Line<T> &b){
  return (T)std::abs((U)dot(a.diff(), b.diff())) == 0;
}
