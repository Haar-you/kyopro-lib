---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/2426/main.test.cpp
    title: test/aoj/2426/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
    title: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235/main.test.cpp
    title: test/yukicoder/235/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Utils/sort_simultaneously.cpp\"\n#include <vector>\n\
    #include <utility>\n#include <algorithm>\n#include <numeric>\n#include <initializer_list>\n\
    \nnamespace haar_lib {\n  template <typename Compare, typename ... Args>\n  void\
    \ sort_simultaneously(const Compare &compare, std::vector<Args> &... args){\n\
    \    const int N = std::max({args.size() ...});\n    std::vector<int> ord(N);\n\
    \    std::iota(ord.begin(), ord.end(), 0);\n    std::sort(ord.begin(), ord.end(),\
    \ compare);\n\n    (void)std::initializer_list<int>{\n      (void(\n        [&](){\n\
    \          auto temp = args;\n          for(int i = 0; i < N; ++i) temp[i] = args[ord[i]];\n\
    \          std::swap(temp, args);\n        }()\n      ), 0) ...};\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include <numeric>\n#include <initializer_list>\n\nnamespace haar_lib {\n  template\
    \ <typename Compare, typename ... Args>\n  void sort_simultaneously(const Compare\
    \ &compare, std::vector<Args> &... args){\n    const int N = std::max({args.size()\
    \ ...});\n    std::vector<int> ord(N);\n    std::iota(ord.begin(), ord.end(),\
    \ 0);\n    std::sort(ord.begin(), ord.end(), compare);\n\n    (void)std::initializer_list<int>{\n\
    \      (void(\n        [&](){\n          auto temp = args;\n          for(int\
    \ i = 0; i < N; ++i) temp[i] = args[ord[i]];\n          std::swap(temp, args);\n\
    \        }()\n      ), 0) ...};\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Utils/sort_simultaneously.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/2426/main.test.cpp
  - test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
  - test/yukicoder/235/main.test.cpp
documentation_of: Mylib/Utils/sort_simultaneously.cpp
layout: document
title: null
---

## Operations

## Requirements

## Notes

## Problems

## References
