---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3118/main.test.cpp
    title: test/aoj/3118/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/SqrtDecomposition/sqrt_decomposition.cpp\"\
    \n#include <algorithm>\n#include <cmath>\n\nnamespace haar_lib {\n  struct sqrt_decomposition\
    \ {\n    const int N;\n    const int BLOCK_SIZE;\n    const int BLOCK_NUM;\n\n\
    \    sqrt_decomposition(int N):\n      N(N), BLOCK_SIZE((int)std::sqrt(N)), BLOCK_NUM((N\
    \ + BLOCK_SIZE - 1) / BLOCK_SIZE)\n    {\n    }\n\n    template <typename Func>\n\
    \    void init(const Func &f){\n      for(int i = 0; i < BLOCK_NUM; ++i){\n  \
    \      const int L = i * BLOCK_SIZE;\n        const int R = std::min<int>(N, (i\
    \ + 1) * BLOCK_SIZE);\n        f(i, L, R);\n      }\n    }\n\n    template <typename\
    \ FuncBlock, typename FuncRange>\n    void query(int l, int r, const FuncBlock\
    \ &func_block, const FuncRange &func_range){ // [l, r)\n      for(int i = 0; i\
    \ < BLOCK_NUM; ++i){\n        const int L = i * BLOCK_SIZE;\n        const int\
    \ R = std::min<int>(N, (i + 1) * BLOCK_SIZE);\n\n        if(l <= L and R <= r){\n\
    \          func_block(i, L, R);\n        }else if((L <= l and l < R) or (L < r\
    \ and r <= R)){\n          func_range(i, L, R, std::max(l, L), std::min(r, R));\n\
    \        }\n      }\n    }\n  };\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cmath>\n\nnamespace haar_lib\
    \ {\n  struct sqrt_decomposition {\n    const int N;\n    const int BLOCK_SIZE;\n\
    \    const int BLOCK_NUM;\n\n    sqrt_decomposition(int N):\n      N(N), BLOCK_SIZE((int)std::sqrt(N)),\
    \ BLOCK_NUM((N + BLOCK_SIZE - 1) / BLOCK_SIZE)\n    {\n    }\n\n    template <typename\
    \ Func>\n    void init(const Func &f){\n      for(int i = 0; i < BLOCK_NUM; ++i){\n\
    \        const int L = i * BLOCK_SIZE;\n        const int R = std::min<int>(N,\
    \ (i + 1) * BLOCK_SIZE);\n        f(i, L, R);\n      }\n    }\n\n    template\
    \ <typename FuncBlock, typename FuncRange>\n    void query(int l, int r, const\
    \ FuncBlock &func_block, const FuncRange &func_range){ // [l, r)\n      for(int\
    \ i = 0; i < BLOCK_NUM; ++i){\n        const int L = i * BLOCK_SIZE;\n       \
    \ const int R = std::min<int>(N, (i + 1) * BLOCK_SIZE);\n\n        if(l <= L and\
    \ R <= r){\n          func_block(i, L, R);\n        }else if((L <= l and l < R)\
    \ or (L < r and r <= R)){\n          func_range(i, L, R, std::max(l, L), std::min(r,\
    \ R));\n        }\n      }\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/SqrtDecomposition/sqrt_decomposition.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3118/main.test.cpp
documentation_of: Mylib/Algorithm/SqrtDecomposition/sqrt_decomposition.cpp
layout: document
title: Sqrt decomposition
---

## Operations

## Requirements

## Notes

## Problems

## References
