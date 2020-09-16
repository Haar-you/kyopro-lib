#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/distance_line_point.cpp"

namespace haar_lib {
  namespace intersect_circle_line {
    enum status_t {
                 OUTSIDE = 0b001,
                 TANGENT = 0b010,
                 CROSSED = 0b100
    };

    template <typename T>
    struct result {
      status_t status;
      std::vector<point<T>> crosspoints;
    };

    template <typename T>
    auto check(const circle<T> &c, const line<T> &l){
      const T d = distance_line_point(l, c.center);

      if(d > c.radius){
        return result<T>({OUTSIDE, {}});
      }

      const auto n = normal(l);
      const auto b = l.from + diff(l) * cross(n, c.center + n - l.from) / cross(n, diff(l));

      if(d == c.radius){
        return result<T>({TANGENT, {b}});
      }

      const T a = sqrt(c.radius * c.radius - d * d);
      return result<T>({CROSSED, {b + unit(l) * a, b - unit(l) * a}});
    }
  }
}
