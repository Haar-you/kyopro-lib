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
  bundledCode: "#line 2 \"Mylib/Debug/memory_dump.cpp\"\n#include <cctype>\n#include\
    \ <cstddef>\n#include <cstdio>\n\nvoid memory_dump(const void* p, size_t size)\
    \ {\n  unsigned char* cur = (unsigned char*) p;\n\n  printf(\"               \
    \  | 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f\\n\");\n  printf(\"__________________________________________________________________\\\
    n\");\n\n  size_t padding = (size_t) cur % 0x10;\n  size += padding;\n  cur -=\
    \ padding;\n\n  char temp[17];\n\n  size_t i = 0;\n  for (; i < size; ++i) {\n\
    \    if (i % 16 == 0) {\n      if (i != 0) {\n        printf(\"|%s|\\n\", temp);\n\
    \      }\n      printf(\"%16p | \", cur);\n      for (size_t j = 0; j < 16; ++j)\
    \ temp[j] = ' ';\n      temp[16] = '\\0';\n    }\n\n    printf(\"%02x \", (int)\
    \ (*cur));\n\n    if (isprint((char) (*cur))) {\n      temp[i % 16] = (char) (*cur);\n\
    \    } else {\n      temp[i % 16] = '.';\n    }\n\n    ++cur;\n  }\n\n  for (size_t\
    \ k = 0; k < (16 - (i % 16)) % 16; ++k) printf(\"   \");\n  printf(\"|%s|\\n\"\
    , temp);\n\n  printf(\"\\n\");\n}\n"
  code: "#pragma once\n#include <cctype>\n#include <cstddef>\n#include <cstdio>\n\n\
    void memory_dump(const void* p, size_t size) {\n  unsigned char* cur = (unsigned\
    \ char*) p;\n\n  printf(\"                 | 00 01 02 03 04 05 06 07 08 09 0a\
    \ 0b 0c 0d 0e 0f\\n\");\n  printf(\"__________________________________________________________________\\\
    n\");\n\n  size_t padding = (size_t) cur % 0x10;\n  size += padding;\n  cur -=\
    \ padding;\n\n  char temp[17];\n\n  size_t i = 0;\n  for (; i < size; ++i) {\n\
    \    if (i % 16 == 0) {\n      if (i != 0) {\n        printf(\"|%s|\\n\", temp);\n\
    \      }\n      printf(\"%16p | \", cur);\n      for (size_t j = 0; j < 16; ++j)\
    \ temp[j] = ' ';\n      temp[16] = '\\0';\n    }\n\n    printf(\"%02x \", (int)\
    \ (*cur));\n\n    if (isprint((char) (*cur))) {\n      temp[i % 16] = (char) (*cur);\n\
    \    } else {\n      temp[i % 16] = '.';\n    }\n\n    ++cur;\n  }\n\n  for (size_t\
    \ k = 0; k < (16 - (i % 16)) % 16; ++k) printf(\"   \");\n  printf(\"|%s|\\n\"\
    , temp);\n\n  printf(\"\\n\");\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Debug/memory_dump.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Debug/memory_dump.cpp
layout: document
title: Memory dump
---

## Operations

## Requirements

## Notes

## Problems

## References
