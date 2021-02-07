---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Convolution/fast_zeta_transform_subset.cpp
    title: Fast Zeta transform (Subsets)
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3134
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3134
  bundledCode: "#line 1 \"test/aoj/3134/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3134\"\
    \n\n#include <iostream>\n#include <vector>\n#include <functional>\n#include <algorithm>\n\
    #line 4 \"Mylib/Convolution/fast_zeta_transform_subset.cpp\"\n#include <cassert>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Func = std::plus<T>>\n\
    \  std::vector<T> fast_zeta_transform_subset(std::vector<T> f, const Func &op\
    \ = std::plus<T>()){\n    const int N = f.size();\n    assert((N & (N - 1)) ==\
    \ 0 && \"N must be a power of 2\");\n    for(int i = 1; i < N; i <<= 1){\n   \
    \   for(int j = 0; j < N; ++j){\n        if(j & i) f[j] = op(f[j], f[j ^ i]);\n\
    \      }\n    }\n    return f;\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 9 \"test/aoj/3134/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int N, K; std::cin >> N >> K;\n\n  auto A = hl::input_vector<int>(N);\n\n \
    \ std::vector<int> sum(1 << N);\n\n  for(int i = 0; i < 1 << N; ++i){\n    for(int\
    \ j = 0; j < N; ++j){\n      if(not (i & (1 << j))){\n        sum[i | (1 << j)]\
    \ = sum[i] + A[j];\n      }\n    }\n  }\n\n  std::vector<int> f(1 << N);\n  for(int\
    \ i = 0; i < 1 << N; ++i){\n    if(sum[i] == K) f[i] = true;\n  }\n\n  f = hl::fast_zeta_transform_subset(f,\
    \ std::logical_or<bool>());\n\n  int ans = N;\n\n  for(int i = 0; i < 1 << N;\
    \ ++i){\n    if(not f[i]){\n      ans = std::min(ans, N - __builtin_popcount(i));\n\
    \    }\n  }\n\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3134\"\
    \n\n#include <iostream>\n#include <vector>\n#include <functional>\n#include <algorithm>\n\
    #include \"Mylib/Convolution/fast_zeta_transform_subset.cpp\"\n#include \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int N, K; std::cin >> N >> K;\n\
    \n  auto A = hl::input_vector<int>(N);\n\n  std::vector<int> sum(1 << N);\n\n\
    \  for(int i = 0; i < 1 << N; ++i){\n    for(int j = 0; j < N; ++j){\n      if(not\
    \ (i & (1 << j))){\n        sum[i | (1 << j)] = sum[i] + A[j];\n      }\n    }\n\
    \  }\n\n  std::vector<int> f(1 << N);\n  for(int i = 0; i < 1 << N; ++i){\n  \
    \  if(sum[i] == K) f[i] = true;\n  }\n\n  f = hl::fast_zeta_transform_subset(f,\
    \ std::logical_or<bool>());\n\n  int ans = N;\n\n  for(int i = 0; i < 1 << N;\
    \ ++i){\n    if(not f[i]){\n      ans = std::min(ans, N - __builtin_popcount(i));\n\
    \    }\n  }\n\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Convolution/fast_zeta_transform_subset.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/3134/main.test.cpp
  requiredBy: []
  timestamp: '2020-10-30 23:28:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/3134/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/3134/main.test.cpp
- /verify/test/aoj/3134/main.test.cpp.html
title: test/aoj/3134/main.test.cpp
---
