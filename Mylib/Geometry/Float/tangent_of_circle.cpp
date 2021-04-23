#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

namespace haar_lib {
  template <typename T>
  std::vector<point<T>> tangent_of_circle(const circle<T> &c, const point<T> &p) {
    const T d = abs(p - c.center);

    if (d < c.radius) return {};
    if (abs(d - c.radius) == 0) return {p};

    const T a = acos(c.radius / d);
    const T t = atan2(p.y - c.center.y, p.x - c.center.x);
    return {
        c.center + polar(c.radius, t + a),
        c.center + polar(c.radius, t - a)};
  }
}  // namespace haar_lib
