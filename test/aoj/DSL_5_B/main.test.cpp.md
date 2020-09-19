---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Algorithm/Imos/imos_2d.cpp
    title: 2D Imos algorithm
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Mylib/IO/input_tuples.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Mylib/IO/input_tuple.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
  bundledCode: "#line 1 \"test/aoj/DSL_5_B/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n\n#include <iostream>\n#include <algorithm>\n#line 2 \"Mylib/Algorithm/Imos/imos_2d.cpp\"\
    \n#include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  struct\
    \ imos_2d {\n    using value_type = T;\n\n    std::vector<std::vector<T>> vec;\n\
    \    int n, m;\n    imos_2d(int n, int m): vec(n + 1, std::vector<T>(m + 1)),\
    \ n(n), m(m){}\n\n    void add(int a1, int b1, int a2, int b2){ // [a1, a2) [b1,\
    \ b2)\n      vec[a1][b1] += 1;\n      vec[a2][b2] += 1;\n      vec[a1][b2] -=\
    \ 1;\n      vec[a2][b1] -= 1;\n    }\n\n    void build(){\n      for(int i = 0;\
    \ i < n; ++i){\n        for(int j = 0; j < m + 1; ++j){\n          vec[i + 1][j]\
    \ += vec[i][j];\n        }\n      }\n\n      for(int i = 0; i < n + 1; ++i){\n\
    \        for(int j = 0; j < m; ++j){\n          vec[i][j + 1] += vec[i][j];\n\
    \        }\n      }\n    }\n\n    const std::vector<T>& operator[](size_t i) const\
    \ {return vec[i];}\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n\
    #include <utility>\n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, size_t ... I>\n  static void\
    \ input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){\n \
    \   (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};\n\
    \  }\n\n  template <typename T, typename U>\n  std::istream& operator>>(std::istream\
    \ &s, std::pair<T, U> &value){\n    s >> value.first >> value.second;\n    return\
    \ s;\n  }\n\n  template <typename ... Args>\n  std::istream& operator>>(std::istream\
    \ &s, std::tuple<Args ...> &value){\n    input_tuple_helper(s, value, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    return s;\n  }\n}\n#line 8 \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename ... Args>\n  class InputTuples\
    \ {\n    struct iter {\n      using value_type = std::tuple<Args ...>;\n     \
    \ value_type value;\n      bool fetched = false;\n      int N, c = 0;\n\n    \
    \  value_type operator*(){\n        if(not fetched){\n          std::cin >> value;\n\
    \        }\n        return value;\n      }\n\n      void operator++(){\n     \
    \   ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter &) const\
    \ {\n        return c < N;\n      }\n\n      iter(int N): N(N){}\n    };\n\n \
    \   int N;\n\n  public:\n    InputTuples(int N): N(N){}\n\n    iter begin() const\
    \ {return iter(N);}\n    iter end() const {return iter(N);}\n  };\n\n  template\
    \ <typename ... Args>\n  auto input_tuples(int N){\n    return InputTuples<Args\
    \ ...>(N);\n  }\n}\n#line 7 \"test/aoj/DSL_5_B/main.test.cpp\"\n\nnamespace hl\
    \ = haar_lib;\n\nint main(){\n  int N; std::cin >> N;\n  hl::imos_2d<int> imos(1000,\
    \ 1000);\n\n  for(auto [x1, y1, x2, y2] : hl::input_tuples<int, int, int, int>(N)){\n\
    \    imos.add(x1, y1, x2, y2);\n  }\n\n  imos.build();\n\n  int ans = 0;\n  for(int\
    \ i = 0; i < 1000; ++i){\n    for(int j = 0; j < 1000; ++j){\n      ans = std::max(ans,\
    \ imos[i][j]);\n    }\n  }\n\n  std::cout << ans << std::endl;\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n\n#include <iostream>\n#include <algorithm>\n#include \"Mylib/Algorithm/Imos/imos_2d.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int N; std::cin >> N;\n  hl::imos_2d<int> imos(1000, 1000);\n\n  for(auto [x1,\
    \ y1, x2, y2] : hl::input_tuples<int, int, int, int>(N)){\n    imos.add(x1, y1,\
    \ x2, y2);\n  }\n\n  imos.build();\n\n  int ans = 0;\n  for(int i = 0; i < 1000;\
    \ ++i){\n    for(int j = 0; j < 1000; ++j){\n      ans = std::max(ans, imos[i][j]);\n\
    \    }\n  }\n\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Algorithm/Imos/imos_2d.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/DSL_5_B/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_5_B/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_5_B/main.test.cpp
- /verify/test/aoj/DSL_5_B/main.test.cpp.html
title: test/aoj/DSL_5_B/main.test.cpp
---
