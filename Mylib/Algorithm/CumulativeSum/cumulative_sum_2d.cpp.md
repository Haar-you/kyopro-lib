---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/755/main.test.cpp
    title: test/yukicoder/755/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/CumulativeSum/cumulative_sum_2d.cpp\"\n\
    #include <vector>\n#include <functional>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Add = std::plus<T>, typename Minus = std::minus<T>>\n\
    \  class cumulative_sum_2d {\n    std::vector<std::vector<T>> data;\n    int N,\
    \ M;\n    Add add;\n    Minus minus;\n    bool is_built = false;\n\n  public:\n\
    \    cumulative_sum_2d(){}\n    cumulative_sum_2d(int N, int M, const T &e = 0,\
    \ const Add &add = Add(), const Minus &minus = Minus()):\n      N(N), M(M), add(add),\
    \ minus(minus)\n    {\n      data.assign(N + 1, std::vector<T>(M + 1, e));\n \
    \   }\n\n    auto& update(const std::vector<std::vector<T>> &a){\n      assert(not\
    \ is_built);\n      for(int i = 0; i < N; ++i){\n        for(int j = 0; j < M;\
    \ ++j){\n          data[i + 1][j + 1] = add(data[i + 1][j + 1], a[i][j]);\n  \
    \      }\n      }\n      return *this;\n    }\n\n    auto& update(int i, int j,\
    \ const T &val){\n      assert(not is_built);\n      data[i + 1][j + 1] = add(data[i\
    \ + 1][j + 1], val);\n      return *this;\n    }\n\n    auto& build(){\n     \
    \ assert(not is_built);\n      for(int i = 1; i <= N; ++i) for(int j = 0; j <=\
    \ M; ++j) data[i][j] = add(data[i][j], data[i - 1][j]);\n      for(int i = 0;\
    \ i <= N; ++i) for(int j = 1; j <= M; ++j) data[i][j] = add(data[i][j], data[i][j\
    \ - 1]);\n      is_built = true;\n      return *this;\n    }\n\n    T fold(std::pair<int,\
    \ int> p1, std::pair<int, int> p2) const { // [x1, x2), [y1, y2)\n      assert(is_built);\n\
    \      const auto [x1, y1] = p1;\n      const auto [x2, y2] = p2;\n      return\
    \ add(minus(data[x2][y2], add(data[x1][y2], data[x2][y1])), data[x1][y1]);\n \
    \   }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <functional>\n#include <cassert>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Add = std::plus<T>, typename\
    \ Minus = std::minus<T>>\n  class cumulative_sum_2d {\n    std::vector<std::vector<T>>\
    \ data;\n    int N, M;\n    Add add;\n    Minus minus;\n    bool is_built = false;\n\
    \n  public:\n    cumulative_sum_2d(){}\n    cumulative_sum_2d(int N, int M, const\
    \ T &e = 0, const Add &add = Add(), const Minus &minus = Minus()):\n      N(N),\
    \ M(M), add(add), minus(minus)\n    {\n      data.assign(N + 1, std::vector<T>(M\
    \ + 1, e));\n    }\n\n    auto& update(const std::vector<std::vector<T>> &a){\n\
    \      assert(not is_built);\n      for(int i = 0; i < N; ++i){\n        for(int\
    \ j = 0; j < M; ++j){\n          data[i + 1][j + 1] = add(data[i + 1][j + 1],\
    \ a[i][j]);\n        }\n      }\n      return *this;\n    }\n\n    auto& update(int\
    \ i, int j, const T &val){\n      assert(not is_built);\n      data[i + 1][j +\
    \ 1] = add(data[i + 1][j + 1], val);\n      return *this;\n    }\n\n    auto&\
    \ build(){\n      assert(not is_built);\n      for(int i = 1; i <= N; ++i) for(int\
    \ j = 0; j <= M; ++j) data[i][j] = add(data[i][j], data[i - 1][j]);\n      for(int\
    \ i = 0; i <= N; ++i) for(int j = 1; j <= M; ++j) data[i][j] = add(data[i][j],\
    \ data[i][j - 1]);\n      is_built = true;\n      return *this;\n    }\n\n   \
    \ T fold(std::pair<int, int> p1, std::pair<int, int> p2) const { // [x1, x2),\
    \ [y1, y2)\n      assert(is_built);\n      const auto [x1, y1] = p1;\n      const\
    \ auto [x2, y2] = p2;\n      return add(minus(data[x2][y2], add(data[x1][y2],\
    \ data[x2][y1])), data[x1][y1]);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/CumulativeSum/cumulative_sum_2d.cpp
  requiredBy: []
  timestamp: '2020-09-25 01:38:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/755/main.test.cpp
documentation_of: Mylib/Algorithm/CumulativeSum/cumulative_sum_2d.cpp
layout: document
title: 2D cumulative sum
---

## Operations

## Requirements

## Notes

## Problems

## References
