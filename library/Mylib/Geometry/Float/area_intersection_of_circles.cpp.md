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


# :warning: 2円の共通部分の面積

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#090220fbd726178f7b9d402d3ae3f683">Mylib/Geometry/Float</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Geometry/Float/area_intersection_of_circles.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Operations

## Requirements

## Notes

## Problems

- [Educational Codeforces Round 2 D. Area of Two Circles' Intersection](https://codeforces.com/contest/600/problem/D)

## References



## Depends on

* :question: <a href="geometry_template.cpp.html">幾何基本セット</a>
* :x: <a href="intersect_circles.cpp.html">円同士の交差</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cmath>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/intersect_circles.cpp"

/**
 * @title 2円の共通部分の面積
 * @docs area_intersection_of_circles.md
 */
template <typename T, typename U = typename T::value_type>
T area_of_intersection_of_circles(const Circle<T> &a, const Circle<T> &b){
  auto [s, p] = intersect_circles::check(a, b);
  
  switch(s){
  case intersect_circles::SAME: {
    return a.radius * a.radius * M_PI;
  }
  case intersect_circles::INSIDE:
  case intersect_circles::INSCRIBED: {
    return std::min(a.radius * a.radius * M_PI, b.radius * b.radius * M_PI);
  }
  case intersect_circles::INTERSECT: {
    T ret = 0;

    auto d = (a.center - b.center).size();

    {
      T ang = std::acos((U)((a.radius * a.radius + d * d - b.radius * b.radius) / (a.radius * d * 2.0)));
      ret += (ang - std::sin((U)(ang * 2.0)) / 2.0) * a.radius * a.radius;
    }

    {
      T ang = std::acos((U)((b.radius * b.radius + d * d - a.radius * a.radius) / (b.radius * d * 2.0)));
      ret += (ang - std::sin((U)(ang * 2.0)) / 2.0) * b.radius * b.radius;
    }
    
    return ret;
  }
  case intersect_circles::CIRCUMSCRIBED:
  case intersect_circles::OUTSIDE: {
    return 0;
  }
  }
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Geometry/Float/area_intersection_of_circles.cpp"
#include <cmath>
#line 2 "Mylib/Geometry/Float/geometry_template.cpp"
#include <iostream>
#line 4 "Mylib/Geometry/Float/geometry_template.cpp"
#include <vector>

/**
 * @title 幾何基本セット
 * @docs geometry_template.md
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
#line 5 "Mylib/Geometry/Float/intersect_circles.cpp"

/**
 * @title 円同士の交差
 * @docs intersect_circles.md
 */
namespace intersect_circles{
  enum Status{
              SAME          = 0b000001,
              INSIDE        = 0b000010,
              INSCRIBED     = 0b000100,
              INTERSECT     = 0b001000,
              CIRCUMSCRIBED = 0b010000,
              OUTSIDE       = 0b100000
  };

  template <typename T>
  struct Result{
    Status status;
    std::vector<Point<T>> crosspoints;
  };
  
  template <typename T, typename U = typename T::value_type>
  auto check(const Circle<T> &a, const Circle<T> &b){
    Result<T> ret;
    
    const T d = (a.center - b.center).size();
    const T x = std::acos((U)((a.radius * a.radius + d * d - b.radius * b.radius) / ((T)2.0 * d * a.radius)));
    const T t = std::atan2((U)(b.center.y - a.center.y), (U)(b.center.x - a.center.x));
    
    if(a.radius + b.radius == d){
      ret.crosspoints.emplace_back(a.center + Vec<T>::polar(a.radius, t)); // if circumscribed
      ret.status = CIRCUMSCRIBED;
    }
    else if((T)std::fabs((U)(a.radius - b.radius)) == d){
      ret.crosspoints.emplace_back(a.center + Vec<T>::polar(a.radius, t)); // if inscribed
      ret.status = INSCRIBED;
    }
    else if(a.radius + b.radius > d and d > (T)std::fabs((U)(a.radius - b.radius))){ // if intersect
      ret.crosspoints.emplace_back(a.center + Vec<T>::polar(a.radius, t+x));
      ret.crosspoints.emplace_back(a.center + Vec<T>::polar(a.radius, t-x));
      ret.status = INTERSECT;
    }
    else if(a.radius + b.radius < d){
      ret.status = OUTSIDE;
    }
    else if((T)std::fabs((U)(a.radius - b.radius)) > d){
      ret.status = INSIDE;
    }
    else{
      ret.status = SAME;
    }
    
    return ret;
  }
}
#line 5 "Mylib/Geometry/Float/area_intersection_of_circles.cpp"

/**
 * @title 2円の共通部分の面積
 * @docs area_intersection_of_circles.md
 */
template <typename T, typename U = typename T::value_type>
T area_of_intersection_of_circles(const Circle<T> &a, const Circle<T> &b){
  auto [s, p] = intersect_circles::check(a, b);
  
  switch(s){
  case intersect_circles::SAME: {
    return a.radius * a.radius * M_PI;
  }
  case intersect_circles::INSIDE:
  case intersect_circles::INSCRIBED: {
    return std::min(a.radius * a.radius * M_PI, b.radius * b.radius * M_PI);
  }
  case intersect_circles::INTERSECT: {
    T ret = 0;

    auto d = (a.center - b.center).size();

    {
      T ang = std::acos((U)((a.radius * a.radius + d * d - b.radius * b.radius) / (a.radius * d * 2.0)));
      ret += (ang - std::sin((U)(ang * 2.0)) / 2.0) * a.radius * a.radius;
    }

    {
      T ang = std::acos((U)((b.radius * b.radius + d * d - a.radius * a.radius) / (b.radius * d * 2.0)));
      ret += (ang - std::sin((U)(ang * 2.0)) / 2.0) * b.radius * b.radius;
    }
    
    return ret;
  }
  case intersect_circles::CIRCUMSCRIBED:
  case intersect_circles::OUTSIDE: {
    return 0;
  }
  }
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

