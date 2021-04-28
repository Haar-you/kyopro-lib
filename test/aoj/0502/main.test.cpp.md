---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':heavy_check_mark:'
    path: Mylib/Misc/dice.cpp
    title: Dice
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0502
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0502
  bundledCode: "#line 1 \"test/aoj/0502/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0502\"\
    \n\n#include <iostream>\n#include <string>\n#line 2 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <initializer_list>\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include\
    \ <tuple>\n#include <utility>\n#include <vector>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, size_t... I>\n  static void\
    \ input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>) {\n \
    \   (void) std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};\n\
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
    \  }\n}  // namespace haar_lib\n#line 3 \"Mylib/Misc/dice.cpp\"\n\nnamespace haar_lib\
    \ {\n  struct dice {\n    int top, bottom, front, back, right, left;\n\n    dice()\
    \ : top(), bottom(), front(), back(), right(), left() {}\n    dice(int top, int\
    \ bottom, int front, int back, int right, int left) : top(top), bottom(bottom),\
    \ front(front), back(back), right(right), left(left) {}\n\n    dice rot_left()\
    \ const {\n      return dice(right, left, front, back, bottom, top);\n    }\n\n\
    \    dice rot_right() const {\n      return dice(left, right, front, back, top,\
    \ bottom);\n    }\n\n    dice rot_front() const {\n      return dice(back, front,\
    \ top, bottom, right, left);\n    }\n\n    dice rot_back() const {\n      return\
    \ dice(front, back, bottom, top, right, left);\n    }\n\n    dice rot_clockwise()\
    \ const {\n      return dice(top, bottom, right, left, back, front);\n    }\n\n\
    \    dice rot_counterclockwise() const {\n      return dice(top, bottom, left,\
    \ right, front, back);\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &s, const dice &a) {\n      s << \"(\"\n        << a.top << \", \"\n       \
    \ << a.bottom << \", \"\n        << a.front << \", \"\n        << a.back << \"\
    , \"\n        << a.right << \", \"\n        << a.left << \")\";\n      return\
    \ s;\n    }\n  };\n}  // namespace haar_lib\n#line 7 \"test/aoj/0502/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  int N;\n  while (std::cin >> N,\
    \ N) {\n    auto d = hl::dice(1, 6, 2, 5, 3, 4);\n\n    int ans = 1;\n\n    for\
    \ (auto [s] : hl::input_tuples<std::string>(N)) {\n      if (s == \"North\") d\
    \ = d.rot_back(), ans += d.top;\n      if (s == \"East\") d = d.rot_right(), ans\
    \ += d.top;\n      if (s == \"West\") d = d.rot_left(), ans += d.top;\n      if\
    \ (s == \"South\") d = d.rot_front(), ans += d.top;\n      if (s == \"Right\"\
    ) d = d.rot_clockwise(), ans += d.top;\n      if (s == \"Left\") d = d.rot_counterclockwise(),\
    \ ans += d.top;\n    }\n\n    std::cout << ans << \"\\n\";\n  }\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0502\"\
    \n\n#include <iostream>\n#include <string>\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n#include \"Mylib/Misc/dice.cpp\"\n\nnamespace hl = haar_lib;\n\nint main() {\n\
    \  int N;\n  while (std::cin >> N, N) {\n    auto d = hl::dice(1, 6, 2, 5, 3,\
    \ 4);\n\n    int ans = 1;\n\n    for (auto [s] : hl::input_tuples<std::string>(N))\
    \ {\n      if (s == \"North\") d = d.rot_back(), ans += d.top;\n      if (s ==\
    \ \"East\") d = d.rot_right(), ans += d.top;\n      if (s == \"West\") d = d.rot_left(),\
    \ ans += d.top;\n      if (s == \"South\") d = d.rot_front(), ans += d.top;\n\
    \      if (s == \"Right\") d = d.rot_clockwise(), ans += d.top;\n      if (s ==\
    \ \"Left\") d = d.rot_counterclockwise(), ans += d.top;\n    }\n\n    std::cout\
    \ << ans << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/Misc/dice.cpp
  isVerificationFile: true
  path: test/aoj/0502/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/0502/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/0502/main.test.cpp
- /verify/test/aoj/0502/main.test.cpp.html
title: test/aoj/0502/main.test.cpp
---
