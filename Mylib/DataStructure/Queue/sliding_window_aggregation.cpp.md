---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/queue_operate_all_composite/main.test.cpp
    title: test/yosupo-judge/queue_operate_all_composite/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/Queue/sliding_window_aggregation.cpp\"\
    \n#include <vector>\n#include <stack>\n#include <optional>\n\nnamespace haar_lib\
    \ {\n  template <typename Semigroup>\n  class sliding_window_aggregation {\n \
    \ public:\n    using value_type = typename Semigroup::value_type;\n\n  private:\n\
    \    Semigroup S_;\n\n    std::stack<value_type> front_stack_, back_stack_;\n\
    \    std::vector<value_type> front_sum_, back_sum_;\n\n    std::optional<value_type>\
    \ f(std::optional<value_type> a, std::optional<value_type> b) const {\n      if(a){\n\
    \        if(b) return {S_(*a, *b)};\n        else return {*a};\n      }else{\n\
    \        if(b) return {*b};\n        else return std::nullopt;\n      }\n    }\n\
    \n    std::optional<value_type> g(const std::vector<value_type> &a) const {\n\
    \      return a.empty() ? std::nullopt : std::optional(a.back());\n    }\n\n \
    \ public:\n    sliding_window_aggregation(){}\n\n    std::optional<value_type>\
    \ fold() const {\n      return f(g(front_sum_), g(back_sum_));\n    }\n\n    void\
    \ push(const value_type &value){\n      back_stack_.push(value);\n      back_sum_.push_back(f(g(back_sum_),\
    \ value).value());\n    }\n\n    void pop(){\n      if(front_stack_.empty()){\n\
    \        back_sum_.clear();\n\n        while(not back_stack_.empty()){\n     \
    \     const auto value = back_stack_.top(); back_stack_.pop();\n          front_stack_.push(value);\n\
    \          front_sum_.push_back(f(value, g(front_sum_)).value());\n        }\n\
    \      }\n\n      front_stack_.pop();\n      front_sum_.pop_back();\n    }\n \
    \ };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <stack>\n#include <optional>\n\n\
    namespace haar_lib {\n  template <typename Semigroup>\n  class sliding_window_aggregation\
    \ {\n  public:\n    using value_type = typename Semigroup::value_type;\n\n  private:\n\
    \    Semigroup S_;\n\n    std::stack<value_type> front_stack_, back_stack_;\n\
    \    std::vector<value_type> front_sum_, back_sum_;\n\n    std::optional<value_type>\
    \ f(std::optional<value_type> a, std::optional<value_type> b) const {\n      if(a){\n\
    \        if(b) return {S_(*a, *b)};\n        else return {*a};\n      }else{\n\
    \        if(b) return {*b};\n        else return std::nullopt;\n      }\n    }\n\
    \n    std::optional<value_type> g(const std::vector<value_type> &a) const {\n\
    \      return a.empty() ? std::nullopt : std::optional(a.back());\n    }\n\n \
    \ public:\n    sliding_window_aggregation(){}\n\n    std::optional<value_type>\
    \ fold() const {\n      return f(g(front_sum_), g(back_sum_));\n    }\n\n    void\
    \ push(const value_type &value){\n      back_stack_.push(value);\n      back_sum_.push_back(f(g(back_sum_),\
    \ value).value());\n    }\n\n    void pop(){\n      if(front_stack_.empty()){\n\
    \        back_sum_.clear();\n\n        while(not back_stack_.empty()){\n     \
    \     const auto value = back_stack_.top(); back_stack_.pop();\n          front_stack_.push(value);\n\
    \          front_sum_.push_back(f(value, g(front_sum_)).value());\n        }\n\
    \      }\n\n      front_stack_.pop();\n      front_sum_.pop_back();\n    }\n \
    \ };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/Queue/sliding_window_aggregation.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/queue_operate_all_composite/main.test.cpp
documentation_of: Mylib/DataStructure/Queue/sliding_window_aggregation.cpp
layout: document
title: Sliding window aggregation
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://scrapbox.io/data-structures/Sliding_Window_Aggregation](https://scrapbox.io/data-structures/Sliding_Window_Aggregation)
