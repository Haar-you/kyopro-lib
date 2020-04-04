#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 直線と線分の交差
 */
namespace intersect_line_segment{
  enum Status{
              LEFTSIDE   = 0b0001,
              RIGHTSIDE  = 0b0010,
              OVERLAPPED = 0b0100,
              CROSSED    = 0b1000,
  };

  template <typename T>
  struct Result{
    Status status;
    std::vector<Point<T>> crosspoints;
  };

  template <typename T>
  auto check(const Line<T> &l, const Segment<T> &s){
    Result<T> ret;
    
    const T a = cross(l.diff(), s.from-l.from);
    const T b = cross(l.diff(), s.to-l.from);

    if(a == 0 and b == 0){
      ret.status = OVERLAPPED;
    }
    else if(a < 0 and b < 0){
      ret.status = RIGHTSIDE;
    }
    else if(a > 0 and b > 0){
      ret.status = LEFTSIDE;
    }
    else{
      ret.status = CROSSED;
      ret.crosspoints.emplace_back(s.from + s.diff() * cross(l.diff(),l.from-s.from) / cross(l.diff(),s.diff()));
    }
    return ret;
  }
}
