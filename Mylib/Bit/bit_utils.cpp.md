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
  bundledCode: "#line 2 \"Mylib/Bit/bit_utils.cpp\"\n#include <limits>\n#include <type_traits>\n\
    #include <cstdint>\n\nnamespace haar_lib {\n  bool has_single_bit(uint64_t x){\n\
    \    return x != 0 and (x & (x - 1)) == 0;\n  }\n\n  int countl_zero(uint64_t\
    \ x){\n    if(x == 0) return 64;\n    return __builtin_clzll(x);\n  }\n\n  int\
    \ countl_one(uint64_t x){\n    return countl_zero(~x);\n  }\n\n  int countr_zero(uint64_t\
    \ x){\n    if(x == 0) return 64;\n    return __builtin_ctzll(x);\n  }\n\n  int\
    \ countr_one(uint64_t x){\n    return countr_zero(~x);\n  }\n\n  uint64_t bit_width(uint64_t\
    \ x){\n    if(x == 0) return 0;\n    return 64 - countl_zero(x);\n  }\n\n  uint64_t\
    \ bit_ceil(uint64_t x){\n    if(has_single_bit(x)) return x;\n    return 1LL <<\
    \ bit_width(x);\n  }\n\n  uint64_t bit_floor(uint64_t x){\n    if(has_single_bit(x))\
    \ return x;\n    return bit_ceil(x) >> 1;\n  }\n\n  int popcount(uint64_t x){\n\
    \    return __builtin_popcountll(x);\n  }\n\n  template <typename T>\n  T rotl(T\
    \ x, int s){\n    static_assert(std::is_unsigned_v<T>, \"T must be an unsigned\
    \ integer type.\");\n    constexpr int N = std::numeric_limits<T>::digits;\n \
    \   s %= N;\n    if(s == 0) return x;\n    else if(s > 0) return (x << s) | (x\
    \ >> (N - s));\n    else return (x >> -s) | (x << (N + s));\n  }\n\n  template\
    \ <typename T>\n  T rotr(T x, int s){\n    return rotl(x, -s);\n  }\n}\n"
  code: "#pragma once\n#include <limits>\n#include <type_traits>\n#include <cstdint>\n\
    \nnamespace haar_lib {\n  bool has_single_bit(uint64_t x){\n    return x != 0\
    \ and (x & (x - 1)) == 0;\n  }\n\n  int countl_zero(uint64_t x){\n    if(x ==\
    \ 0) return 64;\n    return __builtin_clzll(x);\n  }\n\n  int countl_one(uint64_t\
    \ x){\n    return countl_zero(~x);\n  }\n\n  int countr_zero(uint64_t x){\n  \
    \  if(x == 0) return 64;\n    return __builtin_ctzll(x);\n  }\n\n  int countr_one(uint64_t\
    \ x){\n    return countr_zero(~x);\n  }\n\n  uint64_t bit_width(uint64_t x){\n\
    \    if(x == 0) return 0;\n    return 64 - countl_zero(x);\n  }\n\n  uint64_t\
    \ bit_ceil(uint64_t x){\n    if(has_single_bit(x)) return x;\n    return 1LL <<\
    \ bit_width(x);\n  }\n\n  uint64_t bit_floor(uint64_t x){\n    if(has_single_bit(x))\
    \ return x;\n    return bit_ceil(x) >> 1;\n  }\n\n  int popcount(uint64_t x){\n\
    \    return __builtin_popcountll(x);\n  }\n\n  template <typename T>\n  T rotl(T\
    \ x, int s){\n    static_assert(std::is_unsigned_v<T>, \"T must be an unsigned\
    \ integer type.\");\n    constexpr int N = std::numeric_limits<T>::digits;\n \
    \   s %= N;\n    if(s == 0) return x;\n    else if(s > 0) return (x << s) | (x\
    \ >> (N - s));\n    else return (x >> -s) | (x << (N + s));\n  }\n\n  template\
    \ <typename T>\n  T rotr(T x, int s){\n    return rotl(x, -s);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Bit/bit_utils.cpp
  requiredBy: []
  timestamp: '2020-10-07 17:47:39+09:00'
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
