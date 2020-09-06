---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :x: Geometry template

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#090220fbd726178f7b9d402d3ae3f683">Mylib/Geometry/Float</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Geometry/Float/geometry_template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Required by

* :x: <a href="area_intersection_of_circle_and_polygon.cpp.html">Area of intersection between a circle and a polygon</a>
* :x: <a href="area_intersection_of_circles.cpp.html">Area of intersection between two circles</a>
* :x: <a href="area_polygon.cpp.html">Area of polygon</a>
* :x: <a href="ccw.cpp.html">Check clockwise-counterclockwise</a>
* :x: <a href="circumscribed_circle_of_triangle.cpp.html">Circumscribed circle of a triangle</a>
* :x: <a href="closest_pair.cpp.html">Closest pair</a>
* :x: <a href="common_tangent_of_circles.cpp.html">Common tangents of two circles</a>
* :x: <a href="convex_cut.cpp.html">Convex cut</a>
* :x: <a href="convex_diameter.cpp.html">Convex diameter</a>
* :x: <a href="convex_hull.cpp.html">Convex hull</a>
* :x: <a href="distance_line_point.cpp.html">Distance between a line and a point</a>
* :x: <a href="distance_segment_point.cpp.html">Distance between a segment and a point</a>
* :x: <a href="distance_segments.cpp.html">Distance between two segments</a>
* :x: <a href="inscribed_circle_of_triangle.cpp.html">Inscribed circle of a triangle</a>
* :x: <a href="intersect_circle_line.cpp.html">Intersection between a circle and a line</a>
* :x: <a href="intersect_circle_segment.cpp.html">Intersection between a circle and a segment</a>
* :x: <a href="intersect_circles.cpp.html">Intersection between two circles</a>
* :x: <a href="intersect_line_segment.cpp.html">Intersection between a line and a segment</a>
* :x: <a href="intersect_segments.cpp.html">Intersection between two lines</a>
* :x: <a href="is_convex.cpp.html">Check convex</a>
* :x: <a href="is_point_in_polygon.cpp.html">Check if a point is in a polygon</a>
* :x: <a href="minimum_covering_circle.cpp.html">Minimum covering circle</a>
* :x: <a href="orthogonal.cpp.html">Orthogonal</a>
* :x: <a href="parallel.cpp.html">Parallel</a>
* :x: <a href="projection.cpp.html">Projection</a>
* :x: <a href="reflection.cpp.html">Reflection</a>
* :x: <a href="tangent_of_circle.cpp.html">Tangent of circle</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/2136/main.test.cpp.html">test/aoj/2136/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/3034/main.test.cpp.html">test/aoj/3034/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_1_A/main.test.cpp.html">test/aoj/CGL_1_A/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_1_B/main.test.cpp.html">test/aoj/CGL_1_B/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_1_C/main.test.cpp.html">test/aoj/CGL_1_C/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_2_A/main.test.cpp.html">test/aoj/CGL_2_A/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_2_B/main.test.cpp.html">test/aoj/CGL_2_B/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_2_C/main.test.cpp.html">test/aoj/CGL_2_C/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_2_D/main.test.cpp.html">test/aoj/CGL_2_D/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_3_A/main.test.cpp.html">test/aoj/CGL_3_A/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_3_B/main.test.cpp.html">test/aoj/CGL_3_B/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_3_C/main.test.cpp.html">test/aoj/CGL_3_C/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_4_A/main.test.cpp.html">test/aoj/CGL_4_A/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_4_B/main.test.cpp.html">test/aoj/CGL_4_B/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_4_C/main.test.cpp.html">test/aoj/CGL_4_C/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_5_A/main.test.cpp.html">test/aoj/CGL_5_A/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_7_A/main.test.cpp.html">test/aoj/CGL_7_A/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_7_B/main.test.cpp.html">test/aoj/CGL_7_B/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_7_C/main.test.cpp.html">test/aoj/CGL_7_C/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_7_D/main.test.cpp.html">test/aoj/CGL_7_D/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_7_E/main.test.cpp.html">test/aoj/CGL_7_E/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_7_F/main.test.cpp.html">test/aoj/CGL_7_F/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_7_G/main.test.cpp.html">test/aoj/CGL_7_G/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_7_H/main.test.cpp.html">test/aoj/CGL_7_H/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_7_I/main.test.cpp.html">test/aoj/CGL_7_I/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>
#include <cmath>
#include <vector>

/**
 * @title Geometry template
 * @docs geometry_template.md
 */

template <typename T>
struct Vec {
  T x, y;
  Vec(){}
  Vec(T x, T y): x(x), y(y){}

  friend auto operator+(const Vec &a, const Vec &b){return Vec(a.x + b.x, a.y + b.y);}
  friend auto operator-(const Vec &a, const Vec &b){return Vec(a.x - b.x, a.y - b.y);}
  friend auto operator-(const Vec &a){return Vec(-a.x, -a.y);}

  friend bool operator==(const Vec &a, const Vec &b){return a.x == b.x and a.y == b.y;}
  friend bool operator!=(const Vec &a, const Vec &b){return !(a == b);}
  friend bool operator<(const Vec &a, const Vec &b){return a.x < b.x or (a.x == b.x and a.y < b.y);}

  friend std::istream& operator>>(std::istream &s, Vec &a){
    s >> a.x  >> a.y; return s;
  }
};

template <typename T, typename U> auto operator*(const Vec<T> &a, const U &k){return Vec<T>(a.x * k, a.y * k);}
template <typename T, typename U> auto operator*(const U &k, const Vec<T> &a){return Vec<T>(a.x * k, a.y * k);}
template <typename T, typename U> auto operator/(const Vec<T> &a, const U &k){return Vec<T>(a.x / k, a.y / k);}

template <typename T> using Point = Vec<T>;

template <typename T> T abs(const Vec<T> &a){return sqrt(a.x * a.x + a.y * a.y);}
template <typename T> T abs_sq(const Vec<T> &a){return a.x * a.x + a.y * a.y;}

template <typename T> T dot(const Vec<T> &a, const Vec<T> &b){return a.x * b.x + a.y * b.y;}
template <typename T> T cross(const Vec<T> &a, const Vec<T> &b){return a.x * b.y - a.y * b.x;}

template <typename T> auto unit(const Vec<T> &a){return a / abs(a);}
template <typename T> auto normal(const Vec<T> &p){return Vec<T>(-p.y, p.x);}

template <typename T> auto polar(const T &r, const T &ang){return Vec<T>(r * cos(ang), r * sin(ang));}

template <typename T> T angle(const Vec<T> &a, const Vec<T> &b){return atan2(b.y - a.y, b.x - a.x);}
template <typename T> T phase(const Vec<T> &a){return atan2(a.y, a.x);}

template <typename T>
T angle_diff(const Vec<T> &a, const Vec<T> &b){
  T r = phase(b) - phase(a);

  if(r < -M_PI) return r + 2 * M_PI;
  else if(r > M_PI) return r - 2 * M_PI;
  return r;
}


template <typename T> struct Line {
  Point<T> from, to;
  Line(): from(), to(){}
  Line(const Point<T> &from, const Point<T> &to): from(from), to(to){}
};

template <typename T> using Segment = Line<T>;


template <typename T> auto unit(const Line<T> &a){return unit(a.to - a.from);}
template <typename T> auto normal(const Line<T> &a){return normal(a.to - a.from);}

template <typename T> auto diff(const Segment<T> &a){return a.to - a.from;}

template <typename T> T abs(const Segment<T> &a){return abs(diff(a));}

template <typename T> T dot(const Line<T> &a, const Line<T> &b){return dot(diff(a), diff(b));}
template <typename T> T cross(const Line<T> &a, const Line<T> &b){return cross(diff(a), diff(b));}


template <typename T> using Polygon = std::vector<Point<T>>;

template <typename T> struct Circle {
  Point<T> center;
  T radius;
  Circle(): center(), radius(0){}
  Circle(const Point<T> &center, T radius): center(center), radius(radius){}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Geometry/Float/geometry_template.cpp"
#include <iostream>
#include <cmath>
#include <vector>

/**
 * @title Geometry template
 * @docs geometry_template.md
 */

template <typename T>
struct Vec {
  T x, y;
  Vec(){}
  Vec(T x, T y): x(x), y(y){}

  friend auto operator+(const Vec &a, const Vec &b){return Vec(a.x + b.x, a.y + b.y);}
  friend auto operator-(const Vec &a, const Vec &b){return Vec(a.x - b.x, a.y - b.y);}
  friend auto operator-(const Vec &a){return Vec(-a.x, -a.y);}

  friend bool operator==(const Vec &a, const Vec &b){return a.x == b.x and a.y == b.y;}
  friend bool operator!=(const Vec &a, const Vec &b){return !(a == b);}
  friend bool operator<(const Vec &a, const Vec &b){return a.x < b.x or (a.x == b.x and a.y < b.y);}

  friend std::istream& operator>>(std::istream &s, Vec &a){
    s >> a.x  >> a.y; return s;
  }
};

template <typename T, typename U> auto operator*(const Vec<T> &a, const U &k){return Vec<T>(a.x * k, a.y * k);}
template <typename T, typename U> auto operator*(const U &k, const Vec<T> &a){return Vec<T>(a.x * k, a.y * k);}
template <typename T, typename U> auto operator/(const Vec<T> &a, const U &k){return Vec<T>(a.x / k, a.y / k);}

template <typename T> using Point = Vec<T>;

template <typename T> T abs(const Vec<T> &a){return sqrt(a.x * a.x + a.y * a.y);}
template <typename T> T abs_sq(const Vec<T> &a){return a.x * a.x + a.y * a.y;}

template <typename T> T dot(const Vec<T> &a, const Vec<T> &b){return a.x * b.x + a.y * b.y;}
template <typename T> T cross(const Vec<T> &a, const Vec<T> &b){return a.x * b.y - a.y * b.x;}

template <typename T> auto unit(const Vec<T> &a){return a / abs(a);}
template <typename T> auto normal(const Vec<T> &p){return Vec<T>(-p.y, p.x);}

template <typename T> auto polar(const T &r, const T &ang){return Vec<T>(r * cos(ang), r * sin(ang));}

template <typename T> T angle(const Vec<T> &a, const Vec<T> &b){return atan2(b.y - a.y, b.x - a.x);}
template <typename T> T phase(const Vec<T> &a){return atan2(a.y, a.x);}

template <typename T>
T angle_diff(const Vec<T> &a, const Vec<T> &b){
  T r = phase(b) - phase(a);

  if(r < -M_PI) return r + 2 * M_PI;
  else if(r > M_PI) return r - 2 * M_PI;
  return r;
}


template <typename T> struct Line {
  Point<T> from, to;
  Line(): from(), to(){}
  Line(const Point<T> &from, const Point<T> &to): from(from), to(to){}
};

template <typename T> using Segment = Line<T>;


template <typename T> auto unit(const Line<T> &a){return unit(a.to - a.from);}
template <typename T> auto normal(const Line<T> &a){return normal(a.to - a.from);}

template <typename T> auto diff(const Segment<T> &a){return a.to - a.from;}

template <typename T> T abs(const Segment<T> &a){return abs(diff(a));}

template <typename T> T dot(const Line<T> &a, const Line<T> &b){return dot(diff(a), diff(b));}
template <typename T> T cross(const Line<T> &a, const Line<T> &b){return cross(diff(a), diff(b));}


template <typename T> using Polygon = std::vector<Point<T>>;

template <typename T> struct Circle {
  Point<T> center;
  T radius;
  Circle(): center(), radius(0){}
  Circle(const Point<T> &center, T radius): center(center), radius(radius){}
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

