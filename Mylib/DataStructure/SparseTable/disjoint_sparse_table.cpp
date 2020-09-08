#pragma once
#include <vector>
#include <algorithm>
#include <cassert>

/**
 * @title Disjoint sparse table
 * @docs disjoint_sparse_table.md
 */
namespace haar_lib {
  template <typename Semigroup>
  class DisjointSparseTable {
    using value_type = typename Semigroup::value_type;
    const static Semigroup S;

    int N;
    int logN;
    std::vector<value_type> A;

    std::vector<std::vector<value_type>> data;

    void build(int l, int r, int d){
      if(d <= 0) return;

      const int m = (l + r) / 2;

      data[d][m] = A[m];
      for(int i = m + 1; i < r; ++i){
        data[d][i] = S(data[d][i - 1], A[i]);
      }

      data[d][m - 1] = A[m - 1];
      for(int i = m - 2; i >= l; --i){
        data[d][i] = S(data[d][i + 1], A[i]);
      }

      build(l, m, d - 1);
      build(m, r, d - 1);
    }

  public:
    DisjointSparseTable(std::vector<value_type> a):
      N(a.size()),
      logN(N > 1 ? 32 - __builtin_clz(N - 1) : 0),
      A(a),
      data(logN, std::vector<value_type>(1 << logN))
    {
      A.resize(1 << logN);
      if(logN > 0) std::copy(A.begin(), A.end(), data[0].begin());
      build(0, 1 << logN, logN - 1);
    }

    value_type get(int l, int r) const {
      assert(l < r);
      --r;

      if(l == r) return A[l];

      const int k = 31 - __builtin_clz(l ^ r);
      return S(data[k][l], data[k][r]);
    }
  };
}
