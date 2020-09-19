#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/ccw.cpp"

namespace haar_lib {
  template <typename T>
  bool is_convex(const polygon<T> &ps){
    const int n = ps.size();
    std::vector<ccw> temp;

    for(int i = 0; i < n; ++i){
      const auto c = check_ccw(ps[i], ps[(i + 1) % n], ps[(i + 2) % n]);

      if(c.is_clockwise() or c.is_counter_clockwise()){
        if(temp.empty()) temp.push_back(c);
        else if(temp.back() != c) return false;
      }
    }

    return true;
  }
}
