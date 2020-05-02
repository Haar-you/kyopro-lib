#pragma once
#include <vector>
#include <cmath>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/ccw.cpp"

/**
 * @title 線分同士の交差
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

  template <typename T, typename U = typename T::value_type>
  auto check(const Segment<T> &a, const Segment<T> &b){
    Result<T> ret;
    
    T cr = cross(a.diff(), b.diff());

    if((T)std::abs((U)cr) == 0){ // parallel
      if(ccw::ccw(a.from, a.to, b.from) * ccw::ccw(a.from, a.to, b.to) <= 0 and
         ccw::ccw(b.from, b.to, a.from) * ccw::ccw(b.from, b.to, a.to) <= 0){
        ret.status = OVERLAPPED;
        return ret;
      }else{
        ret.status = NOT_INTERSECTING;
        return ret;
      }
    }

    T t1 = cross(b.from-a.from, b.diff()) / cr;
    T t2 = cross(b.from-a.from, a.diff()) / cr;

    if(t1 < 0 or t1 > 1 or t2 < 0 or t2 > 1){ // no crosspoint
      ret.status = NOT_INTERSECTING;
      return ret;
    }

    ret.crosspoints.emplace_back(a.from + a.diff() * t1);
    ret.status = INTERSECTING;
    return ret;
  }
}
