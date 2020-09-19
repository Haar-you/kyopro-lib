---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Debug/grid_viewer.cpp\"\n#include <iostream>\n#include\
    \ <string>\n#include <functional>\n#include <vector>\n\ntemplate <typename C>\n\
    void grid_viewer([[maybe_unused]] const C &A, [[maybe_unused]] int width = 10){\n\
    #ifdef DEBUG\n  const int H = A.size();\n  const int W = A[0].size();\n\n  std::cerr\
    \ << \"    \";\n  for(int j = 0; j < W; ++j){\n    std::cerr << \"\\e[1;32m\"\
    \ << std::left << std::setw(width) << j << \"\\e[m\";\n  }\n  std::cerr << \"\\\
    n\";\n  std::cerr << std::right;\n\n  for(int i = 0; i < H; ++i){\n    std::cerr\
    \ << \"\\e[1;32m\" << std::setw(2) << i << \"|\\e[m \";\n\n    for(int j = 0;\
    \ j < W; ++j){\n      std::stringstream ss;\n      ss << A[i][j];\n      auto\
    \ s = ss.str();\n      if(s.size() > width){\n        s.resize(width);\n     \
    \ }else{\n        while(s.size() < width) s.push_back(' ');\n      }\n\n     \
    \ std::cerr << s << \"\";\n    }\n\n    std::cerr << \"\\n\";\n  }\n\n  std::cerr\
    \ << std::right;\n  std::cerr << std::setw(0);\n#endif\n}\n"
  code: "#pragma once\n#include <iostream>\n#include <string>\n#include <functional>\n\
    #include <vector>\n\ntemplate <typename C>\nvoid grid_viewer([[maybe_unused]]\
    \ const C &A, [[maybe_unused]] int width = 10){\n#ifdef DEBUG\n  const int H =\
    \ A.size();\n  const int W = A[0].size();\n\n  std::cerr << \"    \";\n  for(int\
    \ j = 0; j < W; ++j){\n    std::cerr << \"\\e[1;32m\" << std::left << std::setw(width)\
    \ << j << \"\\e[m\";\n  }\n  std::cerr << \"\\n\";\n  std::cerr << std::right;\n\
    \n  for(int i = 0; i < H; ++i){\n    std::cerr << \"\\e[1;32m\" << std::setw(2)\
    \ << i << \"|\\e[m \";\n\n    for(int j = 0; j < W; ++j){\n      std::stringstream\
    \ ss;\n      ss << A[i][j];\n      auto s = ss.str();\n      if(s.size() > width){\n\
    \        s.resize(width);\n      }else{\n        while(s.size() < width) s.push_back('\
    \ ');\n      }\n\n      std::cerr << s << \"\";\n    }\n\n    std::cerr << \"\\\
    n\";\n  }\n\n  std::cerr << std::right;\n  std::cerr << std::setw(0);\n#endif\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Debug/grid_viewer.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Debug/grid_viewer.cpp
layout: document
title: null
---

## Operations

## Requirements

## Notes

## Problems

## References
