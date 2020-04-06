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


# :heavy_check_mark: 幾何基本セット

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#090220fbd726178f7b9d402d3ae3f683">Mylib/Geometry/Float</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Geometry/Float/geometry_template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-04 13:11:51+09:00




## Required by

* :heavy_check_mark: <a href="area_intersection_of_circle_and_polygon.cpp.html">円と多角形の共通部分の面積</a>
* :warning: <a href="area_intersection_of_circles.cpp.html">2円の共通部分の面積</a>
* :heavy_check_mark: <a href="area_polygon.cpp.html">多角形の面積</a>
* :heavy_check_mark: <a href="ccw.cpp.html">clockwise-counterclockwise判定</a>
* :warning: <a href="circumscribed_circle_of_triangle.cpp.html">三角形の外接円</a>
* :heavy_check_mark: <a href="closest_pair.cpp.html">最近点対</a>
* :heavy_check_mark: <a href="common_tangent_of_circles.cpp.html">2円の共通接線</a>
* :heavy_check_mark: <a href="convex_cut.cpp.html">凸多角形の切断</a>
* :heavy_check_mark: <a href="convex_diameter.cpp.html">凸多角形の直径</a>
* :heavy_check_mark: <a href="convex_hull.cpp.html">凸包</a>
* :heavy_check_mark: <a href="distance_line_point.cpp.html">直線と点間の距離</a>
* :heavy_check_mark: <a href="distance_segment_point.cpp.html">線分・点間の距離</a>
* :heavy_check_mark: <a href="distance_segments.cpp.html">線分間の距離</a>
* :heavy_check_mark: <a href="intersect_circle_line.cpp.html">円と直線の交差</a>
* :heavy_check_mark: <a href="intersect_circle_segment.cpp.html">円と線分の交差</a>
* :heavy_check_mark: <a href="intersect_circles.cpp.html">円同士の交差</a>
* :heavy_check_mark: <a href="intersect_line_segment.cpp.html">直線と線分の交差</a>
* :heavy_check_mark: <a href="intersect_segments.cpp.html">線分同士の交差</a>
* :heavy_check_mark: <a href="is_convex.cpp.html">凸多角形判定</a>
* :heavy_check_mark: <a href="is_point_in_polygon.cpp.html">点・多角形の包含関係</a>
* :warning: <a href="minimum_covering_circle.cpp.html">最小包含円</a>
* :heavy_check_mark: <a href="orthogonal.cpp.html">直行判定</a>
* :heavy_check_mark: <a href="parallel.cpp.html">平行判定</a>
* :heavy_check_mark: <a href="projection.cpp.html">射影</a>
* :heavy_check_mark: <a href="reflection.cpp.html">反射</a>
* :heavy_check_mark: <a href="tangent_of_circle.cpp.html">円の接線</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/2136/main.test.cpp.html">test/aoj/2136/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_1_A/main.test.cpp.html">test/aoj/CGL_1_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_1_B/main.test.cpp.html">test/aoj/CGL_1_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_1_C/main.test.cpp.html">test/aoj/CGL_1_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_2_A/main.test.cpp.html">test/aoj/CGL_2_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_2_B/main.test.cpp.html">test/aoj/CGL_2_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_2_C/main.test.cpp.html">test/aoj/CGL_2_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_2_D/main.test.cpp.html">test/aoj/CGL_2_D/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_3_A/main.test.cpp.html">test/aoj/CGL_3_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_3_B/main.test.cpp.html">test/aoj/CGL_3_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_3_C/main.test.cpp.html">test/aoj/CGL_3_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_4_A/main.test.cpp.html">test/aoj/CGL_4_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_4_B/main.test.cpp.html">test/aoj/CGL_4_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_4_C/main.test.cpp.html">test/aoj/CGL_4_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_5_A/main.test.cpp.html">test/aoj/CGL_5_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_7_A/main.test.cpp.html">test/aoj/CGL_7_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_7_D/main.test.cpp.html">test/aoj/CGL_7_D/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_7_E/main.test.cpp.html">test/aoj/CGL_7_E/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_7_F/main.test.cpp.html">test/aoj/CGL_7_F/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_7_G/main.test.cpp.html">test/aoj/CGL_7_G/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_7_H/main.test.cpp.html">test/aoj/CGL_7_H/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>
#include <cmath>
#include <vector>

/**
 * @title 幾何基本セット
 */
template <typename T> struct Vec{
  using U = typename T::value_type;
  T x, y;
  Vec(): x(0), y(0){}
  Vec(const T &x, const T &y): x(x), y(y){}
  T size() const {return std::sqrt((U)(x*x+y*y));}
  T size_sq() const {return x*x+y*y;}
  
  static auto polar(const T &r, const T &ang){return Vec<T>(r * std::cos((U)ang), r * std::sin((U)ang));}

  friend auto operator+(const Vec &a, const Vec &b){return Vec(a.x+b.x, a.y+b.y);}
  friend auto operator-(const Vec &a, const Vec &b){return Vec(a.x-b.x, a.y-b.y);}
  friend auto operator-(const Vec &a){return Vec(-a.x, -a.y);}

  friend bool operator==(const Vec &a, const Vec &b){return a.x == b.x and a.y == b.y;}
  friend bool operator!=(const Vec &a, const Vec &b){return !(a==b);}
  friend bool operator<(const Vec &a, const Vec &b){return a.x < b.x or (a.x == b.x and a.y < b.y);}
  
  friend std::istream& operator>>(std::istream &s, Vec &a){
    s >> a.x >> a.y; return s;
  }

  friend T dot(const Vec &a, const Vec &b){
    return a.x*b.x+a.y*b.y;
  }

  friend  T cross(const Vec &a, const Vec &b){
    return a.x*b.y-a.y*b.x;
  }

  friend  T angle(const Vec &a, const Vec &b){ // 点aから点bへの角度
    return std::atan2((U)(b.y-a.y), (U)(b.x-a.x));
  }

  friend  auto unit(const Vec &a){ // 単位ベクトル
    return a / a.size();
  }
  
  friend  auto normal(const Vec &p){
    return Vec<T>(-p.y,p.x);
  }

  friend  T phase(const Vec &a){
    return std::atan2((U)a.y, (U)a.x);
  }
};

template <typename T, typename U> auto operator*(const Vec<T> &a, const U &k){return Vec<T>(a.x*k, a.y*k);}
template <typename T, typename U> auto operator*(const U &k, const Vec<T> &a){return Vec<T>(a.x*k, a.y*k);}
template <typename T, typename U> auto operator/(const Vec<T> &a, const U &k){return Vec<T>(a.x/k, a.y/k);}


template <typename T> using Point = Vec<T>;


template <typename T>
T angle_diff(const Vec<T> &a, const Vec<T> &b){
  T r = phase(b) - phase(a);

  if(r < -M_PI) return r + 2 * M_PI;
  else if(r > M_PI) return r - 2 * M_PI;
  return r;
}

template <typename T> struct Line{
  Point<T> from, to;
  Line(): from(), to(){}
  Line(const Point<T> &from, const Point<T> &to): from(from), to(to){}
  Vec<T> diff() const {return to-from;}
  T size() const {return diff().size();}
};

template <typename T> using Segment = Line<T>;
template <typename T> using Polygon = std::vector<Point<T>>;

template <typename T> struct Circle{
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
 * @title 幾何基本セット
 */
template <typename T> struct Vec{
  using U = typename T::value_type;
  T x, y;
  Vec(): x(0), y(0){}
  Vec(const T &x, const T &y): x(x), y(y){}
  T size() const {return std::sqrt((U)(x*x+y*y));}
  T size_sq() const {return x*x+y*y;}
  
  static auto polar(const T &r, const T &ang){return Vec<T>(r * std::cos((U)ang), r * std::sin((U)ang));}

  friend auto operator+(const Vec &a, const Vec &b){return Vec(a.x+b.x, a.y+b.y);}
  friend auto operator-(const Vec &a, const Vec &b){return Vec(a.x-b.x, a.y-b.y);}
  friend auto operator-(const Vec &a){return Vec(-a.x, -a.y);}

  friend bool operator==(const Vec &a, const Vec &b){return a.x == b.x and a.y == b.y;}
  friend bool operator!=(const Vec &a, const Vec &b){return !(a==b);}
  friend bool operator<(const Vec &a, const Vec &b){return a.x < b.x or (a.x == b.x and a.y < b.y);}
  
  friend std::istream& operator>>(std::istream &s, Vec &a){
    s >> a.x >> a.y; return s;
  }

  friend T dot(const Vec &a, const Vec &b){
    return a.x*b.x+a.y*b.y;
  }

  friend  T cross(const Vec &a, const Vec &b){
    return a.x*b.y-a.y*b.x;
  }

  friend  T angle(const Vec &a, const Vec &b){ // 点aから点bへの角度
    return std::atan2((U)(b.y-a.y), (U)(b.x-a.x));
  }

  friend  auto unit(const Vec &a){ // 単位ベクトル
    return a / a.size();
  }
  
  friend  auto normal(const Vec &p){
    return Vec<T>(-p.y,p.x);
  }

  friend  T phase(const Vec &a){
    return std::atan2((U)a.y, (U)a.x);
  }
};

template <typename T, typename U> auto operator*(const Vec<T> &a, const U &k){return Vec<T>(a.x*k, a.y*k);}
template <typename T, typename U> auto operator*(const U &k, const Vec<T> &a){return Vec<T>(a.x*k, a.y*k);}
template <typename T, typename U> auto operator/(const Vec<T> &a, const U &k){return Vec<T>(a.x/k, a.y/k);}


template <typename T> using Point = Vec<T>;


template <typename T>
T angle_diff(const Vec<T> &a, const Vec<T> &b){
  T r = phase(b) - phase(a);

  if(r < -M_PI) return r + 2 * M_PI;
  else if(r > M_PI) return r - 2 * M_PI;
  return r;
}

template <typename T> struct Line{
  Point<T> from, to;
  Line(): from(), to(){}
  Line(const Point<T> &from, const Point<T> &to): from(from), to(to){}
  Vec<T> diff() const {return to-from;}
  T size() const {return diff().size();}
};

template <typename T> using Segment = Line<T>;
template <typename T> using Polygon = std::vector<Point<T>>;

template <typename T> struct Circle{
  Point<T> center;
  T radius;
  Circle(): center(), radius(0){}
  Circle(const Point<T> &center, T radius): center(center), radius(radius){}
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

