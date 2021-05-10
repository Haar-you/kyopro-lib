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
  bundledCode: "#line 2 \"Mylib/Bit/bit_utils.cpp\"\n#include <cstdint>\n#include\
    \ <limits>\n#include <type_traits>\n\nnamespace haar_lib {\n  constexpr bool has_single_bit(uint64_t\
    \ x) {\n    return x != 0 and (x & (x - 1)) == 0;\n  }\n\n  constexpr int countl_zero(uint64_t\
    \ x) {\n    if (x == 0) return 64;\n    return __builtin_clzll(x);\n  }\n\n  constexpr\
    \ int countl_one(uint64_t x) {\n    return countl_zero(~x);\n  }\n\n  constexpr\
    \ int countr_zero(uint64_t x) {\n    if (x == 0) return 64;\n    return __builtin_ctzll(x);\n\
    \  }\n\n  constexpr int countr_one(uint64_t x) {\n    return countr_zero(~x);\n\
    \  }\n\n  constexpr uint64_t bit_width(uint64_t x) {\n    if (x == 0) return 0;\n\
    \    return 64 - countl_zero(x);\n  }\n\n  constexpr uint64_t bit_ceil(uint64_t\
    \ x) {\n    if (has_single_bit(x)) return x;\n    return 1LL << bit_width(x);\n\
    \  }\n\n  constexpr uint64_t bit_floor(uint64_t x) {\n    if (has_single_bit(x))\
    \ return x;\n    return bit_ceil(x) >> 1;\n  }\n\n  constexpr int popcount(uint64_t\
    \ x) {\n    return __builtin_popcountll(x);\n  }\n\n  template <typename T>\n\
    \  constexpr T rotl(T x, int s) {\n    static_assert(std::is_unsigned_v<T>, \"\
    T must be an unsigned integer type.\");\n    constexpr int N = std::numeric_limits<T>::digits;\n\
    \    s %= N;\n    if (s == 0)\n      return x;\n    else if (s > 0)\n      return\
    \ (x << s) | (x >> (N - s));\n    else\n      return (x >> -s) | (x << (N + s));\n\
    \  }\n\n  template <typename T>\n  constexpr T rotr(T x, int s) {\n    return\
    \ rotl(x, -s);\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cstdint>\n#include <limits>\n#include <type_traits>\n\
    \nnamespace haar_lib {\n  constexpr bool has_single_bit(uint64_t x) {\n    return\
    \ x != 0 and (x & (x - 1)) == 0;\n  }\n\n  constexpr int countl_zero(uint64_t\
    \ x) {\n    if (x == 0) return 64;\n    return __builtin_clzll(x);\n  }\n\n  constexpr\
    \ int countl_one(uint64_t x) {\n    return countl_zero(~x);\n  }\n\n  constexpr\
    \ int countr_zero(uint64_t x) {\n    if (x == 0) return 64;\n    return __builtin_ctzll(x);\n\
    \  }\n\n  constexpr int countr_one(uint64_t x) {\n    return countr_zero(~x);\n\
    \  }\n\n  constexpr uint64_t bit_width(uint64_t x) {\n    if (x == 0) return 0;\n\
    \    return 64 - countl_zero(x);\n  }\n\n  constexpr uint64_t bit_ceil(uint64_t\
    \ x) {\n    if (has_single_bit(x)) return x;\n    return 1LL << bit_width(x);\n\
    \  }\n\n  constexpr uint64_t bit_floor(uint64_t x) {\n    if (has_single_bit(x))\
    \ return x;\n    return bit_ceil(x) >> 1;\n  }\n\n  constexpr int popcount(uint64_t\
    \ x) {\n    return __builtin_popcountll(x);\n  }\n\n  template <typename T>\n\
    \  constexpr T rotl(T x, int s) {\n    static_assert(std::is_unsigned_v<T>, \"\
    T must be an unsigned integer type.\");\n    constexpr int N = std::numeric_limits<T>::digits;\n\
    \    s %= N;\n    if (s == 0)\n      return x;\n    else if (s > 0)\n      return\
    \ (x << s) | (x >> (N - s));\n    else\n      return (x >> -s) | (x << (N + s));\n\
    \  }\n\n  template <typename T>\n  constexpr T rotr(T x, int s) {\n    return\
    \ rotl(x, -s);\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Bit/bit_utils.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Bit/bit_utils.cpp
layout: document
title: Bit utils
---

## Operations

## Requirements

## Notes

## Problems

## References