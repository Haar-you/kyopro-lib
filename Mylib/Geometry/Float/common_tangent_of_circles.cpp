#pragma once
#include <vector>
#include <cmath>
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 2円の共通接線
 * @docs common_tangent_of_circles.md
 */
template <typename T, typename U = typename T::value_type>
std::vector<Point<T>> common_tangent_of_circles(const Circle<T> &a, const Circle<T> &b){
  const T d = (b.center - a.center).size();
  const auto n = unit(b.center - a.center);

  const auto cc = b.center - a.center;
  const T r = a.radius - b.radius;
  const T R = a.radius + b.radius;
  
  if(a.radius + b.radius == d){ // 一方が他方に外接している。
    return {
            a.center + (cc*r + normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + (cc*r - normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + n * a.radius
    };
  }else if(a.radius + b.radius < d){ // aとbは互いに離れている。
    return {
            a.center + (cc*r + normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + (cc*r - normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + (cc*R + normal(cc) * std::sqrt((U)(cc.size_sq()-R*R))) * a.radius / cc.size_sq(),
            a.center + (cc*R - normal(cc) * std::sqrt((U)(cc.size_sq()-R*R))) * a.radius / cc.size_sq()	    
    };
  }else if(a.radius + b.radius > d and d > (T)std::fabs((U)(a.radius - b.radius))){ // aとbは二点で交差している。
    return {
            a.center + (cc*r + normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + (cc*r - normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq()	    
    };
  }else if((T)std::fabs((U)(a.radius - b.radius)) == d){ // 一方が他方に内接している。
    return {
            a.radius > b.radius ? a.center + n * a.radius : b.center - n * b.radius
    };
  }

  return {};
}
