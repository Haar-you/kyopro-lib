#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/ccw.cpp"

/**
 * @title 凸多角形判定
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B
 */
template <typename T>
bool is_convex(const Polygon<T> &ps){
  const int n = ps.size();
  std::vector<ccw::CCW> temp;

  for(int i = 0; i < n; ++i){
    const auto c = ccw::ccw(ps[i], ps[(i+1)%n], ps[(i+2)%n]);
    
    if(c == ccw::CLOCKWISE or c == ccw::COUNTER_CLOCKWISE){
      if(temp.empty()) temp.push_back(c);
      else if(temp.back() != c) return false;
    }
  }
  
  return true;
}
