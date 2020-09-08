#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title Inscribed circle of a triangle
 * @docs inscribed_circle_of_triangle.md
 */
namespace haar_lib {
  template <typename T>
  Circle<T> inscribed_circle_of_triangle(const Point<T> &a, const Point<T> &b, const Point<T> &c){
    const T A = abs(b - c), B = abs(a - c), C = abs(a - b), s = (A + B + C) / 2.0;

    return Circle<T>(
      (A * a + B * b + C * c) / (A + B + C),
      sqrt((s - A)  * (s - B) * (s - C) / s)
    );
  }
}
