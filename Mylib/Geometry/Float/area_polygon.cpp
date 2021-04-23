#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

namespace haar_lib {
  template <typename T>
  T area(const polygon<T> &ps) {
    T ret       = 0;
    const int n = (int) ps.size();
    for (int i = 0; i < n; ++i) {
      ret += (ps[i].x - ps[(i + 1) % n].x) * (ps[i].y + ps[(i + 1) % n].y);
    }
    if (ret < 0) ret = -ret;
    ret /= 2;
    return ret;
  }
}  // namespace haar_lib
