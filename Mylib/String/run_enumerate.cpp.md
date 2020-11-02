---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/String/z_algorithm.cpp
    title: Z-algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/runenumerate/main.test.cpp
    title: test/yosupo-judge/runenumerate/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/String/run_enumerate.cpp\"\n#include <string>\n#include\
    \ <tuple>\n#include <map>\n#include <utility>\n#include <algorithm>\n#line 2 \"\
    Mylib/String/z_algorithm.cpp\"\n#include <vector>\n#line 4 \"Mylib/String/z_algorithm.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Container>\n  std::vector<int>\
    \ z_algorithm(const Container &s){\n    const int n = s.size();\n    std::vector<int>\
    \ ret(n, 0);\n    int j = 0;\n\n    for(int i = 1; i < n; ++i){\n      if(i +\
    \ ret[i - j] < j + ret[j]){\n        ret[i] = ret[i - j];\n      }else{\n    \
    \    int k = std::max<int>(0, j + ret[j] - i);\n        while(i + k < n and s[k]\
    \ == s[i + k]) ++k;\n        ret[i] = k;\n        j = i;\n      }\n    }\n\n \
    \   ret[0] = n;\n\n    return ret;\n  }\n}\n#line 8 \"Mylib/String/run_enumerate.cpp\"\
    \n\nnamespace haar_lib {\n  namespace run_enumerate_impl {\n    auto aux(const\
    \ std::string &first, const std::string &second){\n      std::vector<std::tuple<int,\
    \ int, int>> ret;\n\n      const int N = first.size(), M = second.size();\n\n\
    \      auto a = z_algorithm(std::string(first.rbegin(), first.rend()));\n\n  \
    \    std::string t = second + '\\0' + first + second;\n      auto b = z_algorithm(t);\n\
    \n      for(int i = 1; i < N; ++i){\n        int l1 = a[i];\n        int l2 =\
    \ b[second.size() + first.size() - i + 1];\n\n        if(l1 + i == N or l2 ==\
    \ M or i > l1 + l2) continue;\n\n        int l = N - i - l1, r = N + l2;\n   \
    \     int t = i;\n        ret.emplace_back(t, l, r);\n      }\n\n      return\
    \ ret;\n    }\n\n    void run(std::string s, int left, std::vector<std::tuple<int,\
    \ int, int>> &ret){\n      if(s.size() == 1) return;\n\n      const int N = s.size();\n\
    \      const int m = N / 2;\n      const std::string first = s.substr(0, m), second\
    \ = s.substr(m);\n\n      {\n        auto res = aux(first, second);\n\n      \
    \  for(auto &[t, l, r] : res){\n          ret.emplace_back(t, left + l, left +\
    \ r);\n        }\n      }\n\n      {\n        auto res = aux(std::string(second.rbegin(),\
    \ second.rend()), std::string(first.rbegin(), first.rend()));\n\n        for(auto\
    \ &[t, l, r] : res){\n          ret.emplace_back(t, left + N - r, left + N - l);\n\
    \        }\n      }\n\n      run(first, left, ret);\n      run(second, left +\
    \ first.size(), ret);\n    }\n\n    void sub(std::string s, std::vector<std::tuple<int,\
    \ int, int>> &ret){\n      const int N = s.size();\n\n      {\n        auto a\
    \ = z_algorithm(s);\n\n        for(int i = 1; i < N; ++i){\n          if(i <=\
    \ a[i]){\n            ret.emplace_back(i, 0, i + a[i]);\n          }\n       \
    \ }\n      }\n\n      {\n        auto a = z_algorithm(std::string(s.rbegin(),\
    \ s.rend()));\n\n        for(int i = 1; i < N; ++i){\n          if(i <= a[i]){\n\
    \            ret.emplace_back(i, N - i - a[i], N);\n          }\n        }\n \
    \     }\n    }\n  }\n\n  auto run_enumerate(const std::string &s){\n    std::vector<std::tuple<int,\
    \ int, int>> ret;\n    run_enumerate_impl::run(s, 0, ret);\n    run_enumerate_impl::sub(s,\
    \ ret);\n\n    std::map<std::pair<int, int>, int> m;\n\n    for(auto &[t, l, r]\
    \ : ret){\n      auto p = std::make_pair(l, r);\n\n      if(m.find(p) != m.end()){\n\
    \        m[p] = std::min(m[p], t);\n      }else{\n        m[p] = t;\n      }\n\
    \    }\n\n    ret.clear();\n\n    for(auto &[p, t] : m){\n      ret.emplace_back(t,\
    \ p.first, p.second);\n    }\n\n    std::sort(ret.begin(), ret.end());\n    return\
    \ ret;\n  }\n}\n"
  code: "#pragma once\n#include <string>\n#include <tuple>\n#include <map>\n#include\
    \ <utility>\n#include <algorithm>\n#include \"Mylib/String/z_algorithm.cpp\"\n\
    \nnamespace haar_lib {\n  namespace run_enumerate_impl {\n    auto aux(const std::string\
    \ &first, const std::string &second){\n      std::vector<std::tuple<int, int,\
    \ int>> ret;\n\n      const int N = first.size(), M = second.size();\n\n     \
    \ auto a = z_algorithm(std::string(first.rbegin(), first.rend()));\n\n      std::string\
    \ t = second + '\\0' + first + second;\n      auto b = z_algorithm(t);\n\n   \
    \   for(int i = 1; i < N; ++i){\n        int l1 = a[i];\n        int l2 = b[second.size()\
    \ + first.size() - i + 1];\n\n        if(l1 + i == N or l2 == M or i > l1 + l2)\
    \ continue;\n\n        int l = N - i - l1, r = N + l2;\n        int t = i;\n \
    \       ret.emplace_back(t, l, r);\n      }\n\n      return ret;\n    }\n\n  \
    \  void run(std::string s, int left, std::vector<std::tuple<int, int, int>> &ret){\n\
    \      if(s.size() == 1) return;\n\n      const int N = s.size();\n      const\
    \ int m = N / 2;\n      const std::string first = s.substr(0, m), second = s.substr(m);\n\
    \n      {\n        auto res = aux(first, second);\n\n        for(auto &[t, l,\
    \ r] : res){\n          ret.emplace_back(t, left + l, left + r);\n        }\n\
    \      }\n\n      {\n        auto res = aux(std::string(second.rbegin(), second.rend()),\
    \ std::string(first.rbegin(), first.rend()));\n\n        for(auto &[t, l, r] :\
    \ res){\n          ret.emplace_back(t, left + N - r, left + N - l);\n        }\n\
    \      }\n\n      run(first, left, ret);\n      run(second, left + first.size(),\
    \ ret);\n    }\n\n    void sub(std::string s, std::vector<std::tuple<int, int,\
    \ int>> &ret){\n      const int N = s.size();\n\n      {\n        auto a = z_algorithm(s);\n\
    \n        for(int i = 1; i < N; ++i){\n          if(i <= a[i]){\n            ret.emplace_back(i,\
    \ 0, i + a[i]);\n          }\n        }\n      }\n\n      {\n        auto a =\
    \ z_algorithm(std::string(s.rbegin(), s.rend()));\n\n        for(int i = 1; i\
    \ < N; ++i){\n          if(i <= a[i]){\n            ret.emplace_back(i, N - i\
    \ - a[i], N);\n          }\n        }\n      }\n    }\n  }\n\n  auto run_enumerate(const\
    \ std::string &s){\n    std::vector<std::tuple<int, int, int>> ret;\n    run_enumerate_impl::run(s,\
    \ 0, ret);\n    run_enumerate_impl::sub(s, ret);\n\n    std::map<std::pair<int,\
    \ int>, int> m;\n\n    for(auto &[t, l, r] : ret){\n      auto p = std::make_pair(l,\
    \ r);\n\n      if(m.find(p) != m.end()){\n        m[p] = std::min(m[p], t);\n\
    \      }else{\n        m[p] = t;\n      }\n    }\n\n    ret.clear();\n\n    for(auto\
    \ &[p, t] : m){\n      ret.emplace_back(t, p.first, p.second);\n    }\n\n    std::sort(ret.begin(),\
    \ ret.end());\n    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/String/z_algorithm.cpp
  isVerificationFile: false
  path: Mylib/String/run_enumerate.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/runenumerate/main.test.cpp
documentation_of: Mylib/String/run_enumerate.cpp
layout: document
title: Run enumerate
---

## Operations

## Requirements

## Notes

## Problems

## References

- [http://pazzle1230.hatenablog.com/entry/2019/11/27/234632](http://pazzle1230.hatenablog.com/entry/2019/11/27/234632)
