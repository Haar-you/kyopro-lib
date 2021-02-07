---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/ShortestPath/bellman_ford.cpp
    title: Bellman-Ford algorithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_B/main.test.cpp
    title: test/aoj/GRL_1_B/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Math/unbounded.cpp\"\n#include <iostream>\n\ntemplate\
    \ <typename T>\nstruct unbounded {\nprivate:\n  enum class tag_t { POSITIVE_INFINITY,\
    \ NEGATIVE_INFINITY, FINITE } tag_;\n  T value_;\n\n  unbounded(tag_t tag_): tag_(tag_){}\n\
    \npublic:\n  using value_type = T;\n\n  unbounded(): tag_(tag_t::FINITE), value_(T()){}\n\
    \  unbounded(T value_): tag_(tag_t::FINITE), value_(value_){}\n  unbounded(const\
    \ unbounded<T> &that): tag_(that.tag_), value_(that.value_){}\n\n  bool is_positive_inf()\
    \ const {return tag_ == tag_t::POSITIVE_INFINITY;}\n  bool is_negative_inf() const\
    \ {return tag_ == tag_t::NEGATIVE_INFINITY;}\n  bool is_finite() const {return\
    \ tag_ == tag_t::FINITE;}\n\n  T value() const {return value_;}\n  T& value(){return\
    \ value_;}\n\n  static auto positive_inf(){\n    return unbounded(tag_t::POSITIVE_INFINITY);\n\
    \  }\n\n  static auto negative_inf(){\n    return unbounded(tag_t::NEGATIVE_INFINITY);\n\
    \  }\n\n  friend std::ostream& operator<<(std::ostream &s, const unbounded &a){\n\
    \    switch(a.tag_){\n    case tag_t::POSITIVE_INFINITY: s << \"\u221E\"; break;\n\
    \    case tag_t::NEGATIVE_INFINITY: s << \"-\u221E\"; break;\n    case tag_t::FINITE:\
    \ s << a.value_;\n    }\n    return s;\n  }\n\n  unbounded operator-() const {\n\
    \    if(is_finite()) return -value_;\n    else if(is_positive_inf()) return unbounded::negative_inf();\n\
    \    return unbounded::positive_inf();\n  }\n\n  auto& operator+=(unbounded that){\n\
    \    if(is_finite()){\n      if(that.is_finite()) value_ += that.value_;\n   \
    \   else tag_ = that.tag_;\n    }\n    return *this;\n  }\n\n  auto operator+(unbounded\
    \ that) const {\n    return unbounded(*this) += that;\n  }\n\n  auto& operator-=(unbounded\
    \ that){\n    return (*this) += (-that);\n  }\n\n  auto operator-(unbounded that)\
    \ const {\n    return unbounded(*this) -= that;\n  }\n\n  int compare(unbounded\
    \ that) const {\n    if(is_positive_inf()){\n      if(that.is_positive_inf())\
    \ return 0;\n      else return 1;\n    }else if(is_negative_inf()){\n      if(that.is_negative_inf())\
    \ return 0;\n      else return -1;\n    }else{\n      if(that.is_positive_inf())\
    \ return -1;\n      else if(that.is_negative_inf()) return 1;\n      else return\
    \ (value_ > that.value_) - (value_ < that.value_);\n    }\n  }\n\n  bool operator==(unbounded\
    \ that) const {return compare(that) == 0;}\n  bool operator!=(unbounded that)\
    \ const {return compare(that) != 0;}\n  bool operator<(unbounded that) const {return\
    \ compare(that) < 0;}\n  bool operator<=(unbounded that) const {return compare(that)\
    \ <= 0;}\n  bool operator>(unbounded that) const {return compare(that) > 0;}\n\
    \  bool operator>=(unbounded that) const {return compare(that) >= 0;}\n};\n"
  code: "#pragma once\n#include <iostream>\n\ntemplate <typename T>\nstruct unbounded\
    \ {\nprivate:\n  enum class tag_t { POSITIVE_INFINITY, NEGATIVE_INFINITY, FINITE\
    \ } tag_;\n  T value_;\n\n  unbounded(tag_t tag_): tag_(tag_){}\n\npublic:\n \
    \ using value_type = T;\n\n  unbounded(): tag_(tag_t::FINITE), value_(T()){}\n\
    \  unbounded(T value_): tag_(tag_t::FINITE), value_(value_){}\n  unbounded(const\
    \ unbounded<T> &that): tag_(that.tag_), value_(that.value_){}\n\n  bool is_positive_inf()\
    \ const {return tag_ == tag_t::POSITIVE_INFINITY;}\n  bool is_negative_inf() const\
    \ {return tag_ == tag_t::NEGATIVE_INFINITY;}\n  bool is_finite() const {return\
    \ tag_ == tag_t::FINITE;}\n\n  T value() const {return value_;}\n  T& value(){return\
    \ value_;}\n\n  static auto positive_inf(){\n    return unbounded(tag_t::POSITIVE_INFINITY);\n\
    \  }\n\n  static auto negative_inf(){\n    return unbounded(tag_t::NEGATIVE_INFINITY);\n\
    \  }\n\n  friend std::ostream& operator<<(std::ostream &s, const unbounded &a){\n\
    \    switch(a.tag_){\n    case tag_t::POSITIVE_INFINITY: s << \"\u221E\"; break;\n\
    \    case tag_t::NEGATIVE_INFINITY: s << \"-\u221E\"; break;\n    case tag_t::FINITE:\
    \ s << a.value_;\n    }\n    return s;\n  }\n\n  unbounded operator-() const {\n\
    \    if(is_finite()) return -value_;\n    else if(is_positive_inf()) return unbounded::negative_inf();\n\
    \    return unbounded::positive_inf();\n  }\n\n  auto& operator+=(unbounded that){\n\
    \    if(is_finite()){\n      if(that.is_finite()) value_ += that.value_;\n   \
    \   else tag_ = that.tag_;\n    }\n    return *this;\n  }\n\n  auto operator+(unbounded\
    \ that) const {\n    return unbounded(*this) += that;\n  }\n\n  auto& operator-=(unbounded\
    \ that){\n    return (*this) += (-that);\n  }\n\n  auto operator-(unbounded that)\
    \ const {\n    return unbounded(*this) -= that;\n  }\n\n  int compare(unbounded\
    \ that) const {\n    if(is_positive_inf()){\n      if(that.is_positive_inf())\
    \ return 0;\n      else return 1;\n    }else if(is_negative_inf()){\n      if(that.is_negative_inf())\
    \ return 0;\n      else return -1;\n    }else{\n      if(that.is_positive_inf())\
    \ return -1;\n      else if(that.is_negative_inf()) return 1;\n      else return\
    \ (value_ > that.value_) - (value_ < that.value_);\n    }\n  }\n\n  bool operator==(unbounded\
    \ that) const {return compare(that) == 0;}\n  bool operator!=(unbounded that)\
    \ const {return compare(that) != 0;}\n  bool operator<(unbounded that) const {return\
    \ compare(that) < 0;}\n  bool operator<=(unbounded that) const {return compare(that)\
    \ <= 0;}\n  bool operator>(unbounded that) const {return compare(that) > 0;}\n\
    \  bool operator>=(unbounded that) const {return compare(that) >= 0;}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Math/unbounded.cpp
  requiredBy:
  - Mylib/Graph/ShortestPath/bellman_ford.cpp
  timestamp: '2020-10-07 09:46:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_B/main.test.cpp
documentation_of: Mylib/Math/unbounded.cpp
layout: document
title: Number with infinity
---

## Operations

## Requirements

## Notes

## Problems

## References
