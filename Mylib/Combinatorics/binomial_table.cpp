#pragma once
#include <vector>

/**
 * @title Binomial coefficients table
 * @docs binomial_table.md
 */
template <typename T>
auto binomial_table(int n, int k){
  std::vector<std::vector<T>> ret(n+1, std::vector<T>(k+1));
  ret[0][0] = 1;
  
  for(int i = 1; i <= n; ++i){
    ret[i][0] = 1;
    
    for(int j = 1; j <= k; ++j){
      ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
    }
  }

  return ret;
}
