---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Geometry/Float/double_eps.cpp
    title: Floating point number with eps
  - icon: ':question:'
    path: Mylib/Geometry/Float/geometry_template.cpp
    title: Geometry template
  - icon: ':x:'
    path: Mylib/Geometry/Float/intersect_circles.cpp
    title: Intersection between two circles
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A
  bundledCode: "#line 1 \"test/aoj/CGL_7_A/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Geometry/Float/double_eps.cpp\"\n#include\
    \ <cmath>\n#line 4 \"Mylib/Geometry/Float/double_eps.cpp\"\n#include <limits>\n\
    \nnamespace haar_lib {\n  template <typename T, const T &eps>\n  struct double_eps\
    \ {\n    using value_type = T;\n\n  private:\n    T value_;\n\n  public:\n   \
    \ double_eps() : value_(0) {}\n    double_eps(T value_) : value_(value_) {}\n\n\
    \    auto &operator=(const double_eps &rhs) {\n      this->value_ = rhs.value_;\n\
    \      return *this;\n    }\n    auto &operator+=(const double_eps &rhs) {\n \
    \     this->value_ += rhs.value_;\n      return *this;\n    }\n    auto &operator-=(const\
    \ double_eps &rhs) {\n      this->value_ -= rhs.value_;\n      return *this;\n\
    \    }\n    auto &operator*=(const double_eps &rhs) {\n      this->value_ *= rhs.value_;\n\
    \      return *this;\n    }\n    auto &operator/=(const double_eps &rhs) {\n \
    \     this->value_ /= rhs.value_;\n      return *this;\n    }\n\n    auto operator+(const\
    \ double_eps &rhs) const { return double_eps(this->value_ + rhs.value_); }\n \
    \   auto operator-(const double_eps &rhs) const { return double_eps(this->value_\
    \ - rhs.value_); }\n    auto operator*(const double_eps &rhs) const { return double_eps(this->value_\
    \ * rhs.value_); }\n    auto operator/(const double_eps &rhs) const { return double_eps(this->value_\
    \ / rhs.value_); }\n\n    bool operator==(const double_eps &rhs) const { return\
    \ std::abs(this->value_ - rhs.value_) < eps; }\n    bool operator!=(const double_eps\
    \ &rhs) const { return !(*this == rhs); }\n    bool operator<(const double_eps\
    \ &rhs) const { return this->value_ - rhs.value_ < -eps; }\n    bool operator<=(const\
    \ double_eps &rhs) const { return this->value_ - rhs.value_ < eps; }\n    bool\
    \ operator>(const double_eps &rhs) const { return !(*this <= rhs); }\n    bool\
    \ operator>=(const double_eps &rhs) const { return !(*this < rhs); }\n\n    auto\
    \ operator-() const { return double_eps(-(this->value_)); }\n\n    explicit operator\
    \ double() const noexcept { return value_; }\n    explicit operator long double()\
    \ const noexcept { return value_; }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &s, const double_eps &rhs) {\n      s << rhs.value_;\n      return s;\n    }\n\
    \    friend std::istream &operator>>(std::istream &s, double_eps &rhs) {\n   \
    \   s >> rhs.value_;\n      return s;\n    }\n\n    friend double_eps sin(double_eps\
    \ x) { return std::sin((T) x); }\n    friend double_eps cos(double_eps x) { return\
    \ std::cos((T) x); }\n    friend double_eps tan(double_eps x) { return std::tan((T)\
    \ x); }\n    friend double_eps acos(double_eps x) { return std::acos((T) x); }\n\
    \    friend double_eps atan2(double_eps y, double_eps x) { return std::atan2((T)\
    \ y, (T) x); }\n    friend double_eps abs(double_eps x) { return std::abs((T)\
    \ x); }\n    friend double_eps sqrt(double_eps x) { return std::sqrt(std::max<T>(0,\
    \ (T) x)); }\n  };\n}  // namespace haar_lib\n\nnamespace std {\n  template <typename\
    \ T, const T &eps>\n  class numeric_limits<haar_lib::double_eps<T, eps>> {\n \
    \ public:\n    static haar_lib::double_eps<T, eps> infinity() { return numeric_limits<T>::infinity();\
    \ }\n    static haar_lib::double_eps<T, eps> min() { return numeric_limits<T>::min();\
    \ }\n    static haar_lib::double_eps<T, eps> max() { return numeric_limits<T>::max();\
    \ }\n    static haar_lib::double_eps<T, eps> lowest() { return numeric_limits<T>::lowest();\
    \ }\n  };\n}  // namespace std\n#line 4 \"Mylib/Geometry/Float/geometry_template.cpp\"\
    \n#include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  struct\
    \ vec {\n    T x, y;\n    vec() {}\n    vec(T x, T y) : x(x), y(y) {}\n\n    friend\
    \ auto operator+(const vec &a, const vec &b) { return vec(a.x + b.x, a.y + b.y);\
    \ }\n    friend auto operator-(const vec &a, const vec &b) { return vec(a.x -\
    \ b.x, a.y - b.y); }\n    friend auto operator-(const vec &a) { return vec(-a.x,\
    \ -a.y); }\n\n    friend bool operator==(const vec &a, const vec &b) { return\
    \ a.x == b.x and a.y == b.y; }\n    friend bool operator!=(const vec &a, const\
    \ vec &b) { return !(a == b); }\n    friend bool operator<(const vec &a, const\
    \ vec &b) { return a.x < b.x or (a.x == b.x and a.y < b.y); }\n\n    friend std::istream\
    \ &operator>>(std::istream &s, vec &a) {\n      s >> a.x >> a.y;\n      return\
    \ s;\n    }\n  };\n\n  template <typename T, typename U>\n  auto operator*(const\
    \ vec<T> &a, const U &k) { return vec<T>(a.x * k, a.y * k); }\n  template <typename\
    \ T, typename U>\n  auto operator*(const U &k, const vec<T> &a) { return vec<T>(a.x\
    \ * k, a.y * k); }\n  template <typename T, typename U>\n  auto operator/(const\
    \ vec<T> &a, const U &k) { return vec<T>(a.x / k, a.y / k); }\n\n  template <typename\
    \ T>\n  using point = vec<T>;\n\n  template <typename T>\n  T abs(const vec<T>\
    \ &a) { return sqrt(a.x * a.x + a.y * a.y); }\n  template <typename T>\n  T abs_sq(const\
    \ vec<T> &a) { return a.x * a.x + a.y * a.y; }\n\n  template <typename T>\n  T\
    \ dot(const vec<T> &a, const vec<T> &b) { return a.x * b.x + a.y * b.y; }\n  template\
    \ <typename T>\n  T cross(const vec<T> &a, const vec<T> &b) { return a.x * b.y\
    \ - a.y * b.x; }\n\n  template <typename T>\n  auto unit(const vec<T> &a) { return\
    \ a / abs(a); }\n  template <typename T>\n  auto normal(const vec<T> &p) { return\
    \ vec<T>(-p.y, p.x); }\n\n  template <typename T>\n  auto polar(const T &r, const\
    \ T &ang) { return vec<T>(r * cos(ang), r * sin(ang)); }\n\n  template <typename\
    \ T>\n  T angle(const vec<T> &a, const vec<T> &b) { return atan2(b.y - a.y, b.x\
    \ - a.x); }\n  template <typename T>\n  T phase(const vec<T> &a) { return atan2(a.y,\
    \ a.x); }\n\n  template <typename T>\n  T angle_diff(const vec<T> &a, const vec<T>\
    \ &b) {\n    T r = phase(b) - phase(a);\n\n    if (r < -M_PI)\n      return r\
    \ + 2 * M_PI;\n    else if (r > M_PI)\n      return r - 2 * M_PI;\n    return\
    \ r;\n  }\n\n  template <typename T>\n  struct line {\n    point<T> from, to;\n\
    \    line() : from(), to() {}\n    line(const point<T> &from, const point<T> &to)\
    \ : from(from), to(to) {}\n  };\n\n  template <typename T>\n  using segment =\
    \ line<T>;\n\n  template <typename T>\n  auto unit(const line<T> &a) { return\
    \ unit(a.to - a.from); }\n  template <typename T>\n  auto normal(const line<T>\
    \ &a) { return normal(a.to - a.from); }\n\n  template <typename T>\n  auto diff(const\
    \ segment<T> &a) { return a.to - a.from; }\n\n  template <typename T>\n  T abs(const\
    \ segment<T> &a) { return abs(diff(a)); }\n\n  template <typename T>\n  T dot(const\
    \ line<T> &a, const line<T> &b) { return dot(diff(a), diff(b)); }\n  template\
    \ <typename T>\n  T cross(const line<T> &a, const line<T> &b) { return cross(diff(a),\
    \ diff(b)); }\n\n  template <typename T>\n  using polygon = std::vector<point<T>>;\n\
    \n  template <typename T>\n  struct circle {\n    point<T> center;\n    T radius;\n\
    \    circle() : center(), radius(0) {}\n    circle(const point<T> &center, T radius)\
    \ : center(center), radius(radius) {}\n  };\n\n  template <typename T>\n  std::ostream\
    \ &operator<<(std::ostream &s, const vec<T> &a) {\n    s << \"(\" << a.x << \"\
    , \" << a.y << \")\";\n    return s;\n  }\n\n  template <typename T>\n  std::ostream\
    \ &operator<<(std::ostream &s, const line<T> &a) {\n    s << \"(\" << a.from <<\
    \ \" -> \" << a.to << \")\";\n    return s;\n  }\n\n  template <typename T>\n\
    \  std::ostream &operator<<(std::ostream &s, const circle<T> &a) {\n    s << \"\
    (\"\n      << \"center: \" << a.center << \", \"\n      << \"radius: \" << a.radius\
    \ << \")\";\n    return s;\n  }\n}  // namespace haar_lib\n#line 4 \"Mylib/Geometry/Float/intersect_circles.cpp\"\
    \n\nnamespace haar_lib {\n  namespace intersect_circles_impl {\n    enum class\
    \ status_t { SAME,\n                          INSIDE,\n                      \
    \    INSCRIBED,\n                          INTERSECTED,\n                    \
    \      CIRCUMSCRIBED,\n                          OUTSIDE };\n    template <typename\
    \ T>\n    struct result {\n      status_t status;\n      std::vector<point<T>>\
    \ crosspoints;\n      bool is_same() const { return status == status_t::SAME;\
    \ }\n      bool is_inside() const { return status == status_t::INSIDE; }\n   \
    \   bool is_inscribed() const { return status == status_t::INSCRIBED; }\n    \
    \  bool is_intersected() const { return status == status_t::INTERSECTED; }\n \
    \     bool is_circumscribed() const { return status == status_t::CIRCUMSCRIBED;\
    \ }\n      bool is_outside() const { return status == status_t::OUTSIDE; }\n \
    \   };\n  }  // namespace intersect_circles_impl\n\n  template <typename T>\n\
    \  auto intersect_circles(const circle<T> &a, const circle<T> &b) {\n    using\
    \ namespace intersect_circles_impl;\n\n    const T d = abs(a.center - b.center);\n\
    \    const T x = acos((a.radius * a.radius + d * d - b.radius * b.radius) / ((T)\
    \ 2.0 * d * a.radius));\n    const T t = atan2(b.center.y - a.center.y, b.center.x\
    \ - a.center.x);\n\n    if (a.radius + b.radius == d) {\n      return result<T>({status_t::CIRCUMSCRIBED,\
    \ {a.center + polar(a.radius, t)}});\n    } else if (abs(a.radius - b.radius)\
    \ == d) {\n      return result<T>({status_t::INSCRIBED, {a.center + polar(a.radius,\
    \ t)}});\n    } else if (a.radius + b.radius > d and d > abs(a.radius - b.radius))\
    \ {\n      return result<T>(\n          {status_t::INTERSECTED,\n           {a.center\
    \ + polar(a.radius, t + x), a.center + polar(a.radius, t - x)}});\n    } else\
    \ if (a.radius + b.radius < d) {\n      return result<T>({status_t::OUTSIDE, {}});\n\
    \    } else if (abs(a.radius - b.radius) > d) {\n      return result<T>({status_t::INSIDE,\
    \ {}});\n    }\n\n    return result<T>({status_t::SAME, {}});\n  }\n}  // namespace\
    \ haar_lib\n#line 7 \"test/aoj/CGL_7_A/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nstatic constexpr double eps = 1e-7;\nusing D                     = hl::double_eps<double,\
    \ eps>;\n\nint main() {\n  hl::circle<D> c1, c2;\n  std::cin >> c1.center >> c1.radius\
    \ >> c2.center >> c2.radius;\n\n  const auto s = hl::intersect_circles(c1, c2);\n\
    \n  if (s.is_inside()) std::cout << 0 << std::endl;\n  if (s.is_inscribed()) std::cout\
    \ << 1 << std::endl;\n  if (s.is_intersected()) std::cout << 2 << std::endl;\n\
    \  if (s.is_circumscribed()) std::cout << 3 << std::endl;\n  if (s.is_outside())\
    \ std::cout << 4 << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\"\
    \n\n#include <iostream>\n#include \"Mylib/Geometry/Float/double_eps.cpp\"\n#include\
    \ \"Mylib/Geometry/Float/geometry_template.cpp\"\n#include \"Mylib/Geometry/Float/intersect_circles.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nstatic constexpr double eps = 1e-7;\nusing D \
    \                    = hl::double_eps<double, eps>;\n\nint main() {\n  hl::circle<D>\
    \ c1, c2;\n  std::cin >> c1.center >> c1.radius >> c2.center >> c2.radius;\n\n\
    \  const auto s = hl::intersect_circles(c1, c2);\n\n  if (s.is_inside()) std::cout\
    \ << 0 << std::endl;\n  if (s.is_inscribed()) std::cout << 1 << std::endl;\n \
    \ if (s.is_intersected()) std::cout << 2 << std::endl;\n  if (s.is_circumscribed())\
    \ std::cout << 3 << std::endl;\n  if (s.is_outside()) std::cout << 4 << std::endl;\n\
    \n  return 0;\n}\n"
  dependsOn:
  - Mylib/Geometry/Float/double_eps.cpp
  - Mylib/Geometry/Float/geometry_template.cpp
  - Mylib/Geometry/Float/intersect_circles.cpp
  isVerificationFile: true
  path: test/aoj/CGL_7_A/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/CGL_7_A/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_7_A/main.test.cpp
- /verify/test/aoj/CGL_7_A/main.test.cpp.html
title: test/aoj/CGL_7_A/main.test.cpp
---
