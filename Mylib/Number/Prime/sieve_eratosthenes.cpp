#pragma once
#include <vector>

namespace haar_lib {
  class eratosthenes_sieve {
    std::vector<bool> is_prime_;

  public:
    eratosthenes_sieve(){}
    eratosthenes_sieve(int MAX): is_prime_(MAX + 1){
      is_prime_.flip();
      is_prime_[0] = is_prime_[1] = false;

      for(int i = 2; i * i <= MAX; ++i){
        if(is_prime_[i]){
          for(int j = i * i; j <= MAX; j += i){
            is_prime_[j] = false;
          }
        }
      }
    }

    bool operator()(int i) const {
      return is_prime_[i];
    }
  };
}
