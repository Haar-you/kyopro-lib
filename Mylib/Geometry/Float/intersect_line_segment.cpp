#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"

namespace haar_lib {
  namespace intersect_line_segment_impl {
    enum class status_t { LEFTSIDE,
                          RIGHTSIDE,
                          OVERLAPPED,
                          CROSSED };
    template <typename T>
    struct result {
      status_t status;
      std::vector<point<T>> crosspoints;
      bool is_leftside() const { return status == status_t::LEFTSIDE; }
      bool is_rightside() const { return status == status_t::RIGHTSIDE; }
      bool is_overlapped() const { return status == status_t::OVERLAPPED; }
      bool is_crossed() const { return status == status_t::CROSSED; }
    };
  }  // namespace intersect_line_segment_impl

  template <typename T>
  auto intersect_line_segment(const line<T> &l, const segment<T> &s) {
    using namespace intersect_line_segment_impl;

    const T a = cross(diff(l), s.from - l.from);
    const T b = cross(diff(l), s.to - l.from);

    if (a == 0 and b == 0) {
      return result<T>({status_t::OVERLAPPED, {}});
    } else if (a < 0 and b < 0) {
      return result<T>({status_t::RIGHTSIDE, {}});
    } else if (a > 0 and b > 0) {
      return result<T>({status_t::LEFTSIDE, {}});
    }

    return result<T>(
        {status_t::CROSSED,
         {s.from + diff(s) * cross(diff(l), l.from - s.from) / cross(l, s)}});
  }
}  // namespace haar_lib
