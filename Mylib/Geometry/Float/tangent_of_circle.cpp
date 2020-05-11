#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 円の接線
 * @docs tangent_of_circle.md
 */
template <typename T>
std::vector<Point<T>> tangent_of_circle(const Circle<T> &c, const Point<T> &p){
  const T d = abs(p - c.center);

  if(d < c.radius) return {};
  if(abs(d - c.radius) == 0) return {p};

  const T a = acos(c.radius / d);
  const T t = atan2(p.y - c.center.y, p.x - c.center.x);
  return
    {
     c.center + polar(c.radius, t + a),
     c.center + polar(c.radius, t - a)
    };
}
