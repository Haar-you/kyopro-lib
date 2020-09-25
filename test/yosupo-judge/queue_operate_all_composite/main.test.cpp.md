---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/Monoid/affine.cpp
    title: Affine monoid
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/Monoid/dual.cpp
    title: Dual monoid
  - icon: ':x:'
    path: Mylib/DataStructure/Queue/sliding_window_aggregation.cpp
    title: Sliding window aggregation
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
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/yosupo-judge/queue_operate_all_composite/main.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include <iostream>\n#line 3 \"Mylib/Number/Mint/mint.cpp\"\n#include <utility>\n\
    \nnamespace haar_lib {\n  template <int32_t M>\n  class modint {\n    uint32_t\
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
    \ operator int64_t() const noexcept {return val;}\n  };\n}\n#line 3 \"Mylib/AlgebraicStructure/Monoid/affine.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct affine_monoid {\n\
    \    using value_type = std::pair<T, T>;\n    value_type operator()() const {return\
    \ std::make_pair(1, 0);}\n    value_type operator()(const value_type &a, const\
    \ value_type &b) const {\n      return std::make_pair(a.first * b.first, a.first\
    \ * b.second + a.second);\n    }\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/dual.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Monoid>\n  struct dual_monoid {\n\
    \    using value_type = typename Monoid::value_type;\n    const static Monoid\
    \ M;\n    value_type operator()() const {return M();}\n    value_type operator()(const\
    \ value_type &a, const value_type &b) const {return M(b, a);}\n  };\n}\n#line\
    \ 2 \"Mylib/DataStructure/Queue/sliding_window_aggregation.cpp\"\n#include <vector>\n\
    #include <stack>\n#include <optional>\n\nnamespace haar_lib {\n  template <typename\
    \ Semigroup>\n  class sliding_window_aggregation {\n    using value_type = typename\
    \ Semigroup::value_type;\n    const static Semigroup S;\n\n    std::stack<value_type>\
    \ front_stack, back_stack;\n    std::vector<value_type> front_sum, back_sum;\n\
    \n    std::optional<value_type> f(std::optional<value_type> a, std::optional<value_type>\
    \ b) const {\n      if(a){\n        if(b) return {S(*a, *b)};\n        else return\
    \ {*a};\n      }else{\n        if(b) return {*b};\n        else return {};\n \
    \     }\n    }\n\n    std::optional<value_type> g(const std::vector<value_type>\
    \ &a) const {\n      return a.empty() ? std::nullopt : std::optional(a.back());\n\
    \    }\n\n  public:\n    sliding_window_aggregation(){}\n\n    std::optional<value_type>\
    \ fold() const {\n      return f(g(front_sum), g(back_sum));\n    }\n\n    void\
    \ push(const value_type &value){\n      back_stack.push(value);\n      back_sum.push_back(f(g(back_sum),\
    \ value).value());\n    }\n\n    void pop(){\n      if(front_stack.empty()){\n\
    \        back_sum.clear();\n\n        while(not back_stack.empty()){\n       \
    \   const auto value = back_stack.top(); back_stack.pop();\n          front_stack.push(value);\n\
    \          front_sum.push_back(f(value, g(front_sum)).value());\n        }\n \
    \     }\n\n      front_stack.pop();\n      front_sum.pop_back();\n    }\n  };\n\
    }\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#line 6 \"Mylib/IO/input_tuples.cpp\"\
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
    \ 9 \"test/yosupo-judge/queue_operate_all_composite/main.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nusing mint = hl::modint<998244353>;\nusing M = hl::dual_monoid<hl::affine_monoid<mint>>;\n\
    \nint main(){\n  int Q; std::cin >> Q;\n\n  hl::sliding_window_aggregation<M>\
    \ swag;\n\n  for(auto [type] : hl::input_tuples<int>(Q)){\n    if(type == 0){\n\
    \      int a, b; std::cin >> a >> b;\n      swag.push({a, b});\n    }else if(type\
    \ == 1){\n      swag.pop();\n    }else{\n      int x; std::cin >> x;\n      auto\
    \ res = swag.fold();\n      if(res){\n        auto [a, b] = *res;\n        std::cout\
    \ << a * x + b << std::endl;\n      }else{\n        std::cout << x << std::endl;\n\
    \      }\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include <iostream>\n#include \"Mylib/Number/Mint/mint.cpp\"\n#include \"\
    Mylib/AlgebraicStructure/Monoid/affine.cpp\"\n#include \"Mylib/AlgebraicStructure/Monoid/dual.cpp\"\
    \n#include \"Mylib/DataStructure/Queue/sliding_window_aggregation.cpp\"\n#include\
    \ \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nusing mint = hl::modint<998244353>;\n\
    using M = hl::dual_monoid<hl::affine_monoid<mint>>;\n\nint main(){\n  int Q; std::cin\
    \ >> Q;\n\n  hl::sliding_window_aggregation<M> swag;\n\n  for(auto [type] : hl::input_tuples<int>(Q)){\n\
    \    if(type == 0){\n      int a, b; std::cin >> a >> b;\n      swag.push({a,\
    \ b});\n    }else if(type == 1){\n      swag.pop();\n    }else{\n      int x;\
    \ std::cin >> x;\n      auto res = swag.fold();\n      if(res){\n        auto\
    \ [a, b] = *res;\n        std::cout << a * x + b << std::endl;\n      }else{\n\
    \        std::cout << x << std::endl;\n      }\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Mint/mint.cpp
  - Mylib/AlgebraicStructure/Monoid/affine.cpp
  - Mylib/AlgebraicStructure/Monoid/dual.cpp
  - Mylib/DataStructure/Queue/sliding_window_aggregation.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/queue_operate_all_composite/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-17 22:58:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/queue_operate_all_composite/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/queue_operate_all_composite/main.test.cpp
- /verify/test/yosupo-judge/queue_operate_all_composite/main.test.cpp.html
title: test/yosupo-judge/queue_operate_all_composite/main.test.cpp
---
