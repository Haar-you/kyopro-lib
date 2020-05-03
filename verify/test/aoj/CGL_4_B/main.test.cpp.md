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


# :heavy_check_mark: test/aoj/CGL_4_B/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#328617ce477603fe21039ae9cca6fb61">test/aoj/CGL_4_B</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/CGL_4_B/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/convex_diameter.cpp.html">凸多角形の直径</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/double_eps.cpp.html">誤差許容浮動小数点数</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/geometry_template.cpp.html">幾何基本セット</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B"
#define ERROR 0.000001

#include <iostream>
#include <iomanip>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/convex_diameter.cpp"

using D = DoubleEps<double>;
template<> double D::eps = ERROR;

int main(){
  int n; std::cin >> n;

  Polygon<D> g(n);
  for(int i = 0; i < n; ++i) std::cin >> g[i];

  auto ans = convex_diameter(g);

  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/CGL_4_B/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B"
#define ERROR 0.000001

#include <iostream>
#include <iomanip>
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
#line 2 "Mylib/Geometry/Float/convex_diameter.cpp"
#include <algorithm>
#line 4 "Mylib/Geometry/Float/convex_diameter.cpp"

/**
 * @title 凸多角形の直径
 * @docs convex_diameter.md
 */
template <typename T>
T convex_diameter(const Polygon<T> &ps){
  const int n = (int)ps.size();
  int i = std::min_element(ps.begin(), ps.end(), [](const auto &a, const auto &b){return a.y < b.y;}) - ps.begin();
  int j = std::max_element(ps.begin(), ps.end(), [](const auto &a, const auto &b){return a.y < b.y;}) - ps.begin();

  T ret = (ps[i]-ps[j]).size();

  for(int k = 0; k < 2*n; ++k){
    if(cross(ps[(i+1)%n]-ps[i], ps[(j+1)%n]-ps[j]) > 0){
      (++j) %= n;
    }else{
      (++i) %= n;
    }

    ret = std::max(ret, (ps[i]-ps[j]).size());
  }

  return ret;
}
#line 9 "test/aoj/CGL_4_B/main.test.cpp"

using D = DoubleEps<double>;
template<> double D::eps = ERROR;

int main(){
  int n; std::cin >> n;

  Polygon<D> g(n);
  for(int i = 0; i < n; ++i) std::cin >> g[i];

  auto ans = convex_diameter(g);

  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

