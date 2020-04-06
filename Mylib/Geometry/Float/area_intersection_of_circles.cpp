#pragma once
#include <cmath>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/intersect_circles.cpp"

/**
 * @title 2円の共通部分の面積
 * @see https://codeforces.com/contest/600/problem/D
 */
template <typename T, typename U = typename T::value_type>
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

    auto d = (a.center - b.center).size();

    {
      T ang = std::acos((U)((a.radius * a.radius + d * d - b.radius * b.radius) / (a.radius * d * 2.0)));
      ret += (ang - std::sin((U)(ang * 2.0)) / 2.0) * a.radius * a.radius;
    }

    {
      T ang = std::acos((U)((b.radius * b.radius + d * d - a.radius * a.radius) / (b.radius * d * 2.0)));
      ret += (ang - std::sin((U)(ang * 2.0)) / 2.0) * b.radius * b.radius;
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
