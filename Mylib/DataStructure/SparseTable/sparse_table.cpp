#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <optional>

namespace haar_lib {
  template <typename Semilattice>
  class sparse_table {
  public:
    using value_type = typename Semilattice::value_type;

  private:
    Semilattice S_;

    std::vector<std::vector<value_type>> data_;
    std::vector<int> log_table_;

  public:
    sparse_table(){}
    template <typename T>
    sparse_table(const std::vector<T> &v){
      const int n = v.size();
      int logn = 0;
      while((1 << logn) <= n) ++logn;

      data_.assign(n, std::vector<value_type>(logn));
      for(int i = 0; i < n; ++i) data_[i][0] = v[i];
      for(int j = 1; j < logn; ++j){
        for(int i = 0; i < n; ++i){
          data_[i][j] = S_(data_[i][j - 1], data_[std::min<int>(n - 1, i + (1 << (j - 1)))][j - 1]);
        }
      }

      log_table_.assign(n + 1, 0);
      for(int i = 2; i < n + 1; ++i) log_table_[i] = log_table_[i >> 1] + 1;
    }

    std::optional<value_type> fold(int s, int t) const { // [s, t)
      if(s == t) return std::nullopt;
      int k = log_table_[t - s];
      return S_(data_[s][k], data_[t - (1 << k)][k]);
    }
  };
}
