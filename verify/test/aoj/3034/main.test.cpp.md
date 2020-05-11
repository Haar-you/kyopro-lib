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


# :heavy_check_mark: test/aoj/3034/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#607ede2caa7064ff1cf75c22fd3209d4">test/aoj/3034</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/3034/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-11 12:02:00+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3034">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3034</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Bit/for_each_subset_asc.cpp.html">Mylib/Bit/for_each_subset_asc.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/circumscribed_circle_of_triangle.cpp.html">三角形の外接円</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/double_eps.cpp.html">誤差許容浮動小数点数</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/geometry_template.cpp.html">幾何基本セット</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/minimum_covering_circle.cpp.html">最小包含円</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Misc/fix_point.cpp.html">不動点コンビネータ</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3034"
#define ERROR 1e-3

#include <iostream>
#include <iomanip>
#include <vector>

#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/minimum_covering_circle.cpp"
#include "Mylib/Misc/fix_point.cpp"
#include "Mylib/Bit/for_each_subset_asc.cpp"

using D = DoubleEps<double>;
template <> double D::eps = ERROR;

D dp[15][1<<14];
bool check[15][1<<14];

const D INF = 1e9;

int main(){
  int N, M; std::cin >> N >> M;

  std::vector<Point<D>> ps(N);
  for(int i = 0; i < N; ++i) std::cin >> ps[i];

  const int mask = (1 << N) - 1;

  std::vector<double> memo(1 << N);

  for(int t = 0; t < (1 << N); ++t){  
    std::vector<Point<D>> q;
    for(int i = 0; i < N; ++i){
      if(t & (1 << i)) q.push_back(ps[i]);
    }
    memo[t] = (double)minimum_covering_circle(q).radius;
  }  

  auto rec =
    make_fix_point([&](auto &&rec, int d, int s) -> D{
                     if(d == M){
                       if(s != 0) return dp[d][s] = INF;
                       return dp[d][s] = 0;
                     }

                     if(check[d][s]) return dp[d][s];
                     check[d][s] = true;

                     D ret = INF;

                     for_each_subset_asc(s,
                                         [&](int t){
                                           
                                           D val = std::max((double)rec(d+1, s^t), memo[t]);
                                           ret = std::min((double)ret, (double)val);
                                         });

                     return dp[d][s] = ret;
                   });

  auto ans = rec(0, mask);

  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/3034/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3034"
#define ERROR 1e-3

#include <iostream>
#include <iomanip>
#include <vector>

#line 3 "Mylib/Geometry/Float/geometry_template.cpp"
#include <cmath>
#line 5 "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 幾何基本セット
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

template <typename T> DoubleEps<T> sin(DoubleEps<T> x){return std::sin((T)x);}
template <typename T> DoubleEps<T> cos(DoubleEps<T> x){return std::cos((T)x);}
template <typename T> DoubleEps<T> tan(DoubleEps<T> x){return std::tan((T)x);}

template <typename T> DoubleEps<T> acos(DoubleEps<T> x){return std::acos((T)x);}
template <typename T> DoubleEps<T> atan2(DoubleEps<T> y, DoubleEps<T> x){return std::atan2((T)y, (T)x);}

template <typename T> DoubleEps<T> abs(DoubleEps<T> x){return std::abs((T)x);}

template <typename T> DoubleEps<T> sqrt(DoubleEps<T> x){return std::sqrt((T)x);}

#line 3 "Mylib/Geometry/Float/minimum_covering_circle.cpp"
#include <random>
#include <algorithm>
#line 3 "Mylib/Geometry/Float/circumscribed_circle_of_triangle.cpp"

/**
 * @title 三角形の外接円
 * @docs circumscribed_circle_of_triangle.md
 */
template <typename T>
Circle<T> circumscribed_circle_of_triangle(const Point<T> &a, const Point<T> &b, const Point<T> &c){
  const T A = abs_sq(b - c), B = abs_sq(a - c), C = abs_sq(a - b), S = A + B + C;
  const T x = sqrt(A), y = sqrt(B), z = sqrt(C), w = x + y + z;

  const T AA = A * (S - A * 2.0);
  const T BB = B * (S - B * 2.0);
  const T CC = C * (S - C * 2.0);

  return Circle<T>(
    (AA * a + BB * b + CC * c) / (AA + BB + CC),
    x * y * z / sqrt(w * (w - x * 2.0) * (w - y * 2.0) * (w - z * 2.0))
  );
}
#line 6 "Mylib/Geometry/Float/minimum_covering_circle.cpp"

/**
 * @title 最小包含円
 * @docs minimum_covering_circle.md
 */
template <typename T>
Circle<T> minimum_covering_circle(std::vector<Point<T>> ps, int seed = 0){
  if(ps.empty()) return Circle<T>();
  if(ps.size() == 1) return Circle<T>(ps[0], 0);

  const int N = ps.size();

  std::mt19937 rand(seed);
  std::shuffle(ps.begin(), ps.end(), rand);

  auto make_circle_2 = [&](const auto &p, const auto &q){
                    const auto c = (p + q) / 2.0;
                    return Circle<T>(c, abs(p - c));
                  };


  auto check = [](const auto &p, const auto &c){
                 return abs(c.center - p) <= c.radius;
               };


  Circle<T> ret = make_circle_2(ps[0], ps[1]);
  
  for(int i = 2; i < N; ++i){
    if(check(ps[i], ret)) continue;

    ret = make_circle_2(ps[0], ps[i]);

    for(int j = 1; j < i; ++j){
      if(check(ps[j], ret)) continue;

      ret = make_circle_2(ps[i], ps[j]);

      for(int k = 0; k < j; ++k){
        if(check(ps[k], ret)) continue;
        if(i == j or j == k or k == i) continue;

        ret = circumscribed_circle_of_triangle(ps[i], ps[j], ps[k]);
      }
    }
  }

  return ret;
}
#line 2 "Mylib/Misc/fix_point.cpp"
#include <utility>

/**
 * @title 不動点コンビネータ
 * @docs fix_point.md
 */
template <typename F>
struct FixPoint : F{
  explicit constexpr FixPoint(F &&f) noexcept : F(std::forward<F>(f)){}

  template <typename... Args>
  constexpr decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

template <typename F>
static inline constexpr decltype(auto) make_fix_point(F &&f){
  return FixPoint<F>(std::forward<F>(f));
}

template <typename F>
static inline constexpr decltype(auto) make_fix_point(F &f){
  return FixPoint<F>(std::forward<F>(f));
}
#line 2 "Mylib/Bit/for_each_subset_asc.cpp"

/**
 * @docs for_each_subset_asc.md
 */
template <typename Func>
void for_each_subset_asc(int a, const Func &f){
  for(int t=0; ; t=(t-a)&a){
    f(t);
    if(t==a) break;
  }
}
#line 13 "test/aoj/3034/main.test.cpp"

using D = DoubleEps<double>;
template <> double D::eps = ERROR;

D dp[15][1<<14];
bool check[15][1<<14];

const D INF = 1e9;

int main(){
  int N, M; std::cin >> N >> M;

  std::vector<Point<D>> ps(N);
  for(int i = 0; i < N; ++i) std::cin >> ps[i];

  const int mask = (1 << N) - 1;

  std::vector<double> memo(1 << N);

  for(int t = 0; t < (1 << N); ++t){  
    std::vector<Point<D>> q;
    for(int i = 0; i < N; ++i){
      if(t & (1 << i)) q.push_back(ps[i]);
    }
    memo[t] = (double)minimum_covering_circle(q).radius;
  }  

  auto rec =
    make_fix_point([&](auto &&rec, int d, int s) -> D{
                     if(d == M){
                       if(s != 0) return dp[d][s] = INF;
                       return dp[d][s] = 0;
                     }

                     if(check[d][s]) return dp[d][s];
                     check[d][s] = true;

                     D ret = INF;

                     for_each_subset_asc(s,
                                         [&](int t){
                                           
                                           D val = std::max((double)rec(d+1, s^t), memo[t]);
                                           ret = std::min((double)ret, (double)val);
                                         });

                     return dp[d][s] = ret;
                   });

  auto ans = rec(0, mask);

  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

