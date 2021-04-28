---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Number/Mod/mod_inv.cpp
    title: Mod inverse
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/linear_congruence_equation.cpp\"\n#include\
    \ <numeric>\n#include <optional>\n#line 2 \"Mylib/Number/Mod/mod_inv.cpp\"\n#include\
    \ <cstdint>\n#include <utility>\n\nnamespace haar_lib {\n  constexpr int64_t mod_inv(int64_t\
    \ a, int64_t m) {\n    int64_t b = m, u = 1, v = 0;\n\n    while (b) {\n     \
    \ int64_t t = a / b;\n      a -= t * b;\n      a = a ^ b;\n      b = a ^ b;\n\
    \      a = a ^ b;\n\n      u -= t * v;\n      u = u ^ v;\n      v = u ^ v;\n \
    \     u = u ^ v;\n    }\n\n    u %= m;\n    if (u < 0) u += m;\n\n    return u;\n\
    \  }\n}  // namespace haar_lib\n#line 5 \"Mylib/Number/linear_congruence_equation.cpp\"\
    \n\nnamespace haar_lib {\n  // ax + b = 0 (mod m)\n  std::optional<int64_t> linear_congruence_equation(int64_t\
    \ a, int64_t b, int64_t m) {\n    if (a >= m) a %= m;\n    if (b >= m) b %= m;\n\
    \    if (a < 0) (a += m) %= m;\n    if (b < 0) (b += m) %= m;\n\n    auto g =\
    \ std::gcd(a, m);\n    if (b % g == 0) {\n      a /= g;\n      b /= g;\n     \
    \ m /= g;\n    }\n\n    if (std::gcd(a, m) == 1) {\n      return (m - b) * mod_inv(a,\
    \ m) % m;\n    }\n\n    return std::nullopt;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <numeric>\n#include <optional>\n#include \"Mylib/Number/Mod/mod_inv.cpp\"\
    \n\nnamespace haar_lib {\n  // ax + b = 0 (mod m)\n  std::optional<int64_t> linear_congruence_equation(int64_t\
    \ a, int64_t b, int64_t m) {\n    if (a >= m) a %= m;\n    if (b >= m) b %= m;\n\
    \    if (a < 0) (a += m) %= m;\n    if (b < 0) (b += m) %= m;\n\n    auto g =\
    \ std::gcd(a, m);\n    if (b % g == 0) {\n      a /= g;\n      b /= g;\n     \
    \ m /= g;\n    }\n\n    if (std::gcd(a, m) == 1) {\n      return (m - b) * mod_inv(a,\
    \ m) % m;\n    }\n\n    return std::nullopt;\n  }\n}  // namespace haar_lib\n"
  dependsOn:
  - Mylib/Number/Mod/mod_inv.cpp
  isVerificationFile: false
  path: Mylib/Number/linear_congruence_equation.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Number/linear_congruence_equation.cpp
layout: document
title: Linear congruence equation
---

## Operations

- `linear_congruence_equation(a, b, m)`
    - $ax + b = 0 \pmod m$を満たすx($0 \le x \lt m$)を求める。
    - 存在しなければ、`std::nullopt`を返す。

## Requirements

## Notes

## Problems

## References
