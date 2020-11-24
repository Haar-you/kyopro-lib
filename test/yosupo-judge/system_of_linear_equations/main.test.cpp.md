---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: join function
  - icon: ':heavy_check_mark:'
    path: Mylib/LinearAlgebra/SimultaneousLinearEquations/simultaneous_linear_equations.cpp
    title: Simultaneous linear equations
  - icon: ':question:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/system_of_linear_equations
    links:
    - https://judge.yosupo.jp/problem/system_of_linear_equations
  bundledCode: "#line 1 \"test/yosupo-judge/system_of_linear_equations/main.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations\"\
    \n\n#include <vector>\n#line 2 \"Mylib/Number/Mint/mint.cpp\"\n#include <iostream>\n\
    #include <utility>\n\nnamespace haar_lib {\n  template <int32_t M>\n  class modint\
    \ {\n    uint32_t val_;\n\n  public:\n    constexpr static auto mod(){return M;}\n\
    \n    constexpr modint(): val_(0){}\n    constexpr modint(int64_t n){\n      if(n\
    \ >= M) val_ = n % M;\n      else if(n < 0) val_ = n % M + M;\n      else val_\
    \ = n;\n    }\n\n    constexpr auto& operator=(const modint &a){val_ = a.val_;\
    \ return *this;}\n    constexpr auto& operator+=(const modint &a){\n      if(val_\
    \ + a.val_ >= M) val_ = (uint64_t)val_ + a.val_ - M;\n      else val_ += a.val_;\n\
    \      return *this;\n    }\n    constexpr auto& operator-=(const modint &a){\n\
    \      if(val_ < a.val_) val_ += M;\n      val_ -= a.val_;\n      return *this;\n\
    \    }\n    constexpr auto& operator*=(const modint &a){\n      val_ = (uint64_t)val_\
    \ * a.val_ % M;\n      return *this;\n    }\n    constexpr auto& operator/=(const\
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
    \ operator int64_t() const noexcept {return val_;}\n  };\n}\n#line 3 \"Mylib/LinearAlgebra/SimultaneousLinearEquations/simultaneous_linear_equations.cpp\"\
    \n#include <optional>\n#line 5 \"Mylib/LinearAlgebra/SimultaneousLinearEquations/simultaneous_linear_equations.cpp\"\
    \n\nnamespace haar_lib {\n  namespace simulaneous_linear_equations_impl {\n  \
    \  template <typename T>\n    struct result {\n      int rank, dim;\n      std::vector<T>\
    \ solution;\n      std::vector<std::vector<T>> basis;\n    };\n  }\n\n  template\
    \ <typename T>\n  auto simulaneous_linear_equations(std::vector<std::vector<T>>\
    \ a, std::vector<T> b){\n    using result = simulaneous_linear_equations_impl::result<T>;\n\
    \    std::optional<result> ret;\n    const int n = a.size();\n    const int m\
    \ = a[0].size();\n\n    int rank = 0;\n\n    for(int j = 0; j < m; ++j){\n   \
    \   int pivot = -1;\n\n      for(int i = rank; i < n; ++i){\n        if(a[i][j]\
    \ != 0){\n          pivot = i;\n          break;\n        }\n      }\n\n     \
    \ if(pivot == -1) continue;\n\n      std::swap(a[pivot], a[rank]);\n      std::swap(b[pivot],\
    \ b[rank]);\n\n      auto d = a[rank][j];\n      for(int k = 0; k < m; ++k) a[rank][k]\
    \ /= d;\n      b[rank] /= d;\n\n      for(int i = 0; i < n; ++i){\n        if(i\
    \ == rank or a[i][j] == 0) continue;\n        auto d = a[i][j];\n        for(int\
    \ k = 0; k < m; ++k) a[i][k] -= a[rank][k] * d;\n        b[i] -= b[rank] * d;\n\
    \      }\n\n      ++rank;\n    }\n\n    for(int i = rank; i < n; ++i){\n     \
    \ if(b[i] != 0){\n        return ret;\n      }\n    }\n\n    const int dim = m\
    \ - rank;\n\n    std::vector<std::vector<T>> basis(dim, std::vector<T>(m));\n\
    \    std::vector<int> index;\n\n    {\n      int k = 0;\n      for(int i = 0;\
    \ i < rank; ++i){\n        for(int j = k; j < m; ++j){\n          if(a[i][j] ==\
    \ 1){\n            k = j + 1;\n            break;\n          }\n\n          index.push_back(j);\n\
    \        }\n      }\n\n      for(int j = k; j < m; ++j) index.push_back(j);\n\
    \    }\n\n    for(int i = 0, k = 0; i < rank; ++i){\n      for(int j = k; j <\
    \ m; ++j){\n        if(a[i][j] == 1){\n          for(int l = 0; l < dim; ++l)\
    \ basis[l][j] = -a[i][index[l]];\n          k = j + 1;\n          break;\n   \
    \     }\n      }\n    }\n\n    for(int i = 0; i < dim; ++i) basis[i][index[i]]\
    \ = 1;\n\n    std::vector<T> solution(m);\n    for(int i = 0; i < rank; ++i) solution[i]\
    \ = b[i];\n\n    ret = result({rank, dim, solution, basis});\n\n    return ret;\n\
    \  }\n}\n#line 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n#include <string>\n\
    \nnamespace haar_lib {\n  template <typename Iter>\n  std::string join(Iter first,\
    \ Iter last, std::string delim = \" \"){\n    std::stringstream s;\n\n    for(auto\
    \ it = first; it != last; ++it){\n      if(it != first) s << delim;\n      s <<\
    \ *it;\n    }\n\n    return s.str();\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 8 \"test/yosupo-judge/system_of_linear_equations/main.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nusing mint = hl::modint<998244353>;\n\nint main(){\n  std::cin.tie(0);\n\
    \  std::ios::sync_with_stdio(false);\n\n  int N, M; std::cin >> N >> M;\n\n  auto\
    \ A = hl::input_vector<mint>(N, M);\n  auto B = hl::input_vector<mint>(N);\n\n\
    \  auto res = hl::simulaneous_linear_equations(A, B);\n\n  if(not res){\n    std::cout\
    \ << -1 << \"\\n\";\n  }else{\n    std::cout << (*res).dim << \"\\n\";\n\n   \
    \ std::cout << hl::join((*res).solution.begin(), (*res).solution.end()) << \"\\\
    n\";\n\n    for(auto &b : (*res).basis){\n      std::cout << hl::join(b.begin(),\
    \ b.end()) << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations\"\
    \n\n#include <vector>\n#include \"Mylib/Number/Mint/mint.cpp\"\n#include \"Mylib/LinearAlgebra/SimultaneousLinearEquations/simultaneous_linear_equations.cpp\"\
    \n#include \"Mylib/IO/join.cpp\"\n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nusing mint = hl::modint<998244353>;\n\nint main(){\n  std::cin.tie(0);\n\
    \  std::ios::sync_with_stdio(false);\n\n  int N, M; std::cin >> N >> M;\n\n  auto\
    \ A = hl::input_vector<mint>(N, M);\n  auto B = hl::input_vector<mint>(N);\n\n\
    \  auto res = hl::simulaneous_linear_equations(A, B);\n\n  if(not res){\n    std::cout\
    \ << -1 << \"\\n\";\n  }else{\n    std::cout << (*res).dim << \"\\n\";\n\n   \
    \ std::cout << hl::join((*res).solution.begin(), (*res).solution.end()) << \"\\\
    n\";\n\n    for(auto &b : (*res).basis){\n      std::cout << hl::join(b.begin(),\
    \ b.end()) << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Mint/mint.cpp
  - Mylib/LinearAlgebra/SimultaneousLinearEquations/simultaneous_linear_equations.cpp
  - Mylib/IO/join.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/yosupo-judge/system_of_linear_equations/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-30 07:57:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/system_of_linear_equations/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/system_of_linear_equations/main.test.cpp
- /verify/test/yosupo-judge/system_of_linear_equations/main.test.cpp.html
title: test/yosupo-judge/system_of_linear_equations/main.test.cpp
---
