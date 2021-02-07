---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3118/main.test.cpp
    title: test/aoj/3118/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/sqrt_decomposition.cpp\"\n#include <algorithm>\n\
    #include <cmath>\n\nnamespace haar_lib {\n  class sqrt_decomposition {\n    int\
    \ N_, BLOCK_SIZE_, BLOCK_NUM_;\n\n  public:\n    sqrt_decomposition(int N):\n\
    \      N_(N), BLOCK_SIZE_((int)std::sqrt(N)), BLOCK_NUM_((N + BLOCK_SIZE_ - 1)\
    \ / BLOCK_SIZE_){}\n\n    int block_size() const {return BLOCK_SIZE_;}\n    int\
    \ block_num() const {return BLOCK_NUM_;}\n\n    template <typename Func>\n   \
    \ void init(const Func &f){\n      for(int i = 0; i < BLOCK_NUM_; ++i){\n    \
    \    const int L = i * BLOCK_SIZE_;\n        const int R = std::min<int>(N_, (i\
    \ + 1) * BLOCK_SIZE_);\n        f(i, L, R);\n      }\n    }\n\n    template <typename\
    \ FuncBlock, typename FuncRange>\n    void query(int l, int r, const FuncBlock\
    \ &func_block, const FuncRange &func_range){\n      for(int i = 0; i < BLOCK_NUM_;\
    \ ++i){\n        const int L = i * BLOCK_SIZE_;\n        const int R = std::min<int>(N_,\
    \ (i + 1) * BLOCK_SIZE_);\n\n        if(l <= L and R <= r){\n          func_block(i,\
    \ L, R);\n        }else if((L <= l and l < R) or (L < r and r <= R)){\n      \
    \    func_range(i, L, R, std::max(l, L), std::min(r, R));\n        }\n      }\n\
    \    }\n  };\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cmath>\n\nnamespace haar_lib\
    \ {\n  class sqrt_decomposition {\n    int N_, BLOCK_SIZE_, BLOCK_NUM_;\n\n  public:\n\
    \    sqrt_decomposition(int N):\n      N_(N), BLOCK_SIZE_((int)std::sqrt(N)),\
    \ BLOCK_NUM_((N + BLOCK_SIZE_ - 1) / BLOCK_SIZE_){}\n\n    int block_size() const\
    \ {return BLOCK_SIZE_;}\n    int block_num() const {return BLOCK_NUM_;}\n\n  \
    \  template <typename Func>\n    void init(const Func &f){\n      for(int i =\
    \ 0; i < BLOCK_NUM_; ++i){\n        const int L = i * BLOCK_SIZE_;\n        const\
    \ int R = std::min<int>(N_, (i + 1) * BLOCK_SIZE_);\n        f(i, L, R);\n   \
    \   }\n    }\n\n    template <typename FuncBlock, typename FuncRange>\n    void\
    \ query(int l, int r, const FuncBlock &func_block, const FuncRange &func_range){\n\
    \      for(int i = 0; i < BLOCK_NUM_; ++i){\n        const int L = i * BLOCK_SIZE_;\n\
    \        const int R = std::min<int>(N_, (i + 1) * BLOCK_SIZE_);\n\n        if(l\
    \ <= L and R <= r){\n          func_block(i, L, R);\n        }else if((L <= l\
    \ and l < R) or (L < r and r <= R)){\n          func_range(i, L, R, std::max(l,\
    \ L), std::min(r, R));\n        }\n      }\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/sqrt_decomposition.cpp
  requiredBy: []
  timestamp: '2020-12-09 10:43:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3118/main.test.cpp
documentation_of: Mylib/Algorithm/sqrt_decomposition.cpp
layout: document
title: Sqrt decomposition
---

## Operations

## Requirements

## Notes

## Problems

## References
