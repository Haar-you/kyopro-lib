#pragma once
#include <algorithm>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/distance_segment_point.cpp"

namespace haar_lib {
  template <typename T>
  T distance_segments(const segment<T> &l1, const segment<T> &l2){
    const T cr = cross(l1, l2);
    const T t1 = cross(l2.from - l1.from, diff(l2)) / cr;
    const T t2 = cross(l2.from - l1.from, diff(l1)) / cr;

    if(t1 < 0 or t1 > 1 or t2 < 0 or t2 > 1){
      return std::min(
        {
         distance_segment_point(l1, l2.from),
         distance_segment_point(l1, l2.to),
         distance_segment_point(l2, l1.from),
         distance_segment_point(l2, l1.to)
        }
      );
    }else{
      return 0;
    }
  }
}
