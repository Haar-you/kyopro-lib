#pragma once
#include <vector>
#include <optional>
#include <utility>
#include <bitset>

/**
 * @title Simultaneous linear equations (Mod2)
 * @docs binary_simultaneous_linear_equations.md
 */
namespace binary_simultaneous_linear_equations{
  template <size_t N>
  struct Result{
    int rank, dim;
    std::vector<bool> solution;
  };

  template <size_t N>
  auto solve(std::vector<std::bitset<N>> a, std::vector<bool> b){
    std::optional<Result<N>> ret;
  
    const int n = a.size(), m = N;
    int rank = 0;
    
    for(int j = 0; j < m; ++j){
      int pivot = -1;
      for(int i = rank; i < n; ++i){
        if(a[i][j]){
          pivot = i;
          break;
        }
      }

      if(pivot == -1) continue;
      std::swap(a[pivot], a[rank]);
      swap(b[pivot], b[rank]);
    
      for(int i = 0; i < n; ++i){
        if(i != rank and a[i][j]){
          a[i] ^= a[rank];
          b[i] = b[i] ^ b[rank];
        }
      }
    
      ++rank;
    }
  
    for(int i = rank; i < n; ++i){
      if(b[i]){
        return ret;
      }
    }
  
    int dim = m - rank;

    std::vector<bool> solution(m);
    for(int i = 0; i < rank; ++i) solution[i] = b[i];

    ret = Result<N>({rank, dim, solution});
  
    return ret;
  }
}
