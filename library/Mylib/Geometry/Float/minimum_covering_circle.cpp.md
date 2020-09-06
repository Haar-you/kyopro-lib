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


# :x: Minimum covering circle

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#090220fbd726178f7b9d402d3ae3f683">Mylib/Geometry/Float</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Geometry/Float/minimum_covering_circle.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Operations

## Requirements

## Notes

## Problems

- [ABC 151 F - Enclose All](https://atcoder.jp/contests/abc151/tasks/abc151_f)
- [AOJ 3034 Explosion](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3034)

## References

- [https://tubo28.me/compprog/algorithm/minball/](https://tubo28.me/compprog/algorithm/minball/)


## Depends on

* :x: <a href="circumscribed_circle_of_triangle.cpp.html">Circumscribed circle of a triangle</a>
* :x: <a href="geometry_template.cpp.html">Geometry template</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/3034/main.test.cpp.html">test/aoj/3034/main.test.cpp</a>


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
 * @title Minimum covering circle
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
                    return Circle<T>(c, abs(p - c));
                  };

  auto check = [](const auto &p, const auto &c){
                 return abs(c.center - p) <= c.radius;
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
#line 2 "Mylib/Geometry/Float/geometry_template.cpp"
#include <iostream>
#include <cmath>
#line 5 "Mylib/Geometry/Float/geometry_template.cpp"

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
#line 3 "Mylib/Geometry/Float/circumscribed_circle_of_triangle.cpp"

/**
 * @title Circumscribed circle of a triangle
 * @docs circumscribed_circle_of_triangle.md
 */
template <typename T>
Circle<T> circumscribed_circle_of_triangle(const Point<T> &a, const Point<T> &b, const Point<T> &c){
  const T A = abs_sq(b - c), B = abs_sq(a - c), C = abs_sq(a - b), S = A + B + C;
  const T AA = A * (S - A * 2.0);
  const T BB = B * (S - B * 2.0);
  const T CC = C * (S - C * 2.0);
  const auto center = (AA * a + BB * b + CC * c) / (AA + BB + CC);

  return Circle<T>(
    center,
    abs(center - a)
  );
}
#line 6 "Mylib/Geometry/Float/minimum_covering_circle.cpp"

/**
 * @title Minimum covering circle
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
                    return Circle<T>(c, abs(p - c));
                  };

  auto check = [](const auto &p, const auto &c){
                 return abs(c.center - p) <= c.radius;
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

