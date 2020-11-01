---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':heavy_check_mark:'
    path: Mylib/LinearAlgebra/SimultaneousLinearEquations/binary_simultaneous_linear_equations.cpp
    title: Simultaneous linear equations (Mod2)
  - icon: ':question:'
    path: Mylib/Number/Mod/mod_pow.cpp
    title: Mod pow
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2530
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2530
  bundledCode: "#line 1 \"test/aoj/2530/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2530\"\
    \n\n#include <iostream>\n#include <vector>\n#include <bitset>\n#line 2 \"Mylib/Number/Mod/mod_pow.cpp\"\
    \n#include <cstdint>\n\nnamespace haar_lib {\n  constexpr int64_t mod_pow(int64_t\
    \ n, int64_t p, int64_t m){\n    int64_t ret = 1;\n    while(p > 0){\n      if(p\
    \ & 1) (ret *= n) %= m;\n      (n *= n) %= m;\n      p >>= 1;\n    }\n    return\
    \ ret;\n  }\n}\n#line 3 \"Mylib/LinearAlgebra/SimultaneousLinearEquations/binary_simultaneous_linear_equations.cpp\"\
    \n#include <optional>\n#include <utility>\n#line 6 \"Mylib/LinearAlgebra/SimultaneousLinearEquations/binary_simultaneous_linear_equations.cpp\"\
    \n\nnamespace haar_lib {\n  namespace binary_simultaneous_linear_equations_impl\
    \ {\n    template <size_t N>\n    struct result {\n      int rank, dim;\n    \
    \  std::vector<bool> solution;\n    };\n  }\n\n  template <size_t N>\n  auto binary_simultaneous_linear_equations(std::vector<std::bitset<N>>\
    \ a, std::vector<bool> b){\n    using result = binary_simultaneous_linear_equations_impl::result<N>;\n\
    \    std::optional<result> ret;\n\n    const int n = a.size(), m = N;\n    int\
    \ rank = 0;\n\n    for(int j = 0; j < m; ++j){\n      int pivot = -1;\n      for(int\
    \ i = rank; i < n; ++i){\n        if(a[i][j]){\n          pivot = i;\n       \
    \   break;\n        }\n      }\n\n      if(pivot == -1) continue;\n      std::swap(a[pivot],\
    \ a[rank]);\n      swap(b[pivot], b[rank]);\n\n      for(int i = 0; i < n; ++i){\n\
    \        if(i != rank and a[i][j]){\n          a[i] ^= a[rank];\n          b[i]\
    \ = b[i] ^ b[rank];\n        }\n      }\n\n      ++rank;\n    }\n\n    for(int\
    \ i = rank; i < n; ++i){\n      if(b[i]){\n        return ret;\n      }\n    }\n\
    \n    const int dim = m - rank;\n\n    std::vector<bool> solution(m);\n    for(int\
    \ i = 0; i < rank; ++i) solution[i] = b[i];\n\n    ret = result({rank, dim, solution});\n\
    \    return ret;\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  std::vector<T> input_vector(int N){\n    std::vector<T>\
    \ ret(N);\n    for(int i = 0; i < N; ++i) std::cin >> ret[i];\n    return ret;\n\
    \  }\n\n  template <typename T>\n  std::vector<std::vector<T>> input_vector(int\
    \ N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int i = 0; i <\
    \ N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line 9 \"test/aoj/2530/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nconstexpr int64_t mod = 1000000009;\nusing B =\
    \ std::bitset<2500>;\n\nint main(){\n  int R, C; std::cin >> R >> C;\n\n  auto\
    \ f = hl::input_vector<int>(R, C);\n\n  std::vector<std::vector<int>> index(R,\
    \ std::vector<int>(C));\n  {\n    int c = 0;\n    for(int i = 0; i < R; ++i){\n\
    \      for(int j = 0; j < C; ++j){\n        index[i][j] = c;\n        ++c;\n \
    \     }\n    }\n  }\n\n  std::vector<B> a(R * C);\n  std::vector<bool> b(R * C);\n\
    \n  for(int i = 0; i < R; ++i){\n    for(int j = 0; j < C; ++j){\n      b[index[i][j]]\
    \ = f[i][j];\n\n      for(int p = 0; p < R; ++p){\n        for(int q = 0; q <\
    \ C; ++q){\n          if(abs(i - p) == abs(j - q) or i == p or j == q){\n    \
    \        a[index[p][q]][index[i][j]] = true;\n          }\n        }\n      }\n\
    \    }\n  }\n\n  auto res = hl::binary_simultaneous_linear_equations(a, b);\n\n\
    \  int64_t ans = 0;\n  if(res){\n    ans = hl::mod_pow(2, R * C - (*res).rank,\
    \ mod);\n  }\n\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2530\"\
    \n\n#include <iostream>\n#include <vector>\n#include <bitset>\n#include \"Mylib/Number/Mod/mod_pow.cpp\"\
    \n#include \"Mylib/LinearAlgebra/SimultaneousLinearEquations/binary_simultaneous_linear_equations.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nconstexpr\
    \ int64_t mod = 1000000009;\nusing B = std::bitset<2500>;\n\nint main(){\n  int\
    \ R, C; std::cin >> R >> C;\n\n  auto f = hl::input_vector<int>(R, C);\n\n  std::vector<std::vector<int>>\
    \ index(R, std::vector<int>(C));\n  {\n    int c = 0;\n    for(int i = 0; i <\
    \ R; ++i){\n      for(int j = 0; j < C; ++j){\n        index[i][j] = c;\n    \
    \    ++c;\n      }\n    }\n  }\n\n  std::vector<B> a(R * C);\n  std::vector<bool>\
    \ b(R * C);\n\n  for(int i = 0; i < R; ++i){\n    for(int j = 0; j < C; ++j){\n\
    \      b[index[i][j]] = f[i][j];\n\n      for(int p = 0; p < R; ++p){\n      \
    \  for(int q = 0; q < C; ++q){\n          if(abs(i - p) == abs(j - q) or i ==\
    \ p or j == q){\n            a[index[p][q]][index[i][j]] = true;\n          }\n\
    \        }\n      }\n    }\n  }\n\n  auto res = hl::binary_simultaneous_linear_equations(a,\
    \ b);\n\n  int64_t ans = 0;\n  if(res){\n    ans = hl::mod_pow(2, R * C - (*res).rank,\
    \ mod);\n  }\n\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Mod/mod_pow.cpp
  - Mylib/LinearAlgebra/SimultaneousLinearEquations/binary_simultaneous_linear_equations.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/2530/main.test.cpp
  requiredBy: []
  timestamp: '2020-10-28 03:22:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/2530/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2530/main.test.cpp
- /verify/test/aoj/2530/main.test.cpp.html
title: test/aoj/2530/main.test.cpp
---
