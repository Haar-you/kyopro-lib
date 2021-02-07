---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Combinatorics/montmort_number.cpp
    title: Montmort number
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/join.cpp
    title: join function
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Mint/runtime_mint.cpp
    title: Modint (Runtime mod)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/montmort_number_mod
    links:
    - https://judge.yosupo.jp/problem/montmort_number_mod
  bundledCode: "#line 1 \"test/yosupo-judge/montmort_number_mod/main.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/montmort_number_mod\"\n\n#include\
    \ <iostream>\n#line 3 \"Mylib/Number/Mint/runtime_mint.cpp\"\n#include <utility>\n\
    \nnamespace haar_lib {\n  template <const int &M>\n  class runtime_modint {\n\
    \    int64_t val_;\n\n  public:\n    runtime_modint(): val_(0){}\n    runtime_modint(int64_t\
    \ n){\n      if(n >= M) val_ = n % M;\n      else if(n < 0) val_ = n % M + M;\n\
    \      else val_ = n;\n    }\n\n    static auto mod(){return M;}\n\n    auto operator+(const\
    \ runtime_modint &a) const {return runtime_modint(val_ + a.val_);}\n    auto operator-(const\
    \ runtime_modint &a) const {return runtime_modint(val_ - a.val_);}\n    auto operator*(const\
    \ runtime_modint &a) const {return runtime_modint(val_ * a.val_);}\n    auto operator/(const\
    \ runtime_modint &a) const {return runtime_modint(val_ * a.inv().val_);}\n\n \
    \   const auto& operator=(const runtime_modint &a){val_ = a.val_; return *this;}\n\
    \    const auto& operator+=(const runtime_modint &a){if((val_ += a.val_) >= M)\
    \ val_ -= M; return *this;}\n    const auto& operator-=(const runtime_modint &a){if(val_\
    \ < a.val_) val_ += M; val_ -= a.val_; return *this;}\n    const auto& operator*=(const\
    \ runtime_modint &a){(val_ *= a.val_) %= M; return *this;}\n    const auto& operator/=(const\
    \ runtime_modint &a){(val_ *= a.inv().val_) %= M; return *this;}\n\n    bool operator==(const\
    \ runtime_modint &a) const {return val_ == a.val_;}\n    bool operator!=(const\
    \ runtime_modint &a) const {return val_ != a.val_;}\n\n    static auto pow(int64_t\
    \ n, int64_t p){\n      runtime_modint ret = 1, e = n;\n      for(; p; e *= e,\
    \ p >>= 1) if(p & 1) ret *= e;\n      return ret;\n    }\n\n    auto pow(int64_t\
    \ p) const {\n      runtime_modint ret = 1, e = val_;\n      for(; p; e *= e,\
    \ p >>= 1) if(p & 1) ret *= e;\n      return ret;\n    }\n\n    runtime_modint\
    \ inv() const {\n      int64_t a = val_, b = M, u = 1, v = 0;\n\n      while(b){\n\
    \        int64_t t = a / b;\n        a -= t * b; std::swap(a, b);\n        u -=\
    \ t * v; std::swap(u, v);\n      }\n      u %= M;\n      if(u < 0) u += M;\n\n\
    \      return u;\n    }\n\n    explicit operator int32_t() const noexcept {return\
    \ val_;}\n    explicit operator int64_t() const noexcept {return val_;}\n\n  \
    \  friend auto operator-(const runtime_modint &a){return runtime_modint(-a.val_);}\n\
    \n    friend auto operator+(int64_t a, const runtime_modint &b){return runtime_modint(a)\
    \ + b;}\n    friend auto operator-(int64_t a, const runtime_modint &b){return\
    \ runtime_modint(a) - b;}\n    friend auto operator*(int64_t a, const runtime_modint\
    \ &b){return runtime_modint(a) * b;}\n    friend auto operator/(int64_t a, const\
    \ runtime_modint &b){return runtime_modint(a) / b;}\n\n    friend std::istream&\
    \ operator>>(std::istream &is, runtime_modint &a){is >> a.val_; return is;}\n\
    \    friend std::ostream& operator<<(std::ostream &os, const runtime_modint &a){os\
    \ << a.val_; return os;}\n  };\n}\n#line 2 \"Mylib/Combinatorics/montmort_number.cpp\"\
    \n#include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  auto montmort_number(int\
    \ n){\n    std::vector<T> ret(n + 1);\n\n    ret[0] = 1;\n    ret[1] = 0;\n  \
    \  ret[2] = 1;\n\n    for(int i = 3; i <= n; ++i){\n      ret[i] = (ret[i - 1]\
    \ + ret[i - 2]) * (i - 1);\n    }\n\n    return ret;\n  }\n}\n#line 3 \"Mylib/IO/join.cpp\"\
    \n#include <sstream>\n#include <string>\n\nnamespace haar_lib {\n  template <typename\
    \ Iter>\n  std::string join(Iter first, Iter last, std::string delim = \" \"){\n\
    \    std::stringstream s;\n\n    for(auto it = first; it != last; ++it){\n   \
    \   if(it != first) s << delim;\n      s << *it;\n    }\n\n    return s.str();\n\
    \  }\n}\n#line 7 \"test/yosupo-judge/montmort_number_mod/main.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\n\nstatic int M;\nusing mint = hl::runtime_modint<M>;\n\nint\
    \ main(){\n  int N; std::cin >> N >> M;\n\n  auto ans = hl::montmort_number<mint>(1000000);\n\
    \n  std::cout << hl::join(ans.begin() + 1, ans.begin() + N + 1) << \"\\n\";\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/montmort_number_mod\"\n\
    \n#include <iostream>\n#include \"Mylib/Number/Mint/runtime_mint.cpp\"\n#include\
    \ \"Mylib/Combinatorics/montmort_number.cpp\"\n#include \"Mylib/IO/join.cpp\"\n\
    \nnamespace hl = haar_lib;\n\n\nstatic int M;\nusing mint = hl::runtime_modint<M>;\n\
    \nint main(){\n  int N; std::cin >> N >> M;\n\n  auto ans = hl::montmort_number<mint>(1000000);\n\
    \n  std::cout << hl::join(ans.begin() + 1, ans.begin() + N + 1) << \"\\n\";\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Mint/runtime_mint.cpp
  - Mylib/Combinatorics/montmort_number.cpp
  - Mylib/IO/join.cpp
  isVerificationFile: true
  path: test/yosupo-judge/montmort_number_mod/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/montmort_number_mod/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/montmort_number_mod/main.test.cpp
- /verify/test/yosupo-judge/montmort_number_mod/main.test.cpp.html
title: test/yosupo-judge/montmort_number_mod/main.test.cpp
---
