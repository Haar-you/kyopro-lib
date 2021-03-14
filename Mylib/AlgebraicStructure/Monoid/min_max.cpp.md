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
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/min_max.cpp\"\n#include\
    \ <optional>\n#include <algorithm>\n\nnamespace haar_lib {\n  namespace min_max_monoid_impl\
    \ {\n    template <typename T>\n    struct internal_value {\n      std::optional<T>\
    \ min, max;\n      internal_value(): min(std::nullopt), max(std::nullopt){}\n\
    \      internal_value(T value): min(value), max(value){}\n    };\n  }\n\n  template\
    \ <typename T>\n  struct min_max_monoid {\n    using value_type = min_max_monoid_impl::internal_value<T>;\n\
    \n    value_type operator()() const {\n      return {};\n    }\n\n    value_type\
    \ operator()(const value_type &a, const value_type &b) const {\n      value_type\
    \ ret;\n      if(not a.min) ret.min = b.min;\n      if(not b.min) ret.min = a.min;\n\
    \      if(a.min and b.min) ret.min = std::min(a.min.value(), b.min.value());\n\
    \n      if(not a.max) ret.max = b.max;\n      if(not b.max) ret.max = a.max;\n\
    \      if(a.max and b.max) ret.max = std::max(a.max.value(), b.max.value());\n\
    \n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <optional>\n#include <algorithm>\n\nnamespace haar_lib\
    \ {\n  namespace min_max_monoid_impl {\n    template <typename T>\n    struct\
    \ internal_value {\n      std::optional<T> min, max;\n      internal_value():\
    \ min(std::nullopt), max(std::nullopt){}\n      internal_value(T value): min(value),\
    \ max(value){}\n    };\n  }\n\n  template <typename T>\n  struct min_max_monoid\
    \ {\n    using value_type = min_max_monoid_impl::internal_value<T>;\n\n    value_type\
    \ operator()() const {\n      return {};\n    }\n\n    value_type operator()(const\
    \ value_type &a, const value_type &b) const {\n      value_type ret;\n      if(not\
    \ a.min) ret.min = b.min;\n      if(not b.min) ret.min = a.min;\n      if(a.min\
    \ and b.min) ret.min = std::min(a.min.value(), b.min.value());\n\n      if(not\
    \ a.max) ret.max = b.max;\n      if(not b.max) ret.max = a.max;\n      if(a.max\
    \ and b.max) ret.max = std::max(a.max.value(), b.max.value());\n\n      return\
    \ ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/min_max.cpp
  requiredBy: []
  timestamp: '2021-03-13 05:23:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/AlgebraicStructure/Monoid/min_max.cpp
layout: document
title: Min-Max monoid
---

## Operations

## Requirements

## Notes

## Problems

## References
