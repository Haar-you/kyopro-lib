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
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/max_contiguous.cpp\"\n#include\
    \ <tuple>\n#include <algorithm>\n\nnamespace haar_lib {\n  namespace max_contiguous_monoid_impl\
    \ {\n    struct inner_value {\n      int count, left, right, length;\n      inner_value(){}\n\
    \      inner_value(int count, int left, int right, int length):\n        count(count),\
    \ left(left), right(right), length(length){}\n      inner_value(int x): count(x\
    \ ? 1 : 0), left(x ? 1 : 0), right(x ? 1 : 0), length(1){}\n    };\n  }\n\n  struct\
    \ max_contiguous_monoid {\n    using value_type = max_contiguous_monoid_impl::inner_value;\n\
    \n    value_type operator()() const {\n      return {0, 0, 0, 0};\n    }\n\n \
    \   value_type operator()(const value_type &a, const value_type &b) const {\n\
    \      return {\n              std::max({a.count, b.count, a.right + b.left}),\n\
    \              a.count == a.length ? a.count + b.left : a.left,\n            \
    \  b.count == b.length ? b.count + a.right : b.right,\n              a.length\
    \ + b.length\n      };\n    }\n  };\n}\n"
  code: "#pragma once\n#include <tuple>\n#include <algorithm>\n\nnamespace haar_lib\
    \ {\n  namespace max_contiguous_monoid_impl {\n    struct inner_value {\n    \
    \  int count, left, right, length;\n      inner_value(){}\n      inner_value(int\
    \ count, int left, int right, int length):\n        count(count), left(left),\
    \ right(right), length(length){}\n      inner_value(int x): count(x ? 1 : 0),\
    \ left(x ? 1 : 0), right(x ? 1 : 0), length(1){}\n    };\n  }\n\n  struct max_contiguous_monoid\
    \ {\n    using value_type = max_contiguous_monoid_impl::inner_value;\n\n    value_type\
    \ operator()() const {\n      return {0, 0, 0, 0};\n    }\n\n    value_type operator()(const\
    \ value_type &a, const value_type &b) const {\n      return {\n              std::max({a.count,\
    \ b.count, a.right + b.left}),\n              a.count == a.length ? a.count +\
    \ b.left : a.left,\n              b.count == b.length ? b.count + a.right : b.right,\n\
    \              a.length + b.length\n      };\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/max_contiguous.cpp
  requiredBy: []
  timestamp: '2020-09-18 01:14:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/AlgebraicStructure/Monoid/max_contiguous.cpp
layout: document
title: Max contiguous monoid
---

## Operations

- `id()`
	- 長さ`0`の列を表す。
	- `return (0, 0, 0, 0)`
- `op(a, b)`
	- `a`の右隣に`b`を隣接させる。

## Requirements

## Notes

- 連続する`1`の最大長を管理する。
	- `value_type = (最大連続長, 左側最大連続長, 右側最大連続長, セグメント長)`

## Problems

- [Codeforces Round #276 (Div. 1) E. Sign on Fence](https://codeforces.com/contest/484/problem/E)

## References

