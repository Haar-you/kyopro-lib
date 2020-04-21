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
    - Last commit date: 2020-04-22 05:49:57+09:00


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
#line 3 "Mylib/Geometry/Float/minimum_covering_circle.cpp"
#include <random>
#include <algorithm>
#line 4 "Mylib/Geometry/Float/circumscribed_circle_of_triangle.cpp"

/**
 * @title 三角形の外接円
 */
template <typename T, typename U = typename T::value_type>
Circle<T> circumscribed_circle_of_triangle(const Point<T> &a, const Point<T> &b, const Point<T> &c){
  T A = (b-c).size_sq(), B = (a-c).size_sq(), C = (a-b).size_sq();
  T x = std::sqrt((U)A), y = std::sqrt((U)B), z = std::sqrt((U)C);

  return Circle<T>
    (
     (A*(B+C-A)*a + B*(C+A-B)*b + C*(A+B-C)*c) / (A*(B+C-A) + B*(C+A-B) + C*(A+B-C)),
     x * y * z / std::sqrt((U)((x+y+z)*(-x+y+z)*(x-y+z)*(x+y-z)))
     );
}
#line 6 "Mylib/Geometry/Float/minimum_covering_circle.cpp"

/**
 * @title 最小包含円
 * @see https://tubo28.me/compprog/algorithm/minball/
 * @see https://atcoder.jp/contests/abc151/tasks/abc151_f
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3034
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
                    return Circle<T>(c, (p - c).size());
                  };


  auto check = [](const auto &p, const auto &c){
                 return (c.center - p).size() <= c.radius;
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

