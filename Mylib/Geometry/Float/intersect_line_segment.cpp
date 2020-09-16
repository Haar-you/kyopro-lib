#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"

namespace haar_lib {
  namespace intersect_line_segment {
    enum status_t {
                 LEFTSIDE   = 0b0001,
                 RIGHTSIDE  = 0b0010,
                 OVERLAPPED = 0b0100,
                 CROSSED    = 0b1000,
    };

    template <typename T>
    struct result {
      status_t status;
      std::vector<point<T>> crosspoints;
    };

    template <typename T>
    auto check(const line<T> &l, const segment<T> &s){
      const T a = cross(diff(l), s.from - l.from);
      const T b = cross(diff(l), s.to - l.from);

      if(a == 0 and b == 0){
        return result<T>({OVERLAPPED, {}});
      }
      else if(a < 0 and b < 0){
        return result<T>({RIGHTSIDE, {}});
      }
      else if(a > 0 and b > 0){
        return result<T>({LEFTSIDE, {}});
      }

      return result<T>({CROSSED, {s.from + diff(s) * cross(diff(l), l.from - s.from) / cross(l, s)}});
    }
  }
}
