---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/DynamicProgramming/SpeedupTechnique/kitamasa_algorithm.cpp
    title: Kitamasa algorithm
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':x:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/658
    links:
    - https://yukicoder.me/problems/no/658
  bundledCode: "#line 1 \"test/yukicoder/658/main.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/658\"\
    \n\n#include <iostream>\n#line 3 \"Mylib/Number/Mint/mint.cpp\"\n#include <utility>\n\
    \nnamespace haar_lib {\n  template <int32_t M>\n  class modint {\n    uint32_t\
    \ val_;\n\n  public:\n    constexpr static auto mod(){return M;}\n\n    constexpr\
    \ modint(): val_(0){}\n    constexpr modint(int64_t n){\n      if(n >= M) val_\
    \ = n % M;\n      else if(n < 0) val_ = n % M + M;\n      else val_ = n;\n   \
    \ }\n\n    constexpr auto& operator=(const modint &a){val_ = a.val_; return *this;}\n\
    \    constexpr auto& operator+=(const modint &a){\n      if(val_ + a.val_ >= M)\
    \ val_ = (uint64_t)val_ + a.val_ - M;\n      else val_ += a.val_;\n      return\
    \ *this;\n    }\n    constexpr auto& operator-=(const modint &a){\n      if(val_\
    \ < a.val_) val_ += M;\n      val_ -= a.val_;\n      return *this;\n    }\n  \
    \  constexpr auto& operator*=(const modint &a){\n      val_ = (uint64_t)val_ *\
    \ a.val_ % M;\n      return *this;\n    }\n    constexpr auto& operator/=(const\
    \ modint &a){\n      val_ = (uint64_t)val_ * a.inv().val_ % M;\n      return *this;\n\
    \    }\n\n    constexpr auto operator+(const modint &a) const {return modint(*this)\
    \ += a;}\n    constexpr auto operator-(const modint &a) const {return modint(*this)\
    \ -= a;}\n    constexpr auto operator*(const modint &a) const {return modint(*this)\
    \ *= a;}\n    constexpr auto operator/(const modint &a) const {return modint(*this)\
    \ /= a;}\n\n    constexpr bool operator==(const modint &a) const {return val_\
    \ == a.val_;}\n    constexpr bool operator!=(const modint &a) const {return val_\
    \ != a.val_;}\n\n    constexpr auto& operator++(){*this += 1; return *this;}\n\
    \    constexpr auto& operator--(){*this -= 1; return *this;}\n\n    constexpr\
    \ auto operator++(int){auto t = *this; *this += 1; return t;}\n    constexpr auto\
    \ operator--(int){auto t = *this; *this -= 1; return t;}\n\n    constexpr static\
    \ modint pow(int64_t n, int64_t p){\n      if(p < 0) return pow(n, -p).inv();\n\
    \n      int64_t ret = 1, e = n % M;\n      for(; p; (e *= e) %= M, p >>= 1) if(p\
    \ & 1) (ret *= e) %= M;\n      return ret;\n    }\n\n    constexpr static modint\
    \ inv(int64_t a){\n      int64_t b = M, u = 1, v = 0;\n\n      while(b){\n   \
    \     int64_t t = a / b;\n        a -= t * b; std::swap(a, b);\n        u -= t\
    \ * v; std::swap(u, v);\n      }\n\n      u %= M;\n      if(u < 0) u += M;\n\n\
    \      return u;\n    }\n\n    constexpr static auto frac(int64_t a, int64_t b){return\
    \ modint(a) / modint(b);}\n\n    constexpr auto pow(int64_t p) const {return pow(val_,\
    \ p);}\n    constexpr auto inv() const {return inv(val_);}\n\n    friend constexpr\
    \ auto operator-(const modint &a){return modint(M - a.val_);}\n\n    friend constexpr\
    \ auto operator+(int64_t a, const modint &b){return modint(a) + b;}\n    friend\
    \ constexpr auto operator-(int64_t a, const modint &b){return modint(a) - b;}\n\
    \    friend constexpr auto operator*(int64_t a, const modint &b){return modint(a)\
    \ * b;}\n    friend constexpr auto operator/(int64_t a, const modint &b){return\
    \ modint(a) / b;}\n\n    friend std::istream& operator>>(std::istream &s, modint\
    \ &a){s >> a.val_; return s;}\n    friend std::ostream& operator<<(std::ostream\
    \ &s, const modint &a){s << a.val_; return s;}\n\n    template <int N>\n    static\
    \ auto div(){\n      static auto value = inv(N);\n      return value;\n    }\n\
    \n    explicit operator int32_t() const noexcept {return val_;}\n    explicit\
    \ operator int64_t() const noexcept {return val_;}\n  };\n}\n#line 2 \"Mylib/DynamicProgramming/SpeedupTechnique/kitamasa_algorithm.cpp\"\
    \n#include <vector>\n#include <cstdint>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class kitamasa_algorithm {\n    int size_;\n    std::vector<T> initial_values_,\
    \ coeff_;\n\n  public:\n    kitamasa_algorithm(){}\n    kitamasa_algorithm(int\
    \ size, const std::vector<T> &initial_values, const std::vector<T> &coeff):\n\
    \      size_(size), initial_values_(initial_values), coeff_(coeff){}\n\n    std::vector<T>\
    \ inc(const std::vector<T> &a) const {\n      std::vector<T> ret(size_);\n\n \
    \     for(int i = 0; i < size_; ++i) ret[i] += a[size_ - 1] * coeff_[i];\n   \
    \   for(int i = 1; i < size_; ++i) ret[i] += a[i - 1];\n\n      return ret;\n\
    \    }\n\n    std::vector<T> dbl(const std::vector<T> &a) const {\n      std::vector<T>\
    \ ret(size_), b(a);\n\n      for(int j = 0; j < size_; ++j){\n        for(int\
    \ i = 0; i < size_; ++i){\n          ret[i] += a[j] * b[i];\n        }\n\n   \
    \     b = inc(b);\n      }\n\n      return ret;\n    }\n\n    T eval(const std::vector<T>\
    \ &v) const {\n      T ret = 0;\n      for(int i = 0; i < size_; ++i) ret += v[i]\
    \ * initial_values_[i];\n      return ret;\n    }\n\n    std::vector<T> get(int64_t\
    \ index) const {\n      std::vector<T> ret(size_);\n      ret[0] = 1;\n\n    \
    \  bool check = false;\n      for(int i = 63; i >= 0; --i){\n        if(check)\
    \ ret = dbl(ret);\n\n        if(index & (1LL << i)){\n          ret = inc(ret);\n\
    \          check = true;\n        }\n      }\n\n      return ret;\n    }\n\n \
    \   T operator[](int64_t index) const {\n      if(index < size_) return initial_values_[index];\n\
    \      return eval(get(index));\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
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
    \ N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line 7 \"test/yukicoder/658/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing mint = hl::modint<17>;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int Q; std::cin\
    \ >> Q;\n\n  for(auto [N] : hl::input_tuples<int64_t>(Q)){\n    hl::kitamasa_algorithm<mint>\
    \ ka(4, {0, 0, 0, 1}, {1, 1, 1, 1});\n    std::cout << ka[N - 1] << std::endl;\n\
    \  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/658\"\n\n#include <iostream>\n\
    #include \"Mylib/Number/Mint/mint.cpp\"\n#include \"Mylib/DynamicProgramming/SpeedupTechnique/kitamasa_algorithm.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nusing\
    \ mint = hl::modint<17>;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int Q; std::cin >> Q;\n\n  for(auto [N] : hl::input_tuples<int64_t>(Q)){\n\
    \    hl::kitamasa_algorithm<mint> ka(4, {0, 0, 0, 1}, {1, 1, 1, 1});\n    std::cout\
    \ << ka[N - 1] << std::endl;\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Mint/mint.cpp
  - Mylib/DynamicProgramming/SpeedupTechnique/kitamasa_algorithm.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yukicoder/658/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-30 07:57:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/658/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/658/main.test.cpp
- /verify/test/yukicoder/658/main.test.cpp.html
title: test/yukicoder/658/main.test.cpp
---
