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
  bundledCode: "#line 2 \"Mylib/Wrapper/wrapped_set.cpp\"\n#include <functional>\n\
    #include <set>\n\nnamespace haar_lib {\n  template <typename T, typename Compare\
    \ = std::less<T>>\n  class wrapped_set : public std::set<T, Compare> {\n    using\
    \ super = std::set<T, Compare>;\n\n  public:\n    const T& max() const {\n   \
    \   assert(not super::empty());\n      return *super::rbegin();\n    }\n\n   \
    \ const T& min() const {\n      assert(not super::empty());\n      return *super::begin();\n\
    \    }\n\n    bool contains(const T& x) const {\n      return super::find(x) !=\
    \ super::end();\n    }\n\n    template <typename Predicate>\n    void erase_if(Predicate\
    \ pred) {\n      for (auto it = super::begin(); it != super::end();) {\n     \
    \   if (pred(*it))\n          it = super::erase(it);\n        else\n         \
    \ ++it;\n      }\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <functional>\n#include <set>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Compare = std::less<T>>\n  class wrapped_set\
    \ : public std::set<T, Compare> {\n    using super = std::set<T, Compare>;\n\n\
    \  public:\n    const T& max() const {\n      assert(not super::empty());\n  \
    \    return *super::rbegin();\n    }\n\n    const T& min() const {\n      assert(not\
    \ super::empty());\n      return *super::begin();\n    }\n\n    bool contains(const\
    \ T& x) const {\n      return super::find(x) != super::end();\n    }\n\n    template\
    \ <typename Predicate>\n    void erase_if(Predicate pred) {\n      for (auto it\
    \ = super::begin(); it != super::end();) {\n        if (pred(*it))\n         \
    \ it = super::erase(it);\n        else\n          ++it;\n      }\n    }\n  };\n\
    }  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Wrapper/wrapped_set.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Wrapper/wrapped_set.cpp
layout: document
title: null
---

## Operations

## Requirements

## Notes

## Problems

## References
