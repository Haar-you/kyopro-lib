#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/distance_segment_point.cpp"

namespace haar_lib {
  namespace intersect_circle_segment_impl {
    enum class status_t { INSIDE, OUTSIDE, TANGENT, ONE_CROSSPOINT, TWO_CROSSPOINTS };
    template <typename T>
    struct result {
      status_t status;
      std::vector<point<T>> crosspoints;
      bool is_inside() const {return status == status_t::INSIDE;}
      bool is_outside() const {return status == status_t::OUTSIDE;}
      bool is_tangent() const {return status == status_t::TANGENT;}
      bool has_one_crosspoint() const {return status == status_t::ONE_CROSSPOINT;}
      bool has_two_crosspoints() const {return status == status_t::TWO_CROSSPOINTS;}
    };
  }

  template <typename T>
  auto intersect_circle_segment(const circle<T> &cl, const line<T> &s){
    using namespace intersect_circle_segment_impl;

    const T r = cl.radius;
    const auto &c = cl.center;

    const T d1 = abs(c - s.from);
    const T d2 = abs(c - s.to);
    const T v = distance_segment_point(s, c);
    const T m = sqrt(r * r - v * v);
    const auto n = normal(s);
    const auto k = s.from + diff(s) * cross(n, c + n - s.from) / cross(n, diff(s));

    if(d1 < r and d2 < r){
      return result<T>({status_t::INSIDE, {}});
    }
    else if(v == r){
      return result<T>({status_t::TANGENT, {k}});
    }
    else if(v > r){
      return result<T>({status_t::OUTSIDE, {}});
    }
    else if(d1 >= r and d2 >= r){
      return result<T>({status_t::TWO_CROSSPOINTS, {k - unit(s) * m, k + unit(s) * m}});
    }

    const T b = dot(unit(s), s.from - c);
    const T a = abs_sq(s.from - c) - r * r;
    const T x = sqrt(b * b - a);

    return result<T>(
      {
       status_t::ONE_CROSSPOINT,
       {s.from + unit(s) * (-b - x >= 0 ? -b - x : -b + x)}
      }
    );
  }
}
