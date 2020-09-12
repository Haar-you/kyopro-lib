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


# :x: Convex hull

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#090220fbd726178f7b9d402d3ae3f683">Mylib/Geometry/Float</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Geometry/Float/convex_hull.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

## Requirements

## Notes

## Problems

- [AOJ 0342 Road Planning](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0342) (凸包/最小全域木)
- [AGC 021 B - Holes](https://atcoder.jp/contests/agc021/tasks/agc021_b) (凸包)
- [Codeforces Round #549 (Div. 2) F. U2](https://codeforces.com/contest/1143/problem/F) (式変形/上側凸包)

## References



## Depends on

* :question: <a href="geometry_template.cpp.html">Geometry template</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/CGL_4_A/main.test.cpp.html">test/aoj/CGL_4_A/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title Convex hull
 * @docs convex_hull.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<point<T>> upper_hull(polygon<T> pts, bool upper = true){
    std::sort(
      pts.begin(),
      pts.end(),
      [](const auto &a, const auto &b){return a.x < b.x or (a.x == b.x and a.y < b.y);}
    );

    if(upper) std::reverse(pts.begin(), pts.end());

    std::vector<point<T>> ret;

    ret.push_back(pts.back());
    pts.pop_back();

    while(not pts.empty()){
      const auto s = pts.back();
      pts.pop_back();

      if(ret.size() == 1){
        ret.push_back(s);
      }else{
        const auto p = *(ret.end()-2);
        const auto q = ret.back();

        if(cross(q - p, s - p) <= 0){
          ret.push_back(s);
        }else{
          ret.pop_back();
          pts.push_back(s);
        }
      }
    }

    return ret;
  }

  template <typename T>
  std::vector<point<T>> convex_hull(const polygon<T> &pts){
    auto ret = upper_hull(pts);
    auto lower = upper_hull(pts, false);

    ret.pop_back();
    lower.pop_back();

    for(auto &p : lower) ret.push_back(p);

    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Geometry/Float/convex_hull.cpp"
#include <vector>
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
#line 5 "Mylib/Geometry/Float/convex_hull.cpp"

/**
 * @title Convex hull
 * @docs convex_hull.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<point<T>> upper_hull(polygon<T> pts, bool upper = true){
    std::sort(
      pts.begin(),
      pts.end(),
      [](const auto &a, const auto &b){return a.x < b.x or (a.x == b.x and a.y < b.y);}
    );

    if(upper) std::reverse(pts.begin(), pts.end());

    std::vector<point<T>> ret;

    ret.push_back(pts.back());
    pts.pop_back();

    while(not pts.empty()){
      const auto s = pts.back();
      pts.pop_back();

      if(ret.size() == 1){
        ret.push_back(s);
      }else{
        const auto p = *(ret.end()-2);
        const auto q = ret.back();

        if(cross(q - p, s - p) <= 0){
          ret.push_back(s);
        }else{
          ret.pop_back();
          pts.push_back(s);
        }
      }
    }

    return ret;
  }

  template <typename T>
  std::vector<point<T>> convex_hull(const polygon<T> &pts){
    auto ret = upper_hull(pts);
    auto lower = upper_hull(pts, false);

    ret.pop_back();
    lower.pop_back();

    for(auto &p : lower) ret.push_back(p);

    return ret;
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

