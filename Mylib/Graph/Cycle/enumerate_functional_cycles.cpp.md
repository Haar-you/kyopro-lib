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
  bundledCode: "#line 2 \"Mylib/Graph/Cycle/enumerate_functional_cycles.cpp\"\n#include\
    \ <algorithm>\n#include <optional>\n#include <vector>\n\nnamespace haar_lib {\n\
    \  namespace enumerate_functional_cycles_impl {\n    constexpr static int SEARCHED\
    \  = 1;\n    constexpr static int SEARCHING = 2;\n\n    std::optional<int> rec(\n\
    \        const std::vector<int> &g,\n        int cur,\n        std::vector<int>\
    \ &temp,\n        std::vector<std::vector<int>> &ret,\n        std::vector<int>\
    \ &check) {\n      if (check[cur] == SEARCHED) return std::nullopt;\n      if\
    \ (check[cur] == SEARCHING) return {cur};\n      check[cur] = SEARCHING;\n\n \
    \     const int i = g[cur];\n\n      if (auto res = rec(g, i, temp, ret, check);\
    \ res) {\n        if (*res != -1) {\n          temp.push_back(i);\n          if\
    \ (*res == cur) {\n            check[cur] = SEARCHED;\n            return {-1};\n\
    \          }\n        }\n\n        check[cur] = SEARCHED;\n        return res;\n\
    \      }\n\n      check[cur] = SEARCHED;\n      return std::nullopt;\n    }\n\
    \  }  // namespace enumerate_functional_cycles_impl\n\n  std::vector<std::vector<int>>\
    \ enumerate_functional_cycles(std::vector<int> g) {\n    const int n = g.size();\n\
    \n    std::vector<std::vector<int>> ret;\n    std::vector<int> check(n);\n\n \
    \   for (int i = 0; i < n; ++i) {\n      if (check[i] == 0) {\n        std::vector<int>\
    \ temp;\n        auto res = enumerate_functional_cycles_impl::rec(g, i, temp,\
    \ ret, check);\n        if (res) {\n          std::reverse(temp.begin(), temp.end());\n\
    \          ret.push_back(temp);\n        }\n      }\n    }\n\n    return ret;\n\
    \  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <optional>\n#include <vector>\n\
    \nnamespace haar_lib {\n  namespace enumerate_functional_cycles_impl {\n    constexpr\
    \ static int SEARCHED  = 1;\n    constexpr static int SEARCHING = 2;\n\n    std::optional<int>\
    \ rec(\n        const std::vector<int> &g,\n        int cur,\n        std::vector<int>\
    \ &temp,\n        std::vector<std::vector<int>> &ret,\n        std::vector<int>\
    \ &check) {\n      if (check[cur] == SEARCHED) return std::nullopt;\n      if\
    \ (check[cur] == SEARCHING) return {cur};\n      check[cur] = SEARCHING;\n\n \
    \     const int i = g[cur];\n\n      if (auto res = rec(g, i, temp, ret, check);\
    \ res) {\n        if (*res != -1) {\n          temp.push_back(i);\n          if\
    \ (*res == cur) {\n            check[cur] = SEARCHED;\n            return {-1};\n\
    \          }\n        }\n\n        check[cur] = SEARCHED;\n        return res;\n\
    \      }\n\n      check[cur] = SEARCHED;\n      return std::nullopt;\n    }\n\
    \  }  // namespace enumerate_functional_cycles_impl\n\n  std::vector<std::vector<int>>\
    \ enumerate_functional_cycles(std::vector<int> g) {\n    const int n = g.size();\n\
    \n    std::vector<std::vector<int>> ret;\n    std::vector<int> check(n);\n\n \
    \   for (int i = 0; i < n; ++i) {\n      if (check[i] == 0) {\n        std::vector<int>\
    \ temp;\n        auto res = enumerate_functional_cycles_impl::rec(g, i, temp,\
    \ ret, check);\n        if (res) {\n          std::reverse(temp.begin(), temp.end());\n\
    \          ret.push_back(temp);\n        }\n      }\n    }\n\n    return ret;\n\
    \  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/Cycle/enumerate_functional_cycles.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/Cycle/enumerate_functional_cycles.cpp
layout: document
title: Enumerate cycles in functional graph
---

## Operations

## Requirements

## Notes

## Problems

## References
