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


# :x: 点・多角形の包含関係

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#090220fbd726178f7b9d402d3ae3f683">Mylib/Geometry/Float</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Geometry/Float/is_point_in_polygon.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Depends on

* :question: <a href="ccw.cpp.html">clockwise-counterclockwise判定</a>
* :question: <a href="geometry_template.cpp.html">幾何基本セット</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/CGL_3_C/main.test.cpp.html">test/aoj/CGL_3_C/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cmath>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/ccw.cpp"

/**
 * @title 点・多角形の包含関係
 * @docs is_point_in_polygon.md
 */
namespace point_in_polygon{
  enum Status{
              INCLUSION  = 0b001,
              ON_SEGMENT = 0b010,
              OUTSIDE    = 0b100
  };

  template <typename T, typename U = typename T::value_type>
  Status check(const Point<T> &p, const Polygon<T> &polygon){
    const int n = polygon.size();
  
    T d = 0;
    for(int i = 0; i < n; ++i){
      if(ccw::ccw(polygon[i], polygon[(i+1)%n], p) == ccw::ON_SEGMENT) return ON_SEGMENT;
      
      T a = angle(polygon[i],p);
      T b = angle(polygon[(i+1)%n],p);

      if(a < 0) a += 2 * M_PI;
      if(b < 0) b += 2 * M_PI;

      T ang = b-a;

      if((T)std::fabs((U)ang) > M_PI){
        if(ang <= 0) ang += 2*M_PI;
        else ang -= 2*M_PI;
      }
      
      d += ang;
    }

    if((T)std::fabs(std::fabs((U)d) - 2*M_PI) == 0) return INCLUSION;
    
    return OUTSIDE;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Geometry/Float/is_point_in_polygon.cpp"
#include <cmath>
#line 2 "Mylib/Geometry/Float/geometry_template.cpp"
#include <iostream>
#line 4 "Mylib/Geometry/Float/geometry_template.cpp"
#include <vector>

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
#line 3 "Mylib/Geometry/Float/ccw.cpp"

/**
 * @title clockwise-counterclockwise判定
 * @docs ccw.md
 */
namespace ccw{
  enum CCW{
           ONLINE_BACK       = -2,
           COUNTER_CLOCKWISE = -1,
           ON_SEGMENT        = 0,
           CLOCKWISE         = 1,
           ONLINE_FRONT      = 2
  };

  template <typename T>
  CCW ccw(const Point<T> &p0, const Point<T> &p1, const Point<T> &p2){
    const T cr = cross(p1-p0, p2-p0);
    const T d = dot(p1-p0, p2-p0);

    if(cr == 0){
      if(d < 0) return ONLINE_BACK;
      else if((p2-p0).size() > (p1-p0).size()) return ONLINE_FRONT;
      else return ON_SEGMENT;
    }else if(cr > 0){
      return COUNTER_CLOCKWISE;
    }else{
      return CLOCKWISE;
    }
  }
}
#line 5 "Mylib/Geometry/Float/is_point_in_polygon.cpp"

/**
 * @title 点・多角形の包含関係
 * @docs is_point_in_polygon.md
 */
namespace point_in_polygon{
  enum Status{
              INCLUSION  = 0b001,
              ON_SEGMENT = 0b010,
              OUTSIDE    = 0b100
  };

  template <typename T, typename U = typename T::value_type>
  Status check(const Point<T> &p, const Polygon<T> &polygon){
    const int n = polygon.size();
  
    T d = 0;
    for(int i = 0; i < n; ++i){
      if(ccw::ccw(polygon[i], polygon[(i+1)%n], p) == ccw::ON_SEGMENT) return ON_SEGMENT;
      
      T a = angle(polygon[i],p);
      T b = angle(polygon[(i+1)%n],p);

      if(a < 0) a += 2 * M_PI;
      if(b < 0) b += 2 * M_PI;

      T ang = b-a;

      if((T)std::fabs((U)ang) > M_PI){
        if(ang <= 0) ang += 2*M_PI;
        else ang -= 2*M_PI;
      }
      
      d += ang;
    }

    if((T)std::fabs(std::fabs((U)d) - 2*M_PI) == 0) return INCLUSION;
    
    return OUTSIDE;
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

