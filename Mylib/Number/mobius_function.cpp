#pragma once
#include <vector>

/**
 * @title Möbius function
 * @docs mobius_function.md
 */
template <typename Checker>
std::vector<int> mobius_function(int n, Checker is_prime){
  std::vector<int> ret(n+1);
  std::vector<int> ps;

  ret[1] = 1;

  for(int i = 2; i <= n; ++i){
    if(is_prime(i)){
      ps.push_back(i);
      ret[i] = -1;
    }
    for(auto &j : ps){
      if(i * j > n) break;
      if(i % j == 0) ret[i * j] = 0;
      else ret[i * j] = ret[i] * ret[j];
    }
  }
  
  return ret;
}
