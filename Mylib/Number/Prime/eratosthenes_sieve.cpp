#pragma once
#include <bitset>

namespace eratosthenes_sieve{
  constexpr int MAX = 1000000;
  std::bitset<MAX+1> is_prime;

  __attribute__((constructor)) void init(){
    is_prime.flip();
    is_prime[0] = is_prime[1] = false;
    
    for(int i = 2; i <= MAX; ++i){
      if(is_prime[i]){
        for(int j = 2*i; j <= MAX; j += i){
          is_prime[j] = false;
        }
      }
    }
  }
}
