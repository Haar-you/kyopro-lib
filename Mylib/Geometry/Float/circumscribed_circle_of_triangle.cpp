#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 三角形の外接円
 * @docs circumscribed_circle_of_triangle.md
 */
template <typename T>
Circle<T> circumscribed_circle_of_triangle(const Point<T> &a, const Point<T> &b, const Point<T> &c){
  const T A = abs_sq(b - c), B = abs_sq(a - c), C = abs_sq(a - b), S = A + B + C;
  const T x = sqrt(A), y = sqrt(B), z = sqrt(C), w = x + y + z;

  const T AA = A * (S - A * 2.0);
  const T BB = B * (S - B * 2.0);
  const T CC = C * (S - C * 2.0);

  return Circle<T>(
    (AA * a + BB * b + CC * c) / (AA + BB + CC),
    x * y * z / sqrt(w * (w - x * 2.0) * (w - y * 2.0) * (w - z * 2.0))
  );
}
