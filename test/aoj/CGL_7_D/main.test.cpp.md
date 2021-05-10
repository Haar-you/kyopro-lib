---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Geometry/Float/distance_line_point.cpp
    title: Distance between a line and a point
  - icon: ':question:'
    path: Mylib/Geometry/Float/double_eps.cpp
    title: Floating point number with eps
  - icon: ':question:'
    path: Mylib/Geometry/Float/geometry_template.cpp
    title: Geometry template
  - icon: ':x:'
    path: Mylib/Geometry/Float/intersect_circle_line.cpp
    title: Intersection between a circle and a line
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.000001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
  bundledCode: "#line 1 \"test/aoj/CGL_7_D/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D\"\
    \n#define ERROR 0.000001\n\n#include <algorithm>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <vector>\n#line 2 \"Mylib/Geometry/Float/double_eps.cpp\"\
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
    \ }\n  };\n}  // namespace std\n#line 5 \"Mylib/Geometry/Float/geometry_template.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct vec {\n    T x, y;\n\
    \    vec() {}\n    vec(T x, T y) : x(x), y(y) {}\n\n    friend auto operator+(const\
    \ vec &a, const vec &b) { return vec(a.x + b.x, a.y + b.y); }\n    friend auto\
    \ operator-(const vec &a, const vec &b) { return vec(a.x - b.x, a.y - b.y); }\n\
    \    friend auto operator-(const vec &a) { return vec(-a.x, -a.y); }\n\n    friend\
    \ bool operator==(const vec &a, const vec &b) { return a.x == b.x and a.y == b.y;\
    \ }\n    friend bool operator!=(const vec &a, const vec &b) { return !(a == b);\
    \ }\n    friend bool operator<(const vec &a, const vec &b) { return a.x < b.x\
    \ or (a.x == b.x and a.y < b.y); }\n\n    friend std::istream &operator>>(std::istream\
    \ &s, vec &a) {\n      s >> a.x >> a.y;\n      return s;\n    }\n  };\n\n  template\
    \ <typename T, typename U>\n  auto operator*(const vec<T> &a, const U &k) { return\
    \ vec<T>(a.x * k, a.y * k); }\n  template <typename T, typename U>\n  auto operator*(const\
    \ U &k, const vec<T> &a) { return vec<T>(a.x * k, a.y * k); }\n  template <typename\
    \ T, typename U>\n  auto operator/(const vec<T> &a, const U &k) { return vec<T>(a.x\
    \ / k, a.y / k); }\n\n  template <typename T>\n  using point = vec<T>;\n\n  template\
    \ <typename T>\n  T abs(const vec<T> &a) { return sqrt(a.x * a.x + a.y * a.y);\
    \ }\n  template <typename T>\n  T abs_sq(const vec<T> &a) { return a.x * a.x +\
    \ a.y * a.y; }\n\n  template <typename T>\n  T dot(const vec<T> &a, const vec<T>\
    \ &b) { return a.x * b.x + a.y * b.y; }\n  template <typename T>\n  T cross(const\
    \ vec<T> &a, const vec<T> &b) { return a.x * b.y - a.y * b.x; }\n\n  template\
    \ <typename T>\n  auto unit(const vec<T> &a) { return a / abs(a); }\n  template\
    \ <typename T>\n  auto normal(const vec<T> &p) { return vec<T>(-p.y, p.x); }\n\
    \n  template <typename T>\n  auto polar(const T &r, const T &ang) { return vec<T>(r\
    \ * cos(ang), r * sin(ang)); }\n\n  template <typename T>\n  T angle(const vec<T>\
    \ &a, const vec<T> &b) { return atan2(b.y - a.y, b.x - a.x); }\n  template <typename\
    \ T>\n  T phase(const vec<T> &a) { return atan2(a.y, a.x); }\n\n  template <typename\
    \ T>\n  T angle_diff(const vec<T> &a, const vec<T> &b) {\n    T r = phase(b) -\
    \ phase(a);\n\n    if (r < -M_PI)\n      return r + 2 * M_PI;\n    else if (r\
    \ > M_PI)\n      return r - 2 * M_PI;\n    return r;\n  }\n\n  template <typename\
    \ T>\n  struct line {\n    point<T> from, to;\n    line() : from(), to() {}\n\
    \    line(const point<T> &from, const point<T> &to) : from(from), to(to) {}\n\
    \  };\n\n  template <typename T>\n  using segment = line<T>;\n\n  template <typename\
    \ T>\n  auto unit(const line<T> &a) { return unit(a.to - a.from); }\n  template\
    \ <typename T>\n  auto normal(const line<T> &a) { return normal(a.to - a.from);\
    \ }\n\n  template <typename T>\n  auto diff(const segment<T> &a) { return a.to\
    \ - a.from; }\n\n  template <typename T>\n  T abs(const segment<T> &a) { return\
    \ abs(diff(a)); }\n\n  template <typename T>\n  T dot(const line<T> &a, const\
    \ line<T> &b) { return dot(diff(a), diff(b)); }\n  template <typename T>\n  T\
    \ cross(const line<T> &a, const line<T> &b) { return cross(diff(a), diff(b));\
    \ }\n\n  template <typename T>\n  using polygon = std::vector<point<T>>;\n\n \
    \ template <typename T>\n  struct circle {\n    point<T> center;\n    T radius;\n\
    \    circle() : center(), radius(0) {}\n    circle(const point<T> &center, T radius)\
    \ : center(center), radius(radius) {}\n  };\n\n  template <typename T>\n  std::ostream\
    \ &operator<<(std::ostream &s, const vec<T> &a) {\n    s << \"(\" << a.x << \"\
    , \" << a.y << \")\";\n    return s;\n  }\n\n  template <typename T>\n  std::ostream\
    \ &operator<<(std::ostream &s, const line<T> &a) {\n    s << \"(\" << a.from <<\
    \ \" -> \" << a.to << \")\";\n    return s;\n  }\n\n  template <typename T>\n\
    \  std::ostream &operator<<(std::ostream &s, const circle<T> &a) {\n    s << \"\
    (\"\n      << \"center: \" << a.center << \", \"\n      << \"radius: \" << a.radius\
    \ << \")\";\n    return s;\n  }\n}  // namespace haar_lib\n#line 3 \"Mylib/Geometry/Float/distance_line_point.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  T distance_line_point(const\
    \ line<T> &l, const point<T> &p) {\n    return abs(cross(diff(l), p - l.from)\
    \ / abs(l));\n  }\n}  // namespace haar_lib\n#line 5 \"Mylib/Geometry/Float/intersect_circle_line.cpp\"\
    \n\nnamespace haar_lib {\n  namespace intersect_circle_line_impl {\n    enum class\
    \ status_t { OUTSIDE,\n                          TANGENT,\n                  \
    \        CROSSED };\n    template <typename T>\n    struct result {\n      status_t\
    \ status;\n      std::vector<point<T>> crosspoints;\n      bool is_outside() const\
    \ { return status == status_t::OUTSIDE; }\n      bool is_tangent() const { return\
    \ status == status_t::TANGENT; }\n      bool is_crossed() const { return status\
    \ == status_t::CROSSED; }\n    };\n  }  // namespace intersect_circle_line_impl\n\
    \n  template <typename T>\n  auto intersect_circle_line(const circle<T> &c, const\
    \ line<T> &l) {\n    using namespace intersect_circle_line_impl;\n\n    const\
    \ T d = distance_line_point(l, c.center);\n\n    if (d > c.radius) {\n      return\
    \ result<T>({status_t::OUTSIDE, {}});\n    }\n\n    const auto n = normal(l);\n\
    \    const auto b = l.from + diff(l) * cross(n, c.center + n - l.from) / cross(n,\
    \ diff(l));\n\n    if (d == c.radius) {\n      return result<T>({status_t::TANGENT,\
    \ {b}});\n    }\n\n    const T a = sqrt(c.radius * c.radius - d * d);\n    return\
    \ result<T>({status_t::CROSSED, {b + unit(l) * a, b - unit(l) * a}});\n  }\n}\
    \  // namespace haar_lib\n#line 2 \"Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n\
    #line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#include <utility>\n\
    #line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T, size_t... I>\n  static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>)\
    \ {\n    (void) std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};\n\
    \  }\n\n  template <typename T, typename U>\n  std::istream &operator>>(std::istream\
    \ &s, std::pair<T, U> &value) {\n    s >> value.first >> value.second;\n    return\
    \ s;\n  }\n\n  template <typename... Args>\n  std::istream &operator>>(std::istream\
    \ &s, std::tuple<Args...> &value) {\n    input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());\n\
    \    return s;\n  }\n}  // namespace haar_lib\n#line 8 \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename... Args>\n  class InputTuples {\n\
    \    struct iter {\n      using value_type = std::tuple<Args...>;\n      value_type\
    \ value;\n      bool fetched = false;\n      int N, c = 0;\n\n      value_type\
    \ operator*() {\n        if (not fetched) {\n          std::cin >> value;\n  \
    \      }\n        return value;\n      }\n\n      void operator++() {\n      \
    \  ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter &) const\
    \ {\n        return c < N;\n      }\n\n      iter(int N) : N(N) {}\n    };\n\n\
    \    int N;\n\n  public:\n    InputTuples(int N) : N(N) {}\n\n    iter begin()\
    \ const { return iter(N); }\n    iter end() const { return iter(N); }\n  };\n\n\
    \  template <typename... Args>\n  auto input_tuples(int N) {\n    return InputTuples<Args...>(N);\n\
    \  }\n}  // namespace haar_lib\n#line 12 \"test/aoj/CGL_7_D/main.test.cpp\"\n\n\
    namespace hl = haar_lib;\n\nstatic constexpr double eps = ERROR;\nusing D    \
    \                 = hl::double_eps<double, eps>;\n\nint main() {\n  hl::circle<D>\
    \ c;\n  std::cin >> c.center >> c.radius;\n\n  int q;\n  std::cin >> q;\n\n  for\
    \ (auto [p0, p1] : hl::input_tuples<hl::point<D>, hl::point<D>>(q)) {\n    hl::line<D>\
    \ l(p0, p1);\n\n    const auto s = hl::intersect_circle_line(c, l);\n    auto\
    \ ans     = s.crosspoints;\n\n    std::sort(\n        ans.begin(), ans.end(),\n\
    \        [](const auto &a, const auto &b) { return a.x < b.x or (a.x == b.x and\
    \ a.y < b.y); });\n\n    std::cout << std::fixed << std::setprecision(12);\n\n\
    \    if (s.is_tangent()) {\n      std::cout << ans[0].x << \" \" << ans[0].y <<\
    \ \" \";\n      std::cout << ans[0].x << \" \" << ans[0].y << std::endl;\n   \
    \ } else if (s.is_crossed()) {\n      std::cout << ans[0].x << \" \" << ans[0].y\
    \ << \" \";\n      std::cout << ans[1].x << \" \" << ans[1].y << std::endl;\n\
    \    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D\"\
    \n#define ERROR 0.000001\n\n#include <algorithm>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <vector>\n#include \"Mylib/Geometry/Float/double_eps.cpp\"\
    \n#include \"Mylib/Geometry/Float/geometry_template.cpp\"\n#include \"Mylib/Geometry/Float/intersect_circle_line.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nstatic\
    \ constexpr double eps = ERROR;\nusing D                     = hl::double_eps<double,\
    \ eps>;\n\nint main() {\n  hl::circle<D> c;\n  std::cin >> c.center >> c.radius;\n\
    \n  int q;\n  std::cin >> q;\n\n  for (auto [p0, p1] : hl::input_tuples<hl::point<D>,\
    \ hl::point<D>>(q)) {\n    hl::line<D> l(p0, p1);\n\n    const auto s = hl::intersect_circle_line(c,\
    \ l);\n    auto ans     = s.crosspoints;\n\n    std::sort(\n        ans.begin(),\
    \ ans.end(),\n        [](const auto &a, const auto &b) { return a.x < b.x or (a.x\
    \ == b.x and a.y < b.y); });\n\n    std::cout << std::fixed << std::setprecision(12);\n\
    \n    if (s.is_tangent()) {\n      std::cout << ans[0].x << \" \" << ans[0].y\
    \ << \" \";\n      std::cout << ans[0].x << \" \" << ans[0].y << std::endl;\n\
    \    } else if (s.is_crossed()) {\n      std::cout << ans[0].x << \" \" << ans[0].y\
    \ << \" \";\n      std::cout << ans[1].x << \" \" << ans[1].y << std::endl;\n\
    \    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Geometry/Float/double_eps.cpp
  - Mylib/Geometry/Float/geometry_template.cpp
  - Mylib/Geometry/Float/intersect_circle_line.cpp
  - Mylib/Geometry/Float/distance_line_point.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/CGL_7_D/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/CGL_7_D/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_7_D/main.test.cpp
- /verify/test/aoj/CGL_7_D/main.test.cpp.html
title: test/aoj/CGL_7_D/main.test.cpp
---