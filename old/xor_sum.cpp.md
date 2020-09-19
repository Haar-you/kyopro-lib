---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"old/xor_sum.cpp\"\n#include <array>\n\nnamespace haar_lib\
    \ {\n  template <typename U, int B>\n  struct bitxor_sum {\n    using value_type_get\
    \ = typename std::array<int, B>;\n    using value_type_update = U;\n\n    value_type_get\
    \ id_get() const {\n      value_type_get ret;\n      ret.fill(0);\n      return\
    \ ret;\n    }\n    value_type_update id_update() const {return 0;}\n\n    value_type_get\
    \ op_get(const value_type_get &a, const value_type_get &b){\n      value_type_get\
    \ ret;\n      for(int i = 0; i < B; ++i) ret[i] = a[i] + b[i];\n      return ret;\n\
    \    }\n    value_type_update op_update(value_type_update a, value_type_update\
    \ b) const {return a ^ b;}\n\n    value_type_get op(const value_type_get &a, const\
    \ value_type_update &b, int len) const {\n      auto ret = a;\n      for(int i\
    \ = 0; i < B; ++i) if((b >> i) & 1) ret[i] = len - ret[i];\n      return ret;\n\
    \    }\n  };\n}\n"
  code: "#pragma once\n#include <array>\n\nnamespace haar_lib {\n  template <typename\
    \ U, int B>\n  struct bitxor_sum {\n    using value_type_get = typename std::array<int,\
    \ B>;\n    using value_type_update = U;\n\n    value_type_get id_get() const {\n\
    \      value_type_get ret;\n      ret.fill(0);\n      return ret;\n    }\n   \
    \ value_type_update id_update() const {return 0;}\n\n    value_type_get op_get(const\
    \ value_type_get &a, const value_type_get &b){\n      value_type_get ret;\n  \
    \    for(int i = 0; i < B; ++i) ret[i] = a[i] + b[i];\n      return ret;\n   \
    \ }\n    value_type_update op_update(value_type_update a, value_type_update b)\
    \ const {return a ^ b;}\n\n    value_type_get op(const value_type_get &a, const\
    \ value_type_update &b, int len) const {\n      auto ret = a;\n      for(int i\
    \ = 0; i < B; ++i) if((b >> i) & 1) ret[i] = len - ret[i];\n      return ret;\n\
    \    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/xor_sum.cpp
  requiredBy: []
  timestamp: '2020-09-18 18:43:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/xor_sum.cpp
layout: document
redirect_from:
- /library/old/xor_sum.cpp
- /library/old/xor_sum.cpp.html
title: old/xor_sum.cpp
---
