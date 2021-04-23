#pragma once
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>

namespace haar_lib {
  template <typename T>
  class range_mode_query {
    std::vector<T> a_, D_;
    std::vector<int> b_, b_index_;
    int N_, block_size_, block_num_, K_;
    std::vector<std::vector<int>> index_, mode_, freq_;

  public:
    range_mode_query() {}
    range_mode_query(std::vector<T> a) : a_(a), D_(a), N_(a.size()), block_size_(std::sqrt(N_)), block_num_((N_ + block_size_ - 1) / block_size_), mode_(block_num_, std::vector<int>(block_num_)), freq_(block_num_, std::vector<int>(block_num_)) {
      std::sort(D_.begin(), D_.end());
      D_.erase(std::unique(D_.begin(), D_.end()), D_.end());

      b_.resize(N_);
      for (int i = 0; i < N_; ++i) {
        b_[i] = std::lower_bound(D_.begin(), D_.end(), a_[i]) - D_.begin();
      }

      K_ = D_.size();

      index_.resize(K_);
      b_index_.resize(N_);
      for (int i = 0; i < N_; ++i) {
        b_index_[i] = index_[b_[i]].size();
        index_[b_[i]].push_back(i);
      }

      for (int i = 0; i < block_num_; ++i) {
        std::vector<int> temp(K_);
        int md = 0, fr = 0;

        for (int j = i; j < block_num_; ++j) {
          int R = std::min(N_, block_size_ * (j + 1));
          for (int x = block_size_ * j; x < R; ++x) {
            temp[b_[x]] += 1;

            if (temp[b_[x]] > fr) {
              md = b_[x];
              fr = temp[b_[x]];
            }
          }

          mode_[i][j] = md;
          freq_[i][j] = fr;
        }
      }
    }

    std::pair<int, T> query(int l, int r) {  // [l, r)
      std::pair<int, T> ret = std::make_pair(0, 0);

      const int span_l = (l + block_size_ - 1) / block_size_, span_r = r / block_size_ - 1;

      if (span_l <= span_r) {
        ret = std::make_pair(freq_[span_l][span_r], D_[mode_[span_l][span_r]]);
      }

      // prefix
      for (int i = l; i < std::min(r, span_l * block_size_); ++i) {
        if (b_index_[i] - 1 >= 0 and index_[b_[i]][b_index_[i] - 1] >= l) continue;

        if (b_index_[i] + ret.first - 1 < 0 or
            (b_index_[i] + ret.first - 1 < (int) index_[b_[i]].size() and index_[b_[i]][b_index_[i] + ret.first - 1] < r)) {
          int fr = ret.first;

          for (int j = b_index_[i] + ret.first; j < (int) index_[b_[i]].size(); ++j) {
            if (index_[b_[i]][j] < r)
              ++fr;
            else
              break;
          }

          if (fr > ret.first) {
            ret = std::make_pair(fr, D_[b_[i]]);
          }
        }
      }

      // suffix
      for (int i = r - 1; i >= std::max(l, (span_r + 1) * block_size_); --i) {
        if (b_index_[i] + 1 < (int) index_[b_[i]].size() and index_[b_[i]][b_index_[i] + 1] < r) continue;

        if (b_index_[i] - ret.first + 1 >= (int) index_[b_[i]].size() or
            (b_index_[i] - ret.first + 1 >= 0 and index_[b_[i]][b_index_[i] - ret.first + 1] >= l)) {
          int fr = ret.first;

          for (int j = b_index_[i] - ret.first; j >= 0; --j) {
            if (index_[b_[i]][j] >= l)
              ++fr;
            else
              break;
          }

          if (fr > ret.first) {
            ret = std::make_pair(fr, D_[b_[i]]);
          }
        }
      }

      return ret;
    }
  };
}  // namespace haar_lib
