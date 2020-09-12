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
    - Last commit date: 2020-09-09 02:56:29+09:00




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
* :question: <a href="geometry_template.cpp.html">Geometry template</a>


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
namespace haar_lib {
  template <typename T>
  circle<T> minimum_covering_circle(std::vector<point<T>> ps, int seed = 0){
    if(ps.empty()) return circle<T>();
    if(ps.size() == 1) return circle<T>(ps[0], 0);

    const int N = ps.size();

    std::mt19937 rand(seed);
    std::shuffle(ps.begin(), ps.end(), rand);

    auto make_circle_2 =
      [&](const auto &p, const auto &q){
        const auto c = (p + q) / 2.0;
        return circle<T>(c, abs(p - c));
      };

    auto check =
      [](const auto &p, const auto &c){
        return abs(c.center - p) <= c.radius;
      };

    circle<T> ret = make_circle_2(ps[0], ps[1]);

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
namespace haar_lib {
  template <typename T>
  struct vec {
    T x, y;
    vec(){}
    vec(T x, T y): x(x), y(y){}

    friend auto operator+(const vec &a, const vec &b){return vec(a.x + b.x, a.y + b.y);}
    friend auto operator-(const vec &a, const vec &b){return vec(a.x - b.x, a.y - b.y);}
    friend auto operator-(const vec &a){return vec(-a.x, -a.y);}

    friend bool operator==(const vec &a, const vec &b){return a.x == b.x and a.y == b.y;}
    friend bool operator!=(const vec &a, const vec &b){return !(a == b);}
    friend bool operator<(const vec &a, const vec &b){return a.x < b.x or (a.x == b.x and a.y < b.y);}

    friend std::istream& operator>>(std::istream &s, vec &a){
      s >> a.x >> a.y; return s;
    }
  };

  template <typename T, typename U> auto operator*(const vec<T> &a, const U &k){return vec<T>(a.x * k, a.y * k);}
  template <typename T, typename U> auto operator*(const U &k, const vec<T> &a){return vec<T>(a.x * k, a.y * k);}
  template <typename T, typename U> auto operator/(const vec<T> &a, const U &k){return vec<T>(a.x / k, a.y / k);}

  template <typename T> using point = vec<T>;

  template <typename T> T abs(const vec<T> &a){return sqrt(a.x * a.x + a.y * a.y);}
  template <typename T> T abs_sq(const vec<T> &a){return a.x * a.x + a.y * a.y;}

  template <typename T> T dot(const vec<T> &a, const vec<T> &b){return a.x * b.x + a.y * b.y;}
  template <typename T> T cross(const vec<T> &a, const vec<T> &b){return a.x * b.y - a.y * b.x;}

  template <typename T> auto unit(const vec<T> &a){return a / abs(a);}
  template <typename T> auto normal(const vec<T> &p){return vec<T>(-p.y, p.x);}

  template <typename T> auto polar(const T &r, const T &ang){return vec<T>(r * cos(ang), r * sin(ang));}

  template <typename T> T angle(const vec<T> &a, const vec<T> &b){return atan2(b.y - a.y, b.x - a.x);}
  template <typename T> T phase(const vec<T> &a){return atan2(a.y, a.x);}

  template <typename T>
  T angle_diff(const vec<T> &a, const vec<T> &b){
    T r = phase(b) - phase(a);

    if(r < -M_PI) return r + 2 * M_PI;
    else if(r > M_PI) return r - 2 * M_PI;
    return r;
  }


  template <typename T> struct line {
    point<T> from, to;
    line(): from(), to(){}
    line(const point<T> &from, const point<T> &to): from(from), to(to){}
  };

  template <typename T> using segment = line<T>;


  template <typename T> auto unit(const line<T> &a){return unit(a.to - a.from);}
  template <typename T> auto normal(const line<T> &a){return normal(a.to - a.from);}

  template <typename T> auto diff(const segment<T> &a){return a.to - a.from;}

  template <typename T> T abs(const segment<T> &a){return abs(diff(a));}

  template <typename T> T dot(const line<T> &a, const line<T> &b){return dot(diff(a), diff(b));}
  template <typename T> T cross(const line<T> &a, const line<T> &b){return cross(diff(a), diff(b));}


  template <typename T> using polygon = std::vector<point<T>>;

  template <typename T> struct circle {
    point<T> center;
    T radius;
    circle(): center(), radius(0){}
    circle(const point<T> &center, T radius): center(center), radius(radius){}
  };

  template <typename T>
  std::ostream& operator<<(std::ostream &s, const vec<T> &a){
    s << "(" << a.x << ", " << a.y << ")";
    return s;
  }

  template <typename T>
  std::ostream& operator<<(std::ostream &s, const line<T> &a){
    s << "(" << a.from << " -> " << a.to << ")";
    return s;
  }

  template <typename T>
  std::ostream& operator<<(std::ostream &s, const circle<T> &a){
    s << "("
      << "center: " << a.center << ", "
      << "radius: " << a.radius << ")";
    return s;
  }
}
#line 3 "Mylib/Geometry/Float/circumscribed_circle_of_triangle.cpp"

/**
 * @title Circumscribed circle of a triangle
 * @docs circumscribed_circle_of_triangle.md
 */
namespace haar_lib {
  template <typename T>
  circle<T> circumscribed_circle_of_triangle(const point<T> &a, const point<T> &b, const point<T> &c){
    const T A = abs_sq(b - c), B = abs_sq(a - c), C = abs_sq(a - b), S = A + B + C;
    const T AA = A * (S - A * 2.0);
    const T BB = B * (S - B * 2.0);
    const T CC = C * (S - C * 2.0);
    const auto center = (AA * a + BB * b + CC * c) / (AA + BB + CC);

    return circle<T>(
      center,
      abs(center - a)
    );
  }
}
#line 6 "Mylib/Geometry/Float/minimum_covering_circle.cpp"

/**
 * @title Minimum covering circle
 * @docs minimum_covering_circle.md
 */
namespace haar_lib {
  template <typename T>
  circle<T> minimum_covering_circle(std::vector<point<T>> ps, int seed = 0){
    if(ps.empty()) return circle<T>();
    if(ps.size() == 1) return circle<T>(ps[0], 0);

    const int N = ps.size();

    std::mt19937 rand(seed);
    std::shuffle(ps.begin(), ps.end(), rand);

    auto make_circle_2 =
      [&](const auto &p, const auto &q){
        const auto c = (p + q) / 2.0;
        return circle<T>(c, abs(p - c));
      };

    auto check =
      [](const auto &p, const auto &c){
        return abs(c.center - p) <= c.radius;
      };

    circle<T> ret = make_circle_2(ps[0], ps[1]);

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
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

