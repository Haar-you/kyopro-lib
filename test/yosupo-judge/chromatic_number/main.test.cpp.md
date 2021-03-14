---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Coloring/chromatic_number.cpp
    title: Graph vertex coloring
  - icon: ':question:'
    path: Mylib/Number/Mod/mod_pow.cpp
    title: Mod pow
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/chromatic_number
    links:
    - https://judge.yosupo.jp/problem/chromatic_number
  bundledCode: "#line 1 \"test/yosupo-judge/chromatic_number/main.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\n\n#include <iostream>\n\
    #include <vector>\n#line 3 \"Mylib/Graph/Coloring/chromatic_number.cpp\"\n#include\
    \ <cstdint>\n#include <cmath>\n#line 3 \"Mylib/Number/Mod/mod_pow.cpp\"\n\nnamespace\
    \ haar_lib {\n  constexpr int64_t mod_pow(int64_t n, int64_t p, int64_t m){\n\
    \    int64_t ret = 1;\n    while(p > 0){\n      if(p & 1) (ret *= n) %= m;\n \
    \     (n *= n) %= m;\n      p >>= 1;\n    }\n    return ret;\n  }\n}\n#line 6\
    \ \"Mylib/Graph/Coloring/chromatic_number.cpp\"\n\nnamespace haar_lib {\n  int\
    \ chromatic_number(const std::vector<std::vector<int>> &graph){\n    static constexpr\
    \ int mod = 1000000007;\n    const int N = graph.size();\n\n    std::vector<int>\
    \ g(N);\n    for(int i = 0; i < N; ++i){\n      for(auto j : graph[i]){\n    \
    \    g[i] |= (1 << j);\n      }\n    }\n\n    std::vector<int64_t> I(1 << N);\n\
    \    I[0] = 1;\n    for(int i = 1; i < (1 << N); ++i){\n      int c = __builtin_ctz(i);\n\
    \      I[i] = I[i - (1 << c)] + I[(i - (1 << c)) & (~g[c])];\n      if(I[i] >=\
    \ mod) I[i] -= mod;\n    }\n\n    const auto check =\n      [&](int k){\n    \
    \    int64_t t = 0;\n        for(int i = 0; i < (1 << N); ++i){\n          if(__builtin_popcount(i)\
    \ % 2 == 1) t -= mod_pow(I[i], k, mod);\n          else t += mod_pow(I[i], k,\
    \ mod);\n          if(t < 0) t += mod;\n          if(t >= mod) t -= mod;\n   \
    \     }\n        return (t % mod != 0);\n      };\n\n    int lb = 0, ub = N;\n\
    \    while(std::abs(lb - ub) > 1){\n      const auto mid = (lb + ub) / 2;\n\n\
    \      if(check(mid)){\n        ub = mid;\n      }else{\n        lb = mid;\n \
    \     }\n    }\n\n    return ub;\n  }\n}\n#line 6 \"test/yosupo-judge/chromatic_number/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, M; std::cin >> N >> M;\n  std::vector<std::vector<int>> g(N);\n\n \
    \ for(int i = 0; i < M; ++i){\n    int u, v; std::cin >> u >> v;\n    g[u].push_back(v);\n\
    \    g[v].push_back(u);\n  }\n\n  int ans = hl::chromatic_number(g);\n  std::cout\
    \ << ans << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\n\n\
    #include <iostream>\n#include <vector>\n#include \"Mylib/Graph/Coloring/chromatic_number.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, M; std::cin >> N >> M;\n  std::vector<std::vector<int>> g(N);\n\n \
    \ for(int i = 0; i < M; ++i){\n    int u, v; std::cin >> u >> v;\n    g[u].push_back(v);\n\
    \    g[v].push_back(u);\n  }\n\n  int ans = hl::chromatic_number(g);\n  std::cout\
    \ << ans << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Coloring/chromatic_number.cpp
  - Mylib/Number/Mod/mod_pow.cpp
  isVerificationFile: true
  path: test/yosupo-judge/chromatic_number/main.test.cpp
  requiredBy: []
  timestamp: '2021-03-13 06:02:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/chromatic_number/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/chromatic_number/main.test.cpp
- /verify/test/yosupo-judge/chromatic_number/main.test.cpp.html
title: test/yosupo-judge/chromatic_number/main.test.cpp
---
