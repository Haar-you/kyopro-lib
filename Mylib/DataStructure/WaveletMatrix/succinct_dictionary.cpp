#pragma once
#include <vector>
#include <optional>
#include <cassert>

/**
 * @title Succinct dictionary
 * @docs succinct_dictionary.md
 */
namespace haar_lib {
  struct SuccinctDict {
    int N;

    static const int chunk_size = 256;
    static const int block_size = 64;
    std::vector<uint64_t> data;

    std::vector<std::vector<uint8_t>> blocks;

    std::vector<uint32_t> chunks;

    int chunk_num;
    static const int block_num = chunk_size / block_size;

    SuccinctDict(): N(0){}
    SuccinctDict(const std::vector<bool> &b): N(b.size()){
      chunk_num = (N + chunk_size - 1) / chunk_size;

      data.assign(chunk_num * block_num + 1, 0);

      for(int i = 0; i < N; ++i){
        if(b[i]){
          int block_index = i / block_size;
          int index = i % block_size;
          data[block_index] |= (1LL << index);
        }
      }

      chunks.assign(chunk_num + 1, 0);
      blocks.assign(chunk_num + 1, std::vector<uint8_t>(block_num, 0));

      for(int i = 0; i < chunk_num; ++i){
        for(int j = 0; j < block_num - 1; ++j){
          blocks[i][j + 1] = blocks[i][j] + __builtin_popcountll(data[i * block_num + j]);
        }

        chunks[i + 1] = chunks[i] + blocks[i][block_num - 1] + __builtin_popcountll(data[(i + 1) * block_num - 1]);
      }
    }

    /**
     * @return [0, index)のbの個数
     */
    int rank(int index, int b) const {
      if(b == 0){
        return index - rank(index, 1);
      }else{
        if(index > N) index = N;

        const int chunk_pos = index / chunk_size;
        const int block_pos = (index % chunk_size) / block_size;

        const uint64_t mask =
          data[chunk_pos * block_num + block_pos] & ((1LL << (index % block_size)) - 1);

        const int ret = chunks[chunk_pos] +
          blocks[chunk_pos][block_pos] +
          __builtin_popcountll(mask);

        return ret;
      }
    }

    /**
     * @return [l, r)のbの個数
     */
    int count(int l, int r, int b) const {
      return rank(r, b) - rank(l, b);
    }

    /**
     * @return b[index]
     */
    int access(int index) const {
      return (data[index / block_size] >> (index % block_size)) & 1;
    }

    /**
     * @note n in [1, N]
     * @return 先頭からn番目のbの位置
     */
    std::optional<int> select(int n, int b) const {
      assert(n >= 1);

      if(rank(N, b) < n) return {};

      int lb = -1, ub = N;
      while(abs(lb - ub) > 1){
        int mid = (lb + ub) / 2;

        if(rank(mid, b) >= n){
          ub = mid;
        }else{
          lb = mid;
        }
      }

      return {lb};
    }
  };
}
