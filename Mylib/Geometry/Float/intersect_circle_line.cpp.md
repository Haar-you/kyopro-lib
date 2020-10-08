---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/distance_line_point.cpp
    title: Distance between a line and a point
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/geometry_template.cpp
    title: Geometry template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_D/main.test.cpp
    title: test/aoj/CGL_7_D/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Geometry/Float/intersect_circle_line.cpp\"\n#include\
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
    \ \"radius: \" << a.radius << \")\";\n    return s;\n  }\n}\n#line 3 \"Mylib/Geometry/Float/distance_line_point.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  T distance_line_point(const\
    \ line<T> &l, const point<T> &p){\n    return abs(cross(diff(l), p - l.from) /\
    \ abs(l));\n  }\n}\n#line 5 \"Mylib/Geometry/Float/intersect_circle_line.cpp\"\
    \n\nnamespace haar_lib {\n  namespace intersect_circle_line_impl {\n    enum class\
    \ status_t { OUTSIDE, TANGENT, CROSSED };\n    template <typename T>\n    struct\
    \ result {\n      status_t status;\n      std::vector<point<T>> crosspoints;\n\
    \      bool is_outside() const {return status == status_t::OUTSIDE;}\n      bool\
    \ is_tangent() const {return status == status_t::TANGENT;}\n      bool is_crossed()\
    \ const {return status == status_t::CROSSED;}\n    };\n  }\n\n  template <typename\
    \ T>\n  auto intersect_circle_line(const circle<T> &c, const line<T> &l){\n  \
    \  using namespace intersect_circle_line_impl;\n\n    const T d = distance_line_point(l,\
    \ c.center);\n\n    if(d > c.radius){\n      return result<T>({status_t::OUTSIDE,\
    \ {}});\n    }\n\n    const auto n = normal(l);\n    const auto b = l.from + diff(l)\
    \ * cross(n, c.center + n - l.from) / cross(n, diff(l));\n\n    if(d == c.radius){\n\
    \      return result<T>({status_t::TANGENT, {b}});\n    }\n\n    const T a = sqrt(c.radius\
    \ * c.radius - d * d);\n    return result<T>({status_t::CROSSED, {b + unit(l)\
    \ * a, b - unit(l) * a}});\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"Mylib/Geometry/Float/geometry_template.cpp\"\
    \n#include \"Mylib/Geometry/Float/distance_line_point.cpp\"\n\nnamespace haar_lib\
    \ {\n  namespace intersect_circle_line_impl {\n    enum class status_t { OUTSIDE,\
    \ TANGENT, CROSSED };\n    template <typename T>\n    struct result {\n      status_t\
    \ status;\n      std::vector<point<T>> crosspoints;\n      bool is_outside() const\
    \ {return status == status_t::OUTSIDE;}\n      bool is_tangent() const {return\
    \ status == status_t::TANGENT;}\n      bool is_crossed() const {return status\
    \ == status_t::CROSSED;}\n    };\n  }\n\n  template <typename T>\n  auto intersect_circle_line(const\
    \ circle<T> &c, const line<T> &l){\n    using namespace intersect_circle_line_impl;\n\
    \n    const T d = distance_line_point(l, c.center);\n\n    if(d > c.radius){\n\
    \      return result<T>({status_t::OUTSIDE, {}});\n    }\n\n    const auto n =\
    \ normal(l);\n    const auto b = l.from + diff(l) * cross(n, c.center + n - l.from)\
    \ / cross(n, diff(l));\n\n    if(d == c.radius){\n      return result<T>({status_t::TANGENT,\
    \ {b}});\n    }\n\n    const T a = sqrt(c.radius * c.radius - d * d);\n    return\
    \ result<T>({status_t::CROSSED, {b + unit(l) * a, b - unit(l) * a}});\n  }\n}\n"
  dependsOn:
  - Mylib/Geometry/Float/geometry_template.cpp
  - Mylib/Geometry/Float/distance_line_point.cpp
  isVerificationFile: false
  path: Mylib/Geometry/Float/intersect_circle_line.cpp
  requiredBy: []
  timestamp: '2020-09-19 20:03:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_7_D/main.test.cpp
documentation_of: Mylib/Geometry/Float/intersect_circle_line.cpp
layout: document
title: Intersection between a circle and a line
---

## Operations

## Requirements

## Notes

## Problems

## References
