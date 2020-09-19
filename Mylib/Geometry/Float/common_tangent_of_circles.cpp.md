---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Geometry/Float/geometry_template.cpp
    title: Geometry template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/CGL_7_G/main.test.cpp
    title: test/aoj/CGL_7_G/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Geometry/Float/common_tangent_of_circles.cpp\"\n#include\
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
    \ \"radius: \" << a.radius << \")\";\n    return s;\n  }\n}\n#line 4 \"Mylib/Geometry/Float/common_tangent_of_circles.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<point<T>> common_tangent_of_circles(const\
    \ circle<T> &a, const circle<T> &b){\n    const T d = abs(b.center - a.center);\n\
    \    const auto n = unit(b.center - a.center);\n\n    const auto cc = b.center\
    \ - a.center;\n    const T r = a.radius - b.radius;\n    const T R = a.radius\
    \ + b.radius;\n\n    if(a.radius + b.radius == d){ // \u4E00\u65B9\u304C\u4ED6\
    \u65B9\u306B\u5916\u63A5\u3057\u3066\u3044\u308B\u3002\n      return {\n     \
    \         a.center + (cc * r + normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius\
    \ / abs_sq(cc),\n              a.center + (cc * r - normal(cc) * sqrt(abs_sq(cc)\
    \ - r * r)) * a.radius / abs_sq(cc),\n              a.center + n * a.radius\n\
    \      };\n    }else if(a.radius + b.radius < d){ // a\u3068b\u306F\u4E92\u3044\
    \u306B\u96E2\u308C\u3066\u3044\u308B\u3002\n      return {\n              a.center\
    \ + (cc * r + normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),\n\
    \              a.center + (cc * r - normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius\
    \ / abs_sq(cc),\n              a.center + (cc * R + normal(cc) * sqrt(abs_sq(cc)\
    \ - R * R)) * a.radius / abs_sq(cc),\n              a.center + (cc * R - normal(cc)\
    \ * sqrt(abs_sq(cc) - R * R)) * a.radius / abs_sq(cc)\n      };\n    }else if(a.radius\
    \ + b.radius > d and d > abs(a.radius - b.radius)){ // a\u3068b\u306F\u4E8C\u70B9\
    \u3067\u4EA4\u5DEE\u3057\u3066\u3044\u308B\u3002\n      return {\n           \
    \   a.center + (cc * r + normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),\n\
    \              a.center + (cc * r - normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius\
    \ / abs_sq(cc)\n      };\n    }else if(abs(a.radius - b.radius) == d){ // \u4E00\
    \u65B9\u304C\u4ED6\u65B9\u306B\u5185\u63A5\u3057\u3066\u3044\u308B\u3002\n   \
    \   return {\n              a.radius > b.radius ? a.center + n * a.radius : b.center\
    \ - n * b.radius\n      };\n    }\n\n    return {};\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"Mylib/Geometry/Float/geometry_template.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<point<T>> common_tangent_of_circles(const\
    \ circle<T> &a, const circle<T> &b){\n    const T d = abs(b.center - a.center);\n\
    \    const auto n = unit(b.center - a.center);\n\n    const auto cc = b.center\
    \ - a.center;\n    const T r = a.radius - b.radius;\n    const T R = a.radius\
    \ + b.radius;\n\n    if(a.radius + b.radius == d){ // \u4E00\u65B9\u304C\u4ED6\
    \u65B9\u306B\u5916\u63A5\u3057\u3066\u3044\u308B\u3002\n      return {\n     \
    \         a.center + (cc * r + normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius\
    \ / abs_sq(cc),\n              a.center + (cc * r - normal(cc) * sqrt(abs_sq(cc)\
    \ - r * r)) * a.radius / abs_sq(cc),\n              a.center + n * a.radius\n\
    \      };\n    }else if(a.radius + b.radius < d){ // a\u3068b\u306F\u4E92\u3044\
    \u306B\u96E2\u308C\u3066\u3044\u308B\u3002\n      return {\n              a.center\
    \ + (cc * r + normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),\n\
    \              a.center + (cc * r - normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius\
    \ / abs_sq(cc),\n              a.center + (cc * R + normal(cc) * sqrt(abs_sq(cc)\
    \ - R * R)) * a.radius / abs_sq(cc),\n              a.center + (cc * R - normal(cc)\
    \ * sqrt(abs_sq(cc) - R * R)) * a.radius / abs_sq(cc)\n      };\n    }else if(a.radius\
    \ + b.radius > d and d > abs(a.radius - b.radius)){ // a\u3068b\u306F\u4E8C\u70B9\
    \u3067\u4EA4\u5DEE\u3057\u3066\u3044\u308B\u3002\n      return {\n           \
    \   a.center + (cc * r + normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),\n\
    \              a.center + (cc * r - normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius\
    \ / abs_sq(cc)\n      };\n    }else if(abs(a.radius - b.radius) == d){ // \u4E00\
    \u65B9\u304C\u4ED6\u65B9\u306B\u5185\u63A5\u3057\u3066\u3044\u308B\u3002\n   \
    \   return {\n              a.radius > b.radius ? a.center + n * a.radius : b.center\
    \ - n * b.radius\n      };\n    }\n\n    return {};\n  }\n}\n"
  dependsOn:
  - Mylib/Geometry/Float/geometry_template.cpp
  isVerificationFile: false
  path: Mylib/Geometry/Float/common_tangent_of_circles.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/CGL_7_G/main.test.cpp
documentation_of: Mylib/Geometry/Float/common_tangent_of_circles.cpp
layout: document
title: Common tangents of two circles
---

## Operations

## Requirements

## Notes

## Problems

## References
