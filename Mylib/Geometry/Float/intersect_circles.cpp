#pragma once
#include <vector>
#include <cmath>
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 円同士の交差
 * @see https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_A
 */
namespace intersect_circles{
  enum Status{
              SAME          = 0b000001,
              INSIDE        = 0b000010,
              INSCRIBED     = 0b000100,
              INTERSECT     = 0b001000,
              CIRCUMSCRIBED = 0b010000,
              OUTSIDE       = 0b100000
  };

  template <typename T>
  struct Result{
    Status status;
    std::vector<Point<T>> crosspoints;
  };
  
  template <typename T, typename U = typename T::value_type>
  auto check(const Circle<T> &a, const Circle<T> &b){
    Result<T> ret;
    
    const T d = (a.center - b.center).size();
    const T x = std::acos((U)((a.radius * a.radius + d * d - b.radius * b.radius) / ((T)2.0 * d * a.radius)));
    const T t = std::atan2((U)(b.center.y - a.center.y), (U)(b.center.x - a.center.x));
    
    if(a.radius + b.radius == d){
      ret.crosspoints.emplace_back(a.center + Vec<T>::polar(a.radius, t)); // if circumscribed
      ret.status = CIRCUMSCRIBED;
    }
    else if((T)std::fabs((U)(a.radius - b.radius)) == d){
      ret.crosspoints.emplace_back(a.center + Vec<T>::polar(a.radius, t)); // if inscribed
      ret.status = INSCRIBED;
    }
    else if(a.radius + b.radius > d and d > (T)std::fabs((U)(a.radius - b.radius))){ // if intersect
      ret.crosspoints.emplace_back(a.center + Vec<T>::polar(a.radius, t+x));
      ret.crosspoints.emplace_back(a.center + Vec<T>::polar(a.radius, t-x));
      ret.status = INTERSECT;
    }
    else if(a.radius + b.radius < d){
      ret.status = OUTSIDE;
    }
    else if((T)std::fabs((U)(a.radius - b.radius)) > d){
      ret.status = INSIDE;
    }
    else{
      ret.status = SAME;
    }
    
    return ret;
  }
}
