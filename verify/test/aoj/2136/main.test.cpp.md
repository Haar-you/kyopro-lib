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
    - Last commit date: 2020-06-03 05:13:49+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2136">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2136</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/ccw.cpp.html">Check clockwise-counterclockwise</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/double_eps.cpp.html">Floating point number with eps</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/geometry_template.cpp.html">Geometry template</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Geometry/Float/intersect_segments.cpp.html">Intersection between two lines</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/Coloring/chromatic_number.cpp.html">Graph vertex coloring</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/IO/input_tuples_with_index.cpp.html">Mylib/IO/input_tuples_with_index.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Mod/mod_power.cpp.html">Mod power</a>


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
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples_with_index.cpp"

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

    for(auto [i, S] : input_tuples_with_index<int>(N)){
      lines[i] = input_vector<Point<D>>(S);
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

#line 5 "Mylib/Geometry/Float/geometry_template.cpp"

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
#line 5 "Mylib/Geometry/Float/intersect_segments.cpp"

/**
 * @title Intersection between two lines
 * @docs intersect_segments.md
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

  template <typename T>
  auto check(const Segment<T> &a, const Segment<T> &b){
    const T cr = cross(a, b);

    if(abs(cr) == 0){ // parallel
      if(ccw::ccw(a.from, a.to, b.from) * ccw::ccw(a.from, a.to, b.to) <= 0 and
         ccw::ccw(b.from, b.to, a.from) * ccw::ccw(b.from, b.to, a.to) <= 0){
        return Result<T>({OVERLAPPED, {}});
      }else{
        return Result<T>({NOT_INTERSECTING, {}});
      }
    }

    const T t1 = cross(b.from - a.from, diff(b)) / cr;
    const T t2 = cross(b.from - a.from, diff(a)) / cr;

    if(t1 < 0 or t1 > 1 or t2 < 0 or t2 > 1){ // no crosspoint
      return Result<T>({NOT_INTERSECTING, {}});
    }

    return Result<T>({INTERSECTING, {a.from + diff(a) * t1}});
  }
}
#line 2 "Mylib/Number/Mod/mod_power.cpp"

/**
 * @title Mod power
 * @docs mod_power.md
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
 * @title Graph vertex coloring
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
#line 4 "Mylib/IO/input_tuples_with_index.cpp"
#include <tuple>
#include <utility>
#include <initializer_list>
#line 5 "Mylib/IO/input_tuple.cpp"
#include <initializer_list>

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());
  return s;
}
#line 8 "Mylib/IO/input_tuples_with_index.cpp"

/**
 * @docs input_tuples_with_index.md
 */
template <typename ... Args>
class InputTuplesWithIndex{
  struct iter{
    using value_type = std::tuple<int, Args ...>;
    value_type value;
    bool fetched = false;
    int N;
    int c = 0;

    value_type operator*(){
      if(not fetched){
        std::tuple<Args ...> temp; std::cin >> temp;
        value = std::tuple_cat(std::make_tuple(c), temp);
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
  InputTuplesWithIndex(int N): N(N){}

  iter begin() const {return iter(N);}
  iter end() const {return iter(N);}
};

template <typename ... Args>
auto input_tuples_with_index(int N){
  return InputTuplesWithIndex<Args ...>(N);
}

#line 12 "test/aoj/2136/main.test.cpp"

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

    for(auto [i, S] : input_tuples_with_index<int>(N)){
      lines[i] = input_vector<Point<D>>(S);
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

