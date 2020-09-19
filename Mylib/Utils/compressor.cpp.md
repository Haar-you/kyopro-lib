---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1337/main.test.cpp
    title: test/aoj/1337/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
    title: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Utils/compressor.cpp\"\n#include <vector>\n#include\
    \ <algorithm>\n\nnamespace haar_lib {\n  template <typename T>\n  class compressor\
    \ {\n    std::vector<T> data;\n\n  public:\n    auto& add(const T &val){\n   \
    \   data.push_back(val);\n      return *this;\n    }\n\n    auto& add(const std::vector<T>\
    \ &vals){\n      data.insert(data.end(), vals.begin(), vals.end());\n      return\
    \ *this;\n    }\n\n    template <typename U, typename ... Args>\n    auto& add(const\
    \ U &val, const Args &... args){\n      add(val);\n      return add(args ...);\n\
    \    }\n\n    auto& build(){\n      std::sort(data.begin(), data.end());\n   \
    \   data.erase(std::unique(data.begin(), data.end()), data.end());\n      return\
    \ *this;\n    }\n\n    int get_index(const T &val) const {\n      return std::lower_bound(data.begin(),\
    \ data.end(), val) - data.begin();\n    }\n\n    auto& compress(std::vector<T>\
    \ &vals) const {\n      for(auto &x : vals) x = get_index(x);\n      return *this;\n\
    \    }\n\n    auto& compress(T &val) const {\n      val = get_index(val);\n  \
    \    return *this;\n    }\n\n    template <typename U, typename ... Args>\n  \
    \  auto& compress(U &val, Args &... args) const {\n      compress(val);\n    \
    \  return compress(args ...);\n    }\n\n    auto& decompress(std::vector<T> &vals)\
    \ const {\n      for(auto &x : vals) x = data[x];\n      return *this;\n    }\n\
    \n    auto& decompress(T &val) const {\n      val = data[val];\n      return *this;\n\
    \    }\n\n    template <typename U, typename ... Args>\n    auto& decompress(U\
    \ &val, Args &... args) const {\n      decompress(val);\n      return decompress(args\
    \ ...);\n    }\n\n    int size() const {return data.size();}\n    T operator[](int\
    \ index) const {return data[index];}\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  class compressor {\n    std::vector<T> data;\n\
    \n  public:\n    auto& add(const T &val){\n      data.push_back(val);\n      return\
    \ *this;\n    }\n\n    auto& add(const std::vector<T> &vals){\n      data.insert(data.end(),\
    \ vals.begin(), vals.end());\n      return *this;\n    }\n\n    template <typename\
    \ U, typename ... Args>\n    auto& add(const U &val, const Args &... args){\n\
    \      add(val);\n      return add(args ...);\n    }\n\n    auto& build(){\n \
    \     std::sort(data.begin(), data.end());\n      data.erase(std::unique(data.begin(),\
    \ data.end()), data.end());\n      return *this;\n    }\n\n    int get_index(const\
    \ T &val) const {\n      return std::lower_bound(data.begin(), data.end(), val)\
    \ - data.begin();\n    }\n\n    auto& compress(std::vector<T> &vals) const {\n\
    \      for(auto &x : vals) x = get_index(x);\n      return *this;\n    }\n\n \
    \   auto& compress(T &val) const {\n      val = get_index(val);\n      return\
    \ *this;\n    }\n\n    template <typename U, typename ... Args>\n    auto& compress(U\
    \ &val, Args &... args) const {\n      compress(val);\n      return compress(args\
    \ ...);\n    }\n\n    auto& decompress(std::vector<T> &vals) const {\n      for(auto\
    \ &x : vals) x = data[x];\n      return *this;\n    }\n\n    auto& decompress(T\
    \ &val) const {\n      val = data[val];\n      return *this;\n    }\n\n    template\
    \ <typename U, typename ... Args>\n    auto& decompress(U &val, Args &... args)\
    \ const {\n      decompress(val);\n      return decompress(args ...);\n    }\n\
    \n    int size() const {return data.size();}\n    T operator[](int index) const\
    \ {return data[index];}\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Utils/compressor.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/1337/main.test.cpp
  - test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
documentation_of: Mylib/Utils/compressor.cpp
layout: document
title: Compressor
---

## Operations

## Requirements

## Notes

## Problems

## References
