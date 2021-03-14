---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Algorithm/cumulative_sum_2d.cpp
    title: 2D cumulative sum
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/755
    links:
    - https://yukicoder.me/problems/no/755
  bundledCode: "#line 1 \"test/yukicoder/755/main.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/755\"\
    \n\n#include <iostream>\n#include <vector>\n#line 3 \"Mylib/Algorithm/cumulative_sum_2d.cpp\"\
    \n#include <functional>\n#include <cassert>\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  class cumulative_sum_2d {\n  public:\n    using value_type =\
    \ T;\n\n  private:\n    template <typename> friend class cumulative_sum_2d_builder;\n\
    \    int N_, M_;\n    std::vector<std::vector<T>> data_;\n\n  public:\n    T fold(std::pair<int,\
    \ int> p1, std::pair<int, int> p2) const {\n      const auto [x1, y1] = p1;\n\
    \      const auto [x2, y2] = p2;\n      assert(0 <= x1 and x1 <= x2 and x2 <=\
    \ N_);\n      assert(0 <= y1 and y1 <= y2 and y2 <= M_);\n      return data_[x2][y2]\
    \ - data_[x1][y2] - data_[x2][y1] + data_[x1][y1];\n    }\n  };\n\n  template\
    \ <typename T>\n  class cumulative_sum_2d_builder {\n    int N_, M_;\n    std::vector<std::vector<T>>\
    \ data_;\n\n  public:\n    cumulative_sum_2d_builder(){}\n    cumulative_sum_2d_builder(int\
    \ N, int M):\n      N_(N), M_(M), data_(N + 1, std::vector<T>(M + 1)){}\n\n  \
    \  auto& update(const std::vector<std::vector<T>> &a){\n      for(int i = 0; i\
    \ < N_; ++i){\n        for(int j = 0; j < M_; ++j){\n          data_[i + 1][j\
    \ + 1] += a[i][j];\n        }\n      }\n      return *this;\n    }\n\n    auto&\
    \ update(int i, int j, const T &val){\n      data_[i + 1][j + 1] += val;\n   \
    \   return *this;\n    }\n\n    auto build() const {\n      cumulative_sum_2d<T>\
    \ ret;\n      ret.data_ = data_;\n      ret.N_ = N_;\n      ret.M_ = M_;\n\n \
    \     for(int i = 1; i <= N_; ++i)\n        for(int j = 0; j <= M_; ++j)\n   \
    \       ret.data_[i][j] += ret.data_[i - 1][j];\n      for(int i = 0; i <= N_;\
    \ ++i)\n        for(int j = 1; j <= M_; ++j)\n          ret.data_[i][j] += ret.data_[i][j\
    \ - 1];\n      return ret;\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
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
    \ 8 \"test/yukicoder/755/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N, M; std::cin\
    \ >> N >> M;\n\n  auto A = hl::input_vector<int64_t>(M, M);\n\n  auto c = hl::cumulative_sum_2d_builder<int64_t>(M,\
    \ M).update(A).build();\n\n  for(auto [x, y] : hl::input_tuples<int, int>(N)){\n\
    \    --x, --y;\n\n    int ans = 0;\n\n    for(int x1 = 0; x1 <= x; ++x1){\n  \
    \    for(int y1 = 0; y1 <= y; ++y1){\n        for(int x2 = x; x2 < M; ++x2){\n\
    \          for(int y2 = y; y2 < M; ++y2){\n            if(c.fold({x1, y1}, {x2\
    \ + 1, y2 + 1}) == 0) ++ans;\n          }\n        }\n      }\n    }\n\n    std::cout\
    \ << ans << std::endl;\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/755\"\n\n#include <iostream>\n\
    #include <vector>\n#include \"Mylib/Algorithm/cumulative_sum_2d.cpp\"\n#include\
    \ \"Mylib/IO/input_vector.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, M; std::cin >> N >> M;\n\n  auto A = hl::input_vector<int64_t>(M, M);\n\
    \n  auto c = hl::cumulative_sum_2d_builder<int64_t>(M, M).update(A).build();\n\
    \n  for(auto [x, y] : hl::input_tuples<int, int>(N)){\n    --x, --y;\n\n    int\
    \ ans = 0;\n\n    for(int x1 = 0; x1 <= x; ++x1){\n      for(int y1 = 0; y1 <=\
    \ y; ++y1){\n        for(int x2 = x; x2 < M; ++x2){\n          for(int y2 = y;\
    \ y2 < M; ++y2){\n            if(c.fold({x1, y1}, {x2 + 1, y2 + 1}) == 0) ++ans;\n\
    \          }\n        }\n      }\n    }\n\n    std::cout << ans << std::endl;\n\
    \  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Algorithm/cumulative_sum_2d.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yukicoder/755/main.test.cpp
  requiredBy: []
  timestamp: '2020-12-09 10:43:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/755/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/755/main.test.cpp
- /verify/test/yukicoder/755/main.test.cpp.html
title: test/yukicoder/755/main.test.cpp
---
