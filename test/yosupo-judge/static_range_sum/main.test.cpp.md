---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Algorithm/cumulative_sum_1d.cpp
    title: 1D cumulative sum
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/yosupo-judge/static_range_sum/main.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include <iostream>\n\
    #line 2 \"Mylib/Algorithm/cumulative_sum_1d.cpp\"\n#include <vector>\n#include\
    \ <functional>\n#include <cassert>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class cumulative_sum_1d {\n  public:\n    using value_type = T;\n\n  private:\n\
    \    template <typename> friend class cumulative_sum_1d_builder;\n    int N_;\n\
    \    std::vector<T> data_;\n\n  public:\n    T fold(int l, int r) const {\n  \
    \    assert(0 <= l and l <= r and r <= N_);\n      return data_[r] - data_[l];\n\
    \    }\n  };\n\n  template <typename T>\n  class cumulative_sum_1d_builder {\n\
    \    int N_;\n    std::vector<T> data_;\n\n  public:\n    cumulative_sum_1d_builder(){}\n\
    \    cumulative_sum_1d_builder(int N): N_(N), data_(N + 1){}\n\n    auto& update(const\
    \ std::vector<T> &a){\n      for(int i = 0; i < N_; ++i) data_[i + 1] += a[i];\n\
    \      return *this;\n    }\n\n    auto& update(int i, const T &val){\n      assert(0\
    \ <= i and i < N_);\n      data_[i + 1] += val;\n      return *this;\n    }\n\n\
    \    auto build() const {\n      cumulative_sum_1d<T> ret;\n      ret.data_ =\
    \ data_;\n      ret.N_ = N_;\n      for(int i = 0; i < N_; ++i) ret.data_[i +\
    \ 1] += ret.data_[i];\n      return ret;\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
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
    \ 7 \"test/yosupo-judge/static_range_sum/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N, Q; std::cin >> N >> Q;\n\n  auto a = hl::input_vector<int64_t>(N);\n\n  auto\
    \ c = hl::cumulative_sum_1d_builder<int64_t>(N).update(a).build();\n\n  for(auto\
    \ [l, r] : hl::input_tuples<int, int>(Q)){\n    std::cout << c.fold(l, r) << \"\
    \\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <iostream>\n#include \"Mylib/Algorithm/cumulative_sum_1d.cpp\"\n#include\
    \ \"Mylib/IO/input_vector.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n\n  auto a = hl::input_vector<int64_t>(N);\n\
    \n  auto c = hl::cumulative_sum_1d_builder<int64_t>(N).update(a).build();\n\n\
    \  for(auto [l, r] : hl::input_tuples<int, int>(Q)){\n    std::cout << c.fold(l,\
    \ r) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Algorithm/cumulative_sum_1d.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/static_range_sum/main.test.cpp
  requiredBy: []
  timestamp: '2020-12-09 10:43:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/static_range_sum/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/static_range_sum/main.test.cpp
- /verify/test/yosupo-judge/static_range_sum/main.test.cpp.html
title: test/yosupo-judge/static_range_sum/main.test.cpp
---
