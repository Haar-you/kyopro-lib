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


# :heavy_check_mark: test/aoj/CGL_7_D/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#e911575daa682b21b03c82a7db870c26">test/aoj/CGL_7_D</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/CGL_7_D/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/distance_line_point.cpp.html">直線と点間の距離</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/double_eps.cpp.html">誤差許容浮動小数点数</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/geometry_template.cpp.html">幾何基本セット</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/intersect_circle_line.cpp.html">円と直線の交差</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D"
#define ERROR 0.000001

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/intersect_circle_line.cpp"

using D = DoubleEps<double>;
template<> double D::eps = 1e-7;

int main(){
  Circle<D> c;
  std::cin >> c.center >> c.radius;

  int q; std::cin >> q;

  while(q--){
    Point<D> p0, p1; std::cin >> p0 >> p1;
    Line<D> l(p0, p1);

    auto [s, ans] = intersect_circle_line::check(c, l);
    
    std::sort(ans.begin(), ans.end(), [](const auto &a, const auto &b){return a.x < b.x or (a.x == b.x and a.y < b.y);});

    std::cout << std::fixed << std::setprecision(12);

    if(s == intersect_circle_line::TANGENT){
      std::cout << ans[0].x << " " << ans[0].y << " ";
      std::cout << ans[0].x << " " << ans[0].y << std::endl;
    }else if(s == intersect_circle_line::CROSSED){
      std::cout << ans[0].x << " " << ans[0].y << " ";
      std::cout << ans[1].x << " " << ans[1].y << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/CGL_7_D/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D"
#define ERROR 0.000001

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#line 3 "Mylib/Geometry/Float/double_eps.cpp"
#include <limits>

/**
 * @title 誤差許容浮動小数点数
 * @docs double_eps.md
 */
template <typename T>
struct DoubleEps{
  using value_type = T;
  
  static T eps;

  T value;

  DoubleEps(): value(0){}
  DoubleEps(T value): value(value){}
  
  auto& operator=(const DoubleEps &rhs){this->value = rhs.value; return *this;}
  auto& operator+=(const DoubleEps &rhs){this->value += rhs.value; return *this;}
  auto& operator-=(const DoubleEps &rhs){this->value -= rhs.value; return *this;}
  auto& operator*=(const DoubleEps &rhs){this->value *= rhs.value; return *this;}
  auto& operator/=(const DoubleEps &rhs){this->value /= rhs.value; return *this;}

  auto operator+(const DoubleEps &rhs) const {return DoubleEps(this->value + rhs.value);}
  auto operator-(const DoubleEps &rhs) const {return DoubleEps(this->value - rhs.value);}
  auto operator*(const DoubleEps &rhs) const {return DoubleEps(this->value * rhs.value);}
  auto operator/(const DoubleEps &rhs) const {return DoubleEps(this->value / rhs.value);}

  bool operator==(const DoubleEps &rhs) const {return std::abs(this->value - rhs.value) < eps;}
  bool operator!=(const DoubleEps &rhs) const {return !(*this == rhs);}
  bool operator<(const DoubleEps &rhs) const {return this->value - rhs.value < -eps;}
  bool operator<=(const DoubleEps &rhs) const {return this->value - rhs.value < eps;}
  bool operator>(const DoubleEps &rhs) const {return !(*this <= rhs);}
  bool operator>=(const DoubleEps &rhs) const {return !(*this < rhs);}

  auto operator-() const {return DoubleEps(-(this->value));}
  
  explicit operator double() const noexcept {return value;}
  explicit operator long double() const noexcept {return value;}

  friend std::ostream& operator<<(std::ostream &s, const DoubleEps &rhs){s << rhs.value; return s;}
  friend std::istream& operator>>(std::istream &s, DoubleEps &rhs){s >> rhs.value; return s;}
};

template <typename T> T DoubleEps<T>::eps;

namespace std{
  template <typename T>
  class numeric_limits<DoubleEps<T>>{
  public:
    static DoubleEps<T> infinity() {return numeric_limits<T>::infinity();}
    static DoubleEps<T> min() {return numeric_limits<T>::min();}
    static DoubleEps<T> max() {return numeric_limits<T>::max();}
    static DoubleEps<T> lowest() {return numeric_limits<T>::lowest();}
  };
}
#line 3 "Mylib/Geometry/Float/geometry_template.cpp"
#include <cmath>
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
#line 4 "Mylib/Geometry/Float/distance_line_point.cpp"

/**
 * @title 直線と点間の距離
 * @docs distance_line_point.md
 */
template <typename T, typename U = typename T::value_type>
T distance_line_point(const Line<T> &l, const Point<T> &p){
  return std::fabs((U)(cross(l.diff(),p - l.from) / l.size()));
}
#line 6 "Mylib/Geometry/Float/intersect_circle_line.cpp"

/**
 * @title 円と直線の交差
 * @docs intersect_circle_line.md
 */
namespace intersect_circle_line{
  enum Status{
              OUTSIDE = 0b001,
              TANGENT = 0b010,
              CROSSED = 0b100
  };

  template <typename T>
  struct Result{
    Status status;
    std::vector<Point<T>> crosspoints;
  };
  
  template <typename T, typename U = typename T::value_type>
  auto check(const Circle<T> &c, const Line<T> &l){
    Result<T> ret;
    
    const T d = distance_line_point(l, c.center);

    if(d > c.radius){
      ret.status = OUTSIDE;
      return ret;
    }

    const auto n = normal(l.diff());
    const auto b = l.from + l.diff() * cross(n, c.center + n - l.from) / cross(n, l.diff());

    if(d == c.radius){
      ret.crosspoints.emplace_back(b);
      ret.status = TANGENT;
      return ret;
    }
    
    const T a = std::sqrt((U)(c.radius * c.radius - d * d));
    ret.crosspoints.emplace_back(b + unit(l.diff()) * a);
    ret.crosspoints.emplace_back(b - unit(l.diff()) * a);
    ret.status = CROSSED;
    return ret;
  }
}
#line 11 "test/aoj/CGL_7_D/main.test.cpp"

using D = DoubleEps<double>;
template<> double D::eps = 1e-7;

int main(){
  Circle<D> c;
  std::cin >> c.center >> c.radius;

  int q; std::cin >> q;

  while(q--){
    Point<D> p0, p1; std::cin >> p0 >> p1;
    Line<D> l(p0, p1);

    auto [s, ans] = intersect_circle_line::check(c, l);
    
    std::sort(ans.begin(), ans.end(), [](const auto &a, const auto &b){return a.x < b.x or (a.x == b.x and a.y < b.y);});

    std::cout << std::fixed << std::setprecision(12);

    if(s == intersect_circle_line::TANGENT){
      std::cout << ans[0].x << " " << ans[0].y << " ";
      std::cout << ans[0].x << " " << ans[0].y << std::endl;
    }else if(s == intersect_circle_line::CROSSED){
      std::cout << ans[0].x << " " << ans[0].y << " ";
      std::cout << ans[1].x << " " << ans[1].y << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

