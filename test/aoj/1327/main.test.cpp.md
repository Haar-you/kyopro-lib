---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Number/Mint/runtime_mint.cpp
    title: Modint (Runtime mod)
  - icon: ':question:'
    path: Mylib/LinearAlgebra/Square/square_matrix.cpp
    title: Square matrix
  - icon: ':question:'
    path: Mylib/LinearAlgebra/Square/power.cpp
    title: Power of a matrix
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: Mylib/IO/join.cpp
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Mylib/IO/input_vector.cpp
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
    \ runtime_modint {\n    int64_t val;\n\n  public:\n    runtime_modint(): val(0){}\n\
    \    runtime_modint(int64_t n){\n      if(n >= M) val = n % M;\n      else if(n\
    \ < 0) val = n % M + M;\n      else val = n;\n    }\n\n    static auto mod(){return\
    \ M;}\n\n    auto operator+(const runtime_modint &a) const {return runtime_modint(val\
    \ + a.val);}\n    auto operator-(const runtime_modint &a) const {return runtime_modint(val\
    \ - a.val);}\n    auto operator*(const runtime_modint &a) const {return runtime_modint(val\
    \ * a.val);}\n    auto operator/(const runtime_modint &a) const {return runtime_modint(val\
    \ * a.inv().val);}\n\n    const auto& operator=(const runtime_modint &a){val =\
    \ a.val; return *this;}\n    const auto& operator+=(const runtime_modint &a){if((val\
    \ += a.val) >= M) val -= M; return *this;}\n    const auto& operator-=(const runtime_modint\
    \ &a){if(val < a.val) val += M; val -= a.val; return *this;}\n    const auto&\
    \ operator*=(const runtime_modint &a){(val *= a.val) %= M; return *this;}\n  \
    \  const auto& operator/=(const runtime_modint &a){(val *= a.inv().val) %= M;\
    \ return *this;}\n\n    bool operator==(const runtime_modint &a) const {return\
    \ val == a.val;}\n    bool operator!=(const runtime_modint &a) const {return val\
    \ != a.val;}\n\n    static auto pow(int64_t n, int64_t p){\n      runtime_modint\
    \ ret = 1, e = n;\n      for(; p; e *= e, p >>= 1) if(p & 1) ret *= e;\n     \
    \ return ret;\n    }\n\n    auto pow(int64_t p) const {\n      runtime_modint\
    \ ret = 1, e = val;\n      for(; p; e *= e, p >>= 1) if(p & 1) ret *= e;\n   \
    \   return ret;\n    }\n\n    runtime_modint inv() const {\n      int64_t a =\
    \ val, b = M, u = 1, v = 0;\n\n      while(b){\n        int64_t t = a / b;\n \
    \       a -= t * b; std::swap(a, b);\n        u -= t * v; std::swap(u, v);\n \
    \     }\n      u %= M;\n      if(u < 0) u += M;\n\n      return u;\n    }\n\n\
    \    explicit operator int32_t() const noexcept {return val;}\n    explicit operator\
    \ int64_t() const noexcept {return val;}\n\n    friend auto operator-(const runtime_modint\
    \ &a){return runtime_modint(-a.val);}\n\n    friend auto operator+(int64_t a,\
    \ const runtime_modint &b){return runtime_modint(a) + b;}\n    friend auto operator-(int64_t\
    \ a, const runtime_modint &b){return runtime_modint(a) - b;}\n    friend auto\
    \ operator*(int64_t a, const runtime_modint &b){return runtime_modint(a) * b;}\n\
    \    friend auto operator/(int64_t a, const runtime_modint &b){return runtime_modint(a)\
    \ / b;}\n\n    friend std::istream& operator>>(std::istream &is, runtime_modint\
    \ &a){is >> a.val; return is;}\n    friend std::ostream& operator<<(std::ostream\
    \ &os, const runtime_modint &a){os << a.val; return os;}\n  };\n}\n#line 4 \"\
    Mylib/LinearAlgebra/Square/square_matrix.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T, const int &N>\n  struct square_matrix {\n    using value_type =\
    \ T;\n\n    std::vector<std::vector<T>> matrix;\n\n    square_matrix(): matrix(N,\
    \ std::vector<T>(N)){}\n    square_matrix(const T &val): matrix(N, std::vector<T>(N,\
    \ val)){}\n    square_matrix(const std::vector<std::vector<T>> &matrix): matrix(matrix){}\n\
    \n    bool operator==(const square_matrix &val) const {return matrix == val.matrix;}\n\
    \    bool operator!=(const square_matrix &val) const {return !(*this == val);}\n\
    \n    auto& operator=(const square_matrix &val){\n      this->matrix = val.matrix;\n\
    \      return *this;\n    }\n\n    auto& operator+=(const square_matrix &val){\n\
    \      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j]\
    \ + val[i][j];\n      return *this;\n    }\n\n    auto& operator-=(const square_matrix\
    \ &val){\n      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j]\
    \ = matrix[i][j] - val[i][j];\n      return *this;\n    }\n\n    auto& operator*=(const\
    \ square_matrix &val){\n      std::vector<std::vector<T>> temp(N, std::vector<T>(N));\n\
    \      for(int i = 0; i < N; ++i)\n        for(int j = 0; j < N; ++j)\n      \
    \    for(int k = 0; k < N; ++k)\n            temp[i][j] = temp[i][j] + matrix[i][k]\
    \ * val[k][j];\n      std::swap(matrix, temp);\n      return *this;\n    }\n\n\
    \    const auto& operator[](size_t i) const {return matrix[i];}\n    auto& operator[](size_t\
    \ i){return matrix[i];}\n    int size() const {return N;}\n\n    static auto make_unit(){\n\
    \      square_matrix ret;\n      for(int i = 0; i < N; ++i) ret[i][i] = 1;\n \
    \     return ret;\n    }\n\n    friend auto operator+(const square_matrix &a,\
    \ const square_matrix &b){auto ret = a; ret += b; return ret;}\n    friend auto\
    \ operator-(const square_matrix &a, const square_matrix &b){auto ret = a; ret\
    \ -= b; return ret;}\n    friend auto operator*(const square_matrix &a, const\
    \ square_matrix &b){auto ret = a; ret *= b; return ret;}\n  };\n}\n#line 2 \"\
    Mylib/LinearAlgebra/Square/power.cpp\"\n#include <cstdint>\n\nnamespace haar_lib\
    \ {\n  template <typename M>\n  M power(M a, uint64_t p){\n    if(p == 0) return\
    \ M::make_unit();\n    if(p == 1) return a;\n\n    M temp = power(a, p >> 1);\n\
    \    auto ret = temp * temp;\n\n    if(p & 1) ret *= a;\n\n    return ret;\n \
    \ }\n}\n#line 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n#include <string>\n\
    \nnamespace haar_lib {\n  template <typename Iter>\n  std::string join(Iter first,\
    \ Iter last, std::string delim = \" \"){\n    std::stringstream s;\n\n    for(auto\
    \ it = first; it != last; ++it){\n      if(it != first) s << delim;\n      s <<\
    \ *it;\n    }\n\n    return s.str();\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 10 \"test/aoj/1327/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nstatic int\
    \ n, m;\nusing mint = hl::runtime_modint<m>;\nusing M = hl::square_matrix<mint,\
    \ n>;\n\nint main(){\n  int a, b, c, t;\n\n  while(std::cin >> n >> m >> a >>\
    \ b >> c >> t, n){\n    auto s = hl::input_vector<mint>(n);\n\n    M mat;\n\n\
    \    for(int i = 0; i < n; ++i){\n      if(i - 1 >= 0) mat[i][i - 1] = a;\n  \
    \    mat[i][i] = b;\n      if(i + 1 < n) mat[i][i + 1] = c;\n    }\n\n    mat\
    \ = hl::power(mat, t);\n\n    std::vector<mint> ans(n);\n\n    for(int i = 0;\
    \ i < n; ++i){\n      for(int j = 0; j < n; ++j){\n        ans[i] += mat[i][j]\
    \ * s[j];\n      }\n    }\n\n    std::cout << hl::join(ans.begin(), ans.end())\
    \ << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1327\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Number/Mint/runtime_mint.cpp\"\
    \n#include \"Mylib/LinearAlgebra/Square/square_matrix.cpp\"\n#include \"Mylib/LinearAlgebra/Square/power.cpp\"\
    \n#include \"Mylib/IO/join.cpp\"\n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nstatic int n, m;\nusing mint = hl::runtime_modint<m>;\nusing\
    \ M = hl::square_matrix<mint, n>;\n\nint main(){\n  int a, b, c, t;\n\n  while(std::cin\
    \ >> n >> m >> a >> b >> c >> t, n){\n    auto s = hl::input_vector<mint>(n);\n\
    \n    M mat;\n\n    for(int i = 0; i < n; ++i){\n      if(i - 1 >= 0) mat[i][i\
    \ - 1] = a;\n      mat[i][i] = b;\n      if(i + 1 < n) mat[i][i + 1] = c;\n  \
    \  }\n\n    mat = hl::power(mat, t);\n\n    std::vector<mint> ans(n);\n\n    for(int\
    \ i = 0; i < n; ++i){\n      for(int j = 0; j < n; ++j){\n        ans[i] += mat[i][j]\
    \ * s[j];\n      }\n    }\n\n    std::cout << hl::join(ans.begin(), ans.end())\
    \ << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Mint/runtime_mint.cpp
  - Mylib/LinearAlgebra/Square/square_matrix.cpp
  - Mylib/LinearAlgebra/Square/power.cpp
  - Mylib/IO/join.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/1327/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-17 22:58:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/1327/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/1327/main.test.cpp
- /verify/test/aoj/1327/main.test.cpp.html
title: test/aoj/1327/main.test.cpp
---
