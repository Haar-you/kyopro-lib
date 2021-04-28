---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ALDS1_14_C/main.test.cpp
    title: test/aoj/ALDS1_14_C/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/String/rolling_hash_2d.cpp\"\n#include <random>\n\
    #include <vector>\n\nnamespace haar_lib {\n  class rolling_hash_2d {\n    std::vector<int64_t>\
    \ pow_w_, pow_h_;\n    int64_t MOD_, BASEW_, BASEH_;\n\n  public:\n    rolling_hash_2d()\
    \ {}\n    rolling_hash_2d(int width, int height, int MOD, int BASEW, int BASEH)\
    \ : MOD_(MOD), BASEW_(BASEW), BASEH_(BASEH) {\n      pow_w_.resize(width + 1);\n\
    \      pow_h_.resize(height + 1);\n      pow_w_[0] = pow_h_[0] = 1;\n      for\
    \ (int i = 1; i <= width; ++i) pow_w_[i] = pow_w_[i - 1] * BASEW_ % MOD_;\n  \
    \    for (int i = 1; i <= height; ++i) pow_h_[i] = pow_h_[i - 1] * BASEH_ % MOD_;\n\
    \    }\n\n    template <typename T>\n    auto gen_hash_table(const T &s) const\
    \ {\n      const int n = s.size(), m = s[0].size();\n      std::vector<std::vector<int64_t>>\
    \ ret(n + 1, std::vector<int64_t>(m + 1));\n\n      for (int i = 0; i < n; ++i)\
    \ {\n        for (int j = 0; j < m; ++j) {\n          ret[i + 1][j + 1] = (ret[i\
    \ + 1][j] * BASEW_ + s[i][j]) % MOD_;\n        }\n      }\n      for (int i =\
    \ 0; i < n; ++i) {\n        for (int j = 0; j < m; ++j) {\n          ret[i + 1][j\
    \ + 1] = (ret[i][j + 1] * BASEH_ + ret[i + 1][j + 1]) % MOD_;\n        }\n   \
    \   }\n\n      return ret;\n    }\n\n    template <typename T>\n    auto gen_hash(const\
    \ T &s) const {\n      const int n = s.size(), m = s[0].size();\n      int64_t\
    \ ret = 0;\n      for (int i = 0; i < n; ++i) {\n        int64_t temp = 0;\n \
    \       for (int j = 0; j < m; ++j) {\n          temp = (temp * BASEW_ + s[i][j])\
    \ % MOD_;\n        }\n        ret = (ret * BASEH_ + temp) % MOD_;\n      }\n \
    \     return ret;\n    }\n\n    /**\n     * @attention [i1, i2), [j1, j2)\n  \
    \   */\n    int64_t get(const std::vector<std::vector<int64_t>> &table, int i1,\
    \ int j1, int i2, int j2) const {\n      const auto a = table[i2][j2];\n     \
    \ const auto b = table[i1][j2] * pow_h_[i2 - i1] % MOD_;\n      const auto c =\
    \ table[i2][j1] * pow_w_[j2 - j1] % MOD_;\n      const auto d = table[i1][j1]\
    \ * pow_h_[i2 - i1] % MOD_ * pow_w_[j2 - j1] % MOD_;\n\n      return (((a - b\
    \ + MOD_) % MOD_ - c + MOD_) % MOD_ + d + MOD_) % MOD_;\n    }\n\n    template\
    \ <typename T>\n    std::vector<std::pair<int, int>> find(const T &s, const T\
    \ &pattern) const {\n      auto hp = gen_hash(pattern);\n      auto hs = gen_hash_table(s);\n\
    \n      const int H = s.size();\n      const int W = s[0].size();\n      const\
    \ int R = pattern.size();\n      const int C = pattern[0].size();\n\n      std::vector<std::pair<int,\
    \ int>> ret;\n\n      for (int i = 0; i <= H - R; ++i) {\n        for (int j =\
    \ 0; j <= W - C; ++j) {\n          if (hp == get(hs, i, j, i + R, j + C)) ret.emplace_back(i,\
    \ j);\n        }\n      }\n\n      return ret;\n    }\n  };\n\n  auto make_rh_2d(int\
    \ width, int height, int MOD, int seed = 0) {\n    std::mt19937 rnd(seed);\n \
    \   std::uniform_int_distribution<> dist(2, MOD - 2);\n    return rolling_hash_2d(width,\
    \ height, MOD, dist(rnd), dist(rnd));\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <random>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  class rolling_hash_2d {\n    std::vector<int64_t> pow_w_, pow_h_;\n   \
    \ int64_t MOD_, BASEW_, BASEH_;\n\n  public:\n    rolling_hash_2d() {}\n    rolling_hash_2d(int\
    \ width, int height, int MOD, int BASEW, int BASEH) : MOD_(MOD), BASEW_(BASEW),\
    \ BASEH_(BASEH) {\n      pow_w_.resize(width + 1);\n      pow_h_.resize(height\
    \ + 1);\n      pow_w_[0] = pow_h_[0] = 1;\n      for (int i = 1; i <= width; ++i)\
    \ pow_w_[i] = pow_w_[i - 1] * BASEW_ % MOD_;\n      for (int i = 1; i <= height;\
    \ ++i) pow_h_[i] = pow_h_[i - 1] * BASEH_ % MOD_;\n    }\n\n    template <typename\
    \ T>\n    auto gen_hash_table(const T &s) const {\n      const int n = s.size(),\
    \ m = s[0].size();\n      std::vector<std::vector<int64_t>> ret(n + 1, std::vector<int64_t>(m\
    \ + 1));\n\n      for (int i = 0; i < n; ++i) {\n        for (int j = 0; j < m;\
    \ ++j) {\n          ret[i + 1][j + 1] = (ret[i + 1][j] * BASEW_ + s[i][j]) % MOD_;\n\
    \        }\n      }\n      for (int i = 0; i < n; ++i) {\n        for (int j =\
    \ 0; j < m; ++j) {\n          ret[i + 1][j + 1] = (ret[i][j + 1] * BASEH_ + ret[i\
    \ + 1][j + 1]) % MOD_;\n        }\n      }\n\n      return ret;\n    }\n\n   \
    \ template <typename T>\n    auto gen_hash(const T &s) const {\n      const int\
    \ n = s.size(), m = s[0].size();\n      int64_t ret = 0;\n      for (int i = 0;\
    \ i < n; ++i) {\n        int64_t temp = 0;\n        for (int j = 0; j < m; ++j)\
    \ {\n          temp = (temp * BASEW_ + s[i][j]) % MOD_;\n        }\n        ret\
    \ = (ret * BASEH_ + temp) % MOD_;\n      }\n      return ret;\n    }\n\n    /**\n\
    \     * @attention [i1, i2), [j1, j2)\n     */\n    int64_t get(const std::vector<std::vector<int64_t>>\
    \ &table, int i1, int j1, int i2, int j2) const {\n      const auto a = table[i2][j2];\n\
    \      const auto b = table[i1][j2] * pow_h_[i2 - i1] % MOD_;\n      const auto\
    \ c = table[i2][j1] * pow_w_[j2 - j1] % MOD_;\n      const auto d = table[i1][j1]\
    \ * pow_h_[i2 - i1] % MOD_ * pow_w_[j2 - j1] % MOD_;\n\n      return (((a - b\
    \ + MOD_) % MOD_ - c + MOD_) % MOD_ + d + MOD_) % MOD_;\n    }\n\n    template\
    \ <typename T>\n    std::vector<std::pair<int, int>> find(const T &s, const T\
    \ &pattern) const {\n      auto hp = gen_hash(pattern);\n      auto hs = gen_hash_table(s);\n\
    \n      const int H = s.size();\n      const int W = s[0].size();\n      const\
    \ int R = pattern.size();\n      const int C = pattern[0].size();\n\n      std::vector<std::pair<int,\
    \ int>> ret;\n\n      for (int i = 0; i <= H - R; ++i) {\n        for (int j =\
    \ 0; j <= W - C; ++j) {\n          if (hp == get(hs, i, j, i + R, j + C)) ret.emplace_back(i,\
    \ j);\n        }\n      }\n\n      return ret;\n    }\n  };\n\n  auto make_rh_2d(int\
    \ width, int height, int MOD, int seed = 0) {\n    std::mt19937 rnd(seed);\n \
    \   std::uniform_int_distribution<> dist(2, MOD - 2);\n    return rolling_hash_2d(width,\
    \ height, MOD, dist(rnd), dist(rnd));\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/rolling_hash_2d.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ALDS1_14_C/main.test.cpp
documentation_of: Mylib/String/rolling_hash_2d.cpp
layout: document
title: Rolling hash (2D)
---

## Operations

## Requirements

## Notes

## Problems

## References
