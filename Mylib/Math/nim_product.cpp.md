---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/nim_product_64/main.test.cpp
    title: test/yosupo-judge/nim_product_64/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Math/nim_product.cpp\"\n#include <cstdint>\n\nnamespace\
    \ haar_lib {\n  namespace nimber_impl {\n    constexpr uint8_t p[16][16] =\n \
    \       {\n            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\n   \
    \         {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},\n          \
    \  {0, 2, 3, 1, 8, 10, 11, 9, 12, 14, 15, 13, 4, 6, 7, 5},\n            {0, 3,\
    \ 1, 2, 12, 15, 13, 14, 4, 7, 5, 6, 8, 11, 9, 10},\n            {0, 4, 8, 12,\
    \ 6, 2, 14, 10, 11, 15, 3, 7, 13, 9, 5, 1},\n            {0, 5, 10, 15, 2, 7,\
    \ 8, 13, 3, 6, 9, 12, 1, 4, 11, 14},\n            {0, 6, 11, 13, 14, 8, 5, 3,\
    \ 7, 1, 12, 10, 9, 15, 2, 4},\n            {0, 7, 9, 14, 10, 13, 3, 4, 15, 8,\
    \ 6, 1, 5, 2, 12, 11},\n            {0, 8, 12, 4, 11, 3, 7, 15, 13, 5, 1, 9, 6,\
    \ 14, 10, 2},\n            {0, 9, 14, 7, 15, 6, 1, 8, 5, 12, 11, 2, 10, 3, 4,\
    \ 13},\n            {0, 10, 15, 5, 3, 9, 12, 6, 1, 11, 14, 4, 2, 8, 13, 7},\n\
    \            {0, 11, 13, 6, 7, 12, 10, 1, 9, 2, 4, 15, 14, 5, 3, 8},\n       \
    \     {0, 12, 4, 8, 13, 1, 9, 5, 6, 10, 2, 14, 11, 7, 15, 3},\n            {0,\
    \ 13, 6, 11, 9, 4, 15, 2, 14, 3, 8, 5, 7, 10, 1, 12},\n            {0, 14, 7,\
    \ 9, 5, 11, 2, 12, 10, 4, 13, 3, 15, 1, 8, 6},\n            {0, 15, 5, 10, 1,\
    \ 14, 4, 11, 2, 13, 7, 8, 3, 12, 6, 9}};\n\n    uint8_t memo[256][256];\n\n  \
    \  __attribute__((constructor)) void init() {\n      constexpr uint32_t mask =\
    \ 0xf;\n\n      for (int a = 0; a < 256; ++a) {\n        for (int b = 0; b < 256;\
    \ ++b) {\n          uint8_t au = a >> 4;\n          uint8_t al = a & mask;\n \
    \         uint8_t bu = b >> 4;\n          uint8_t bl = b & mask;\n\n         \
    \ memo[a][b] = ((p[au][bu] ^ p[al][bu] ^ p[au][bl]) << 4) ^ p[au][p[bu][1 << 3]]\
    \ ^ p[al][bl];\n        }\n      }\n    }\n  }  // namespace nimber_impl\n\n \
    \ uint16_t nim_product_16(uint16_t a, uint16_t b) {\n    using namespace nimber_impl;\n\
    \n    constexpr uint16_t mask = 0xff;\n\n    uint8_t au = a >> 8;\n    uint8_t\
    \ al = a & mask;\n    uint8_t bu = b >> 8;\n    uint8_t bl = b & mask;\n\n   \
    \ return ((uint16_t)(memo[au][bu] ^ memo[al][bu] ^ memo[au][bl]) << 8) ^ memo[au][memo[bu][1\
    \ << 7]] ^ memo[al][bl];\n  }\n\n  uint32_t nim_product_32(uint32_t a, uint32_t\
    \ b) {\n    constexpr uint32_t mask = 0xffff;\n\n    uint16_t au = a >> 16;\n\
    \    uint16_t al = a & mask;\n    uint16_t bu = b >> 16;\n    uint16_t bl = b\
    \ & mask;\n\n    return ((uint32_t)(nim_product_16(au, bu) ^ nim_product_16(al,\
    \ bu) ^ nim_product_16(au, bl)) << 16) ^ nim_product_16(au, nim_product_16(bu,\
    \ 1 << 15)) ^ nim_product_16(al, bl);\n  }\n\n  uint64_t nim_product_64(uint64_t\
    \ a, uint64_t b) {\n    constexpr uint64_t mask = 0xffffffff;\n\n    uint32_t\
    \ au = a >> 32;\n    uint32_t al = a & mask;\n    uint32_t bu = b >> 32;\n   \
    \ uint32_t bl = b & mask;\n\n    return ((uint64_t)(nim_product_32(au, bu) ^ nim_product_32(al,\
    \ bu) ^ nim_product_32(au, bl)) << 32) ^ nim_product_32(au, nim_product_32(bu,\
    \ 1 << 31)) ^ nim_product_32(al, bl);\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cstdint>\n\nnamespace haar_lib {\n  namespace nimber_impl\
    \ {\n    constexpr uint8_t p[16][16] =\n        {\n            {0, 0, 0, 0, 0,\
    \ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\n            {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,\
    \ 10, 11, 12, 13, 14, 15},\n            {0, 2, 3, 1, 8, 10, 11, 9, 12, 14, 15,\
    \ 13, 4, 6, 7, 5},\n            {0, 3, 1, 2, 12, 15, 13, 14, 4, 7, 5, 6, 8, 11,\
    \ 9, 10},\n            {0, 4, 8, 12, 6, 2, 14, 10, 11, 15, 3, 7, 13, 9, 5, 1},\n\
    \            {0, 5, 10, 15, 2, 7, 8, 13, 3, 6, 9, 12, 1, 4, 11, 14},\n       \
    \     {0, 6, 11, 13, 14, 8, 5, 3, 7, 1, 12, 10, 9, 15, 2, 4},\n            {0,\
    \ 7, 9, 14, 10, 13, 3, 4, 15, 8, 6, 1, 5, 2, 12, 11},\n            {0, 8, 12,\
    \ 4, 11, 3, 7, 15, 13, 5, 1, 9, 6, 14, 10, 2},\n            {0, 9, 14, 7, 15,\
    \ 6, 1, 8, 5, 12, 11, 2, 10, 3, 4, 13},\n            {0, 10, 15, 5, 3, 9, 12,\
    \ 6, 1, 11, 14, 4, 2, 8, 13, 7},\n            {0, 11, 13, 6, 7, 12, 10, 1, 9,\
    \ 2, 4, 15, 14, 5, 3, 8},\n            {0, 12, 4, 8, 13, 1, 9, 5, 6, 10, 2, 14,\
    \ 11, 7, 15, 3},\n            {0, 13, 6, 11, 9, 4, 15, 2, 14, 3, 8, 5, 7, 10,\
    \ 1, 12},\n            {0, 14, 7, 9, 5, 11, 2, 12, 10, 4, 13, 3, 15, 1, 8, 6},\n\
    \            {0, 15, 5, 10, 1, 14, 4, 11, 2, 13, 7, 8, 3, 12, 6, 9}};\n\n    uint8_t\
    \ memo[256][256];\n\n    __attribute__((constructor)) void init() {\n      constexpr\
    \ uint32_t mask = 0xf;\n\n      for (int a = 0; a < 256; ++a) {\n        for (int\
    \ b = 0; b < 256; ++b) {\n          uint8_t au = a >> 4;\n          uint8_t al\
    \ = a & mask;\n          uint8_t bu = b >> 4;\n          uint8_t bl = b & mask;\n\
    \n          memo[a][b] = ((p[au][bu] ^ p[al][bu] ^ p[au][bl]) << 4) ^ p[au][p[bu][1\
    \ << 3]] ^ p[al][bl];\n        }\n      }\n    }\n  }  // namespace nimber_impl\n\
    \n  uint16_t nim_product_16(uint16_t a, uint16_t b) {\n    using namespace nimber_impl;\n\
    \n    constexpr uint16_t mask = 0xff;\n\n    uint8_t au = a >> 8;\n    uint8_t\
    \ al = a & mask;\n    uint8_t bu = b >> 8;\n    uint8_t bl = b & mask;\n\n   \
    \ return ((uint16_t)(memo[au][bu] ^ memo[al][bu] ^ memo[au][bl]) << 8) ^ memo[au][memo[bu][1\
    \ << 7]] ^ memo[al][bl];\n  }\n\n  uint32_t nim_product_32(uint32_t a, uint32_t\
    \ b) {\n    constexpr uint32_t mask = 0xffff;\n\n    uint16_t au = a >> 16;\n\
    \    uint16_t al = a & mask;\n    uint16_t bu = b >> 16;\n    uint16_t bl = b\
    \ & mask;\n\n    return ((uint32_t)(nim_product_16(au, bu) ^ nim_product_16(al,\
    \ bu) ^ nim_product_16(au, bl)) << 16) ^ nim_product_16(au, nim_product_16(bu,\
    \ 1 << 15)) ^ nim_product_16(al, bl);\n  }\n\n  uint64_t nim_product_64(uint64_t\
    \ a, uint64_t b) {\n    constexpr uint64_t mask = 0xffffffff;\n\n    uint32_t\
    \ au = a >> 32;\n    uint32_t al = a & mask;\n    uint32_t bu = b >> 32;\n   \
    \ uint32_t bl = b & mask;\n\n    return ((uint64_t)(nim_product_32(au, bu) ^ nim_product_32(al,\
    \ bu) ^ nim_product_32(au, bl)) << 32) ^ nim_product_32(au, nim_product_32(bu,\
    \ 1 << 31)) ^ nim_product_32(al, bl);\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Math/nim_product.cpp
  requiredBy: []
  timestamp: '2021-05-10 06:09:59+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/nim_product_64/main.test.cpp
documentation_of: Mylib/Math/nim_product.cpp
layout: document
title: Nim product
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://kyopro-friends.hatenablog.com/entry/2020/04/07/195850](https://kyopro-friends.hatenablog.com/entry/2020/04/07/195850)
