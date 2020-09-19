#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"

namespace haar_lib {
  namespace intersect_circles_impl {
    enum class status_t { SAME, INSIDE, INSCRIBED, INTERSECTED, CIRCUMSCRIBED, OUTSIDE };
    template <typename T>
    struct result {
      status_t status;
      std::vector<point<T>> crosspoints;
      bool is_same() const {return status == status_t::SAME;}
      bool is_inside() const {return status == status_t::INSIDE;}
      bool is_inscribed() const {return status == status_t::INSCRIBED;}
      bool is_intersected() const {return status == status_t::INTERSECTED;}
      bool is_circumscribed() const {return status == status_t::CIRCUMSCRIBED;}
      bool is_outside() const {return status == status_t::OUTSIDE;}
    };
  }

  template <typename T>
  auto intersect_circles(const circle<T> &a, const circle<T> &b){
    using namespace intersect_circles_impl;

    const T d = abs(a.center - b.center);
    const T x = acos((a.radius * a.radius + d * d - b.radius * b.radius) / ((T)2.0 * d * a.radius));
    const T t = atan2(b.center.y - a.center.y, b.center.x - a.center.x);

    if(a.radius + b.radius == d){
      return result<T>({status_t::CIRCUMSCRIBED, {a.center + polar(a.radius, t)}});
    }
    else if(abs(a.radius - b.radius) == d){
      return result<T>({status_t::INSCRIBED, {a.center + polar(a.radius, t)}});
    }
    else if(a.radius + b.radius > d and d > abs(a.radius - b.radius)){
      return result<T>(
        {
         status_t::INTERSECTED,
         {a.center + polar(a.radius, t + x), a.center + polar(a.radius, t - x)}
        }
      );
    }
    else if(a.radius + b.radius < d){
      return result<T>({status_t::OUTSIDE, {}});
    }
    else if(abs(a.radius - b.radius) > d){
      return result<T>({status_t::INSIDE, {}});
    }

    return result<T>({status_t::SAME, {}});
  }
}
