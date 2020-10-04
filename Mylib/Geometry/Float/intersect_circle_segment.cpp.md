---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Geometry/Float/distance_segment_point.cpp
    title: Distance between a segment and a point
  - icon: ':question:'
    path: Mylib/Geometry/Float/geometry_template.cpp
    title: Geometry template
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Geometry/Float/area_intersection_of_circle_and_polygon.cpp
    title: Area of intersection between a circle and a polygon
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/CGL_7_H/main.test.cpp
    title: test/aoj/CGL_7_H/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Geometry/Float/intersect_circle_segment.cpp\"\n#include\
    \ <vector>\n#line 2 \"Mylib/Geometry/Float/geometry_template.cpp\"\n#include <iostream>\n\
    #include <cmath>\n#line 5 \"Mylib/Geometry/Float/geometry_template.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct vec {\n    T x, y;\n    vec(){}\n\
    \    vec(T x, T y): x(x), y(y){}\n\n    friend auto operator+(const vec &a, const\
    \ vec &b){return vec(a.x + b.x, a.y + b.y);}\n    friend auto operator-(const\
    \ vec &a, const vec &b){return vec(a.x - b.x, a.y - b.y);}\n    friend auto operator-(const\
    \ vec &a){return vec(-a.x, -a.y);}\n\n    friend bool operator==(const vec &a,\
    \ const vec &b){return a.x == b.x and a.y == b.y;}\n    friend bool operator!=(const\
    \ vec &a, const vec &b){return !(a == b);}\n    friend bool operator<(const vec\
    \ &a, const vec &b){return a.x < b.x or (a.x == b.x and a.y < b.y);}\n\n    friend\
    \ std::istream& operator>>(std::istream &s, vec &a){\n      s >> a.x >> a.y; return\
    \ s;\n    }\n  };\n\n  template <typename T, typename U> auto operator*(const\
    \ vec<T> &a, const U &k){return vec<T>(a.x * k, a.y * k);}\n  template <typename\
    \ T, typename U> auto operator*(const U &k, const vec<T> &a){return vec<T>(a.x\
    \ * k, a.y * k);}\n  template <typename T, typename U> auto operator/(const vec<T>\
    \ &a, const U &k){return vec<T>(a.x / k, a.y / k);}\n\n  template <typename T>\
    \ using point = vec<T>;\n\n  template <typename T> T abs(const vec<T> &a){return\
    \ sqrt(a.x * a.x + a.y * a.y);}\n  template <typename T> T abs_sq(const vec<T>\
    \ &a){return a.x * a.x + a.y * a.y;}\n\n  template <typename T> T dot(const vec<T>\
    \ &a, const vec<T> &b){return a.x * b.x + a.y * b.y;}\n  template <typename T>\
    \ T cross(const vec<T> &a, const vec<T> &b){return a.x * b.y - a.y * b.x;}\n\n\
    \  template <typename T> auto unit(const vec<T> &a){return a / abs(a);}\n  template\
    \ <typename T> auto normal(const vec<T> &p){return vec<T>(-p.y, p.x);}\n\n  template\
    \ <typename T> auto polar(const T &r, const T &ang){return vec<T>(r * cos(ang),\
    \ r * sin(ang));}\n\n  template <typename T> T angle(const vec<T> &a, const vec<T>\
    \ &b){return atan2(b.y - a.y, b.x - a.x);}\n  template <typename T> T phase(const\
    \ vec<T> &a){return atan2(a.y, a.x);}\n\n  template <typename T>\n  T angle_diff(const\
    \ vec<T> &a, const vec<T> &b){\n    T r = phase(b) - phase(a);\n\n    if(r < -M_PI)\
    \ return r + 2 * M_PI;\n    else if(r > M_PI) return r - 2 * M_PI;\n    return\
    \ r;\n  }\n\n\n  template <typename T> struct line {\n    point<T> from, to;\n\
    \    line(): from(), to(){}\n    line(const point<T> &from, const point<T> &to):\
    \ from(from), to(to){}\n  };\n\n  template <typename T> using segment = line<T>;\n\
    \n\n  template <typename T> auto unit(const line<T> &a){return unit(a.to - a.from);}\n\
    \  template <typename T> auto normal(const line<T> &a){return normal(a.to - a.from);}\n\
    \n  template <typename T> auto diff(const segment<T> &a){return a.to - a.from;}\n\
    \n  template <typename T> T abs(const segment<T> &a){return abs(diff(a));}\n\n\
    \  template <typename T> T dot(const line<T> &a, const line<T> &b){return dot(diff(a),\
    \ diff(b));}\n  template <typename T> T cross(const line<T> &a, const line<T>\
    \ &b){return cross(diff(a), diff(b));}\n\n\n  template <typename T> using polygon\
    \ = std::vector<point<T>>;\n\n  template <typename T> struct circle {\n    point<T>\
    \ center;\n    T radius;\n    circle(): center(), radius(0){}\n    circle(const\
    \ point<T> &center, T radius): center(center), radius(radius){}\n  };\n\n  template\
    \ <typename T>\n  std::ostream& operator<<(std::ostream &s, const vec<T> &a){\n\
    \    s << \"(\" << a.x << \", \" << a.y << \")\";\n    return s;\n  }\n\n  template\
    \ <typename T>\n  std::ostream& operator<<(std::ostream &s, const line<T> &a){\n\
    \    s << \"(\" << a.from << \" -> \" << a.to << \")\";\n    return s;\n  }\n\n\
    \  template <typename T>\n  std::ostream& operator<<(std::ostream &s, const circle<T>\
    \ &a){\n    s << \"(\"\n      << \"center: \" << a.center << \", \"\n      <<\
    \ \"radius: \" << a.radius << \")\";\n    return s;\n  }\n}\n#line 3 \"Mylib/Geometry/Float/distance_segment_point.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  T distance_segment_point(const\
    \ segment<T> &l, const point<T> &p){\n    if(dot(diff(l), p - l.from) < 0) return\
    \ abs(p - l.from);\n    if(dot(-diff(l), p - l.to) < 0) return abs(p - l.to);\n\
    \    return abs(cross(diff(l), p - l.from)) / abs(l);\n  }\n}\n#line 5 \"Mylib/Geometry/Float/intersect_circle_segment.cpp\"\
    \n\nnamespace haar_lib {\n  namespace intersect_circle_segment_impl {\n    enum\
    \ class status_t { INSIDE, OUTSIDE, TANGENT, ONE_CROSSPOINT, TWO_CROSSPOINTS };\n\
    \    template <typename T>\n    struct result {\n      status_t status;\n    \
    \  std::vector<point<T>> crosspoints;\n      bool is_inside() const {return status\
    \ == status_t::INSIDE;}\n      bool is_outside() const {return status == status_t::OUTSIDE;}\n\
    \      bool is_tangent() const {return status == status_t::TANGENT;}\n      bool\
    \ has_one_crosspoint() const {return status == status_t::ONE_CROSSPOINT;}\n  \
    \    bool has_two_crosspoints() const {return status == status_t::TWO_CROSSPOINTS;}\n\
    \    };\n  }\n\n  template <typename T>\n  auto intersect_circle_segment(const\
    \ circle<T> &cl, const line<T> &s){\n    using namespace intersect_circle_segment_impl;\n\
    \n    const T r = cl.radius;\n    const auto &c = cl.center;\n\n    const T d1\
    \ = abs(c - s.from);\n    const T d2 = abs(c - s.to);\n    const T v = distance_segment_point(s,\
    \ c);\n    const T m = sqrt(r * r - v * v);\n    const auto n = normal(s);\n \
    \   const auto k = s.from + diff(s) * cross(n, c + n - s.from) / cross(n, diff(s));\n\
    \n    if(d1 < r and d2 < r){\n      return result<T>({status_t::INSIDE, {}});\n\
    \    }\n    else if(v == r){\n      return result<T>({status_t::TANGENT, {k}});\n\
    \    }\n    else if(v > r){\n      return result<T>({status_t::OUTSIDE, {}});\n\
    \    }\n    else if(d1 >= r and d2 >= r){\n      return result<T>({status_t::TWO_CROSSPOINTS,\
    \ {k - unit(s) * m, k + unit(s) * m}});\n    }\n\n    const T b = dot(unit(s),\
    \ s.from - c);\n    const T a = abs_sq(s.from - c) - r * r;\n    const T x = sqrt(b\
    \ * b - a);\n\n    return result<T>(\n      {\n       status_t::ONE_CROSSPOINT,\n\
    \       {s.from + unit(s) * (-b - x >= 0 ? -b - x : -b + x)}\n      }\n    );\n\
    \  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"Mylib/Geometry/Float/geometry_template.cpp\"\
    \n#include \"Mylib/Geometry/Float/distance_segment_point.cpp\"\n\nnamespace haar_lib\
    \ {\n  namespace intersect_circle_segment_impl {\n    enum class status_t { INSIDE,\
    \ OUTSIDE, TANGENT, ONE_CROSSPOINT, TWO_CROSSPOINTS };\n    template <typename\
    \ T>\n    struct result {\n      status_t status;\n      std::vector<point<T>>\
    \ crosspoints;\n      bool is_inside() const {return status == status_t::INSIDE;}\n\
    \      bool is_outside() const {return status == status_t::OUTSIDE;}\n      bool\
    \ is_tangent() const {return status == status_t::TANGENT;}\n      bool has_one_crosspoint()\
    \ const {return status == status_t::ONE_CROSSPOINT;}\n      bool has_two_crosspoints()\
    \ const {return status == status_t::TWO_CROSSPOINTS;}\n    };\n  }\n\n  template\
    \ <typename T>\n  auto intersect_circle_segment(const circle<T> &cl, const line<T>\
    \ &s){\n    using namespace intersect_circle_segment_impl;\n\n    const T r =\
    \ cl.radius;\n    const auto &c = cl.center;\n\n    const T d1 = abs(c - s.from);\n\
    \    const T d2 = abs(c - s.to);\n    const T v = distance_segment_point(s, c);\n\
    \    const T m = sqrt(r * r - v * v);\n    const auto n = normal(s);\n    const\
    \ auto k = s.from + diff(s) * cross(n, c + n - s.from) / cross(n, diff(s));\n\n\
    \    if(d1 < r and d2 < r){\n      return result<T>({status_t::INSIDE, {}});\n\
    \    }\n    else if(v == r){\n      return result<T>({status_t::TANGENT, {k}});\n\
    \    }\n    else if(v > r){\n      return result<T>({status_t::OUTSIDE, {}});\n\
    \    }\n    else if(d1 >= r and d2 >= r){\n      return result<T>({status_t::TWO_CROSSPOINTS,\
    \ {k - unit(s) * m, k + unit(s) * m}});\n    }\n\n    const T b = dot(unit(s),\
    \ s.from - c);\n    const T a = abs_sq(s.from - c) - r * r;\n    const T x = sqrt(b\
    \ * b - a);\n\n    return result<T>(\n      {\n       status_t::ONE_CROSSPOINT,\n\
    \       {s.from + unit(s) * (-b - x >= 0 ? -b - x : -b + x)}\n      }\n    );\n\
    \  }\n}\n"
  dependsOn:
  - Mylib/Geometry/Float/geometry_template.cpp
  - Mylib/Geometry/Float/distance_segment_point.cpp
  isVerificationFile: false
  path: Mylib/Geometry/Float/intersect_circle_segment.cpp
  requiredBy:
  - Mylib/Geometry/Float/area_intersection_of_circle_and_polygon.cpp
  timestamp: '2020-09-19 20:03:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/CGL_7_H/main.test.cpp
documentation_of: Mylib/Geometry/Float/intersect_circle_segment.cpp
layout: document
title: Intersection between a circle and a segment
---

## Operations

## Requirements

## Notes

## Problems

## References
