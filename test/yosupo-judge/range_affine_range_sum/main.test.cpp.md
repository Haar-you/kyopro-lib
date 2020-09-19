---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
    title: Lazy segment tree
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/sum.cpp
    title: Sum monoid
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/Monoid/affine.cpp
    title: Affine monoid
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp
    title: Range affine / Range sum
  - icon: ':x:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Mylib/IO/input_vector.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Mylib/IO/input_tuples.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Mylib/IO/input_tuple.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo-judge/range_affine_range_sum/main.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#include <iostream>\n#include <vector>\n#line 3 \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename MonoidGet, typename MonoidUpdate,\
    \ template <typename, typename> typename Connector>\n  class lazy_segment_tree\
    \ {\n    using value_type_get = typename MonoidGet::value_type;\n    using value_type_update\
    \ = typename MonoidUpdate::value_type;\n    Connector<MonoidGet, MonoidUpdate>\
    \ M;\n    MonoidGet M_get;\n    MonoidUpdate M_update;\n\n    const int depth,\
    \ size, hsize;\n    std::vector<value_type_get> data;\n    std::vector<value_type_update>\
    \ lazy;\n\n    void propagate(int i){\n      if(lazy[i] == M_update()) return;\n\
    \      if(i < hsize){\n        lazy[i << 1 | 0] = M_update(lazy[i], lazy[i <<\
    \ 1 | 0]);\n        lazy[i << 1 | 1] = M_update(lazy[i], lazy[i << 1 | 1]);\n\
    \      }\n      int len = hsize >> (31 - __builtin_clz(i));\n      data[i] = M(data[i],\
    \ lazy[i], len);\n      lazy[i] = M_update();\n    }\n\n    void propagate_top_down(int\
    \ i){\n      std::vector<int> temp;\n      while(i > 1){\n        i >>= 1;\n \
    \       temp.push_back(i);\n      }\n\n      for(auto it = temp.rbegin(); it !=\
    \ temp.rend(); ++it) propagate(*it);\n    }\n\n    void bottom_up(int i){\n  \
    \    while(i > 1){\n        i >>= 1;\n        propagate(i << 1 | 0);\n       \
    \ propagate(i << 1 | 1);\n        data[i] = M_get(data[i << 1 | 0], data[i <<\
    \ 1 | 1]);\n      }\n    }\n\n  public:\n    lazy_segment_tree(){}\n    lazy_segment_tree(int\
    \ n):\n      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 <<\
    \ depth),\n      hsize(size / 2),\n      data(size, M_get()),\n      lazy(size,\
    \ M_update())\n    {}\n\n    void update(int l, int r, const value_type_update\
    \ &x){\n      propagate_top_down(l + hsize);\n      if(r < hsize) propagate_top_down(r\
    \ + hsize);\n\n      int L = l + hsize, R = r + hsize;\n\n      while(L < R){\n\
    \        if(R & 1){\n          --R;\n          lazy[R] = M_update(x, lazy[R]);\n\
    \          propagate(R);\n        }\n        if(L & 1){\n          lazy[L] = M_update(x,\
    \ lazy[L]);\n          propagate(L);\n          ++L;\n        }\n        L >>=\
    \ 1;\n        R >>= 1;\n      }\n\n      bottom_up(l + hsize);\n      if(r < hsize)\
    \ bottom_up(r + hsize);\n    }\n\n    void update_at(int i, const value_type_update\
    \ &x){update(i, i + 1, x);}\n\n    value_type_get get(int l, int r){\n      propagate_top_down(l\
    \ + hsize);\n      if(r < hsize) propagate_top_down(r + hsize);\n\n      value_type_get\
    \ ret_left = M_get(), ret_right = M_get();\n\n      int L = l + hsize, R = r +\
    \ hsize;\n\n      while(L < R){\n        if(R & 1){\n          --R;\n        \
    \  propagate(R);\n          ret_right = M_get(data[R], ret_right);\n        }\n\
    \        if(L & 1){\n          propagate(L);\n          ret_left = M_get(ret_left,\
    \ data[L]);\n          ++L;\n        }\n        L >>= 1;\n        R >>= 1;\n \
    \     }\n\n      return M_get(ret_left, ret_right);\n    }\n\n    value_type_get\
    \ operator[](int i){return get(i, i + 1);}\n\n    template <typename T>\n    void\
    \ init(const T &val){\n      init_with_vector(std::vector<T>(hsize, val));\n \
    \   }\n\n    template <typename T>\n    void init_with_vector(const std::vector<T>\
    \ &val){\n      data.assign(size, M_get());\n      lazy.assign(size, M_update());\n\
    \      for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = (value_type_get)val[i];\n\
    \      for(int i = hsize - 1; i > 0; --i) data[i] = M_get(data[i << 1 | 0], data[i\
    \ << 1 | 1]);\n    }\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct sum_monoid {\n   \
    \ using value_type = T;\n    value_type operator()() const {return 0;}\n    value_type\
    \ operator()(value_type a, value_type b) const {return a + b;}\n  };\n}\n#line\
    \ 2 \"Mylib/AlgebraicStructure/Monoid/affine.cpp\"\n#include <utility>\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct affine_monoid {\n    using value_type\
    \ = std::pair<T, T>;\n    value_type operator()() const {return std::make_pair(1,\
    \ 0);}\n    value_type operator()(const value_type &a, const value_type &b) const\
    \ {\n      return std::make_pair(a.first * b.first, a.first * b.second + a.second);\n\
    \    }\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename MonoidGet, typename MonoidUpdate>\n\
    \  struct affine_sum {\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(value_type_get a, value_type_update b, int len) const {\n      return\
    \ b.first * a + b.second * len;\n    }\n  };\n}\n#line 4 \"Mylib/Number/Mint/mint.cpp\"\
    \n\nnamespace haar_lib {\n  template <int32_t M>\n  class modint {\n    uint32_t\
    \ val;\n\n  public:\n    constexpr static auto mod(){return M;}\n\n    constexpr\
    \ modint(): val(0){}\n    constexpr modint(int64_t n){\n      if(n >= M) val =\
    \ n % M;\n      else if(n < 0) val = n % M + M;\n      else val = n;\n    }\n\n\
    \    constexpr auto& operator=(const modint &a){val = a.val; return *this;}\n\
    \    constexpr auto& operator+=(const modint &a){\n      if(val + a.val >= M)\
    \ val = (uint64_t)val + a.val - M;\n      else val += a.val;\n      return *this;\n\
    \    }\n    constexpr auto& operator-=(const modint &a){\n      if(val < a.val)\
    \ val += M;\n      val -= a.val;\n      return *this;\n    }\n    constexpr auto&\
    \ operator*=(const modint &a){\n      val = (uint64_t)val * a.val % M;\n     \
    \ return *this;\n    }\n    constexpr auto& operator/=(const modint &a){\n   \
    \   val = (uint64_t)val * a.inv().val % M;\n      return *this;\n    }\n\n   \
    \ constexpr auto operator+(const modint &a) const {return modint(*this) += a;}\n\
    \    constexpr auto operator-(const modint &a) const {return modint(*this) -=\
    \ a;}\n    constexpr auto operator*(const modint &a) const {return modint(*this)\
    \ *= a;}\n    constexpr auto operator/(const modint &a) const {return modint(*this)\
    \ /= a;}\n\n    constexpr bool operator==(const modint &a) const {return val ==\
    \ a.val;}\n    constexpr bool operator!=(const modint &a) const {return val !=\
    \ a.val;}\n\n    constexpr auto& operator++(){*this += 1; return *this;}\n   \
    \ constexpr auto& operator--(){*this -= 1; return *this;}\n\n    constexpr auto\
    \ operator++(int){auto t = *this; *this += 1; return t;}\n    constexpr auto operator--(int){auto\
    \ t = *this; *this -= 1; return t;}\n\n    constexpr static modint pow(int64_t\
    \ n, int64_t p){\n      if(p < 0) return pow(n, -p).inv();\n\n      int64_t ret\
    \ = 1, e = n % M;\n      for(; p; (e *= e) %= M, p >>= 1) if(p & 1) (ret *= e)\
    \ %= M;\n      return ret;\n    }\n\n    constexpr static modint inv(int64_t a){\n\
    \      int64_t b = M, u = 1, v = 0;\n\n      while(b){\n        int64_t t = a\
    \ / b;\n        a -= t * b; std::swap(a, b);\n        u -= t * v; std::swap(u,\
    \ v);\n      }\n\n      u %= M;\n      if(u < 0) u += M;\n\n      return u;\n\
    \    }\n\n    constexpr static auto frac(int64_t a, int64_t b){return modint(a)\
    \ / modint(b);}\n\n    constexpr auto pow(int64_t p) const {return pow(val, p);}\n\
    \    constexpr auto inv() const {return inv(val);}\n\n    friend constexpr auto\
    \ operator-(const modint &a){return modint(M - a.val);}\n\n    friend constexpr\
    \ auto operator+(int64_t a, const modint &b){return modint(a) + b;}\n    friend\
    \ constexpr auto operator-(int64_t a, const modint &b){return modint(a) - b;}\n\
    \    friend constexpr auto operator*(int64_t a, const modint &b){return modint(a)\
    \ * b;}\n    friend constexpr auto operator/(int64_t a, const modint &b){return\
    \ modint(a) / b;}\n\n    friend std::istream& operator>>(std::istream &s, modint<M>\
    \ &a){s >> a.val; return s;}\n    friend std::ostream& operator<<(std::ostream\
    \ &s, const modint<M> &a){s << a.val; return s;}\n\n    template <int N>\n   \
    \ static auto div(){\n      static auto value = inv(N);\n      return value;\n\
    \    }\n\n    explicit operator int32_t() const noexcept {return val;}\n    explicit\
    \ operator int64_t() const noexcept {return val;}\n  };\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#line 6 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace\
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
    \ 12 \"test/yosupo-judge/range_affine_range_sum/main.test.cpp\"\n\nnamespace hl\
    \ = haar_lib;\n\nusing mint = hl::modint<998244353>;\n\nint main(){\n  std::cin.tie(0);\n\
    \  std::ios::sync_with_stdio(false);\n\n  int N, Q; std::cin >> N >> Q;\n\n  auto\
    \ seg = hl::lazy_segment_tree<hl::sum_monoid<mint>, hl::affine_monoid<mint>, hl::affine_sum>(N);\n\
    \  auto a = hl::input_vector<mint>(N);\n  seg.init_with_vector(a);\n\n  for(auto\
    \ [t, l, r] : hl::input_tuples<int, int, int>(Q)){\n    if(t == 0){\n      int\
    \ b, c; std::cin >> b >> c;\n      seg.update(l, r, std::make_pair(b, c));\n \
    \   }else{\n      std::cout << seg.get(l, r) << \"\\n\";\n    }\n  }\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n#include \"Mylib/AlgebraicStructure/Monoid/affine.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp\"\n#include\
    \ \"Mylib/Number/Mint/mint.cpp\"\n#include \"Mylib/IO/input_vector.cpp\"\n#include\
    \ \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nusing mint = hl::modint<998244353>;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N, Q; std::cin >> N >> Q;\n\n  auto seg = hl::lazy_segment_tree<hl::sum_monoid<mint>,\
    \ hl::affine_monoid<mint>, hl::affine_sum>(N);\n  auto a = hl::input_vector<mint>(N);\n\
    \  seg.init_with_vector(a);\n\n  for(auto [t, l, r] : hl::input_tuples<int, int,\
    \ int>(Q)){\n    if(t == 0){\n      int b, c; std::cin >> b >> c;\n      seg.update(l,\
    \ r, std::make_pair(b, c));\n    }else{\n      std::cout << seg.get(l, r) << \"\
    \\n\";\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
  - Mylib/AlgebraicStructure/Monoid/sum.cpp
  - Mylib/AlgebraicStructure/Monoid/affine.cpp
  - Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp
  - Mylib/Number/Mint/mint.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/range_affine_range_sum/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-18 18:43:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/range_affine_range_sum/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/range_affine_range_sum/main.test.cpp
- /verify/test/yosupo-judge/range_affine_range_sum/main.test.cpp.html
title: test/yosupo-judge/range_affine_range_sum/main.test.cpp
---
