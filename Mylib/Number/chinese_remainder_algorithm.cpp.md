---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Number/extended_gcd.cpp
    title: Extended Euclidean algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/186/main.test.cpp
    title: test/yukicoder/186/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Number/chinese_remainder_algorithm.cpp\"\n#include\
    \ <vector>\n#include <tuple>\n#line 3 \"Mylib/Number/extended_gcd.cpp\"\n\nnamespace\
    \ haar_lib {\n  std::tuple<int64_t, int64_t, int64_t> ext_gcd(int64_t a, int64_t\
    \ b){\n    if(b == 0) return std::make_tuple(a, 1, 0);\n    int64_t d, p, q;\n\
    \    std::tie(d, q, p) = ext_gcd(b, (a + b) % b);\n    return std::make_tuple(d,\
    \ p, q - a / b * p);\n  }\n}\n#line 5 \"Mylib/Number/chinese_remainder_algorithm.cpp\"\
    \n\nnamespace haar_lib {\n  bool chinese_remainder_algorithm(int64_t b1, int64_t\
    \ m1, int64_t b2, int64_t m2, int64_t &r, int64_t &m){\n    int64_t p, q, d;\n\
    \    std::tie(d, p, q) = ext_gcd(m1, m2);\n    if((b2 - b1) % d != 0) return false;\n\
    \    m = m1 * m2 / d;\n    int64_t t = ((b2 - b1) * p / d) % (m2 / d);\n    r\
    \ = (b1 + m1 * t + m) % m;\n    return true;\n  }\n\n  bool chinese_remainder_algorithm(const\
    \ std::vector<int64_t> &bs, const std::vector<int64_t> &ms, int64_t &r, int64_t\
    \ &m){\n    int64_t R = 0, M = 1;\n    for(int i = 0; i < (int)bs.size(); ++i){\n\
    \      if(not chinese_remainder_algorithm(R, M, bs[i], ms[i], r, m)) return false;\n\
    \      R = r;\n      M = m;\n    }\n    return true;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <tuple>\n#include \"Mylib/Number/extended_gcd.cpp\"\
    \n\nnamespace haar_lib {\n  bool chinese_remainder_algorithm(int64_t b1, int64_t\
    \ m1, int64_t b2, int64_t m2, int64_t &r, int64_t &m){\n    int64_t p, q, d;\n\
    \    std::tie(d, p, q) = ext_gcd(m1, m2);\n    if((b2 - b1) % d != 0) return false;\n\
    \    m = m1 * m2 / d;\n    int64_t t = ((b2 - b1) * p / d) % (m2 / d);\n    r\
    \ = (b1 + m1 * t + m) % m;\n    return true;\n  }\n\n  bool chinese_remainder_algorithm(const\
    \ std::vector<int64_t> &bs, const std::vector<int64_t> &ms, int64_t &r, int64_t\
    \ &m){\n    int64_t R = 0, M = 1;\n    for(int i = 0; i < (int)bs.size(); ++i){\n\
    \      if(not chinese_remainder_algorithm(R, M, bs[i], ms[i], r, m)) return false;\n\
    \      R = r;\n      M = m;\n    }\n    return true;\n  }\n}\n"
  dependsOn:
  - Mylib/Number/extended_gcd.cpp
  isVerificationFile: false
  path: Mylib/Number/chinese_remainder_algorithm.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/186/main.test.cpp
documentation_of: Mylib/Number/chinese_remainder_algorithm.cpp
layout: document
title: Chinese remainder theorem
---

## Operations

## Requirements

## Notes

## Problems

## References
