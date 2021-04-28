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
  bundledCode: "#line 2 \"Mylib/DataStructure/Set/integer_set.cpp\"\n#include <iterator>\n\
    #include <map>\n#include <optional>\n\nnamespace haar_lib {\n  class integer_set\
    \ {\n    std::map<int64_t, int64_t> data_;\n    using citer = typename std::map<int64_t,\
    \ int64_t>::const_iterator;\n\n    std::optional<citer> get_interval(int64_t x)\
    \ const {\n      if (data_.empty()) return std::nullopt;\n      auto next = data_.lower_bound(x);\n\
    \      if (next == data_.end()) {\n        auto prev = std::prev(next);\n    \
    \    if (x <= prev->second) return {prev};\n        return std::nullopt;\n   \
    \   }\n      if (next->first == x) return {next};\n      if (next == data_.begin())\
    \ return std::nullopt;\n      auto prev = std::prev(next);\n      if (x <= prev->second)\
    \ return {prev};\n      return std::nullopt;\n    }\n\n  public:\n    integer_set()\
    \ {}\n\n    bool contains(int64_t x) const {\n      return (bool) get_interval(x);\n\
    \    }\n\n    void add(int64_t x) {\n      if (data_.empty()) {\n        data_[x]\
    \ = x;\n        return;\n      }\n\n      auto next = data_.lower_bound(x);\n\
    \      if (next == data_.end()) {\n        auto prev = std::prev(next);\n    \
    \    if (x <= prev->second) return;\n        if (prev->second + 1 == x) {\n  \
    \        prev->second = x;\n        } else {\n          data_[x] = x;\n      \
    \  }\n        return;\n      }\n      if (next->first == x) return;\n\n      if\
    \ (next == data_.begin()) {\n        if (x + 1 == next->first) {\n          auto\
    \ t = next->second;\n          data_.erase(next);\n          data_[x] = t;\n \
    \       } else {\n          data_[x] = x;\n        }\n        return;\n      }\n\
    \n      auto prev = std::prev(next);\n      if (x <= prev->second) return;\n \
    \     if (prev->second + 1 == x) {\n        prev->second = x;\n\n        if (prev->second\
    \ + 1 == next->first) {\n          prev->second = next->second;\n          data_.erase(next);\n\
    \        }\n      } else if (x + 1 == next->first) {\n        auto t = next->second;\n\
    \        data_.erase(next);\n        data_[x] = t;\n      } else {\n        data_[x]\
    \ = x;\n      }\n\n      return;\n    }\n\n    void erase(int64_t x) {\n     \
    \ const auto res = get_interval(x);\n      if (res) {\n        const auto it \
    \    = res.value();\n        const auto [l, r] = *it;\n        data_.erase(it);\n\
    \        if (l <= x - 1) data_[l] = x - 1;\n        if (x + 1 <= r) data_[x +\
    \ 1] = r;\n      }\n    }\n\n    int64_t mex(int64_t x) const {\n      auto res\
    \ = get_interval(x);\n      if (res) return (*res)->second + 1;\n      return\
    \ x;\n    }\n  };\n};  // namespace haar_lib\n"
  code: "#pragma once\n#include <iterator>\n#include <map>\n#include <optional>\n\n\
    namespace haar_lib {\n  class integer_set {\n    std::map<int64_t, int64_t> data_;\n\
    \    using citer = typename std::map<int64_t, int64_t>::const_iterator;\n\n  \
    \  std::optional<citer> get_interval(int64_t x) const {\n      if (data_.empty())\
    \ return std::nullopt;\n      auto next = data_.lower_bound(x);\n      if (next\
    \ == data_.end()) {\n        auto prev = std::prev(next);\n        if (x <= prev->second)\
    \ return {prev};\n        return std::nullopt;\n      }\n      if (next->first\
    \ == x) return {next};\n      if (next == data_.begin()) return std::nullopt;\n\
    \      auto prev = std::prev(next);\n      if (x <= prev->second) return {prev};\n\
    \      return std::nullopt;\n    }\n\n  public:\n    integer_set() {}\n\n    bool\
    \ contains(int64_t x) const {\n      return (bool) get_interval(x);\n    }\n\n\
    \    void add(int64_t x) {\n      if (data_.empty()) {\n        data_[x] = x;\n\
    \        return;\n      }\n\n      auto next = data_.lower_bound(x);\n      if\
    \ (next == data_.end()) {\n        auto prev = std::prev(next);\n        if (x\
    \ <= prev->second) return;\n        if (prev->second + 1 == x) {\n          prev->second\
    \ = x;\n        } else {\n          data_[x] = x;\n        }\n        return;\n\
    \      }\n      if (next->first == x) return;\n\n      if (next == data_.begin())\
    \ {\n        if (x + 1 == next->first) {\n          auto t = next->second;\n \
    \         data_.erase(next);\n          data_[x] = t;\n        } else {\n    \
    \      data_[x] = x;\n        }\n        return;\n      }\n\n      auto prev =\
    \ std::prev(next);\n      if (x <= prev->second) return;\n      if (prev->second\
    \ + 1 == x) {\n        prev->second = x;\n\n        if (prev->second + 1 == next->first)\
    \ {\n          prev->second = next->second;\n          data_.erase(next);\n  \
    \      }\n      } else if (x + 1 == next->first) {\n        auto t = next->second;\n\
    \        data_.erase(next);\n        data_[x] = t;\n      } else {\n        data_[x]\
    \ = x;\n      }\n\n      return;\n    }\n\n    void erase(int64_t x) {\n     \
    \ const auto res = get_interval(x);\n      if (res) {\n        const auto it \
    \    = res.value();\n        const auto [l, r] = *it;\n        data_.erase(it);\n\
    \        if (l <= x - 1) data_[l] = x - 1;\n        if (x + 1 <= r) data_[x +\
    \ 1] = r;\n      }\n    }\n\n    int64_t mex(int64_t x) const {\n      auto res\
    \ = get_interval(x);\n      if (res) return (*res)->second + 1;\n      return\
    \ x;\n    }\n  };\n};  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/Set/integer_set.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/DataStructure/Set/integer_set.cpp
layout: document
title: Integer set
---

## Operations

## Requirements

## Notes

## Problems

- [C - Neq Min](https://atcoder.jp/contests/hhkb2020/tasks/hhkb2020_c)

## References

- [https://rsk0315.hatenablog.com/entry/2020/10/11/125049](https://rsk0315.hatenablog.com/entry/2020/10/11/125049)
