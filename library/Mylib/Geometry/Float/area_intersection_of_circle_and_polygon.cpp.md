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


# :x: 円と多角形の共通部分の面積

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#090220fbd726178f7b9d402d3ae3f683">Mylib/Geometry/Float</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Geometry/Float/area_intersection_of_circle_and_polygon.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Depends on

* :x: <a href="distance_segment_point.cpp.html">線分・点間の距離</a>
* :question: <a href="geometry_template.cpp.html">幾何基本セット</a>
* :x: <a href="intersect_circle_segment.cpp.html">円と線分の交差</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/CGL_7_H/main.test.cpp.html">test/aoj/CGL_7_H/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/intersect_circle_segment.cpp"

/**
 * @title 円と多角形の共通部分の面積
 * @docs area_intersection_of_circle_and_polygon.md
 */
template <typename T>
T area_intersection_of_circle_and_polygon(const Circle<T> &cl, const Polygon<T> &ps){
  const int n = ps.size();
  T ret = 0;
  
  for(int i = 0; i < n; ++i){
    T temp = 0;

    const T r = cl.radius;
    const auto &c = cl.center;

    const auto &p1 = ps[i];
    const auto &p2 = ps[(i+1)%n];

    const auto [t, res] = intersect_circle_segment::check(cl, Line<T>(p1,p2));

    const T d1 = (p1 - c).size();
    const T d2 = (p2 - c).size();
    
    if(res.size() == 0){
      if(t == intersect_circle_segment::INSIDE){ // if inside
        temp += cross(p1-c, p2-c) / 2;
      }else{ // if outside
        temp += r * r * angle_diff(p1-c, p2-c) / 2;
      }
    }else if(res.size() == 1){
      const auto &q = res[0];
      if(d1 >= r and d2 >= r){
        temp += r * r * angle_diff(p1-c, p2-c) / 2;
      }else if(d1 >= r){
        temp += r * r * angle_diff(p1-c, q-c) / 2 + cross(q-c, p2-c) / 2;
      }else{
        temp += cross(p1-c, q-c) / 2 + r * r * angle_diff(q-c, p2-c) / 2;
      }
    }else{
      const auto &q1 = res[0];
      const auto &q2 = res[1];
      temp +=
        r * r * angle_diff(p1-c, q1-c) / 2 +
        cross(q1-c, q2-c) / 2 +
        r * r * angle_diff(q2-c, p2-c) / 2;
    }
    
    ret += temp;
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Geometry/Float/area_intersection_of_circle_and_polygon.cpp"
#include <vector>
#line 2 "Mylib/Geometry/Float/geometry_template.cpp"
#include <iostream>
#include <cmath>
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
#line 3 "Mylib/Geometry/Float/distance_segment_point.cpp"

/**
 * @title 線分・点間の距離
 * @docs distance_segment_point.md
 */
template <typename T, typename U = typename T::value_type>
T distance_segment_point(const Line<T> &l, const Point<T> &p){
  if(dot(l.diff(), p-l.from) < 0) return (p-l.from).size();
  if(dot(-l.diff(), p-l.to) < 0) return (p-l.to).size();
  return (T)std::abs((U)cross(l.diff(), p-l.from)) / l.size();
}
#line 6 "Mylib/Geometry/Float/intersect_circle_segment.cpp"

/**
 * @title 円と線分の交差
 * @docs intersect_circle_segment.md
 */
namespace intersect_circle_segment{
  enum Status{
              INSIDE         = 0b00001,
              OUTSIDE        = 0b00010,
              TANGENT        = 0b00100,
              ONE_CROSSPOINT = 0b01000,
              TWO_CROSSPOINT = 0b10000
  };

  template <typename T>
  struct Result{
    Status status;
    std::vector<Point<T>> crosspoints;
  };

  template <typename T, typename U = typename T::value_type>
  auto check(const Circle<T> &cl, const Line<T> &s){
    Result<T> ret;
    
    const T r = cl.radius;
    const auto &c = cl.center;

    const T d1 = (c - s.from).size();
    const T d2 = (c - s.to).size();
    const T v = distance_segment_point(s, c);
    const T m = std::sqrt((U)(r*r - v*v));
    const auto n = normal(s.diff());
    const auto k = s.from + s.diff() * cross(n, c + n - s.from) / cross(n, s.diff());

    if(d1 < r and d2 < r){ // if inside
      ret.status = INSIDE;
    }
    else if(v == r){ // if tangent
      ret.crosspoints.emplace_back(k);
      ret.status = TANGENT;
    }
    else if(v > r){ // if outside
      ret.status = OUTSIDE;
    }
    else if(d1 >= r and d2 >= r){ // if two crosspoints exist
      ret.crosspoints.emplace_back(k - unit(s.diff()) * m);
      ret.crosspoints.emplace_back(k + unit(s.diff()) * m);
      ret.status = TWO_CROSSPOINT;
    }
    else{ // if one crosspoint exists
      const T b = dot(unit(s.diff()), s.from - c);
      const T a = (s.from - c).size_sq() - r*r;
      const T x = std::sqrt((U)(b*b - a));
      ret.crosspoints.emplace_back(s.from + unit(s.diff()) * (-b-x >= 0 ? -b-x : -b+x));
      ret.status = ONE_CROSSPOINT;
    }

    return ret;
  }
};
#line 5 "Mylib/Geometry/Float/area_intersection_of_circle_and_polygon.cpp"

/**
 * @title 円と多角形の共通部分の面積
 * @docs area_intersection_of_circle_and_polygon.md
 */
template <typename T>
T area_intersection_of_circle_and_polygon(const Circle<T> &cl, const Polygon<T> &ps){
  const int n = ps.size();
  T ret = 0;
  
  for(int i = 0; i < n; ++i){
    T temp = 0;

    const T r = cl.radius;
    const auto &c = cl.center;

    const auto &p1 = ps[i];
    const auto &p2 = ps[(i+1)%n];

    const auto [t, res] = intersect_circle_segment::check(cl, Line<T>(p1,p2));

    const T d1 = (p1 - c).size();
    const T d2 = (p2 - c).size();
    
    if(res.size() == 0){
      if(t == intersect_circle_segment::INSIDE){ // if inside
        temp += cross(p1-c, p2-c) / 2;
      }else{ // if outside
        temp += r * r * angle_diff(p1-c, p2-c) / 2;
      }
    }else if(res.size() == 1){
      const auto &q = res[0];
      if(d1 >= r and d2 >= r){
        temp += r * r * angle_diff(p1-c, p2-c) / 2;
      }else if(d1 >= r){
        temp += r * r * angle_diff(p1-c, q-c) / 2 + cross(q-c, p2-c) / 2;
      }else{
        temp += cross(p1-c, q-c) / 2 + r * r * angle_diff(q-c, p2-c) / 2;
      }
    }else{
      const auto &q1 = res[0];
      const auto &q2 = res[1];
      temp +=
        r * r * angle_diff(p1-c, q1-c) / 2 +
        cross(q1-c, q2-c) / 2 +
        r * r * angle_diff(q2-c, p2-c) / 2;
    }
    
    ret += temp;
  }

  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

