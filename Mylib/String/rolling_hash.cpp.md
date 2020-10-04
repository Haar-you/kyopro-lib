---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ALDS1_14_B/main.test.cpp
    title: test/aoj/ALDS1_14_B/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/String/rolling_hash.cpp\"\n#include <vector>\n#include\
    \ <random>\n\nnamespace haar_lib {\n  class rolling_hash {\n    std::vector<int64_t>\
    \ pow_;\n    int64_t MOD_, BASE_;\n\n  public:\n    rolling_hash(){}\n    rolling_hash(int\
    \ size, int MOD, int BASE): MOD_(MOD), BASE_(BASE){\n      pow_.assign(size +\
    \ 1, 1);\n      for(int i = 1; i <= size; ++i) pow_[i] = pow_[i - 1] * BASE_ %\
    \ MOD_;\n    }\n\n    template <typename T>\n    auto gen_hash_table(const T &s)\
    \ const {\n      std::vector<int64_t> ret(s.size() + 1);\n      for(int i = 0;\
    \ i < (int)s.size(); ++i) ret[i + 1] = (ret[i] * BASE_ + s[i]) % MOD_;\n     \
    \ return ret;\n    }\n\n    template <typename T>\n    auto gen_hash(const T &s)\
    \ const {\n      int64_t ret = 0;\n      for(int i = 0; i < (int)s.size(); ++i)\
    \ ret = (ret * BASE_ + s[i]) % MOD_;\n      return ret;\n    }\n\n    /**\n  \
    \   * @attention [l, r)\n     */\n    int64_t get(const std::vector<int64_t> &table,\
    \ int l, int r) const {\n      return (table[r] - table[l] * pow_[r - l] % MOD_\
    \ + MOD_ * MOD_) % MOD_;\n    }\n\n    template <typename T>\n    std::vector<int>\
    \ find(const T &s, const T &pattern) const {\n      auto hp = gen_hash(pattern);\n\
    \      auto hs = gen_hash_table(s);\n      std::vector<int> ret;\n      for(int\
    \ i = 0; i <= ((int)s.size() - (int)pattern.size()); ++i){\n        if(hp == get(hs,\
    \ i, i + pattern.size())) ret.push_back(i);\n      }\n\n      return ret;\n  \
    \  }\n  };\n\n  auto make_rh(int size, int MOD, int seed = 0){\n    std::mt19937\
    \ rnd(seed);\n    std::uniform_int_distribution<> dist(2, MOD - 2);\n    return\
    \ rolling_hash(size, dist(rnd), MOD);\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <random>\n\nnamespace haar_lib\
    \ {\n  class rolling_hash {\n    std::vector<int64_t> pow_;\n    int64_t MOD_,\
    \ BASE_;\n\n  public:\n    rolling_hash(){}\n    rolling_hash(int size, int MOD,\
    \ int BASE): MOD_(MOD), BASE_(BASE){\n      pow_.assign(size + 1, 1);\n      for(int\
    \ i = 1; i <= size; ++i) pow_[i] = pow_[i - 1] * BASE_ % MOD_;\n    }\n\n    template\
    \ <typename T>\n    auto gen_hash_table(const T &s) const {\n      std::vector<int64_t>\
    \ ret(s.size() + 1);\n      for(int i = 0; i < (int)s.size(); ++i) ret[i + 1]\
    \ = (ret[i] * BASE_ + s[i]) % MOD_;\n      return ret;\n    }\n\n    template\
    \ <typename T>\n    auto gen_hash(const T &s) const {\n      int64_t ret = 0;\n\
    \      for(int i = 0; i < (int)s.size(); ++i) ret = (ret * BASE_ + s[i]) % MOD_;\n\
    \      return ret;\n    }\n\n    /**\n     * @attention [l, r)\n     */\n    int64_t\
    \ get(const std::vector<int64_t> &table, int l, int r) const {\n      return (table[r]\
    \ - table[l] * pow_[r - l] % MOD_ + MOD_ * MOD_) % MOD_;\n    }\n\n    template\
    \ <typename T>\n    std::vector<int> find(const T &s, const T &pattern) const\
    \ {\n      auto hp = gen_hash(pattern);\n      auto hs = gen_hash_table(s);\n\
    \      std::vector<int> ret;\n      for(int i = 0; i <= ((int)s.size() - (int)pattern.size());\
    \ ++i){\n        if(hp == get(hs, i, i + pattern.size())) ret.push_back(i);\n\
    \      }\n\n      return ret;\n    }\n  };\n\n  auto make_rh(int size, int MOD,\
    \ int seed = 0){\n    std::mt19937 rnd(seed);\n    std::uniform_int_distribution<>\
    \ dist(2, MOD - 2);\n    return rolling_hash(size, dist(rnd), MOD);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/rolling_hash.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ALDS1_14_B/main.test.cpp
documentation_of: Mylib/String/rolling_hash.cpp
layout: document
title: Rolling hash
---

## Operations

## Requirements

## Notes

## Problems

## References
