---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/Monoid/bounded_min.cpp
    title: Bounded min monoid
  - icon: ':x:'
    path: Mylib/DataStructure/SparseTable/sparse_table.cpp
    title: Sparse table
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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/yosupo-judge/staticrmq/main.sparse_table.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <iostream>\n\
    #include <vector>\n#line 2 \"Mylib/AlgebraicStructure/Monoid/bounded_min.cpp\"\
    \n#include <algorithm>\n#include <limits>\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  struct bounded_min_monoid {\n    using value_type = T;\n\n \
    \   value_type operator()() const { return std::numeric_limits<T>::max(); }\n\
    \    value_type operator()(const value_type &a, const value_type &b) const {\n\
    \      return std::min(a, b);\n    }\n  };\n}  // namespace haar_lib\n#line 3\
    \ \"Mylib/DataStructure/SparseTable/sparse_table.cpp\"\n#include <cassert>\n#include\
    \ <optional>\n#include <utility>\n#line 7 \"Mylib/DataStructure/SparseTable/sparse_table.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Semilattice>\n  class sparse_table\
    \ {\n  public:\n    using value_type = typename Semilattice::value_type;\n\n \
    \ private:\n    Semilattice S_;\n\n    int n_;\n    std::vector<std::vector<value_type>>\
    \ data_;\n    std::vector<int> log_table_;\n\n  public:\n    sparse_table() {}\n\
    \    template <typename T>\n    sparse_table(const std::vector<T> &v) : n_(v.size())\
    \ {\n      int logn = 0;\n      while ((1 << logn) <= n_) ++logn;\n\n      data_.assign(n_,\
    \ std::vector<value_type>(logn));\n      for (int i = 0; i < n_; ++i) data_[i][0]\
    \ = v[i];\n      for (int j = 1; j < logn; ++j) {\n        for (int i = 0; i <\
    \ n_; ++i) {\n          data_[i][j] = S_(data_[i][j - 1], data_[std::min<int>(n_\
    \ - 1, i + (1 << (j - 1)))][j - 1]);\n        }\n      }\n\n      log_table_.assign(n_\
    \ + 1, 0);\n      for (int i = 2; i < n_ + 1; ++i) log_table_[i] = log_table_[i\
    \ >> 1] + 1;\n    }\n\n    std::optional<value_type> fold(int l, int r) const\
    \ {\n      assert(0 <= l and l <= r and r <= n_);\n      if (l == r) return std::nullopt;\n\
    \      int k = log_table_[r - l];\n      return S_(data_[l][k], data_[r - (1 <<\
    \ k)][k]);\n    }\n  };\n}  // namespace haar_lib\n#line 2 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <initializer_list>\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include\
    \ <tuple>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T, size_t... I>\n  static void input_tuple_helper(std::istream &s,\
    \ T &val, std::index_sequence<I...>) {\n    (void) std::initializer_list<int>{(void(s\
    \ >> std::get<I>(val)), 0)...};\n  }\n\n  template <typename T, typename U>\n\
    \  std::istream &operator>>(std::istream &s, std::pair<T, U> &value) {\n    s\
    \ >> value.first >> value.second;\n    return s;\n  }\n\n  template <typename...\
    \ Args>\n  std::istream &operator>>(std::istream &s, std::tuple<Args...> &value)\
    \ {\n    input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());\n\
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
    \  }\n}  // namespace haar_lib\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int N) {\n\
    \    std::vector<T> ret(N);\n    for (int i = 0; i < N; ++i) std::cin >> ret[i];\n\
    \    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M) {\n    std::vector<std::vector<T>> ret(N);\n    for\
    \ (int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n\
    }  // namespace haar_lib\n#line 9 \"test/yosupo-judge/staticrmq/main.sparse_table.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q;\n  std::cin >> N >> Q;\n\n  auto a = hl::input_vector<int>(N);\n\
    \n  hl::sparse_table<hl::bounded_min_monoid<int>> s(a);\n\n  for (auto [l, r]\
    \ : hl::input_tuples<int, int>(Q)) {\n    std::cout << s.fold(l, r).value() <<\
    \ \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include \"Mylib/AlgebraicStructure/Monoid/bounded_min.cpp\"\
    \n#include \"Mylib/DataStructure/SparseTable/sparse_table.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nint main()\
    \ {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N, Q;\n\
    \  std::cin >> N >> Q;\n\n  auto a = hl::input_vector<int>(N);\n\n  hl::sparse_table<hl::bounded_min_monoid<int>>\
    \ s(a);\n\n  for (auto [l, r] : hl::input_tuples<int, int>(Q)) {\n    std::cout\
    \ << s.fold(l, r).value() << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/AlgebraicStructure/Monoid/bounded_min.cpp
  - Mylib/DataStructure/SparseTable/sparse_table.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/yosupo-judge/staticrmq/main.sparse_table.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/staticrmq/main.sparse_table.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/staticrmq/main.sparse_table.test.cpp
- /verify/test/yosupo-judge/staticrmq/main.sparse_table.test.cpp.html
title: test/yosupo-judge/staticrmq/main.sparse_table.test.cpp
---