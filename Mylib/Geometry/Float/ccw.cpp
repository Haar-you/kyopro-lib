#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title clockwise-counterclockwise判定
 * @docs ccw.md
 */
namespace ccw{
  enum CCW{
           ONLINE_BACK       = -2,
           COUNTER_CLOCKWISE = -1,
           ON_SEGMENT        = 0,
           CLOCKWISE         = 1,
           ONLINE_FRONT      = 2
  };

  template <typename T>
  CCW ccw(const Point<T> &p0, const Point<T> &p1, const Point<T> &p2){
    const T cr = cross(p1-p0, p2-p0);
    const T d = dot(p1-p0, p2-p0);

    if(cr == 0){
      if(d < 0) return ONLINE_BACK;
      else if((p2-p0).size() > (p1-p0).size()) return ONLINE_FRONT;
      else return ON_SEGMENT;
    }else if(cr > 0){
      return COUNTER_CLOCKWISE;
    }else{
      return CLOCKWISE;
    }
  }
}
