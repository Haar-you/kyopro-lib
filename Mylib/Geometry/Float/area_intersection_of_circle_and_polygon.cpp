#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/intersect_circle_segment.cpp"

/**
 * @title 円と多角形の共通面積
 * @see https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_H
 */
template <typename T>
T area_intersection_of_circle_and_polygon(const Circle<T> &cl, const Polygon<T> &ps){
  const int n = ps.size();
  T ret = 0;
  
  for(int i = 0; i < n; ++i){
    T temp = 0;

    const T r = cl.radius;
    const auto &c = cl.center;

    const auto &p1 = ps[i];
    const auto &p2 = ps[(i+1)%n];

    const auto [t, res] = intersect_circle_segment::check(cl, Line<T>(p1,p2));

    const T d1 = (p1 - c).size();
    const T d2 = (p2 - c).size();
    
    if(res.size() == 0){
      if(t == intersect_circle_segment::INSIDE){ // if inside
        temp += cross(p1-c, p2-c) / 2;
      }else{ // if outside
        temp += r * r * angle_diff(p1-c, p2-c) / 2;
      }
    }else if(res.size() == 1){
      const auto &q = res[0];
      if(d1 >= r and d2 >= r){
        temp += r * r * angle_diff(p1-c, p2-c) / 2;
      }else if(d1 >= r){
        temp += r * r * angle_diff(p1-c, q-c) / 2 + cross(q-c, p2-c) / 2;
      }else{
        temp += cross(p1-c, q-c) / 2 + r * r * angle_diff(q-c, p2-c) / 2;
      }
    }else{
      const auto &q1 = res[0];
      const auto &q2 = res[1];
      temp +=
        r * r * angle_diff(p1-c, q1-c) / 2 +
        cross(q1-c, q2-c) / 2 +
        r * r * angle_diff(q2-c, p2-c) / 2;
    }
    
    ret += temp;
  }

  return ret;
}
