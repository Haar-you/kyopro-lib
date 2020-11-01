---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/Set/wrapped_set.cpp\"\n#include <set>\n\
    #include <functional>\n\nnamespace haar_lib {\n  template <typename T, typename\
    \ Compare = std::less<T>>\n  class wrapped_set : public std::set<T, Compare> {\n\
    \    using super = std::set<T, Compare>;\n\n  public:\n    const T& max() const\
    \ {\n      assert(not super::empty());\n      return *super::rbegin();\n    }\n\
    \n    const T& min() const {\n      assert(not super::empty());\n      return\
    \ *super::begin();\n    }\n\n    bool contains(const T &x) const {\n      return\
    \ super::find(x) != super::end();\n    }\n\n    template <typename Predicate>\n\
    \    void erase_if(Predicate pred){\n      for(auto it = super::begin(); it !=\
    \ super::end();){\n        if(pred(*it)) it = super::erase(it);\n        else\
    \ ++it;\n      }\n    }\n  };\n}\n"
  code: "#pragma once\n#include <set>\n#include <functional>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Compare = std::less<T>>\n  class wrapped_set\
    \ : public std::set<T, Compare> {\n    using super = std::set<T, Compare>;\n\n\
    \  public:\n    const T& max() const {\n      assert(not super::empty());\n  \
    \    return *super::rbegin();\n    }\n\n    const T& min() const {\n      assert(not\
    \ super::empty());\n      return *super::begin();\n    }\n\n    bool contains(const\
    \ T &x) const {\n      return super::find(x) != super::end();\n    }\n\n    template\
    \ <typename Predicate>\n    void erase_if(Predicate pred){\n      for(auto it\
    \ = super::begin(); it != super::end();){\n        if(pred(*it)) it = super::erase(it);\n\
    \        else ++it;\n      }\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/Set/wrapped_set.cpp
  requiredBy: []
  timestamp: '2020-10-29 12:52:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/DataStructure/Set/wrapped_set.cpp
layout: document
redirect_from:
- /library/Mylib/DataStructure/Set/wrapped_set.cpp
- /library/Mylib/DataStructure/Set/wrapped_set.cpp.html
title: Mylib/DataStructure/Set/wrapped_set.cpp
---
