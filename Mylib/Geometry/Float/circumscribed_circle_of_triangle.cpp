#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title Circumscribed circle of a triangle
 * @docs circumscribed_circle_of_triangle.md
 */
namespace haar_lib {
  template <typename T>
  Circle<T> circumscribed_circle_of_triangle(const Point<T> &a, const Point<T> &b, const Point<T> &c){
    const T A = abs_sq(b - c), B = abs_sq(a - c), C = abs_sq(a - b), S = A + B + C;
    const T AA = A * (S - A * 2.0);
    const T BB = B * (S - B * 2.0);
    const T CC = C * (S - C * 2.0);
    const auto center = (AA * a + BB * b + CC * c) / (AA + BB + CC);

    return Circle<T>(
      center,
      abs(center - a)
    );
  }
}
