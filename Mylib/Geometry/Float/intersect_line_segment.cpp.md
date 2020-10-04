---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Geometry/Float/geometry_template.cpp
    title: Geometry template
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Geometry/Float/convex_cut.cpp
    title: Convex cut
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/CGL_4_C/main.test.cpp
    title: test/aoj/CGL_4_C/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Geometry/Float/intersect_line_segment.cpp\"\n#include\
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
    \ \"radius: \" << a.radius << \")\";\n    return s;\n  }\n}\n#line 4 \"Mylib/Geometry/Float/intersect_line_segment.cpp\"\
    \n\nnamespace haar_lib {\n  namespace intersect_line_segment_impl {\n    enum\
    \ class status_t { LEFTSIDE, RIGHTSIDE, OVERLAPPED, CROSSED };\n    template <typename\
    \ T>\n    struct result {\n      status_t status;\n      std::vector<point<T>>\
    \ crosspoints;\n      bool is_leftside() const {return status == status_t::LEFTSIDE;}\n\
    \      bool is_rightside() const {return status == status_t::RIGHTSIDE;}\n   \
    \   bool is_overlapped() const {return status == status_t::OVERLAPPED;}\n    \
    \  bool is_crossed() const {return status == status_t::CROSSED;}\n    };\n  }\n\
    \n  template <typename T>\n  auto intersect_line_segment(const line<T> &l, const\
    \ segment<T> &s){\n    using namespace intersect_line_segment_impl;\n\n    const\
    \ T a = cross(diff(l), s.from - l.from);\n    const T b = cross(diff(l), s.to\
    \ - l.from);\n\n    if(a == 0 and b == 0){\n      return result<T>({status_t::OVERLAPPED,\
    \ {}});\n    }\n    else if(a < 0 and b < 0){\n      return result<T>({status_t::RIGHTSIDE,\
    \ {}});\n    }\n    else if(a > 0 and b > 0){\n      return result<T>({status_t::LEFTSIDE,\
    \ {}});\n    }\n\n    return result<T>(\n      {\n       status_t::CROSSED,\n\
    \       {s.from + diff(s) * cross(diff(l), l.from - s.from) / cross(l, s)}\n \
    \     }\n    );\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"Mylib/Geometry/Float/geometry_template.cpp\"\
    \n\nnamespace haar_lib {\n  namespace intersect_line_segment_impl {\n    enum\
    \ class status_t { LEFTSIDE, RIGHTSIDE, OVERLAPPED, CROSSED };\n    template <typename\
    \ T>\n    struct result {\n      status_t status;\n      std::vector<point<T>>\
    \ crosspoints;\n      bool is_leftside() const {return status == status_t::LEFTSIDE;}\n\
    \      bool is_rightside() const {return status == status_t::RIGHTSIDE;}\n   \
    \   bool is_overlapped() const {return status == status_t::OVERLAPPED;}\n    \
    \  bool is_crossed() const {return status == status_t::CROSSED;}\n    };\n  }\n\
    \n  template <typename T>\n  auto intersect_line_segment(const line<T> &l, const\
    \ segment<T> &s){\n    using namespace intersect_line_segment_impl;\n\n    const\
    \ T a = cross(diff(l), s.from - l.from);\n    const T b = cross(diff(l), s.to\
    \ - l.from);\n\n    if(a == 0 and b == 0){\n      return result<T>({status_t::OVERLAPPED,\
    \ {}});\n    }\n    else if(a < 0 and b < 0){\n      return result<T>({status_t::RIGHTSIDE,\
    \ {}});\n    }\n    else if(a > 0 and b > 0){\n      return result<T>({status_t::LEFTSIDE,\
    \ {}});\n    }\n\n    return result<T>(\n      {\n       status_t::CROSSED,\n\
    \       {s.from + diff(s) * cross(diff(l), l.from - s.from) / cross(l, s)}\n \
    \     }\n    );\n  }\n}\n"
  dependsOn:
  - Mylib/Geometry/Float/geometry_template.cpp
  isVerificationFile: false
  path: Mylib/Geometry/Float/intersect_line_segment.cpp
  requiredBy:
  - Mylib/Geometry/Float/convex_cut.cpp
  timestamp: '2020-09-19 20:03:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/CGL_4_C/main.test.cpp
documentation_of: Mylib/Geometry/Float/intersect_line_segment.cpp
layout: document
title: Intersection between a line and a segment
---

## Operations

## Requirements

## Notes

## Problems

## References
