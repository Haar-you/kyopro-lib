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


# :x: Intersection between a circle and a segment

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#090220fbd726178f7b9d402d3ae3f683">Mylib/Geometry/Float</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Geometry/Float/intersect_circle_segment.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Depends on

* :x: <a href="distance_segment_point.cpp.html">Distance between a segment and a point</a>
* :question: <a href="geometry_template.cpp.html">Geometry template</a>


## Required by

* :x: <a href="area_intersection_of_circle_and_polygon.cpp.html">Area of intersection between a circle and a polygon</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/CGL_7_H/main.test.cpp.html">test/aoj/CGL_7_H/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/distance_segment_point.cpp"

/**
 * @title Intersection between a circle and a segment
 * @docs intersect_circle_segment.md
 */
namespace haar_lib {
  namespace intersect_circle_segment {
    enum status_t {
                 INSIDE         = 0b00001,
                 OUTSIDE        = 0b00010,
                 TANGENT        = 0b00100,
                 ONE_CROSSPOINT = 0b01000,
                 TWO_CROSSPOINT = 0b10000
    };

    template <typename T>
    struct result {
      status_t status;
      std::vector<point<T>> crosspoints;
    };

    template <typename T>
    auto check(const circle<T> &cl, const line<T> &s){
      const T r = cl.radius;
      const auto &c = cl.center;

      const T d1 = abs(c - s.from);
      const T d2 = abs(c - s.to);
      const T v = distance_segment_point(s, c);
      const T m = sqrt(r * r - v * v);
      const auto n = normal(s);
      const auto k = s.from + diff(s) * cross(n, c + n - s.from) / cross(n, diff(s));

      if(d1 < r and d2 < r){
        return result<T>({INSIDE, {}});
      }
      else if(v == r){
        return result<T>({TANGENT, {k}});
      }
      else if(v > r){
        return result<T>({OUTSIDE, {}});
      }
      else if(d1 >= r and d2 >= r){
        return result<T>({TWO_CROSSPOINT, {k - unit(s) * m, k + unit(s) * m}});
      }

      const T b = dot(unit(s), s.from - c);
      const T a = abs_sq(s.from - c) - r * r;
      const T x = sqrt(b * b - a);

      return result<T>({ONE_CROSSPOINT, {s.from + unit(s) * (-b - x >= 0 ? -b - x : -b + x)}});
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Geometry/Float/intersect_circle_segment.cpp"
#include <vector>
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
#line 3 "Mylib/Geometry/Float/distance_segment_point.cpp"

/**
 * @title Distance between a segment and a point
 * @docs distance_segment_point.md
 */
namespace haar_lib {
  template <typename T>
  T distance_segment_point(const segment<T> &l, const point<T> &p){
    if(dot(diff(l), p - l.from) < 0) return abs(p - l.from);
    if(dot(-diff(l), p - l.to) < 0) return abs(p - l.to);
    return abs(cross(diff(l), p - l.from)) / abs(l);
  }
}
#line 5 "Mylib/Geometry/Float/intersect_circle_segment.cpp"

/**
 * @title Intersection between a circle and a segment
 * @docs intersect_circle_segment.md
 */
namespace haar_lib {
  namespace intersect_circle_segment {
    enum status_t {
                 INSIDE         = 0b00001,
                 OUTSIDE        = 0b00010,
                 TANGENT        = 0b00100,
                 ONE_CROSSPOINT = 0b01000,
                 TWO_CROSSPOINT = 0b10000
    };

    template <typename T>
    struct result {
      status_t status;
      std::vector<point<T>> crosspoints;
    };

    template <typename T>
    auto check(const circle<T> &cl, const line<T> &s){
      const T r = cl.radius;
      const auto &c = cl.center;

      const T d1 = abs(c - s.from);
      const T d2 = abs(c - s.to);
      const T v = distance_segment_point(s, c);
      const T m = sqrt(r * r - v * v);
      const auto n = normal(s);
      const auto k = s.from + diff(s) * cross(n, c + n - s.from) / cross(n, diff(s));

      if(d1 < r and d2 < r){
        return result<T>({INSIDE, {}});
      }
      else if(v == r){
        return result<T>({TANGENT, {k}});
      }
      else if(v > r){
        return result<T>({OUTSIDE, {}});
      }
      else if(d1 >= r and d2 >= r){
        return result<T>({TWO_CROSSPOINT, {k - unit(s) * m, k + unit(s) * m}});
      }

      const T b = dot(unit(s), s.from - c);
      const T a = abs_sq(s.from - c) - r * r;
      const T x = sqrt(b * b - a);

      return result<T>({ONE_CROSSPOINT, {s.from + unit(s) * (-b - x >= 0 ? -b - x : -b + x)}});
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

