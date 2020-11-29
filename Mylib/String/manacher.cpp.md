---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/enumerate_palindromes/main.manacher.test.cpp
    title: test/yosupo-judge/enumerate_palindromes/main.manacher.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/String/manacher.cpp\"\n#include <vector>\n#include\
    \ <optional>\n\nnamespace haar_lib {\n  template <typename Container>\n  std::vector<int>\
    \ manacher(const Container &s){\n    const int n = s.size();\n    std::vector<int>\
    \ ret(n);\n    int center = 0;\n\n    for(int cur = 0; cur < n; ++cur){\n    \
    \  int left = center - (cur - center);\n\n      if(left >= 0 and cur + ret[left]\
    \ < center + ret[center]){\n        ret[cur] = ret[left];\n      }else{\n    \
    \    int len = center + ret[center] - cur;\n        while(cur - len >= 0 and cur\
    \ + len < n and s[cur - len] == s[cur + len]) ++len;\n        ret[cur] = len;\n\
    \        center = cur;\n      }\n    }\n\n    return ret;\n  }\n\n  template <typename\
    \ Container>\n  std::vector<int> manacher_all(const Container &s){\n    using\
    \ T = typename Container::value_type;\n    const int N = s.size();\n    std::vector<int>\
    \ ret(2 * N - 1);\n\n    {\n      auto res = manacher(s);\n      for(int i = 0;\
    \ i < N; ++i){\n        ret[i * 2] = res[i] * 2 - 1;\n      }\n    }\n\n    {\n\
    \      std::vector<std::optional<T>> T;\n      for(int i = 0; i < N; ++i){\n \
    \       if(i) T.push_back(std::nullopt);\n        T.push_back(s[i]);\n      }\n\
    \n      auto res = manacher(T);\n      for(int i = 0; i < N - 1; ++i){\n     \
    \   ret[i * 2 + 1] = (res[i * 2 + 1] / 2) * 2;\n      }\n    }\n\n    return ret;\n\
    \  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <optional>\n\nnamespace haar_lib\
    \ {\n  template <typename Container>\n  std::vector<int> manacher(const Container\
    \ &s){\n    const int n = s.size();\n    std::vector<int> ret(n);\n    int center\
    \ = 0;\n\n    for(int cur = 0; cur < n; ++cur){\n      int left = center - (cur\
    \ - center);\n\n      if(left >= 0 and cur + ret[left] < center + ret[center]){\n\
    \        ret[cur] = ret[left];\n      }else{\n        int len = center + ret[center]\
    \ - cur;\n        while(cur - len >= 0 and cur + len < n and s[cur - len] == s[cur\
    \ + len]) ++len;\n        ret[cur] = len;\n        center = cur;\n      }\n  \
    \  }\n\n    return ret;\n  }\n\n  template <typename Container>\n  std::vector<int>\
    \ manacher_all(const Container &s){\n    using T = typename Container::value_type;\n\
    \    const int N = s.size();\n    std::vector<int> ret(2 * N - 1);\n\n    {\n\
    \      auto res = manacher(s);\n      for(int i = 0; i < N; ++i){\n        ret[i\
    \ * 2] = res[i] * 2 - 1;\n      }\n    }\n\n    {\n      std::vector<std::optional<T>>\
    \ T;\n      for(int i = 0; i < N; ++i){\n        if(i) T.push_back(std::nullopt);\n\
    \        T.push_back(s[i]);\n      }\n\n      auto res = manacher(T);\n      for(int\
    \ i = 0; i < N - 1; ++i){\n        ret[i * 2 + 1] = (res[i * 2 + 1] / 2) * 2;\n\
    \      }\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/manacher.cpp
  requiredBy: []
  timestamp: '2020-11-30 03:27:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/enumerate_palindromes/main.manacher.test.cpp
documentation_of: Mylib/String/manacher.cpp
layout: document
title: Manacher algorithm
---

## Operations

- `manacher(s)`
	- 各位置`i`を中心とした最長奇数長回文の片側長さ(回文長`L`に対して`L/2+1`)の配列を返す。

## Requirements

## Notes

## Problems

## References
