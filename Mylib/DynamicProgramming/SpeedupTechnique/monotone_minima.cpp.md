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
  bundledCode: "#line 2 \"Mylib/DynamicProgramming/SpeedupTechnique/monotone_minima.cpp\"\
    \n#include <utility>\n#include <vector>\n\nnamespace haar_lib {\n  namespace monotone_minima_impl\
    \ {\n    template <typename T, typename F>\n    auto rec(\n        int N, int\
    \ M, const F &f, int top, int bottom, int left, int right,\n        std::vector<std::pair<int,\
    \ T>> &ret) {\n      if (top > bottom) return;\n      if (top == bottom) {\n \
    \       const int i = top;\n\n        int index = left;\n        T m       = f(i,\
    \ index);\n\n        for (int j = left; j <= right; ++j) {\n          const auto\
    \ temp = f(i, j);\n          if (temp < m) {\n            m     = temp;\n    \
    \        index = j;\n          }\n        }\n\n        ret[i] = std::make_pair(index,\
    \ m);\n        return;\n      }\n\n      const int mid = (top + bottom) / 2;\n\
    \      rec(N, M, f, mid, mid, left, right, ret);\n      rec(N, M, f, top, mid\
    \ - 1, left, ret[mid].first, ret);\n      rec(N, M, f, mid + 1, bottom, ret[mid].first,\
    \ right, ret);\n    }\n  }  // namespace monotone_minima_impl\n\n  template <typename\
    \ T, typename F>\n  auto monotone_minima(int N, int M, const F &f) {\n    std::vector<std::pair<int,\
    \ T>> ret(M);\n    monotone_minima_impl::rec<T, F>(N, M, f, 0, N - 1, 0, M - 1,\
    \ ret);\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  namespace monotone_minima_impl {\n    template <typename T, typename F>\n\
    \    auto rec(\n        int N, int M, const F &f, int top, int bottom, int left,\
    \ int right,\n        std::vector<std::pair<int, T>> &ret) {\n      if (top >\
    \ bottom) return;\n      if (top == bottom) {\n        const int i = top;\n\n\
    \        int index = left;\n        T m       = f(i, index);\n\n        for (int\
    \ j = left; j <= right; ++j) {\n          const auto temp = f(i, j);\n       \
    \   if (temp < m) {\n            m     = temp;\n            index = j;\n     \
    \     }\n        }\n\n        ret[i] = std::make_pair(index, m);\n        return;\n\
    \      }\n\n      const int mid = (top + bottom) / 2;\n      rec(N, M, f, mid,\
    \ mid, left, right, ret);\n      rec(N, M, f, top, mid - 1, left, ret[mid].first,\
    \ ret);\n      rec(N, M, f, mid + 1, bottom, ret[mid].first, right, ret);\n  \
    \  }\n  }  // namespace monotone_minima_impl\n\n  template <typename T, typename\
    \ F>\n  auto monotone_minima(int N, int M, const F &f) {\n    std::vector<std::pair<int,\
    \ T>> ret(M);\n    monotone_minima_impl::rec<T, F>(N, M, f, 0, N - 1, 0, M - 1,\
    \ ret);\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DynamicProgramming/SpeedupTechnique/monotone_minima.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/DynamicProgramming/SpeedupTechnique/monotone_minima.cpp
layout: document
title: Monotone minima
---

## Operations

## Requirements

## Notes

## Problems

- [C - スペースエクスプローラー高橋君](https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c)

## References

- [https://ei1333.github.io/luzhiled/snippets/dp/monotone-minima.html](https://ei1333.github.io/luzhiled/snippets/dp/monotone-minima.html)
- [https://ferin-tech.hatenablog.com/entry/2018/02/23/071343](https://ferin-tech.hatenablog.com/entry/2018/02/23/071343)
- [https://wiki.kimiyuki.net/monotone%20minima](https://wiki.kimiyuki.net/monotone%20minima)
