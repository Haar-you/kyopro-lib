#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/ccw.cpp"

namespace haar_lib {
  namespace intersect_segments_impl {
    enum status_t { INTERSECTED, OVERLAPPED, NOT_INTERSECTED, SAME };
    template <typename T>
    struct result {
      status_t status;
      std::vector<point<T>> crosspoints;
      bool is_intersected() const {return status == status_t::INTERSECTED;}
      bool is_overlapped() const {return status == status_t::OVERLAPPED;}
      bool is_not_intersected() const {return status == status_t::NOT_INTERSECTED;}
      bool is_same() const {return status == status_t::SAME;}
    };
  }

  template <typename T>
  auto intersect_segments(const segment<T> &a, const segment<T> &b){
    using namespace intersect_segments_impl;

    const T cr = cross(a, b);

    if(abs(cr) == 0){ // parallel
      if(check_ccw(a.from, a.to, b.from).value * check_ccw(a.from, a.to, b.to).value <= 0 and
         check_ccw(b.from, b.to, a.from).value * check_ccw(b.from, b.to, a.to).value <= 0){
        return result<T>({status_t::OVERLAPPED, {}});
      }else{
        return result<T>({status_t::NOT_INTERSECTED, {}});
      }
    }

    const T t1 = cross(b.from - a.from, diff(b)) / cr;
    const T t2 = cross(b.from - a.from, diff(a)) / cr;

    if(t1 < 0 or t1 > 1 or t2 < 0 or t2 > 1){ // no crosspoint
      return result<T>({status_t::NOT_INTERSECTED, {}});
    }

    return result<T>({status_t::INTERSECTED, {a.from + diff(a) * t1}});
  }
}
