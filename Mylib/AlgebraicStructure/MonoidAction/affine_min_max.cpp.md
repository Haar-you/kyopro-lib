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
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/MonoidAction/affine_min_max.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename MonoidUpdate, typename MonoidGet>\n\
    \  struct affine_min_max {\n    using monoid_get        = MonoidGet;\n    using\
    \ monoid_update     = MonoidUpdate;\n    using value_type_get    = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(const value_type_get &a, const value_type_update &b, int) const {\n\
    \      value_type_get ret;\n      if (b.first >= 0) {\n        if (a.min) ret.min\
    \ = b.first * (a.min.value()) + b.second;\n        if (a.max) ret.max = b.first\
    \ * (a.max.value()) + b.second;\n      } else {\n        if (a.min) ret.max =\
    \ b.first * (a.min.value()) + b.second;\n        if (a.max) ret.min = b.first\
    \ * (a.max.value()) + b.second;\n      }\n\n      return ret;\n    }\n  };\n}\
    \  // namespace haar_lib\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename MonoidUpdate,\
    \ typename MonoidGet>\n  struct affine_min_max {\n    using monoid_get       \
    \ = MonoidGet;\n    using monoid_update     = MonoidUpdate;\n    using value_type_get\
    \    = typename MonoidGet::value_type;\n    using value_type_update = typename\
    \ MonoidUpdate::value_type;\n\n    value_type_get operator()(const value_type_get\
    \ &a, const value_type_update &b, int) const {\n      value_type_get ret;\n  \
    \    if (b.first >= 0) {\n        if (a.min) ret.min = b.first * (a.min.value())\
    \ + b.second;\n        if (a.max) ret.max = b.first * (a.max.value()) + b.second;\n\
    \      } else {\n        if (a.min) ret.max = b.first * (a.min.value()) + b.second;\n\
    \        if (a.max) ret.min = b.first * (a.max.value()) + b.second;\n      }\n\
    \n      return ret;\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/MonoidAction/affine_min_max.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/AlgebraicStructure/MonoidAction/affine_min_max.cpp
layout: document
title: Range affine / Range min-max
---

## Operations

## Requirements

## Notes

## Problems

## References
