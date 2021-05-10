---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/ccw.cpp
    title: Check clockwise-counterclockwise
  - icon: ':question:'
    path: Mylib/Geometry/Float/double_eps.cpp
    title: Floating point number with eps
  - icon: ':question:'
    path: Mylib/Geometry/Float/geometry_template.cpp
    title: Geometry template
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/is_convex.cpp
    title: Check convex
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B
  bundledCode: "#line 1 \"test/aoj/CGL_3_B/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B\"\
    \n\n#include <iomanip>\n#include <iostream>\n#line 2 \"Mylib/Geometry/Float/double_eps.cpp\"\
    \n#include <cmath>\n#line 4 \"Mylib/Geometry/Float/double_eps.cpp\"\n#include\
    \ <limits>\n\nnamespace haar_lib {\n  template <typename T, const T &eps>\n  struct\
    \ double_eps {\n    using value_type = T;\n\n  private:\n    T value_;\n\n  public:\n\
    \    double_eps() : value_(0) {}\n    double_eps(T value_) : value_(value_) {}\n\
    \n    auto &operator=(const double_eps &rhs) {\n      this->value_ = rhs.value_;\n\
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
    \ << \")\";\n    return s;\n  }\n}  // namespace haar_lib\n#line 3 \"Mylib/Geometry/Float/ccw.cpp\"\
    \n\nnamespace haar_lib {\n  namespace ccw_impl {\n    enum status {\n      ONLINE_BACK\
    \       = -2,\n      COUNTER_CLOCKWISE = -1,\n      ON_SEGMENT        = 0,\n \
    \     CLOCKWISE         = 1,\n      ONLINE_FRONT      = 2\n    };\n  }\n\n  struct\
    \ ccw {\n    ccw_impl::status value;\n    bool operator==(const ccw &that) const\
    \ { return value == that.value; };\n    bool operator!=(const ccw &that) const\
    \ { return value != that.value; };\n    bool is_online_back() const { return value\
    \ == ccw_impl::status::ONLINE_BACK; }\n    bool is_counter_clockwise() const {\
    \ return value == ccw_impl::status::COUNTER_CLOCKWISE; }\n    bool is_on_segment()\
    \ const { return value == ccw_impl::status::ON_SEGMENT; }\n    bool is_clockwise()\
    \ const { return value == ccw_impl::status::CLOCKWISE; }\n    bool is_online_front()\
    \ const { return value == ccw_impl::status::ONLINE_FRONT; }\n  };\n\n  template\
    \ <typename T>\n  ccw check_ccw(const point<T> &p0, const point<T> &p1, const\
    \ point<T> &p2) {\n    using namespace ccw_impl;\n\n    const T cr = cross(p1\
    \ - p0, p2 - p0);\n    const T d  = dot(p1 - p0, p2 - p0);\n\n    if (cr == 0)\
    \ {\n      if (d < 0)\n        return ccw({ONLINE_BACK});\n      else if (abs(p2\
    \ - p0) > abs(p1 - p0))\n        return ccw({ONLINE_FRONT});\n      else\n   \
    \     return ccw({ON_SEGMENT});\n    } else if (cr > 0) {\n      return ccw({COUNTER_CLOCKWISE});\n\
    \    } else {\n      return ccw({CLOCKWISE});\n    }\n  }\n}  // namespace haar_lib\n\
    #line 5 \"Mylib/Geometry/Float/is_convex.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  bool is_convex(const polygon<T> &ps) {\n    const int n = ps.size();\n\
    \    std::vector<ccw> temp;\n\n    for (int i = 0; i < n; ++i) {\n      const\
    \ auto c = check_ccw(ps[i], ps[(i + 1) % n], ps[(i + 2) % n]);\n\n      if (c.is_clockwise()\
    \ or c.is_counter_clockwise()) {\n        if (temp.empty())\n          temp.push_back(c);\n\
    \        else if (temp.back() != c)\n          return false;\n      }\n    }\n\
    \n    return true;\n  }\n}  // namespace haar_lib\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N) {\n    std::vector<T> ret(N);\n    for (int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M) {\n    std::vector<std::vector<T>> ret(N);\n    for\
    \ (int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n\
    }  // namespace haar_lib\n#line 9 \"test/aoj/CGL_3_B/main.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nstatic constexpr double eps = 1e-7;\nusing D             \
    \        = hl::double_eps<double, eps>;\n\nint main() {\n  int n;\n  std::cin\
    \ >> n;\n\n  hl::polygon<D> p = hl::input_vector<hl::point<D>>(n);\n\n  std::cout\
    \ << (hl::is_convex(p) ? 1 : 0) << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B\"\
    \n\n#include <iomanip>\n#include <iostream>\n#include \"Mylib/Geometry/Float/double_eps.cpp\"\
    \n#include \"Mylib/Geometry/Float/geometry_template.cpp\"\n#include \"Mylib/Geometry/Float/is_convex.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nstatic\
    \ constexpr double eps = 1e-7;\nusing D                     = hl::double_eps<double,\
    \ eps>;\n\nint main() {\n  int n;\n  std::cin >> n;\n\n  hl::polygon<D> p = hl::input_vector<hl::point<D>>(n);\n\
    \n  std::cout << (hl::is_convex(p) ? 1 : 0) << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Geometry/Float/double_eps.cpp
  - Mylib/Geometry/Float/geometry_template.cpp
  - Mylib/Geometry/Float/is_convex.cpp
  - Mylib/Geometry/Float/ccw.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/CGL_3_B/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_3_B/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_3_B/main.test.cpp
- /verify/test/aoj/CGL_3_B/main.test.cpp.html
title: test/aoj/CGL_3_B/main.test.cpp
---