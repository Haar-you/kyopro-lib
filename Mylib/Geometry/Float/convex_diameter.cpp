#pragma once
#include <algorithm>
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 凸多角形の直径
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B
 */
template <typename T>
T convex_diameter(const Polygon<T> &ps){
  const int n = (int)ps.size();
  int i = std::min_element(ps.begin(), ps.end(), [](const auto &a, const auto &b){return a.y < b.y;}) - ps.begin();
  int j = std::max_element(ps.begin(), ps.end(), [](const auto &a, const auto &b){return a.y < b.y;}) - ps.begin();

  T ret = (ps[i]-ps[j]).size();

  for(int k = 0; k < 2*n; ++k){
    if(cross(ps[(i+1)%n]-ps[i], ps[(j+1)%n]-ps[j]) > 0){
      (++j) %= n;
    }else{
      (++i) %= n;
    }

    ret = std::max(ret, (ps[i]-ps[j]).size());
  }

  return ret;
}
