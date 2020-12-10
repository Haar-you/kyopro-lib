---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Convolution/ntt_convolution.cpp
    title: Number theoretic transform
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: join function
  - icon: ':question:'
    path: Mylib/Math/formal_power_series.cpp
    title: Formal power series
  - icon: ':question:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  - icon: ':question:'
    path: Mylib/Number/Mod/mod_pow.cpp
    title: Mod pow
  - icon: ':question:'
    path: Mylib/Number/Prime/primitive_root.cpp
    title: Primitive root
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/log_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/log_of_formal_power_series
  bundledCode: "#line 1 \"test/yosupo-judge/log_of_formal_power_series/main.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/log_of_formal_power_series\"\
    \n\n#include <iostream>\n#include <vector>\n#include <functional>\n#line 3 \"\
    Mylib/Number/Mint/mint.cpp\"\n#include <utility>\n\nnamespace haar_lib {\n  template\
    \ <int32_t M>\n  class modint {\n    uint32_t val_;\n\n  public:\n    constexpr\
    \ static auto mod(){return M;}\n\n    constexpr modint(): val_(0){}\n    constexpr\
    \ modint(int64_t n){\n      if(n >= M) val_ = n % M;\n      else if(n < 0) val_\
    \ = n % M + M;\n      else val_ = n;\n    }\n\n    constexpr auto& operator=(const\
    \ modint &a){val_ = a.val_; return *this;}\n    constexpr auto& operator+=(const\
    \ modint &a){\n      if(val_ + a.val_ >= M) val_ = (uint64_t)val_ + a.val_ - M;\n\
    \      else val_ += a.val_;\n      return *this;\n    }\n    constexpr auto& operator-=(const\
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
    \ operator int64_t() const noexcept {return val_;}\n  };\n}\n#line 2 \"Mylib/Number/Mod/mod_pow.cpp\"\
    \n#include <cstdint>\n\nnamespace haar_lib {\n  constexpr int64_t mod_pow(int64_t\
    \ n, int64_t p, int64_t m){\n    int64_t ret = 1;\n    while(p > 0){\n      if(p\
    \ & 1) (ret *= n) %= m;\n      (n *= n) %= m;\n      p >>= 1;\n    }\n    return\
    \ ret;\n  }\n}\n#line 3 \"Mylib/Number/Prime/primitive_root.cpp\"\n\nnamespace\
    \ haar_lib {\n  constexpr int primitive_root(int p){\n    int pf[30] = {};\n \
    \   int k = 0;\n    {\n      int n = p - 1;\n      for(int64_t i = 2; i * i <=\
    \ p; ++i){\n        if(n % i == 0){\n          pf[k++] = i;\n          while(n\
    \ % i == 0) n /= i;\n        }\n      }\n      if(n != 1)\n        pf[k++] = n;\n\
    \    }\n\n    for(int g = 2; g <= p; ++g){\n      bool ok = true;\n      for(int\
    \ i = 0; i < k; ++i){\n        if(mod_pow(g, (p - 1) / pf[i], p) == 1){\n    \
    \      ok = false;\n          break;\n        }\n      }\n\n      if(not ok) continue;\n\
    \n      return g;\n    }\n    return -1;\n  }\n}\n#line 3 \"Mylib/Convolution/ntt_convolution.cpp\"\
    \n#include <cassert>\n#line 5 \"Mylib/Convolution/ntt_convolution.cpp\"\n#include\
    \ <algorithm>\n#line 7 \"Mylib/Convolution/ntt_convolution.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T, int PRIM_ROOT, int MAX_SIZE>\n  class number_theoretic_transform\
    \ {\n  public:\n    using value_type = T;\n    constexpr static int primitive_root\
    \ = PRIM_ROOT;\n    constexpr static int max_size = MAX_SIZE;\n\n  private:\n\
    \    const int MAX_POWER_;\n    std::vector<T> BASE_, INV_BASE_;\n\n  public:\n\
    \    number_theoretic_transform():\n      MAX_POWER_(__builtin_ctz(MAX_SIZE)),\n\
    \      BASE_(MAX_POWER_ + 1),\n      INV_BASE_(MAX_POWER_ + 1)\n    {\n      static_assert((MAX_SIZE\
    \ & (MAX_SIZE - 1)) == 0, \"MAX_SIZE must be power of 2.\");\n\n      T t = T::pow(PRIM_ROOT,\
    \ (T::mod() - 1) >> (MAX_POWER_ + 2));\n      T s = t.inv();\n\n      for(int\
    \ i = MAX_POWER_; --i >= 0;){\n        t *= t;\n        s *= s;\n        BASE_[i]\
    \ = -t;\n        INV_BASE_[i] = -s;\n      }\n    }\n\n    void run(std::vector<T>\
    \ &f, bool INVERSE = false) const {\n      const int n = f.size();\n      assert((n\
    \ & (n - 1)) == 0 and n <= MAX_SIZE); // \u30C7\u30FC\u30BF\u6570\u306F2\u306E\
    \u51AA\u4E57\u500B\n\n      if(INVERSE){\n        for(int b = 1; b < n; b <<=\
    \ 1){\n          T w = 1;\n          for(int j = 0, k = 1; j < n; j += 2 * b,\
    \ ++k){\n            for(int i = 0; i < b; ++i){\n              const auto s =\
    \ f[i + j];\n              const auto t = f[i + j + b];\n\n              f[i +\
    \ j] = s + t;\n              f[i + j + b] = (s - t) * w;\n            }\n    \
    \        w *= INV_BASE_[__builtin_ctz(k)];\n          }\n        }\n\n       \
    \ const T t = T::inv(n);\n        for(auto &x : f) x *= t;\n      }else{\n   \
    \     for(int b = n >> 1; b; b >>= 1){\n          T w = 1;\n          for(int\
    \ j = 0, k = 1; j < n; j += 2 * b, ++k){\n            for(int i = 0; i < b; ++i){\n\
    \              const auto s = f[i + j];\n              const auto t = f[i + j\
    \ + b] * w;\n\n              f[i + j] = s + t;\n              f[i + j + b] = s\
    \ - t;\n            }\n            w *= BASE_[__builtin_ctz(k)];\n          }\n\
    \        }\n      }\n    }\n\n    template <typename U>\n    std::vector<T> convolve(std::vector<U>\
    \ f, std::vector<U> g) const {\n      const int m = f.size() + g.size() - 1;\n\
    \      int n = 1;\n      while(n < m) n *= 2;\n\n      std::vector<T> f2(n), g2(n);\n\
    \n      for(int i = 0; i < (int)f.size(); ++i) f2[i] = (int64_t)f[i];\n      for(int\
    \ i = 0; i < (int)g.size(); ++i) g2[i] = (int64_t)g[i];\n\n      run(f2);\n  \
    \    run(g2);\n\n      for(int i = 0; i < n; ++i) f2[i] *= g2[i];\n      run(f2,\
    \ true);\n\n      return f2;\n    }\n\n    template <typename U>\n    std::vector<T>\
    \ operator()(std::vector<U> f, std::vector<U> g) const {\n      return convolve(f,\
    \ g);\n    }\n  };\n\n  template <typename T>\n  std::vector<T> convolve_general_mod(std::vector<T>\
    \ f, std::vector<T> g){\n    static constexpr int M1 = 167772161, P1 = 3;\n  \
    \  static constexpr int M2 = 469762049, P2 = 3;\n    static constexpr int M3 =\
    \ 1224736769, P3 = 3;\n\n    auto res1 = number_theoretic_transform<modint<M1>,\
    \ P1, 1 << 20>().convolve(f, g);\n    auto res2 = number_theoretic_transform<modint<M2>,\
    \ P2, 1 << 20>().convolve(f, g);\n    auto res3 = number_theoretic_transform<modint<M3>,\
    \ P3, 1 << 20>().convolve(f, g);\n\n    const int n = res1.size();\n\n    std::vector<T>\
    \ ret(n);\n\n    const int64_t M12 = (int64_t)modint<M2>::inv(M1);\n    const\
    \ int64_t M13 = (int64_t)modint<M3>::inv(M1);\n    const int64_t M23 = (int64_t)modint<M3>::inv(M2);\n\
    \n    for(int i = 0; i < n; ++i){\n      const int64_t r[3] = {(int64_t)res1[i],\
    \ (int64_t)res2[i], (int64_t)res3[i]};\n\n      const int64_t t0 = r[0] % M1;\n\
    \      const int64_t t1 = (r[1] - t0 + M2) * M12 % M2;\n      const int64_t t2\
    \ = ((r[2] - t0 + M3) * M13 % M3 - t1 + M3) * M23 % M3;\n\n      ret[i] = T(t0)\
    \ + T(t1) * M1 + T(t2) * M1 * M2;\n    }\n\n    return ret;\n  }\n}\n#line 4 \"\
    Mylib/Math/formal_power_series.cpp\"\n#include <initializer_list>\n#line 6 \"\
    Mylib/Math/formal_power_series.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T, const auto &convolve>\n  class formal_power_series {\n  public:\n    using\
    \ value_type = T;\n\n  private:\n    std::vector<T> data_;\n\n  public:\n    formal_power_series(){}\n\
    \    explicit formal_power_series(int N): data_(N){}\n    formal_power_series(const\
    \ std::vector<T> &data_): data_(data_){}\n    formal_power_series(std::initializer_list<T>\
    \ init): data_(init.begin(), init.end()){}\n    formal_power_series(const formal_power_series\
    \ &a): data_(a.data_){}\n    formal_power_series(formal_power_series &&a) noexcept\
    \ {*this = std::move(a);}\n\n    size_t size() const {\n      return data_.size();\n\
    \    }\n\n    const T& operator[](int i) const {\n      return data_[i];\n   \
    \ }\n\n    T& operator[](int i){\n      return data_[i];\n    }\n\n    auto begin()\
    \ {return data_.begin();}\n    auto end() {return data_.end();}\n\n    const auto&\
    \ data() const {return data_;}\n\n    void resize(int n){\n      data_.resize(n);\n\
    \    }\n\n    auto& operator=(formal_power_series &&rhs) noexcept {\n      if(this\
    \ != &rhs){\n        data_ = std::move(rhs.data_);\n      }\n      return *this;\n\
    \    }\n\n    auto& operator+=(const formal_power_series &rhs){\n      if(data_.size()\
    \ < rhs.size()) data_.resize(rhs.size());\n      for(int i = 0; i < rhs.size();\
    \ ++i) data_[i] += rhs[i];\n      return *this;\n    }\n\n    auto& operator+=(T\
    \ rhs){\n      data_[0] += rhs;\n      return *this;\n    }\n\n    auto operator+(T\
    \ rhs) const {\n      auto ret = *this;\n      return ret += rhs;\n    }\n\n \
    \   auto operator+(const formal_power_series &rhs) const {\n      auto ret = *this;\n\
    \      return ret += rhs;\n    }\n\n    auto& operator-=(const formal_power_series\
    \ &rhs){\n      if(data_.size() < rhs.size()) data_.resize(rhs.size());\n    \
    \  for(int i = 0; i < rhs.size(); ++i) data_[i] -= rhs[i];\n      return *this;\n\
    \    }\n\n    auto& operator-=(T rhs){\n      data_[0] -= rhs;\n      return *this;\n\
    \    }\n\n    auto operator-(T rhs) const {\n      auto ret = *this;\n      return\
    \ ret -= rhs;\n    }\n\n    auto operator-(const formal_power_series &rhs) const\
    \ {\n      auto ret = *this;\n      return ret -= rhs;\n    }\n\n    auto operator-()\
    \ const {\n      auto ret = *this;\n      for(auto &x : ret) x = -x;\n      return\
    \ ret;\n    }\n\n    auto& operator*=(const formal_power_series &rhs){\n     \
    \ data_ = convolve(data_, rhs.data_);\n      return *this;\n    }\n\n    auto\
    \ operator*(const formal_power_series &rhs) const {\n      auto ret = convolve(data_,\
    \ rhs.data_);\n      return formal_power_series(ret);\n    }\n\n    auto& operator*=(T\
    \ rhs){\n      for(auto &x : data_) x *= rhs;\n      return *this;\n    }\n\n\
    \    auto operator*(T rhs) const {\n      auto ret = *this;\n      return ret\
    \ *= rhs;\n    }\n\n    auto differentiate() const {\n      const int n = data_.size();\n\
    \      std::vector<T> ret(n - 1);\n      for(int i = 0; i < n - 1; ++i){\n   \
    \     ret[i] = data_[i + 1] * (i + 1);\n      }\n\n      return formal_power_series(ret);\n\
    \    }\n\n    auto integrate() const {\n      const int n = data_.size();\n  \
    \    std::vector<T> ret(n + 1);\n      for(int i = 0; i < n; ++i){\n        ret[i\
    \ + 1] = data_[i] / (i + 1);\n      }\n\n      return formal_power_series(ret);\n\
    \    }\n\n    auto inv() const {\n      assert(data_[0] != 0);\n      const int\
    \ n = data_.size();\n\n      int t = 1;\n      std::vector<T> ret = {data_[0].inv()};\n\
    \      ret.reserve(n * 2);\n\n      while(t <= n * 2){\n        std::vector<T>\
    \ c(data_.begin(), data_.begin() + std::min(t, n));\n        c = convolve(c, convolve(ret,\
    \ ret));\n\n        c.resize(t);\n        ret.resize(t);\n\n        for(int i\
    \ = 0; i < t; ++i){\n          ret[i] = ret[i] * 2 - c[i];\n        }\n\n    \
    \    t <<= 1;\n      }\n\n      ret.resize(n);\n\n      return formal_power_series(ret);\n\
    \    }\n\n    auto log() const {\n      assert(data_[0] == 1);\n      const int\
    \ n = data_.size();\n      auto ret = (differentiate() * inv()).integrate();\n\
    \      ret.resize(n);\n      return ret;\n    }\n\n    auto exp() const {\n  \
    \    const int n = data_.size();\n\n      int t = 1;\n      formal_power_series\
    \ b({1});\n\n      while(t <= n * 2){\n        t <<= 1;\n        auto temp = b.log();\n\
    \        temp.resize(t);\n\n        for(int i = 0; i < t; ++i) temp[i] = -temp[i];\n\
    \        temp[0] += 1;\n        for(int i = 0; i < std::min(t, n); ++i) temp[i]\
    \ += data_[i];\n\n        b = b * temp;\n        b.resize(t);\n      }\n\n   \
    \   b.resize(n);\n\n      return b;\n    }\n\n    auto shift(int64_t k) const\
    \ {\n      const int64_t n = data_.size();\n      formal_power_series ret(n);\n\
    \n      if(k >= 0){\n        for(int64_t i = k; i < n; ++i){\n          ret[i]\
    \ = data_[i - k];\n        }\n      }else{\n        for(int64_t i = 0; i < n +\
    \ k; ++i){\n          ret[i] = data_[i - k];\n        }\n      }\n\n      return\
    \ ret;\n    }\n\n    auto pow(int64_t M) const {\n      assert(M >= 0);\n\n  \
    \    const int n = data_.size();\n      int k = 0;\n      for(; k < n; ++k){\n\
    \        if(data_[k] != 0){\n          break;\n        }\n      }\n\n      if(k\
    \ >= n) return *this;\n\n      T a = data_[k];\n\n      formal_power_series ret\
    \ = *this;\n      ret = (ret.shift(-k)) * a.inv();\n      ret = (ret.log() * (T)M).exp();\n\
    \      ret = (ret * a.pow(M)).shift(M * k);\n\n      return ret;\n    }\n\n  \
    \  std::optional<formal_power_series> sqrt() const;\n  };\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n#include <string>\n\nnamespace\
    \ haar_lib {\n  template <typename Iter>\n  std::string join(Iter first, Iter\
    \ last, std::string delim = \" \"){\n    std::stringstream s;\n\n    for(auto\
    \ it = first; it != last; ++it){\n      if(it != first) s << delim;\n      s <<\
    \ *it;\n    }\n\n    return s.str();\n  }\n}\n#line 12 \"test/yosupo-judge/log_of_formal_power_series/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nconstexpr int mod = 998244353;\nconstexpr int\
    \ prim_root = hl::primitive_root(mod);\nusing mint = hl::modint<mod>;\nusing NTT\
    \ = hl::number_theoretic_transform<mint, prim_root, 1 << 20>;\nconst static auto\
    \ ntt = NTT();\nusing FPS = hl::formal_power_series<mint, ntt>;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N; std::cin\
    \ >> N;\n  auto a = hl::input_vector<mint>(N);\n  auto ans = FPS(a).log();\n\n\
    \  std::cout << hl::join(ans.begin(), ans.begin() + N) << \"\\n\";\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/log_of_formal_power_series\"\
    \n\n#include <iostream>\n#include <vector>\n#include <functional>\n#include \"\
    Mylib/Number/Mint/mint.cpp\"\n#include \"Mylib/Number/Prime/primitive_root.cpp\"\
    \n#include \"Mylib/Convolution/ntt_convolution.cpp\"\n#include \"Mylib/Math/formal_power_series.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n#include \"Mylib/IO/join.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nconstexpr int mod = 998244353;\nconstexpr int prim_root =\
    \ hl::primitive_root(mod);\nusing mint = hl::modint<mod>;\nusing NTT = hl::number_theoretic_transform<mint,\
    \ prim_root, 1 << 20>;\nconst static auto ntt = NTT();\nusing FPS = hl::formal_power_series<mint,\
    \ ntt>;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N; std::cin >> N;\n  auto a = hl::input_vector<mint>(N);\n  auto ans =\
    \ FPS(a).log();\n\n  std::cout << hl::join(ans.begin(), ans.begin() + N) << \"\
    \\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Mint/mint.cpp
  - Mylib/Number/Prime/primitive_root.cpp
  - Mylib/Number/Mod/mod_pow.cpp
  - Mylib/Convolution/ntt_convolution.cpp
  - Mylib/Math/formal_power_series.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/join.cpp
  isVerificationFile: true
  path: test/yosupo-judge/log_of_formal_power_series/main.test.cpp
  requiredBy: []
  timestamp: '2020-12-09 11:17:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/log_of_formal_power_series/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/log_of_formal_power_series/main.test.cpp
- /verify/test/yosupo-judge/log_of_formal_power_series/main.test.cpp.html
title: test/yosupo-judge/log_of_formal_power_series/main.test.cpp
---
