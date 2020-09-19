---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/queue_operate_all_composite/main.test.cpp
    title: test/yosupo-judge/queue_operate_all_composite/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/Queue/sliding_window_aggregation.cpp\"\
    \n#include <vector>\n#include <stack>\n#include <optional>\n\nnamespace haar_lib\
    \ {\n  template <typename Semigroup>\n  class sliding_window_aggregation {\n \
    \   using value_type = typename Semigroup::value_type;\n    const static Semigroup\
    \ S;\n\n    std::stack<value_type> front_stack, back_stack;\n    std::vector<value_type>\
    \ front_sum, back_sum;\n\n    std::optional<value_type> f(std::optional<value_type>\
    \ a, std::optional<value_type> b) const {\n      if(a){\n        if(b) return\
    \ {S(*a, *b)};\n        else return {*a};\n      }else{\n        if(b) return\
    \ {*b};\n        else return {};\n      }\n    }\n\n    std::optional<value_type>\
    \ g(const std::vector<value_type> &a) const {\n      return a.empty() ? std::nullopt\
    \ : std::optional(a.back());\n    }\n\n  public:\n    sliding_window_aggregation(){}\n\
    \n    std::optional<value_type> fold() const {\n      return f(g(front_sum), g(back_sum));\n\
    \    }\n\n    void push(const value_type &value){\n      back_stack.push(value);\n\
    \      back_sum.push_back(f(g(back_sum), value).value());\n    }\n\n    void pop(){\n\
    \      if(front_stack.empty()){\n        back_sum.clear();\n\n        while(not\
    \ back_stack.empty()){\n          const auto value = back_stack.top(); back_stack.pop();\n\
    \          front_stack.push(value);\n          front_sum.push_back(f(value, g(front_sum)).value());\n\
    \        }\n      }\n\n      front_stack.pop();\n      front_sum.pop_back();\n\
    \    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <stack>\n#include <optional>\n\n\
    namespace haar_lib {\n  template <typename Semigroup>\n  class sliding_window_aggregation\
    \ {\n    using value_type = typename Semigroup::value_type;\n    const static\
    \ Semigroup S;\n\n    std::stack<value_type> front_stack, back_stack;\n    std::vector<value_type>\
    \ front_sum, back_sum;\n\n    std::optional<value_type> f(std::optional<value_type>\
    \ a, std::optional<value_type> b) const {\n      if(a){\n        if(b) return\
    \ {S(*a, *b)};\n        else return {*a};\n      }else{\n        if(b) return\
    \ {*b};\n        else return {};\n      }\n    }\n\n    std::optional<value_type>\
    \ g(const std::vector<value_type> &a) const {\n      return a.empty() ? std::nullopt\
    \ : std::optional(a.back());\n    }\n\n  public:\n    sliding_window_aggregation(){}\n\
    \n    std::optional<value_type> fold() const {\n      return f(g(front_sum), g(back_sum));\n\
    \    }\n\n    void push(const value_type &value){\n      back_stack.push(value);\n\
    \      back_sum.push_back(f(g(back_sum), value).value());\n    }\n\n    void pop(){\n\
    \      if(front_stack.empty()){\n        back_sum.clear();\n\n        while(not\
    \ back_stack.empty()){\n          const auto value = back_stack.top(); back_stack.pop();\n\
    \          front_stack.push(value);\n          front_sum.push_back(f(value, g(front_sum)).value());\n\
    \        }\n      }\n\n      front_stack.pop();\n      front_sum.pop_back();\n\
    \    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/Queue/sliding_window_aggregation.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
