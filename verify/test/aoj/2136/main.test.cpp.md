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


# :heavy_check_mark: test/aoj/2136/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f1466abfa075f1547bf443d1976f4e75">test/aoj/2136</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/2136/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-30 00:04:32+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2136">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2136</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/ccw.cpp.html">clockwise-counterclockwise判定</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/double_eps.cpp.html">誤差許容浮動小数点数</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/geometry_template.cpp.html">幾何基本セット</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/intersect_segments.cpp.html">線分同士の交差</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/Coloring/chromatic_number.cpp.html">グラフ頂点彩色数</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Mod/mod_power.cpp.html">mod累乗</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2136"

#include <iostream>
#include <vector>

#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/intersect_segments.cpp"
#include "Mylib/Graph/Coloring/chromatic_number.cpp"

using D = DoubleEps<double>;
template <> double D::eps = 1e-7;

bool intersect(const std::vector<Point<D>> &a, const std::vector<Point<D>> &b){
  for(int i = 0; i < (int)a.size()-1; ++i){
    for(int j = 0; j < (int)b.size()-1; ++j){
      auto l1 = Line<D>(a[i], a[i+1]);
      auto l2 = Line<D>(b[j], b[j+1]);
      if(intersect_segments::check(l1, l2).status != intersect_segments::NOT_INTERSECTING){
        return true;
      }
    }
  }

  return false;
}

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N;

  while(std::cin >> N, N){
    std::vector<std::vector<Point<D>>> lines(N);

    for(int i = 0; i < N; ++i){
      int S; std::cin >> S;
      lines[i].resize(S);
      for(int j = 0; j < S; ++j){
        std::cin >> lines[i][j].x >> lines[i][j].y;
      }
    }

    std::vector<std::vector<int>> graph(N);
  
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < i; ++j){
        if(intersect(lines[i], lines[j])){
          graph[j].push_back(i);
          graph[i].push_back(j);
        }
      }
    }

    int ans = chromatic_number(graph);
    std::cout << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/2136/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2136"

#include <iostream>
#include <vector>

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
#line 3 "Mylib/Geometry/Float/ccw.cpp"

/**
 * @title clockwise-counterclockwise判定
 */
namespace ccw{
  enum CCW{
           ONLINE_BACK       = -2,
           COUNTER_CLOCKWISE = -1,
           ON_SEGMENT        = 0,
           CLOCKWISE         = 1,
           ONLINE_FRONT      = 2
  };

  template <typename T>
  CCW ccw(const Point<T> &p0, const Point<T> &p1, const Point<T> &p2){
    const T cr = cross(p1-p0, p2-p0);
    const T d = dot(p1-p0, p2-p0);

    if(cr == 0){
      if(d < 0) return ONLINE_BACK;
      else if((p2-p0).size() > (p1-p0).size()) return ONLINE_FRONT;
      else return ON_SEGMENT;
    }else if(cr > 0){
      return COUNTER_CLOCKWISE;
    }else{
      return CLOCKWISE;
    }
  }
}
#line 6 "Mylib/Geometry/Float/intersect_segments.cpp"

/**
 * @title 線分同士の交差
 * @see http://judge.u-aizu.ac.jp/onLinejudge/description.jsp?id=CGL_2_B
 */
namespace intersect_segments{
  enum Status{
              INTERSECTING     = 0b0001,
              OVERLAPPED       = 0b0010,
              NOT_INTERSECTING = 0b0100,
              SAME             = 0b1000
  };

  template <typename T>
  struct Result{
    Status status;
    std::vector<Point<T>> crosspoints;
  };

  template <typename T, typename U = typename T::value_type>
  auto check(const Segment<T> &a, const Segment<T> &b){
    Result<T> ret;
    
    T cr = cross(a.diff(), b.diff());

    if((T)std::abs((U)cr) == 0){ // parallel
      if(ccw::ccw(a.from, a.to, b.from) * ccw::ccw(a.from, a.to, b.to) <= 0 and
         ccw::ccw(b.from, b.to, a.from) * ccw::ccw(b.from, b.to, a.to) <= 0){
        ret.status = OVERLAPPED;
        return ret;
      }else{
        ret.status = NOT_INTERSECTING;
        return ret;
      }
    }

    T t1 = cross(b.from-a.from, b.diff()) / cr;
    T t2 = cross(b.from-a.from, a.diff()) / cr;

    if(t1 < 0 or t1 > 1 or t2 < 0 or t2 > 1){ // no crosspoint
      ret.status = NOT_INTERSECTING;
      return ret;
    }

    ret.crosspoints.emplace_back(a.from + a.diff() * t1);
    ret.status = INTERSECTING;
    return ret;
  }
}
#line 2 "Mylib/Number/Mod/mod_power.cpp"

/**
 * @title mod累乗
 */
int64_t power(int64_t n, int64_t p, int64_t m){
  int64_t ret = 1;
  while(p > 0){
    if(p & 1) (ret *= n) %= m;
    (n *= n) %= m;
    p >>= 1;
  }
  return ret;
}
#line 4 "Mylib/Graph/Coloring/chromatic_number.cpp"

/**
 * @title グラフ頂点彩色数
 * @docs chromatic_number.md
 */
int chromatic_number(const std::vector<std::vector<int>> &graph){
  const int mod = 1000000007;
  const int N = graph.size();
 
  std::vector<int> g(N);
  for(int i = 0; i < N; ++i){
    for(auto j : graph[i]){
      g[i] |= (1<<j);
    }
  }
  
  std::vector<int64_t> I(1<<N);
  I[0] = 1;
  for(int i = 1; i < (1<<N); ++i){
    int c = __builtin_ctz(i);
    I[i] = I[i-(1<<c)] + I[(i-(1<<c))&(~g[c])];
    if(I[i] >= mod) I[i] -= mod;
  }
  
  const auto check =
    [&](int k){
      int64_t t = 0;
      for(int i = 0; i < (1<<N); ++i){
        if(__builtin_popcount(i) % 2 == 1) t -= power(I[i],k,mod);
        else t += power(I[i],k,mod);
        if(t < 0) t += mod;
        if(t >= mod) t -= mod;
      }
      return (t % mod != 0);
    };
  
  int lb = 0, ub = N;
  while(abs(lb-ub) > 1){
    const auto mid = (lb+ub)/2;
 
    if(check(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  
  return ub;
}
#line 10 "test/aoj/2136/main.test.cpp"

using D = DoubleEps<double>;
template <> double D::eps = 1e-7;

bool intersect(const std::vector<Point<D>> &a, const std::vector<Point<D>> &b){
  for(int i = 0; i < (int)a.size()-1; ++i){
    for(int j = 0; j < (int)b.size()-1; ++j){
      auto l1 = Line<D>(a[i], a[i+1]);
      auto l2 = Line<D>(b[j], b[j+1]);
      if(intersect_segments::check(l1, l2).status != intersect_segments::NOT_INTERSECTING){
        return true;
      }
    }
  }

  return false;
}

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N;

  while(std::cin >> N, N){
    std::vector<std::vector<Point<D>>> lines(N);

    for(int i = 0; i < N; ++i){
      int S; std::cin >> S;
      lines[i].resize(S);
      for(int j = 0; j < S; ++j){
        std::cin >> lines[i][j].x >> lines[i][j].y;
      }
    }

    std::vector<std::vector<int>> graph(N);
  
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < i; ++j){
        if(intersect(lines[i], lines[j])){
          graph[j].push_back(i);
          graph[i].push_back(j);
        }
      }
    }

    int ans = chromatic_number(graph);
    std::cout << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

