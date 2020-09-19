#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

namespace haar_lib {
  namespace ccw_impl {
    enum status {
                 ONLINE_BACK       = -2,
                 COUNTER_CLOCKWISE = -1,
                 ON_SEGMENT        = 0,
                 CLOCKWISE         = 1,
                 ONLINE_FRONT      = 2
    };
  }

  struct ccw {
    ccw_impl::status value;
    bool operator==(const ccw &that) const {return value == that.value;};
    bool operator!=(const ccw &that) const {return value != that.value;};
    bool is_online_back() const {return value == ccw_impl::status::ONLINE_BACK;}
    bool is_counter_clockwise() const {return value == ccw_impl::status::COUNTER_CLOCKWISE;}
    bool is_on_segment() const {return value == ccw_impl::status::ON_SEGMENT;}
    bool is_clockwise() const {return value == ccw_impl::status::CLOCKWISE;}
    bool is_online_front() const {return value == ccw_impl::status::ONLINE_FRONT;}
  };

  template <typename T>
  ccw check_ccw(const point<T> &p0, const point<T> &p1, const point<T> &p2){
    using namespace ccw_impl;

    const T cr = cross(p1 - p0, p2 - p0);
    const T d = dot(p1 - p0, p2 - p0);

    if(cr == 0){
      if(d < 0) return ccw({ONLINE_BACK});
      else if(abs(p2 - p0) > abs(p1 - p0)) return ccw({ONLINE_FRONT});
      else return ccw({ON_SEGMENT});
    }else if(cr > 0){
      return ccw({COUNTER_CLOCKWISE});
    }else{
      return ccw({CLOCKWISE});
    }
  }
}
