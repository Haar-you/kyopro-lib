---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Algorithm/mo_algorithm.cpp
    title: Mo's algorithm
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Input tuple vector
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0425
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0425
  bundledCode: "#line 1 \"test/aoj/0425/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0425\"\
    \n\n#include <iostream>\n#include <numeric>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\n#line 2 \"Mylib/Algorithm/mo_algorithm.cpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#line 6 \"Mylib/Algorithm/mo_algorithm.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename AppendLeft, typename AppendRight,\
    \ typename RemoveLeft, typename RemoveRight, typename Query>\n  class mo_algorithm\
    \ {\n    int N_, Q_, index_, width_;\n    std::vector<int> left_, right_, ord_;\n\
    \n    AppendLeft append_left_;\n    AppendRight append_right_;\n    RemoveLeft\
    \ remove_left_;\n    RemoveRight remove_right_;\n    Query query_;\n\n    bool\
    \ is_built_ = false;\n\n  public:\n    mo_algorithm() {}\n    mo_algorithm(\n\
    \        int N, int Q,\n        const AppendLeft &append_left, const AppendRight\
    \ &append_right,\n        const RemoveLeft &remove_left, const RemoveRight &remove_right,\n\
    \        const Query &query) : N_(N), Q_(Q), index_(0), width_(std::sqrt(N)),\
    \ left_(Q), right_(Q), ord_(Q), append_left_(append_left), append_right_(append_right),\
    \ remove_left_(remove_left), remove_right_(remove_right), query_(query) {}\n\n\
    \    // [l, r)\n    void add(int l, int r) {\n      left_[index_]  = l;\n    \
    \  right_[index_] = r;\n      ord_[index_]   = index_;\n      ++index_;\n    }\n\
    \n    void run() {\n      std::sort(\n          ord_.begin(), ord_.end(),\n  \
    \        [&](int i, int j) {\n            const int a = left_[i] / width_, b =\
    \ left_[j] / width_;\n            if (a == b) {\n              if (a & 1)\n  \
    \              return right_[i] < right_[j];\n              else\n           \
    \     return right_[i] > right_[j];\n            } else {\n              return\
    \ a < b;\n            }\n          });\n\n      int q = 0;\n      int l = left_[ord_[0]],\
    \ r = left_[ord_[0]];\n\n      for (int i = 0; i < Q_; ++i) {\n        int id\
    \ = ord_[q++];\n\n        while (l != left_[id] or r != right_[id]) {\n      \
    \    if (l > left_[id]) append_left_(--l);\n          if (l < left_[id]) remove_left_(l++);\n\
    \          if (r < right_[id]) append_right_(r++);\n          if (r > right_[id])\
    \ remove_right_(--r);\n        }\n\n        query_(id);\n      }\n    }\n  };\n\
    }  // namespace haar_lib\n#line 2 \"Mylib/IO/input_tuple_vector.cpp\"\n#include\
    \ <initializer_list>\n#line 7 \"Mylib/IO/input_tuple_vector.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T, size_t... I>\n  void input_tuple_vector_init(T\
    \ &val, int N, std::index_sequence<I...>) {\n    (void) std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0)...};\n  }\n\n  template <typename T, size_t... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I...>) {\n    (void) std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0)...};\n  }\n\n  template <typename... Args>\n  auto\
    \ input_tuple_vector(int N) {\n    std::tuple<std::vector<Args>...> ret;\n\n \
    \   input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof...(Args)>());\n\
    \    for (int i = 0; i < N; ++i) {\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof...(Args)>());\n\
    \    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
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
    \  }\n}  // namespace haar_lib\n#line 11 \"test/aoj/0425/main.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, K, Q;\n  std::cin >> N >> K >> Q;\n\n  auto [a, b] = hl::input_tuple_vector<int,\
    \ int>(K);\n  for (auto &x : a) --x;\n  for (auto &x : b) --x;\n\n  std::vector<std::tuple<int,\
    \ int, int, int>> qs;\n  for (auto [type, s, t, x] : hl::input_tuples<int, int,\
    \ int, int>(Q)) {\n    --s, --t, --x;\n    qs.emplace_back(type, s, t, x);\n \
    \ }\n\n  std::vector<int> p(N), q(N);\n  std::iota(p.begin(), p.end(), 0);\n \
    \ std::iota(q.begin(), q.end(), 0);\n\n  std::vector<int> ans(Q);\n\n  auto left\
    \ =\n      [&](int i) {\n        std::swap(q[p[q[a[i]]]], q[p[q[b[i]]]]);\n  \
    \      std::swap(p[q[a[i]]], p[q[b[i]]]);\n      };\n\n  auto right =\n      [&](int\
    \ i) {\n        std::swap(q[p[a[i]]], q[p[b[i]]]);\n        std::swap(p[a[i]],\
    \ p[b[i]]);\n      };\n\n  auto query =\n      [&](int i) {\n        if (std::get<0>(qs[i])\
    \ == 1)\n          ans[i] = p[std::get<3>(qs[i])] + 1;\n        else\n       \
    \   ans[i] = q[std::get<3>(qs[i])] + 1;\n      };\n\n  auto mo = hl::mo_algorithm(N,\
    \ Q, left, right, left, right, query);\n\n  for (int i = 0; i < Q; ++i) mo.add(std::get<1>(qs[i]),\
    \ std::get<2>(qs[i]) + 1);\n  mo.run();\n\n  for (int i = 0; i < Q; ++i) std::cout\
    \ << ans[i] << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0425\"\
    \n\n#include <iostream>\n#include <numeric>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\n#include \"Mylib/Algorithm/mo_algorithm.cpp\"\n#include \"\
    Mylib/IO/input_tuple_vector.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\n\n\
    namespace hl = haar_lib;\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, K, Q;\n  std::cin >> N >> K >> Q;\n\n  auto [a, b] = hl::input_tuple_vector<int,\
    \ int>(K);\n  for (auto &x : a) --x;\n  for (auto &x : b) --x;\n\n  std::vector<std::tuple<int,\
    \ int, int, int>> qs;\n  for (auto [type, s, t, x] : hl::input_tuples<int, int,\
    \ int, int>(Q)) {\n    --s, --t, --x;\n    qs.emplace_back(type, s, t, x);\n \
    \ }\n\n  std::vector<int> p(N), q(N);\n  std::iota(p.begin(), p.end(), 0);\n \
    \ std::iota(q.begin(), q.end(), 0);\n\n  std::vector<int> ans(Q);\n\n  auto left\
    \ =\n      [&](int i) {\n        std::swap(q[p[q[a[i]]]], q[p[q[b[i]]]]);\n  \
    \      std::swap(p[q[a[i]]], p[q[b[i]]]);\n      };\n\n  auto right =\n      [&](int\
    \ i) {\n        std::swap(q[p[a[i]]], q[p[b[i]]]);\n        std::swap(p[a[i]],\
    \ p[b[i]]);\n      };\n\n  auto query =\n      [&](int i) {\n        if (std::get<0>(qs[i])\
    \ == 1)\n          ans[i] = p[std::get<3>(qs[i])] + 1;\n        else\n       \
    \   ans[i] = q[std::get<3>(qs[i])] + 1;\n      };\n\n  auto mo = hl::mo_algorithm(N,\
    \ Q, left, right, left, right, query);\n\n  for (int i = 0; i < Q; ++i) mo.add(std::get<1>(qs[i]),\
    \ std::get<2>(qs[i]) + 1);\n  mo.run();\n\n  for (int i = 0; i < Q; ++i) std::cout\
    \ << ans[i] << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Algorithm/mo_algorithm.cpp
  - Mylib/IO/input_tuple_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/0425/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/0425/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/0425/main.test.cpp
- /verify/test/aoj/0425/main.test.cpp.html
title: test/aoj/0425/main.test.cpp
---