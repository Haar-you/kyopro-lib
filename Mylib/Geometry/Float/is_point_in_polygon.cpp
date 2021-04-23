#pragma once
#include "Mylib/Geometry/Float/ccw.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"

namespace haar_lib {
  namespace point_in_polygon_impl {
    enum class status { INCLUSION,
                        ON_SEGMENT,
                        OUTSIDE };
    struct result {
      status s;
      bool is_inclusion() const { return s == status::INCLUSION; }
      bool is_on_segment() const { return s == status::ON_SEGMENT; }
      bool is_outside() const { return s == status::OUTSIDE; }
    };
  }  // namespace point_in_polygon_impl

  template <typename T>
  auto point_in_polygon(const point<T> &p, const polygon<T> &polygon) {
    using namespace point_in_polygon_impl;

    const int n = polygon.size();

    T d = 0;
    for (int i = 0; i < n; ++i) {
      if (check_ccw(polygon[i], polygon[(i + 1) % n], p).is_on_segment()) {
        return result({status::ON_SEGMENT});
      }

      T a = angle(polygon[i], p);
      T b = angle(polygon[(i + 1) % n], p);

      if (a < 0) a += 2 * M_PI;
      if (b < 0) b += 2 * M_PI;

      T ang = b - a;

      if (abs(ang) > M_PI) {
        if (ang <= 0)
          ang += 2 * M_PI;
        else
          ang -= 2 * M_PI;
      }

      d += ang;
    }

    if (abs(abs(d) - 2 * M_PI) == 0) return result({status::INCLUSION});

    return result({status::OUTSIDE});
  }
}  // namespace haar_lib
