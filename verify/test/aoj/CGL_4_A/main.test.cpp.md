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


# :heavy_check_mark: test/aoj/CGL_4_A/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a269259367036c402826e762072de44f">test/aoj/CGL_4_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/CGL_4_A/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/convex_hull.cpp.html">Convex hull</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/double_eps.cpp.html">Floating point number with eps</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/geometry_template.cpp.html">Geometry template</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"

#include <iostream>
#include <algorithm>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/convex_hull.cpp"
#include "Mylib/IO/input_vector.cpp"

using D = DoubleEps<double>;
template<> double D::eps = 1e-7;

int main(){
  int n; std::cin >> n;
  Polygon<D> ps = input_vector<Point<D>>(n);

  auto ans = convex_hull(ps);
  
  std::cout << ans.size() << std::endl;

  {
    std::reverse(ans.begin(), ans.end());

    int k =
      std::min_element(
        ans.begin(), ans.end(),
        [](const auto &a, const auto &b){
          return a.y < b.y or (a.y == b.y and a.x < b.x);
        }
      ) - ans.begin();

    std::rotate(ans.begin(), ans.begin() + k, ans.end());
  }
  
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
#line 1 "test/aoj/CGL_4_A/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"

#include <iostream>
#include <algorithm>
#line 3 "Mylib/Geometry/Float/double_eps.cpp"
#include <limits>
#include <cmath>

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

#line 4 "Mylib/Geometry/Float/geometry_template.cpp"
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
#line 5 "Mylib/Geometry/Float/convex_hull.cpp"

/**
 * @title Convex hull
 * @docs convex_hull.md
 */
template <typename T> 
std::vector<Point<T>> upper_hull(Polygon<T> pts, bool upper = true){
  std::sort(
    pts.begin(),
    pts.end(),
    [](const auto &a, const auto &b){return a.x < b.x or (a.x == b.x and a.y < b.y);}
  );

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
#line 9 "test/aoj/CGL_4_A/main.test.cpp"

using D = DoubleEps<double>;
template<> double D::eps = 1e-7;

int main(){
  int n; std::cin >> n;
  Polygon<D> ps = input_vector<Point<D>>(n);

  auto ans = convex_hull(ps);
  
  std::cout << ans.size() << std::endl;

  {
    std::reverse(ans.begin(), ans.end());

    int k =
      std::min_element(
        ans.begin(), ans.end(),
        [](const auto &a, const auto &b){
          return a.y < b.y or (a.y == b.y and a.x < b.x);
        }
      ) - ans.begin();

    std::rotate(ans.begin(), ans.begin() + k, ans.end());
  }
  
  for(auto &p : ans){
    std::cout << p.x << " " << p.y << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
