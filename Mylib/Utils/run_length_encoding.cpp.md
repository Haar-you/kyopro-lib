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
  bundledCode: "#line 2 \"Mylib/Utils/run_length_encoding.cpp\"\n#include <vector>\n\
    #include <utility>\n#include <cstdint>\n\nnamespace haar_lib {\n  template <typename\
    \ Container, typename T = typename Container::value_type>\n  auto run_length_encoding(const\
    \ Container &v) -> std::vector<std::pair<T, int64_t>> {\n    std::vector<std::pair<T,\
    \ int64_t>> ret;\n\n    for(auto &x : v){\n      if(ret.empty()) ret.emplace_back(x,\
    \ 1);\n      else if(ret.back().first == x) ++ret.back().second;\n      else ret.emplace_back(x,\
    \ 1);\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <cstdint>\n\
    \nnamespace haar_lib {\n  template <typename Container, typename T = typename\
    \ Container::value_type>\n  auto run_length_encoding(const Container &v) -> std::vector<std::pair<T,\
    \ int64_t>> {\n    std::vector<std::pair<T, int64_t>> ret;\n\n    for(auto &x\
    \ : v){\n      if(ret.empty()) ret.emplace_back(x, 1);\n      else if(ret.back().first\
    \ == x) ++ret.back().second;\n      else ret.emplace_back(x, 1);\n    }\n\n  \
    \  return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Utils/run_length_encoding.cpp
  requiredBy: []
  timestamp: '2021-03-13 04:56:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Utils/run_length_encoding.cpp
layout: document
title: Run length encoding
---

## Operations

## Requirements

## Notes

## Problems

## References
