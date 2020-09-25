---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/static_range_sum/main.test.cpp
    title: test/yosupo-judge/static_range_sum/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/CumulativeSum/cumulative_sum_1d.cpp\"\n\
    #include <vector>\n#include <functional>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Add = std::plus<T>, typename Minus = std::minus<T>>\n\
    \  class cumulative_sum_1d {\n    std::vector<T> data;\n    int N;\n    Add add;\n\
    \    Minus minus;\n    bool is_built = false;\n\n  public:\n    cumulative_sum_1d(){}\n\
    \    cumulative_sum_1d(\n      int N, const T &e = 0, const Add &add = Add(),\
    \ const Minus &minus = Minus()\n    ): N(N), add(add), minus(minus)\n    {\n \
    \     data.assign(N + 1, e);\n    }\n\n    auto& update(const std::vector<T> &a){\n\
    \      assert(not is_built);\n      for(int i = 0; i < N; ++i) data[i + 1] = add(data[i\
    \ + 1], a[i]);\n      return *this;\n    }\n\n    auto& update(int i, const T\
    \ &val){\n      assert(not is_built);\n      data[i + 1] = add(data[i + 1], val);\n\
    \      return *this;\n    }\n\n    auto& build(){\n      assert(not is_built);\n\
    \      for(int i = 0; i < N; ++i) data[i + 1] = add(data[i + 1], data[i]);\n \
    \     is_built = true;\n      return *this;\n    }\n\n    T fold(int l, int r)\
    \ const {\n      assert(is_built);\n      return minus(data[r], data[l]);\n  \
    \  }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <functional>\n#include <cassert>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Add = std::plus<T>, typename\
    \ Minus = std::minus<T>>\n  class cumulative_sum_1d {\n    std::vector<T> data;\n\
    \    int N;\n    Add add;\n    Minus minus;\n    bool is_built = false;\n\n  public:\n\
    \    cumulative_sum_1d(){}\n    cumulative_sum_1d(\n      int N, const T &e =\
    \ 0, const Add &add = Add(), const Minus &minus = Minus()\n    ): N(N), add(add),\
    \ minus(minus)\n    {\n      data.assign(N + 1, e);\n    }\n\n    auto& update(const\
    \ std::vector<T> &a){\n      assert(not is_built);\n      for(int i = 0; i < N;\
    \ ++i) data[i + 1] = add(data[i + 1], a[i]);\n      return *this;\n    }\n\n \
    \   auto& update(int i, const T &val){\n      assert(not is_built);\n      data[i\
    \ + 1] = add(data[i + 1], val);\n      return *this;\n    }\n\n    auto& build(){\n\
    \      assert(not is_built);\n      for(int i = 0; i < N; ++i) data[i + 1] = add(data[i\
    \ + 1], data[i]);\n      is_built = true;\n      return *this;\n    }\n\n    T\
    \ fold(int l, int r) const {\n      assert(is_built);\n      return minus(data[r],\
    \ data[l]);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/CumulativeSum/cumulative_sum_1d.cpp
  requiredBy: []
  timestamp: '2020-09-25 01:38:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/static_range_sum/main.test.cpp
documentation_of: Mylib/Algorithm/CumulativeSum/cumulative_sum_1d.cpp
layout: document
title: 1D cumulative sum
---

## Operations

## Requirements

## Notes

## Problems

## References
