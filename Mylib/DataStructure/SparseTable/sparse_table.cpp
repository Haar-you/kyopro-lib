#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <optional>

namespace haar_lib {
  template <typename Semilattice>
  class sparse_table {
    using value_type = typename Semilattice::value_type;
    const static Semilattice S;

    std::vector<std::vector<value_type>> a;
    std::vector<int> log_table;

  public:
    template <typename T>
    sparse_table(const std::vector<T> &v){
      int n = v.size();
      int logn = 0;
      while((1 << logn) <= n) ++logn;

      a.assign(n, std::vector<value_type>(logn));
      for(int i = 0; i < n; ++i) a[i][0] = v[i];
      for(int j = 1; j < logn; ++j){
        for(int i = 0; i < n; ++i){
          a[i][j] = S(a[i][j - 1], a[std::min<int>(n - 1, i + (1 << (j - 1)))][j - 1]);
        }
      }

      log_table.assign(n + 1, 0);
      for(int i = 2; i < n + 1; ++i) log_table[i] = log_table[i >> 1] + 1;
    }

    std::optional<value_type> fold(int s, int t) const { // [s, t)
      if(s == t) return std::nullopt;
      int k = log_table[t - s];
      return S(a[s][k], a[t - (1 << k)][k]);
    }
  };
}
