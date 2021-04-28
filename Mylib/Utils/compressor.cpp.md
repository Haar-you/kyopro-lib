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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Utils/compressor.cpp\"\n#include <algorithm>\n#include\
    \ <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  class compressor\
    \ {\n    std::vector<T> data_;\n    template <typename>\n    friend class compressor_builder;\n\
    \n  public:\n    int get_index(const T &val) const {\n      return std::lower_bound(data_.begin(),\
    \ data_.end(), val) - data_.begin();\n    }\n\n    auto &compress(std::vector<T>\
    \ &vals) const {\n      for (auto &x : vals) x = get_index(x);\n      return *this;\n\
    \    }\n\n    auto &compress(T &val) const {\n      val = get_index(val);\n  \
    \    return *this;\n    }\n\n    template <typename U, typename... Args>\n   \
    \ auto &compress(U &val, Args &... args) const {\n      compress(val);\n     \
    \ return compress(args...);\n    }\n\n    auto &decompress(std::vector<T> &vals)\
    \ const {\n      for (auto &x : vals) x = data_[x];\n      return *this;\n   \
    \ }\n\n    auto &decompress(T &val) const {\n      val = data_[val];\n      return\
    \ *this;\n    }\n\n    template <typename U, typename... Args>\n    auto &decompress(U\
    \ &val, Args &... args) const {\n      decompress(val);\n      return decompress(args...);\n\
    \    }\n\n    int size() const { return data_.size(); }\n    T operator[](int\
    \ index) const { return data_[index]; }\n  };\n\n  template <typename T>\n  class\
    \ compressor_builder {\n    std::vector<T> data_;\n\n  public:\n    auto &add(const\
    \ T &val) {\n      data_.push_back(val);\n      return *this;\n    }\n\n    auto\
    \ &add(const std::vector<T> &vals) {\n      data_.insert(data_.end(), vals.begin(),\
    \ vals.end());\n      return *this;\n    }\n\n    template <typename U, typename...\
    \ Args>\n    auto &add(const U &val, const Args &... args) {\n      add(val);\n\
    \      return add(args...);\n    }\n\n    auto build() const {\n      compressor<T>\
    \ ret;\n      ret.data_ = data_;\n      std::sort(ret.data_.begin(), ret.data_.end());\n\
    \      ret.data_.erase(std::unique(ret.data_.begin(), ret.data_.end()), ret.data_.end());\n\
    \      return ret;\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  class compressor {\n    std::vector<T> data_;\n\
    \    template <typename>\n    friend class compressor_builder;\n\n  public:\n\
    \    int get_index(const T &val) const {\n      return std::lower_bound(data_.begin(),\
    \ data_.end(), val) - data_.begin();\n    }\n\n    auto &compress(std::vector<T>\
    \ &vals) const {\n      for (auto &x : vals) x = get_index(x);\n      return *this;\n\
    \    }\n\n    auto &compress(T &val) const {\n      val = get_index(val);\n  \
    \    return *this;\n    }\n\n    template <typename U, typename... Args>\n   \
    \ auto &compress(U &val, Args &... args) const {\n      compress(val);\n     \
    \ return compress(args...);\n    }\n\n    auto &decompress(std::vector<T> &vals)\
    \ const {\n      for (auto &x : vals) x = data_[x];\n      return *this;\n   \
    \ }\n\n    auto &decompress(T &val) const {\n      val = data_[val];\n      return\
    \ *this;\n    }\n\n    template <typename U, typename... Args>\n    auto &decompress(U\
    \ &val, Args &... args) const {\n      decompress(val);\n      return decompress(args...);\n\
    \    }\n\n    int size() const { return data_.size(); }\n    T operator[](int\
    \ index) const { return data_[index]; }\n  };\n\n  template <typename T>\n  class\
    \ compressor_builder {\n    std::vector<T> data_;\n\n  public:\n    auto &add(const\
    \ T &val) {\n      data_.push_back(val);\n      return *this;\n    }\n\n    auto\
    \ &add(const std::vector<T> &vals) {\n      data_.insert(data_.end(), vals.begin(),\
    \ vals.end());\n      return *this;\n    }\n\n    template <typename U, typename...\
    \ Args>\n    auto &add(const U &val, const Args &... args) {\n      add(val);\n\
    \      return add(args...);\n    }\n\n    auto build() const {\n      compressor<T>\
    \ ret;\n      ret.data_ = data_;\n      std::sort(ret.data_.begin(), ret.data_.end());\n\
    \      ret.data_.erase(std::unique(ret.data_.begin(), ret.data_.end()), ret.data_.end());\n\
    \      return ret;\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Utils/compressor.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
  - test/aoj/1337/main.test.cpp
documentation_of: Mylib/Utils/compressor.cpp
layout: document
title: Compressor
---

## Operations

## Requirements

## Notes

## Problems

## References
