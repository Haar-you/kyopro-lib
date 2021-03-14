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
  bundledCode: "#line 2 \"Mylib/DataStructure/Array/rollbackable_vector.cpp\"\n#include\
    \ <vector>\n#include <variant>\n#include <initializer_list>\n#include <utility>\n\
    #include <iostream>\n\nnamespace haar_lib {\n  template <typename T>\n  class\
    \ rollbackable_vector {\n  public:\n    using value_type = T;\n\n  private:\n\
    \    std::vector<T> data_;\n\n    using Update = std::pair<T, int>;\n    struct\
    \ PushBack {};\n    using PopBack = T;\n\n    std::vector<std::variant<Update,\
    \ PushBack, PopBack>> history_;\n\n  public:\n    rollbackable_vector(){}\n  \
    \  rollbackable_vector(size_t n): data_(n){}\n    rollbackable_vector(std::vector<T>\
    \ a): data_(a){}\n    rollbackable_vector(std::initializer_list<T> a): data_(a.begin(),\
    \ a.end()){}\n\n    void push_back(const T &value){\n      history_.push_back(PushBack());\n\
    \      data_.push_back(value);\n    }\n\n    void pop_back(){\n      history_.push_back(PopBack(data_.back()));\n\
    \      data_.pop_back();\n    }\n\n    void set(int i, const T &value){\n    \
    \  history_.push_back(Update(data_[i], i));\n      data_[i] = value;\n    }\n\n\
    \    void roll_back(){\n      if(std::holds_alternative<Update>(history_.back())){\n\
    \        auto [value, i] = std::get<Update>(history_.back());\n        data_[i]\
    \ = value;\n      }else if(std::holds_alternative<PushBack>(history_.back())){\n\
    \        data_.pop_back();\n      }else if(std::holds_alternative<PopBack>(history_.back())){\n\
    \        auto value = std::get<PopBack>(history_.back());\n        data_.push_back(value);\n\
    \      }\n\n      history_.pop_back();\n    }\n\n    bool rollbackable() const\
    \ {\n      return not history_.empty();\n    }\n\n    const value_type& operator[](int\
    \ i) const {return data_[i];}\n\n    auto cbegin() const {return data_.cbegin();}\n\
    \    auto cend() const {return data_.cend();}\n\n    int size() const {return\
    \ data_.size();}\n    bool empty() const {return data_.empty();}\n\n    const\
    \ T& back() const {return data_.back();}\n    const T& front() const {return data_.front();}\n\
    \n    const auto& data() const {return data_;}\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <variant>\n#include <initializer_list>\n\
    #include <utility>\n#include <iostream>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class rollbackable_vector {\n  public:\n    using value_type = T;\n\n\
    \  private:\n    std::vector<T> data_;\n\n    using Update = std::pair<T, int>;\n\
    \    struct PushBack {};\n    using PopBack = T;\n\n    std::vector<std::variant<Update,\
    \ PushBack, PopBack>> history_;\n\n  public:\n    rollbackable_vector(){}\n  \
    \  rollbackable_vector(size_t n): data_(n){}\n    rollbackable_vector(std::vector<T>\
    \ a): data_(a){}\n    rollbackable_vector(std::initializer_list<T> a): data_(a.begin(),\
    \ a.end()){}\n\n    void push_back(const T &value){\n      history_.push_back(PushBack());\n\
    \      data_.push_back(value);\n    }\n\n    void pop_back(){\n      history_.push_back(PopBack(data_.back()));\n\
    \      data_.pop_back();\n    }\n\n    void set(int i, const T &value){\n    \
    \  history_.push_back(Update(data_[i], i));\n      data_[i] = value;\n    }\n\n\
    \    void roll_back(){\n      if(std::holds_alternative<Update>(history_.back())){\n\
    \        auto [value, i] = std::get<Update>(history_.back());\n        data_[i]\
    \ = value;\n      }else if(std::holds_alternative<PushBack>(history_.back())){\n\
    \        data_.pop_back();\n      }else if(std::holds_alternative<PopBack>(history_.back())){\n\
    \        auto value = std::get<PopBack>(history_.back());\n        data_.push_back(value);\n\
    \      }\n\n      history_.pop_back();\n    }\n\n    bool rollbackable() const\
    \ {\n      return not history_.empty();\n    }\n\n    const value_type& operator[](int\
    \ i) const {return data_[i];}\n\n    auto cbegin() const {return data_.cbegin();}\n\
    \    auto cend() const {return data_.cend();}\n\n    int size() const {return\
    \ data_.size();}\n    bool empty() const {return data_.empty();}\n\n    const\
    \ T& back() const {return data_.back();}\n    const T& front() const {return data_.front();}\n\
    \n    const auto& data() const {return data_;}\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/Array/rollbackable_vector.cpp
  requiredBy: []
  timestamp: '2021-03-12 18:33:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/DataStructure/Array/rollbackable_vector.cpp
layout: document
title: Rollbackable vector
---

## Operations

## Requirements

## Notes

## Problems

- [ABC 165 F - LIS on Tree](https://atcoder.jp/contests/abc165/tasks/abc165_f)

## References

