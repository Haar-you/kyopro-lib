---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Algorithm/Imos/linear_imos_1d.cpp
    title: 1D Imos algorithm (Linear addition)
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/join.cpp
    title: join function
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3165
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3165
  bundledCode: "#line 1 \"test/aoj/3165/main.test.imos.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3165\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Algorithm/Imos/linear_imos_1d.cpp\"\n\
    #include <vector>\n#include <cassert>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class linear_imos_1d {\n  public:\n    using value_type = T;\n\n  private:\n\
    \    int n_;\n    std::vector<T> vec_a_, vec_a_end_, vec_b_;\n\n  public:\n  \
    \  linear_imos_1d(int n):\n      n_(n), vec_a_(n_ + 1), vec_a_end_(n_ + 1), vec_b_(n_\
    \ + 1){}\n\n    void update(int s, int t, const T &a, const T &b){\n      assert(0\
    \ <= s and s <= t and t <= n_);\n      vec_a_[s + 1] += a;\n      vec_a_[t] -=\
    \ a;\n\n      vec_a_end_[t] -= a * (t - s - 1);\n\n      vec_b_[s] += b;\n   \
    \   vec_b_[t] -= b;\n    }\n\n    auto build() const {\n      std::vector<T> ret(vec_a_);\n\
    \      for(int i = 0; i < n_; ++i) ret[i + 1] += ret[i];\n      for(int i = 0;\
    \ i < n_; ++i) ret[i] += vec_a_end_[i];\n      for(int i = 0; i < n_; ++i) ret[i\
    \ + 1] += ret[i];\n\n      std::vector<T> temp(vec_b_);\n      for(int i = 0;\
    \ i < n_; ++i) temp[i + 1] += temp[i];\n      for(int i = 0; i < n_; ++i) ret[i]\
    \ += temp[i];\n\n      ret.pop_back();\n\n      return ret;\n    }\n  };\n}\n\
    #line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#include <utility>\n\
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
    \ 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n#include <string>\n\nnamespace\
    \ haar_lib {\n  template <typename Iter>\n  std::string join(Iter first, Iter\
    \ last, std::string delim = \" \"){\n    std::stringstream s;\n\n    for(auto\
    \ it = first; it != last; ++it){\n      if(it != first) s << delim;\n      s <<\
    \ *it;\n    }\n\n    return s.str();\n  }\n}\n#line 7 \"test/aoj/3165/main.test.imos.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n\n  auto imos = hl::linear_imos_1d<int64_t>(N);\n\
    \n  for(auto [l, k] : hl::input_tuples<int, int>(Q)){\n    --l;\n    imos.update(l,\
    \ l + k, 1, 1);\n  }\n\n  const auto res = imos.build();\n\n  std::cout << hl::join(res.begin(),\
    \ res.end()) << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3165\"\
    \n\n#include <iostream>\n#include \"Mylib/Algorithm/Imos/linear_imos_1d.cpp\"\n\
    #include \"Mylib/IO/input_tuples.cpp\"\n#include \"Mylib/IO/join.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n\n  auto imos = hl::linear_imos_1d<int64_t>(N);\n\
    \n  for(auto [l, k] : hl::input_tuples<int, int>(Q)){\n    --l;\n    imos.update(l,\
    \ l + k, 1, 1);\n  }\n\n  const auto res = imos.build();\n\n  std::cout << hl::join(res.begin(),\
    \ res.end()) << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Algorithm/Imos/linear_imos_1d.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/IO/join.cpp
  isVerificationFile: true
  path: test/aoj/3165/main.test.imos.cpp
  requiredBy: []
  timestamp: '2020-10-29 12:10:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/3165/main.test.imos.cpp
layout: document
redirect_from:
- /verify/test/aoj/3165/main.test.imos.cpp
- /verify/test/aoj/3165/main.test.imos.cpp.html
title: test/aoj/3165/main.test.imos.cpp
---
