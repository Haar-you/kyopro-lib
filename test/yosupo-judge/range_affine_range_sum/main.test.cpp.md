---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/Monoid/affine.cpp
    title: Affine monoid
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/sum.cpp
    title: Sum monoid
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp
    title: Range affine / Range sum
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
  - icon: ':x:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo-judge/range_affine_range_sum/main.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#include <iostream>\n#include <vector>\n#line 2 \"Mylib/AlgebraicStructure/Monoid/affine.cpp\"\
    \n#include <utility>\n\nnamespace haar_lib {\n  template <typename T>\n  struct\
    \ affine_monoid {\n    using value_type = std::pair<T, T>;\n    value_type operator()()\
    \ const { return std::make_pair(1, 0); }\n    value_type operator()(const value_type\
    \ &a, const value_type &b) const {\n      return std::make_pair(a.first * b.first,\
    \ a.first * b.second + a.second);\n    }\n  };\n}  // namespace haar_lib\n#line\
    \ 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  struct sum_monoid {\n    using value_type = T;\n    value_type\
    \ operator()() const { return 0; }\n    value_type operator()(value_type a, value_type\
    \ b) const { return a + b; }\n  };\n}  // namespace haar_lib\n#line 2 \"Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename MonoidUpdate, typename MonoidGet>\n\
    \  struct affine_sum {\n    using monoid_get        = MonoidGet;\n    using monoid_update\
    \     = MonoidUpdate;\n    using value_type_get    = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(value_type_get a, value_type_update b, int len) const {\n      return\
    \ b.first * a + b.second * len;\n    }\n  };\n}  // namespace haar_lib\n#line\
    \ 2 \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\n#include <cassert>\n\
    #line 4 \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename Monoid>\n  class lazy_segment_tree {\n  public:\n\
    \    using monoid_get        = typename Monoid::monoid_get;\n    using monoid_update\
    \     = typename Monoid::monoid_update;\n    using value_type_get    = typename\
    \ monoid_get::value_type;\n    using value_type_update = typename monoid_update::value_type;\n\
    \n  private:\n    Monoid M_;\n    monoid_get M_get_;\n    monoid_update M_update_;\n\
    \n    int depth_, size_, hsize_;\n    std::vector<value_type_get> data_;\n   \
    \ std::vector<value_type_update> lazy_;\n\n    void propagate(int i) {\n     \
    \ if (lazy_[i] == M_update_()) return;\n      if (i < hsize_) {\n        lazy_[i\
    \ << 1 | 0] = M_update_(lazy_[i], lazy_[i << 1 | 0]);\n        lazy_[i << 1 |\
    \ 1] = M_update_(lazy_[i], lazy_[i << 1 | 1]);\n      }\n      const int len =\
    \ hsize_ >> (31 - __builtin_clz(i));\n      data_[i]      = M_(data_[i], lazy_[i],\
    \ len);\n      lazy_[i]      = M_update_();\n    }\n\n    void propagate_top_down(int\
    \ i) {\n      std::vector<int> temp;\n      while (i > 1) {\n        i >>= 1;\n\
    \        temp.push_back(i);\n      }\n\n      for (auto it = temp.rbegin(); it\
    \ != temp.rend(); ++it) propagate(*it);\n    }\n\n    void bottom_up(int i) {\n\
    \      while (i > 1) {\n        i >>= 1;\n        propagate(i << 1 | 0);\n   \
    \     propagate(i << 1 | 1);\n        data_[i] = M_get_(data_[i << 1 | 0], data_[i\
    \ << 1 | 1]);\n      }\n    }\n\n  public:\n    lazy_segment_tree() {}\n    lazy_segment_tree(int\
    \ n) : depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n                  \
    \             size_(1 << depth_),\n                               hsize_(size_\
    \ / 2),\n                               data_(size_, M_get_()),\n            \
    \                   lazy_(size_, M_update_()) {}\n\n    void update(int l, int\
    \ r, const value_type_update &x) {\n      assert(0 <= l and l <= r and r <= hsize_);\n\
    \      propagate_top_down(l + hsize_);\n      if (r < hsize_) propagate_top_down(r\
    \ + hsize_);\n\n      int L = l + hsize_, R = r + hsize_;\n\n      while (L <\
    \ R) {\n        if (R & 1) {\n          --R;\n          lazy_[R] = M_update_(x,\
    \ lazy_[R]);\n          propagate(R);\n        }\n        if (L & 1) {\n     \
    \     lazy_[L] = M_update_(x, lazy_[L]);\n          propagate(L);\n          ++L;\n\
    \        }\n        L >>= 1;\n        R >>= 1;\n      }\n\n      bottom_up(l +\
    \ hsize_);\n      if (r < hsize_) bottom_up(r + hsize_);\n    }\n\n    void update(int\
    \ i, const value_type_update &x) { update(i, i + 1, x); }\n\n    value_type_get\
    \ fold(int l, int r) {\n      assert(0 <= l and l <= r and r <= hsize_);\n   \
    \   propagate_top_down(l + hsize_);\n      if (r < hsize_) propagate_top_down(r\
    \ + hsize_);\n\n      value_type_get ret_left = M_get_(), ret_right = M_get_();\n\
    \n      int L = l + hsize_, R = r + hsize_;\n\n      while (L < R) {\n       \
    \ if (R & 1) {\n          --R;\n          propagate(R);\n          ret_right =\
    \ M_get_(data_[R], ret_right);\n        }\n        if (L & 1) {\n          propagate(L);\n\
    \          ret_left = M_get_(ret_left, data_[L]);\n          ++L;\n        }\n\
    \        L >>= 1;\n        R >>= 1;\n      }\n\n      return M_get_(ret_left,\
    \ ret_right);\n    }\n\n    value_type_get fold_all() {\n      return fold(0,\
    \ hsize_);\n    }\n\n    value_type_get operator[](int i) { return fold(i, i +\
    \ 1); }\n\n    template <typename T>\n    void init(const T &val) {\n      init_with_vector(std::vector<T>(hsize_,\
    \ val));\n    }\n\n    template <typename T>\n    void init_with_vector(const\
    \ std::vector<T> &val) {\n      data_.assign(size_, M_get_());\n      lazy_.assign(size_,\
    \ M_update_());\n      for (int i = 0; i < (int) val.size(); ++i) data_[hsize_\
    \ + i] = (value_type_get) val[i];\n      for (int i = hsize_; --i > 0;) data_[i]\
    \ = M_get_(data_[i << 1 | 0], data_[i << 1 | 1]);\n    }\n  };\n}  // namespace\
    \ haar_lib\n#line 2 \"Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n\
    #line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
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
    \  }\n}  // namespace haar_lib\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int N) {\n\
    \    std::vector<T> ret(N);\n    for (int i = 0; i < N; ++i) std::cin >> ret[i];\n\
    \    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M) {\n    std::vector<std::vector<T>> ret(N);\n    for\
    \ (int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n\
    }  // namespace haar_lib\n#line 4 \"Mylib/Number/Mint/mint.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <int32_t M>\n  class modint {\n    uint32_t val_;\n\n\
    \  public:\n    constexpr static auto mod() { return M; }\n\n    constexpr modint()\
    \ : val_(0) {}\n    constexpr modint(int64_t n) {\n      if (n >= M)\n       \
    \ val_ = n % M;\n      else if (n < 0)\n        val_ = n % M + M;\n      else\n\
    \        val_ = n;\n    }\n\n    constexpr auto &operator=(const modint &a) {\n\
    \      val_ = a.val_;\n      return *this;\n    }\n    constexpr auto &operator+=(const\
    \ modint &a) {\n      if (val_ + a.val_ >= M)\n        val_ = (uint64_t) val_\
    \ + a.val_ - M;\n      else\n        val_ += a.val_;\n      return *this;\n  \
    \  }\n    constexpr auto &operator-=(const modint &a) {\n      if (val_ < a.val_)\
    \ val_ += M;\n      val_ -= a.val_;\n      return *this;\n    }\n    constexpr\
    \ auto &operator*=(const modint &a) {\n      val_ = (uint64_t) val_ * a.val_ %\
    \ M;\n      return *this;\n    }\n    constexpr auto &operator/=(const modint\
    \ &a) {\n      val_ = (uint64_t) val_ * a.inv().val_ % M;\n      return *this;\n\
    \    }\n\n    constexpr auto operator+(const modint &a) const { return modint(*this)\
    \ += a; }\n    constexpr auto operator-(const modint &a) const { return modint(*this)\
    \ -= a; }\n    constexpr auto operator*(const modint &a) const { return modint(*this)\
    \ *= a; }\n    constexpr auto operator/(const modint &a) const { return modint(*this)\
    \ /= a; }\n\n    constexpr bool operator==(const modint &a) const { return val_\
    \ == a.val_; }\n    constexpr bool operator!=(const modint &a) const { return\
    \ val_ != a.val_; }\n\n    constexpr auto &operator++() {\n      *this += 1;\n\
    \      return *this;\n    }\n    constexpr auto &operator--() {\n      *this -=\
    \ 1;\n      return *this;\n    }\n\n    constexpr auto operator++(int) {\n   \
    \   auto t = *this;\n      *this += 1;\n      return t;\n    }\n    constexpr\
    \ auto operator--(int) {\n      auto t = *this;\n      *this -= 1;\n      return\
    \ t;\n    }\n\n    constexpr static modint pow(int64_t n, int64_t p) {\n     \
    \ if (p < 0) return pow(n, -p).inv();\n\n      int64_t ret = 1, e = n % M;\n \
    \     for (; p; (e *= e) %= M, p >>= 1)\n        if (p & 1) (ret *= e) %= M;\n\
    \      return ret;\n    }\n\n    constexpr static modint inv(int64_t a) {\n  \
    \    int64_t b = M, u = 1, v = 0;\n\n      while (b) {\n        int64_t t = a\
    \ / b;\n        a -= t * b;\n        std::swap(a, b);\n        u -= t * v;\n \
    \       std::swap(u, v);\n      }\n\n      u %= M;\n      if (u < 0) u += M;\n\
    \n      return u;\n    }\n\n    constexpr static auto frac(int64_t a, int64_t\
    \ b) { return modint(a) / modint(b); }\n\n    constexpr auto pow(int64_t p) const\
    \ { return pow(val_, p); }\n    constexpr auto inv() const { return inv(val_);\
    \ }\n\n    friend constexpr auto operator-(const modint &a) { return modint(M\
    \ - a.val_); }\n\n    friend constexpr auto operator+(int64_t a, const modint\
    \ &b) { return modint(a) + b; }\n    friend constexpr auto operator-(int64_t a,\
    \ const modint &b) { return modint(a) - b; }\n    friend constexpr auto operator*(int64_t\
    \ a, const modint &b) { return modint(a) * b; }\n    friend constexpr auto operator/(int64_t\
    \ a, const modint &b) { return modint(a) / b; }\n\n    friend std::istream &operator>>(std::istream\
    \ &s, modint &a) {\n      s >> a.val_;\n      return s;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &s, const modint &a) {\n      s << a.val_;\n      return\
    \ s;\n    }\n\n    template <int N>\n    static auto div() {\n      static auto\
    \ value = inv(N);\n      return value;\n    }\n\n    explicit operator int32_t()\
    \ const noexcept { return val_; }\n    explicit operator int64_t() const noexcept\
    \ { return val_; }\n  };\n}  // namespace haar_lib\n#line 12 \"test/yosupo-judge/range_affine_range_sum/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing mint   = hl::modint<998244353>;\nusing sum\
    \    = hl::sum_monoid<mint>;\nusing affine = hl::affine_monoid<mint>;\n\nint main()\
    \ {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N, Q;\n\
    \  std::cin >> N >> Q;\n\n  auto seg = hl::lazy_segment_tree<hl::affine_sum<affine,\
    \ sum>>(N);\n  auto a   = hl::input_vector<mint>(N);\n  seg.init_with_vector(a);\n\
    \n  for (auto [t, l, r] : hl::input_tuples<int, int, int>(Q)) {\n    if (t ==\
    \ 0) {\n      int b, c;\n      std::cin >> b >> c;\n      seg.update(l, r, std::make_pair(b,\
    \ c));\n    } else {\n      std::cout << seg.fold(l, r) << \"\\n\";\n    }\n \
    \ }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/AlgebraicStructure/Monoid/affine.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n#include \"Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp\"\
    \n#include \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\n#include\
    \ \"Mylib/IO/input_tuples.cpp\"\n#include \"Mylib/IO/input_vector.cpp\"\n#include\
    \ \"Mylib/Number/Mint/mint.cpp\"\n\nnamespace hl = haar_lib;\n\nusing mint   =\
    \ hl::modint<998244353>;\nusing sum    = hl::sum_monoid<mint>;\nusing affine =\
    \ hl::affine_monoid<mint>;\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q;\n  std::cin >> N >> Q;\n\n  auto seg = hl::lazy_segment_tree<hl::affine_sum<affine,\
    \ sum>>(N);\n  auto a   = hl::input_vector<mint>(N);\n  seg.init_with_vector(a);\n\
    \n  for (auto [t, l, r] : hl::input_tuples<int, int, int>(Q)) {\n    if (t ==\
    \ 0) {\n      int b, c;\n      std::cin >> b >> c;\n      seg.update(l, r, std::make_pair(b,\
    \ c));\n    } else {\n      std::cout << seg.fold(l, r) << \"\\n\";\n    }\n \
    \ }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/AlgebraicStructure/Monoid/affine.cpp
  - Mylib/AlgebraicStructure/Monoid/sum.cpp
  - Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp
  - Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/Number/Mint/mint.cpp
  isVerificationFile: true
  path: test/yosupo-judge/range_affine_range_sum/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/range_affine_range_sum/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/range_affine_range_sum/main.test.cpp
- /verify/test/yosupo-judge/range_affine_range_sum/main.test.cpp.html
title: test/yosupo-judge/range_affine_range_sum/main.test.cpp
---
