#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/intersect_circles.cpp"

/**
 * @title Area of intersection between two circles
 * @docs area_intersection_of_circles.md
 */
template <typename T>
T area_of_intersection_of_circles(const Circle<T> &a, const Circle<T> &b){
  auto [s, p] = intersect_circles::check(a, b);

  switch(s){
  case intersect_circles::SAME: {
    return a.radius * a.radius * M_PI;
  }
  case intersect_circles::INSIDE:
  case intersect_circles::INSCRIBED: {
    return std::min(a.radius * a.radius * M_PI, b.radius * b.radius * M_PI);
  }
  case intersect_circles::INTERSECT: {
    T ret = 0;

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
  case intersect_circles::CIRCUMSCRIBED:
  case intersect_circles::OUTSIDE: {
    return 0;
  }
  }
  return 0;
}
