---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Geometry/Float/geometry_template.cpp
    title: Geometry template
  - icon: ':x:'
    path: Mylib/Geometry/Float/manhattan_segments_intersections.cpp
    title: Manhattan segments intersections
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_6_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_6_A
  bundledCode: "#line 1 \"test/aoj/CGL_6_A/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_6_A\"\
    \n\n#include <iostream>\n#include <vector>\n#line 2 \"Mylib/Geometry/Float/geometry_template.cpp\"\
    \n#include <cmath>\n#line 5 \"Mylib/Geometry/Float/geometry_template.cpp\"\n\n\
    namespace haar_lib {\n  template <typename T>\n  struct vec {\n    T x, y;\n \
    \   vec() {}\n    vec(T x, T y) : x(x), y(y) {}\n\n    friend auto operator+(const\
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
    \ << \")\";\n    return s;\n  }\n}  // namespace haar_lib\n#line 2 \"Mylib/Geometry/Float/manhattan_segments_intersections.cpp\"\
    \n#include <algorithm>\n#include <climits>\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\n#include <tuple>\n#include <utility>\n#line\
    \ 10 \"Mylib/Geometry/Float/manhattan_segments_intersections.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  int manhattan_segments_intersections(std::vector<segment<T>>\
    \ segs) {\n    std::vector<segment<T>> hs;\n    std::vector<std::tuple<point<T>,\
    \ bool, int>> vs;\n    int count = 0;\n\n    for (auto s : segs) {\n      if (s.from.y\
    \ == s.to.y) {\n        hs.push_back(s);\n      } else {\n        vs.emplace_back(s.from,\
    \ s.from.y < s.to.y, count);\n        vs.emplace_back(s.to, s.from.y > s.to.y,\
    \ count);\n        ++count;\n      }\n    }\n\n    std::sort(hs.rbegin(), hs.rend(),\
    \ [](const auto &a, const auto &b) { return a.from.y < b.from.y; });\n    std::sort(vs.rbegin(),\
    \ vs.rend(), [](const auto &a, const auto &b) { return std::get<0>(a).y < std::get<0>(b).y;\
    \ });\n\n    __gnu_pbds::tree<\n        std::pair<T, int>,\n        __gnu_pbds::null_type,\n\
    \        std::less<std::pair<T, int>>,\n        __gnu_pbds::rb_tree_tag,\n   \
    \     __gnu_pbds::tree_order_statistics_node_update>\n        set;\n    int64_t\
    \ ans = 0;\n\n    while (true) {\n      if (hs.empty() or vs.empty()) break;\n\
    \n      T ymin = std::min(hs.back().from.y, std::get<0>(vs.back()).y);\n\n   \
    \   std::vector<segment<T>> rs;\n      std::vector<std::tuple<point<T>, bool,\
    \ int>> ps;\n\n      while (not hs.empty() and hs.back().from.y == ymin) {\n \
    \       rs.push_back(hs.back());\n        hs.pop_back();\n      }\n\n      while\
    \ (not vs.empty() and std::get<0>(vs.back()).y == ymin) {\n        ps.push_back(vs.back());\n\
    \        vs.pop_back();\n      }\n\n      for (auto [a, b, c] : ps) {\n      \
    \  if (b) set.insert(std::make_pair(a.x, c));\n      }\n\n      for (auto [a,\
    \ b] : rs) {\n        auto [x1, x2] = std::minmax(a.x, b.x);\n\n        auto ix1\
    \ = set.order_of_key(std::make_pair(x1, 0));\n        auto ix2 = set.order_of_key(std::make_pair(x2,\
    \ INT_MAX));\n\n        ans += ix2 - ix1;\n      }\n\n      for (auto [a, b, c]\
    \ : ps) {\n        if (not b) set.erase(std::make_pair(a.x, c));\n      }\n  \
    \  }\n\n    return ans;\n  }\n}  // namespace haar_lib\n#line 7 \"test/aoj/CGL_6_A/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int n;\n  std::cin >> n;\n  std::vector<hl::segment<int>> s(n);\n  for (int\
    \ i = 0; i < n; ++i) {\n    std::cin >> s[i].from >> s[i].to;\n  }\n\n  auto ans\
    \ = hl::manhattan_segments_intersections(s);\n  std::cout << ans << \"\\n\";\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_6_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Geometry/Float/geometry_template.cpp\"\
    \n#include \"Mylib/Geometry/Float/manhattan_segments_intersections.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int n;\n  std::cin >> n;\n  std::vector<hl::segment<int>> s(n);\n  for (int\
    \ i = 0; i < n; ++i) {\n    std::cin >> s[i].from >> s[i].to;\n  }\n\n  auto ans\
    \ = hl::manhattan_segments_intersections(s);\n  std::cout << ans << \"\\n\";\n\
    \n  return 0;\n}\n"
  dependsOn:
  - Mylib/Geometry/Float/geometry_template.cpp
  - Mylib/Geometry/Float/manhattan_segments_intersections.cpp
  isVerificationFile: true
  path: test/aoj/CGL_6_A/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/CGL_6_A/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_6_A/main.test.cpp
- /verify/test/aoj/CGL_6_A/main.test.cpp.html
title: test/aoj/CGL_6_A/main.test.cpp
---
