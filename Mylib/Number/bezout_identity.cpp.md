---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Number/extended_gcd.cpp
    title: Extended Euclidean algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/bezout_identity.cpp\"\n#include <utility>\n\
    #include <optional>\n#line 2 \"Mylib/Number/extended_gcd.cpp\"\n#include <tuple>\n\
    \nnamespace haar_lib {\n  auto ext_gcd(int64_t a, int64_t b) ->\n    std::tuple<\n\
    \      int64_t, // gcd\n      int64_t, // p\n      int64_t  // q\n      >\n  {\n\
    \    if(b == 0) return std::make_tuple(a, 1, 0);\n    const auto [d, q, p] = ext_gcd(b,\
    \ (a + b) % b);\n    return std::make_tuple(d, p, q - a / b * p);\n  }\n}\n#line\
    \ 5 \"Mylib/Number/bezout_identity.cpp\"\n\nnamespace haar_lib {\n  struct bezout_generator\
    \ {\n    int64_t a, b, c, x, y, dx, dy;\n\n    auto value() const {return std::make_pair(x,\
    \ y);}\n    auto next(int64_t n = 1){x += dx * n, y -= dy * n; return std::make_pair(x,\
    \ y);}\n    auto prev(int64_t n = 1){x -= dx * n, y += dy * n; return std::make_pair(x,\
    \ y);}\n  };\n\n  std::optional<bezout_generator> bezout_identity(int64_t a, int64_t\
    \ b, int64_t c){\n    auto [g, x, y] = ext_gcd(a, b);\n\n    if(c % g != 0) return\
    \ std::nullopt;\n\n    int64_t dx = b / g;\n    int64_t dy = a / g;\n    int64_t\
    \ dc = c / g;\n\n    x %= dx;\n    if(x < 0){\n      x += std::abs(dx);\n    }\n\
    \n    x *= dc;\n    dx *= dc;\n    dy *= dc;\n\n    y = (c - a * x) / b;\n\n \
    \   return bezout_generator({a, b, c, x, y, dx, dy});\n  }\n}\n"
  code: "#pragma once\n#include <utility>\n#include <optional>\n#include \"Mylib/Number/extended_gcd.cpp\"\
    \n\nnamespace haar_lib {\n  struct bezout_generator {\n    int64_t a, b, c, x,\
    \ y, dx, dy;\n\n    auto value() const {return std::make_pair(x, y);}\n    auto\
    \ next(int64_t n = 1){x += dx * n, y -= dy * n; return std::make_pair(x, y);}\n\
    \    auto prev(int64_t n = 1){x -= dx * n, y += dy * n; return std::make_pair(x,\
    \ y);}\n  };\n\n  std::optional<bezout_generator> bezout_identity(int64_t a, int64_t\
    \ b, int64_t c){\n    auto [g, x, y] = ext_gcd(a, b);\n\n    if(c % g != 0) return\
    \ std::nullopt;\n\n    int64_t dx = b / g;\n    int64_t dy = a / g;\n    int64_t\
    \ dc = c / g;\n\n    x %= dx;\n    if(x < 0){\n      x += std::abs(dx);\n    }\n\
    \n    x *= dc;\n    dx *= dc;\n    dy *= dc;\n\n    y = (c - a * x) / b;\n\n \
    \   return bezout_generator({a, b, c, x, y, dx, dy});\n  }\n}\n"
  dependsOn:
  - Mylib/Number/extended_gcd.cpp
  isVerificationFile: false
  path: Mylib/Number/bezout_identity.cpp
  requiredBy: []
  timestamp: '2021-03-13 04:56:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Number/bezout_identity.cpp
layout: document
title: "B\xE9zout's identity"
---

## Operations
$ax + by = c$の形の一次不定方程式を解く。
$c \neq 0 \pmod {gcd(a, b)}$のとき、整数解x, yは存在しない。
そうでなければ、整数解ペアx, yのうちxが最小の非負整数となるものを設定した生成器を返す。

## Requirements

## Notes

## Problems

## References

- [https://ja.wikipedia.org/wiki/ベズーの等式](https://ja.wikipedia.org/wiki/%E3%83%99%E3%82%BA%E3%83%BC%E3%81%AE%E7%AD%89%E5%BC%8F)
- [https://mathtrain.jp/axbyc](https://mathtrain.jp/axbyc)
