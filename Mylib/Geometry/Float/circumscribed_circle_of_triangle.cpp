#pragma once
#include <cmath>
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 三角形の外接円
 */
template <typename T, typename U = typename T::value_type>
Circle<T> circumscribed_circle_of_triangle(const Point<T> &a, const Point<T> &b, const Point<T> &c){
  T A = (b-c).size_sq(), B = (a-c).size_sq(), C = (a-b).size_sq();
  T x = std::sqrt((U)A), y = std::sqrt((U)B), z = std::sqrt((U)C);

  return Circle<T>
    (
     (A*(B+C-A)*a + B*(C+A-B)*b + C*(A+B-C)*c) / (A*(B+C-A) + B*(C+A-B) + C*(A+B-C)),
     x * y * z / std::sqrt((U)((x+y+z)*(-x+y+z)*(x-y+z)*(x+y-z)))
     );
}
