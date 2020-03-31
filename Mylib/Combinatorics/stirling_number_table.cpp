#pragma once
#include <vector>

/**
 * @attention time complexity O(N^2)
 */
template <typename T>
auto stirling_number_table(int n){
  std::vector<std::vector<T>> ret(n+1, std::vector<T>(n+1));

  ret[0][0] = 1;

  for(int i = 1; i <= n; ++i) ret[i][1] = ret[i][i] = 1;

  for(int i = 3; i <= n; ++i){
    for(int j = 2; j < i; ++j){
      ret[i][j] = ret[i-1][j-1] + j * ret[i-1][j];
    }
  }

  return ret;
}
