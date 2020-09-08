#pragma once
#include <vector>
#include <utility>
#include <algorithm>

/**
 * @title Sparse table (2D)
 * @docs sparse_table_2d.md
 */
namespace haar_lib {
  template <typename Semilattice>
  class sparse_table_2d {
    using value_type = typename Semilattice::value_type;
    const static Semilattice S;

    std::vector<std::vector<std::vector<std::vector<value_type>>>> a;
    std::vector<int> log_table;

  public:
    sparse_table_2d(const std::vector<std::vector<value_type>> &v){
      const int n = v.size();
      const int m = v[0].size();
      int logn = 0;
      int logm = 0;
      while((1 << logn) <= n) ++logn;
      while((1 << logm) <= m) ++logm;

      a = std::vector(n, std::vector(logn, std::vector(m, std::vector<value_type>(logm))));

      for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j) a[i][0][j][0] = v[i][j];

        for(int y = 1; y < logm; ++y){
          for(int j = 0; j < m; ++j){
            a[i][0][j][y] =
              S(a[i][0][j][y - 1],
                a[i][0][std::min<int>(m - 1, j + (1 << (y - 1)))][y - 1]);
          }
        }
      }

      for(int x = 1; x < logn; ++x){
        for(int i = 0; i < n; ++i){
          for(int y = 0; y < logm; ++y){
            for(int j = 0; j < m; ++j){
              a[i][x][j][y] =
                S(a[i][x - 1][j][y],
                  a[std::min<int>(n - 1, i + (1 << (x - 1)))][x - 1][j][y]);
            }
          }
        }
      }

      log_table.assign(std::max(n, m) + 1, 0);
      for(int i = 2; i < std::max(n, m) + 1; ++i) log_table[i] = log_table[i >> 1] + 1;
    }

    value_type get(int r1, int c1, int r2, int c2) const { // [(r1, c1), (r2, c2))
      const int kr = log_table[r2 - r1];
      const int kc = log_table[c2 - c1];

      const value_type x = S(a[r1][kr][c1][kc], a[r1][kr][c2 - (1 << kc)][kc]);
      const value_type y = S(a[r2 - (1 << kr)][kr][c1][kc], a[r2 - (1 << kr)][kr][c2 - (1 << kc)][kc]);

      return S(x, y);
    }
  };
}
