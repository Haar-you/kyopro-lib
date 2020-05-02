#pragma once
#include <cmath>
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 円の接線
 * @docs tangent_of_circle.md
 */
template <typename T, typename U = typename T::value_type>
std::vector<Point<T>> tangent_of_circle(const Circle<T> &c, const Point<T> &p){
  const T d = (p - c.center).size();

  if(d < c.radius) return {};
  if((T)std::fabs((U)(d - c.radius)) == 0) return {p};

  const T a = std::acos((U)(c.radius / d));
  const T t = std::atan2((U)(p.y - c.center.y), (U)(p.x - c.center.x));
  return {c.center + Point<T>::polar(c.radius, t + a), c.center + Point<T>::polar(c.radius, t - a)};
}
