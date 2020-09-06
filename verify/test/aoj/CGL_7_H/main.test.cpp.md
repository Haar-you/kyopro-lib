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


# :x: test/aoj/CGL_7_H/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#c934d03610ed9f5a73c21bd24c2c38a8">test/aoj/CGL_7_H</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/CGL_7_H/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 09:10:27+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Geometry/Float/area_intersection_of_circle_and_polygon.cpp.html">Area of intersection between a circle and a polygon</a>
* :x: <a href="../../../../library/Mylib/Geometry/Float/distance_segment_point.cpp.html">Distance between a segment and a point</a>
* :x: <a href="../../../../library/Mylib/Geometry/Float/double_eps.cpp.html">Floating point number with eps</a>
* :x: <a href="../../../../library/Mylib/Geometry/Float/geometry_template.cpp.html">Geometry template</a>
* :x: <a href="../../../../library/Mylib/Geometry/Float/intersect_circle_segment.cpp.html">Intersection between a circle and a segment</a>
* :x: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H"
#define ERROR 0.00001

#include <iostream>
#include <iomanip>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/area_intersection_of_circle_and_polygon.cpp"
#include "Mylib/IO/input_vector.cpp"

using D = DoubleEps<double>;
template <> double D::eps = ERROR;

int main(){
  int n; std::cin >> n;
  int r; std::cin >> r;

  Circle<D> c(Point<D>(0, 0), r);

  Polygon<D> p = input_vector<Point<D>>(n);

  auto ans = area_intersection_of_circle_and_polygon(c, p);

  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/CGL_7_H/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H"
#define ERROR 0.00001

#include <iostream>
#include <iomanip>
#line 3 "Mylib/Geometry/Float/double_eps.cpp"
#include <limits>
#include <cmath>

/**
 * @title Floating point number with eps
 * @docs double_eps.md
 */
template <typename T>
struct DoubleEps {
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

namespace std {
  template <typename T>
  class numeric_limits<DoubleEps<T>> {
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
#line 4 "Mylib/Geometry/Float/geometry_template.cpp"
#include <vector>

/**
 * @title Geometry template
 * @docs geometry_template.md
 */

template <typename T>
struct Vec {
  T x, y;
  Vec(){}
  Vec(T x, T y): x(x), y(y){}

  friend auto operator+(const Vec &a, const Vec &b){return Vec(a.x + b.x, a.y + b.y);}
  friend auto operator-(const Vec &a, const Vec &b){return Vec(a.x - b.x, a.y - b.y);}
  friend auto operator-(const Vec &a){return Vec(-a.x, -a.y);}

  friend bool operator==(const Vec &a, const Vec &b){return a.x == b.x and a.y == b.y;}
  friend bool operator!=(const Vec &a, const Vec &b){return !(a == b);}
  friend bool operator<(const Vec &a, const Vec &b){return a.x < b.x or (a.x == b.x and a.y < b.y);}

  friend std::istream& operator>>(std::istream &s, Vec &a){
    s >> a.x  >> a.y; return s;
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


template <typename T> struct Line {
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

template <typename T> struct Circle {
  Point<T> center;
  T radius;
  Circle(): center(), radius(0){}
  Circle(const Point<T> &center, T radius): center(center), radius(radius){}
};
#line 3 "Mylib/Geometry/Float/distance_segment_point.cpp"

/**
 * @title Distance between a segment and a point
 * @docs distance_segment_point.md
 */
template <typename T>
T distance_segment_point(const Segment<T> &l, const Point<T> &p){
  if(dot(diff(l), p - l.from) < 0) return abs(p - l.from);
  if(dot(-diff(l), p - l.to) < 0) return abs(p - l.to);
  return abs(cross(diff(l), p - l.from)) / abs(l);
}
#line 5 "Mylib/Geometry/Float/intersect_circle_segment.cpp"

/**
 * @title Intersection between a circle and a segment
 * @docs intersect_circle_segment.md
 */
namespace intersect_circle_segment {
  enum Status {
              INSIDE         = 0b00001,
              OUTSIDE        = 0b00010,
              TANGENT        = 0b00100,
              ONE_CROSSPOINT = 0b01000,
              TWO_CROSSPOINT = 0b10000
  };

  template <typename T>
  struct Result {
    Status status;
    std::vector<Point<T>> crosspoints;
  };

  template <typename T>
  auto check(const Circle<T> &cl, const Line<T> &s){
    const T r = cl.radius;
    const auto &c = cl.center;

    const T d1 = abs(c - s.from);
    const T d2 = abs(c - s.to);
    const T v = distance_segment_point(s, c);
    const T m = sqrt(r * r - v * v);
    const auto n = normal(s);
    const auto k = s.from + diff(s) * cross(n, c + n - s.from) / cross(n, diff(s));

    if(d1 < r and d2 < r){
      return Result<T>({INSIDE, {}});
    }
    else if(v == r){
      return Result<T>({TANGENT, {k}});
    }
    else if(v > r){
      return Result<T>({OUTSIDE, {}});
    }
    else if(d1 >= r and d2 >= r){
      return Result<T>({TWO_CROSSPOINT, {k - unit(s) * m, k + unit(s) * m}});
    }

    const T b = dot(unit(s), s.from - c);
    const T a = abs_sq(s.from - c) - r * r;
    const T x = sqrt(b * b - a);

    return Result<T>({ONE_CROSSPOINT, {s.from + unit(s) * (-b - x >= 0 ? -b - x : -b + x)}});
  }
};
#line 5 "Mylib/Geometry/Float/area_intersection_of_circle_and_polygon.cpp"

/**
 * @title Area of intersection between a circle and a polygon
 * @docs area_intersection_of_circle_and_polygon.md
 */
template <typename T>
T area_intersection_of_circle_and_polygon(const Circle<T> &cl, const Polygon<T> &ps){
  const int n = ps.size();
  T ret = 0;

  for(int i = 0; i < n; ++i){
    T temp = 0;

    const T r = cl.radius;
    const auto &c = cl.center;

    const auto &p1 = ps[i];
    const auto &p2 = ps[(i + 1) % n];

    const auto [t, res] = intersect_circle_segment::check(cl, Line<T>(p1, p2));

    const T d1 = abs(p1 - c);
    const T d2 = abs(p2 - c);

    if(res.size() == 0){
      if(t == intersect_circle_segment::INSIDE){ // if inside
        temp += cross(p1 - c, p2 - c) / 2;
      }else{ // if outside
        temp += r * r * angle_diff(p1 - c, p2 - c) / 2;
      }
    }else if(res.size() == 1){
      const auto &q = res[0];
      if(d1 >= r and d2 >= r){
        temp += r * r * angle_diff(p1 - c, p2 - c) / 2;
      }else if(d1 >= r){
        temp += r * r * angle_diff(p1 - c, q - c) / 2 + cross(q - c, p2 - c) / 2;
      }else{
        temp += cross(p1 - c, q - c) / 2 + r * r * angle_diff(q - c, p2 - c) / 2;
      }
    }else{
      const auto &q1 = res[0];
      const auto &q2 = res[1];
      temp +=
        r * r * angle_diff(p1 - c, q1 - c) / 2 +
        cross(q1 - c, q2 - c) / 2 +
        r * r * angle_diff(q2 - c, p2 - c) / 2;
    }

    ret += temp;
  }

  return ret;
}
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
template <typename T>
std::vector<T> input_vector(int N){
  std::vector<T> ret(N);
  for(int i = 0; i < N; ++i) std::cin >> ret[i];
  return ret;
}

template <typename T>
std::vector<std::vector<T>> input_vector(int N, int M){
  std::vector<std::vector<T>> ret(N);
  for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);
  return ret;
}
#line 10 "test/aoj/CGL_7_H/main.test.cpp"

using D = DoubleEps<double>;
template <> double D::eps = ERROR;

int main(){
  int n; std::cin >> n;
  int r; std::cin >> r;

  Circle<D> c(Point<D>(0, 0), r);

  Polygon<D> p = input_vector<Point<D>>(n);

  auto ans = area_intersection_of_circle_and_polygon(c, p);

  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

