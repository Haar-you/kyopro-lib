---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Typical/max_rectangle.cpp
    title: Largest rectangle
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DPL_3_B/main.test.cpp
    title: test/aoj/DPL_3_B/main.test.cpp
  - icon: ':x:'
    path: test/aoj/DPL_3_C/main.test.cpp
    title: test/aoj/DPL_3_C/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/max_rectangle_in_histogram.cpp\"\n#include\
    \ <stack>\n#include <utility>\n#include <vector>\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  T max_rectangle_in_histogram(const std::vector<T> &h) {\n  \
    \  std::stack<std::pair<T, int>> st;\n    T ret = 0;\n\n    for (size_t i = 0;\
    \ i < h.size(); ++i) {\n      if (st.empty()) {\n        st.emplace(h[i], i);\n\
    \      } else if (st.top().first < h[i]) {\n        st.emplace(h[i], i);\n   \
    \   } else if (st.top().first > h[i]) {\n        int j = i;\n        while (not\
    \ st.empty() and st.top().first > h[i]) {\n          ret = std::max(ret, st.top().first\
    \ * ((T) i - st.top().second));\n          j   = st.top().second;\n          st.pop();\n\
    \        }\n        st.emplace(h[i], j);\n      }\n    }\n\n    while (not st.empty())\
    \ {\n      ret = std::max(ret, st.top().first * ((T) h.size() - st.top().second));\n\
    \      st.pop();\n    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <stack>\n#include <utility>\n#include <vector>\n\n\
    namespace haar_lib {\n  template <typename T>\n  T max_rectangle_in_histogram(const\
    \ std::vector<T> &h) {\n    std::stack<std::pair<T, int>> st;\n    T ret = 0;\n\
    \n    for (size_t i = 0; i < h.size(); ++i) {\n      if (st.empty()) {\n     \
    \   st.emplace(h[i], i);\n      } else if (st.top().first < h[i]) {\n        st.emplace(h[i],\
    \ i);\n      } else if (st.top().first > h[i]) {\n        int j = i;\n       \
    \ while (not st.empty() and st.top().first > h[i]) {\n          ret = std::max(ret,\
    \ st.top().first * ((T) i - st.top().second));\n          j   = st.top().second;\n\
    \          st.pop();\n        }\n        st.emplace(h[i], j);\n      }\n    }\n\
    \n    while (not st.empty()) {\n      ret = std::max(ret, st.top().first * ((T)\
    \ h.size() - st.top().second));\n      st.pop();\n    }\n\n    return ret;\n \
    \ }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/max_rectangle_in_histogram.cpp
  requiredBy:
  - Mylib/Typical/max_rectangle.cpp
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DPL_3_C/main.test.cpp
  - test/aoj/DPL_3_B/main.test.cpp
documentation_of: Mylib/Typical/max_rectangle_in_histogram.cpp
layout: document
title: Largest rectangle in histogram
---

## Operations
- `max_rectangle_in_histogram(T h[N])`
	- Time complexity $O(N)$

## Requirements

## Notes

## Problems

- [AOJ DPL_3_C Largest Rectangle in a Histogram](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C)

## References

