#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/ccw.cpp"

/**
 * @title Intersection between two lines
 * @docs intersect_segments.md
 */
namespace intersect_segments{
  enum Status{
              INTERSECTING     = 0b0001,
              OVERLAPPED       = 0b0010,
              NOT_INTERSECTING = 0b0100,
              SAME             = 0b1000
  };

  template <typename T>
  struct Result{
    Status status;
    std::vector<Point<T>> crosspoints;
  };

  template <typename T>
  auto check(const Segment<T> &a, const Segment<T> &b){
    const T cr = cross(a, b);

    if(abs(cr) == 0){ // parallel
      if(ccw::ccw(a.from, a.to, b.from) * ccw::ccw(a.from, a.to, b.to) <= 0 and
         ccw::ccw(b.from, b.to, a.from) * ccw::ccw(b.from, b.to, a.to) <= 0){
        return Result<T>({OVERLAPPED, {}});
      }else{
        return Result<T>({NOT_INTERSECTING, {}});
      }
    }

    const T t1 = cross(b.from - a.from, diff(b)) / cr;
    const T t2 = cross(b.from - a.from, diff(a)) / cr;

    if(t1 < 0 or t1 > 1 or t2 < 0 or t2 > 1){ // no crosspoint
      return Result<T>({NOT_INTERSECTING, {}});
    }

    return Result<T>({INTERSECTING, {a.from + diff(a) * t1}});
  }
}
