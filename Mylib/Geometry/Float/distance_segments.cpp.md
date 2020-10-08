---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/distance_segment_point.cpp
    title: Distance between a segment and a point
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/geometry_template.cpp
    title: Geometry template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_D/main.test.cpp
    title: test/aoj/CGL_2_D/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Geometry/Float/distance_segments.cpp\"\n#include <algorithm>\n\
    #line 2 \"Mylib/Geometry/Float/geometry_template.cpp\"\n#include <iostream>\n\
    #include <cmath>\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct vec {\n    T x, y;\n    vec(){}\n    vec(T x, T y): x(x), y(y){}\n\
    \n    friend auto operator+(const vec &a, const vec &b){return vec(a.x + b.x,\
    \ a.y + b.y);}\n    friend auto operator-(const vec &a, const vec &b){return vec(a.x\
    \ - b.x, a.y - b.y);}\n    friend auto operator-(const vec &a){return vec(-a.x,\
    \ -a.y);}\n\n    friend bool operator==(const vec &a, const vec &b){return a.x\
    \ == b.x and a.y == b.y;}\n    friend bool operator!=(const vec &a, const vec\
    \ &b){return !(a == b);}\n    friend bool operator<(const vec &a, const vec &b){return\
    \ a.x < b.x or (a.x == b.x and a.y < b.y);}\n\n    friend std::istream& operator>>(std::istream\
    \ &s, vec &a){\n      s >> a.x >> a.y; return s;\n    }\n  };\n\n  template <typename\
    \ T, typename U> auto operator*(const vec<T> &a, const U &k){return vec<T>(a.x\
    \ * k, a.y * k);}\n  template <typename T, typename U> auto operator*(const U\
    \ &k, const vec<T> &a){return vec<T>(a.x * k, a.y * k);}\n  template <typename\
    \ T, typename U> auto operator/(const vec<T> &a, const U &k){return vec<T>(a.x\
    \ / k, a.y / k);}\n\n  template <typename T> using point = vec<T>;\n\n  template\
    \ <typename T> T abs(const vec<T> &a){return sqrt(a.x * a.x + a.y * a.y);}\n \
    \ template <typename T> T abs_sq(const vec<T> &a){return a.x * a.x + a.y * a.y;}\n\
    \n  template <typename T> T dot(const vec<T> &a, const vec<T> &b){return a.x *\
    \ b.x + a.y * b.y;}\n  template <typename T> T cross(const vec<T> &a, const vec<T>\
    \ &b){return a.x * b.y - a.y * b.x;}\n\n  template <typename T> auto unit(const\
    \ vec<T> &a){return a / abs(a);}\n  template <typename T> auto normal(const vec<T>\
    \ &p){return vec<T>(-p.y, p.x);}\n\n  template <typename T> auto polar(const T\
    \ &r, const T &ang){return vec<T>(r * cos(ang), r * sin(ang));}\n\n  template\
    \ <typename T> T angle(const vec<T> &a, const vec<T> &b){return atan2(b.y - a.y,\
    \ b.x - a.x);}\n  template <typename T> T phase(const vec<T> &a){return atan2(a.y,\
    \ a.x);}\n\n  template <typename T>\n  T angle_diff(const vec<T> &a, const vec<T>\
    \ &b){\n    T r = phase(b) - phase(a);\n\n    if(r < -M_PI) return r + 2 * M_PI;\n\
    \    else if(r > M_PI) return r - 2 * M_PI;\n    return r;\n  }\n\n\n  template\
    \ <typename T> struct line {\n    point<T> from, to;\n    line(): from(), to(){}\n\
    \    line(const point<T> &from, const point<T> &to): from(from), to(to){}\n  };\n\
    \n  template <typename T> using segment = line<T>;\n\n\n  template <typename T>\
    \ auto unit(const line<T> &a){return unit(a.to - a.from);}\n  template <typename\
    \ T> auto normal(const line<T> &a){return normal(a.to - a.from);}\n\n  template\
    \ <typename T> auto diff(const segment<T> &a){return a.to - a.from;}\n\n  template\
    \ <typename T> T abs(const segment<T> &a){return abs(diff(a));}\n\n  template\
    \ <typename T> T dot(const line<T> &a, const line<T> &b){return dot(diff(a), diff(b));}\n\
    \  template <typename T> T cross(const line<T> &a, const line<T> &b){return cross(diff(a),\
    \ diff(b));}\n\n\n  template <typename T> using polygon = std::vector<point<T>>;\n\
    \n  template <typename T> struct circle {\n    point<T> center;\n    T radius;\n\
    \    circle(): center(), radius(0){}\n    circle(const point<T> &center, T radius):\
    \ center(center), radius(radius){}\n  };\n\n  template <typename T>\n  std::ostream&\
    \ operator<<(std::ostream &s, const vec<T> &a){\n    s << \"(\" << a.x << \",\
    \ \" << a.y << \")\";\n    return s;\n  }\n\n  template <typename T>\n  std::ostream&\
    \ operator<<(std::ostream &s, const line<T> &a){\n    s << \"(\" << a.from <<\
    \ \" -> \" << a.to << \")\";\n    return s;\n  }\n\n  template <typename T>\n\
    \  std::ostream& operator<<(std::ostream &s, const circle<T> &a){\n    s << \"\
    (\"\n      << \"center: \" << a.center << \", \"\n      << \"radius: \" << a.radius\
    \ << \")\";\n    return s;\n  }\n}\n#line 3 \"Mylib/Geometry/Float/distance_segment_point.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  T distance_segment_point(const\
    \ segment<T> &l, const point<T> &p){\n    if(dot(diff(l), p - l.from) < 0) return\
    \ abs(p - l.from);\n    if(dot(-diff(l), p - l.to) < 0) return abs(p - l.to);\n\
    \    return abs(cross(diff(l), p - l.from)) / abs(l);\n  }\n}\n#line 5 \"Mylib/Geometry/Float/distance_segments.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  T distance_segments(const\
    \ segment<T> &l1, const segment<T> &l2){\n    const T cr = cross(l1, l2);\n  \
    \  const T t1 = cross(l2.from - l1.from, diff(l2)) / cr;\n    const T t2 = cross(l2.from\
    \ - l1.from, diff(l1)) / cr;\n\n    if(t1 < 0 or t1 > 1 or t2 < 0 or t2 > 1){\n\
    \      return std::min(\n        {\n         distance_segment_point(l1, l2.from),\n\
    \         distance_segment_point(l1, l2.to),\n         distance_segment_point(l2,\
    \ l1.from),\n         distance_segment_point(l2, l1.to)\n        }\n      );\n\
    \    }else{\n      return 0;\n    }\n  }\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include \"Mylib/Geometry/Float/geometry_template.cpp\"\
    \n#include \"Mylib/Geometry/Float/distance_segment_point.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  T distance_segments(const segment<T> &l1, const\
    \ segment<T> &l2){\n    const T cr = cross(l1, l2);\n    const T t1 = cross(l2.from\
    \ - l1.from, diff(l2)) / cr;\n    const T t2 = cross(l2.from - l1.from, diff(l1))\
    \ / cr;\n\n    if(t1 < 0 or t1 > 1 or t2 < 0 or t2 > 1){\n      return std::min(\n\
    \        {\n         distance_segment_point(l1, l2.from),\n         distance_segment_point(l1,\
    \ l2.to),\n         distance_segment_point(l2, l1.from),\n         distance_segment_point(l2,\
    \ l1.to)\n        }\n      );\n    }else{\n      return 0;\n    }\n  }\n}\n"
  dependsOn:
  - Mylib/Geometry/Float/geometry_template.cpp
  - Mylib/Geometry/Float/distance_segment_point.cpp
  isVerificationFile: false
  path: Mylib/Geometry/Float/distance_segments.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_2_D/main.test.cpp
documentation_of: Mylib/Geometry/Float/distance_segments.cpp
layout: document
title: Distance between two segments
---

## Operations

## Requirements

## Notes

## Problems

## References
