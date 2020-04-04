#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 多角形の面積
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
 */
template <typename T>
T polygon_area(const Polygon<T> &ps){
  T ret = 0;
  const int n = (int)ps.size();
  for(int i = 0; i < n; ++i){
    ret += (ps[i].x-ps[(i+1)%n].x) * (ps[i].y+ps[(i+1)%n].y);
  }
  if(ret < 0) ret = -ret;
  ret /= 2;
  return ret;
}
