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


# :heavy_check_mark: 最小包含円

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#090220fbd726178f7b9d402d3ae3f683">Mylib/Geometry/Float</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Geometry/Float/minimum_covering_circle.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Operations

## Requirements

## Notes

## Problems

- [ABC 151 F - Enclose All](https://atcoder.jp/contests/abc151/tasks/abc151_f)
- [AOJ 3034 Explosion](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3034)

## References

- [https://tubo28.me/compprog/algorithm/minball/](https://tubo28.me/compprog/algorithm/minball/)


## Depends on

* :heavy_check_mark: <a href="circumscribed_circle_of_triangle.cpp.html">三角形の外接円</a>
* :question: <a href="geometry_template.cpp.html">幾何基本セット</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/3034/main.test.cpp.html">test/aoj/3034/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <random>
#include <algorithm>
#include "Mylib/Geometry/Float/circumscribed_circle_of_triangle.cpp"

/**
 * @title 最小包含円
 * @docs minimum_covering_circle.md
 */
template <typename T>
Circle<T> minimum_covering_circle(std::vector<Point<T>> ps, int seed = 0){
  if(ps.empty()) return Circle<T>();
  if(ps.size() == 1) return Circle<T>(ps[0], 0);

  const int N = ps.size();

  std::mt19937 rand(seed);
  std::shuffle(ps.begin(), ps.end(), rand);

  auto make_circle_2 = [&](const auto &p, const auto &q){
                    const auto c = (p + q) / 2.0;
                    return Circle<T>(c, (p - c).size());
                  };


  auto check = [](const auto &p, const auto &c){
                 return (c.center - p).size() <= c.radius;
               };


  Circle<T> ret = make_circle_2(ps[0], ps[1]);
  
  for(int i = 2; i < N; ++i){
    if(check(ps[i], ret)) continue;

    ret = make_circle_2(ps[0], ps[i]);

    for(int j = 1; j < i; ++j){
      if(check(ps[j], ret)) continue;

      ret = make_circle_2(ps[i], ps[j]);

      for(int k = 0; k < j; ++k){
        if(check(ps[k], ret)) continue;
        if(i == j or j == k or k == i) continue;

        ret = circumscribed_circle_of_triangle(ps[i], ps[j], ps[k]);
      }
    }
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Geometry/Float/minimum_covering_circle.cpp"
#include <vector>
#include <random>
#include <algorithm>
#line 2 "Mylib/Geometry/Float/circumscribed_circle_of_triangle.cpp"
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
#line 4 "Mylib/Geometry/Float/circumscribed_circle_of_triangle.cpp"

/**
 * @title 三角形の外接円
 * @docs circumscribed_circle_of_triangle.md
 */
template <typename T, typename U = typename T::value_type>
Circle<T> circumscribed_circle_of_triangle(const Point<T> &a, const Point<T> &b, const Point<T> &c){
  T A = (b-c).size_sq(), B = (a-c).size_sq(), C = (a-b).size_sq();
  T x = std::sqrt((U)A), y = std::sqrt((U)B), z = std::sqrt((U)C);

  return Circle<T>
    (
     (A*(B+C-A)*a + B*(C+A-B)*b + C*(A+B-C)*c) / (A*(B+C-A) + B*(C+A-B) + C*(A+B-C)),
     x * y * z / std::sqrt((U)((x+y+z)*(-x+y+z)*(x-y+z)*(x+y-z)))
     );
}
#line 6 "Mylib/Geometry/Float/minimum_covering_circle.cpp"

/**
 * @title 最小包含円
 * @docs minimum_covering_circle.md
 */
template <typename T>
Circle<T> minimum_covering_circle(std::vector<Point<T>> ps, int seed = 0){
  if(ps.empty()) return Circle<T>();
  if(ps.size() == 1) return Circle<T>(ps[0], 0);

  const int N = ps.size();

  std::mt19937 rand(seed);
  std::shuffle(ps.begin(), ps.end(), rand);

  auto make_circle_2 = [&](const auto &p, const auto &q){
                    const auto c = (p + q) / 2.0;
                    return Circle<T>(c, (p - c).size());
                  };


  auto check = [](const auto &p, const auto &c){
                 return (c.center - p).size() <= c.radius;
               };


  Circle<T> ret = make_circle_2(ps[0], ps[1]);
  
  for(int i = 2; i < N; ++i){
    if(check(ps[i], ret)) continue;

    ret = make_circle_2(ps[0], ps[i]);

    for(int j = 1; j < i; ++j){
      if(check(ps[j], ret)) continue;

      ret = make_circle_2(ps[i], ps[j]);

      for(int k = 0; k < j; ++k){
        if(check(ps[k], ret)) continue;
        if(i == j or j == k or k == i) continue;

        ret = circumscribed_circle_of_triangle(ps[i], ps[j], ps[k]);
      }
    }
  }

  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

