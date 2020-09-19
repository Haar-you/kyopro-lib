---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/montmort_number_mod/main.test.cpp
    title: test/yosupo-judge/montmort_number_mod/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/montmort_number.cpp\"\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  auto montmort_number(int n){\n\
    \    std::vector<T> ret(n + 1);\n\n    ret[0] = 1;\n    ret[1] = 0;\n    ret[2]\
    \ = 1;\n\n    for(int i = 3; i <= n; ++i){\n      ret[i] = (ret[i - 1] + ret[i\
    \ - 2]) * (i - 1);\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  auto montmort_number(int n){\n    std::vector<T> ret(n + 1);\n\n    ret[0]\
    \ = 1;\n    ret[1] = 0;\n    ret[2] = 1;\n\n    for(int i = 3; i <= n; ++i){\n\
    \      ret[i] = (ret[i - 1] + ret[i - 2]) * (i - 1);\n    }\n\n    return ret;\n\
    \  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Combinatorics/montmort_number.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/montmort_number_mod/main.test.cpp
documentation_of: Mylib/Combinatorics/montmort_number.cpp
layout: document
title: Montmort number
---

## Operations

- `montmort_number(int n)`
	- 長さ$0$~$n$の完全順列の個数を列挙する。
	- Time complexity $O(n)$

## Requirements

## Notes

## Problems

- [ARC009 C - 高橋君、24歳](https://atcoder.jp/contests/arc009/tasks/arc009_3)
- [Montmort Number](https://judge.yosupo.jp/problem/montmort_number_mod)

## References

- [https://ja.wikipedia.org/wiki/%E5%AE%8C%E5%85%A8%E9%A0%86%E5%88%97](https://ja.wikipedia.org/wiki/%E5%AE%8C%E5%85%A8%E9%A0%86%E5%88%97)
- [https://oeis.org/A000166](https://oeis.org/A000166)

