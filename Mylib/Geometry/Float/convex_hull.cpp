#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 凸包
 * @docs convex_hull.md
 */
template <typename T> 
std::vector<Point<T>> upper_hull(Polygon<T> pts, bool upper = true){
  std::sort(pts.begin(), pts.end(), [](const auto &a, const auto &b){return a.x < b.x or (a.x == b.x and a.y < b.y);});

  if(upper) std::reverse(pts.begin(), pts.end());
  
  std::vector<Point<T>> ret;

  ret.push_back(pts.back());
  pts.pop_back();
  
  while(not pts.empty()){
    const auto s = pts.back();
    pts.pop_back();

    if(ret.size() == 1){
      ret.push_back(s);
    }else{
      const auto p = *(ret.end()-2);
      const auto q = ret.back();
      
      if(cross(q-p, s-p) <= 0){
        ret.push_back(s);
      }else{
        ret.pop_back();
        pts.push_back(s);
      }
    }
  }

  return ret;
}

template <typename T>
std::vector<Point<T>> convex_hull(const Polygon<T> &pts){
  auto ret = upper_hull(pts);
  auto lower = upper_hull(pts, false);

  ret.pop_back();
  lower.pop_back();

  for(auto &p : lower) ret.push_back(p);

  return ret;
}
