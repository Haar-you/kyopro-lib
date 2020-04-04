#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/projection.cpp"

/**
 * @title 反射
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
 */
template <typename T>
Point<T> reflection(const Line<T> &l, const Point<T> &p){
  return p + (projection(l,p) - p) * 2.0;
}
