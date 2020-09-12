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


# :question: Intersection between two lines

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#090220fbd726178f7b9d402d3ae3f683">Mylib/Geometry/Float</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Geometry/Float/intersect_segments.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Depends on

* :question: <a href="ccw.cpp.html">Check clockwise-counterclockwise</a>
* :question: <a href="geometry_template.cpp.html">Geometry template</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/2136/main.test.cpp.html">test/aoj/2136/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_2_B/main.test.cpp.html">test/aoj/CGL_2_B/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/CGL_2_C/main.test.cpp.html">test/aoj/CGL_2_C/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/ccw.cpp"

/**
 * @title Intersection between two lines
 * @docs intersect_segments.md
 */
namespace haar_lib {
  namespace intersect_segments {
    enum status_t {
                 INTERSECTING     = 0b0001,
                 OVERLAPPED       = 0b0010,
                 NOT_INTERSECTING = 0b0100,
                 SAME             = 0b1000
    };

    template <typename T>
    struct result {
      status_t status;
      std::vector<point<T>> crosspoints;
    };

    template <typename T>
    auto check(const segment<T> &a, const segment<T> &b){
      const T cr = cross(a, b);

      if(abs(cr) == 0){ // parallel
        if(ccw::ccw(a.from, a.to, b.from) * ccw::ccw(a.from, a.to, b.to) <= 0 and
           ccw::ccw(b.from, b.to, a.from) * ccw::ccw(b.from, b.to, a.to) <= 0){
          return result<T>({OVERLAPPED, {}});
        }else{
          return result<T>({NOT_INTERSECTING, {}});
        }
      }

      const T t1 = cross(b.from - a.from, diff(b)) / cr;
      const T t2 = cross(b.from - a.from, diff(a)) / cr;

      if(t1 < 0 or t1 > 1 or t2 < 0 or t2 > 1){ // no crosspoint
        return result<T>({NOT_INTERSECTING, {}});
      }

      return result<T>({INTERSECTING, {a.from + diff(a) * t1}});
    }
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Geometry/Float/intersect_segments.cpp"
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
#line 3 "Mylib/Geometry/Float/ccw.cpp"

/**
 * @title Check clockwise-counterclockwise
 * @docs ccw.md
 */
namespace haar_lib {
  namespace ccw {
    enum status {
                 ONLINE_BACK       = -2,
                 COUNTER_CLOCKWISE = -1,
                 ON_SEGMENT        = 0,
                 CLOCKWISE         = 1,
                 ONLINE_FRONT      = 2
    };

    template <typename T>
    status ccw(const point<T> &p0, const point<T> &p1, const point<T> &p2){
      const T cr = cross(p1 - p0, p2 - p0);
      const T d = dot(p1 - p0, p2 - p0);

      if(cr == 0){
        if(d < 0) return ONLINE_BACK;
        else if(abs(p2 - p0) > abs(p1 - p0)) return ONLINE_FRONT;
        else return ON_SEGMENT;
      }else if(cr > 0){
        return COUNTER_CLOCKWISE;
      }else{
        return CLOCKWISE;
      }
    }
  }
}
#line 5 "Mylib/Geometry/Float/intersect_segments.cpp"

/**
 * @title Intersection between two lines
 * @docs intersect_segments.md
 */
namespace haar_lib {
  namespace intersect_segments {
    enum status_t {
                 INTERSECTING     = 0b0001,
                 OVERLAPPED       = 0b0010,
                 NOT_INTERSECTING = 0b0100,
                 SAME             = 0b1000
    };

    template <typename T>
    struct result {
      status_t status;
      std::vector<point<T>> crosspoints;
    };

    template <typename T>
    auto check(const segment<T> &a, const segment<T> &b){
      const T cr = cross(a, b);

      if(abs(cr) == 0){ // parallel
        if(ccw::ccw(a.from, a.to, b.from) * ccw::ccw(a.from, a.to, b.to) <= 0 and
           ccw::ccw(b.from, b.to, a.from) * ccw::ccw(b.from, b.to, a.to) <= 0){
          return result<T>({OVERLAPPED, {}});
        }else{
          return result<T>({NOT_INTERSECTING, {}});
        }
      }

      const T t1 = cross(b.from - a.from, diff(b)) / cr;
      const T t2 = cross(b.from - a.from, diff(a)) / cr;

      if(t1 < 0 or t1 > 1 or t2 < 0 or t2 > 1){ // no crosspoint
        return result<T>({NOT_INTERSECTING, {}});
      }

      return result<T>({INTERSECTING, {a.from + diff(a) * t1}});
    }
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

