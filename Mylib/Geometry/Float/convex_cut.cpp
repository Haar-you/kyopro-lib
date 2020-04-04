#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/intersect_line_segment.cpp"
#include "Mylib/Geometry/Float/ccw.cpp"

/**
 * @title 凸多角形の切断
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C
 */
template <typename T>
void convex_cut(const Polygon<T> &ps, const Line<T> &l, Polygon<T> &left, Polygon<T> &right){
  const int n = ps.size();

  for(int i = 0; i < n; ++i){
    switch(auto [s, c] = intersect_line_segment::check(l, Line<T>(ps[i], ps[(i+1)%n])); s){
    case intersect_line_segment::LEFTSIDE:{
      left.push_back(ps[i]);
      break;
    }
    case intersect_line_segment::RIGHTSIDE:{
      right.push_back(ps[i]);
      break;
    }
    case intersect_line_segment::OVERLAPPED:{
      right.push_back(ps[i]);
      left.push_back(ps[i]);
      break;
    }
    case intersect_line_segment::CROSSED:{
      if(ccw::ccw(l.from, l.to, ps[i]) == ccw::CLOCKWISE){
        right.push_back(ps[i]);
      }else{
        left.push_back(ps[i]);
      }

      left.push_back(c[0]);
      right.push_back(c[0]);
      break;
    }
    }
  }
}
