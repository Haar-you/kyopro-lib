#pragma once
#include "Mylib/Geometry/Float/ccw.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/intersect_line_segment.cpp"

namespace haar_lib {
  template <typename T>
  void convex_cut(const polygon<T> &ps, const line<T> &l, polygon<T> &left, polygon<T> &right) {
    const int n = ps.size();

    for (int i = 0; i < n; ++i) {
      const auto s = intersect_line_segment(l, line<T>(ps[i], ps[(i + 1) % n]));
      auto c       = s.crosspoints;
      if (s.is_leftside()) {
        left.push_back(ps[i]);
      } else if (s.is_rightside()) {
        right.push_back(ps[i]);
      } else if (s.is_overlapped()) {
        right.push_back(ps[i]);
        left.push_back(ps[i]);
      } else if (s.is_crossed()) {
        if (check_ccw(l.from, l.to, ps[i]).is_clockwise()) {
          right.push_back(ps[i]);
        } else {
          left.push_back(ps[i]);
        }

        left.push_back(c[0]);
        right.push_back(c[0]);
      }
    }
  }
}  // namespace haar_lib
