---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/min.cpp
    title: Min monoid
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/Monoid/update.cpp
    title: Update monoid
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/MonoidAction/update_min.cpp
    title: Range update / Range min
  - icon: ':question:'
    path: Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
    title: Lazy segment tree
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
  bundledCode: "#line 1 \"test/aoj/DSL_2_F/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#include <climits>\n#include <iostream>\n#line 2 \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\
    \n#include <algorithm>\n#include <optional>\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  struct min_monoid {\n    using value_type = std::optional<T>;\n\
    \n    value_type operator()() const { return {}; }\n    value_type operator()(const\
    \ value_type &a, const value_type &b) const {\n      if (not a) return b;\n  \
    \    if (not b) return a;\n      return {std::min(*a, *b)};\n    }\n  };\n}  //\
    \ namespace haar_lib\n#line 3 \"Mylib/AlgebraicStructure/Monoid/update.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename T>\n  struct update_monoid {\n  \
    \  using value_type = std::optional<T>;\n    value_type operator()() const { return\
    \ std::nullopt; }\n    value_type operator()(const value_type &a, const value_type\
    \ &b) const { return (a ? a : b); }\n  };\n}  // namespace haar_lib\n#line 2 \"\
    Mylib/AlgebraicStructure/MonoidAction/update_min.cpp\"\n\nnamespace haar_lib {\n\
    \  template <typename MonoidUpdate, typename MonoidGet>\n  struct update_min {\n\
    \    using monoid_get        = MonoidGet;\n    using monoid_update     = MonoidUpdate;\n\
    \    using value_type_get    = typename MonoidGet::value_type;\n    using value_type_update\
    \ = typename MonoidUpdate::value_type;\n\n    value_type_get operator()(value_type_get\
    \ a, value_type_update b, int) const {\n      return b ? *b : a;\n    }\n  };\n\
    }  // namespace haar_lib\n#line 2 \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\
    \n#include <cassert>\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ Monoid>\n  class lazy_segment_tree {\n  public:\n    using monoid_get      \
    \  = typename Monoid::monoid_get;\n    using monoid_update     = typename Monoid::monoid_update;\n\
    \    using value_type_get    = typename monoid_get::value_type;\n    using value_type_update\
    \ = typename monoid_update::value_type;\n\n  private:\n    Monoid M_;\n    monoid_get\
    \ M_get_;\n    monoid_update M_update_;\n\n    int depth_, size_, hsize_;\n  \
    \  std::vector<value_type_get> data_;\n    std::vector<value_type_update> lazy_;\n\
    \n    void propagate(int i) {\n      if (lazy_[i] == M_update_()) return;\n  \
    \    if (i < hsize_) {\n        lazy_[i << 1 | 0] = M_update_(lazy_[i], lazy_[i\
    \ << 1 | 0]);\n        lazy_[i << 1 | 1] = M_update_(lazy_[i], lazy_[i << 1 |\
    \ 1]);\n      }\n      const int len = hsize_ >> (31 - __builtin_clz(i));\n  \
    \    data_[i]      = M_(data_[i], lazy_[i], len);\n      lazy_[i]      = M_update_();\n\
    \    }\n\n    void propagate_top_down(int i) {\n      std::vector<int> temp;\n\
    \      while (i > 1) {\n        i >>= 1;\n        temp.push_back(i);\n      }\n\
    \n      for (auto it = temp.rbegin(); it != temp.rend(); ++it) propagate(*it);\n\
    \    }\n\n    void bottom_up(int i) {\n      while (i > 1) {\n        i >>= 1;\n\
    \        propagate(i << 1 | 0);\n        propagate(i << 1 | 1);\n        data_[i]\
    \ = M_get_(data_[i << 1 | 0], data_[i << 1 | 1]);\n      }\n    }\n\n  public:\n\
    \    lazy_segment_tree() {}\n    lazy_segment_tree(int n) : depth_(n > 1 ? 32\
    \ - __builtin_clz(n - 1) + 1 : 1),\n                               size_(1 <<\
    \ depth_),\n                               hsize_(size_ / 2),\n              \
    \                 data_(size_, M_get_()),\n                               lazy_(size_,\
    \ M_update_()) {}\n\n    void update(int l, int r, const value_type_update &x)\
    \ {\n      assert(0 <= l and l <= r and r <= hsize_);\n      propagate_top_down(l\
    \ + hsize_);\n      if (r < hsize_) propagate_top_down(r + hsize_);\n\n      int\
    \ L = l + hsize_, R = r + hsize_;\n\n      while (L < R) {\n        if (R & 1)\
    \ {\n          --R;\n          lazy_[R] = M_update_(x, lazy_[R]);\n          propagate(R);\n\
    \        }\n        if (L & 1) {\n          lazy_[L] = M_update_(x, lazy_[L]);\n\
    \          propagate(L);\n          ++L;\n        }\n        L >>= 1;\n      \
    \  R >>= 1;\n      }\n\n      bottom_up(l + hsize_);\n      if (r < hsize_) bottom_up(r\
    \ + hsize_);\n    }\n\n    void update(int i, const value_type_update &x) { update(i,\
    \ i + 1, x); }\n\n    value_type_get fold(int l, int r) {\n      assert(0 <= l\
    \ and l <= r and r <= hsize_);\n      propagate_top_down(l + hsize_);\n      if\
    \ (r < hsize_) propagate_top_down(r + hsize_);\n\n      value_type_get ret_left\
    \ = M_get_(), ret_right = M_get_();\n\n      int L = l + hsize_, R = r + hsize_;\n\
    \n      while (L < R) {\n        if (R & 1) {\n          --R;\n          propagate(R);\n\
    \          ret_right = M_get_(data_[R], ret_right);\n        }\n        if (L\
    \ & 1) {\n          propagate(L);\n          ret_left = M_get_(ret_left, data_[L]);\n\
    \          ++L;\n        }\n        L >>= 1;\n        R >>= 1;\n      }\n\n  \
    \    return M_get_(ret_left, ret_right);\n    }\n\n    value_type_get fold_all()\
    \ {\n      return fold(0, hsize_);\n    }\n\n    value_type_get operator[](int\
    \ i) { return fold(i, i + 1); }\n\n    template <typename T>\n    void init(const\
    \ T &val) {\n      init_with_vector(std::vector<T>(hsize_, val));\n    }\n\n \
    \   template <typename T>\n    void init_with_vector(const std::vector<T> &val)\
    \ {\n      data_.assign(size_, M_get_());\n      lazy_.assign(size_, M_update_());\n\
    \      for (int i = 0; i < (int) val.size(); ++i) data_[hsize_ + i] = (value_type_get)\
    \ val[i];\n      for (int i = hsize_; --i > 0;) data_[i] = M_get_(data_[i << 1\
    \ | 0], data_[i << 1 | 1]);\n    }\n  };\n}  // namespace haar_lib\n#line 2 \"\
    Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <tuple>\n#include <utility>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename T, size_t... I>\n  static void input_tuple_helper(std::istream\
    \ &s, T &val, std::index_sequence<I...>) {\n    (void) std::initializer_list<int>{(void(s\
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
    \  }\n}  // namespace haar_lib\n#line 10 \"test/aoj/DSL_2_F/main.test.cpp\"\n\n\
    namespace hl = haar_lib;\n\nusing update = hl::update_monoid<int>;\nusing min\
    \    = hl::min_monoid<int>;\n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n\
    \n  hl::lazy_segment_tree<hl::update_min<update, min>> seg(n);\n\n  for (auto\
    \ [type, s, t] : hl::input_tuples<int, int, int>(q)) {\n    if (type == 0) {\n\
    \      int x;\n      std::cin >> x;\n      seg.update(s, t + 1, x);\n    } else\
    \ {\n      std::cout << seg.fold(s, t + 1).value_or(INT_MAX) << std::endl;\n \
    \   }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#include <climits>\n#include <iostream>\n#include \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/Monoid/update.cpp\"\n#include \"Mylib/AlgebraicStructure/MonoidAction/update_min.cpp\"\
    \n#include \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\n#include\
    \ \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nusing update =\
    \ hl::update_monoid<int>;\nusing min    = hl::min_monoid<int>;\n\nint main() {\n\
    \  int n, q;\n  std::cin >> n >> q;\n\n  hl::lazy_segment_tree<hl::update_min<update,\
    \ min>> seg(n);\n\n  for (auto [type, s, t] : hl::input_tuples<int, int, int>(q))\
    \ {\n    if (type == 0) {\n      int x;\n      std::cin >> x;\n      seg.update(s,\
    \ t + 1, x);\n    } else {\n      std::cout << seg.fold(s, t + 1).value_or(INT_MAX)\
    \ << std::endl;\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/AlgebraicStructure/Monoid/min.cpp
  - Mylib/AlgebraicStructure/Monoid/update.cpp
  - Mylib/AlgebraicStructure/MonoidAction/update_min.cpp
  - Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_F/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_F/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_F/main.test.cpp
- /verify/test/aoj/DSL_2_F/main.test.cpp.html
title: test/aoj/DSL_2_F/main.test.cpp
---
