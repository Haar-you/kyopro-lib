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
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Geometry/Float/area_intersection_of_circle_and_polygon.cpp.html">Area of intersection between a circle and a polygon</a>
* :x: <a href="../../../../library/Mylib/Geometry/Float/distance_segment_point.cpp.html">Distance between a segment and a point</a>
* :question: <a href="../../../../library/Mylib/Geometry/Float/double_eps.cpp.html">Floating point number with eps</a>
* :question: <a href="../../../../library/Mylib/Geometry/Float/geometry_template.cpp.html">Geometry template</a>
* :x: <a href="../../../../library/Mylib/Geometry/Float/intersect_circle_segment.cpp.html">Intersection between a circle and a segment</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


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

namespace hl = haar_lib;

using D = hl::double_eps<double>;
template <> double D::eps = ERROR;

int main(){
  int n; std::cin >> n;
  int r; std::cin >> r;

  hl::circle<D> c(hl::point<D>(0, 0), r);

  hl::polygon<D> p = hl::input_vector<hl::point<D>>(n);

  auto ans = hl::area_intersection_of_circle_and_polygon(c, p);

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
namespace haar_lib {
  template <typename T>
  struct double_eps {
    using value_type = T;

    static T eps;

    T value;

    double_eps(): value(0){}
    double_eps(T value): value(value){}

    auto& operator=(const double_eps &rhs){this->value = rhs.value; return *this;}
    auto& operator+=(const double_eps &rhs){this->value += rhs.value; return *this;}
    auto& operator-=(const double_eps &rhs){this->value -= rhs.value; return *this;}
    auto& operator*=(const double_eps &rhs){this->value *= rhs.value; return *this;}
    auto& operator/=(const double_eps &rhs){this->value /= rhs.value; return *this;}

    auto operator+(const double_eps &rhs) const {return double_eps(this->value + rhs.value);}
    auto operator-(const double_eps &rhs) const {return double_eps(this->value - rhs.value);}
    auto operator*(const double_eps &rhs) const {return double_eps(this->value * rhs.value);}
    auto operator/(const double_eps &rhs) const {return double_eps(this->value / rhs.value);}

    bool operator==(const double_eps &rhs) const {return std::abs(this->value - rhs.value) < eps;}
    bool operator!=(const double_eps &rhs) const {return !(*this == rhs);}
    bool operator<(const double_eps &rhs) const {return this->value - rhs.value < -eps;}
    bool operator<=(const double_eps &rhs) const {return this->value - rhs.value < eps;}
    bool operator>(const double_eps &rhs) const {return !(*this <= rhs);}
    bool operator>=(const double_eps &rhs) const {return !(*this < rhs);}

    auto operator-() const {return double_eps(-(this->value));}

    explicit operator double() const noexcept {return value;}
    explicit operator long double() const noexcept {return value;}

    friend std::ostream& operator<<(std::ostream &s, const double_eps &rhs){s << rhs.value; return s;}
    friend std::istream& operator>>(std::istream &s, double_eps &rhs){s >> rhs.value; return s;}
  };

  template <typename T> T double_eps<T>::eps;


  template <typename T> double_eps<T> sin(double_eps<T> x){return std::sin((T)x);}
  template <typename T> double_eps<T> cos(double_eps<T> x){return std::cos((T)x);}
  template <typename T> double_eps<T> tan(double_eps<T> x){return std::tan((T)x);}

  template <typename T> double_eps<T> acos(double_eps<T> x){return std::acos((T)x);}
  template <typename T> double_eps<T> atan2(double_eps<T> y, double_eps<T> x){return std::atan2((T)y, (T)x);}

  template <typename T> double_eps<T> abs(double_eps<T> x){return std::abs((T)x);}

  template <typename T> double_eps<T> sqrt(double_eps<T> x){return std::sqrt((T)x);}
}

namespace std {
  template <typename T>
  class numeric_limits<haar_lib::double_eps<T>> {
  public:
    static haar_lib::double_eps<T> infinity() {return numeric_limits<T>::infinity();}
    static haar_lib::double_eps<T> min() {return numeric_limits<T>::min();}
    static haar_lib::double_eps<T> max() {return numeric_limits<T>::max();}
    static haar_lib::double_eps<T> lowest() {return numeric_limits<T>::lowest();}
  };
}
#line 4 "Mylib/Geometry/Float/geometry_template.cpp"
#include <vector>

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
#line 3 "Mylib/Geometry/Float/distance_segment_point.cpp"

/**
 * @title Distance between a segment and a point
 * @docs distance_segment_point.md
 */
namespace haar_lib {
  template <typename T>
  T distance_segment_point(const segment<T> &l, const point<T> &p){
    if(dot(diff(l), p - l.from) < 0) return abs(p - l.from);
    if(dot(-diff(l), p - l.to) < 0) return abs(p - l.to);
    return abs(cross(diff(l), p - l.from)) / abs(l);
  }
}
#line 5 "Mylib/Geometry/Float/intersect_circle_segment.cpp"

/**
 * @title Intersection between a circle and a segment
 * @docs intersect_circle_segment.md
 */
namespace haar_lib {
  namespace intersect_circle_segment {
    enum status_t {
                 INSIDE         = 0b00001,
                 OUTSIDE        = 0b00010,
                 TANGENT        = 0b00100,
                 ONE_CROSSPOINT = 0b01000,
                 TWO_CROSSPOINT = 0b10000
    };

    template <typename T>
    struct result {
      status_t status;
      std::vector<point<T>> crosspoints;
    };

    template <typename T>
    auto check(const circle<T> &cl, const line<T> &s){
      const T r = cl.radius;
      const auto &c = cl.center;

      const T d1 = abs(c - s.from);
      const T d2 = abs(c - s.to);
      const T v = distance_segment_point(s, c);
      const T m = sqrt(r * r - v * v);
      const auto n = normal(s);
      const auto k = s.from + diff(s) * cross(n, c + n - s.from) / cross(n, diff(s));

      if(d1 < r and d2 < r){
        return result<T>({INSIDE, {}});
      }
      else if(v == r){
        return result<T>({TANGENT, {k}});
      }
      else if(v > r){
        return result<T>({OUTSIDE, {}});
      }
      else if(d1 >= r and d2 >= r){
        return result<T>({TWO_CROSSPOINT, {k - unit(s) * m, k + unit(s) * m}});
      }

      const T b = dot(unit(s), s.from - c);
      const T a = abs_sq(s.from - c) - r * r;
      const T x = sqrt(b * b - a);

      return result<T>({ONE_CROSSPOINT, {s.from + unit(s) * (-b - x >= 0 ? -b - x : -b + x)}});
    }
  };
}
#line 5 "Mylib/Geometry/Float/area_intersection_of_circle_and_polygon.cpp"

/**
 * @title Area of intersection between a circle and a polygon
 * @docs area_intersection_of_circle_and_polygon.md
 */
namespace haar_lib {
  template <typename T>
  T area_intersection_of_circle_and_polygon(const circle<T> &cl, const polygon<T> &ps){
    const int n = ps.size();
    T ret = 0;

    for(int i = 0; i < n; ++i){
      T temp = 0;

      const T r = cl.radius;
      const auto &c = cl.center;

      const auto &p1 = ps[i];
      const auto &p2 = ps[(i + 1) % n];

      const auto [t, res] = intersect_circle_segment::check(cl, line<T>(p1, p2));

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
}
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
namespace haar_lib {
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
}
#line 10 "test/aoj/CGL_7_H/main.test.cpp"

namespace hl = haar_lib;

using D = hl::double_eps<double>;
template <> double D::eps = ERROR;

int main(){
  int n; std::cin >> n;
  int r; std::cin >> r;

  hl::circle<D> c(hl::point<D>(0, 0), r);

  hl::polygon<D> p = hl::input_vector<hl::point<D>>(n);

  auto ans = hl::area_intersection_of_circle_and_polygon(c, p);

  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
