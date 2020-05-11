#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 直線と線分の交差
 * @docs intersect_line_segment.md
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
    const T a = cross(diff(l), s.from - l.from);
    const T b = cross(diff(l), s.to - l.from);

    if(a == 0 and b == 0){
      return Result<T>({OVERLAPPED, {}});
    }
    else if(a < 0 and b < 0){
      return Result<T>({RIGHTSIDE, {}});
    }
    else if(a > 0 and b > 0){
      return Result<T>({LEFTSIDE, {}});
    }
    
    return Result<T>({CROSSED, {s.from + diff(s) * cross(diff(l), l.from - s.from) / cross(l, s)}});
  }
}
