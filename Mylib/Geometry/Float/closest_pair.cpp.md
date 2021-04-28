---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Geometry/Float/geometry_template.cpp
    title: Geometry template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/CGL_5_A/main.test.cpp
    title: test/aoj/CGL_5_A/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Geometry/Float/closest_pair.cpp\"\n#include <algorithm>\n\
    #include <cmath>\n#include <limits>\n#include <utility>\n#include <vector>\n#line\
    \ 3 \"Mylib/Geometry/Float/geometry_template.cpp\"\n#include <iostream>\n#line\
    \ 5 \"Mylib/Geometry/Float/geometry_template.cpp\"\n\nnamespace haar_lib {\n \
    \ template <typename T>\n  struct vec {\n    T x, y;\n    vec() {}\n    vec(T\
    \ x, T y) : x(x), y(y) {}\n\n    friend auto operator+(const vec &a, const vec\
    \ &b) { return vec(a.x + b.x, a.y + b.y); }\n    friend auto operator-(const vec\
    \ &a, const vec &b) { return vec(a.x - b.x, a.y - b.y); }\n    friend auto operator-(const\
    \ vec &a) { return vec(-a.x, -a.y); }\n\n    friend bool operator==(const vec\
    \ &a, const vec &b) { return a.x == b.x and a.y == b.y; }\n    friend bool operator!=(const\
    \ vec &a, const vec &b) { return !(a == b); }\n    friend bool operator<(const\
    \ vec &a, const vec &b) { return a.x < b.x or (a.x == b.x and a.y < b.y); }\n\n\
    \    friend std::istream &operator>>(std::istream &s, vec &a) {\n      s >> a.x\
    \ >> a.y;\n      return s;\n    }\n  };\n\n  template <typename T, typename U>\n\
    \  auto operator*(const vec<T> &a, const U &k) { return vec<T>(a.x * k, a.y *\
    \ k); }\n  template <typename T, typename U>\n  auto operator*(const U &k, const\
    \ vec<T> &a) { return vec<T>(a.x * k, a.y * k); }\n  template <typename T, typename\
    \ U>\n  auto operator/(const vec<T> &a, const U &k) { return vec<T>(a.x / k, a.y\
    \ / k); }\n\n  template <typename T>\n  using point = vec<T>;\n\n  template <typename\
    \ T>\n  T abs(const vec<T> &a) { return sqrt(a.x * a.x + a.y * a.y); }\n  template\
    \ <typename T>\n  T abs_sq(const vec<T> &a) { return a.x * a.x + a.y * a.y; }\n\
    \n  template <typename T>\n  T dot(const vec<T> &a, const vec<T> &b) { return\
    \ a.x * b.x + a.y * b.y; }\n  template <typename T>\n  T cross(const vec<T> &a,\
    \ const vec<T> &b) { return a.x * b.y - a.y * b.x; }\n\n  template <typename T>\n\
    \  auto unit(const vec<T> &a) { return a / abs(a); }\n  template <typename T>\n\
    \  auto normal(const vec<T> &p) { return vec<T>(-p.y, p.x); }\n\n  template <typename\
    \ T>\n  auto polar(const T &r, const T &ang) { return vec<T>(r * cos(ang), r *\
    \ sin(ang)); }\n\n  template <typename T>\n  T angle(const vec<T> &a, const vec<T>\
    \ &b) { return atan2(b.y - a.y, b.x - a.x); }\n  template <typename T>\n  T phase(const\
    \ vec<T> &a) { return atan2(a.y, a.x); }\n\n  template <typename T>\n  T angle_diff(const\
    \ vec<T> &a, const vec<T> &b) {\n    T r = phase(b) - phase(a);\n\n    if (r <\
    \ -M_PI)\n      return r + 2 * M_PI;\n    else if (r > M_PI)\n      return r -\
    \ 2 * M_PI;\n    return r;\n  }\n\n  template <typename T>\n  struct line {\n\
    \    point<T> from, to;\n    line() : from(), to() {}\n    line(const point<T>\
    \ &from, const point<T> &to) : from(from), to(to) {}\n  };\n\n  template <typename\
    \ T>\n  using segment = line<T>;\n\n  template <typename T>\n  auto unit(const\
    \ line<T> &a) { return unit(a.to - a.from); }\n  template <typename T>\n  auto\
    \ normal(const line<T> &a) { return normal(a.to - a.from); }\n\n  template <typename\
    \ T>\n  auto diff(const segment<T> &a) { return a.to - a.from; }\n\n  template\
    \ <typename T>\n  T abs(const segment<T> &a) { return abs(diff(a)); }\n\n  template\
    \ <typename T>\n  T dot(const line<T> &a, const line<T> &b) { return dot(diff(a),\
    \ diff(b)); }\n  template <typename T>\n  T cross(const line<T> &a, const line<T>\
    \ &b) { return cross(diff(a), diff(b)); }\n\n  template <typename T>\n  using\
    \ polygon = std::vector<point<T>>;\n\n  template <typename T>\n  struct circle\
    \ {\n    point<T> center;\n    T radius;\n    circle() : center(), radius(0) {}\n\
    \    circle(const point<T> &center, T radius) : center(center), radius(radius)\
    \ {}\n  };\n\n  template <typename T>\n  std::ostream &operator<<(std::ostream\
    \ &s, const vec<T> &a) {\n    s << \"(\" << a.x << \", \" << a.y << \")\";\n \
    \   return s;\n  }\n\n  template <typename T>\n  std::ostream &operator<<(std::ostream\
    \ &s, const line<T> &a) {\n    s << \"(\" << a.from << \" -> \" << a.to << \"\
    )\";\n    return s;\n  }\n\n  template <typename T>\n  std::ostream &operator<<(std::ostream\
    \ &s, const circle<T> &a) {\n    s << \"(\"\n      << \"center: \" << a.center\
    \ << \", \"\n      << \"radius: \" << a.radius << \")\";\n    return s;\n  }\n\
    }  // namespace haar_lib\n#line 8 \"Mylib/Geometry/Float/closest_pair.cpp\"\n\n\
    namespace haar_lib {\n  namespace closest_pair_impl {\n    template <typename\
    \ T>\n    T rec(std::vector<point<T>> &s) {\n      const int N = s.size();\n\n\
    \      if (N == 1) return std::numeric_limits<T>::infinity();\n\n      if (N ==\
    \ 2) {\n        if (s[0].y > s[1].y) std::swap(s[0], s[1]);\n        return abs(s[0]\
    \ - s[1]);\n      }\n\n      const T mid_x = s[N / 2].x;\n\n      auto left  =\
    \ std::vector<point<T>>(s.begin(), s.begin() + N / 2);\n      auto right = std::vector<point<T>>(s.begin()\
    \ + N / 2, s.end());\n\n      const T d1 = rec(left);\n      const T d2 = rec(right);\n\
    \n      T d = std::min(d1, d2);\n\n      s.clear();\n\n      std::merge(\n   \
    \       left.begin(), left.end(),\n          right.begin(), right.end(),\n   \
    \       std::back_inserter(s),\n          [](const auto &a, const auto &b) { return\
    \ a.y < b.y; });\n\n      std::vector<point<T>> v;\n\n      for (const auto &p\
    \ : s) {\n        if (abs(p.x - mid_x) > d) continue;\n\n        for (auto it\
    \ = v.rbegin(); it != v.rend(); ++it) {\n          const auto &q = *it;\n    \
    \      if (abs(p.y - q.y) > d) break;\n\n          d = std::min(d, abs(p - q));\n\
    \        }\n\n        v.push_back(p);\n      }\n\n      return d;\n    }\n  }\
    \  // namespace closest_pair_impl\n\n  template <typename T>\n  T closest_pair(std::vector<point<T>>\
    \ s) {\n    std::sort(s.begin(), s.end(), [](const auto &a, const auto &b) { return\
    \ a.x < b.x; });\n    return closest_pair_impl::rec(s);\n  }\n}  // namespace\
    \ haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <cmath>\n#include <limits>\n\
    #include <utility>\n#include <vector>\n#include \"Mylib/Geometry/Float/geometry_template.cpp\"\
    \n\nnamespace haar_lib {\n  namespace closest_pair_impl {\n    template <typename\
    \ T>\n    T rec(std::vector<point<T>> &s) {\n      const int N = s.size();\n\n\
    \      if (N == 1) return std::numeric_limits<T>::infinity();\n\n      if (N ==\
    \ 2) {\n        if (s[0].y > s[1].y) std::swap(s[0], s[1]);\n        return abs(s[0]\
    \ - s[1]);\n      }\n\n      const T mid_x = s[N / 2].x;\n\n      auto left  =\
    \ std::vector<point<T>>(s.begin(), s.begin() + N / 2);\n      auto right = std::vector<point<T>>(s.begin()\
    \ + N / 2, s.end());\n\n      const T d1 = rec(left);\n      const T d2 = rec(right);\n\
    \n      T d = std::min(d1, d2);\n\n      s.clear();\n\n      std::merge(\n   \
    \       left.begin(), left.end(),\n          right.begin(), right.end(),\n   \
    \       std::back_inserter(s),\n          [](const auto &a, const auto &b) { return\
    \ a.y < b.y; });\n\n      std::vector<point<T>> v;\n\n      for (const auto &p\
    \ : s) {\n        if (abs(p.x - mid_x) > d) continue;\n\n        for (auto it\
    \ = v.rbegin(); it != v.rend(); ++it) {\n          const auto &q = *it;\n    \
    \      if (abs(p.y - q.y) > d) break;\n\n          d = std::min(d, abs(p - q));\n\
    \        }\n\n        v.push_back(p);\n      }\n\n      return d;\n    }\n  }\
    \  // namespace closest_pair_impl\n\n  template <typename T>\n  T closest_pair(std::vector<point<T>>\
    \ s) {\n    std::sort(s.begin(), s.end(), [](const auto &a, const auto &b) { return\
    \ a.x < b.x; });\n    return closest_pair_impl::rec(s);\n  }\n}  // namespace\
    \ haar_lib\n"
  dependsOn:
  - Mylib/Geometry/Float/geometry_template.cpp
  isVerificationFile: false
  path: Mylib/Geometry/Float/closest_pair.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/CGL_5_A/main.test.cpp
documentation_of: Mylib/Geometry/Float/closest_pair.cpp
layout: document
title: Closest pair
---

## Operations

## Requirements

## Notes

## Problems

## References
