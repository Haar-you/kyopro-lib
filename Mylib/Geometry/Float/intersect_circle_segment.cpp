#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/distance_segment_point.cpp"

namespace haar_lib {
  namespace intersect_circle_segment {
    enum status_t {
                 INSIDE         = 0b00001,
                 OUTSIDE        = 0b00010,
                 TANGENT        = 0b00100,
                 ONE_CROSSPOINT = 0b01000,
                 TWO_CROSSPOINT = 0b10000
    };

    template <typename T>
    struct result {
      status_t status;
      std::vector<point<T>> crosspoints;
    };

    template <typename T>
    auto check(const circle<T> &cl, const line<T> &s){
      const T r = cl.radius;
      const auto &c = cl.center;

      const T d1 = abs(c - s.from);
      const T d2 = abs(c - s.to);
      const T v = distance_segment_point(s, c);
      const T m = sqrt(r * r - v * v);
      const auto n = normal(s);
      const auto k = s.from + diff(s) * cross(n, c + n - s.from) / cross(n, diff(s));

      if(d1 < r and d2 < r){
        return result<T>({INSIDE, {}});
      }
      else if(v == r){
        return result<T>({TANGENT, {k}});
      }
      else if(v > r){
        return result<T>({OUTSIDE, {}});
      }
      else if(d1 >= r and d2 >= r){
        return result<T>({TWO_CROSSPOINT, {k - unit(s) * m, k + unit(s) * m}});
      }

      const T b = dot(unit(s), s.from - c);
      const T a = abs_sq(s.from - c) - r * r;
      const T x = sqrt(b * b - a);

      return result<T>({ONE_CROSSPOINT, {s.from + unit(s) * (-b - x >= 0 ? -b - x : -b + x)}});
    }
  };
}
