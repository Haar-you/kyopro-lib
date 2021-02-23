---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1102/main.test.cpp
    title: test/aoj/1102/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1300/main.test.cpp
    title: test/aoj/1300/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2401/main.test.cpp
    title: test/aoj/2401/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Parser/parser.cpp\"\n#include <string>\n#include <cassert>\n\
    \nnamespace haar_lib {\n  struct parser {\n    using state = std::string::const_iterator;\n\
    \n    state cur, first, last;\n\n    parser(){}\n    parser(const std::string\
    \ &s): cur(s.cbegin()), first(s.cbegin()), last(s.cend()){}\n\n    char peek()\
    \ const {return *cur;}\n\n    bool check(char c) const {\n      return *cur ==\
    \ c;\n    }\n\n    bool check(const std::string &s) const {\n      state temp\
    \ = cur;\n      for(auto c : s){\n        if(c != *temp) return false;\n     \
    \   ++temp;\n      }\n      return true;\n    }\n\n    void ignore(char c){\n\
    \      assert(*cur == c);\n      ++cur;\n    }\n\n    void ignore(){\n      ++cur;\n\
    \    }\n\n    void ignore(const std::string &s){\n      for(auto c : s){\n   \
    \     assert(*cur == c);\n        ++cur;\n      }\n    }\n\n    template <class\
    \ Checker>\n    void ignore_if(const Checker &f){\n      assert(f(*cur));\n  \
    \    ++cur;\n    }\n\n    bool check_and_ignore(char c){\n      if(*cur != c)\
    \ return false;\n      ++cur;\n      return true;\n    }\n\n    bool end() const\
    \ {return cur == last;}\n    bool digit() const {return isdigit(*cur);}\n    bool\
    \ alpha() const {return isalpha(*cur);}\n    bool lower() const {return islower(*cur);}\n\
    \    bool upper() const {return isupper(*cur);}\n\n    char get_char(){\n    \
    \  return *(cur++);\n    }\n\n    int get_digit(){\n      return (int)(*(cur++)\
    \ - '0');\n    }\n\n    template <typename Checker>\n    auto get_string(const\
    \ Checker &f){\n      std::string ret;\n      while(f(peek())){\n        ret +=\
    \ peek();\n        ignore();\n      }\n      return ret;\n    }\n\n    auto get_string_alpha(){\n\
    \      std::string ret;\n      while(isalpha(*cur)){\n        ret += *cur;\n \
    \       ++cur;\n      }\n      return ret;\n    }\n\n    auto get_string_alnum(){\n\
    \      std::string ret;\n      while(isalnum(*cur)){\n        ret += *cur;\n \
    \       ++cur;\n      }\n      return ret;\n    }\n\n    template <typename T>\n\
    \    T get_number(){\n      T ret = get_digit();\n      while(digit()){\n    \
    \    (ret *= 10) += (T)(get_digit());\n      }\n      return ret;\n    }\n  };\n\
    }\n"
  code: "#pragma once\n#include <string>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  struct parser {\n    using state = std::string::const_iterator;\n\n   \
    \ state cur, first, last;\n\n    parser(){}\n    parser(const std::string &s):\
    \ cur(s.cbegin()), first(s.cbegin()), last(s.cend()){}\n\n    char peek() const\
    \ {return *cur;}\n\n    bool check(char c) const {\n      return *cur == c;\n\
    \    }\n\n    bool check(const std::string &s) const {\n      state temp = cur;\n\
    \      for(auto c : s){\n        if(c != *temp) return false;\n        ++temp;\n\
    \      }\n      return true;\n    }\n\n    void ignore(char c){\n      assert(*cur\
    \ == c);\n      ++cur;\n    }\n\n    void ignore(){\n      ++cur;\n    }\n\n \
    \   void ignore(const std::string &s){\n      for(auto c : s){\n        assert(*cur\
    \ == c);\n        ++cur;\n      }\n    }\n\n    template <class Checker>\n   \
    \ void ignore_if(const Checker &f){\n      assert(f(*cur));\n      ++cur;\n  \
    \  }\n\n    bool check_and_ignore(char c){\n      if(*cur != c) return false;\n\
    \      ++cur;\n      return true;\n    }\n\n    bool end() const {return cur ==\
    \ last;}\n    bool digit() const {return isdigit(*cur);}\n    bool alpha() const\
    \ {return isalpha(*cur);}\n    bool lower() const {return islower(*cur);}\n  \
    \  bool upper() const {return isupper(*cur);}\n\n    char get_char(){\n      return\
    \ *(cur++);\n    }\n\n    int get_digit(){\n      return (int)(*(cur++) - '0');\n\
    \    }\n\n    template <typename Checker>\n    auto get_string(const Checker &f){\n\
    \      std::string ret;\n      while(f(peek())){\n        ret += peek();\n   \
    \     ignore();\n      }\n      return ret;\n    }\n\n    auto get_string_alpha(){\n\
    \      std::string ret;\n      while(isalpha(*cur)){\n        ret += *cur;\n \
    \       ++cur;\n      }\n      return ret;\n    }\n\n    auto get_string_alnum(){\n\
    \      std::string ret;\n      while(isalnum(*cur)){\n        ret += *cur;\n \
    \       ++cur;\n      }\n      return ret;\n    }\n\n    template <typename T>\n\
    \    T get_number(){\n      T ret = get_digit();\n      while(digit()){\n    \
    \    (ret *= 10) += (T)(get_digit());\n      }\n      return ret;\n    }\n  };\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Parser/parser.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1102/main.test.cpp
  - test/aoj/2401/main.test.cpp
  - test/aoj/1300/main.test.cpp
documentation_of: Mylib/Parser/parser.cpp
layout: document
title: Parsing
---

## Operations

## Requirements

## Notes

## Problems

## References
