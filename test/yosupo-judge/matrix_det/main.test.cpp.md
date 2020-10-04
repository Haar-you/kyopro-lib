---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':x:'
    path: Mylib/LinearAlgebra/Square/determinant.cpp
    title: Determinant
  - icon: ':question:'
    path: Mylib/LinearAlgebra/Square/square_matrix.cpp
    title: Square matrix
  - icon: ':x:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
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
    \  template <int32_t M>\n  class modint {\n    uint32_t val_;\n\n  public:\n \
    \   constexpr static auto mod(){return M;}\n\n    constexpr modint(): val_(0){}\n\
    \    constexpr modint(int64_t n){\n      if(n >= M) val_ = n % M;\n      else\
    \ if(n < 0) val_ = n % M + M;\n      else val_ = n;\n    }\n\n    constexpr auto&\
    \ operator=(const modint &a){val_ = a.val_; return *this;}\n    constexpr auto&\
    \ operator+=(const modint &a){\n      if(val_ + a.val_ >= M) val_ = (uint64_t)val_\
    \ + a.val_ - M;\n      else val_ += a.val_;\n      return *this;\n    }\n    constexpr\
    \ auto& operator-=(const modint &a){\n      if(val_ < a.val_) val_ += M;\n   \
    \   val_ -= a.val_;\n      return *this;\n    }\n    constexpr auto& operator*=(const\
    \ modint &a){\n      val_ = (uint64_t)val_ * a.val_ % M;\n      return *this;\n\
    \    }\n    constexpr auto& operator/=(const modint &a){\n      val_ = (uint64_t)val_\
    \ * a.inv().val_ % M;\n      return *this;\n    }\n\n    constexpr auto operator+(const\
    \ modint &a) const {return modint(*this) += a;}\n    constexpr auto operator-(const\
    \ modint &a) const {return modint(*this) -= a;}\n    constexpr auto operator*(const\
    \ modint &a) const {return modint(*this) *= a;}\n    constexpr auto operator/(const\
    \ modint &a) const {return modint(*this) /= a;}\n\n    constexpr bool operator==(const\
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
    \ operator int64_t() const noexcept {return val_;}\n  };\n}\n#line 2 \"Mylib/LinearAlgebra/Square/square_matrix.cpp\"\
    \n#include <vector>\n#line 4 \"Mylib/LinearAlgebra/Square/square_matrix.cpp\"\n\
    #include <cstdint>\n#line 6 \"Mylib/LinearAlgebra/Square/square_matrix.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename T, int &N>\n  class vector_dyn {\n\
    \  public:\n    using value_type = T;\n\n  private:\n    std::vector<T> data_;\n\
    \n  public:\n    vector_dyn(): data_(N){}\n    vector_dyn(T value): data_(N, value){}\n\
    \    vector_dyn(std::initializer_list<T> list): data_(N){\n      int i = 0;\n\
    \      for(auto it = list.begin(); it != list.end(); ++it) data_[i++] = *it;\n\
    \    }\n    vector_dyn(const vector_dyn &that): data_(that.data_){}\n\n    template\
    \ <typename U>\n    vector_dyn(const std::vector<U> &that): data_(that.begin(),\
    \ that.end()){}\n\n    bool operator==(const vector_dyn &that){return data_ ==\
    \ that.data_;}\n    bool operator!=(const vector_dyn &that){return !(*this ==\
    \ that);}\n\n    auto& operator=(const vector_dyn &that){\n      data_ = that.data_;\n\
    \      return *this;\n    }\n\n    auto& operator+=(const vector_dyn &that){\n\
    \      for(int i = 0; i < N; ++i) data_[i] += that.data_[i];\n      return *this;\n\
    \    }\n\n    auto& operator-=(const vector_dyn &that){\n      for(int i = 0;\
    \ i < N; ++i) data_[i] -= that.data_[i];\n      return *this;\n    }\n\n    friend\
    \ auto dot(const vector_dyn &a, const vector_dyn &b){\n      T ret = 0;\n    \
    \  for(int i = 0; i < N; ++i) ret += a.data_[i] * b.data_[i];\n      return ret;\n\
    \    }\n\n    auto operator+(const vector_dyn &that) const {\n      return vector(*this)\
    \ += that;\n    }\n\n    auto operator-(const vector_dyn &that) const {\n    \
    \  return vector(*this) -= that;\n    }\n\n    auto& operator[](int i){return\
    \ data_[i];}\n    const auto& operator[](int i) const {return data_[i];}\n   \
    \ auto begin() const {return data_.begin();}\n    auto end() const {return data_.end();}\n\
    \n    int size() const {return N;}\n\n    friend std::ostream& operator<<(std::ostream\
    \ &s, const vector_dyn &a){\n      s << \"{\";\n      for(auto it = a.data_.begin();\
    \ it != a.data_.end(); ++it){\n        if(it != a.data_.begin()) s << \",\";\n\
    \        s << *it;\n      }\n      s << \"}\";\n      return s;\n    }\n  };\n\
    \n\n  template <typename T, int &N>\n  class square_matrix_dyn {\n  public:\n\
    \    using value_type = T;\n    using vector_type = vector_dyn<T, N>;\n\n  private:\n\
    \    std::vector<vector_type> data_;\n\n  public:\n    square_matrix_dyn(): data_(N,\
    \ vector_type()){}\n    square_matrix_dyn(const T &val): data_(N, vector_type(val)){}\n\
    \    square_matrix_dyn(std::initializer_list<std::initializer_list<T>> list):\
    \ data_(N){\n      int i = 0;\n      for(auto it = list.begin(); it != list.end();\
    \ ++it){\n        data_[i++] = vector_type(*it);\n      }\n    }\n    square_matrix_dyn(const\
    \ square_matrix_dyn &that): data_(that.data_){}\n    square_matrix_dyn(const std::vector<std::vector<T>>\
    \ &that): data_(N){\n      for(int i = 0; i < N; ++i) data_[i] = that[i];\n  \
    \  }\n\n    bool operator==(const square_matrix_dyn &that) const {return data_\
    \ == that.data_;}\n    bool operator!=(const square_matrix_dyn &that) const {return\
    \ !(*this == that);}\n\n    auto& operator=(const square_matrix_dyn &that){\n\
    \      data_ = that.data_;\n      return *this;\n    }\n\n    auto& operator+=(const\
    \ square_matrix_dyn &that){\n      for(int i = 0; i < N; ++i) data_[i] += that.data_[i];\n\
    \      return *this;\n    }\n\n    auto& operator-=(const square_matrix_dyn &that){\n\
    \      for(int i = 0; i < N; ++i) data_[i] -= that.data_[i];\n      return *this;\n\
    \    }\n\n    auto& operator*=(const square_matrix_dyn &that){\n      square_matrix_dyn\
    \ ret;\n      for(int i = 0; i < N; ++i)\n        for(int j = 0; j < N; ++j)\n\
    \          for(int k = 0; k < N; ++k)\n            ret[i][j] += data_[i][k] *\
    \ that.data_[k][j];\n      return *this = ret;\n    }\n\n    const auto& operator[](int\
    \ i) const {return data_[i];}\n    auto& operator[](int i){return data_[i];}\n\
    \    int size() const {return N;}\n\n    static auto unit(){\n      square_matrix_dyn\
    \ ret;\n      for(int i = 0; i < N; ++i) ret[i][i] = 1;\n      return ret;\n \
    \   }\n\n    auto operator+(const square_matrix_dyn &that){\n      return square_matrix_dyn(*this)\
    \ += that;\n    }\n    auto operator-(const square_matrix_dyn &that){\n      return\
    \ square_matrix_dyn(*this) -= that;\n    }\n    auto operator*(const square_matrix_dyn\
    \ &that){\n      return square_matrix_dyn(*this) *= that;\n    }\n\n    auto pow(uint64_t\
    \ p) const {\n      auto ret = unit();\n      auto a = *this;\n\n      while(p\
    \ > 0){\n        if(p & 1) ret *= a;\n        a *= a;\n        p >>= 1;\n    \
    \  }\n\n      return ret;\n    }\n\n    auto operator*(const vector_type &that){\n\
    \      vector_type ret;\n      for(int i = 0; i < N; ++i) ret[i] = dot(data_[i],\
    \ that);\n      return ret;\n    }\n  };\n}\n#line 3 \"Mylib/LinearAlgebra/Square/determinant.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename M, typename T = typename M::value_type>\n\
    \  T determinant(M m){\n    const int N = m.size();\n\n    int s = 0;\n    for(int\
    \ i = 0; i < N; ++i){\n      if(m[i][i] == 0){\n        for(int j = i + 1; j <\
    \ N; ++j){\n          if(m[j][i] != 0){\n            std::swap(m[i], m[j]);\n\
    \            (s += 1) %= 2;\n            break;\n          }\n          if(j ==\
    \ N - 1) return 0;\n        }\n      }\n\n      for(int j = i + 1; j < N; ++j){\n\
    \        T t = m[j][i] / m[i][i];\n        for(int k = 0; k < N; ++k) m[j][k]\
    \ -= m[i][k] * t;\n      }\n    }\n\n    T ret = s ? -1 : 1;\n    for(int i =\
    \ 0; i < N; ++i) ret *= m[i][i];\n    return ret;\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 8 \"test/yosupo-judge/matrix_det/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nusing mint = hl::modint<998244353>;\n\nstatic int N;\nusing Mat = hl::square_matrix_dyn<mint,\
    \ N>;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  std::cin >> N;\n\n  Mat m(hl::input_vector<mint>(N, N));\n\n  std::cout <<\
    \ hl::determinant(m) << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include\
    \ <iostream>\n#include \"Mylib/Number/Mint/mint.cpp\"\n#include \"Mylib/LinearAlgebra/Square/square_matrix.cpp\"\
    \n#include \"Mylib/LinearAlgebra/Square/determinant.cpp\"\n#include \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing mint = hl::modint<998244353>;\n\nstatic\
    \ int N;\nusing Mat = hl::square_matrix_dyn<mint, N>;\n\nint main(){\n  std::cin.tie(0);\n\
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
  timestamp: '2020-09-30 07:57:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/matrix_det/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/matrix_det/main.test.cpp
- /verify/test/yosupo-judge/matrix_det/main.test.cpp.html
title: test/yosupo-judge/matrix_det/main.test.cpp
---
