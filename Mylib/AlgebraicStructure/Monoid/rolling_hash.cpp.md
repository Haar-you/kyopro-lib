---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2444/main.test.cpp
    title: test/aoj/2444/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/rolling_hash.cpp\"\n#include\
    \ <array>\n#include <utility>\n\nnamespace haar_lib {\n  namespace rolling_hash_monoid_impl\
    \ {\n    template <int64_t Mod, int64_t Base>\n    struct internal_value {\n \
    \     int64_t hash, power;\n      internal_value() {}\n      internal_value(int64_t\
    \ hash, int64_t power) : hash(hash), power(power) {}\n      internal_value(int64_t\
    \ a) : hash(a % Mod), power(Base) {}\n    };\n  }  // namespace rolling_hash_monoid_impl\n\
    \n  template <int64_t Mod, int Base>\n  struct rolling_hash_monoid {\n    using\
    \ value_type = rolling_hash_monoid_impl::internal_value<Mod, Base>;\n\n    value_type\
    \ operator()() const {\n      value_type ret(0, 1);\n      return ret;\n    }\n\
    \n    value_type operator()(const value_type &a, const value_type &b) const {\n\
    \      value_type ret;\n      ret.hash  = (a.hash + b.hash * a.power % Mod) %\
    \ Mod;\n      ret.power = a.power * b.power % Mod;\n      return ret;\n    }\n\
    \  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <array>\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  namespace rolling_hash_monoid_impl {\n    template <int64_t Mod, int64_t\
    \ Base>\n    struct internal_value {\n      int64_t hash, power;\n      internal_value()\
    \ {}\n      internal_value(int64_t hash, int64_t power) : hash(hash), power(power)\
    \ {}\n      internal_value(int64_t a) : hash(a % Mod), power(Base) {}\n    };\n\
    \  }  // namespace rolling_hash_monoid_impl\n\n  template <int64_t Mod, int Base>\n\
    \  struct rolling_hash_monoid {\n    using value_type = rolling_hash_monoid_impl::internal_value<Mod,\
    \ Base>;\n\n    value_type operator()() const {\n      value_type ret(0, 1);\n\
    \      return ret;\n    }\n\n    value_type operator()(const value_type &a, const\
    \ value_type &b) const {\n      value_type ret;\n      ret.hash  = (a.hash + b.hash\
    \ * a.power % Mod) % Mod;\n      ret.power = a.power * b.power % Mod;\n      return\
    \ ret;\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/rolling_hash.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2444/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/Monoid/rolling_hash.cpp
layout: document
title: Rolling hash monoid
---

## Operations

## Requirements

## Notes

## Problems

## References