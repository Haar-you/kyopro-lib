#pragma once
#include <vector>
#include "Mylib/Geometry/Float/distance_line_point.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"

namespace haar_lib {
  namespace intersect_circle_line_impl {
    enum class status_t { OUTSIDE,
                          TANGENT,
                          CROSSED };
    template <typename T>
    struct result {
      status_t status;
      std::vector<point<T>> crosspoints;
      bool is_outside() const { return status == status_t::OUTSIDE; }
      bool is_tangent() const { return status == status_t::TANGENT; }
      bool is_crossed() const { return status == status_t::CROSSED; }
    };
  }  // namespace intersect_circle_line_impl

  template <typename T>
  auto intersect_circle_line(const circle<T> &c, const line<T> &l) {
    using namespace intersect_circle_line_impl;

    const T d = distance_line_point(l, c.center);

    if (d > c.radius) {
      return result<T>({status_t::OUTSIDE, {}});
    }

    const auto n = normal(l);
    const auto b = l.from + diff(l) * cross(n, c.center + n - l.from) / cross(n, diff(l));

    if (d == c.radius) {
      return result<T>({status_t::TANGENT, {b}});
    }

    const T a = sqrt(c.radius * c.radius - d * d);
    return result<T>({status_t::CROSSED, {b + unit(l) * a, b - unit(l) * a}});
  }
}  // namespace haar_lib
