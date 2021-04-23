#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/intersect_circles.cpp"

namespace haar_lib {
  template <typename T>
  T area_of_intersection_of_circles(const circle<T> &a, const circle<T> &b) {
    const auto s = intersect_circles(a, b);
    auto p       = s.crosspoints;

    if (s.is_same()) {
      return a.radius * a.radius * M_PI;
    } else if (s.is_inside() or s.is_inscribed()) {
      return std::min(a.radius * a.radius * M_PI, b.radius * b.radius * M_PI);
    } else if (s.is_intersected()) {
      T ret  = 0;
      auto d = abs(a.center - b.center);

      {
        T ang = acos((a.radius * a.radius + d * d - b.radius * b.radius) / (a.radius * d * 2.0));
        ret += (ang - sin(ang * 2.0) / 2.0) * a.radius * a.radius;
      }

      {
        T ang = acos((b.radius * b.radius + d * d - a.radius * a.radius) / (b.radius * d * 2.0));
        ret += (ang - sin(ang * 2.0) / 2.0) * b.radius * b.radius;
      }

      return ret;
    }

    return 0;
  }
}  // namespace haar_lib
