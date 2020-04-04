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


# :heavy_check_mark: 凸包

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#090220fbd726178f7b9d402d3ae3f683">Mylib/Geometry/Float</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Geometry/Float/convex_hull.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-04 13:11:51+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Prelim/0342?year=2016 (凸包/最小全域木)">https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Prelim/0342?year=2016 (凸包/最小全域木)</a>
* see: <a href="https://atcoder.jp/contests/agc021/tasks/agc021_b (凸包)">https://atcoder.jp/contests/agc021/tasks/agc021_b (凸包)</a>
* see: <a href="https://codeforces.com/contest/1143/problem/F (式変形/上側凸包)">https://codeforces.com/contest/1143/problem/F (式変形/上側凸包)</a>


## Depends on

* :heavy_check_mark: <a href="geometry_template.cpp.html">幾何基本セット</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_4_A/main.test.cpp.html">test/aoj/CGL_4_A/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 凸包
 * @see https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Prelim/0342?year=2016 (凸包/最小全域木)
 * @see https://atcoder.jp/contests/agc021/tasks/agc021_b (凸包)
 * @see https://codeforces.com/contest/1143/problem/F (式変形/上側凸包)
 */
template <typename T> 
std::vector<Point<T>> upper_hull(Polygon<T> pts, bool upper = true){
  std::sort(pts.begin(), pts.end(), [](const auto &a, const auto &b){return a.x < b.x or (a.x == b.x and a.y < b.y);});

  if(upper) std::reverse(pts.begin(), pts.end());
  
  std::vector<Point<T>> ret;

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
      
      if(cross(q-p, s-p) <= 0){
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
std::vector<Point<T>> convex_hull(const Polygon<T> &pts){
  auto ret = upper_hull(pts);
  auto lower = upper_hull(pts, false);

  ret.pop_back();
  lower.pop_back();

  for(auto &p : lower) ret.push_back(p);

  return ret;
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
 * @title 幾何基本セット
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
#line 5 "Mylib/Geometry/Float/convex_hull.cpp"

/**
 * @title 凸包
 * @see https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Prelim/0342?year=2016 (凸包/最小全域木)
 * @see https://atcoder.jp/contests/agc021/tasks/agc021_b (凸包)
 * @see https://codeforces.com/contest/1143/problem/F (式変形/上側凸包)
 */
template <typename T> 
std::vector<Point<T>> upper_hull(Polygon<T> pts, bool upper = true){
  std::sort(pts.begin(), pts.end(), [](const auto &a, const auto &b){return a.x < b.x or (a.x == b.x and a.y < b.y);});

  if(upper) std::reverse(pts.begin(), pts.end());
  
  std::vector<Point<T>> ret;

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
      
      if(cross(q-p, s-p) <= 0){
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
std::vector<Point<T>> convex_hull(const Polygon<T> &pts){
  auto ret = upper_hull(pts);
  auto lower = upper_hull(pts, false);

  ret.pop_back();
  lower.pop_back();

  for(auto &p : lower) ret.push_back(p);

  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

