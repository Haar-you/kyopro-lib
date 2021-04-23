#pragma once
#include <algorithm>
#include <optional>
#include <utility>
#include <vector>

namespace haar_lib {
  template <typename Semilattice>
  class sparse_table_2d {
  public:
    using value_type = typename Semilattice::value_type;

  private:
    Semilattice S_;

    std::vector<std::vector<std::vector<std::vector<value_type>>>> data_;
    std::vector<int> log_table_;

  public:
    sparse_table_2d() {}
    sparse_table_2d(const std::vector<std::vector<value_type>> &v) {
      const int n = v.size();
      const int m = v[0].size();
      int logn    = 0;
      int logm    = 0;
      while ((1 << logn) <= n) ++logn;
      while ((1 << logm) <= m) ++logm;

      data_ = std::vector(n, std::vector(logn, std::vector(m, std::vector<value_type>(logm))));

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) data_[i][0][j][0] = v[i][j];

        for (int y = 1; y < logm; ++y) {
          for (int j = 0; j < m; ++j) {
            data_[i][0][j][y] =
                S_(data_[i][0][j][y - 1],
                   data_[i][0][std::min<int>(m - 1, j + (1 << (y - 1)))][y - 1]);
          }
        }
      }

      for (int x = 1; x < logn; ++x) {
        for (int i = 0; i < n; ++i) {
          for (int y = 0; y < logm; ++y) {
            for (int j = 0; j < m; ++j) {
              data_[i][x][j][y] =
                  S_(data_[i][x - 1][j][y],
                     data_[std::min<int>(n - 1, i + (1 << (x - 1)))][x - 1][j][y]);
            }
          }
        }
      }

      log_table_.assign(std::max(n, m) + 1, 0);
      for (int i = 2; i < std::max(n, m) + 1; ++i) log_table_[i] = log_table_[i >> 1] + 1;
    }

    std::optional<value_type> fold(int r1, int c1, int r2, int c2) const {
      if (r1 == r2 or c1 == c2) return std::nullopt;
      const int kr = log_table_[r2 - r1];
      const int kc = log_table_[c2 - c1];

      const value_type x = S_(data_[r1][kr][c1][kc], data_[r1][kr][c2 - (1 << kc)][kc]);
      const value_type y = S_(data_[r2 - (1 << kr)][kr][c1][kc], data_[r2 - (1 << kr)][kr][c2 - (1 << kc)][kc]);

      return S_(x, y);
    }
  };
}  // namespace haar_lib
