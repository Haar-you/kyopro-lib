---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/ccw.cpp
    title: Check clockwise-counterclockwise
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/double_eps.cpp
    title: Floating point number with eps
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/geometry_template.cpp
    title: Geometry template
  - icon: ':heavy_check_mark:'
    path: Mylib/Geometry/Float/intersect_segments.cpp
    title: Intersection between two segments
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C
  bundledCode: "#line 1 \"test/aoj/CGL_2_C/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C\"\
    \n#define ERROR 0.00000001\n\n#include <iostream>\n#include <iomanip>\n#line 3\
    \ \"Mylib/Geometry/Float/geometry_template.cpp\"\n#include <cmath>\n#include <vector>\n\
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
    \  };\n}\n#line 3 \"Mylib/Geometry/Float/ccw.cpp\"\n\nnamespace haar_lib {\n \
    \ namespace ccw_impl {\n    enum status {\n                 ONLINE_BACK      \
    \ = -2,\n                 COUNTER_CLOCKWISE = -1,\n                 ON_SEGMENT\
    \        = 0,\n                 CLOCKWISE         = 1,\n                 ONLINE_FRONT\
    \      = 2\n    };\n  }\n\n  struct ccw {\n    ccw_impl::status value;\n    bool\
    \ operator==(const ccw &that) const {return value == that.value;};\n    bool operator!=(const\
    \ ccw &that) const {return value != that.value;};\n    bool is_online_back() const\
    \ {return value == ccw_impl::status::ONLINE_BACK;}\n    bool is_counter_clockwise()\
    \ const {return value == ccw_impl::status::COUNTER_CLOCKWISE;}\n    bool is_on_segment()\
    \ const {return value == ccw_impl::status::ON_SEGMENT;}\n    bool is_clockwise()\
    \ const {return value == ccw_impl::status::CLOCKWISE;}\n    bool is_online_front()\
    \ const {return value == ccw_impl::status::ONLINE_FRONT;}\n  };\n\n  template\
    \ <typename T>\n  ccw check_ccw(const point<T> &p0, const point<T> &p1, const\
    \ point<T> &p2){\n    using namespace ccw_impl;\n\n    const T cr = cross(p1 -\
    \ p0, p2 - p0);\n    const T d = dot(p1 - p0, p2 - p0);\n\n    if(cr == 0){\n\
    \      if(d < 0) return ccw({ONLINE_BACK});\n      else if(abs(p2 - p0) > abs(p1\
    \ - p0)) return ccw({ONLINE_FRONT});\n      else return ccw({ON_SEGMENT});\n \
    \   }else if(cr > 0){\n      return ccw({COUNTER_CLOCKWISE});\n    }else{\n  \
    \    return ccw({CLOCKWISE});\n    }\n  }\n}\n#line 5 \"Mylib/Geometry/Float/intersect_segments.cpp\"\
    \n\nnamespace haar_lib {\n  namespace intersect_segments_impl {\n    enum status_t\
    \ { INTERSECTED, OVERLAPPED, NOT_INTERSECTED, SAME };\n    template <typename\
    \ T>\n    struct result {\n      status_t status;\n      std::vector<point<T>>\
    \ crosspoints;\n      bool is_intersected() const {return status == status_t::INTERSECTED;}\n\
    \      bool is_overlapped() const {return status == status_t::OVERLAPPED;}\n \
    \     bool is_not_intersected() const {return status == status_t::NOT_INTERSECTED;}\n\
    \      bool is_same() const {return status == status_t::SAME;}\n    };\n  }\n\n\
    \  template <typename T>\n  auto intersect_segments(const segment<T> &a, const\
    \ segment<T> &b){\n    using namespace intersect_segments_impl;\n\n    const T\
    \ cr = cross(a, b);\n\n    if(abs(cr) == 0){ // parallel\n      if(check_ccw(a.from,\
    \ a.to, b.from).value * check_ccw(a.from, a.to, b.to).value <= 0 and\n       \
    \  check_ccw(b.from, b.to, a.from).value * check_ccw(b.from, b.to, a.to).value\
    \ <= 0){\n        return result<T>({status_t::OVERLAPPED, {}});\n      }else{\n\
    \        return result<T>({status_t::NOT_INTERSECTED, {}});\n      }\n    }\n\n\
    \    const T t1 = cross(b.from - a.from, diff(b)) / cr;\n    const T t2 = cross(b.from\
    \ - a.from, diff(a)) / cr;\n\n    if(t1 < 0 or t1 > 1 or t2 < 0 or t2 > 1){ //\
    \ no crosspoint\n      return result<T>({status_t::NOT_INTERSECTED, {}});\n  \
    \  }\n\n    return result<T>({status_t::INTERSECTED, {a.from + diff(a) * t1}});\n\
    \  }\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#include <utility>\n\
    #include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T, size_t ... I>\n  static void input_tuple_helper(std::istream\
    \ &s, T &val, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(s\
    \ >> std::get<I>(val)), 0) ...};\n  }\n\n  template <typename T, typename U>\n\
    \  std::istream& operator>>(std::istream &s, std::pair<T, U> &value){\n    s >>\
    \ value.first >> value.second;\n    return s;\n  }\n\n  template <typename ...\
    \ Args>\n  std::istream& operator>>(std::istream &s, std::tuple<Args ...> &value){\n\
    \    input_tuple_helper(s, value, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    return s;\n  }\n}\n#line 8 \"Mylib/IO/input_tuples.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename ... Args>\n  class InputTuples {\n    struct iter {\n\
    \      using value_type = std::tuple<Args ...>;\n      value_type value;\n   \
    \   bool fetched = false;\n      int N, c = 0;\n\n      value_type operator*(){\n\
    \        if(not fetched){\n          std::cin >> value;\n        }\n        return\
    \ value;\n      }\n\n      void operator++(){\n        ++c;\n        fetched =\
    \ false;\n      }\n\n      bool operator!=(iter &) const {\n        return c <\
    \ N;\n      }\n\n      iter(int N): N(N){}\n    };\n\n    int N;\n\n  public:\n\
    \    InputTuples(int N): N(N){}\n\n    iter begin() const {return iter(N);}\n\
    \    iter end() const {return iter(N);}\n  };\n\n  template <typename ... Args>\n\
    \  auto input_tuples(int N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line\
    \ 10 \"test/aoj/CGL_2_C/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nstatic\
    \ constexpr double eps = ERROR;\nusing D = hl::double_eps<double, eps>;\n\nint\
    \ main(){\n  int q; std::cin >> q;\n\n  for(auto [p0, p1, p2, p3] : hl::input_tuples<hl::point<D>,\
    \ hl::point<D>, hl::point<D>, hl::point<D>>(q)){\n    hl::segment<D> s1(p0, p1),\
    \ s2(p2, p3);\n\n    hl::point<D> c = hl::intersect_segments(s1, s2).crosspoints[0];\n\
    \n    std::cout << std::fixed << std::setprecision(12) << c.x << \" \" << c.y\
    \ << std::endl;\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C\"\
    \n#define ERROR 0.00000001\n\n#include <iostream>\n#include <iomanip>\n#include\
    \ \"Mylib/Geometry/Float/geometry_template.cpp\"\n#include \"Mylib/Geometry/Float/double_eps.cpp\"\
    \n#include \"Mylib/Geometry/Float/intersect_segments.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nstatic constexpr double eps = ERROR;\nusing D\
    \ = hl::double_eps<double, eps>;\n\nint main(){\n  int q; std::cin >> q;\n\n \
    \ for(auto [p0, p1, p2, p3] : hl::input_tuples<hl::point<D>, hl::point<D>, hl::point<D>,\
    \ hl::point<D>>(q)){\n    hl::segment<D> s1(p0, p1), s2(p2, p3);\n\n    hl::point<D>\
    \ c = hl::intersect_segments(s1, s2).crosspoints[0];\n\n    std::cout << std::fixed\
    \ << std::setprecision(12) << c.x << \" \" << c.y << std::endl;\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - Mylib/Geometry/Float/geometry_template.cpp
  - Mylib/Geometry/Float/double_eps.cpp
  - Mylib/Geometry/Float/intersect_segments.cpp
  - Mylib/Geometry/Float/ccw.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/CGL_2_C/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_2_C/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_2_C/main.test.cpp
- /verify/test/aoj/CGL_2_C/main.test.cpp.html
title: test/aoj/CGL_2_C/main.test.cpp
---
