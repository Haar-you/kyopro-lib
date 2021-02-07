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
  bundledCode: "#line 2 \"Mylib/Combinatorics/semifactorial.cpp\"\n#include <vector>\n\
    #include <cassert>\n\nnamespace haar_lib {\n  template <typename T>\n  class semifactorial\
    \ {\n  public:\n    using value_type = T;\n\n  private:\n    int N_;\n    std::vector<T>\
    \ data_;\n\n  public:\n    semifactorial(){}\n    semifactorial(int N): N_(N),\
    \ data_(N + 1, 1){\n      for(int i = 2; i <= N_; i += 2) data_[i] = data_[i -\
    \ 2] * i;\n      for(int i = 3; i <= N_; i += 2) data_[i] = data_[i - 2] * i;\n\
    \    }\n\n    T operator()(int i) const {\n      assert(0 <= i and i <= N_);\n\
    \      return data_[i];\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  class semifactorial {\n  public:\n    using value_type\
    \ = T;\n\n  private:\n    int N_;\n    std::vector<T> data_;\n\n  public:\n  \
    \  semifactorial(){}\n    semifactorial(int N): N_(N), data_(N + 1, 1){\n    \
    \  for(int i = 2; i <= N_; i += 2) data_[i] = data_[i - 2] * i;\n      for(int\
    \ i = 3; i <= N_; i += 2) data_[i] = data_[i - 2] * i;\n    }\n\n    T operator()(int\
    \ i) const {\n      assert(0 <= i and i <= N_);\n      return data_[i];\n    }\n\
    \  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Combinatorics/semifactorial.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Combinatorics/semifactorial.cpp
layout: document
title: Semifactorial
---

## Operations

## Requirements

## Notes

## Problems

- [F - Heights and Pairs](https://atcoder.jp/contests/abl/tasks/abl_f)

## References
