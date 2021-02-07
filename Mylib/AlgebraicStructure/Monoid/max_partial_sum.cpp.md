---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/776/main.test.cpp
    title: test/yukicoder/776/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp\"\n\
    #include <optional>\n#include <algorithm>\n#include <iostream>\n\nnamespace haar_lib\
    \ {\n  namespace max_partial_sum_monoid_impl {\n    template <typename T>\n  \
    \  struct max_partial_sum {\n      T sum, left_max, right_max, partial_max;\n\
    \      max_partial_sum(){}\n      max_partial_sum(T x): sum(x), left_max(x), right_max(x),\
    \ partial_max(x){}\n      max_partial_sum(T sum, T left_max, T right_max, T partial_max):\n\
    \        sum(sum), left_max(left_max), right_max(right_max), partial_max(partial_max){}\n\
    \n      friend std::ostream& operator<<(std::ostream &s, const max_partial_sum\
    \ &a){\n        s << \"(\" << \"sum: \" << a.sum << \", \"\n          << \"left_max:\
    \ \" << a.left_max << \", \"\n          << \"right_max: \" << a.right_max << \"\
    , \"\n          << \"partial_max: \" << a.partial_max << \")\";\n        return\
    \ s;\n      }\n    };\n  }\n\n  template <typename T>\n  struct max_partial_sum_monoid\
    \ {\n    using max_partial_sum = max_partial_sum_monoid_impl::max_partial_sum<T>;\n\
    \    using value_type = std::optional<max_partial_sum>;\n\n    value_type operator()()\
    \ const {\n      return std::nullopt;\n    }\n\n    value_type operator()(const\
    \ value_type &a, const value_type &b) const {\n      if(not a) return b;\n   \
    \   if(not b) return a;\n\n      return max_partial_sum(\n        a->sum + b->sum,\n\
    \        std::max(a->left_max, a->sum + std::max(b->left_max, b->sum)),\n    \
    \    std::max(b->right_max, b->sum + std::max(a->right_max, a->sum)),\n      \
    \  std::max({a->partial_max, b->partial_max, a->right_max + b->left_max})\n  \
    \    );\n    }\n  };\n}\n"
  code: "#pragma once\n#include <optional>\n#include <algorithm>\n#include <iostream>\n\
    \nnamespace haar_lib {\n  namespace max_partial_sum_monoid_impl {\n    template\
    \ <typename T>\n    struct max_partial_sum {\n      T sum, left_max, right_max,\
    \ partial_max;\n      max_partial_sum(){}\n      max_partial_sum(T x): sum(x),\
    \ left_max(x), right_max(x), partial_max(x){}\n      max_partial_sum(T sum, T\
    \ left_max, T right_max, T partial_max):\n        sum(sum), left_max(left_max),\
    \ right_max(right_max), partial_max(partial_max){}\n\n      friend std::ostream&\
    \ operator<<(std::ostream &s, const max_partial_sum &a){\n        s << \"(\" <<\
    \ \"sum: \" << a.sum << \", \"\n          << \"left_max: \" << a.left_max << \"\
    , \"\n          << \"right_max: \" << a.right_max << \", \"\n          << \"partial_max:\
    \ \" << a.partial_max << \")\";\n        return s;\n      }\n    };\n  }\n\n \
    \ template <typename T>\n  struct max_partial_sum_monoid {\n    using max_partial_sum\
    \ = max_partial_sum_monoid_impl::max_partial_sum<T>;\n    using value_type = std::optional<max_partial_sum>;\n\
    \n    value_type operator()() const {\n      return std::nullopt;\n    }\n\n \
    \   value_type operator()(const value_type &a, const value_type &b) const {\n\
    \      if(not a) return b;\n      if(not b) return a;\n\n      return max_partial_sum(\n\
    \        a->sum + b->sum,\n        std::max(a->left_max, a->sum + std::max(b->left_max,\
    \ b->sum)),\n        std::max(b->right_max, b->sum + std::max(a->right_max, a->sum)),\n\
    \        std::max({a->partial_max, b->partial_max, a->right_max + b->left_max})\n\
    \      );\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp
  requiredBy: []
  timestamp: '2020-09-18 01:14:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/776/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp
layout: document
title: Max partial sum monoid
---

## Operations

## Requirements

## Notes

## Problems

- [yukicoder No.776 A Simple RMQ Problem](https://yukicoder.me/problems/no/776)

## References

