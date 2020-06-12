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


# :heavy_check_mark: Common tangents of two circles

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#090220fbd726178f7b9d402d3ae3f683">Mylib/Geometry/Float</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Geometry/Float/common_tangent_of_circles.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Depends on

* :heavy_check_mark: <a href="geometry_template.cpp.html">Geometry template</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_7_G/main.test.cpp.html">test/aoj/CGL_7_G/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title Common tangents of two circles
 * @docs common_tangent_of_circles.md
 */
template <typename T>
std::vector<Point<T>> common_tangent_of_circles(const Circle<T> &a, const Circle<T> &b){
  const T d = abs(b.center - a.center);
  const auto n = unit(b.center - a.center);

  const auto cc = b.center - a.center;
  const T r = a.radius - b.radius;
  const T R = a.radius + b.radius;
  
  if(a.radius + b.radius == d){ // 一方が他方に外接している。
    return {
            a.center + (cc * r + normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),
            a.center + (cc * r - normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),
            a.center + n * a.radius
    };
  }else if(a.radius + b.radius < d){ // aとbは互いに離れている。
    return {
            a.center + (cc * r + normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),
            a.center + (cc * r - normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),
            a.center + (cc * R + normal(cc) * sqrt(abs_sq(cc) - R * R)) * a.radius / abs_sq(cc),
            a.center + (cc * R - normal(cc) * sqrt(abs_sq(cc) - R * R)) * a.radius / abs_sq(cc)
    };
  }else if(a.radius + b.radius > d and d > abs(a.radius - b.radius)){ // aとbは二点で交差している。
    return {
            a.center + (cc * r + normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),
            a.center + (cc * r - normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc)
    };
  }else if(abs(a.radius - b.radius) == d){ // 一方が他方に内接している。
    return {
            a.radius > b.radius ? a.center + n * a.radius : b.center - n * b.radius
    };
  }

  return {};
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Geometry/Float/common_tangent_of_circles.cpp"
#include <vector>
#line 2 "Mylib/Geometry/Float/geometry_template.cpp"
#include <iostream>
#include <cmath>
#line 5 "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title Geometry template
 * @docs geometry_template.md
 */

template <typename T>
struct Vec{
  T x, y;
  Vec(){}
  Vec(T x, T y): x(x), y(y){}

  friend auto operator+(const Vec &a, const Vec &b){return Vec(a.x + b.x, a.y + b.y);}
  friend auto operator-(const Vec &a, const Vec &b){return Vec(a.x - b.x, a.y - b.y);}
  friend auto operator-(const Vec &a){return Vec(-a.x, -a.y);}

  friend bool operator==(const Vec &a, const Vec &b){return a.x == b.x and a.y == b.y;}
  friend bool operator!=(const Vec &a, const Vec &b){return !(a==b);}
  friend bool operator<(const Vec &a, const Vec &b){return a.x < b.x or (a.x == b.x and a.y < b.y);}
  
  friend std::istream& operator>>(std::istream &s, Vec &a){
    s >> a.x >> a.y; return s;
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


template <typename T> struct Line{
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

template <typename T> struct Circle{
  Point<T> center;
  T radius;
  Circle(): center(), radius(0){}
  Circle(const Point<T> &center, T radius): center(center), radius(radius){}
};
#line 4 "Mylib/Geometry/Float/common_tangent_of_circles.cpp"

/**
 * @title Common tangents of two circles
 * @docs common_tangent_of_circles.md
 */
template <typename T>
std::vector<Point<T>> common_tangent_of_circles(const Circle<T> &a, const Circle<T> &b){
  const T d = abs(b.center - a.center);
  const auto n = unit(b.center - a.center);

  const auto cc = b.center - a.center;
  const T r = a.radius - b.radius;
  const T R = a.radius + b.radius;
  
  if(a.radius + b.radius == d){ // 一方が他方に外接している。
    return {
            a.center + (cc * r + normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),
            a.center + (cc * r - normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),
            a.center + n * a.radius
    };
  }else if(a.radius + b.radius < d){ // aとbは互いに離れている。
    return {
            a.center + (cc * r + normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),
            a.center + (cc * r - normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),
            a.center + (cc * R + normal(cc) * sqrt(abs_sq(cc) - R * R)) * a.radius / abs_sq(cc),
            a.center + (cc * R - normal(cc) * sqrt(abs_sq(cc) - R * R)) * a.radius / abs_sq(cc)
    };
  }else if(a.radius + b.radius > d and d > abs(a.radius - b.radius)){ // aとbは二点で交差している。
    return {
            a.center + (cc * r + normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc),
            a.center + (cc * r - normal(cc) * sqrt(abs_sq(cc) - r * r)) * a.radius / abs_sq(cc)
    };
  }else if(abs(a.radius - b.radius) == d){ // 一方が他方に内接している。
    return {
            a.radius > b.radius ? a.center + n * a.radius : b.center - n * b.radius
    };
  }

  return {};
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

