#pragma once
#include <vector>
#include <cmath>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/distance_segment_point.cpp"

/**
 * @title 円と線分の交差
 * @docs intersect_circle_segment.md
 */
namespace intersect_circle_segment{
  enum Status{
              INSIDE         = 0b00001,
              OUTSIDE        = 0b00010,
              TANGENT        = 0b00100,
              ONE_CROSSPOINT = 0b01000,
              TWO_CROSSPOINT = 0b10000
  };

  template <typename T>
  struct Result{
    Status status;
    std::vector<Point<T>> crosspoints;
  };

  template <typename T, typename U = typename T::value_type>
  auto check(const Circle<T> &cl, const Line<T> &s){
    Result<T> ret;
    
    const T r = cl.radius;
    const auto &c = cl.center;

    const T d1 = (c - s.from).size();
    const T d2 = (c - s.to).size();
    const T v = distance_segment_point(s, c);
    const T m = std::sqrt((U)(r*r - v*v));
    const auto n = normal(s.diff());
    const auto k = s.from + s.diff() * cross(n, c + n - s.from) / cross(n, s.diff());

    if(d1 < r and d2 < r){ // if inside
      ret.status = INSIDE;
    }
    else if(v == r){ // if tangent
      ret.crosspoints.emplace_back(k);
      ret.status = TANGENT;
    }
    else if(v > r){ // if outside
      ret.status = OUTSIDE;
    }
    else if(d1 >= r and d2 >= r){ // if two crosspoints exist
      ret.crosspoints.emplace_back(k - unit(s.diff()) * m);
      ret.crosspoints.emplace_back(k + unit(s.diff()) * m);
      ret.status = TWO_CROSSPOINT;
    }
    else{ // if one crosspoint exists
      const T b = dot(unit(s.diff()), s.from - c);
      const T a = (s.from - c).size_sq() - r*r;
      const T x = std::sqrt((U)(b*b - a));
      ret.crosspoints.emplace_back(s.from + unit(s.diff()) * (-b-x >= 0 ? -b-x : -b+x));
      ret.status = ONE_CROSSPOINT;
    }

    return ret;
  }
};
