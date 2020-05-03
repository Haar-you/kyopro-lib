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


# :heavy_check_mark: 2円の共通接線

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#090220fbd726178f7b9d402d3ae3f683">Mylib/Geometry/Float</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Geometry/Float/common_tangent_of_circles.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Depends on

* :heavy_check_mark: <a href="geometry_template.cpp.html">幾何基本セット</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_7_G/main.test.cpp.html">test/aoj/CGL_7_G/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <cmath>
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 2円の共通接線
 * @docs common_tangent_of_circles.md
 */
template <typename T, typename U = typename T::value_type>
std::vector<Point<T>> common_tangent_of_circles(const Circle<T> &a, const Circle<T> &b){
  const T d = (b.center - a.center).size();
  const auto n = unit(b.center - a.center);

  const auto cc = b.center - a.center;
  const T r = a.radius - b.radius;
  const T R = a.radius + b.radius;
  
  if(a.radius + b.radius == d){ // 一方が他方に外接している。
    return {
            a.center + (cc*r + normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + (cc*r - normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + n * a.radius
    };
  }else if(a.radius + b.radius < d){ // aとbは互いに離れている。
    return {
            a.center + (cc*r + normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + (cc*r - normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + (cc*R + normal(cc) * std::sqrt((U)(cc.size_sq()-R*R))) * a.radius / cc.size_sq(),
            a.center + (cc*R - normal(cc) * std::sqrt((U)(cc.size_sq()-R*R))) * a.radius / cc.size_sq()	    
    };
  }else if(a.radius + b.radius > d and d > (T)std::fabs((U)(a.radius - b.radius))){ // aとbは二点で交差している。
    return {
            a.center + (cc*r + normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + (cc*r - normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq()	    
    };
  }else if((T)std::fabs((U)(a.radius - b.radius)) == d){ // 一方が他方に内接している。
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
#include <cmath>
#line 2 "Mylib/Geometry/Float/geometry_template.cpp"
#include <iostream>
#line 5 "Mylib/Geometry/Float/geometry_template.cpp"

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
#line 5 "Mylib/Geometry/Float/common_tangent_of_circles.cpp"

/**
 * @title 2円の共通接線
 * @docs common_tangent_of_circles.md
 */
template <typename T, typename U = typename T::value_type>
std::vector<Point<T>> common_tangent_of_circles(const Circle<T> &a, const Circle<T> &b){
  const T d = (b.center - a.center).size();
  const auto n = unit(b.center - a.center);

  const auto cc = b.center - a.center;
  const T r = a.radius - b.radius;
  const T R = a.radius + b.radius;
  
  if(a.radius + b.radius == d){ // 一方が他方に外接している。
    return {
            a.center + (cc*r + normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + (cc*r - normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + n * a.radius
    };
  }else if(a.radius + b.radius < d){ // aとbは互いに離れている。
    return {
            a.center + (cc*r + normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + (cc*r - normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + (cc*R + normal(cc) * std::sqrt((U)(cc.size_sq()-R*R))) * a.radius / cc.size_sq(),
            a.center + (cc*R - normal(cc) * std::sqrt((U)(cc.size_sq()-R*R))) * a.radius / cc.size_sq()	    
    };
  }else if(a.radius + b.radius > d and d > (T)std::fabs((U)(a.radius - b.radius))){ // aとbは二点で交差している。
    return {
            a.center + (cc*r + normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + (cc*r - normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq()	    
    };
  }else if((T)std::fabs((U)(a.radius - b.radius)) == d){ // 一方が他方に内接している。
    return {
            a.radius > b.radius ? a.center + n * a.radius : b.center - n * b.radius
    };
  }

  return {};
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

