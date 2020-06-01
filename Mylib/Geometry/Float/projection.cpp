#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title Projection
 * @docs projection.md
 */
template <typename T>
Point<T> projection(const Line<T> &l, const Point<T> &p){
  return l.from + dot(unit(l), p - l.from) * unit(l);
}
