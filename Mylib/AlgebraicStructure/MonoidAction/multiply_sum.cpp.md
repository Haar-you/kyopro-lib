---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/MonoidAction/multiply_sum.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename MonoidUpdate, typename MonoidGet>\n\
    \  struct multiply_sum {\n    using monoid_get = MonoidGet;\n    using monoid_update\
    \ = MonoidUpdate;\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(value_type_get &a, value_type_update &b, int len) const {\n     \
    \ return a * b;\n    }\n  };\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename MonoidUpdate,\
    \ typename MonoidGet>\n  struct multiply_sum {\n    using monoid_get = MonoidGet;\n\
    \    using monoid_update = MonoidUpdate;\n    using value_type_get = typename\
    \ MonoidGet::value_type;\n    using value_type_update = typename MonoidUpdate::value_type;\n\
    \n    value_type_get operator()(value_type_get &a, value_type_update &b, int len)\
    \ const {\n      return a * b;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/MonoidAction/multiply_sum.cpp
  requiredBy: []
  timestamp: '2020-10-02 17:13:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/AlgebraicStructure/MonoidAction/multiply_sum.cpp
layout: document
title: Range multiply / Range sum
---

## Operations

## Requirements

## Notes

## Problems

## References
