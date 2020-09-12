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


# :x: test/aoj/CGL_2_A/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#739119862b576acc3a057a216570b792">test/aoj/CGL_2_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/CGL_2_A/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A</a>


## Depends on

* :question: <a href="../../../../library/Mylib/Geometry/Float/double_eps.cpp.html">Floating point number with eps</a>
* :question: <a href="../../../../library/Mylib/Geometry/Float/geometry_template.cpp.html">Geometry template</a>
* :x: <a href="../../../../library/Mylib/Geometry/Float/orthogonal.cpp.html">Orthogonal</a>
* :x: <a href="../../../../library/Mylib/Geometry/Float/parallel.cpp.html">Parallel</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A"

#include <iostream>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/parallel.cpp"
#include "Mylib/Geometry/Float/orthogonal.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

using D = hl::double_eps<double>;
template <> double D::eps = 1e-7;

int main(){
  int q; std::cin >> q;

  for(auto [p0, p1, p2, p3] : hl::input_tuples<hl::point<D>, hl::point<D>, hl::point<D>, hl::point<D>>(q)){
    hl::line<D> s1(p0, p1), s2(p2, p3);

    if(hl::parallel(s1, s2)){
      std::cout << 2 << std::endl;
    }else if(hl::orthogonal(s1, s2)){
      std::cout << 1 << std::endl;
    }else{
      std::cout << 0 << std::endl;
    }
  }
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/CGL_2_A/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A"

#include <iostream>
#line 3 "Mylib/Geometry/Float/geometry_template.cpp"
#include <cmath>
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
#line 3 "Mylib/Geometry/Float/double_eps.cpp"
#include <limits>
#line 5 "Mylib/Geometry/Float/double_eps.cpp"

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
#line 3 "Mylib/Geometry/Float/parallel.cpp"

/**
 * @title Parallel
 * @docs parallel.md
 */
namespace haar_lib {
  template <typename T>
  bool parallel(const line<T> &a, const line<T> &b){
    return abs(cross(a, b)) == 0;
  }
}
#line 3 "Mylib/Geometry/Float/orthogonal.cpp"

/**
 * @title Orthogonal
 * @docs orthogonal.md
 */
namespace haar_lib {
  template <typename T>
  bool orthogonal(const line<T> &a, const line<T> &b){
    return abs(dot(a, b)) == 0;
  }
}
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#include <utility>
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
namespace haar_lib {
  template <typename T, size_t ... I>
  static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){
    (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};
  }

  template <typename T, typename U>
  std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
    s >> value.first >> value.second;
    return s;
  }

  template <typename ... Args>
  std::istream& operator>>(std::istream &s, std::tuple<Args ...> &value){
    input_tuple_helper(s, value, std::make_index_sequence<sizeof ... (Args)>());
    return s;
  }
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
namespace haar_lib {
  template <typename ... Args>
  class InputTuples {
    struct iter {
      using value_type = std::tuple<Args ...>;
      value_type value;
      bool fetched = false;
      int N, c = 0;

      value_type operator*(){
        if(not fetched){
          std::cin >> value;
        }
        return value;
      }

      void operator++(){
        ++c;
        fetched = false;
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
}
#line 9 "test/aoj/CGL_2_A/main.test.cpp"

namespace hl = haar_lib;

using D = hl::double_eps<double>;
template <> double D::eps = 1e-7;

int main(){
  int q; std::cin >> q;

  for(auto [p0, p1, p2, p3] : hl::input_tuples<hl::point<D>, hl::point<D>, hl::point<D>, hl::point<D>>(q)){
    hl::line<D> s1(p0, p1), s2(p2, p3);

    if(hl::parallel(s1, s2)){
      std::cout << 2 << std::endl;
    }else if(hl::orthogonal(s1, s2)){
      std::cout << 1 << std::endl;
    }else{
      std::cout << 0 << std::endl;
    }
  }
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

