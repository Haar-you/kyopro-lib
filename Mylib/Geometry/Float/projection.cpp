#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 射影
 * @docs projection.md
 */
template <typename T>
Point<T> projection(const Line<T> &l, const Point<T> &p){
  return l.from + dot(unit(l.to - l.from), p - l.from) * unit(l.to - l.from);
}
