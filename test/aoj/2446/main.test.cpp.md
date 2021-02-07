---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Convolution/fast_mobius_transform_subset.cpp
    title: "Fast M\xF6bius transform (Subsets)"
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
    ERROR: 1e-7
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446
  bundledCode: "#line 1 \"test/aoj/2446/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446\"\
    \n#define ERROR 1e-7\n\n#include <iostream>\n#include <iomanip>\n#include <vector>\n\
    #include <numeric>\n#line 3 \"Mylib/Convolution/fast_mobius_transform_subset.cpp\"\
    \n#include <functional>\n#include <cassert>\n\nnamespace haar_lib {\n  template\
    \ <typename T, typename Func = std::minus<T>>\n  std::vector<T> fast_mobius_transform_subset(std::vector<T>\
    \ f, const Func &op = std::minus<T>()){\n    const int N = f.size();\n    assert((N\
    \ & (N - 1)) == 0 && \"N must be a power of 2\");\n    for(int i = 1; i < N; i\
    \ <<= 1){\n      for(int j = 0; j < N; ++j){\n        if(j & i) f[j] = op(f[j],\
    \ f[j ^ i]);\n      }\n    }\n    return f;\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 10 \"test/aoj/2446/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int64_t n, m; std::cin\
    \ >> n >> m;\n\n  auto a = hl::input_vector<int64_t>(n);\n  auto p = hl::input_vector<double>(n);\n\
    \n  for(auto &x : p) x /= 100.0;\n\n  std::vector<int64_t> dp(1 << n);\n  for(int\
    \ i = 1; i < 1 << n; ++i){\n    int64_t l = 1;\n    for(int j = 0; j < n; ++j){\n\
    \      if((i >> j) & 1){\n        int64_t g = std::gcd(l, a[j]);\n\n        long\
    \ long int k;\n        if(__builtin_smulll_overflow(l / g, a[j], &k)){\n     \
    \     l = m + 1;\n          break;\n        }\n        l = (l / g) * a[j];\n \
    \     }\n    }\n    dp[i] = m / l;\n  }\n\n  dp = hl::fast_mobius_transform_subset(dp);\n\
    \n  double ans = 0.0;\n\n  for(int i = 0; i < (1 << n); ++i){\n    double q =\
    \ 1.0;\n    for(int j = 0; j < n; ++j){\n      if(i >> j & 1) q *= p[j];\n   \
    \   else q *= 1.0 - p[j];\n    }\n    ans += q * std::abs(dp[i]);\n  }\n\n  std::cout\
    \ << std::fixed << std::setprecision(12) << ans << std::endl;\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446\"\
    \n#define ERROR 1e-7\n\n#include <iostream>\n#include <iomanip>\n#include <vector>\n\
    #include <numeric>\n#include \"Mylib/Convolution/fast_mobius_transform_subset.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int64_t n, m; std::cin\
    \ >> n >> m;\n\n  auto a = hl::input_vector<int64_t>(n);\n  auto p = hl::input_vector<double>(n);\n\
    \n  for(auto &x : p) x /= 100.0;\n\n  std::vector<int64_t> dp(1 << n);\n  for(int\
    \ i = 1; i < 1 << n; ++i){\n    int64_t l = 1;\n    for(int j = 0; j < n; ++j){\n\
    \      if((i >> j) & 1){\n        int64_t g = std::gcd(l, a[j]);\n\n        long\
    \ long int k;\n        if(__builtin_smulll_overflow(l / g, a[j], &k)){\n     \
    \     l = m + 1;\n          break;\n        }\n        l = (l / g) * a[j];\n \
    \     }\n    }\n    dp[i] = m / l;\n  }\n\n  dp = hl::fast_mobius_transform_subset(dp);\n\
    \n  double ans = 0.0;\n\n  for(int i = 0; i < (1 << n); ++i){\n    double q =\
    \ 1.0;\n    for(int j = 0; j < n; ++j){\n      if(i >> j & 1) q *= p[j];\n   \
    \   else q *= 1.0 - p[j];\n    }\n    ans += q * std::abs(dp[i]);\n  }\n\n  std::cout\
    \ << std::fixed << std::setprecision(12) << ans << std::endl;\n\n  return 0;\n\
    }\n"
  dependsOn:
  - Mylib/Convolution/fast_mobius_transform_subset.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/2446/main.test.cpp
  requiredBy: []
  timestamp: '2020-10-30 23:28:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/2446/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2446/main.test.cpp
- /verify/test/aoj/2446/main.test.cpp.html
title: test/aoj/2446/main.test.cpp
---
