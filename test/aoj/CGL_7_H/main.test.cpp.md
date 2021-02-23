---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/area_intersection_of_circle_and_polygon.cpp
    title: Area of intersection between a circle and a polygon
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/distance_segment_point.cpp
    title: Distance between a segment and a point
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/double_eps.cpp
    title: Floating point number with eps
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/geometry_template.cpp
    title: Geometry template
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/intersect_circle_segment.cpp
    title: Intersection between a circle and a segment
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H
  bundledCode: "#line 1 \"test/aoj/CGL_7_H/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H\"\
    \n#define ERROR 0.00001\n\n#include <iostream>\n#include <iomanip>\n#line 3 \"\
    Mylib/Geometry/Float/double_eps.cpp\"\n#include <limits>\n#include <cmath>\n\n\
    namespace haar_lib {\n  template <typename T, const T &eps>\n  struct double_eps\
    \ {\n    using value_type = T;\n\n  private:\n    T value_;\n\n  public:\n   \
    \ double_eps(): value_(0){}\n    double_eps(T value_): value_(value_){}\n\n  \
    \  auto& operator=(const double_eps &rhs){this->value_ = rhs.value_; return *this;}\n\
    \    auto& operator+=(const double_eps &rhs){this->value_ += rhs.value_; return\
    \ *this;}\n    auto& operator-=(const double_eps &rhs){this->value_ -= rhs.value_;\
    \ return *this;}\n    auto& operator*=(const double_eps &rhs){this->value_ *=\
    \ rhs.value_; return *this;}\n    auto& operator/=(const double_eps &rhs){this->value_\
    \ /= rhs.value_; return *this;}\n\n    auto operator+(const double_eps &rhs) const\
    \ {return double_eps(this->value_ + rhs.value_);}\n    auto operator-(const double_eps\
    \ &rhs) const {return double_eps(this->value_ - rhs.value_);}\n    auto operator*(const\
    \ double_eps &rhs) const {return double_eps(this->value_ * rhs.value_);}\n   \
    \ auto operator/(const double_eps &rhs) const {return double_eps(this->value_\
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
    \  };\n}\n#line 4 \"Mylib/Geometry/Float/geometry_template.cpp\"\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  struct vec {\n    T x, y;\n\
    \    vec(){}\n    vec(T x, T y): x(x), y(y){}\n\n    friend auto operator+(const\
    \ vec &a, const vec &b){return vec(a.x + b.x, a.y + b.y);}\n    friend auto operator-(const\
    \ vec &a, const vec &b){return vec(a.x - b.x, a.y - b.y);}\n    friend auto operator-(const\
    \ vec &a){return vec(-a.x, -a.y);}\n\n    friend bool operator==(const vec &a,\
    \ const vec &b){return a.x == b.x and a.y == b.y;}\n    friend bool operator!=(const\
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
    \ \"radius: \" << a.radius << \")\";\n    return s;\n  }\n}\n#line 3 \"Mylib/Geometry/Float/distance_segment_point.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  T distance_segment_point(const\
    \ segment<T> &l, const point<T> &p){\n    if(dot(diff(l), p - l.from) < 0) return\
    \ abs(p - l.from);\n    if(dot(-diff(l), p - l.to) < 0) return abs(p - l.to);\n\
    \    return abs(cross(diff(l), p - l.from)) / abs(l);\n  }\n}\n#line 5 \"Mylib/Geometry/Float/intersect_circle_segment.cpp\"\
    \n\nnamespace haar_lib {\n  namespace intersect_circle_segment_impl {\n    enum\
    \ class status_t { INSIDE, OUTSIDE, TANGENT, ONE_CROSSPOINT, TWO_CROSSPOINTS };\n\
    \    template <typename T>\n    struct result {\n      status_t status;\n    \
    \  std::vector<point<T>> crosspoints;\n      bool is_inside() const {return status\
    \ == status_t::INSIDE;}\n      bool is_outside() const {return status == status_t::OUTSIDE;}\n\
    \      bool is_tangent() const {return status == status_t::TANGENT;}\n      bool\
    \ has_one_crosspoint() const {return status == status_t::ONE_CROSSPOINT;}\n  \
    \    bool has_two_crosspoints() const {return status == status_t::TWO_CROSSPOINTS;}\n\
    \    };\n  }\n\n  template <typename T>\n  auto intersect_circle_segment(const\
    \ circle<T> &cl, const line<T> &s){\n    using namespace intersect_circle_segment_impl;\n\
    \n    const T r = cl.radius;\n    const auto &c = cl.center;\n\n    const T d1\
    \ = abs(c - s.from);\n    const T d2 = abs(c - s.to);\n    const T v = distance_segment_point(s,\
    \ c);\n    const T m = sqrt(r * r - v * v);\n    const auto n = normal(s);\n \
    \   const auto k = s.from + diff(s) * cross(n, c + n - s.from) / cross(n, diff(s));\n\
    \n    if(d1 < r and d2 < r){\n      return result<T>({status_t::INSIDE, {}});\n\
    \    }\n    else if(v == r){\n      return result<T>({status_t::TANGENT, {k}});\n\
    \    }\n    else if(v > r){\n      return result<T>({status_t::OUTSIDE, {}});\n\
    \    }\n    else if(d1 >= r and d2 >= r){\n      return result<T>({status_t::TWO_CROSSPOINTS,\
    \ {k - unit(s) * m, k + unit(s) * m}});\n    }\n\n    const T b = dot(unit(s),\
    \ s.from - c);\n    const T a = abs_sq(s.from - c) - r * r;\n    const T x = sqrt(b\
    \ * b - a);\n\n    return result<T>(\n      {\n       status_t::ONE_CROSSPOINT,\n\
    \       {s.from + unit(s) * (-b - x >= 0 ? -b - x : -b + x)}\n      }\n    );\n\
    \  }\n}\n#line 5 \"Mylib/Geometry/Float/area_intersection_of_circle_and_polygon.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  T area_intersection_of_circle_and_polygon(const\
    \ circle<T> &cl, const polygon<T> &ps){\n    const int n = ps.size();\n    T ret\
    \ = 0;\n\n    for(int i = 0; i < n; ++i){\n      T temp = 0;\n\n      const T\
    \ r = cl.radius;\n      const auto &c = cl.center;\n\n      const auto &p1 = ps[i];\n\
    \      const auto &p2 = ps[(i + 1) % n];\n\n      const auto t = intersect_circle_segment(cl,\
    \ line<T>(p1, p2));\n      auto res = t.crosspoints;\n\n      const T d1 = abs(p1\
    \ - c);\n      const T d2 = abs(p2 - c);\n\n      if(res.size() == 0){\n     \
    \   if(t.is_inside()){ // if inside\n          temp += cross(p1 - c, p2 - c) /\
    \ 2;\n        }else{ // if outside\n          temp += r * r * angle_diff(p1 -\
    \ c, p2 - c) / 2;\n        }\n      }else if(res.size() == 1){\n        const\
    \ auto &q = res[0];\n        if(d1 >= r and d2 >= r){\n          temp += r * r\
    \ * angle_diff(p1 - c, p2 - c) / 2;\n        }else if(d1 >= r){\n          temp\
    \ += r * r * angle_diff(p1 - c, q - c) / 2 + cross(q - c, p2 - c) / 2;\n     \
    \   }else{\n          temp += cross(p1 - c, q - c) / 2 + r * r * angle_diff(q\
    \ - c, p2 - c) / 2;\n        }\n      }else{\n        const auto &q1 = res[0];\n\
    \        const auto &q2 = res[1];\n        temp +=\n          r * r * angle_diff(p1\
    \ - c, q1 - c) / 2 +\n          cross(q1 - c, q2 - c) / 2 +\n          r * r *\
    \ angle_diff(q2 - c, p2 - c) / 2;\n      }\n\n      ret += temp;\n    }\n\n  \
    \  return ret;\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  std::vector<T> input_vector(int N){\n    std::vector<T>\
    \ ret(N);\n    for(int i = 0; i < N; ++i) std::cin >> ret[i];\n    return ret;\n\
    \  }\n\n  template <typename T>\n  std::vector<std::vector<T>> input_vector(int\
    \ N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int i = 0; i <\
    \ N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line 10 \"test/aoj/CGL_7_H/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nstatic constexpr double eps = ERROR;\nusing D\
    \ = hl::double_eps<double, eps>;\n\nint main(){\n  int n; std::cin >> n;\n  int\
    \ r; std::cin >> r;\n\n  hl::circle<D> c(hl::point<D>(0, 0), r);\n\n  hl::polygon<D>\
    \ p = hl::input_vector<hl::point<D>>(n);\n\n  auto ans = hl::area_intersection_of_circle_and_polygon(c,\
    \ p);\n\n  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H\"\
    \n#define ERROR 0.00001\n\n#include <iostream>\n#include <iomanip>\n#include \"\
    Mylib/Geometry/Float/double_eps.cpp\"\n#include \"Mylib/Geometry/Float/geometry_template.cpp\"\
    \n#include \"Mylib/Geometry/Float/area_intersection_of_circle_and_polygon.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nstatic\
    \ constexpr double eps = ERROR;\nusing D = hl::double_eps<double, eps>;\n\nint\
    \ main(){\n  int n; std::cin >> n;\n  int r; std::cin >> r;\n\n  hl::circle<D>\
    \ c(hl::point<D>(0, 0), r);\n\n  hl::polygon<D> p = hl::input_vector<hl::point<D>>(n);\n\
    \n  auto ans = hl::area_intersection_of_circle_and_polygon(c, p);\n\n  std::cout\
    \ << std::fixed << std::setprecision(12) << ans << std::endl;\n\n  return 0;\n\
    }\n"
  dependsOn:
  - Mylib/Geometry/Float/double_eps.cpp
  - Mylib/Geometry/Float/geometry_template.cpp
  - Mylib/Geometry/Float/area_intersection_of_circle_and_polygon.cpp
  - Mylib/Geometry/Float/intersect_circle_segment.cpp
  - Mylib/Geometry/Float/distance_segment_point.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/CGL_7_H/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_7_H/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_7_H/main.test.cpp
- /verify/test/aoj/CGL_7_H/main.test.cpp.html
title: test/aoj/CGL_7_H/main.test.cpp
---
