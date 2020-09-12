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


# :x: Area of intersection between two circles

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#090220fbd726178f7b9d402d3ae3f683">Mylib/Geometry/Float</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Geometry/Float/area_intersection_of_circles.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

## Requirements

## Notes

## Problems

- [Educational Codeforces Round 2 D. Area of Two Circles' Intersection](https://codeforces.com/contest/600/problem/D)

## References



## Depends on

* :question: <a href="geometry_template.cpp.html">Geometry template</a>
* :x: <a href="intersect_circles.cpp.html">Intersection between two circles</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/CGL_7_I/main.test.cpp.html">test/aoj/CGL_7_I/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/intersect_circles.cpp"

/**
 * @title Area of intersection between two circles
 * @docs area_intersection_of_circles.md
 */
namespace haar_lib {
  template <typename T>
  T area_of_intersection_of_circles(const circle<T> &a, const circle<T> &b){
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

      auto d = abs(a.center - b.center);

      {
        T ang = acos((a.radius * a.radius + d * d - b.radius * b.radius) / (a.radius * d * 2.0));
        ret += (ang - sin(ang * 2.0) / 2.0) * a.radius * a.radius;
      }

      {
        T ang = acos((b.radius * b.radius + d * d - a.radius * a.radius) / (b.radius * d * 2.0));
        ret += (ang - sin(ang * 2.0) / 2.0) * b.radius * b.radius;
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
}

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
#line 4 "Mylib/Geometry/Float/intersect_circles.cpp"

/**
 * @title Intersection between two circles
 * @docs intersect_circles.md
 */
namespace haar_lib {
  namespace intersect_circles {
    enum status_t {
                 SAME          = 0b000001,
                 INSIDE        = 0b000010,
                 INSCRIBED     = 0b000100,
                 INTERSECT     = 0b001000,
                 CIRCUMSCRIBED = 0b010000,
                 OUTSIDE       = 0b100000
    };

    template <typename T>
    struct result {
      status_t status;
      std::vector<point<T>> crosspoints;
    };

    template <typename T>
    auto check(const circle<T> &a, const circle<T> &b){
      const T d = abs(a.center - b.center);
      const T x = acos((a.radius * a.radius + d * d - b.radius * b.radius) / ((T)2.0 * d * a.radius));
      const T t = atan2(b.center.y - a.center.y, b.center.x - a.center.x);

      if(a.radius + b.radius == d){
        return result<T>({CIRCUMSCRIBED, {a.center + polar(a.radius, t)}});
      }
      else if(abs(a.radius - b.radius) == d){
        return result<T>({INSCRIBED, {a.center + polar(a.radius, t)}});
      }
      else if(a.radius + b.radius > d and d > abs(a.radius - b.radius)){
        return result<T>({INTERSECT, {a.center + polar(a.radius, t + x), a.center + polar(a.radius, t - x)}});
      }
      else if(a.radius + b.radius < d){
        return result<T>({OUTSIDE, {}});
      }
      else if(abs(a.radius - b.radius) > d){
        return result<T>({INSIDE, {}});
      }

      return result<T>({SAME, {}});
    }
  }
}
#line 4 "Mylib/Geometry/Float/area_intersection_of_circles.cpp"

/**
 * @title Area of intersection between two circles
 * @docs area_intersection_of_circles.md
 */
namespace haar_lib {
  template <typename T>
  T area_of_intersection_of_circles(const circle<T> &a, const circle<T> &b){
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

      auto d = abs(a.center - b.center);

      {
        T ang = acos((a.radius * a.radius + d * d - b.radius * b.radius) / (a.radius * d * 2.0));
        ret += (ang - sin(ang * 2.0) / 2.0) * a.radius * a.radius;
      }

      {
        T ang = acos((b.radius * b.radius + d * d - a.radius * a.radius) / (b.radius * d * 2.0));
        ret += (ang - sin(ang * 2.0) / 2.0) * b.radius * b.radius;
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
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

