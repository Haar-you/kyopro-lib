#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/ccw.cpp"

/**
 * @title Check convex
 * @docs is_convex.md
 */
namespace haar_lib {
  template <typename T>
  bool is_convex(const Polygon<T> &ps){
    const int n = ps.size();
    std::vector<ccw::Status> temp;

    for(int i = 0; i < n; ++i){
      const auto c = ccw::ccw(ps[i], ps[(i + 1) % n], ps[(i + 2) % n]);

      if(c == ccw::CLOCKWISE or c == ccw::COUNTER_CLOCKWISE){
        if(temp.empty()) temp.push_back(c);
        else if(temp.back() != c) return false;
      }
    }

    return true;
  }
}
