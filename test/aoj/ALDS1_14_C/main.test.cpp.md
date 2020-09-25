---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/String/rolling_hash_2d.cpp
    title: Rolling hash (2D)
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Mylib/IO/input_vector.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_C/main.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C\"\n\n#include\
    \ <iostream>\n#include <string>\n#include <vector>\n#line 3 \"Mylib/String/rolling_hash_2d.cpp\"\
    \n#include <random>\n\nnamespace haar_lib {\n  class rolling_hash_2d {\n    std::vector<int64_t>\
    \ pow_w, pow_h;\n    int64_t MOD, BASEW, BASEH;\n\n  public:\n    rolling_hash_2d(int\
    \ width, int height, int MOD, int BASEW, int BASEH): MOD(MOD), BASEW(BASEW), BASEH(BASEH){\n\
    \      pow_w.resize(width + 1);\n      pow_h.resize(height + 1);\n      pow_w[0]\
    \ = pow_h[0] = 1;\n      for(int i = 1; i <= width; ++i) pow_w[i] = pow_w[i -\
    \ 1] * BASEW % MOD;\n      for(int i = 1; i <= height; ++i) pow_h[i] = pow_h[i\
    \ - 1] * BASEH % MOD;\n    }\n\n    template <typename T>\n    auto gen_hash_table(const\
    \ T &s) const {\n      const int n = s.size(), m = s[0].size();\n      std::vector<std::vector<int64_t>>\
    \ ret(n + 1, std::vector<int64_t>(m + 1));\n\n      for(int i = 0; i < n; ++i){\n\
    \        for(int j = 0; j < m; ++j){\n          ret[i + 1][j + 1] = (ret[i + 1][j]\
    \ * BASEW + s[i][j]) % MOD;\n        }\n      }\n      for(int i = 0; i < n; ++i){\n\
    \        for(int j = 0; j < m; ++j){\n          ret[i + 1][j + 1] = (ret[i][j\
    \ + 1] * BASEH + ret[i + 1][j + 1]) % MOD;\n        }\n      }\n\n      return\
    \ ret;\n    }\n\n    template <typename T>\n    auto gen_hash(const T &s) const\
    \ {\n      const int n = s.size(), m = s[0].size();\n      int64_t ret = 0;\n\
    \      for(int i = 0; i < n; ++i){\n        int64_t temp = 0;\n        for(int\
    \ j = 0; j < m; ++j){\n          temp = (temp * BASEW + s[i][j]) % MOD;\n    \
    \    }\n        ret = (ret * BASEH + temp) % MOD;\n      }\n      return ret;\n\
    \    }\n\n    /**\n     * @attention [i1, i2), [j1, j2)\n     */\n    int64_t\
    \ get(const std::vector<std::vector<int64_t>> &table, int i1, int j1, int i2,\
    \ int j2) const {\n      const auto a = table[i2][j2];\n      const auto b = table[i1][j2]\
    \ * pow_h[i2 - i1] % MOD;\n      const auto c = table[i2][j1] * pow_w[j2 - j1]\
    \ % MOD;\n      const auto d = table[i1][j1] * pow_h[i2 - i1] % MOD * pow_w[j2\
    \ - j1] % MOD;\n\n      return (((a - b + MOD) % MOD - c + MOD) % MOD + d + MOD)\
    \ % MOD;\n    }\n\n    template <typename T>\n    std::vector<std::pair<int, int>>\
    \ find(const T &s, const T &pattern) const {\n      auto hp = gen_hash(pattern);\n\
    \      auto hs = gen_hash_table(s);\n\n      const int H = s.size();\n      const\
    \ int W = s[0].size();\n      const int R = pattern.size();\n      const int C\
    \ = pattern[0].size();\n\n      std::vector<std::pair<int, int>> ret;\n\n    \
    \  for(int i = 0; i <= H - R; ++i){\n        for(int j = 0; j <= W - C; ++j){\n\
    \          if(hp == get(hs, i, j, i + R, j + C)) ret.emplace_back(i, j);\n   \
    \     }\n      }\n\n      return ret;\n    }\n  };\n\n  auto make_rh_2d(int width,\
    \ int height, int MOD, int seed = 0){\n    std::mt19937 rnd(seed);\n    std::uniform_int_distribution<>\
    \ dist(2, MOD - 2);\n    return rolling_hash_2d(width, height, dist(rnd), dist(rnd),\
    \ MOD);\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace haar_lib {\n\
    \  template <typename T>\n  std::vector<T> input_vector(int N){\n    std::vector<T>\
    \ ret(N);\n    for(int i = 0; i < N; ++i) std::cin >> ret[i];\n    return ret;\n\
    \  }\n\n  template <typename T>\n  std::vector<std::vector<T>> input_vector(int\
    \ N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int i = 0; i <\
    \ N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line 8 \"test/aoj/ALDS1_14_C/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  auto rh = hl::make_rh_2d(1000,\
    \ 1000, 1000000007);\n\n  int H, W; std::cin >> H >> W;\n  auto s = hl::input_vector<std::string>(H);\n\
    \n  int R, C; std::cin >> R >> C;\n  auto t = hl::input_vector<std::string>(R);\n\
    \n  auto res = rh.find(s, t);\n  for(auto [i, j] : res) std::cout << i << \" \"\
    \ << j << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C\"\
    \n\n#include <iostream>\n#include <string>\n#include <vector>\n#include \"Mylib/String/rolling_hash_2d.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  auto rh = hl::make_rh_2d(1000, 1000, 1000000007);\n\n  int H, W; std::cin >>\
    \ H >> W;\n  auto s = hl::input_vector<std::string>(H);\n\n  int R, C; std::cin\
    \ >> R >> C;\n  auto t = hl::input_vector<std::string>(R);\n\n  auto res = rh.find(s,\
    \ t);\n  for(auto [i, j] : res) std::cout << i << \" \" << j << \"\\n\";\n\n \
    \ return 0;\n}\n"
  dependsOn:
  - Mylib/String/rolling_hash_2d.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_C/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_C/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_C/main.test.cpp
- /verify/test/aoj/ALDS1_14_C/main.test.cpp.html
title: test/aoj/ALDS1_14_C/main.test.cpp
---
