---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle_in_histogram.cpp
    title: Largest rectangle in histogram
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_3_B/main.test.cpp
    title: test/aoj/DPL_3_B/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle.cpp\"\
    \n#include <vector>\n#include <algorithm>\n#line 3 \"Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle_in_histogram.cpp\"\
    \n#include <stack>\n#include <utility>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  T max_rectangle_in_histogram(const std::vector<T> &h){\n    std::stack<std::pair<T,\
    \ int>> st;\n    T ret = 0;\n\n    for(size_t i = 0; i < h.size(); ++i){\n   \
    \   if(st.empty()){\n        st.emplace(h[i], i);\n      }else if(st.top().first\
    \ < h[i]){\n        st.emplace(h[i], i);\n      }else if(st.top().first > h[i]){\n\
    \        int j = i;\n        while(not st.empty() and st.top().first > h[i]){\n\
    \          ret = std::max(ret, st.top().first * ((T)i - st.top().second));\n \
    \         j = st.top().second;\n          st.pop();\n        }\n        st.emplace(h[i],\
    \ j);\n      }\n    }\n\n    while(not st.empty()){\n      ret = std::max(ret,\
    \ st.top().first * ((T)h.size() - st.top().second));\n      st.pop();\n    }\n\
    \n    return ret;\n  }\n}\n#line 5 \"Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  int max_rectangle(const std::vector<std::vector<T>>\
    \ &d, T value){\n    const int H = d.size();\n    const int W = d[0].size();\n\
    \n    std::vector<std::vector<int>> c(H, std::vector<int>(W));\n    for(int i\
    \ = 0; i < H; ++i){\n      for(int j = 0; j < W; ++j){\n        if(d[i][j] ==\
    \ value) c[i][j] = 1;\n      }\n    }\n\n    for(int i = 1; i < H; ++i){\n   \
    \   for(int j = 0; j < W; ++j){\n        if(c[i][j]){\n          c[i][j] += c[i\
    \ - 1][j];\n        }\n      }\n    }\n\n    int ret = 0;\n    for(int i = 0;\
    \ i < H; ++i){\n      int t = max_rectangle_in_histogram<int>(c[i]);\n      ret\
    \ = std::max(ret, t);\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include \"Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle_in_histogram.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  int max_rectangle(const std::vector<std::vector<T>>\
    \ &d, T value){\n    const int H = d.size();\n    const int W = d[0].size();\n\
    \n    std::vector<std::vector<int>> c(H, std::vector<int>(W));\n    for(int i\
    \ = 0; i < H; ++i){\n      for(int j = 0; j < W; ++j){\n        if(d[i][j] ==\
    \ value) c[i][j] = 1;\n      }\n    }\n\n    for(int i = 1; i < H; ++i){\n   \
    \   for(int j = 0; j < W; ++j){\n        if(c[i][j]){\n          c[i][j] += c[i\
    \ - 1][j];\n        }\n      }\n    }\n\n    int ret = 0;\n    for(int i = 0;\
    \ i < H; ++i){\n      int t = max_rectangle_in_histogram<int>(c[i]);\n      ret\
    \ = std::max(ret, t);\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle_in_histogram.cpp
  isVerificationFile: false
  path: Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DPL_3_B/main.test.cpp
documentation_of: Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle.cpp
layout: document
title: Largest rectangle
---

## Operations
- `max_rectangle_in_histogram(T h[H][W])`
	- Time complexity $O(HW)$

## Requirements

## Notes

## Problems

- [AOJ DPL_3_B Largest Rectangle](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B)
- [ARC 081 F - Flip and Rectangles](https://atcoder.jp/contests/arc081/tasks/arc081_d) ((w+1)(h+1)の最大値を求める変種)

## References

