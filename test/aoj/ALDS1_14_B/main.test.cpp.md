---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/String/rolling_hash.cpp
    title: Rolling hash
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_B/main.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n\n#include\
    \ <iostream>\n#include <string>\n#line 2 \"Mylib/String/rolling_hash.cpp\"\n#include\
    \ <vector>\n#include <random>\n\nnamespace haar_lib {\n  class rolling_hash {\n\
    \    std::vector<int64_t> pow_;\n    int64_t MOD_, BASE_;\n\n  public:\n    rolling_hash(){}\n\
    \    rolling_hash(int size, int MOD, int BASE): MOD_(MOD), BASE_(BASE){\n    \
    \  pow_.assign(size + 1, 1);\n      for(int i = 1; i <= size; ++i) pow_[i] = pow_[i\
    \ - 1] * BASE_ % MOD_;\n    }\n\n    template <typename T>\n    auto gen_hash_table(const\
    \ T &s) const {\n      std::vector<int64_t> ret(s.size() + 1);\n      for(int\
    \ i = 0; i < (int)s.size(); ++i) ret[i + 1] = (ret[i] * BASE_ + s[i]) % MOD_;\n\
    \      return ret;\n    }\n\n    template <typename T>\n    auto gen_hash(const\
    \ T &s) const {\n      int64_t ret = 0;\n      for(int i = 0; i < (int)s.size();\
    \ ++i) ret = (ret * BASE_ + s[i]) % MOD_;\n      return ret;\n    }\n\n    /**\n\
    \     * @attention [l, r)\n     */\n    int64_t get(const std::vector<int64_t>\
    \ &table, int l, int r) const {\n      return (table[r] - table[l] * pow_[r -\
    \ l] % MOD_ + MOD_ * MOD_) % MOD_;\n    }\n\n    template <typename T>\n    std::vector<int>\
    \ find(const T &s, const T &pattern) const {\n      auto hp = gen_hash(pattern);\n\
    \      auto hs = gen_hash_table(s);\n      std::vector<int> ret;\n      for(int\
    \ i = 0; i <= ((int)s.size() - (int)pattern.size()); ++i){\n        if(hp == get(hs,\
    \ i, i + pattern.size())) ret.push_back(i);\n      }\n\n      return ret;\n  \
    \  }\n  };\n\n  auto make_rh(int size, int MOD, int seed = 0){\n    std::mt19937\
    \ rnd(seed);\n    std::uniform_int_distribution<> dist(2, MOD - 2);\n    return\
    \ rolling_hash(size, MOD, dist(rnd));\n  }\n}\n#line 6 \"test/aoj/ALDS1_14_B/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  auto rh = hl::make_rh(1000000,\
    \ 1000000007);\n\n  std::string t, p; std::cin >> t >> p;\n\n  auto res = rh.find(t,\
    \ p);\n  for(auto i : res) std::cout << i << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <iostream>\n#include <string>\n#include \"Mylib/String/rolling_hash.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  auto rh = hl::make_rh(1000000,\
    \ 1000000007);\n\n  std::string t, p; std::cin >> t >> p;\n\n  auto res = rh.find(t,\
    \ p);\n  for(auto i : res) std::cout << i << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/String/rolling_hash.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_B/main.test.cpp
  requiredBy: []
  timestamp: '2021-01-03 21:45:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_B/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_B/main.test.cpp
- /verify/test/aoj/ALDS1_14_B/main.test.cpp.html
title: test/aoj/ALDS1_14_B/main.test.cpp
---
