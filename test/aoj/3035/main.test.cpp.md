---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/max.cpp
    title: Max monoid
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/min.cpp
    title: Min monoid
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/sum.cpp
    title: Sum monoid
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/Monoid/with_count.cpp
    title: With count
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/MonoidAction/add_max_with_count.cpp
    title: Range add / Range max with count
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/MonoidAction/add_min_with_count.cpp
    title: Range add / Range min with count
  - icon: ':question:'
    path: Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
    title: Lazy segment tree
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3035
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3035
  bundledCode: "#line 1 \"test/aoj/3035/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3035\"\
    \n\n#include <algorithm>\n#include <climits>\n#include <iostream>\n#include <map>\n\
    #line 3 \"Mylib/AlgebraicStructure/Monoid/max.cpp\"\n#include <optional>\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct max_monoid {\n    using value_type\
    \ = std::optional<T>;\n\n    value_type operator()() const { return {}; }\n  \
    \  value_type operator()(const value_type &a, const value_type &b) const {\n \
    \     if (not a) return b;\n      if (not b) return a;\n      return {std::max(*a,\
    \ *b)};\n    }\n  };\n}  // namespace haar_lib\n#line 4 \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct min_monoid {\n   \
    \ using value_type = std::optional<T>;\n\n    value_type operator()() const {\
    \ return {}; }\n    value_type operator()(const value_type &a, const value_type\
    \ &b) const {\n      if (not a) return b;\n      if (not b) return a;\n      return\
    \ {std::min(*a, *b)};\n    }\n  };\n}  // namespace haar_lib\n#line 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct sum_monoid {\n   \
    \ using value_type = T;\n    value_type operator()() const { return 0; }\n   \
    \ value_type operator()(value_type a, value_type b) const { return a + b; }\n\
    \  };\n}  // namespace haar_lib\n#line 2 \"Mylib/AlgebraicStructure/Monoid/with_count.cpp\"\
    \n#include <cstdint>\n#include <utility>\n\nnamespace haar_lib {\n  namespace\
    \ with_count_impl {\n    template <typename T>\n    struct internal_value {\n\
    \      T value;\n      int64_t count;\n      internal_value() : value(T()), count(0)\
    \ {}\n      internal_value(T value) : value(value), count(1) {}\n      internal_value(T\
    \ value, int64_t count) : value(value), count(count) {}\n    };\n  }  // namespace\
    \ with_count_impl\n\n  template <typename Monoid>\n  struct with_count {\n   \
    \ using value_type = with_count_impl::internal_value<typename Monoid::value_type>;\n\
    \    const static Monoid M;\n\n    value_type operator()() const {\n      return\
    \ {M(), 0};\n    }\n\n    value_type operator()(const value_type &a, const value_type\
    \ &b) const {\n      if (a.value == b.value) return {a.value, a.count + b.count};\n\
    \      if (M(a.value, b.value) == a.value) return a;\n      return b;\n    }\n\
    \  };\n}  // namespace haar_lib\n#line 2 \"Mylib/AlgebraicStructure/MonoidAction/add_max_with_count.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename MonoidUpdate, typename MonoidGet>\n\
    \  struct add_max_with_count {\n    using monoid_get        = MonoidGet;\n   \
    \ using monoid_update     = MonoidUpdate;\n    using value_type_get    = typename\
    \ MonoidGet::value_type;\n    using value_type_update = typename MonoidUpdate::value_type;\n\
    \n    value_type_get operator()(const value_type_get &a, const value_type_update\
    \ &b, int) const {\n      return {a.value ? a.value.value() + b : a.value, a.count};\n\
    \    }\n  };\n}  // namespace haar_lib\n#line 2 \"Mylib/AlgebraicStructure/MonoidAction/add_min_with_count.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename MonoidUpdate, typename MonoidGet>\n\
    \  struct add_min_with_count {\n    using monoid_get        = MonoidGet;\n   \
    \ using monoid_update     = MonoidUpdate;\n    using value_type_get    = typename\
    \ MonoidGet::value_type;\n    using value_type_update = typename MonoidUpdate::value_type;\n\
    \n    value_type_get operator()(const value_type_get &a, const value_type_update\
    \ &b, int) const {\n      return {a.value ? a.value.value() + b : a.value, a.count};\n\
    \    }\n  };\n}  // namespace haar_lib\n#line 2 \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\
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
    \n#include <tuple>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T, size_t... I>\n  static void input_tuple_helper(std::istream\
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
    \  }\n}  // namespace haar_lib\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int N) {\n\
    \    std::vector<T> ret(N);\n    for (int i = 0; i < N; ++i) std::cin >> ret[i];\n\
    \    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M) {\n    std::vector<std::vector<T>> ret(N);\n    for\
    \ (int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n\
    }  // namespace haar_lib\n#line 16 \"test/aoj/3035/main.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nusing sum                = hl::sum_monoid<int64_t>;\nusing\
    \ max_with_count     = hl::with_count<hl::max_monoid<int64_t>>;\nusing min_with_count\
    \     = hl::with_count<hl::min_monoid<int64_t>>;\nusing add_max_with_count = hl::add_max_with_count<sum,\
    \ max_with_count>;\nusing add_min_with_count = hl::add_min_with_count<sum, min_with_count>;\n\
    \nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ H, W, Q;\n  std::cin >> H >> W >> Q;\n  auto A = hl::input_vector<int64_t>(H);\n\
    \  auto B = hl::input_vector<int64_t>(W);\n\n  auto seg_h_max = hl::lazy_segment_tree<add_max_with_count>(H);\n\
    \  auto seg_h_min = hl::lazy_segment_tree<add_min_with_count>(H);\n  auto seg_w_max\
    \ = hl::lazy_segment_tree<add_max_with_count>(W);\n  auto seg_w_min = hl::lazy_segment_tree<add_min_with_count>(W);\n\
    \n  seg_h_max.init_with_vector(A);\n  seg_h_min.init_with_vector(A);\n  seg_w_max.init_with_vector(B);\n\
    \  seg_w_min.init_with_vector(B);\n\n  for (auto [type] : hl::input_tuples<int>(Q))\
    \ {\n    switch (type) {\n      case 1: {\n        int a, b, v;\n        std::cin\
    \ >> a >> b >> v;\n        --a;\n        seg_h_max.update(a, b, v);\n        seg_h_min.update(a,\
    \ b, v);\n        break;\n      }\n\n      case 2: {\n        int c, d, v;\n \
    \       std::cin >> c >> d >> v;\n        --c;\n        seg_w_max.update(c, d,\
    \ v);\n        seg_w_min.update(c, d, v);\n        break;\n      }\n\n      case\
    \ 3: {\n        int64_t a, b, c, d;\n        std::cin >> a >> b >> c >> d;\n \
    \       --a, --c;\n\n        std::map<int64_t, int64_t> m;\n\n        auto x =\
    \ std::vector{seg_h_max.fold(a, b), seg_h_min.fold(a, b)};\n        auto y = std::vector{seg_w_max.fold(c,\
    \ d), seg_w_min.fold(c, d)};\n\n        if (x[0].value == x[1].value) x.pop_back();\n\
    \        if (y[0].value == y[1].value) y.pop_back();\n\n        int64_t M = LLONG_MAX;\n\
    \        for (auto p : x) {\n          for (auto q : y) {\n            M = std::min(M,\
    \ *p.value * *q.value);\n          }\n        }\n\n        if (M == 0) {\n   \
    \       int64_t p = 0;\n          for (auto e : x)\n            if (e.value ==\
    \ 0) p += e.count;\n          int64_t q = 0;\n          for (auto e : y)\n   \
    \         if (e.value == 0) q += e.count;\n          m[0] = (b - a) * q + (d -\
    \ c) * p - p * q;\n        } else {\n          for (auto p : x) {\n          \
    \  for (auto q : y) {\n              m[*p.value * *q.value] += p.count * q.count;\n\
    \            }\n          }\n        }\n\n        std::cout << m.begin()->first\
    \ << \" \" << m.begin()->second << \"\\n\";\n\n        break;\n      }\n\n   \
    \   case 4: {\n        int64_t a, b, c, d;\n        std::cin >> a >> b >> c >>\
    \ d;\n        --a, --c;\n\n        std::map<int64_t, int64_t> m;\n\n        auto\
    \ x = std::vector{seg_h_max.fold(a, b), seg_h_min.fold(a, b)};\n        auto y\
    \ = std::vector{seg_w_max.fold(c, d), seg_w_min.fold(c, d)};\n\n        if (x[0].value\
    \ == x[1].value) x.pop_back();\n        if (y[0].value == y[1].value) y.pop_back();\n\
    \n        int64_t M = LLONG_MIN;\n        for (auto p : x) {\n          for (auto\
    \ q : y) {\n            M = std::max(M, *p.value * *q.value);\n          }\n \
    \       }\n\n        if (M == 0) {\n          int64_t p = 0;\n          for (auto\
    \ e : x)\n            if (e.value == 0) p += e.count;\n          int64_t q = 0;\n\
    \          for (auto e : y)\n            if (e.value == 0) q += e.count;\n   \
    \       m[0] = (b - a) * q + (d - c) * p - p * q;\n        } else {\n        \
    \  for (auto p : x) {\n            for (auto q : y) {\n              m[*p.value\
    \ * *q.value] += p.count * q.count;\n            }\n          }\n        }\n\n\
    \        std::cout << m.rbegin()->first << \" \" << m.rbegin()->second << \"\\\
    n\";\n\n        break;\n      }\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3035\"\
    \n\n#include <algorithm>\n#include <climits>\n#include <iostream>\n#include <map>\n\
    #include \"Mylib/AlgebraicStructure/Monoid/max.cpp\"\n#include \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n#include \"Mylib/AlgebraicStructure/Monoid/with_count.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/MonoidAction/add_max_with_count.cpp\"\n\
    #include \"Mylib/AlgebraicStructure/MonoidAction/add_min_with_count.cpp\"\n#include\
    \ \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nusing\
    \ sum                = hl::sum_monoid<int64_t>;\nusing max_with_count     = hl::with_count<hl::max_monoid<int64_t>>;\n\
    using min_with_count     = hl::with_count<hl::min_monoid<int64_t>>;\nusing add_max_with_count\
    \ = hl::add_max_with_count<sum, max_with_count>;\nusing add_min_with_count = hl::add_min_with_count<sum,\
    \ min_with_count>;\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int H, W, Q;\n  std::cin >> H >> W >> Q;\n  auto A = hl::input_vector<int64_t>(H);\n\
    \  auto B = hl::input_vector<int64_t>(W);\n\n  auto seg_h_max = hl::lazy_segment_tree<add_max_with_count>(H);\n\
    \  auto seg_h_min = hl::lazy_segment_tree<add_min_with_count>(H);\n  auto seg_w_max\
    \ = hl::lazy_segment_tree<add_max_with_count>(W);\n  auto seg_w_min = hl::lazy_segment_tree<add_min_with_count>(W);\n\
    \n  seg_h_max.init_with_vector(A);\n  seg_h_min.init_with_vector(A);\n  seg_w_max.init_with_vector(B);\n\
    \  seg_w_min.init_with_vector(B);\n\n  for (auto [type] : hl::input_tuples<int>(Q))\
    \ {\n    switch (type) {\n      case 1: {\n        int a, b, v;\n        std::cin\
    \ >> a >> b >> v;\n        --a;\n        seg_h_max.update(a, b, v);\n        seg_h_min.update(a,\
    \ b, v);\n        break;\n      }\n\n      case 2: {\n        int c, d, v;\n \
    \       std::cin >> c >> d >> v;\n        --c;\n        seg_w_max.update(c, d,\
    \ v);\n        seg_w_min.update(c, d, v);\n        break;\n      }\n\n      case\
    \ 3: {\n        int64_t a, b, c, d;\n        std::cin >> a >> b >> c >> d;\n \
    \       --a, --c;\n\n        std::map<int64_t, int64_t> m;\n\n        auto x =\
    \ std::vector{seg_h_max.fold(a, b), seg_h_min.fold(a, b)};\n        auto y = std::vector{seg_w_max.fold(c,\
    \ d), seg_w_min.fold(c, d)};\n\n        if (x[0].value == x[1].value) x.pop_back();\n\
    \        if (y[0].value == y[1].value) y.pop_back();\n\n        int64_t M = LLONG_MAX;\n\
    \        for (auto p : x) {\n          for (auto q : y) {\n            M = std::min(M,\
    \ *p.value * *q.value);\n          }\n        }\n\n        if (M == 0) {\n   \
    \       int64_t p = 0;\n          for (auto e : x)\n            if (e.value ==\
    \ 0) p += e.count;\n          int64_t q = 0;\n          for (auto e : y)\n   \
    \         if (e.value == 0) q += e.count;\n          m[0] = (b - a) * q + (d -\
    \ c) * p - p * q;\n        } else {\n          for (auto p : x) {\n          \
    \  for (auto q : y) {\n              m[*p.value * *q.value] += p.count * q.count;\n\
    \            }\n          }\n        }\n\n        std::cout << m.begin()->first\
    \ << \" \" << m.begin()->second << \"\\n\";\n\n        break;\n      }\n\n   \
    \   case 4: {\n        int64_t a, b, c, d;\n        std::cin >> a >> b >> c >>\
    \ d;\n        --a, --c;\n\n        std::map<int64_t, int64_t> m;\n\n        auto\
    \ x = std::vector{seg_h_max.fold(a, b), seg_h_min.fold(a, b)};\n        auto y\
    \ = std::vector{seg_w_max.fold(c, d), seg_w_min.fold(c, d)};\n\n        if (x[0].value\
    \ == x[1].value) x.pop_back();\n        if (y[0].value == y[1].value) y.pop_back();\n\
    \n        int64_t M = LLONG_MIN;\n        for (auto p : x) {\n          for (auto\
    \ q : y) {\n            M = std::max(M, *p.value * *q.value);\n          }\n \
    \       }\n\n        if (M == 0) {\n          int64_t p = 0;\n          for (auto\
    \ e : x)\n            if (e.value == 0) p += e.count;\n          int64_t q = 0;\n\
    \          for (auto e : y)\n            if (e.value == 0) q += e.count;\n   \
    \       m[0] = (b - a) * q + (d - c) * p - p * q;\n        } else {\n        \
    \  for (auto p : x) {\n            for (auto q : y) {\n              m[*p.value\
    \ * *q.value] += p.count * q.count;\n            }\n          }\n        }\n\n\
    \        std::cout << m.rbegin()->first << \" \" << m.rbegin()->second << \"\\\
    n\";\n\n        break;\n      }\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/AlgebraicStructure/Monoid/max.cpp
  - Mylib/AlgebraicStructure/Monoid/min.cpp
  - Mylib/AlgebraicStructure/Monoid/sum.cpp
  - Mylib/AlgebraicStructure/Monoid/with_count.cpp
  - Mylib/AlgebraicStructure/MonoidAction/add_max_with_count.cpp
  - Mylib/AlgebraicStructure/MonoidAction/add_min_with_count.cpp
  - Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/3035/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/3035/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/3035/main.test.cpp
- /verify/test/aoj/3035/main.test.cpp.html
title: test/aoj/3035/main.test.cpp
---
