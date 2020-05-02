#pragma once
#include <cmath>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/ccw.cpp"

/**
 * @title 点・多角形の包含関係
 * @docs is_point_in_polygon.md
 */
namespace point_in_polygon{
  enum Status{
              INCLUSION  = 0b001,
              ON_SEGMENT = 0b010,
              OUTSIDE    = 0b100
  };

  template <typename T, typename U = typename T::value_type>
  Status check(const Point<T> &p, const Polygon<T> &polygon){
    const int n = polygon.size();
  
    T d = 0;
    for(int i = 0; i < n; ++i){
      if(ccw::ccw(polygon[i], polygon[(i+1)%n], p) == ccw::ON_SEGMENT) return ON_SEGMENT;
      
      T a = angle(polygon[i],p);
      T b = angle(polygon[(i+1)%n],p);

      if(a < 0) a += 2 * M_PI;
      if(b < 0) b += 2 * M_PI;

      T ang = b-a;

      if((T)std::fabs((U)ang) > M_PI){
        if(ang <= 0) ang += 2*M_PI;
        else ang -= 2*M_PI;
      }
      
      d += ang;
    }

    if((T)std::fabs(std::fabs((U)d) - 2*M_PI) == 0) return INCLUSION;
    
    return OUTSIDE;
  }
}
