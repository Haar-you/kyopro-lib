---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp
    title: Wavelet matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1549/main.test.cpp
    title: test/aoj/1549/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2426/main.test.cpp
    title: test/aoj/2426/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2674/main.test.cpp
    title: test/aoj/2674/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/range_kth_smallest/main.test.cpp
    title: test/yosupo-judge/range_kth_smallest/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/919/main.test.cpp
    title: test/yukicoder/919/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp\"\
    \n#include <vector>\n#include <optional>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  class succinct_dict {\n    int N_;\n\n    static const int chunk_size_\
    \ = 256;\n    static const int block_size_ = 64;\n    std::vector<uint64_t> data_;\n\
    \n    std::vector<std::vector<uint8_t>> blocks_;\n\n    std::vector<uint32_t>\
    \ chunks_;\n\n    int chunk_num_;\n    static const int block_num_ = chunk_size_\
    \ / block_size_;\n\n  public:\n    succinct_dict(): N_(0){}\n    succinct_dict(const\
    \ std::vector<bool> &b): N_(b.size()){\n      chunk_num_ = (N_ + chunk_size_ -\
    \ 1) / chunk_size_;\n\n      data_.assign(chunk_num_ * block_num_ + 1, 0);\n\n\
    \      for(int i = 0; i < N_; ++i){\n        if(b[i]){\n          int block_index\
    \ = i / block_size_;\n          int index = i % block_size_;\n          data_[block_index]\
    \ |= (1LL << index);\n        }\n      }\n\n      chunks_.assign(chunk_num_ +\
    \ 1, 0);\n      blocks_.assign(chunk_num_ + 1, std::vector<uint8_t>(block_num_,\
    \ 0));\n\n      for(int i = 0; i < chunk_num_; ++i){\n        for(int j = 0; j\
    \ < block_num_ - 1; ++j){\n          blocks_[i][j + 1] = blocks_[i][j] + __builtin_popcountll(data_[i\
    \ * block_num_ + j]);\n        }\n\n        chunks_[i + 1] = chunks_[i] + blocks_[i][block_num_\
    \ - 1] + __builtin_popcountll(data_[(i + 1) * block_num_ - 1]);\n      }\n   \
    \ }\n\n    int size() const {return N_;}\n\n    /**\n     * @return [0, index)\u306E\
    b\u306E\u500B\u6570\n     */\n    int rank(int index, int b) const {\n      if(b\
    \ == 0){\n        return index - rank(index, 1);\n      }else{\n        if(index\
    \ > N_) index = N_;\n\n        const int chunk_pos = index / chunk_size_;\n  \
    \      const int block_pos = (index % chunk_size_) / block_size_;\n\n        const\
    \ uint64_t mask =\n          data_[chunk_pos * block_num_ + block_pos] & ((1LL\
    \ << (index % block_size_)) - 1);\n\n        const int ret = chunks_[chunk_pos]\
    \ +\n          blocks_[chunk_pos][block_pos] +\n          __builtin_popcountll(mask);\n\
    \n        return ret;\n      }\n    }\n\n    /**\n     * @return [l, r)\u306E\
    b\u306E\u500B\u6570\n     */\n    int count(int l, int r, int b) const {\n   \
    \   return rank(r, b) - rank(l, b);\n    }\n\n    /**\n     * @return b[index]\n\
    \     */\n    int access(int index) const {\n      return (data_[index / block_size_]\
    \ >> (index % block_size_)) & 1;\n    }\n\n    /**\n     * @note n in [1, N]\n\
    \     * @return \u5148\u982D\u304B\u3089n\u756A\u76EE\u306Eb\u306E\u4F4D\u7F6E\
    \n     */\n    std::optional<int> select(int n, int b) const {\n      assert(n\
    \ >= 1);\n\n      if(rank(N_, b) < n) return {};\n\n      int lb = -1, ub = N_;\n\
    \      while(std::abs(lb - ub) > 1){\n        int mid = (lb + ub) / 2;\n\n   \
    \     if(rank(mid, b) >= n){\n          ub = mid;\n        }else{\n          lb\
    \ = mid;\n        }\n      }\n\n      return {lb};\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <optional>\n#include <cassert>\n\
    \nnamespace haar_lib {\n  class succinct_dict {\n    int N_;\n\n    static const\
    \ int chunk_size_ = 256;\n    static const int block_size_ = 64;\n    std::vector<uint64_t>\
    \ data_;\n\n    std::vector<std::vector<uint8_t>> blocks_;\n\n    std::vector<uint32_t>\
    \ chunks_;\n\n    int chunk_num_;\n    static const int block_num_ = chunk_size_\
    \ / block_size_;\n\n  public:\n    succinct_dict(): N_(0){}\n    succinct_dict(const\
    \ std::vector<bool> &b): N_(b.size()){\n      chunk_num_ = (N_ + chunk_size_ -\
    \ 1) / chunk_size_;\n\n      data_.assign(chunk_num_ * block_num_ + 1, 0);\n\n\
    \      for(int i = 0; i < N_; ++i){\n        if(b[i]){\n          int block_index\
    \ = i / block_size_;\n          int index = i % block_size_;\n          data_[block_index]\
    \ |= (1LL << index);\n        }\n      }\n\n      chunks_.assign(chunk_num_ +\
    \ 1, 0);\n      blocks_.assign(chunk_num_ + 1, std::vector<uint8_t>(block_num_,\
    \ 0));\n\n      for(int i = 0; i < chunk_num_; ++i){\n        for(int j = 0; j\
    \ < block_num_ - 1; ++j){\n          blocks_[i][j + 1] = blocks_[i][j] + __builtin_popcountll(data_[i\
    \ * block_num_ + j]);\n        }\n\n        chunks_[i + 1] = chunks_[i] + blocks_[i][block_num_\
    \ - 1] + __builtin_popcountll(data_[(i + 1) * block_num_ - 1]);\n      }\n   \
    \ }\n\n    int size() const {return N_;}\n\n    /**\n     * @return [0, index)\u306E\
    b\u306E\u500B\u6570\n     */\n    int rank(int index, int b) const {\n      if(b\
    \ == 0){\n        return index - rank(index, 1);\n      }else{\n        if(index\
    \ > N_) index = N_;\n\n        const int chunk_pos = index / chunk_size_;\n  \
    \      const int block_pos = (index % chunk_size_) / block_size_;\n\n        const\
    \ uint64_t mask =\n          data_[chunk_pos * block_num_ + block_pos] & ((1LL\
    \ << (index % block_size_)) - 1);\n\n        const int ret = chunks_[chunk_pos]\
    \ +\n          blocks_[chunk_pos][block_pos] +\n          __builtin_popcountll(mask);\n\
    \n        return ret;\n      }\n    }\n\n    /**\n     * @return [l, r)\u306E\
    b\u306E\u500B\u6570\n     */\n    int count(int l, int r, int b) const {\n   \
    \   return rank(r, b) - rank(l, b);\n    }\n\n    /**\n     * @return b[index]\n\
    \     */\n    int access(int index) const {\n      return (data_[index / block_size_]\
    \ >> (index % block_size_)) & 1;\n    }\n\n    /**\n     * @note n in [1, N]\n\
    \     * @return \u5148\u982D\u304B\u3089n\u756A\u76EE\u306Eb\u306E\u4F4D\u7F6E\
    \n     */\n    std::optional<int> select(int n, int b) const {\n      assert(n\
    \ >= 1);\n\n      if(rank(N_, b) < n) return {};\n\n      int lb = -1, ub = N_;\n\
    \      while(std::abs(lb - ub) > 1){\n        int mid = (lb + ub) / 2;\n\n   \
    \     if(rank(mid, b) >= n){\n          ub = mid;\n        }else{\n          lb\
    \ = mid;\n        }\n      }\n\n      return {lb};\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp
  requiredBy:
  - Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/919/main.test.cpp
  - test/aoj/1549/main.test.cpp
  - test/aoj/2674/main.test.cpp
  - test/aoj/2426/main.test.cpp
  - test/yosupo-judge/range_kth_smallest/main.test.cpp
documentation_of: Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp
layout: document
title: Succinct dictionary
---

## Operations

## Requirements

## Notes

## Problems

## References
