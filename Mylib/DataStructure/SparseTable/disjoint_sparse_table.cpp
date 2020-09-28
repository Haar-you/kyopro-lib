#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
#include <optional>

namespace haar_lib {
  template <typename Semigroup>
  class disjoint_sparse_table {
  public:
    using value_type = typename Semigroup::value_type;

  private:
    Semigroup S_;

    int N_, logN_;
    std::vector<value_type> A_;
    std::vector<std::vector<value_type>> data_;

    void build(int l, int r, int d){
      if(d <= 0) return;

      const int m = (l + r) / 2;

      data_[d][m] = A_[m];
      for(int i = m + 1; i < r; ++i){
        data_[d][i] = S_(data_[d][i - 1], A_[i]);
      }

      data_[d][m - 1] = A_[m - 1];
      for(int i = m - 2; i >= l; --i){
        data_[d][i] = S_(data_[d][i + 1], A_[i]);
      }

      build(l, m, d - 1);
      build(m, r, d - 1);
    }

  public:
    disjoint_sparse_table(){}
    disjoint_sparse_table(std::vector<value_type> a):
      N_(a.size()),
      logN_(N_ > 1 ? 32 - __builtin_clz(N_ - 1) : 0),
      A_(a),
      data_(logN_, std::vector<value_type>(1 << logN_))
    {
      A_.resize(1 << logN);
      if(logN_ > 0) std::copy(A_.begin(), A_.end(), data_[0].begin());
      build(0, 1 << logN_, logN_ - 1);
    }

    std::optional<value_type> fold(int l, int r) const {
      if(l == r) return std::nullopt;
      --r;

      if(l == r) return A_[l];

      const int k = 31 - __builtin_clz(l ^ r);
      return S_(data_[k][l], data_[k][r]);
    }
  };
}
