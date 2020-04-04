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


# :heavy_check_mark: test/aoj/CGL_7_G/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b5574cc7a831f026d52a6858b25848ce">test/aoj/CGL_7_G</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/CGL_7_G/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-04 13:11:51+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/common_tangent_of_circles.cpp.html">2円の共通接線</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/double_eps.cpp.html">誤差許容浮動小数点数</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/geometry_template.cpp.html">幾何基本セット</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G"
#define ERROR 0.00001

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/common_tangent_of_circles.cpp"

using D = DoubleEps<double>;
template<> double D::eps = ERROR;

int main(){
  Circle<D> c1, c2;
  std::cin >> c1.center >> c1.radius >> c2.center >> c2.radius;

  auto ans = common_tangent_of_circles(c1, c2);

  std::sort(ans.begin(), ans.end(),
            [](const auto &a, const auto &b){
              return a.x < b.x or (a.x == b.x and a.y < b.y);
            });

  std::cout << std::fixed << std::setprecision(12);
  
  for(auto &p : ans){
    std::cout << p.x << " " << p.y << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/CGL_7_G/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G"
#define ERROR 0.00001

#include <iostream>
#include <iomanip>
#include <algorithm>
#line 3 "Mylib/Geometry/Float/double_eps.cpp"
#include <limits>

/**
 * @title 誤差許容浮動小数点数
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
#include <vector>

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
#line 5 "Mylib/Geometry/Float/common_tangent_of_circles.cpp"

/**
 * @title 2円の共通接線
 * @note https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_G
 */
template <typename T, typename U = typename T::value_type>
std::vector<Point<T>> common_tangent_of_circles(const Circle<T> &a, const Circle<T> &b){
  const T d = (b.center - a.center).size();
  const auto n = unit(b.center - a.center);

  const auto cc = b.center - a.center;
  const T r = a.radius - b.radius;
  const T R = a.radius + b.radius;
  
  if(a.radius + b.radius == d){ // 一方が他方に外接している。
    return {
            a.center + (cc*r + normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + (cc*r - normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + n * a.radius
    };
  }else if(a.radius + b.radius < d){ // aとbは互いに離れている。
    return {
            a.center + (cc*r + normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + (cc*r - normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + (cc*R + normal(cc) * std::sqrt((U)(cc.size_sq()-R*R))) * a.radius / cc.size_sq(),
            a.center + (cc*R - normal(cc) * std::sqrt((U)(cc.size_sq()-R*R))) * a.radius / cc.size_sq()	    
    };
  }else if(a.radius + b.radius > d and d > (T)std::fabs((U)(a.radius - b.radius))){ // aとbは二点で交差している。
    return {
            a.center + (cc*r + normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq(),
            a.center + (cc*r - normal(cc) * std::sqrt((U)(cc.size_sq()-r*r))) * a.radius / cc.size_sq()	    
    };
  }else if((T)std::fabs((U)(a.radius - b.radius)) == d){ // 一方が他方に内接している。
    return {
            a.radius > b.radius ? a.center + n * a.radius : b.center - n * b.radius
    };
  }

  return {};
}
#line 10 "test/aoj/CGL_7_G/main.test.cpp"

using D = DoubleEps<double>;
template<> double D::eps = ERROR;

int main(){
  Circle<D> c1, c2;
  std::cin >> c1.center >> c1.radius >> c2.center >> c2.radius;

  auto ans = common_tangent_of_circles(c1, c2);

  std::sort(ans.begin(), ans.end(),
            [](const auto &a, const auto &b){
              return a.x < b.x or (a.x == b.x and a.y < b.y);
            });

  std::cout << std::fixed << std::setprecision(12);
  
  for(auto &p : ans){
    std::cout << p.x << " " << p.y << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

