---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: join function
  - icon: ':question:'
    path: Mylib/LinearAlgebra/square_matrix.cpp
    title: Square matrix
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Mint/runtime_mint.cpp
    title: Modint (Runtime mod)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1327
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1327
  bundledCode: "#line 1 \"test/aoj/1327/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1327\"\
    \n\n#include <iostream>\n#include <vector>\n#line 3 \"Mylib/Number/Mint/runtime_mint.cpp\"\
    \n#include <utility>\n\nnamespace haar_lib {\n  template <const int &M>\n  class\
    \ runtime_modint {\n    int64_t val_;\n\n  public:\n    runtime_modint(): val_(0){}\n\
    \    runtime_modint(int64_t n){\n      if(n >= M) val_ = n % M;\n      else if(n\
    \ < 0) val_ = n % M + M;\n      else val_ = n;\n    }\n\n    static auto mod(){return\
    \ M;}\n\n    auto operator+(const runtime_modint &a) const {return runtime_modint(val_\
    \ + a.val_);}\n    auto operator-(const runtime_modint &a) const {return runtime_modint(val_\
    \ - a.val_);}\n    auto operator*(const runtime_modint &a) const {return runtime_modint(val_\
    \ * a.val_);}\n    auto operator/(const runtime_modint &a) const {return runtime_modint(val_\
    \ * a.inv().val_);}\n\n    const auto& operator=(const runtime_modint &a){val_\
    \ = a.val_; return *this;}\n    const auto& operator+=(const runtime_modint &a){if((val_\
    \ += a.val_) >= M) val_ -= M; return *this;}\n    const auto& operator-=(const\
    \ runtime_modint &a){if(val_ < a.val_) val_ += M; val_ -= a.val_; return *this;}\n\
    \    const auto& operator*=(const runtime_modint &a){(val_ *= a.val_) %= M; return\
    \ *this;}\n    const auto& operator/=(const runtime_modint &a){(val_ *= a.inv().val_)\
    \ %= M; return *this;}\n\n    bool operator==(const runtime_modint &a) const {return\
    \ val_ == a.val_;}\n    bool operator!=(const runtime_modint &a) const {return\
    \ val_ != a.val_;}\n\n    static auto pow(int64_t n, int64_t p){\n      runtime_modint\
    \ ret = 1, e = n;\n      for(; p; e *= e, p >>= 1) if(p & 1) ret *= e;\n     \
    \ return ret;\n    }\n\n    auto pow(int64_t p) const {\n      runtime_modint\
    \ ret = 1, e = val_;\n      for(; p; e *= e, p >>= 1) if(p & 1) ret *= e;\n  \
    \    return ret;\n    }\n\n    runtime_modint inv() const {\n      int64_t a =\
    \ val_, b = M, u = 1, v = 0;\n\n      while(b){\n        int64_t t = a / b;\n\
    \        a -= t * b; std::swap(a, b);\n        u -= t * v; std::swap(u, v);\n\
    \      }\n      u %= M;\n      if(u < 0) u += M;\n\n      return u;\n    }\n\n\
    \    explicit operator int32_t() const noexcept {return val_;}\n    explicit operator\
    \ int64_t() const noexcept {return val_;}\n\n    friend auto operator-(const runtime_modint\
    \ &a){return runtime_modint(-a.val_);}\n\n    friend auto operator+(int64_t a,\
    \ const runtime_modint &b){return runtime_modint(a) + b;}\n    friend auto operator-(int64_t\
    \ a, const runtime_modint &b){return runtime_modint(a) - b;}\n    friend auto\
    \ operator*(int64_t a, const runtime_modint &b){return runtime_modint(a) * b;}\n\
    \    friend auto operator/(int64_t a, const runtime_modint &b){return runtime_modint(a)\
    \ / b;}\n\n    friend std::istream& operator>>(std::istream &is, runtime_modint\
    \ &a){is >> a.val_; return is;}\n    friend std::ostream& operator<<(std::ostream\
    \ &os, const runtime_modint &a){os << a.val_; return os;}\n  };\n}\n#line 4 \"\
    Mylib/LinearAlgebra/square_matrix.cpp\"\n#include <cstdint>\n#line 6 \"Mylib/LinearAlgebra/square_matrix.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, int &N>\n  class vector_dyn\
    \ {\n  public:\n    using value_type = T;\n\n  private:\n    std::vector<T> data_;\n\
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
    \ that);\n      return ret;\n    }\n  };\n}\n#line 3 \"Mylib/IO/join.cpp\"\n#include\
    \ <sstream>\n#include <string>\n\nnamespace haar_lib {\n  template <typename Iter>\n\
    \  std::string join(Iter first, Iter last, std::string delim = \" \"){\n    std::stringstream\
    \ s;\n\n    for(auto it = first; it != last; ++it){\n      if(it != first) s <<\
    \ delim;\n      s << *it;\n    }\n\n    return s.str();\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 9 \"test/aoj/1327/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nstatic int\
    \ n, m;\nusing mint = hl::runtime_modint<m>;\nusing M = hl::square_matrix_dyn<mint,\
    \ n>;\n\nint main(){\n  int a, b, c, t;\n\n  while(std::cin >> n >> m >> a >>\
    \ b >> c >> t, n){\n    auto s = hl::input_vector<mint>(n);\n\n    M mat;\n\n\
    \    for(int i = 0; i < n; ++i){\n      if(i - 1 >= 0) mat[i][i - 1] = a;\n  \
    \    mat[i][i] = b;\n      if(i + 1 < n) mat[i][i + 1] = c;\n    }\n\n    mat\
    \ = mat.pow(t);\n\n    auto ans = mat * M::vector_type(s);\n\n    std::cout <<\
    \ hl::join(ans.begin(), ans.end()) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1327\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Number/Mint/runtime_mint.cpp\"\
    \n#include \"Mylib/LinearAlgebra/square_matrix.cpp\"\n#include \"Mylib/IO/join.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nstatic\
    \ int n, m;\nusing mint = hl::runtime_modint<m>;\nusing M = hl::square_matrix_dyn<mint,\
    \ n>;\n\nint main(){\n  int a, b, c, t;\n\n  while(std::cin >> n >> m >> a >>\
    \ b >> c >> t, n){\n    auto s = hl::input_vector<mint>(n);\n\n    M mat;\n\n\
    \    for(int i = 0; i < n; ++i){\n      if(i - 1 >= 0) mat[i][i - 1] = a;\n  \
    \    mat[i][i] = b;\n      if(i + 1 < n) mat[i][i + 1] = c;\n    }\n\n    mat\
    \ = mat.pow(t);\n\n    auto ans = mat * M::vector_type(s);\n\n    std::cout <<\
    \ hl::join(ans.begin(), ans.end()) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Mint/runtime_mint.cpp
  - Mylib/LinearAlgebra/square_matrix.cpp
  - Mylib/IO/join.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/1327/main.test.cpp
  requiredBy: []
  timestamp: '2020-12-09 11:11:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/1327/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/1327/main.test.cpp
- /verify/test/aoj/1327/main.test.cpp.html
title: test/aoj/1327/main.test.cpp
---
