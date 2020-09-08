#pragma once
#include <vector>
#include <optional>
#include <utility>

/**
 * @title Simultaneous linear equations
 * @docs simultaneous_linear_equations.md
 */
namespace haar_lib {
  namespace simulaneous_linear_equations_impl {
    template <typename T>
    struct result {
      int rank, dim;
      std::vector<T> solution;
      std::vector<std::vector<T>> basis;
    };
  }

  template <typename T>
  auto simulaneous_linear_equations(std::vector<std::vector<T>> a, std::vector<T> b){
    using result = simulaneous_linear_equations_impl::result<T>;
    std::optional<result> ret;
    const int n = a.size();
    const int m = a[0].size();

    int rank = 0;

    for(int j = 0; j < m; ++j){
      int pivot = -1;

      for(int i = rank; i < n; ++i){
        if(a[i][j] != 0){
          pivot = i;
          break;
        }
      }

      if(pivot == -1) continue;

      std::swap(a[pivot], a[rank]);
      std::swap(b[pivot], b[rank]);

      auto d = a[rank][j];
      for(int k = 0; k < m; ++k) a[rank][k] /= d;
      b[rank] /= d;

      for(int i = 0; i < n; ++i){
        if(i == rank or a[i][j] == 0) continue;
        auto d = a[i][j];
        for(int k = 0; k < m; ++k) a[i][k] -= a[rank][k] * d;
        b[i] -= b[rank] * d;
      }

      ++rank;
    }

    for(int i = rank; i < n; ++i){
      if(b[i] != 0){
        return ret;
      }
    }

    const int dim = m - rank;

    std::vector<std::vector<T>> basis(dim, std::vector<T>(m));
    std::vector<int> index;

    {
      int k = 0;
      for(int i = 0; i < rank; ++i){
        for(int j = k; j < m; ++j){
          if(a[i][j] == 1){
            k = j + 1;
            break;
          }

          index.push_back(j);
        }
      }

      for(int j = k; j < m; ++j) index.push_back(j);
    }

    for(int i = 0, k = 0; i < rank; ++i){
      for(int j = k; j < m; ++j){
        if(a[i][j] == 1){
          for(int l = 0; l < dim; ++l) basis[l][j] = -a[i][index[l]];
          k = j + 1;
          break;
        }
      }
    }

    for(int i = 0; i < dim; ++i) basis[i][index[i]] = 1;

    std::vector<T> solution(m);
    for(int i = 0; i < rank; ++i) solution[i] = b[i];

    ret = result({rank, dim, solution, basis});

    return ret;
  }
}
