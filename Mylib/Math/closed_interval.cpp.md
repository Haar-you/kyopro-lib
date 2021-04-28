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
  bundledCode: "#line 2 \"Mylib/Math/closed_interval.cpp\"\n#include <algorithm>\n\
    #include <iostream>\n#include <optional>\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct closed_interval {\n    std::optional<std::pair<std::optional<T>,\
    \ std::optional<T>>> value;\n\n    closed_interval() {}\n    closed_interval(std::optional<T>\
    \ l, std::optional<T> r) : value(std::make_pair(l, r)) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &s, const closed_interval<T> &a) {\n      s << \"[\"\
    ;\n      if (a.value) {\n        if ((a.value)->first)\n          s << *((a.value)->first);\n\
    \        else\n          s << \"-\u221E \";\n        s << \",\";\n        if ((a.value)->second)\n\
    \          s << *((a.value)->second);\n        else\n          s << \"\u221E \"\
    ;\n      }\n      s << \"]\";\n      return s;\n    }\n\n    bool is_null() const\
    \ {\n      return not value;\n    }\n\n    bool contains(T v) const {\n      if\
    \ (not value) return false;\n      if (value->first and v < *(value->first)) return\
    \ false;\n      if (value->second and v > *(value->second)) return false;\n\n\
    \      return true;\n    }\n  };\n\n  template <typename T>\n  auto intersect(closed_interval<T>\
    \ a, closed_interval<T> b) {\n    if (not a.value or not b.value) return closed_interval<T>();\n\
    \    std::optional<T> l, r;\n\n    if ((a.value)->first) {\n      l = *((a.value)->first);\n\
    \    }\n\n    if ((b.value)->first) {\n      if (l)\n        l = std::max(*l,\
    \ *((b.value)->first));\n      else\n        l = *((b.value)->first);\n    }\n\
    \n    if ((a.value)->second) {\n      r = *((a.value)->second);\n    }\n\n   \
    \ if ((b.value)->second) {\n      if (r)\n        r = std::min(*r, *((b.value)->second));\n\
    \      else\n        r = *((b.value)->second);\n    }\n\n    if (l and r) {\n\
    \      if (*l > *r) {\n        return closed_interval<T>();\n      }\n    }\n\n\
    \    return closed_interval<T>(l, r);\n  }\n\n  template <typename T>\n  auto\
    \ left_expand(closed_interval<T> a, T x) {\n    if (a.value and (a.value)->first)\
    \ {\n      *((a.value)->first) += x;\n      if ((a.value)->second and *((a.value)->first)\
    \ > *((a.value)->second)) {\n        return closed_interval<T>();\n      }\n \
    \   }\n\n    return a;\n  }\n\n  template <typename T>\n  auto right_expand(closed_interval<T>\
    \ a, T x) {\n    if (a.value and (a.value)->second) {\n      *((a.value)->second)\
    \ += x;\n      if ((a.value)->first and *((a.value)->first) > *((a.value)->second))\
    \ {\n        return closed_interval<T>();\n      }\n    }\n\n    return a;\n \
    \ }\n\n  template <typename T>\n  auto operator+(closed_interval<T> a, T k) {\n\
    \    if (a.value) {\n      if (a.value->first) a.value->first.value() += k;\n\
    \      if (a.value->second) a.value->second.value() += k;\n    }\n    return a;\n\
    \  }\n\n  template <typename T>\n  auto operator-(closed_interval<T> a, T k) {\n\
    \    if (a.value) {\n      if (a.value->first) a.value->first.value() -= k;\n\
    \      if (a.value->second) a.value->second.value() -= k;\n    }\n    return a;\n\
    \  }\n\n  template <typename T>\n  auto operator*(closed_interval<T> a, T k) {\n\
    \    if (a.value) {\n      if (k < 0) std::swap(a.value->first, a.value->second);\n\
    \      if (a.value->first) a.value->first.value() *= k;\n      if (a.value->second)\
    \ a.value->second.value() *= k;\n    }\n    return a;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <iostream>\n#include <optional>\n\
    #include <utility>\n\nnamespace haar_lib {\n  template <typename T>\n  struct\
    \ closed_interval {\n    std::optional<std::pair<std::optional<T>, std::optional<T>>>\
    \ value;\n\n    closed_interval() {}\n    closed_interval(std::optional<T> l,\
    \ std::optional<T> r) : value(std::make_pair(l, r)) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &s, const closed_interval<T> &a) {\n      s << \"[\"\
    ;\n      if (a.value) {\n        if ((a.value)->first)\n          s << *((a.value)->first);\n\
    \        else\n          s << \"-\u221E \";\n        s << \",\";\n        if ((a.value)->second)\n\
    \          s << *((a.value)->second);\n        else\n          s << \"\u221E \"\
    ;\n      }\n      s << \"]\";\n      return s;\n    }\n\n    bool is_null() const\
    \ {\n      return not value;\n    }\n\n    bool contains(T v) const {\n      if\
    \ (not value) return false;\n      if (value->first and v < *(value->first)) return\
    \ false;\n      if (value->second and v > *(value->second)) return false;\n\n\
    \      return true;\n    }\n  };\n\n  template <typename T>\n  auto intersect(closed_interval<T>\
    \ a, closed_interval<T> b) {\n    if (not a.value or not b.value) return closed_interval<T>();\n\
    \    std::optional<T> l, r;\n\n    if ((a.value)->first) {\n      l = *((a.value)->first);\n\
    \    }\n\n    if ((b.value)->first) {\n      if (l)\n        l = std::max(*l,\
    \ *((b.value)->first));\n      else\n        l = *((b.value)->first);\n    }\n\
    \n    if ((a.value)->second) {\n      r = *((a.value)->second);\n    }\n\n   \
    \ if ((b.value)->second) {\n      if (r)\n        r = std::min(*r, *((b.value)->second));\n\
    \      else\n        r = *((b.value)->second);\n    }\n\n    if (l and r) {\n\
    \      if (*l > *r) {\n        return closed_interval<T>();\n      }\n    }\n\n\
    \    return closed_interval<T>(l, r);\n  }\n\n  template <typename T>\n  auto\
    \ left_expand(closed_interval<T> a, T x) {\n    if (a.value and (a.value)->first)\
    \ {\n      *((a.value)->first) += x;\n      if ((a.value)->second and *((a.value)->first)\
    \ > *((a.value)->second)) {\n        return closed_interval<T>();\n      }\n \
    \   }\n\n    return a;\n  }\n\n  template <typename T>\n  auto right_expand(closed_interval<T>\
    \ a, T x) {\n    if (a.value and (a.value)->second) {\n      *((a.value)->second)\
    \ += x;\n      if ((a.value)->first and *((a.value)->first) > *((a.value)->second))\
    \ {\n        return closed_interval<T>();\n      }\n    }\n\n    return a;\n \
    \ }\n\n  template <typename T>\n  auto operator+(closed_interval<T> a, T k) {\n\
    \    if (a.value) {\n      if (a.value->first) a.value->first.value() += k;\n\
    \      if (a.value->second) a.value->second.value() += k;\n    }\n    return a;\n\
    \  }\n\n  template <typename T>\n  auto operator-(closed_interval<T> a, T k) {\n\
    \    if (a.value) {\n      if (a.value->first) a.value->first.value() -= k;\n\
    \      if (a.value->second) a.value->second.value() -= k;\n    }\n    return a;\n\
    \  }\n\n  template <typename T>\n  auto operator*(closed_interval<T> a, T k) {\n\
    \    if (a.value) {\n      if (k < 0) std::swap(a.value->first, a.value->second);\n\
    \      if (a.value->first) a.value->first.value() *= k;\n      if (a.value->second)\
    \ a.value->second.value() *= k;\n    }\n    return a;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Math/closed_interval.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Math/closed_interval.cpp
layout: document
title: Closed interval
---

## Operations

一つの閉区間を管理する。

- `is_null()`
  - 区間が空であるかを判定する。
- `contains(a)`
  - 区間に点`a`が含まれるかを判定する。

- `intersect(a, b)`
  - 区間`a`と`b`の共通部分を得る。
- `left_expand(a, x)`
  - 区間`a`の左端を`x`だけ伸縮したものを返す。
- `right_expand(a, x)`
  - 区間`a`の右端を`x`だけ伸縮したものを返す。

## Requirements

## Notes

## Problems

## References
