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


# :x: test/aoj/CGL_1_C/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#18b84890c49e1ab80d89d6f632360811">test/aoj/CGL_1_C</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/CGL_1_C/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C</a>


## Depends on

* :question: <a href="../../../../library/Mylib/Geometry/Float/ccw.cpp.html">Check clockwise-counterclockwise</a>
* :question: <a href="../../../../library/Mylib/Geometry/Float/double_eps.cpp.html">Floating point number with eps</a>
* :question: <a href="../../../../library/Mylib/Geometry/Float/geometry_template.cpp.html">Geometry template</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"

#include <iostream>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/ccw.cpp"
#include "Mylib/IO/input_tuples.cpp"

using D = DoubleEps<double>;
template<> double D::eps = 1e-7;

int main(){
  Point<D> p0, p1; std::cin >> p0 >> p1;

  int q; std::cin >> q;

  for(auto [p2] : input_tuples<Point<D>>(q)){
    switch(ccw::ccw(p0, p1, p2)){
    case ccw::ONLINE_BACK: std::cout << "ONLINE_BACK" << std::endl; break;
    case ccw::COUNTER_CLOCKWISE: std::cout << "COUNTER_CLOCKWISE" << std::endl; break;
    case ccw::ON_SEGMENT: std::cout << "ON_SEGMENT" << std::endl; break;
    case ccw::CLOCKWISE: std::cout << "CLOCKWISE" << std::endl; break;
    case ccw::ONLINE_FRONT: std::cout << "ONLINE_FRONT" << std::endl; break;
    }
  }
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/CGL_1_C/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"

#include <iostream>
#line 3 "Mylib/Geometry/Float/geometry_template.cpp"
#include <cmath>
#include <vector>

/**
 * @title Geometry template
 * @docs geometry_template.md
 */

template <typename T>
struct Vec{
  T x, y;
  Vec(){}
  Vec(T x, T y): x(x), y(y){}

  friend auto operator+(const Vec &a, const Vec &b){return Vec(a.x + b.x, a.y + b.y);}
  friend auto operator-(const Vec &a, const Vec &b){return Vec(a.x - b.x, a.y - b.y);}
  friend auto operator-(const Vec &a){return Vec(-a.x, -a.y);}

  friend bool operator==(const Vec &a, const Vec &b){return a.x == b.x and a.y == b.y;}
  friend bool operator!=(const Vec &a, const Vec &b){return !(a==b);}
  friend bool operator<(const Vec &a, const Vec &b){return a.x < b.x or (a.x == b.x and a.y < b.y);}
  
  friend std::istream& operator>>(std::istream &s, Vec &a){
    s >> a.x >> a.y; return s;
  }
};

template <typename T, typename U> auto operator*(const Vec<T> &a, const U &k){return Vec<T>(a.x * k, a.y * k);}
template <typename T, typename U> auto operator*(const U &k, const Vec<T> &a){return Vec<T>(a.x * k, a.y * k);}
template <typename T, typename U> auto operator/(const Vec<T> &a, const U &k){return Vec<T>(a.x / k, a.y / k);}

template <typename T> using Point = Vec<T>;

template <typename T> T abs(const Vec<T> &a){return sqrt(a.x * a.x + a.y * a.y);}
template <typename T> T abs_sq(const Vec<T> &a){return a.x * a.x + a.y * a.y;}

template <typename T> T dot(const Vec<T> &a, const Vec<T> &b){return a.x * b.x + a.y * b.y;}
template <typename T> T cross(const Vec<T> &a, const Vec<T> &b){return a.x * b.y - a.y * b.x;}

template <typename T> auto unit(const Vec<T> &a){return a / abs(a);}
template <typename T> auto normal(const Vec<T> &p){return Vec<T>(-p.y, p.x);}

template <typename T> auto polar(const T &r, const T &ang){return Vec<T>(r * cos(ang), r * sin(ang));}

template <typename T> T angle(const Vec<T> &a, const Vec<T> &b){return atan2(b.y - a.y, b.x - a.x);}
template <typename T> T phase(const Vec<T> &a){return atan2(a.y, a.x);}

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
};

template <typename T> using Segment = Line<T>;


template <typename T> auto unit(const Line<T> &a){return unit(a.to - a.from);}
template <typename T> auto normal(const Line<T> &a){return normal(a.to - a.from);}

template <typename T> auto diff(const Segment<T> &a){return a.to - a.from;}

template <typename T> T abs(const Segment<T> &a){return abs(diff(a));}

template <typename T> T dot(const Line<T> &a, const Line<T> &b){return dot(diff(a), diff(b));}
template <typename T> T cross(const Line<T> &a, const Line<T> &b){return cross(diff(a), diff(b));}


template <typename T> using Polygon = std::vector<Point<T>>;

template <typename T> struct Circle{
  Point<T> center;
  T radius;
  Circle(): center(), radius(0){}
  Circle(const Point<T> &center, T radius): center(center), radius(radius){}
};
#line 3 "Mylib/Geometry/Float/double_eps.cpp"
#include <limits>
#line 5 "Mylib/Geometry/Float/double_eps.cpp"

/**
 * @title Floating point number with eps
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

template <typename T> DoubleEps<T> sin(DoubleEps<T> x){return std::sin((T)x);}
template <typename T> DoubleEps<T> cos(DoubleEps<T> x){return std::cos((T)x);}
template <typename T> DoubleEps<T> tan(DoubleEps<T> x){return std::tan((T)x);}

template <typename T> DoubleEps<T> acos(DoubleEps<T> x){return std::acos((T)x);}
template <typename T> DoubleEps<T> atan2(DoubleEps<T> y, DoubleEps<T> x){return std::atan2((T)y, (T)x);}

template <typename T> DoubleEps<T> abs(DoubleEps<T> x){return std::abs((T)x);}

template <typename T> DoubleEps<T> sqrt(DoubleEps<T> x){return std::sqrt((T)x);}

#line 3 "Mylib/Geometry/Float/ccw.cpp"

/**
 * @title Check clockwise-counterclockwise
 * @docs ccw.md
 */
namespace ccw{
  enum Status{
           ONLINE_BACK       = -2,
           COUNTER_CLOCKWISE = -1,
           ON_SEGMENT        = 0,
           CLOCKWISE         = 1,
           ONLINE_FRONT      = 2
  };

  template <typename T>
  Status ccw(const Point<T> &p0, const Point<T> &p1, const Point<T> &p2){
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
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#include <utility>
#include <initializer_list>

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples{
  template <typename T, size_t ... I>
  static void input_tuple_helper(T &val, std::index_sequence<I...>){
    (void)std::initializer_list<int>{(void(std::cin >> std::get<I>(val)), 0)...};
  }
  
  struct iter{
    using value_type = std::tuple<Args ...>;
    value_type value;
    bool get = false;
    int N;
    int c = 0;

    value_type operator*(){
      if(get) return value;
      else{
        input_tuple_helper(value, std::make_index_sequence<sizeof...(Args)>());
        return value;
      }
    }

    void operator++(){
      ++c;
      get = false;
    }

    bool operator!=(iter &) const {
      return c < N;
    }

    iter(int N): N(N){}
  };

  int N;

public:
  InputTuples(int N): N(N){}

  iter begin() const {return iter(N);}
  iter end() const {return iter(N);}
};

template <typename ... Args>
auto input_tuples(int N){
  return InputTuples<Args ...>(N);
}
#line 8 "test/aoj/CGL_1_C/main.test.cpp"

using D = DoubleEps<double>;
template<> double D::eps = 1e-7;

int main(){
  Point<D> p0, p1; std::cin >> p0 >> p1;

  int q; std::cin >> q;

  for(auto [p2] : input_tuples<Point<D>>(q)){
    switch(ccw::ccw(p0, p1, p2)){
    case ccw::ONLINE_BACK: std::cout << "ONLINE_BACK" << std::endl; break;
    case ccw::COUNTER_CLOCKWISE: std::cout << "COUNTER_CLOCKWISE" << std::endl; break;
    case ccw::ON_SEGMENT: std::cout << "ON_SEGMENT" << std::endl; break;
    case ccw::CLOCKWISE: std::cout << "CLOCKWISE" << std::endl; break;
    case ccw::ONLINE_FRONT: std::cout << "ONLINE_FRONT" << std::endl; break;
    }
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

