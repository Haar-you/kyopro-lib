#pragma once
#include <bitset>

/**
 * @title Eratosthenesの篩
 * @docs eratosthenes_sieve.md
 */
template <int MAX>
struct EratosthenesSieve{
  static std::bitset<MAX+1> is_prime;
  
  static void init(){
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
};

template <int MAX> std::bitset<MAX+1> EratosthenesSieve<MAX>::is_prime;
