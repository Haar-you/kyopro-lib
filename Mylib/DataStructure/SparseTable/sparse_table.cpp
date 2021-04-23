#pragma once
#include <algorithm>
#include <cassert>
#include <optional>
#include <utility>
#include <vector>

namespace haar_lib {
  template <typename Semilattice>
  class sparse_table {
  public:
    using value_type = typename Semilattice::value_type;

  private:
    Semilattice S_;

    int n_;
    std::vector<std::vector<value_type>> data_;
    std::vector<int> log_table_;

  public:
    sparse_table() {}
    template <typename T>
    sparse_table(const std::vector<T> &v) : n_(v.size()) {
      int logn = 0;
      while ((1 << logn) <= n_) ++logn;

      data_.assign(n_, std::vector<value_type>(logn));
      for (int i = 0; i < n_; ++i) data_[i][0] = v[i];
      for (int j = 1; j < logn; ++j) {
        for (int i = 0; i < n_; ++i) {
          data_[i][j] = S_(data_[i][j - 1], data_[std::min<int>(n_ - 1, i + (1 << (j - 1)))][j - 1]);
        }
      }

      log_table_.assign(n_ + 1, 0);
      for (int i = 2; i < n_ + 1; ++i) log_table_[i] = log_table_[i >> 1] + 1;
    }

    std::optional<value_type> fold(int l, int r) const {
      assert(0 <= l and l <= r and r <= n_);
      if (l == r) return std::nullopt;
      int k = log_table_[r - l];
      return S_(data_[l][k], data_[r - (1 << k)][k]);
    }
  };
}  // namespace haar_lib
