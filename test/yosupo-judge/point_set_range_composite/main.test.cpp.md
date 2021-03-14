---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/Monoid/affine.cpp
    title: Affine monoid
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/Monoid/dual.cpp
    title: Dual monoid
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/SegmentTree/segment_tree.cpp
    title: Segment tree
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuples_with_index.cpp
    title: Input tuples with index
  - icon: ':question:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/yosupo-judge/point_set_range_composite/main.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <iostream>\n#include <utility>\n#line 2 \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\
    \n#include <vector>\n#include <algorithm>\n#include <functional>\n#include <cassert>\n\
    \nnamespace haar_lib {\n  template <typename Monoid>\n  class segment_tree {\n\
    \  public:\n    using value_type = typename Monoid::value_type;\n\n  private:\n\
    \    Monoid M_;\n    int depth_, size_, hsize_;\n    std::vector<value_type> data_;\n\
    \n  public:\n    segment_tree(){}\n    segment_tree(int n):\n      depth_(n >\
    \ 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size_(1 << depth_), hsize_(size_\
    \ / 2),\n      data_(size_, M_())\n    {}\n\n    auto operator[](int i) const\
    \ {\n      assert(0 <= i and i < hsize_);\n      return data_[hsize_ + i];\n \
    \   }\n\n    auto fold(int l, int r) const {\n      assert(0 <= l and l <= r and\
    \ r <= hsize_);\n      value_type ret_left = M_();\n      value_type ret_right\
    \ = M_();\n\n      int L = l + hsize_, R = r + hsize_;\n      while(L < R){\n\
    \        if(R & 1) ret_right = M_(data_[--R], ret_right);\n        if(L & 1) ret_left\
    \ = M_(ret_left, data_[L++]);\n        L >>= 1, R >>= 1;\n      }\n\n      return\
    \ M_(ret_left, ret_right);\n    }\n\n    auto fold_all() const {\n      return\
    \ data_[1];\n    }\n\n    void set(int i, const value_type &x){\n      assert(0\
    \ <= i and i < hsize_);\n      i += hsize_;\n      data_[i] = x;\n      while(i\
    \ > 1) i >>= 1, data_[i] = M_(data_[i << 1 | 0], data_[i << 1 | 1]);\n    }\n\n\
    \    void update(int i, const value_type &x){\n      assert(0 <= i and i < hsize_);\n\
    \      i += hsize_;\n      data_[i] = M_(data_[i], x);\n      while(i > 1) i >>=\
    \ 1, data_[i] = M_(data_[i << 1 | 0], data_[i << 1 | 1]);\n    }\n\n    template\
    \ <typename T>\n    void init_with_vector(const std::vector<T> &val){\n      data_.assign(size_,\
    \ M_());\n      for(int i = 0; i < (int)val.size(); ++i) data_[hsize_ + i] = val[i];\n\
    \      for(int i = hsize_; --i >= 1;) data_[i] = M_(data_[i << 1 | 0], data_[i\
    \ << 1 | 1]);\n    }\n\n    template <typename T>\n    void init(const T &val){\n\
    \      init_with_vector(std::vector<value_type>(hsize_, val));\n    }\n\n  private:\n\
    \    template <bool Lower, typename F>\n    int bound(const int l, const int r,\
    \ value_type x, F f) const {\n      std::vector<int> pl, pr;\n      int L = l\
    \ + hsize_;\n      int R = r + hsize_;\n      while(L < R){\n        if(R & 1)\
    \ pr.push_back(--R);\n        if(L & 1) pl.push_back(L++);\n        L >>= 1, R\
    \ >>= 1;\n      }\n\n      std::reverse(pr.begin(), pr.end());\n      pl.insert(pl.end(),\
    \ pr.begin(), pr.end());\n\n      value_type a = M_();\n\n      for(int i : pl){\n\
    \        auto b = M_(a, data_[i]);\n\n        if((Lower and not f(b, x)) or (not\
    \ Lower and f(x, b))){\n          while(i < hsize_){\n            const auto c\
    \ = M_(a, data_[i << 1 | 0]);\n            if((Lower and not f(c, x)) or (not\
    \ Lower and f(x, c))){\n              i = i << 1 | 0;\n            }else{\n  \
    \            a = c;\n              i = i << 1 | 1;\n            }\n          }\n\
    \n          return i - hsize_;\n        }\n\n        a = b;\n      }\n\n     \
    \ return r;\n    }\n\n  public:\n    template <typename F = std::less<value_type>>\n\
    \    int lower_bound(int l, int r, value_type x, F f = F()) const {\n      return\
    \ bound<true>(l, r, x, f);\n    }\n\n    template <typename F = std::less<value_type>>\n\
    \    int upper_bound(int l, int r, value_type x, F f = F()) const {\n      return\
    \ bound<false>(l, r, x, f);\n    }\n  };\n}\n#line 3 \"Mylib/AlgebraicStructure/Monoid/affine.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct affine_monoid {\n\
    \    using value_type = std::pair<T, T>;\n    value_type operator()() const {return\
    \ std::make_pair(1, 0);}\n    value_type operator()(const value_type &a, const\
    \ value_type &b) const {\n      return std::make_pair(a.first * b.first, a.first\
    \ * b.second + a.second);\n    }\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/dual.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Monoid>\n  struct dual_monoid {\n\
    \    using value_type = typename Monoid::value_type;\n    const static Monoid\
    \ M;\n    value_type operator()() const {return M();}\n    value_type operator()(const\
    \ value_type &a, const value_type &b) const {return M(b, a);}\n  };\n}\n#line\
    \ 4 \"Mylib/Number/Mint/mint.cpp\"\n\nnamespace haar_lib {\n  template <int32_t\
    \ M>\n  class modint {\n    uint32_t val_;\n\n  public:\n    constexpr static\
    \ auto mod(){return M;}\n\n    constexpr modint(): val_(0){}\n    constexpr modint(int64_t\
    \ n){\n      if(n >= M) val_ = n % M;\n      else if(n < 0) val_ = n % M + M;\n\
    \      else val_ = n;\n    }\n\n    constexpr auto& operator=(const modint &a){val_\
    \ = a.val_; return *this;}\n    constexpr auto& operator+=(const modint &a){\n\
    \      if(val_ + a.val_ >= M) val_ = (uint64_t)val_ + a.val_ - M;\n      else\
    \ val_ += a.val_;\n      return *this;\n    }\n    constexpr auto& operator-=(const\
    \ modint &a){\n      if(val_ < a.val_) val_ += M;\n      val_ -= a.val_;\n   \
    \   return *this;\n    }\n    constexpr auto& operator*=(const modint &a){\n \
    \     val_ = (uint64_t)val_ * a.val_ % M;\n      return *this;\n    }\n    constexpr\
    \ auto& operator/=(const modint &a){\n      val_ = (uint64_t)val_ * a.inv().val_\
    \ % M;\n      return *this;\n    }\n\n    constexpr auto operator+(const modint\
    \ &a) const {return modint(*this) += a;}\n    constexpr auto operator-(const modint\
    \ &a) const {return modint(*this) -= a;}\n    constexpr auto operator*(const modint\
    \ &a) const {return modint(*this) *= a;}\n    constexpr auto operator/(const modint\
    \ &a) const {return modint(*this) /= a;}\n\n    constexpr bool operator==(const\
    \ modint &a) const {return val_ == a.val_;}\n    constexpr bool operator!=(const\
    \ modint &a) const {return val_ != a.val_;}\n\n    constexpr auto& operator++(){*this\
    \ += 1; return *this;}\n    constexpr auto& operator--(){*this -= 1; return *this;}\n\
    \n    constexpr auto operator++(int){auto t = *this; *this += 1; return t;}\n\
    \    constexpr auto operator--(int){auto t = *this; *this -= 1; return t;}\n\n\
    \    constexpr static modint pow(int64_t n, int64_t p){\n      if(p < 0) return\
    \ pow(n, -p).inv();\n\n      int64_t ret = 1, e = n % M;\n      for(; p; (e *=\
    \ e) %= M, p >>= 1) if(p & 1) (ret *= e) %= M;\n      return ret;\n    }\n\n \
    \   constexpr static modint inv(int64_t a){\n      int64_t b = M, u = 1, v = 0;\n\
    \n      while(b){\n        int64_t t = a / b;\n        a -= t * b; std::swap(a,\
    \ b);\n        u -= t * v; std::swap(u, v);\n      }\n\n      u %= M;\n      if(u\
    \ < 0) u += M;\n\n      return u;\n    }\n\n    constexpr static auto frac(int64_t\
    \ a, int64_t b){return modint(a) / modint(b);}\n\n    constexpr auto pow(int64_t\
    \ p) const {return pow(val_, p);}\n    constexpr auto inv() const {return inv(val_);}\n\
    \n    friend constexpr auto operator-(const modint &a){return modint(M - a.val_);}\n\
    \n    friend constexpr auto operator+(int64_t a, const modint &b){return modint(a)\
    \ + b;}\n    friend constexpr auto operator-(int64_t a, const modint &b){return\
    \ modint(a) - b;}\n    friend constexpr auto operator*(int64_t a, const modint\
    \ &b){return modint(a) * b;}\n    friend constexpr auto operator/(int64_t a, const\
    \ modint &b){return modint(a) / b;}\n\n    friend std::istream& operator>>(std::istream\
    \ &s, modint &a){s >> a.val_; return s;}\n    friend std::ostream& operator<<(std::ostream\
    \ &s, const modint &a){s << a.val_; return s;}\n\n    template <int N>\n    static\
    \ auto div(){\n      static auto value = inv(N);\n      return value;\n    }\n\
    \n    explicit operator int32_t() const noexcept {return val_;}\n    explicit\
    \ operator int64_t() const noexcept {return val_;}\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <tuple>\n#line 6 \"Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n\
    #line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T, size_t ... I>\n  static void input_tuple_helper(std::istream &s, T &val,\
    \ std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(s >>\
    \ std::get<I>(val)), 0) ...};\n  }\n\n  template <typename T, typename U>\n  std::istream&\
    \ operator>>(std::istream &s, std::pair<T, U> &value){\n    s >> value.first >>\
    \ value.second;\n    return s;\n  }\n\n  template <typename ... Args>\n  std::istream&\
    \ operator>>(std::istream &s, std::tuple<Args ...> &value){\n    input_tuple_helper(s,\
    \ value, std::make_index_sequence<sizeof ... (Args)>());\n    return s;\n  }\n\
    }\n#line 8 \"Mylib/IO/input_tuples.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ ... Args>\n  class InputTuples {\n    struct iter {\n      using value_type\
    \ = std::tuple<Args ...>;\n      value_type value;\n      bool fetched = false;\n\
    \      int N, c = 0;\n\n      value_type operator*(){\n        if(not fetched){\n\
    \          std::cin >> value;\n        }\n        return value;\n      }\n\n \
    \     void operator++(){\n        ++c;\n        fetched = false;\n      }\n\n\
    \      bool operator!=(iter &) const {\n        return c < N;\n      }\n\n   \
    \   iter(int N): N(N){}\n    };\n\n    int N;\n\n  public:\n    InputTuples(int\
    \ N): N(N){}\n\n    iter begin() const {return iter(N);}\n    iter end() const\
    \ {return iter(N);}\n  };\n\n  template <typename ... Args>\n  auto input_tuples(int\
    \ N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line 8 \"Mylib/IO/input_tuples_with_index.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename ... Args>\n  class InputTuplesWithIndex\
    \ {\n    struct iter {\n      using value_type = std::tuple<int, Args ...>;\n\
    \      value_type value;\n      bool fetched = false;\n      int N;\n      int\
    \ c = 0;\n\n      value_type operator*(){\n        if(not fetched){\n        \
    \  std::tuple<Args ...> temp; std::cin >> temp;\n          value = std::tuple_cat(std::make_tuple(c),\
    \ temp);\n        }\n        return value;\n      }\n\n      void operator++(){\n\
    \        ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter\
    \ &) const {\n        return c < N;\n      }\n\n      iter(int N): N(N){}\n  \
    \  };\n\n    int N;\n\n  public:\n    InputTuplesWithIndex(int N): N(N){}\n\n\
    \    iter begin() const {return iter(N);}\n    iter end() const {return iter(N);}\n\
    \  };\n\n  template <typename ... Args>\n  auto input_tuples_with_index(int N){\n\
    \    return InputTuplesWithIndex<Args ...>(N);\n  }\n}\n#line 11 \"test/yosupo-judge/point_set_range_composite/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing mint = hl::modint<998244353>;\nusing M =\
    \ hl::dual_monoid<hl::affine_monoid<mint>>;\n\nint main(){\n  int N, Q; std::cin\
    \ >> N >> Q;\n\n  auto seg = hl::segment_tree<M>(N);\n\n  for(auto [i, a, b] :\
    \ hl::input_tuples_with_index<int, int>(N)){\n    seg.set(i, {a, b});\n  }\n\n\
    \  for(auto [t] : hl::input_tuples<int>(Q)){\n    if(t == 0){\n      int p, c,\
    \ d; std::cin >> p >> c >> d;\n      seg.set(p, {c, d});\n    }else{\n      int\
    \ l, r, x; std::cin >> l >> r >> x;\n      auto [a, b] = seg.fold(l, r);\n   \
    \   std::cout << a * x + b << std::endl;\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <iostream>\n#include <utility>\n#include \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/Monoid/affine.cpp\"\n#include \"Mylib/AlgebraicStructure/Monoid/dual.cpp\"\
    \n#include \"Mylib/Number/Mint/mint.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n#include \"Mylib/IO/input_tuples_with_index.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nusing mint = hl::modint<998244353>;\nusing M = hl::dual_monoid<hl::affine_monoid<mint>>;\n\
    \nint main(){\n  int N, Q; std::cin >> N >> Q;\n\n  auto seg = hl::segment_tree<M>(N);\n\
    \n  for(auto [i, a, b] : hl::input_tuples_with_index<int, int>(N)){\n    seg.set(i,\
    \ {a, b});\n  }\n\n  for(auto [t] : hl::input_tuples<int>(Q)){\n    if(t == 0){\n\
    \      int p, c, d; std::cin >> p >> c >> d;\n      seg.set(p, {c, d});\n    }else{\n\
    \      int l, r, x; std::cin >> l >> r >> x;\n      auto [a, b] = seg.fold(l,\
    \ r);\n      std::cout << a * x + b << std::endl;\n    }\n  }\n\n  return 0;\n\
    }\n"
  dependsOn:
  - Mylib/DataStructure/SegmentTree/segment_tree.cpp
  - Mylib/AlgebraicStructure/Monoid/affine.cpp
  - Mylib/AlgebraicStructure/Monoid/dual.cpp
  - Mylib/Number/Mint/mint.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/IO/input_tuples_with_index.cpp
  isVerificationFile: true
  path: test/yosupo-judge/point_set_range_composite/main.test.cpp
  requiredBy: []
  timestamp: '2020-10-15 01:51:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/point_set_range_composite/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/point_set_range_composite/main.test.cpp
- /verify/test/yosupo-judge/point_set_range_composite/main.test.cpp.html
title: test/yosupo-judge/point_set_range_composite/main.test.cpp
---
