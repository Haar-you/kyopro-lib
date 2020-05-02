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


# :x: 最近点対

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#090220fbd726178f7b9d402d3ae3f683">Mylib/Geometry/Float</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Geometry/Float/closest_pair.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Depends on

* :question: <a href="geometry_template.cpp.html">幾何基本セット</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/CGL_5_A/main.test.cpp.html">test/aoj/CGL_5_A/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include <limits>
#include <algorithm>
#include <cmath>
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 最近点対
 * @docs closest_pair.md
 */
namespace closest_pair{
  template <typename T, typename U = typename T::value_type>
  T closest_pair(std::vector<Point<T>> &s){
    const int N = s.size();

    if(N == 1) return std::numeric_limits<T>::infinity();

    if(N == 2){
      if(s[0].y > s[1].y) std::swap(s[0], s[1]);
      return (s[0] - s[1]).size();
    }
    
    const T mid_x = s[N/2].x;
    
    auto left = std::vector<Point<T>>(s.begin(), s.begin() + N/2);
    auto right = std::vector<Point<T>>(s.begin() + N/2, s.end());

    const T d1 = closest_pair(left);
    const T d2 = closest_pair(right);

    T d = std::min(d1, d2);

    s.clear();

    std::merge(left.begin(), left.end(),
               right.begin(), right.end(),
               std::back_inserter(s),
               [](const auto &a, const auto &b){return a.y < b.y;});

    std::vector<Point<T>> v;

    for(const auto &p : s){
      if((T)std::fabs((U)(p.x - mid_x)) > d) continue;

      for(auto it = v.rbegin(); it != v.rend(); ++it){
        const auto &q = *it;
        if((T)std::fabs((U)(p.y - q.y)) > d) break;

        d = std::min(d, (p - q).size());
      }

      v.push_back(p);
    }
  
    return d;
  }

  template <typename T>
  T solve(std::vector<Point<T>> s){
    std::sort(s.begin(), s.end(), [](const auto &a, const auto &b){return a.x < b.x;});
    return closest_pair(s);
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Geometry/Float/closest_pair.cpp"
#include <vector>
#include <utility>
#include <limits>
#include <algorithm>
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
#line 8 "Mylib/Geometry/Float/closest_pair.cpp"

/**
 * @title 最近点対
 * @docs closest_pair.md
 */
namespace closest_pair{
  template <typename T, typename U = typename T::value_type>
  T closest_pair(std::vector<Point<T>> &s){
    const int N = s.size();

    if(N == 1) return std::numeric_limits<T>::infinity();

    if(N == 2){
      if(s[0].y > s[1].y) std::swap(s[0], s[1]);
      return (s[0] - s[1]).size();
    }
    
    const T mid_x = s[N/2].x;
    
    auto left = std::vector<Point<T>>(s.begin(), s.begin() + N/2);
    auto right = std::vector<Point<T>>(s.begin() + N/2, s.end());

    const T d1 = closest_pair(left);
    const T d2 = closest_pair(right);

    T d = std::min(d1, d2);

    s.clear();

    std::merge(left.begin(), left.end(),
               right.begin(), right.end(),
               std::back_inserter(s),
               [](const auto &a, const auto &b){return a.y < b.y;});

    std::vector<Point<T>> v;

    for(const auto &p : s){
      if((T)std::fabs((U)(p.x - mid_x)) > d) continue;

      for(auto it = v.rbegin(); it != v.rend(); ++it){
        const auto &q = *it;
        if((T)std::fabs((U)(p.y - q.y)) > d) break;

        d = std::min(d, (p - q).size());
      }

      v.push_back(p);
    }
  
    return d;
  }

  template <typename T>
  T solve(std::vector<Point<T>> s){
    std::sort(s.begin(), s.end(), [](const auto &a, const auto &b){return a.x < b.x;});
    return closest_pair(s);
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

