---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Bit/enumerate_subsets_asc.cpp
    title: Enumerate subsets (Ascending order)
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/circumscribed_circle_of_triangle.cpp
    title: Circumscribed circle of a triangle
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/double_eps.cpp
    title: Floating point number with eps
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/geometry_template.cpp
    title: Geometry template
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/minimum_covering_circle.cpp
    title: Minimum covering circle
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':heavy_check_mark:'
    path: Mylib/Utils/fix_point.cpp
    title: Fixed point combinator
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-3
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3034
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3034
  bundledCode: "#line 1 \"test/aoj/3034/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3034\"\
    \n#define ERROR 1e-3\n\n#include <iostream>\n#include <iomanip>\n#include <vector>\n\
    #line 3 \"Mylib/Geometry/Float/geometry_template.cpp\"\n#include <cmath>\n#line\
    \ 5 \"Mylib/Geometry/Float/geometry_template.cpp\"\n\nnamespace haar_lib {\n \
    \ template <typename T>\n  struct vec {\n    T x, y;\n    vec(){}\n    vec(T x,\
    \ T y): x(x), y(y){}\n\n    friend auto operator+(const vec &a, const vec &b){return\
    \ vec(a.x + b.x, a.y + b.y);}\n    friend auto operator-(const vec &a, const vec\
    \ &b){return vec(a.x - b.x, a.y - b.y);}\n    friend auto operator-(const vec\
    \ &a){return vec(-a.x, -a.y);}\n\n    friend bool operator==(const vec &a, const\
    \ vec &b){return a.x == b.x and a.y == b.y;}\n    friend bool operator!=(const\
    \ vec &a, const vec &b){return !(a == b);}\n    friend bool operator<(const vec\
    \ &a, const vec &b){return a.x < b.x or (a.x == b.x and a.y < b.y);}\n\n    friend\
    \ std::istream& operator>>(std::istream &s, vec &a){\n      s >> a.x >> a.y; return\
    \ s;\n    }\n  };\n\n  template <typename T, typename U> auto operator*(const\
    \ vec<T> &a, const U &k){return vec<T>(a.x * k, a.y * k);}\n  template <typename\
    \ T, typename U> auto operator*(const U &k, const vec<T> &a){return vec<T>(a.x\
    \ * k, a.y * k);}\n  template <typename T, typename U> auto operator/(const vec<T>\
    \ &a, const U &k){return vec<T>(a.x / k, a.y / k);}\n\n  template <typename T>\
    \ using point = vec<T>;\n\n  template <typename T> T abs(const vec<T> &a){return\
    \ sqrt(a.x * a.x + a.y * a.y);}\n  template <typename T> T abs_sq(const vec<T>\
    \ &a){return a.x * a.x + a.y * a.y;}\n\n  template <typename T> T dot(const vec<T>\
    \ &a, const vec<T> &b){return a.x * b.x + a.y * b.y;}\n  template <typename T>\
    \ T cross(const vec<T> &a, const vec<T> &b){return a.x * b.y - a.y * b.x;}\n\n\
    \  template <typename T> auto unit(const vec<T> &a){return a / abs(a);}\n  template\
    \ <typename T> auto normal(const vec<T> &p){return vec<T>(-p.y, p.x);}\n\n  template\
    \ <typename T> auto polar(const T &r, const T &ang){return vec<T>(r * cos(ang),\
    \ r * sin(ang));}\n\n  template <typename T> T angle(const vec<T> &a, const vec<T>\
    \ &b){return atan2(b.y - a.y, b.x - a.x);}\n  template <typename T> T phase(const\
    \ vec<T> &a){return atan2(a.y, a.x);}\n\n  template <typename T>\n  T angle_diff(const\
    \ vec<T> &a, const vec<T> &b){\n    T r = phase(b) - phase(a);\n\n    if(r < -M_PI)\
    \ return r + 2 * M_PI;\n    else if(r > M_PI) return r - 2 * M_PI;\n    return\
    \ r;\n  }\n\n\n  template <typename T> struct line {\n    point<T> from, to;\n\
    \    line(): from(), to(){}\n    line(const point<T> &from, const point<T> &to):\
    \ from(from), to(to){}\n  };\n\n  template <typename T> using segment = line<T>;\n\
    \n\n  template <typename T> auto unit(const line<T> &a){return unit(a.to - a.from);}\n\
    \  template <typename T> auto normal(const line<T> &a){return normal(a.to - a.from);}\n\
    \n  template <typename T> auto diff(const segment<T> &a){return a.to - a.from;}\n\
    \n  template <typename T> T abs(const segment<T> &a){return abs(diff(a));}\n\n\
    \  template <typename T> T dot(const line<T> &a, const line<T> &b){return dot(diff(a),\
    \ diff(b));}\n  template <typename T> T cross(const line<T> &a, const line<T>\
    \ &b){return cross(diff(a), diff(b));}\n\n\n  template <typename T> using polygon\
    \ = std::vector<point<T>>;\n\n  template <typename T> struct circle {\n    point<T>\
    \ center;\n    T radius;\n    circle(): center(), radius(0){}\n    circle(const\
    \ point<T> &center, T radius): center(center), radius(radius){}\n  };\n\n  template\
    \ <typename T>\n  std::ostream& operator<<(std::ostream &s, const vec<T> &a){\n\
    \    s << \"(\" << a.x << \", \" << a.y << \")\";\n    return s;\n  }\n\n  template\
    \ <typename T>\n  std::ostream& operator<<(std::ostream &s, const line<T> &a){\n\
    \    s << \"(\" << a.from << \" -> \" << a.to << \")\";\n    return s;\n  }\n\n\
    \  template <typename T>\n  std::ostream& operator<<(std::ostream &s, const circle<T>\
    \ &a){\n    s << \"(\"\n      << \"center: \" << a.center << \", \"\n      <<\
    \ \"radius: \" << a.radius << \")\";\n    return s;\n  }\n}\n#line 3 \"Mylib/Geometry/Float/double_eps.cpp\"\
    \n#include <limits>\n#line 5 \"Mylib/Geometry/Float/double_eps.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T, const T &eps>\n  struct double_eps {\n \
    \   using value_type = T;\n\n  private:\n    T value_;\n\n  public:\n    double_eps():\
    \ value_(0){}\n    double_eps(T value_): value_(value_){}\n\n    auto& operator=(const\
    \ double_eps &rhs){this->value_ = rhs.value_; return *this;}\n    auto& operator+=(const\
    \ double_eps &rhs){this->value_ += rhs.value_; return *this;}\n    auto& operator-=(const\
    \ double_eps &rhs){this->value_ -= rhs.value_; return *this;}\n    auto& operator*=(const\
    \ double_eps &rhs){this->value_ *= rhs.value_; return *this;}\n    auto& operator/=(const\
    \ double_eps &rhs){this->value_ /= rhs.value_; return *this;}\n\n    auto operator+(const\
    \ double_eps &rhs) const {return double_eps(this->value_ + rhs.value_);}\n   \
    \ auto operator-(const double_eps &rhs) const {return double_eps(this->value_\
    \ - rhs.value_);}\n    auto operator*(const double_eps &rhs) const {return double_eps(this->value_\
    \ * rhs.value_);}\n    auto operator/(const double_eps &rhs) const {return double_eps(this->value_\
    \ / rhs.value_);}\n\n    bool operator==(const double_eps &rhs) const {return\
    \ std::abs(this->value_ - rhs.value_) < eps;}\n    bool operator!=(const double_eps\
    \ &rhs) const {return !(*this == rhs);}\n    bool operator<(const double_eps &rhs)\
    \ const {return this->value_ - rhs.value_ < -eps;}\n    bool operator<=(const\
    \ double_eps &rhs) const {return this->value_ - rhs.value_ < eps;}\n    bool operator>(const\
    \ double_eps &rhs) const {return !(*this <= rhs);}\n    bool operator>=(const\
    \ double_eps &rhs) const {return !(*this < rhs);}\n\n    auto operator-() const\
    \ {return double_eps(-(this->value_));}\n\n    explicit operator double() const\
    \ noexcept {return value_;}\n    explicit operator long double() const noexcept\
    \ {return value_;}\n\n    friend std::ostream& operator<<(std::ostream &s, const\
    \ double_eps &rhs){s << rhs.value_; return s;}\n    friend std::istream& operator>>(std::istream\
    \ &s, double_eps &rhs){s >> rhs.value_; return s;}\n\n    friend double_eps sin(double_eps\
    \ x){return std::sin((T)x);}\n    friend double_eps cos(double_eps x){return std::cos((T)x);}\n\
    \    friend double_eps tan(double_eps x){return std::tan((T)x);}\n    friend double_eps\
    \ acos(double_eps x){return std::acos((T)x);}\n    friend double_eps atan2(double_eps\
    \ y, double_eps x){return std::atan2((T)y, (T)x);}\n    friend double_eps abs(double_eps\
    \ x){return std::abs((T)x);}\n    friend double_eps sqrt(double_eps x){return\
    \ std::sqrt(std::max<T>(0, (T)x));}\n  };\n}\n\nnamespace std {\n  template <typename\
    \ T, const T &eps>\n  class numeric_limits<haar_lib::double_eps<T, eps>> {\n \
    \ public:\n    static haar_lib::double_eps<T, eps> infinity() {return numeric_limits<T>::infinity();}\n\
    \    static haar_lib::double_eps<T, eps> min() {return numeric_limits<T>::min();}\n\
    \    static haar_lib::double_eps<T, eps> max() {return numeric_limits<T>::max();}\n\
    \    static haar_lib::double_eps<T, eps> lowest() {return numeric_limits<T>::lowest();}\n\
    \  };\n}\n#line 3 \"Mylib/Geometry/Float/minimum_covering_circle.cpp\"\n#include\
    \ <random>\n#include <algorithm>\n#line 3 \"Mylib/Geometry/Float/circumscribed_circle_of_triangle.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  circle<T> circumscribed_circle_of_triangle(const\
    \ point<T> &a, const point<T> &b, const point<T> &c){\n    const T A = abs_sq(b\
    \ - c), B = abs_sq(a - c), C = abs_sq(a - b), S = A + B + C;\n    const T AA =\
    \ A * (S - A * 2.0);\n    const T BB = B * (S - B * 2.0);\n    const T CC = C\
    \ * (S - C * 2.0);\n    const auto center = (AA * a + BB * b + CC * c) / (AA +\
    \ BB + CC);\n\n    return circle<T>(\n      center,\n      abs(center - a)\n \
    \   );\n  }\n}\n#line 6 \"Mylib/Geometry/Float/minimum_covering_circle.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename T>\n  circle<T> minimum_covering_circle(std::vector<point<T>>\
    \ ps, int seed = 0){\n    if(ps.empty()) return circle<T>();\n    if(ps.size()\
    \ == 1) return circle<T>(ps[0], 0);\n\n    const int N = ps.size();\n\n    std::mt19937\
    \ rand(seed);\n    std::shuffle(ps.begin(), ps.end(), rand);\n\n    auto make_circle_2\
    \ =\n      [&](const auto &p, const auto &q){\n        const auto c = (p + q)\
    \ / 2.0;\n        return circle<T>(c, abs(p - c));\n      };\n\n    auto check\
    \ =\n      [](const auto &p, const auto &c){\n        return abs(c.center - p)\
    \ <= c.radius;\n      };\n\n    circle<T> ret = make_circle_2(ps[0], ps[1]);\n\
    \n    for(int i = 2; i < N; ++i){\n      if(check(ps[i], ret)) continue;\n\n \
    \     ret = make_circle_2(ps[0], ps[i]);\n\n      for(int j = 1; j < i; ++j){\n\
    \        if(check(ps[j], ret)) continue;\n\n        ret = make_circle_2(ps[i],\
    \ ps[j]);\n\n        for(int k = 0; k < j; ++k){\n          if(check(ps[k], ret))\
    \ continue;\n          if(i == j or j == k or k == i) continue;\n\n          ret\
    \ = circumscribed_circle_of_triangle(ps[i], ps[j], ps[k]);\n        }\n      }\n\
    \    }\n\n    return ret;\n  }\n}\n#line 2 \"Mylib/Utils/fix_point.cpp\"\n#include\
    \ <utility>\n\nnamespace haar_lib {\n  template <typename F>\n  struct fix_point\
    \ : F {\n    explicit constexpr fix_point(F &&f) noexcept : F(std::forward<F>(f)){}\n\
    \n    template <typename ... Args>\n    constexpr auto operator()(Args &&... args)\
    \ const {\n      return F::operator()(*this, std::forward<Args>(args) ...);\n\
    \    }\n  };\n\n  template <typename F>\n  inline constexpr auto make_fix_point(F\
    \ &&f){\n    return fix_point<F>(std::forward<F>(f));\n  }\n\n  template <typename\
    \ F>\n  inline constexpr auto make_fix_point(F &f){\n    return fix_point<F>(std::forward<F>(f));\n\
    \  }\n}\n#line 2 \"Mylib/Bit/enumerate_subsets_asc.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename Func>\n  void enumerate_subsets_asc(int a, const Func\
    \ &f){\n    for(int t = 0; ; t = (t - a) & a){\n      if(not f(t)) break;\n  \
    \    if(t == a) break;\n    }\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 13 \"test/aoj/3034/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nstatic constexpr\
    \ double eps = ERROR;\nusing D = hl::double_eps<double, eps>;\n\nD dp[15][1 <<\
    \ 14];\nbool check[15][1 << 14];\n\nconst D INF = 1e9;\n\nint main(){\n  int N,\
    \ M; std::cin >> N >> M;\n\n  auto ps = hl::input_vector<hl::point<D>>(N);\n\n\
    \  std::vector<double> memo(1 << N);\n\n  for(int t = 0; t < (1 << N); ++t){\n\
    \    std::vector<hl::point<D>> q;\n    for(int i = 0; i < N; ++i){\n      if(t\
    \ & (1 << i)) q.push_back(ps[i]);\n    }\n    memo[t] = (double)hl::minimum_covering_circle(q).radius;\n\
    \  }\n\n  const int mask = (1 << N) - 1;\n\n  auto ans =\n    hl::make_fix_point(\n\
    \      [&](auto &&rec, int d, int s) -> D {\n        if(d == M){\n          if(s\
    \ != 0) return dp[d][s] = INF;\n          return dp[d][s] = 0;\n        }\n\n\
    \        if(check[d][s]) return dp[d][s];\n        check[d][s] = true;\n\n   \
    \     D ret = INF;\n\n        hl::enumerate_subsets_asc(\n          s,\n     \
    \     [&](int t){\n            D val = std::max((double)rec(d + 1, s ^ t), memo[t]);\n\
    \            ret = std::min((double)ret, (double)val);\n            return true;\n\
    \          }\n        );\n\n        return dp[d][s] = ret;\n      }\n    )(0,\
    \ mask);\n\n  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3034\"\
    \n#define ERROR 1e-3\n\n#include <iostream>\n#include <iomanip>\n#include <vector>\n\
    #include \"Mylib/Geometry/Float/geometry_template.cpp\"\n#include \"Mylib/Geometry/Float/double_eps.cpp\"\
    \n#include \"Mylib/Geometry/Float/minimum_covering_circle.cpp\"\n#include \"Mylib/Utils/fix_point.cpp\"\
    \n#include \"Mylib/Bit/enumerate_subsets_asc.cpp\"\n#include \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nstatic constexpr double eps = ERROR;\nusing D\
    \ = hl::double_eps<double, eps>;\n\nD dp[15][1 << 14];\nbool check[15][1 << 14];\n\
    \nconst D INF = 1e9;\n\nint main(){\n  int N, M; std::cin >> N >> M;\n\n  auto\
    \ ps = hl::input_vector<hl::point<D>>(N);\n\n  std::vector<double> memo(1 << N);\n\
    \n  for(int t = 0; t < (1 << N); ++t){\n    std::vector<hl::point<D>> q;\n   \
    \ for(int i = 0; i < N; ++i){\n      if(t & (1 << i)) q.push_back(ps[i]);\n  \
    \  }\n    memo[t] = (double)hl::minimum_covering_circle(q).radius;\n  }\n\n  const\
    \ int mask = (1 << N) - 1;\n\n  auto ans =\n    hl::make_fix_point(\n      [&](auto\
    \ &&rec, int d, int s) -> D {\n        if(d == M){\n          if(s != 0) return\
    \ dp[d][s] = INF;\n          return dp[d][s] = 0;\n        }\n\n        if(check[d][s])\
    \ return dp[d][s];\n        check[d][s] = true;\n\n        D ret = INF;\n\n  \
    \      hl::enumerate_subsets_asc(\n          s,\n          [&](int t){\n     \
    \       D val = std::max((double)rec(d + 1, s ^ t), memo[t]);\n            ret\
    \ = std::min((double)ret, (double)val);\n            return true;\n          }\n\
    \        );\n\n        return dp[d][s] = ret;\n      }\n    )(0, mask);\n\n  std::cout\
    \ << std::fixed << std::setprecision(12) << ans << std::endl;\n\n  return 0;\n\
    }\n"
  dependsOn:
  - Mylib/Geometry/Float/geometry_template.cpp
  - Mylib/Geometry/Float/double_eps.cpp
  - Mylib/Geometry/Float/minimum_covering_circle.cpp
  - Mylib/Geometry/Float/circumscribed_circle_of_triangle.cpp
  - Mylib/Utils/fix_point.cpp
  - Mylib/Bit/enumerate_subsets_asc.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/3034/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/3034/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/3034/main.test.cpp
- /verify/test/aoj/3034/main.test.cpp.html
title: test/aoj/3034/main.test.cpp
---
