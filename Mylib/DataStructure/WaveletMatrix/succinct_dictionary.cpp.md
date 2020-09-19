---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp
    title: Wavelet matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2674/main.test.cpp
    title: test/aoj/2674/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1549/main.test.cpp
    title: test/aoj/1549/main.test.cpp
  - icon: ':x:'
    path: test/aoj/2426/main.test.cpp
    title: test/aoj/2426/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/range_kth_smallest/main.test.cpp
    title: test/yosupo-judge/range_kth_smallest/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/919/main.test.cpp
    title: test/yukicoder/919/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp\"\
    \n#include <vector>\n#include <optional>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  struct succinct_dict {\n    int N;\n\n    static const int chunk_size =\
    \ 256;\n    static const int block_size = 64;\n    std::vector<uint64_t> data;\n\
    \n    std::vector<std::vector<uint8_t>> blocks;\n\n    std::vector<uint32_t> chunks;\n\
    \n    int chunk_num;\n    static const int block_num = chunk_size / block_size;\n\
    \n    succinct_dict(): N(0){}\n    succinct_dict(const std::vector<bool> &b):\
    \ N(b.size()){\n      chunk_num = (N + chunk_size - 1) / chunk_size;\n\n     \
    \ data.assign(chunk_num * block_num + 1, 0);\n\n      for(int i = 0; i < N; ++i){\n\
    \        if(b[i]){\n          int block_index = i / block_size;\n          int\
    \ index = i % block_size;\n          data[block_index] |= (1LL << index);\n  \
    \      }\n      }\n\n      chunks.assign(chunk_num + 1, 0);\n      blocks.assign(chunk_num\
    \ + 1, std::vector<uint8_t>(block_num, 0));\n\n      for(int i = 0; i < chunk_num;\
    \ ++i){\n        for(int j = 0; j < block_num - 1; ++j){\n          blocks[i][j\
    \ + 1] = blocks[i][j] + __builtin_popcountll(data[i * block_num + j]);\n     \
    \   }\n\n        chunks[i + 1] = chunks[i] + blocks[i][block_num - 1] + __builtin_popcountll(data[(i\
    \ + 1) * block_num - 1]);\n      }\n    }\n\n    /**\n     * @return [0, index)\u306E\
    b\u306E\u500B\u6570\n     */\n    int rank(int index, int b) const {\n      if(b\
    \ == 0){\n        return index - rank(index, 1);\n      }else{\n        if(index\
    \ > N) index = N;\n\n        const int chunk_pos = index / chunk_size;\n     \
    \   const int block_pos = (index % chunk_size) / block_size;\n\n        const\
    \ uint64_t mask =\n          data[chunk_pos * block_num + block_pos] & ((1LL <<\
    \ (index % block_size)) - 1);\n\n        const int ret = chunks[chunk_pos] +\n\
    \          blocks[chunk_pos][block_pos] +\n          __builtin_popcountll(mask);\n\
    \n        return ret;\n      }\n    }\n\n    /**\n     * @return [l, r)\u306E\
    b\u306E\u500B\u6570\n     */\n    int count(int l, int r, int b) const {\n   \
    \   return rank(r, b) - rank(l, b);\n    }\n\n    /**\n     * @return b[index]\n\
    \     */\n    int access(int index) const {\n      return (data[index / block_size]\
    \ >> (index % block_size)) & 1;\n    }\n\n    /**\n     * @note n in [1, N]\n\
    \     * @return \u5148\u982D\u304B\u3089n\u756A\u76EE\u306Eb\u306E\u4F4D\u7F6E\
    \n     */\n    std::optional<int> select(int n, int b) const {\n      assert(n\
    \ >= 1);\n\n      if(rank(N, b) < n) return {};\n\n      int lb = -1, ub = N;\n\
    \      while(std::abs(lb - ub) > 1){\n        int mid = (lb + ub) / 2;\n\n   \
    \     if(rank(mid, b) >= n){\n          ub = mid;\n        }else{\n          lb\
    \ = mid;\n        }\n      }\n\n      return {lb};\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <optional>\n#include <cassert>\n\
    \nnamespace haar_lib {\n  struct succinct_dict {\n    int N;\n\n    static const\
    \ int chunk_size = 256;\n    static const int block_size = 64;\n    std::vector<uint64_t>\
    \ data;\n\n    std::vector<std::vector<uint8_t>> blocks;\n\n    std::vector<uint32_t>\
    \ chunks;\n\n    int chunk_num;\n    static const int block_num = chunk_size /\
    \ block_size;\n\n    succinct_dict(): N(0){}\n    succinct_dict(const std::vector<bool>\
    \ &b): N(b.size()){\n      chunk_num = (N + chunk_size - 1) / chunk_size;\n\n\
    \      data.assign(chunk_num * block_num + 1, 0);\n\n      for(int i = 0; i <\
    \ N; ++i){\n        if(b[i]){\n          int block_index = i / block_size;\n \
    \         int index = i % block_size;\n          data[block_index] |= (1LL <<\
    \ index);\n        }\n      }\n\n      chunks.assign(chunk_num + 1, 0);\n    \
    \  blocks.assign(chunk_num + 1, std::vector<uint8_t>(block_num, 0));\n\n     \
    \ for(int i = 0; i < chunk_num; ++i){\n        for(int j = 0; j < block_num -\
    \ 1; ++j){\n          blocks[i][j + 1] = blocks[i][j] + __builtin_popcountll(data[i\
    \ * block_num + j]);\n        }\n\n        chunks[i + 1] = chunks[i] + blocks[i][block_num\
    \ - 1] + __builtin_popcountll(data[(i + 1) * block_num - 1]);\n      }\n    }\n\
    \n    /**\n     * @return [0, index)\u306Eb\u306E\u500B\u6570\n     */\n    int\
    \ rank(int index, int b) const {\n      if(b == 0){\n        return index - rank(index,\
    \ 1);\n      }else{\n        if(index > N) index = N;\n\n        const int chunk_pos\
    \ = index / chunk_size;\n        const int block_pos = (index % chunk_size) /\
    \ block_size;\n\n        const uint64_t mask =\n          data[chunk_pos * block_num\
    \ + block_pos] & ((1LL << (index % block_size)) - 1);\n\n        const int ret\
    \ = chunks[chunk_pos] +\n          blocks[chunk_pos][block_pos] +\n          __builtin_popcountll(mask);\n\
    \n        return ret;\n      }\n    }\n\n    /**\n     * @return [l, r)\u306E\
    b\u306E\u500B\u6570\n     */\n    int count(int l, int r, int b) const {\n   \
    \   return rank(r, b) - rank(l, b);\n    }\n\n    /**\n     * @return b[index]\n\
    \     */\n    int access(int index) const {\n      return (data[index / block_size]\
    \ >> (index % block_size)) & 1;\n    }\n\n    /**\n     * @note n in [1, N]\n\
    \     * @return \u5148\u982D\u304B\u3089n\u756A\u76EE\u306Eb\u306E\u4F4D\u7F6E\
    \n     */\n    std::optional<int> select(int n, int b) const {\n      assert(n\
    \ >= 1);\n\n      if(rank(N, b) < n) return {};\n\n      int lb = -1, ub = N;\n\
    \      while(std::abs(lb - ub) > 1){\n        int mid = (lb + ub) / 2;\n\n   \
    \     if(rank(mid, b) >= n){\n          ub = mid;\n        }else{\n          lb\
    \ = mid;\n        }\n      }\n\n      return {lb};\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp
  requiredBy:
  - Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/2674/main.test.cpp
  - test/aoj/1549/main.test.cpp
  - test/aoj/2426/main.test.cpp
  - test/yosupo-judge/range_kth_smallest/main.test.cpp
  - test/yukicoder/919/main.test.cpp
documentation_of: Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp
layout: document
title: Succinct dictionary
---

## Operations

## Requirements

## Notes

## Problems

## References
