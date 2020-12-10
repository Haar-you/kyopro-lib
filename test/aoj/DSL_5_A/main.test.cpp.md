---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Algorithm/imos_1d.cpp
    title: 1D Imos algorithm
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A
  bundledCode: "#line 1 \"test/aoj/DSL_5_A/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A\"\
    \n\n#include <iostream>\n#include <algorithm>\n#line 2 \"Mylib/Algorithm/imos_1d.cpp\"\
    \n#include <vector>\n#include <cassert>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct imos_1d {\n    using value_type = T;\n\n  private:\n    std::vector<T>\
    \ data_;\n    int n_;\n\n  public:\n    imos_1d(){}\n    imos_1d(int n): data_(n),\
    \ n_(n){}\n\n    void update(int l, int r, T val){ // [l, r)\n      assert(0 <=\
    \ l and l <= r and r <= n_);\n      data_[l] += 1;\n      if(r < n_) data_[r]\
    \ -= 1;\n    }\n\n    auto build() const {\n      std::vector<T> ret(data_);\n\
    \      for(int i = 1; i < n_; ++i){\n        ret[i] += ret[i - 1];\n      }\n\
    \      return ret;\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include\
    \ <tuple>\n#include <utility>\n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
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
    \ ...>(N);\n  }\n}\n#line 7 \"test/aoj/DSL_5_A/main.test.cpp\"\n\nnamespace hl\
    \ = haar_lib;\n\nint main(){\n  int N, T; std::cin >> N >> T;\n  hl::imos_1d<int>\
    \ imos(T + 1);\n\n  for(auto [l, r] : hl::input_tuples<int, int>(N)){\n    imos.update(l,\
    \ r, 1);\n  }\n\n  const auto res = imos.build();\n\n  int ans = *std::max_element(res.begin(),\
    \ res.end());\n\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A\"\
    \n\n#include <iostream>\n#include <algorithm>\n#include \"Mylib/Algorithm/imos_1d.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int N, T; std::cin >> N >> T;\n  hl::imos_1d<int> imos(T + 1);\n\n  for(auto\
    \ [l, r] : hl::input_tuples<int, int>(N)){\n    imos.update(l, r, 1);\n  }\n\n\
    \  const auto res = imos.build();\n\n  int ans = *std::max_element(res.begin(),\
    \ res.end());\n\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Algorithm/imos_1d.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/DSL_5_A/main.test.cpp
  requiredBy: []
  timestamp: '2020-12-09 10:43:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_5_A/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_5_A/main.test.cpp
- /verify/test/aoj/DSL_5_A/main.test.cpp.html
title: test/aoj/DSL_5_A/main.test.cpp
---
