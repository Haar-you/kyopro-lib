---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: Mylib/IO/join.cpp
  - icon: ':x:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  - icon: ':x:'
    path: Mylib/Convolution/ntt_convolution.cpp
    title: Number theoretic transform
  - icon: ':x:'
    path: Mylib/Math/formal_power_series.cpp
    title: Formal power series
  - icon: ':x:'
    path: Mylib/Combinatorics/factorial_table.cpp
    title: Factorial table
  - icon: ':x:'
    path: Mylib/Combinatorics/bernoulli_number_fps.cpp
    title: Bernoulli number (FPS)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bernoulli_number
    links:
    - https://judge.yosupo.jp/problem/bernoulli_number
  bundledCode: "#line 1 \"test/yosupo-judge/bernoulli_number/main.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bernoulli_number\"\n\n#include <iostream>\n\
    #include <functional>\n#line 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n#include\
    \ <string>\n\nnamespace haar_lib {\n  template <typename Iter>\n  std::string\
    \ join(Iter first, Iter last, std::string delim = \" \"){\n    std::stringstream\
    \ s;\n\n    for(auto it = first; it != last; ++it){\n      if(it != first) s <<\
    \ delim;\n      s << *it;\n    }\n\n    return s.str();\n  }\n}\n#line 3 \"Mylib/Number/Mint/mint.cpp\"\
    \n#include <utility>\n\nnamespace haar_lib {\n  template <int32_t M>\n  class\
    \ modint {\n    uint32_t val;\n\n  public:\n    constexpr static auto mod(){return\
    \ M;}\n\n    constexpr modint(): val(0){}\n    constexpr modint(int64_t n){\n\
    \      if(n >= M) val = n % M;\n      else if(n < 0) val = n % M + M;\n      else\
    \ val = n;\n    }\n\n    constexpr auto& operator=(const modint &a){val = a.val;\
    \ return *this;}\n    constexpr auto& operator+=(const modint &a){\n      if(val\
    \ + a.val >= M) val = (uint64_t)val + a.val - M;\n      else val += a.val;\n \
    \     return *this;\n    }\n    constexpr auto& operator-=(const modint &a){\n\
    \      if(val < a.val) val += M;\n      val -= a.val;\n      return *this;\n \
    \   }\n    constexpr auto& operator*=(const modint &a){\n      val = (uint64_t)val\
    \ * a.val % M;\n      return *this;\n    }\n    constexpr auto& operator/=(const\
    \ modint &a){\n      val = (uint64_t)val * a.inv().val % M;\n      return *this;\n\
    \    }\n\n    constexpr auto operator+(const modint &a) const {return modint(*this)\
    \ += a;}\n    constexpr auto operator-(const modint &a) const {return modint(*this)\
    \ -= a;}\n    constexpr auto operator*(const modint &a) const {return modint(*this)\
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
    \ operator int64_t() const noexcept {return val;}\n  };\n}\n#line 2 \"Mylib/Convolution/ntt_convolution.cpp\"\
    \n#include <vector>\n#include <cassert>\n#line 5 \"Mylib/Convolution/ntt_convolution.cpp\"\
    \n#include <algorithm>\n#line 7 \"Mylib/Convolution/ntt_convolution.cpp\"\n\n\
    namespace haar_lib {\n  template <typename T, int PRIM_ROOT, int MAX_SIZE>\n \
    \ class number_theoretic_transform {\n  public:\n    using value_type = T;\n \
    \   constexpr static int primitive_root = PRIM_ROOT;\n\n  private:\n    const\
    \ int MAX_POWER;\n    std::vector<T> BASE, INV_BASE;\n\n  public:\n    number_theoretic_transform():\n\
    \      MAX_POWER(__builtin_ctz(MAX_SIZE)),\n      BASE(MAX_POWER + 1),\n     \
    \ INV_BASE(MAX_POWER + 1)\n    {\n      static_assert((MAX_SIZE & (MAX_SIZE -\
    \ 1)) == 0, \"MAX_SIZE must be power of 2.\");\n\n      T t = T::pow(PRIM_ROOT,\
    \ (T::mod() - 1) >> (MAX_POWER + 2));\n      T s = t.inv();\n\n      for(int i\
    \ = MAX_POWER - 1; i >= 0; --i){\n        t *= t;\n        s *= s;\n        BASE[i]\
    \ = -t;\n        INV_BASE[i] = -s;\n      }\n    }\n\n    void run(std::vector<T>\
    \ &f, bool INVERSE = false){\n      const int n = f.size();\n      assert((n &\
    \ (n - 1)) == 0 and n <= MAX_SIZE); // \u30C7\u30FC\u30BF\u6570\u306F2\u306E\u51AA\
    \u4E57\u500B\n\n      if(INVERSE){\n        for(int b = 1; b < n; b <<= 1){\n\
    \          T w = 1;\n          for(int j = 0, k = 1; j < n; j += 2 * b, ++k){\n\
    \            for(int i = 0; i < b; ++i){\n              const auto s = f[i + j];\n\
    \              const auto t = f[i + j + b];\n\n              f[i + j] = s + t;\n\
    \              f[i + j + b] = (s - t) * w;\n            }\n            w *= INV_BASE[__builtin_ctz(k)];\n\
    \          }\n        }\n\n        const T t = T::inv(n);\n        for(auto &x\
    \ : f) x *= t;\n      }else{\n        for(int b = n >> 1; b; b >>= 1){\n     \
    \     T w = 1;\n          for(int j = 0, k = 1; j < n; j += 2 * b, ++k){\n   \
    \         for(int i = 0; i < b; ++i){\n              const auto s = f[i + j];\n\
    \              const auto t = f[i + j + b] * w;\n\n              f[i + j] = s\
    \ + t;\n              f[i + j + b] = s - t;\n            }\n            w *= BASE[__builtin_ctz(k)];\n\
    \          }\n        }\n      }\n    }\n\n    template <typename U>\n    std::vector<T>\
    \ convolve(std::vector<U> f, std::vector<U> g){\n      const int m = f.size()\
    \ + g.size() - 1;\n      int n = 1;\n      while(n < m) n *= 2;\n\n      std::vector<T>\
    \ f2(n), g2(n);\n\n      for(int i = 0; i < (int)f.size(); ++i) f2[i] = f[i];\n\
    \      for(int i = 0; i < (int)g.size(); ++i) g2[i] = g[i];\n\n      run(f2);\n\
    \      run(g2);\n\n      for(int i = 0; i < n; ++i) f2[i] *= g2[i];\n      run(f2,\
    \ true);\n\n      return f2;\n    }\n  };\n\n  template <typename T, typename\
    \ U>\n  std::vector<T> convolve_general_mod(std::vector<U> f, std::vector<U> g){\n\
    \    static constexpr int M1 = 167772161, P1 = 3;\n    static constexpr int M2\
    \ = 469762049, P2 = 3;\n    static constexpr int M3 = 1224736769, P3 = 3;\n\n\
    \    for(auto &x : f) x %= T::mod();\n    for(auto &x : g) x %= T::mod();\n\n\
    \    auto res1 = number_theoretic_transform<modint<M1>, P1, 1 << 20>().convolve(f,\
    \ g);\n    auto res2 = number_theoretic_transform<modint<M2>, P2, 1 << 20>().convolve(f,\
    \ g);\n    auto res3 = number_theoretic_transform<modint<M3>, P3, 1 << 20>().convolve(f,\
    \ g);\n\n    const int n = res1.size();\n\n    std::vector<T> ret(n);\n\n    const\
    \ int64_t M12 = (int64_t)modint<M2>::inv(M1);\n    const int64_t M13 = (int64_t)modint<M3>::inv(M1);\n\
    \    const int64_t M23 = (int64_t)modint<M3>::inv(M2);\n\n    for(int i = 0; i\
    \ < n; ++i){\n      const int64_t r[3] = {(int64_t)res1[i], (int64_t)res2[i],\
    \ (int64_t)res3[i]};\n\n      const int64_t t0 = r[0] % M1;\n      const int64_t\
    \ t1 = (r[1] - t0 + M2) * M12 % M2;\n      const int64_t t2 = ((r[2] - t0 + M3)\
    \ * M13 % M3 - t1 + M3) * M23 % M3;\n\n      ret[i] = T(t0) + T(t1) * M1 + T(t2)\
    \ * M1 * M2;\n    }\n\n    return ret;\n  }\n}\n#line 4 \"Mylib/Math/formal_power_series.cpp\"\
    \n#include <initializer_list>\n#line 6 \"Mylib/Math/formal_power_series.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename T>\n  struct formal_power_series\
    \ {\n    using value_type = T;\n\n    static std::function<std::vector<T>(std::vector<T>,\
    \ std::vector<T>)> convolve;\n    static std::function<std::optional<T>(T)> get_sqrt;\n\
    \n    std::vector<T> data;\n\n    formal_power_series(const std::vector<T> &data):\
    \ data(data){}\n    formal_power_series(std::initializer_list<T> init): data(init.begin(),\
    \ init.end()){}\n    formal_power_series(int N): data(N){}\n\n    int size() const\
    \ {\n      return data.size();\n    }\n\n    const T& operator[](int i) const\
    \ {\n      return data[i];\n    }\n\n    T& operator[](int i){\n      return data[i];\n\
    \    }\n\n    auto begin() {return data.begin();}\n    auto end() {return data.end();}\n\
    \n    void resize(int n){\n      data.resize(n);\n    }\n\n    auto operator+(const\
    \ formal_power_series &rhs) const {\n      std::vector<T> ret(data);\n      ret.resize(rhs.size());\n\
    \      for(int i = 0; i < (int)rhs.size(); ++i) ret[i] += rhs[i];\n      return\
    \ formal_power_series(ret);\n    }\n\n    auto operator-(const formal_power_series\
    \ &rhs) const {\n      std::vector<T> ret(data);\n      ret.resize(rhs.size());\n\
    \      for(int i = 0; i < (int)rhs.size(); ++i) ret[i] -= rhs[i];\n      return\
    \ formal_power_series(ret);\n    }\n\n    auto operator*(const formal_power_series\
    \ &rhs) const {\n      auto ret = convolve(data, rhs.data);\n      return formal_power_series(ret);\n\
    \    }\n\n    auto operator*(T b) const {\n      std::vector<T> ret(data);\n \
    \     for(auto &x : ret) x *= b;\n      return formal_power_series(ret);\n   \
    \ }\n\n    auto differentiate() const {\n      const int n = data.size();\n  \
    \    std::vector<T> ret(n - 1);\n      for(int i = 0; i < n - 1; ++i){\n     \
    \   ret[i] = data[i + 1] * (i + 1);\n      }\n\n      return formal_power_series(ret);\n\
    \    }\n\n    auto integrate() const {\n      const int n = data.size();\n   \
    \   std::vector<T> ret(n + 1);\n      for(int i = 0; i < n; ++i){\n        ret[i\
    \ + 1] = data[i] / (i + 1);\n      }\n\n      return formal_power_series(ret);\n\
    \    }\n\n    auto inv() const {\n      assert(data[0] != 0);\n      const int\
    \ n = data.size();\n\n      int t = 1;\n      std::vector<T> ret = {data[0].inv()};\n\
    \      ret.reserve(n * 2);\n\n      while(t <= n * 2){\n        std::vector<T>\
    \ c(data.begin(), data.begin() + std::min(t, n));\n        c = convolve(c, convolve(ret,\
    \ ret));\n\n        c.resize(t);\n        ret.resize(t);\n\n        for(int i\
    \ = 0; i < t; ++i){\n          ret[i] = ret[i] * 2 - c[i];\n        }\n\n    \
    \    t <<= 1;\n      }\n\n      ret.resize(n);\n\n      return formal_power_series(ret);\n\
    \    }\n\n    auto log() const {\n      assert(data[0] == 1);\n      const int\
    \ n = data.size();\n      auto ret = (differentiate() * inv()).integrate();\n\
    \      ret.resize(n);\n      return ret;\n    }\n\n    auto exp() const {\n  \
    \    const int n = data.size();\n\n      int t = 1;\n      formal_power_series\
    \ b({1});\n\n      while(t <= n * 2){\n        t <<= 1;\n        auto temp = b.log();\n\
    \        temp.resize(t);\n\n        for(int i = 0; i < t; ++i) temp[i] = -temp[i];\n\
    \        temp[0] += 1;\n        for(int i = 0; i < std::min(t, n); ++i) temp[i]\
    \ += data[i];\n\n        b = b * temp;\n        b.resize(t);\n      }\n\n    \
    \  b.resize(n);\n\n      return b;\n    }\n\n    auto shift(int64_t k) const {\n\
    \      const int64_t n = data.size();\n      formal_power_series ret(n);\n\n \
    \     if(k >= 0){\n        for(int64_t i = k; i < n; ++i){\n          ret[i] =\
    \ data[i - k];\n        }\n      }else{\n        for(int64_t i = 0; i < n + k;\
    \ ++i){\n          ret[i] = data[i - k];\n        }\n      }\n\n      return ret;\n\
    \    }\n\n    auto pow(int64_t M) const {\n      assert(M >= 0);\n\n      const\
    \ int n = data.size();\n      int k = 0;\n      for(; k < n; ++k){\n        if(data[k]\
    \ != 0){\n          break;\n        }\n      }\n\n      if(k >= n) return *this;\n\
    \n      T a = data[k];\n\n      formal_power_series ret = *this;\n      ret =\
    \ (ret.shift(-k)) * a.inv();\n      ret = (ret.log() * (T)M).exp();\n      ret\
    \ = (ret * a.pow(M)).shift(M * k);\n\n      return ret;\n    }\n\n    std::optional<formal_power_series>\
    \ sqrt() const {\n      const int n = data.size();\n      int k = 0;\n      for(;\
    \ k < n; ++k) if(data[k] != 0) break;\n\n      if(k >= n) return *this;\n    \
    \  if(k % 2 != 0) return {};\n\n      int t = 1;\n      auto x = get_sqrt(data[k]);\n\
    \n      if(not x) return {};\n\n      const int m = n - k;\n\n      auto it =\
    \ data.begin() + k;\n      formal_power_series ret({*x});\n\n      while(t <=\
    \ m * 2){\n        formal_power_series f(std::vector(it, it + std::min(t, m)));\n\
    \        ret.resize(t);\n        f.resize(t);\n        ret = (ret + f * ret.inv())\
    \ * T(2).inv();\n        t <<= 1;\n      }\n\n      ret.resize(n);\n      ret\
    \ = ret.shift(k / 2);\n\n      return ret;\n    }\n  };\n\n  template <typename\
    \ T>\n  std::function<std::vector<T>(std::vector<T>, std::vector<T>)> formal_power_series<T>::convolve;\n\
    \n  template <typename T>\n  std::function<std::optional<T>(T)> formal_power_series<T>::get_sqrt;\n\
    }\n#line 4 \"Mylib/Combinatorics/factorial_table.cpp\"\n#include <cstdint>\n\n\
    namespace haar_lib {\n  template <typename T>\n  class factorial_table {\n  public:\n\
    \    using value_type = T;\n\n  private:\n    std::vector<T> f_table;\n    std::vector<T>\
    \ if_table;\n\n  public:\n    factorial_table(int N){\n      f_table.assign(N\
    \ + 1, 1);\n      if_table.assign(N + 1, 1);\n\n      for(int i = 1; i <= N; ++i){\n\
    \        f_table[i] = f_table[i - 1] * i;\n      }\n\n      if_table[N] = f_table[N].inv();\n\
    \n      for(int i = N; --i >= 0;){\n        if_table[i] = if_table[i + 1] * (i\
    \ + 1);\n      }\n    }\n\n    T factorial(int64_t i) const {\n      assert(i\
    \ < (int)f_table.size());\n      return f_table[i];\n    }\n\n    T inv_factorial(int64_t\
    \ i) const {\n      assert(i < (int)if_table.size());\n      return if_table[i];\n\
    \    }\n\n    T P(int64_t n, int64_t k) const {\n      if(n < k or n < 0 or k\
    \ < 0) return 0;\n      return factorial(n) * inv_factorial(n - k);\n    }\n\n\
    \    T C(int64_t n, int64_t k) const {\n      if(n < k or n < 0 or k < 0) return\
    \ 0;\n      return P(n, k) * inv_factorial(k);\n    }\n\n    T H(int64_t n, int64_t\
    \ k) const {\n      if(n == 0 and k == 0) return 1;\n      return C(n + k - 1,\
    \ k);\n    }\n  };\n}\n#line 2 \"Mylib/Combinatorics/bernoulli_number_fps.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Fps, typename Ft>\n  auto bernoulli_number_fps(int\
    \ N, const Ft &ft){\n    Fps x(N + 1);\n\n    for(int i = 0; i <= N; ++i) x[i]\
    \ = ft.inv_factorial(i + 1);\n    x = x.inv();\n\n    for(int i = 0; i <= N; ++i)\
    \ x[i] *= ft.factorial(i);\n\n    return x;\n  }\n}\n#line 11 \"test/yosupo-judge/bernoulli_number/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing mint = hl::modint<998244353>;\nconstexpr\
    \ int PRIM_ROOT = 3;\nusing FPS = hl::formal_power_series<mint>;\nusing NTT =\
    \ hl::number_theoretic_transform<mint, PRIM_ROOT, 1 << 20>;\n\nint main(){\n \
    \ using namespace std::placeholders;\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N; std::cin >> N;\n\n  auto ft = hl::factorial_table<mint>(N + 1);\n\n\
    \  auto ntt = NTT();\n  FPS::convolve = std::bind(&NTT::convolve<mint>, &ntt,\
    \ _1, _2);\n\n  auto res = hl::bernoulli_number_fps<FPS>(N, ft);\n  std::cout\
    \ << hl::join(res.begin(), res.begin() + N + 1) << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bernoulli_number\"\n\n\
    #include <iostream>\n#include <functional>\n#include \"Mylib/IO/join.cpp\"\n#include\
    \ \"Mylib/Number/Mint/mint.cpp\"\n#include \"Mylib/Convolution/ntt_convolution.cpp\"\
    \n#include \"Mylib/Math/formal_power_series.cpp\"\n#include \"Mylib/Combinatorics/factorial_table.cpp\"\
    \n#include \"Mylib/Combinatorics/bernoulli_number_fps.cpp\"\n\nnamespace hl =\
    \ haar_lib;\n\nusing mint = hl::modint<998244353>;\nconstexpr int PRIM_ROOT =\
    \ 3;\nusing FPS = hl::formal_power_series<mint>;\nusing NTT = hl::number_theoretic_transform<mint,\
    \ PRIM_ROOT, 1 << 20>;\n\nint main(){\n  using namespace std::placeholders;\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N; std::cin\
    \ >> N;\n\n  auto ft = hl::factorial_table<mint>(N + 1);\n\n  auto ntt = NTT();\n\
    \  FPS::convolve = std::bind(&NTT::convolve<mint>, &ntt, _1, _2);\n\n  auto res\
    \ = hl::bernoulli_number_fps<FPS>(N, ft);\n  std::cout << hl::join(res.begin(),\
    \ res.begin() + N + 1) << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/join.cpp
  - Mylib/Number/Mint/mint.cpp
  - Mylib/Convolution/ntt_convolution.cpp
  - Mylib/Math/formal_power_series.cpp
  - Mylib/Combinatorics/factorial_table.cpp
  - Mylib/Combinatorics/bernoulli_number_fps.cpp
  isVerificationFile: true
  path: test/yosupo-judge/bernoulli_number/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-17 22:58:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/bernoulli_number/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/bernoulli_number/main.test.cpp
- /verify/test/yosupo-judge/bernoulli_number/main.test.cpp.html
title: test/yosupo-judge/bernoulli_number/main.test.cpp
---
