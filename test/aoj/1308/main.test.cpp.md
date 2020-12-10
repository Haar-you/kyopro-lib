---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':heavy_check_mark:'
    path: Mylib/LinearAlgebra/simultaneous_linear_equations_binary.cpp
    title: Simultaneous linear equations (Mod2)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308
  bundledCode: "#line 1 \"test/aoj/1308/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308\"\
    \n\n#include <iostream>\n#include <vector>\n#include <bitset>\n#line 3 \"Mylib/LinearAlgebra/simultaneous_linear_equations_binary.cpp\"\
    \n#include <optional>\n#include <utility>\n#line 6 \"Mylib/LinearAlgebra/simultaneous_linear_equations_binary.cpp\"\
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
    \ N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line 8 \"test/aoj/1308/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int m, n, d;\n  while(std::cin >> m >> n >> d, m){\n    auto s = hl::input_vector<int>(n,\
    \ m);\n\n    auto a = std::vector(n * m, std::bitset<25 * 25>());\n    std::vector<bool>\
    \ b(n * m);\n\n    std::vector<std::vector<int>> p(n, std::vector<int>(m));\n\
    \    for(int i = 0; i < n; ++i){\n      for(int j = 0; j < m; ++j){\n        p[i][j]\
    \ = j + i * m;\n      }\n    }\n\n    for(int i = 0; i < n; ++i){\n      for(int\
    \ j = 0; j < m; ++j){\n        b[p[i][j]] = s[i][j];\n      }\n    }\n\n    for(int\
    \ i = 0; i < n; ++i){\n      for(int j = 0; j < m; ++j){\n        a[p[i][j]][p[i][j]]\
    \ = 1;\n\n        for(int x = 0; x < n; ++x){\n          for(int y = 0; y < m;\
    \ ++y){\n            if(abs(i - x) + abs(j - y) == d){\n              a[p[x][y]][p[i][j]]\
    \ = 1;\n            }\n          }\n        }\n      }\n    }\n\n    std::cout\
    \ << (bool)(hl::binary_simultaneous_linear_equations(a, b)) << std::endl;\n  }\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308\"\
    \n\n#include <iostream>\n#include <vector>\n#include <bitset>\n#include \"Mylib/LinearAlgebra/simultaneous_linear_equations_binary.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int m, n, d;\n \
    \ while(std::cin >> m >> n >> d, m){\n    auto s = hl::input_vector<int>(n, m);\n\
    \n    auto a = std::vector(n * m, std::bitset<25 * 25>());\n    std::vector<bool>\
    \ b(n * m);\n\n    std::vector<std::vector<int>> p(n, std::vector<int>(m));\n\
    \    for(int i = 0; i < n; ++i){\n      for(int j = 0; j < m; ++j){\n        p[i][j]\
    \ = j + i * m;\n      }\n    }\n\n    for(int i = 0; i < n; ++i){\n      for(int\
    \ j = 0; j < m; ++j){\n        b[p[i][j]] = s[i][j];\n      }\n    }\n\n    for(int\
    \ i = 0; i < n; ++i){\n      for(int j = 0; j < m; ++j){\n        a[p[i][j]][p[i][j]]\
    \ = 1;\n\n        for(int x = 0; x < n; ++x){\n          for(int y = 0; y < m;\
    \ ++y){\n            if(abs(i - x) + abs(j - y) == d){\n              a[p[x][y]][p[i][j]]\
    \ = 1;\n            }\n          }\n        }\n      }\n    }\n\n    std::cout\
    \ << (bool)(hl::binary_simultaneous_linear_equations(a, b)) << std::endl;\n  }\n\
    \n  return 0;\n}\n"
  dependsOn:
  - Mylib/LinearAlgebra/simultaneous_linear_equations_binary.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/1308/main.test.cpp
  requiredBy: []
  timestamp: '2020-12-09 11:11:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/1308/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/1308/main.test.cpp
- /verify/test/aoj/1308/main.test.cpp.html
title: test/aoj/1308/main.test.cpp
---
