#pragma once
#include <vector>
#include <numeric>

/**
 * @see https://codeforces.com/contest/1208/submission/59824476
 * @note phi(nm) = phi(n) * phi(m) if nとmが互いに素
 */
auto phi_function(int n){
  std::vector<int> ret(n+1);
  std::iota(ret.begin(), ret.end(), 0);

  for(int i = 2; i <= n; ++i){
    if(ret[i] == i){
      for(int j = i; j <= n; j += i){
        ret[j] = ret[j] / i * (i-1);
      }
    }
  }
  
  return ret;
}