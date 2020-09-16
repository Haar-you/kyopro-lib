#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/ccw.cpp"

namespace haar_lib {
  namespace point_in_polygon {
    enum status {
                 INCLUSION  = 0b001,
                 ON_SEGMENT = 0b010,
                 OUTSIDE    = 0b100
    };

    template <typename T>
    status check(const point<T> &p, const polygon<T> &polygon){
      const int n = polygon.size();

      T d = 0;
      for(int i = 0; i < n; ++i){
        if(ccw::ccw(polygon[i], polygon[(i + 1) % n], p) == ccw::ON_SEGMENT) return ON_SEGMENT;

        T a = angle(polygon[i], p);
        T b = angle(polygon[(i + 1) % n], p);

        if(a < 0) a += 2 * M_PI;
        if(b < 0) b += 2 * M_PI;

        T ang = b - a;

        if(abs(ang) > M_PI){
          if(ang <= 0) ang += 2 * M_PI;
          else ang -= 2 * M_PI;
        }

        d += ang;
      }

      if(abs(abs(d) - 2 * M_PI) == 0) return INCLUSION;

      return OUTSIDE;
    }
  }
}
