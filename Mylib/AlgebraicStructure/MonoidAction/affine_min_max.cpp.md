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
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/MonoidAction/affine_min_max.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename MonoidGet, typename MonoidUpdate>\n\
    \  struct affine_min_max {\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(const value_type_get &a, const value_type_update &b, int) const {\n\
    \      value_type_get ret;\n      if(b.first >= 0){\n        if(a.min) ret.min\
    \ = b.first * (a.min.value()) + b.second;\n        if(a.max) ret.max = b.first\
    \ * (a.max.value()) + b.second;\n      }else{\n        if(a.min) ret.max = b.first\
    \ * (a.min.value()) + b.second;\n        if(a.max) ret.min = b.first * (a.max.value())\
    \ + b.second;\n      }\n\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename MonoidGet, typename\
    \ MonoidUpdate>\n  struct affine_min_max {\n    using value_type_get = typename\
    \ MonoidGet::value_type;\n    using value_type_update = typename MonoidUpdate::value_type;\n\
    \n    value_type_get operator()(const value_type_get &a, const value_type_update\
    \ &b, int) const {\n      value_type_get ret;\n      if(b.first >= 0){\n     \
    \   if(a.min) ret.min = b.first * (a.min.value()) + b.second;\n        if(a.max)\
    \ ret.max = b.first * (a.max.value()) + b.second;\n      }else{\n        if(a.min)\
    \ ret.max = b.first * (a.min.value()) + b.second;\n        if(a.max) ret.min =\
    \ b.first * (a.max.value()) + b.second;\n      }\n\n      return ret;\n    }\n\
    \  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/MonoidAction/affine_min_max.cpp
  requiredBy: []
  timestamp: '2020-09-20 23:10:27+09:00'
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
