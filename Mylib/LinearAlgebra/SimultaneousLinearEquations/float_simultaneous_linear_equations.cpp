#pragma once
#include <vector>
#include <optional>
#include <utility>

/**
 * @title Simultaneous linear equations (Floating point number)
 * @docs float_simultaneous_linear_equations.md
 */
namespace float_simultaneous_linear_equations{
  template <typename T>
  struct Result{
    int rank, dim;
    std::vector<T> solution;
  };

  template <typename T>
  auto solve(std::vector<std::vector<T>> a, std::vector<T> b, T eps){
    std::optional<Result<T>> ret;

    const int n = a.size(), m = a[0].size();
    int rank = 0;
  
    for(int j = 0; j < m; ++j){
      int pivot = -1;
    
      double M = eps;
      for(int i = rank; i < n; ++i){
        if(std::abs(a[i][j]) > M){
          M = std::abs(a[i][j]);
          pivot = i;
        }
      }
    
      if(pivot == -1) continue;
    
      std::swap(a[pivot], a[rank]);
      std::swap(b[pivot], b[rank]);
    
      {
        double d = a[rank][j];
        for(int k = 0; k < m; ++k) a[rank][k] /= d;
        b[rank] /= d;
      }

      for(int i = 0; i < n; ++i){
        if(i == rank or std::abs(a[i][j]) <= eps) continue;
        double d = a[i][j];
        for(int k = 0; k < m; ++k){
          a[i][k] -= a[rank][k] * d;
        }
        b[i] -= b[rank] * d;
      }
    
      ++rank;
    }
  
    for(int i = rank; i < n; ++i){
      if(std::abs(b[i]) > eps){
        return ret;
      }
    }

    int dim = m - rank;

    std::vector<T> solution(m);
    for(int i = 0; i < rank; ++i) solution[i] = b[i];

    ret = Result<T>({rank, dim, solution});
    return ret;
  }
}
