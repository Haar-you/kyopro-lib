#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"

namespace haar_lib {
  namespace intersect_circles {
    enum status_t {
                 SAME          = 0b000001,
                 INSIDE        = 0b000010,
                 INSCRIBED     = 0b000100,
                 INTERSECT     = 0b001000,
                 CIRCUMSCRIBED = 0b010000,
                 OUTSIDE       = 0b100000
    };

    template <typename T>
    struct result {
      status_t status;
      std::vector<point<T>> crosspoints;
    };

    template <typename T>
    auto check(const circle<T> &a, const circle<T> &b){
      const T d = abs(a.center - b.center);
      const T x = acos((a.radius * a.radius + d * d - b.radius * b.radius) / ((T)2.0 * d * a.radius));
      const T t = atan2(b.center.y - a.center.y, b.center.x - a.center.x);

      if(a.radius + b.radius == d){
        return result<T>({CIRCUMSCRIBED, {a.center + polar(a.radius, t)}});
      }
      else if(abs(a.radius - b.radius) == d){
        return result<T>({INSCRIBED, {a.center + polar(a.radius, t)}});
      }
      else if(a.radius + b.radius > d and d > abs(a.radius - b.radius)){
        return result<T>({INTERSECT, {a.center + polar(a.radius, t + x), a.center + polar(a.radius, t - x)}});
      }
      else if(a.radius + b.radius < d){
        return result<T>({OUTSIDE, {}});
      }
      else if(abs(a.radius - b.radius) > d){
        return result<T>({INSIDE, {}});
      }

      return result<T>({SAME, {}});
    }
  }
}
