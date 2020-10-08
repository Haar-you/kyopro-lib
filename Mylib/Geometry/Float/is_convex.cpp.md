---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/ccw.cpp
    title: Check clockwise-counterclockwise
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/geometry_template.cpp
    title: Geometry template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_B/main.test.cpp
    title: test/aoj/CGL_3_B/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Geometry/Float/is_convex.cpp\"\n#include <vector>\n\
    #line 2 \"Mylib/Geometry/Float/geometry_template.cpp\"\n#include <iostream>\n\
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
    \ \"radius: \" << a.radius << \")\";\n    return s;\n  }\n}\n#line 3 \"Mylib/Geometry/Float/ccw.cpp\"\
    \n\nnamespace haar_lib {\n  namespace ccw_impl {\n    enum status {\n        \
    \         ONLINE_BACK       = -2,\n                 COUNTER_CLOCKWISE = -1,\n\
    \                 ON_SEGMENT        = 0,\n                 CLOCKWISE         =\
    \ 1,\n                 ONLINE_FRONT      = 2\n    };\n  }\n\n  struct ccw {\n\
    \    ccw_impl::status value;\n    bool operator==(const ccw &that) const {return\
    \ value == that.value;};\n    bool operator!=(const ccw &that) const {return value\
    \ != that.value;};\n    bool is_online_back() const {return value == ccw_impl::status::ONLINE_BACK;}\n\
    \    bool is_counter_clockwise() const {return value == ccw_impl::status::COUNTER_CLOCKWISE;}\n\
    \    bool is_on_segment() const {return value == ccw_impl::status::ON_SEGMENT;}\n\
    \    bool is_clockwise() const {return value == ccw_impl::status::CLOCKWISE;}\n\
    \    bool is_online_front() const {return value == ccw_impl::status::ONLINE_FRONT;}\n\
    \  };\n\n  template <typename T>\n  ccw check_ccw(const point<T> &p0, const point<T>\
    \ &p1, const point<T> &p2){\n    using namespace ccw_impl;\n\n    const T cr =\
    \ cross(p1 - p0, p2 - p0);\n    const T d = dot(p1 - p0, p2 - p0);\n\n    if(cr\
    \ == 0){\n      if(d < 0) return ccw({ONLINE_BACK});\n      else if(abs(p2 - p0)\
    \ > abs(p1 - p0)) return ccw({ONLINE_FRONT});\n      else return ccw({ON_SEGMENT});\n\
    \    }else if(cr > 0){\n      return ccw({COUNTER_CLOCKWISE});\n    }else{\n \
    \     return ccw({CLOCKWISE});\n    }\n  }\n}\n#line 5 \"Mylib/Geometry/Float/is_convex.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  bool is_convex(const polygon<T>\
    \ &ps){\n    const int n = ps.size();\n    std::vector<ccw> temp;\n\n    for(int\
    \ i = 0; i < n; ++i){\n      const auto c = check_ccw(ps[i], ps[(i + 1) % n],\
    \ ps[(i + 2) % n]);\n\n      if(c.is_clockwise() or c.is_counter_clockwise()){\n\
    \        if(temp.empty()) temp.push_back(c);\n        else if(temp.back() != c)\
    \ return false;\n      }\n    }\n\n    return true;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"Mylib/Geometry/Float/geometry_template.cpp\"\
    \n#include \"Mylib/Geometry/Float/ccw.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  bool is_convex(const polygon<T> &ps){\n    const int n = ps.size();\n\
    \    std::vector<ccw> temp;\n\n    for(int i = 0; i < n; ++i){\n      const auto\
    \ c = check_ccw(ps[i], ps[(i + 1) % n], ps[(i + 2) % n]);\n\n      if(c.is_clockwise()\
    \ or c.is_counter_clockwise()){\n        if(temp.empty()) temp.push_back(c);\n\
    \        else if(temp.back() != c) return false;\n      }\n    }\n\n    return\
    \ true;\n  }\n}\n"
  dependsOn:
  - Mylib/Geometry/Float/geometry_template.cpp
  - Mylib/Geometry/Float/ccw.cpp
  isVerificationFile: false
  path: Mylib/Geometry/Float/is_convex.cpp
  requiredBy: []
  timestamp: '2020-09-19 20:03:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_3_B/main.test.cpp
documentation_of: Mylib/Geometry/Float/is_convex.cpp
layout: document
title: Check convex
---

## Operations

## Requirements

## Notes

## Problems

## References
