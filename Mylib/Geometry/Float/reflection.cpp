#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/projection.cpp"

/**
 * @title Reflection
 * @docs reflection.md
 */
template <typename T>
Point<T> reflection(const Line<T> &l, const Point<T> &p){
  return p + (projection(l, p) - p) * 2.0;
}
