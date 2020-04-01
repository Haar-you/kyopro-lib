#pragma once
#include <vector>
#include "Mylib/Number/Prime/eratosthenes_sieve.cpp"

/**
 * @see https://codeforces.com/contest/1139/problem/D
 * @see https://en.wikipedia.org/wiki/M%C3%B6bius_function
 */
std::vector<int> mobius_function(int n){
  std::vector<int> ret(n+1);
  std::vector<int> ps;

  ret[1] = 1;

  for(int i = 2; i <= n; ++i){
    if(eratosthenes_sieve::is_prime[i]){
      ps.push_back(i);
      ret[i] = -1;
    }
    for(auto &j : ps){
      if(i*j > n) break;
      if(i%j == 0) ret[i*j] = 0;
      else ret[i*j] = ret[i] * ret[j];
    }
  }
  
  return ret;
}