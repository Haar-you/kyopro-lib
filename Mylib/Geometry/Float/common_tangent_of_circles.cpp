#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title Common tangents of two circles
 * @docs common_tangent_of_circles.md
 */
template <typename T>
std::vector<Point<T>> common_tangent_of_circles(const Circle<T> &a, const Circle<T> &b){
  const T d = abs(b.center - a.center);
  const auto n = unit(b.center - a.center);

  const auto cc = b.center - a.center;
  const T r = a.radius - b.radius;
  const T R = a.radius + b.radius;

  if(a.radius + b.radius == d){ // 一方が他方に外接している。
    return {
            a.center + (cc * r + normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),
            a.center + (cc * r - normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),
            a.center + n * a.radius
    };
  }else if(a.radius + b.radius < d){ // aとbは互いに離れている。
    return {
            a.center + (cc * r + normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),
            a.center + (cc * r - normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),
            a.center + (cc * R + normal(cc) * sqrt(abs_sq(cc) - R * R)) * a.radius / abs_sq(cc),
            a.center + (cc * R - normal(cc) * sqrt(abs_sq(cc) - R * R)) * a.radius / abs_sq(cc)
    };
  }else if(a.radius + b.radius > d and d > abs(a.radius - b.radius)){ // aとbは二点で交差している。
    return {
            a.center + (cc * r + normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),
            a.center + (cc * r - normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc)
    };
  }else if(abs(a.radius - b.radius) == d){ // 一方が他方に内接している。
    return {
            a.radius > b.radius ? a.center + n * a.radius : b.center - n * b.radius
    };
  }

  return {};
}
