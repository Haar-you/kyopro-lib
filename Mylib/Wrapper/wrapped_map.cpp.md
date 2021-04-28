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
  bundledCode: "#line 2 \"Mylib/Wrapper/wrapped_map.cpp\"\n#include <algorithm>\n\
    #include <functional>\n#include <map>\n\nnamespace haar_lib {\n  template <typename\
    \ Key, typename Value, typename Compare = std::less<Key>>\n  class wrapped_map\
    \ : public std::map<Key, Value, Compare> {\n    using super = std::map<Key, Value,\
    \ Compare>;\n\n  public:\n    const auto &max_key() const {\n      assert(not\
    \ super::empty());\n      return *super::rbegin();\n    }\n\n    const auto &min_key()\
    \ const {\n      assert(not super::empty());\n      return *super::begin();\n\
    \    }\n\n    bool contains_key(const Key &x) const {\n      return super::find(x)\
    \ != super::end();\n    }\n\n    const auto &max_value() const {\n      assert(not\
    \ super::empty());\n      return *std::max_element(\n          super::begin(),\
    \ super::end(),\n          [](const auto &a, const auto &b) { return a.second\
    \ < b.second; });\n    }\n\n    const auto &min_value() const {\n      assert(not\
    \ super::empty());\n      return *std::min_element(\n          super::begin(),\
    \ super::end(),\n          [](const auto &a, const auto &b) { return a.second\
    \ < b.second; });\n    }\n\n    template <typename Predicate>\n    void erase_if(Predicate\
    \ pred) {\n      for (auto it = super::begin(); it != super::end();) {\n     \
    \   if (pred(it->first, it->second))\n          it = super::erase(it);\n     \
    \   else\n          ++it;\n      }\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <functional>\n#include <map>\n\
    \nnamespace haar_lib {\n  template <typename Key, typename Value, typename Compare\
    \ = std::less<Key>>\n  class wrapped_map : public std::map<Key, Value, Compare>\
    \ {\n    using super = std::map<Key, Value, Compare>;\n\n  public:\n    const\
    \ auto &max_key() const {\n      assert(not super::empty());\n      return *super::rbegin();\n\
    \    }\n\n    const auto &min_key() const {\n      assert(not super::empty());\n\
    \      return *super::begin();\n    }\n\n    bool contains_key(const Key &x) const\
    \ {\n      return super::find(x) != super::end();\n    }\n\n    const auto &max_value()\
    \ const {\n      assert(not super::empty());\n      return *std::max_element(\n\
    \          super::begin(), super::end(),\n          [](const auto &a, const auto\
    \ &b) { return a.second < b.second; });\n    }\n\n    const auto &min_value()\
    \ const {\n      assert(not super::empty());\n      return *std::min_element(\n\
    \          super::begin(), super::end(),\n          [](const auto &a, const auto\
    \ &b) { return a.second < b.second; });\n    }\n\n    template <typename Predicate>\n\
    \    void erase_if(Predicate pred) {\n      for (auto it = super::begin(); it\
    \ != super::end();) {\n        if (pred(it->first, it->second))\n          it\
    \ = super::erase(it);\n        else\n          ++it;\n      }\n    }\n  };\n}\
    \  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Wrapper/wrapped_map.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Wrapper/wrapped_map.cpp
layout: document
title: null
---

## Operations

## Requirements

## Notes

## Problems

## References
