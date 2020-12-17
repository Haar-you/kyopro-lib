---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':heavy_check_mark:'
    path: Mylib/LinearAlgebra/gaussian_elimination_binary.cpp
    title: Gaussian elimination (Mod2)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/184
    links:
    - https://yukicoder.me/problems/no/184
  bundledCode: "#line 1 \"test/yukicoder/184/main.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/184\"\
    \n\n#include <iostream>\n#include <bitset>\n#include <vector>\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 4 \"Mylib/LinearAlgebra/gaussian_elimination_binary.cpp\"\n#include <utility>\n\
    \nnamespace haar_lib {\n  template <size_t N>\n  int gaussian_elimination(std::vector<std::bitset<N>>\
    \ &m){\n    const int n = m.size();\n    int rank = 0;\n\n    for(size_t j = 0;\
    \ j < N; ++j){\n      int pivot = -1;\n\n      for(int i = rank; i < n; ++i){\n\
    \        if(m[i][j]){\n          pivot = i;\n          break;\n        }\n   \
    \   }\n\n      if(pivot == -1) continue;\n\n      std::swap(m[pivot], m[rank]);\n\
    \n      for(int i = 0; i < n; ++i){\n        if(i != rank and m[i][j]) m[i] ^=\
    \ m[rank];\n      }\n      ++rank;\n    }\n\n    return rank;\n  }\n\n  template\
    \ <size_t N>\n  int gaussian_elimination(std::vector<std::bitset<N>> &&m){\n \
    \   return gaussian_elimination(m);\n  }\n}\n#line 8 \"test/yukicoder/184/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int n; std::cin >> n;\n  auto a\
    \ = hl::input_vector<int64_t>(n);\n\n  int rank = hl::gaussian_elimination(std::vector<std::bitset<64>>(a.begin(),\
    \ a.end()));\n\n  std::cout << (1LL << rank) << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/184\"\n\n#include <iostream>\n\
    #include <bitset>\n#include <vector>\n#include \"Mylib/IO/input_vector.cpp\"\n\
    #include \"Mylib/LinearAlgebra/gaussian_elimination_binary.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  int n; std::cin >> n;\n  auto a = hl::input_vector<int64_t>(n);\n\
    \n  int rank = hl::gaussian_elimination(std::vector<std::bitset<64>>(a.begin(),\
    \ a.end()));\n\n  std::cout << (1LL << rank) << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_vector.cpp
  - Mylib/LinearAlgebra/gaussian_elimination_binary.cpp
  isVerificationFile: true
  path: test/yukicoder/184/main.test.cpp
  requiredBy: []
  timestamp: '2020-12-09 11:11:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/184/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/184/main.test.cpp
- /verify/test/yukicoder/184/main.test.cpp.html
title: test/yukicoder/184/main.test.cpp
---
