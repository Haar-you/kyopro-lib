---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1208/main.test.cpp
    title: test/aoj/1208/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Rational/stern_brocot_tree.cpp\"\n#include\
    \ <utility>\n#include <cstdint>\n\nnamespace haar_lib {\n  template <typename\
    \ Checker>\n  void stern_brocot_tree(const Checker &check, int n, std::pair<int,\
    \ int> &lower, std::pair<int, int> &upper, int64_t pl = 0, int64_t ql = 1, int64_t\
    \ pr = 1, int64_t qr = 0){\n    int64_t pm = pl + pr;\n    int64_t qm = ql + qr;\n\
    \n    if(pm > n or qm > n) return;\n\n    auto t = check(pm, qm);\n\n    if(t\
    \ < 0){\n      lower = {pm, qm};\n      stern_brocot_tree(check, n, lower, upper,\
    \ pm, qm, pr, qr);\n    }else if(t > 0){\n      upper = {pm, qm};\n      stern_brocot_tree(check,\
    \ n, lower, upper, pl, ql, pm, qm);\n    }else{\n      lower = {pm, qm};\n   \
    \   upper = {pm, qm};\n    }\n  }\n}\n"
  code: "#pragma once\n#include <utility>\n#include <cstdint>\n\nnamespace haar_lib\
    \ {\n  template <typename Checker>\n  void stern_brocot_tree(const Checker &check,\
    \ int n, std::pair<int, int> &lower, std::pair<int, int> &upper, int64_t pl =\
    \ 0, int64_t ql = 1, int64_t pr = 1, int64_t qr = 0){\n    int64_t pm = pl + pr;\n\
    \    int64_t qm = ql + qr;\n\n    if(pm > n or qm > n) return;\n\n    auto t =\
    \ check(pm, qm);\n\n    if(t < 0){\n      lower = {pm, qm};\n      stern_brocot_tree(check,\
    \ n, lower, upper, pm, qm, pr, qr);\n    }else if(t > 0){\n      upper = {pm,\
    \ qm};\n      stern_brocot_tree(check, n, lower, upper, pl, ql, pm, qm);\n   \
    \ }else{\n      lower = {pm, qm};\n      upper = {pm, qm};\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Rational/stern_brocot_tree.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1208/main.test.cpp
documentation_of: Mylib/Number/Rational/stern_brocot_tree.cpp
layout: document
title: Stern-Brocot tree
---

## Operations

## Requirements

## Notes

## Problems

## References

- [http://www.prefield.com/algorithm/math/stern_brocot_tree.html](http://www.prefield.com/algorithm/math/stern_brocot_tree.html)
- [https://en.wikipedia.org/wiki/Stern%E2%80%93Brocot_tree](https://en.wikipedia.org/wiki/Stern%E2%80%93Brocot_tree)
- [http://blue-jam.hatenablog.com/entry/20110306/1299415086](http://blue-jam.hatenablog.com/entry/20110306/1299415086)
