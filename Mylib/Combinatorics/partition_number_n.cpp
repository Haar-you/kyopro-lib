#pragma once
#include <cmath>
#include <vector>

/**
 * @see https://judge.yosupo.jp/submission/1223
 * @attention time-complexity O(N√N)
 */
template <typename T>
auto partition_number(int N){
  std::vector<T> p(N+1);
  
  p[0] = 1;

  for(int i = 1; i <= N; ++i){
    int s = sqrt(1+24*i);

    for(int j = 1; j <= (1+s)/6; ++j){
      p[i] += p[i-j*(3*j-1)/2] * (j % 2 ? 1 : -1);
    }
    
    for(int j = 1; j <= (-1+s)/6; ++j){
      p[i] += p[i-j*(3*j+1)/2] * (j % 2 ? 1 : -1);
    }
  }

  return p;
}
