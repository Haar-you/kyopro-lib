---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1084/main.test.cpp
    title: test/yukicoder/1084/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/Imos/linear_imos_1d.cpp\"\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  struct linear_imos_1d {\n \
    \   using value_type = T;\n\n    std::vector<T> vec_a, vec_a_end, vec_b, vec;\n\
    \    int n;\n\n    linear_imos_1d(int n):\n      vec_a(n + 1), vec_a_end(n + 1),\
    \ vec_b(n + 1), vec(n + 1), n(n){}\n\n    void add(int s, int t, const T &a, const\
    \ T &b){ // x \u2208 [s, t)\u306Bax+b\u3092\u52A0\u7B97\u3059\u308B\u3002\n  \
    \    vec_a[s + 1] += a;\n      vec_a[t] -= a;\n\n      vec_a_end[t] -= a * (t\
    \ - s - 1);\n\n      vec_b[s] += a * s + b;\n      vec_b[t] -= a * s + b;\n  \
    \  }\n\n    void build(){\n      for(int i = 0; i < n; ++i) vec_a[i + 1] += vec_a[i];\n\
    \      for(int i = 0; i <= n; ++i) vec_a[i] += vec_a_end[i];\n      for(int i\
    \ = 0; i < n; ++i) vec_a[i + 1] += vec_a[i];\n\n      for(int i = 0; i < n; ++i)\
    \ vec_b[i + 1] += vec_b[i];\n\n      for(int i = 0; i <= n; ++i) vec[i] = vec_a[i]\
    \ + vec_b[i];\n    }\n\n    T operator[](size_t i) const {return vec[i];}\n  };\n\
    }\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct linear_imos_1d {\n    using value_type = T;\n\n    std::vector<T>\
    \ vec_a, vec_a_end, vec_b, vec;\n    int n;\n\n    linear_imos_1d(int n):\n  \
    \    vec_a(n + 1), vec_a_end(n + 1), vec_b(n + 1), vec(n + 1), n(n){}\n\n    void\
    \ add(int s, int t, const T &a, const T &b){ // x \u2208 [s, t)\u306Bax+b\u3092\
    \u52A0\u7B97\u3059\u308B\u3002\n      vec_a[s + 1] += a;\n      vec_a[t] -= a;\n\
    \n      vec_a_end[t] -= a * (t - s - 1);\n\n      vec_b[s] += a * s + b;\n   \
    \   vec_b[t] -= a * s + b;\n    }\n\n    void build(){\n      for(int i = 0; i\
    \ < n; ++i) vec_a[i + 1] += vec_a[i];\n      for(int i = 0; i <= n; ++i) vec_a[i]\
    \ += vec_a_end[i];\n      for(int i = 0; i < n; ++i) vec_a[i + 1] += vec_a[i];\n\
    \n      for(int i = 0; i < n; ++i) vec_b[i + 1] += vec_b[i];\n\n      for(int\
    \ i = 0; i <= n; ++i) vec[i] = vec_a[i] + vec_b[i];\n    }\n\n    T operator[](size_t\
    \ i) const {return vec[i];}\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/Imos/linear_imos_1d.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1084/main.test.cpp
documentation_of: Mylib/Algorithm/Imos/linear_imos_1d.cpp
layout: document
title: 1D Imos algorithm (Linear addition)
---

## Operations

## Requirements

## Notes

## Problems

- [ARC 077 E - guruguru](https://atcoder.jp/contests/arc077/tasks/arc077_c)

## References

