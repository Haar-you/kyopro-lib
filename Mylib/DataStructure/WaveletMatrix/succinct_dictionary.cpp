#pragma once
#include <cassert>
#include <optional>
#include <vector>

namespace haar_lib {
  class succinct_dict {
    int N_;

    static const int chunk_size_ = 256;
    static const int block_size_ = 64;
    std::vector<uint64_t> data_;

    std::vector<std::vector<uint8_t>> blocks_;

    std::vector<uint32_t> chunks_;

    int chunk_num_;
    static const int block_num_ = chunk_size_ / block_size_;

  public:
    succinct_dict() : N_(0) {}
    succinct_dict(const std::vector<bool> &b) : N_(b.size()) {
      chunk_num_ = (N_ + chunk_size_ - 1) / chunk_size_;

      data_.assign(chunk_num_ * block_num_ + 1, 0);

      for (int i = 0; i < N_; ++i) {
        if (b[i]) {
          int block_index = i / block_size_;
          int index       = i % block_size_;
          data_[block_index] |= (1LL << index);
        }
      }

      chunks_.assign(chunk_num_ + 1, 0);
      blocks_.assign(chunk_num_ + 1, std::vector<uint8_t>(block_num_, 0));

      for (int i = 0; i < chunk_num_; ++i) {
        for (int j = 0; j < block_num_ - 1; ++j) {
          blocks_[i][j + 1] = blocks_[i][j] + __builtin_popcountll(data_[i * block_num_ + j]);
        }

        chunks_[i + 1] = chunks_[i] + blocks_[i][block_num_ - 1] + __builtin_popcountll(data_[(i + 1) * block_num_ - 1]);
      }
    }

    int size() const { return N_; }

    /**
     * @return [0, index)のbの個数
     */
    int rank(int index, int b) const {
      if (b == 0) {
        return index - rank(index, 1);
      } else {
        if (index > N_) index = N_;

        const int chunk_pos = index / chunk_size_;
        const int block_pos = (index % chunk_size_) / block_size_;

        const uint64_t mask =
            data_[chunk_pos * block_num_ + block_pos] & ((1LL << (index % block_size_)) - 1);

        const int ret = chunks_[chunk_pos] +
                        blocks_[chunk_pos][block_pos] +
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
      return (data_[index / block_size_] >> (index % block_size_)) & 1;
    }

    /**
     * @note n in [1, N]
     * @return 先頭からn番目のbの位置
     */
    std::optional<int> select(int n, int b) const {
      assert(n >= 1);

      if (rank(N_, b) < n) return {};

      int lb = -1, ub = N_;
      while (std::abs(lb - ub) > 1) {
        int mid = (lb + ub) / 2;

        if (rank(mid, b) >= n) {
          ub = mid;
        } else {
          lb = mid;
        }
      }

      return {lb};
    }
  };
}  // namespace haar_lib
