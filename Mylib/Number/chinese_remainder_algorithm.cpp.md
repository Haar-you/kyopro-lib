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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/chinese_remainder_algorithm.cpp\"\n#include\
    \ <cassert>\n#include <optional>\n#include <vector>\n#line 2 \"Mylib/Number/extended_gcd.cpp\"\
    \n#include <tuple>\n\nnamespace haar_lib {\n  auto ext_gcd(int64_t a, int64_t\
    \ b) -> std::tuple<\n      int64_t,  // gcd\n      int64_t,  // p\n      int64_t\
    \   // q\n      > {\n    if (b == 0) return std::make_tuple(a, 1, 0);\n    const\
    \ auto [d, q, p] = ext_gcd(b, (a + b) % b);\n    return std::make_tuple(d, p,\
    \ q - a / b * p);\n  }\n}  // namespace haar_lib\n#line 6 \"Mylib/Number/chinese_remainder_algorithm.cpp\"\
    \n\nnamespace haar_lib {\n  std::optional<std::pair<int64_t, int64_t>> chinese_remainder_algorithm(\n\
    \      int64_t b1, int64_t m1,\n      int64_t b2, int64_t m2) {\n    const auto\
    \ [d, p, q] = ext_gcd(m1, m2);\n    if ((b2 - b1) % d != 0) return std::nullopt;\n\
    \    const int64_t m = m1 * m2 / d;\n    const int64_t t = ((b2 - b1) * p / d)\
    \ % (m2 / d);\n    const int64_t r = (b1 + m1 * t + m) % m;\n    return {{r, m}};\n\
    \  }\n\n  std::optional<std::pair<int64_t, int64_t>> chinese_remainder_algorithm(\n\
    \      const std::vector<int64_t> &bs,\n      const std::vector<int64_t> &ms)\
    \ {\n    assert(bs.size() == ms.size());\n    int64_t R = 0, M = 1;\n    for (int\
    \ i = 0; i < (int) bs.size(); ++i) {\n      const auto res = chinese_remainder_algorithm(R,\
    \ M, bs[i], ms[i]);\n      if (not res) return std::nullopt;\n      const auto\
    \ [r, m] = *res;\n      R                 = r;\n      M                 = m;\n\
    \    }\n    return {{R, M}};\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cassert>\n#include <optional>\n#include <vector>\n\
    #include \"Mylib/Number/extended_gcd.cpp\"\n\nnamespace haar_lib {\n  std::optional<std::pair<int64_t,\
    \ int64_t>> chinese_remainder_algorithm(\n      int64_t b1, int64_t m1,\n    \
    \  int64_t b2, int64_t m2) {\n    const auto [d, p, q] = ext_gcd(m1, m2);\n  \
    \  if ((b2 - b1) % d != 0) return std::nullopt;\n    const int64_t m = m1 * m2\
    \ / d;\n    const int64_t t = ((b2 - b1) * p / d) % (m2 / d);\n    const int64_t\
    \ r = (b1 + m1 * t + m) % m;\n    return {{r, m}};\n  }\n\n  std::optional<std::pair<int64_t,\
    \ int64_t>> chinese_remainder_algorithm(\n      const std::vector<int64_t> &bs,\n\
    \      const std::vector<int64_t> &ms) {\n    assert(bs.size() == ms.size());\n\
    \    int64_t R = 0, M = 1;\n    for (int i = 0; i < (int) bs.size(); ++i) {\n\
    \      const auto res = chinese_remainder_algorithm(R, M, bs[i], ms[i]);\n   \
    \   if (not res) return std::nullopt;\n      const auto [r, m] = *res;\n     \
    \ R                 = r;\n      M                 = m;\n    }\n    return {{R,\
    \ M}};\n  }\n}  // namespace haar_lib\n"
  dependsOn:
  - Mylib/Number/extended_gcd.cpp
  isVerificationFile: false
  path: Mylib/Number/chinese_remainder_algorithm.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
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
