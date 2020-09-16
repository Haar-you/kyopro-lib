#pragma once
#include <algorithm>
#include "Mylib/Geometry/Float/geometry_template.cpp"

namespace haar_lib {
  template <typename T>
  T convex_diameter(const polygon<T> &ps){
    const int n = (int)ps.size();
    int i = std::min_element(ps.begin(), ps.end(), [](const auto &a, const auto &b){return a.y < b.y;}) - ps.begin();
    int j = std::max_element(ps.begin(), ps.end(), [](const auto &a, const auto &b){return a.y < b.y;}) - ps.begin();

    T ret = abs(ps[i]-ps[j]);

    for(int k = 0; k < 2 * n; ++k){
      if(cross(ps[(i + 1) % n] - ps[i], ps[(j + 1) % n] - ps[j]) > 0){
        (++j) %= n;
      }else{
        (++i) %= n;
      }

      ret = std::max(ret, abs(ps[i] - ps[j]));
    }

    return ret;
  }
}
