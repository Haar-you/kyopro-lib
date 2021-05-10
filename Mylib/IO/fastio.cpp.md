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
  bundledCode: "#line 2 \"Mylib/IO/fastio.cpp\"\n#include <cstdio>\n#include <cstdlib>\n\
    \nclass fastio {\n  static const int read_size  = 1 << 26;\n  static const int\
    \ write_size = 1 << 26;\n\n  char *read_data, *write_data;\n  char *rb, *wb;\n\
    \  char temp[100];\n\npublic:\n  fastio() {\n    read_data  = (char *) std::malloc(read_size);\n\
    \    write_data = (char *) std::malloc(write_size);\n\n    fread(read_data, 1,\
    \ read_size, stdin);\n    rb = read_data;\n    wb = write_data;\n  }\n\n  ~fastio()\
    \ {\n    fwrite(write_data, 1, wb - write_data, stdout);\n    std::free(read_data);\n\
    \    std::free(write_data);\n  }\n\n  template <typename T>\n  inline T read_int()\
    \ {\n    T ret    = 0;\n    bool neg = false;\n\n    while ((*rb < '0' or *rb\
    \ > '9') and *rb != '-') ++rb;\n\n    if (*rb == '-') {\n      neg = true;\n \
    \     ++rb;\n    }\n\n    while ('0' <= *rb and *rb <= '9') {\n      ret = ret\
    \ * 10 + (*rb - '0');\n      ++rb;\n    }\n\n    if (neg) ret = -ret;\n\n    return\
    \ ret;\n  }\n\n  template <typename T>\n  inline void write_int(T x) {\n    if\
    \ (x == 0) {\n      write_char('0');\n      return;\n    }\n\n    if (x < 0) {\n\
    \      write_char('-');\n      x = -x;\n    }\n\n    char *t = temp;\n\n    while\
    \ (x) {\n      auto y = x / 10;\n      *t     = (char) ('0' + x - y * 10);\n \
    \     ++t;\n      x = y;\n    }\n\n    while (t != temp) write_char(*(--t));\n\
    \  }\n\n  inline void write_char(char c) {\n    *wb = c;\n    ++wb;\n  }\n};\n"
  code: "#pragma once\n#include <cstdio>\n#include <cstdlib>\n\nclass fastio {\n \
    \ static const int read_size  = 1 << 26;\n  static const int write_size = 1 <<\
    \ 26;\n\n  char *read_data, *write_data;\n  char *rb, *wb;\n  char temp[100];\n\
    \npublic:\n  fastio() {\n    read_data  = (char *) std::malloc(read_size);\n \
    \   write_data = (char *) std::malloc(write_size);\n\n    fread(read_data, 1,\
    \ read_size, stdin);\n    rb = read_data;\n    wb = write_data;\n  }\n\n  ~fastio()\
    \ {\n    fwrite(write_data, 1, wb - write_data, stdout);\n    std::free(read_data);\n\
    \    std::free(write_data);\n  }\n\n  template <typename T>\n  inline T read_int()\
    \ {\n    T ret    = 0;\n    bool neg = false;\n\n    while ((*rb < '0' or *rb\
    \ > '9') and *rb != '-') ++rb;\n\n    if (*rb == '-') {\n      neg = true;\n \
    \     ++rb;\n    }\n\n    while ('0' <= *rb and *rb <= '9') {\n      ret = ret\
    \ * 10 + (*rb - '0');\n      ++rb;\n    }\n\n    if (neg) ret = -ret;\n\n    return\
    \ ret;\n  }\n\n  template <typename T>\n  inline void write_int(T x) {\n    if\
    \ (x == 0) {\n      write_char('0');\n      return;\n    }\n\n    if (x < 0) {\n\
    \      write_char('-');\n      x = -x;\n    }\n\n    char *t = temp;\n\n    while\
    \ (x) {\n      auto y = x / 10;\n      *t     = (char) ('0' + x - y * 10);\n \
    \     ++t;\n      x = y;\n    }\n\n    while (t != temp) write_char(*(--t));\n\
    \  }\n\n  inline void write_char(char c) {\n    *wb = c;\n    ++wb;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/IO/fastio.cpp
  requiredBy: []
  timestamp: '2021-05-10 06:08:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/IO/fastio.cpp
layout: document
title: Fast IO
---

## Operations

## Requirements

## Notes

## Problems

## References
