---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Geometry/Float/circumscribed_circle_of_triangle.cpp
    title: Circumscribed circle of a triangle
  - icon: ':question:'
    path: Mylib/Geometry/Float/geometry_template.cpp
    title: Geometry template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3034/main.test.cpp
    title: test/aoj/3034/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Geometry/Float/minimum_covering_circle.cpp\"\n#include\
    \ <vector>\n#include <random>\n#include <algorithm>\n#line 2 \"Mylib/Geometry/Float/geometry_template.cpp\"\
    \n#include <iostream>\n#include <cmath>\n#line 5 \"Mylib/Geometry/Float/geometry_template.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct vec {\n    T x, y;\n\
    \    vec(){}\n    vec(T x, T y): x(x), y(y){}\n\n    friend auto operator+(const\
    \ vec &a, const vec &b){return vec(a.x + b.x, a.y + b.y);}\n    friend auto operator-(const\
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
    \ \"radius: \" << a.radius << \")\";\n    return s;\n  }\n}\n#line 3 \"Mylib/Geometry/Float/circumscribed_circle_of_triangle.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  circle<T> circumscribed_circle_of_triangle(const\
    \ point<T> &a, const point<T> &b, const point<T> &c){\n    const T A = abs_sq(b\
    \ - c), B = abs_sq(a - c), C = abs_sq(a - b), S = A + B + C;\n    const T AA =\
    \ A * (S - A * 2.0);\n    const T BB = B * (S - B * 2.0);\n    const T CC = C\
    \ * (S - C * 2.0);\n    const auto center = (AA * a + BB * b + CC * c) / (AA +\
    \ BB + CC);\n\n    return circle<T>(\n      center,\n      abs(center - a)\n \
    \   );\n  }\n}\n#line 6 \"Mylib/Geometry/Float/minimum_covering_circle.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename T>\n  circle<T> minimum_covering_circle(std::vector<point<T>>\
    \ ps, int seed = 0){\n    if(ps.empty()) return circle<T>();\n    if(ps.size()\
    \ == 1) return circle<T>(ps[0], 0);\n\n    const int N = ps.size();\n\n    std::mt19937\
    \ rand(seed);\n    std::shuffle(ps.begin(), ps.end(), rand);\n\n    auto make_circle_2\
    \ =\n      [&](const auto &p, const auto &q){\n        const auto c = (p + q)\
    \ / 2.0;\n        return circle<T>(c, abs(p - c));\n      };\n\n    auto check\
    \ =\n      [](const auto &p, const auto &c){\n        return abs(c.center - p)\
    \ <= c.radius;\n      };\n\n    circle<T> ret = make_circle_2(ps[0], ps[1]);\n\
    \n    for(int i = 2; i < N; ++i){\n      if(check(ps[i], ret)) continue;\n\n \
    \     ret = make_circle_2(ps[0], ps[i]);\n\n      for(int j = 1; j < i; ++j){\n\
    \        if(check(ps[j], ret)) continue;\n\n        ret = make_circle_2(ps[i],\
    \ ps[j]);\n\n        for(int k = 0; k < j; ++k){\n          if(check(ps[k], ret))\
    \ continue;\n          if(i == j or j == k or k == i) continue;\n\n          ret\
    \ = circumscribed_circle_of_triangle(ps[i], ps[j], ps[k]);\n        }\n      }\n\
    \    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <random>\n#include <algorithm>\n\
    #include \"Mylib/Geometry/Float/circumscribed_circle_of_triangle.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  circle<T> minimum_covering_circle(std::vector<point<T>>\
    \ ps, int seed = 0){\n    if(ps.empty()) return circle<T>();\n    if(ps.size()\
    \ == 1) return circle<T>(ps[0], 0);\n\n    const int N = ps.size();\n\n    std::mt19937\
    \ rand(seed);\n    std::shuffle(ps.begin(), ps.end(), rand);\n\n    auto make_circle_2\
    \ =\n      [&](const auto &p, const auto &q){\n        const auto c = (p + q)\
    \ / 2.0;\n        return circle<T>(c, abs(p - c));\n      };\n\n    auto check\
    \ =\n      [](const auto &p, const auto &c){\n        return abs(c.center - p)\
    \ <= c.radius;\n      };\n\n    circle<T> ret = make_circle_2(ps[0], ps[1]);\n\
    \n    for(int i = 2; i < N; ++i){\n      if(check(ps[i], ret)) continue;\n\n \
    \     ret = make_circle_2(ps[0], ps[i]);\n\n      for(int j = 1; j < i; ++j){\n\
    \        if(check(ps[j], ret)) continue;\n\n        ret = make_circle_2(ps[i],\
    \ ps[j]);\n\n        for(int k = 0; k < j; ++k){\n          if(check(ps[k], ret))\
    \ continue;\n          if(i == j or j == k or k == i) continue;\n\n          ret\
    \ = circumscribed_circle_of_triangle(ps[i], ps[j], ps[k]);\n        }\n      }\n\
    \    }\n\n    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/Geometry/Float/circumscribed_circle_of_triangle.cpp
  - Mylib/Geometry/Float/geometry_template.cpp
  isVerificationFile: false
  path: Mylib/Geometry/Float/minimum_covering_circle.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3034/main.test.cpp
documentation_of: Mylib/Geometry/Float/minimum_covering_circle.cpp
layout: document
title: Minimum covering circle
---

## Operations

- `minimum_covering_circle(ps, seed)`
  - 点集合`ps`を内包する最小の円を返す。

## Requirements

## Notes

## Problems

- [ABC 151 F - Enclose All](https://atcoder.jp/contests/abc151/tasks/abc151_f)
- [AOJ 3034 Explosion](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3034)

## References

- [https://tubo28.me/compprog/algorithm/minball/](https://tubo28.me/compprog/algorithm/minball/)
