---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Geometry/Float/geometry_template.cpp
    title: Geometry template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_A/main.test.cpp
    title: test/aoj/CGL_4_A/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Geometry/Float/convex_hull.cpp\"\n#include <algorithm>\n\
    #include <vector>\n#line 2 \"Mylib/Geometry/Float/geometry_template.cpp\"\n#include\
    \ <cmath>\n#include <iostream>\n#line 5 \"Mylib/Geometry/Float/geometry_template.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct vec {\n    T x, y;\n\
    \    vec() {}\n    vec(T x, T y) : x(x), y(y) {}\n\n    friend auto operator+(const\
    \ vec &a, const vec &b) { return vec(a.x + b.x, a.y + b.y); }\n    friend auto\
    \ operator-(const vec &a, const vec &b) { return vec(a.x - b.x, a.y - b.y); }\n\
    \    friend auto operator-(const vec &a) { return vec(-a.x, -a.y); }\n\n    friend\
    \ bool operator==(const vec &a, const vec &b) { return a.x == b.x and a.y == b.y;\
    \ }\n    friend bool operator!=(const vec &a, const vec &b) { return !(a == b);\
    \ }\n    friend bool operator<(const vec &a, const vec &b) { return a.x < b.x\
    \ or (a.x == b.x and a.y < b.y); }\n\n    friend std::istream &operator>>(std::istream\
    \ &s, vec &a) {\n      s >> a.x >> a.y;\n      return s;\n    }\n  };\n\n  template\
    \ <typename T, typename U>\n  auto operator*(const vec<T> &a, const U &k) { return\
    \ vec<T>(a.x * k, a.y * k); }\n  template <typename T, typename U>\n  auto operator*(const\
    \ U &k, const vec<T> &a) { return vec<T>(a.x * k, a.y * k); }\n  template <typename\
    \ T, typename U>\n  auto operator/(const vec<T> &a, const U &k) { return vec<T>(a.x\
    \ / k, a.y / k); }\n\n  template <typename T>\n  using point = vec<T>;\n\n  template\
    \ <typename T>\n  T abs(const vec<T> &a) { return sqrt(a.x * a.x + a.y * a.y);\
    \ }\n  template <typename T>\n  T abs_sq(const vec<T> &a) { return a.x * a.x +\
    \ a.y * a.y; }\n\n  template <typename T>\n  T dot(const vec<T> &a, const vec<T>\
    \ &b) { return a.x * b.x + a.y * b.y; }\n  template <typename T>\n  T cross(const\
    \ vec<T> &a, const vec<T> &b) { return a.x * b.y - a.y * b.x; }\n\n  template\
    \ <typename T>\n  auto unit(const vec<T> &a) { return a / abs(a); }\n  template\
    \ <typename T>\n  auto normal(const vec<T> &p) { return vec<T>(-p.y, p.x); }\n\
    \n  template <typename T>\n  auto polar(const T &r, const T &ang) { return vec<T>(r\
    \ * cos(ang), r * sin(ang)); }\n\n  template <typename T>\n  T angle(const vec<T>\
    \ &a, const vec<T> &b) { return atan2(b.y - a.y, b.x - a.x); }\n  template <typename\
    \ T>\n  T phase(const vec<T> &a) { return atan2(a.y, a.x); }\n\n  template <typename\
    \ T>\n  T angle_diff(const vec<T> &a, const vec<T> &b) {\n    T r = phase(b) -\
    \ phase(a);\n\n    if (r < -M_PI)\n      return r + 2 * M_PI;\n    else if (r\
    \ > M_PI)\n      return r - 2 * M_PI;\n    return r;\n  }\n\n  template <typename\
    \ T>\n  struct line {\n    point<T> from, to;\n    line() : from(), to() {}\n\
    \    line(const point<T> &from, const point<T> &to) : from(from), to(to) {}\n\
    \  };\n\n  template <typename T>\n  using segment = line<T>;\n\n  template <typename\
    \ T>\n  auto unit(const line<T> &a) { return unit(a.to - a.from); }\n  template\
    \ <typename T>\n  auto normal(const line<T> &a) { return normal(a.to - a.from);\
    \ }\n\n  template <typename T>\n  auto diff(const segment<T> &a) { return a.to\
    \ - a.from; }\n\n  template <typename T>\n  T abs(const segment<T> &a) { return\
    \ abs(diff(a)); }\n\n  template <typename T>\n  T dot(const line<T> &a, const\
    \ line<T> &b) { return dot(diff(a), diff(b)); }\n  template <typename T>\n  T\
    \ cross(const line<T> &a, const line<T> &b) { return cross(diff(a), diff(b));\
    \ }\n\n  template <typename T>\n  using polygon = std::vector<point<T>>;\n\n \
    \ template <typename T>\n  struct circle {\n    point<T> center;\n    T radius;\n\
    \    circle() : center(), radius(0) {}\n    circle(const point<T> &center, T radius)\
    \ : center(center), radius(radius) {}\n  };\n\n  template <typename T>\n  std::ostream\
    \ &operator<<(std::ostream &s, const vec<T> &a) {\n    s << \"(\" << a.x << \"\
    , \" << a.y << \")\";\n    return s;\n  }\n\n  template <typename T>\n  std::ostream\
    \ &operator<<(std::ostream &s, const line<T> &a) {\n    s << \"(\" << a.from <<\
    \ \" -> \" << a.to << \")\";\n    return s;\n  }\n\n  template <typename T>\n\
    \  std::ostream &operator<<(std::ostream &s, const circle<T> &a) {\n    s << \"\
    (\"\n      << \"center: \" << a.center << \", \"\n      << \"radius: \" << a.radius\
    \ << \")\";\n    return s;\n  }\n}  // namespace haar_lib\n#line 5 \"Mylib/Geometry/Float/convex_hull.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<point<T>> upper_hull(polygon<T>\
    \ pts, bool upper = true) {\n    std::sort(\n        pts.begin(),\n        pts.end(),\n\
    \        [](const auto &a, const auto &b) { return a.x < b.x or (a.x == b.x and\
    \ a.y < b.y); });\n\n    if (upper) std::reverse(pts.begin(), pts.end());\n\n\
    \    std::vector<point<T>> ret;\n\n    ret.push_back(pts.back());\n    pts.pop_back();\n\
    \n    while (not pts.empty()) {\n      const auto s = pts.back();\n      pts.pop_back();\n\
    \n      if (ret.size() == 1) {\n        ret.push_back(s);\n      } else {\n  \
    \      const auto p = *(ret.end() - 2);\n        const auto q = ret.back();\n\n\
    \        if (cross(q - p, s - p) <= 0) {\n          ret.push_back(s);\n      \
    \  } else {\n          ret.pop_back();\n          pts.push_back(s);\n        }\n\
    \      }\n    }\n\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<point<T>>\
    \ convex_hull(const polygon<T> &pts) {\n    auto ret   = upper_hull(pts);\n  \
    \  auto lower = upper_hull(pts, false);\n\n    ret.pop_back();\n    lower.pop_back();\n\
    \n    for (auto &p : lower) ret.push_back(p);\n\n    return ret;\n  }\n}  // namespace\
    \ haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include \"Mylib/Geometry/Float/geometry_template.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<point<T>> upper_hull(polygon<T>\
    \ pts, bool upper = true) {\n    std::sort(\n        pts.begin(),\n        pts.end(),\n\
    \        [](const auto &a, const auto &b) { return a.x < b.x or (a.x == b.x and\
    \ a.y < b.y); });\n\n    if (upper) std::reverse(pts.begin(), pts.end());\n\n\
    \    std::vector<point<T>> ret;\n\n    ret.push_back(pts.back());\n    pts.pop_back();\n\
    \n    while (not pts.empty()) {\n      const auto s = pts.back();\n      pts.pop_back();\n\
    \n      if (ret.size() == 1) {\n        ret.push_back(s);\n      } else {\n  \
    \      const auto p = *(ret.end() - 2);\n        const auto q = ret.back();\n\n\
    \        if (cross(q - p, s - p) <= 0) {\n          ret.push_back(s);\n      \
    \  } else {\n          ret.pop_back();\n          pts.push_back(s);\n        }\n\
    \      }\n    }\n\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<point<T>>\
    \ convex_hull(const polygon<T> &pts) {\n    auto ret   = upper_hull(pts);\n  \
    \  auto lower = upper_hull(pts, false);\n\n    ret.pop_back();\n    lower.pop_back();\n\
    \n    for (auto &p : lower) ret.push_back(p);\n\n    return ret;\n  }\n}  // namespace\
    \ haar_lib\n"
  dependsOn:
  - Mylib/Geometry/Float/geometry_template.cpp
  isVerificationFile: false
  path: Mylib/Geometry/Float/convex_hull.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_4_A/main.test.cpp
documentation_of: Mylib/Geometry/Float/convex_hull.cpp
layout: document
title: Convex hull
---

## Operations

## Requirements

## Notes

## Problems

- [AOJ 0342 Road Planning](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0342) (凸包/最小全域木)
- [AGC 021 B - Holes](https://atcoder.jp/contests/agc021/tasks/agc021_b) (凸包)
- [Codeforces Round #549 (Div. 2) F. U2](https://codeforces.com/contest/1143/problem/F) (式変形/上側凸包)

## References

