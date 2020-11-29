---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Algorithm/Imos/imos_2d.cpp
    title: 2D Imos algorithm
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
  bundledCode: "#line 1 \"test/aoj/DSL_5_B/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n\n#include <iostream>\n#include <algorithm>\n#line 2 \"Mylib/Algorithm/Imos/imos_2d.cpp\"\
    \n#include <vector>\n#include <cassert>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct imos_2d {\n    using value_type = T;\n\n  private:\n    std::vector<std::vector<T>>\
    \ data_;\n    int n_, m_;\n\n  public:\n    imos_2d(){}\n    imos_2d(int n, int\
    \ m): data_(n, std::vector<T>(m)), n_(n), m_(m){}\n\n    void update(std::pair<int,\
    \ int> p1, std::pair<int, int> p2, T val){\n      const auto [x1, y1] = p1;\n\
    \      const auto [x2, y2] = p2;\n      assert(0 <= x1 and x1 <= x2 and x2 <=\
    \ n_);\n      assert(0 <= y1 and y1 <= y2 and y2 <= m_);\n\n      data_[x1][y1]\
    \ += val;\n      if(x2 < n_ and y2 < m_) data_[x2][y2] += val;\n      if(y2 <\
    \ m_) data_[x1][y2] -= val;\n      if(x2 < n_) data_[x2][y1] -= val;\n    }\n\n\
    \    auto build() const {\n      std::vector<std::vector<T>> ret(data_);\n   \
    \   for(int i = 1; i < n_; ++i){\n        for(int j = 0; j < m_; ++j){\n     \
    \     ret[i][j] += ret[i - 1][j];\n        }\n      }\n\n      for(int i = 0;\
    \ i < n_; ++i){\n        for(int j = 1; j < m_; ++j){\n          ret[i][j] +=\
    \ ret[i][j - 1];\n        }\n      }\n      return ret;\n    }\n  };\n}\n#line\
    \ 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#include <utility>\n#include\
    \ <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T, size_t ... I>\n  static void input_tuple_helper(std::istream\
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
    \ 7 \"test/aoj/DSL_5_B/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int N; std::cin >> N;\n  hl::imos_2d<int> imos(1000, 1000);\n\n  for(auto [x1,\
    \ y1, x2, y2] : hl::input_tuples<int, int, int, int>(N)){\n    imos.update({x1,\
    \ y1}, {x2, y2}, 1);\n  }\n\n  const auto res = imos.build();\n\n  int ans = 0;\n\
    \  for(auto &v : res){\n    ans = std::max(ans, *std::max_element(v.begin(), v.end()));\n\
    \  }\n\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n\n#include <iostream>\n#include <algorithm>\n#include \"Mylib/Algorithm/Imos/imos_2d.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int N; std::cin >> N;\n  hl::imos_2d<int> imos(1000, 1000);\n\n  for(auto [x1,\
    \ y1, x2, y2] : hl::input_tuples<int, int, int, int>(N)){\n    imos.update({x1,\
    \ y1}, {x2, y2}, 1);\n  }\n\n  const auto res = imos.build();\n\n  int ans = 0;\n\
    \  for(auto &v : res){\n    ans = std::max(ans, *std::max_element(v.begin(), v.end()));\n\
    \  }\n\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Algorithm/Imos/imos_2d.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/DSL_5_B/main.test.cpp
  requiredBy: []
  timestamp: '2020-10-11 03:06:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_5_B/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_5_B/main.test.cpp
- /verify/test/aoj/DSL_5_B/main.test.cpp.html
title: test/aoj/DSL_5_B/main.test.cpp
---
