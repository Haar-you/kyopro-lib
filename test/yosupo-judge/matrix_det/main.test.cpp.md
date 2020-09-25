---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  - icon: ':question:'
    path: Mylib/LinearAlgebra/Square/square_matrix.cpp
    title: Square matrix
  - icon: ':x:'
    path: Mylib/LinearAlgebra/Square/determinant.cpp
    title: Determinant
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Mylib/IO/input_vector.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/yosupo-judge/matrix_det/main.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include <iostream>\n#line\
    \ 3 \"Mylib/Number/Mint/mint.cpp\"\n#include <utility>\n\nnamespace haar_lib {\n\
    \  template <int32_t M>\n  class modint {\n    uint32_t val;\n\n  public:\n  \
    \  constexpr static auto mod(){return M;}\n\n    constexpr modint(): val(0){}\n\
    \    constexpr modint(int64_t n){\n      if(n >= M) val = n % M;\n      else if(n\
    \ < 0) val = n % M + M;\n      else val = n;\n    }\n\n    constexpr auto& operator=(const\
    \ modint &a){val = a.val; return *this;}\n    constexpr auto& operator+=(const\
    \ modint &a){\n      if(val + a.val >= M) val = (uint64_t)val + a.val - M;\n \
    \     else val += a.val;\n      return *this;\n    }\n    constexpr auto& operator-=(const\
    \ modint &a){\n      if(val < a.val) val += M;\n      val -= a.val;\n      return\
    \ *this;\n    }\n    constexpr auto& operator*=(const modint &a){\n      val =\
    \ (uint64_t)val * a.val % M;\n      return *this;\n    }\n    constexpr auto&\
    \ operator/=(const modint &a){\n      val = (uint64_t)val * a.inv().val % M;\n\
    \      return *this;\n    }\n\n    constexpr auto operator+(const modint &a) const\
    \ {return modint(*this) += a;}\n    constexpr auto operator-(const modint &a)\
    \ const {return modint(*this) -= a;}\n    constexpr auto operator*(const modint\
    \ &a) const {return modint(*this) *= a;}\n    constexpr auto operator/(const modint\
    \ &a) const {return modint(*this) /= a;}\n\n    constexpr bool operator==(const\
    \ modint &a) const {return val == a.val;}\n    constexpr bool operator!=(const\
    \ modint &a) const {return val != a.val;}\n\n    constexpr auto& operator++(){*this\
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
    \ p) const {return pow(val, p);}\n    constexpr auto inv() const {return inv(val);}\n\
    \n    friend constexpr auto operator-(const modint &a){return modint(M - a.val);}\n\
    \n    friend constexpr auto operator+(int64_t a, const modint &b){return modint(a)\
    \ + b;}\n    friend constexpr auto operator-(int64_t a, const modint &b){return\
    \ modint(a) - b;}\n    friend constexpr auto operator*(int64_t a, const modint\
    \ &b){return modint(a) * b;}\n    friend constexpr auto operator/(int64_t a, const\
    \ modint &b){return modint(a) / b;}\n\n    friend std::istream& operator>>(std::istream\
    \ &s, modint<M> &a){s >> a.val; return s;}\n    friend std::ostream& operator<<(std::ostream\
    \ &s, const modint<M> &a){s << a.val; return s;}\n\n    template <int N>\n   \
    \ static auto div(){\n      static auto value = inv(N);\n      return value;\n\
    \    }\n\n    explicit operator int32_t() const noexcept {return val;}\n    explicit\
    \ operator int64_t() const noexcept {return val;}\n  };\n}\n#line 2 \"Mylib/LinearAlgebra/Square/square_matrix.cpp\"\
    \n#include <vector>\n#line 4 \"Mylib/LinearAlgebra/Square/square_matrix.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename T, const int &N>\n  struct square_matrix\
    \ {\n    using value_type = T;\n\n    std::vector<std::vector<T>> matrix;\n\n\
    \    square_matrix(): matrix(N, std::vector<T>(N)){}\n    square_matrix(const\
    \ T &val): matrix(N, std::vector<T>(N, val)){}\n    square_matrix(const std::vector<std::vector<T>>\
    \ &matrix): matrix(matrix){}\n\n    bool operator==(const square_matrix &val)\
    \ const {return matrix == val.matrix;}\n    bool operator!=(const square_matrix\
    \ &val) const {return !(*this == val);}\n\n    auto& operator=(const square_matrix\
    \ &val){\n      this->matrix = val.matrix;\n      return *this;\n    }\n\n   \
    \ auto& operator+=(const square_matrix &val){\n      for(int i = 0; i < N; ++i)\n\
    \        for(int j = 0; j < N; ++j)\n          matrix[i][j] = matrix[i][j] + val[i][j];\n\
    \      return *this;\n    }\n\n    auto& operator-=(const square_matrix &val){\n\
    \      for(int i = 0; i < N; ++i)\n        for(int j = 0; j < N; ++j)\n      \
    \    matrix[i][j] = matrix[i][j] - val[i][j];\n      return *this;\n    }\n\n\
    \    auto& operator*=(const square_matrix &val){\n      std::vector<std::vector<T>>\
    \ temp(N, std::vector<T>(N));\n      for(int i = 0; i < N; ++i)\n        for(int\
    \ j = 0; j < N; ++j)\n          for(int k = 0; k < N; ++k)\n            temp[i][j]\
    \ += matrix[i][k] * val[k][j];\n      std::swap(matrix, temp);\n      return *this;\n\
    \    }\n\n    const auto& operator[](size_t i) const {return matrix[i];}\n   \
    \ auto& operator[](size_t i){return matrix[i];}\n    int size() const {return\
    \ N;}\n\n    static auto unit(){\n      square_matrix ret;\n      for(int i =\
    \ 0; i < N; ++i) ret[i][i] = 1;\n      return ret;\n    }\n\n    friend auto operator+(const\
    \ square_matrix &a, const square_matrix &b){\n      auto ret = a; return ret +=\
    \ b;\n    }\n    friend auto operator-(const square_matrix &a, const square_matrix\
    \ &b){\n      auto ret = a; return ret -= b;\n    }\n    friend auto operator*(const\
    \ square_matrix &a, const square_matrix &b){\n      auto ret = a; return ret *=\
    \ b;\n    }\n\n    auto pow(uint64_t p) const {\n      auto ret = unit();\n  \
    \    auto a = *this;\n\n      while(p > 0){\n        if(p & 1) ret *= a;\n   \
    \     a *= a;\n        p >>= 1;\n      }\n\n      return ret;\n    }\n  };\n}\n\
    #line 2 \"Mylib/LinearAlgebra/Square/determinant.cpp\"\n\nnamespace haar_lib {\n\
    \  template <typename M, typename T = typename M::value_type>\n  T determinant(M\
    \ m){\n    const int N = m.size();\n\n    int s = 0;\n    for(int i = 0; i < N;\
    \ ++i){\n      if(m[i][i] == 0){\n        for(int j = i + 1; j < N; ++j){\n  \
    \        if(m[j][i] != 0){\n            m[i].swap(m[j]);\n            (s += 1)\
    \ %= 2;\n            break;\n          }\n          if(j == N - 1) return 0;\n\
    \        }\n      }\n\n      for(int j = i + 1; j < N; ++j){\n        T t = m[j][i]\
    \ / m[i][i];\n        for(int k = 0; k < N; ++k) m[j][k] -= m[i][k] * t;\n   \
    \   }\n    }\n\n    T ret = s ? -1 : 1;\n    for(int i = 0; i < N; ++i) ret *=\
    \ m[i][i];\n    return ret;\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\n\
    namespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 8 \"test/yosupo-judge/matrix_det/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nusing mint = hl::modint<998244353>;\n\nstatic int N;\nusing Mat = hl::square_matrix<mint,\
    \ N>;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  std::cin >> N;\n\n  Mat m(hl::input_vector<mint>(N, N));\n\n  std::cout <<\
    \ hl::determinant(m) << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include\
    \ <iostream>\n#include \"Mylib/Number/Mint/mint.cpp\"\n#include \"Mylib/LinearAlgebra/Square/square_matrix.cpp\"\
    \n#include \"Mylib/LinearAlgebra/Square/determinant.cpp\"\n#include \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing mint = hl::modint<998244353>;\n\nstatic\
    \ int N;\nusing Mat = hl::square_matrix<mint, N>;\n\nint main(){\n  std::cin.tie(0);\n\
    \  std::ios::sync_with_stdio(false);\n\n  std::cin >> N;\n\n  Mat m(hl::input_vector<mint>(N,\
    \ N));\n\n  std::cout << hl::determinant(m) << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Mint/mint.cpp
  - Mylib/LinearAlgebra/Square/square_matrix.cpp
  - Mylib/LinearAlgebra/Square/determinant.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/yosupo-judge/matrix_det/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-21 01:58:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/matrix_det/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/matrix_det/main.test.cpp
- /verify/test/yosupo-judge/matrix_det/main.test.cpp.html
title: test/yosupo-judge/matrix_det/main.test.cpp
---
