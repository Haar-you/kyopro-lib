#pragma once
#include <vector>

namespace haar_lib {
  class eratosthenes_sieve {
    std::vector<bool> is_prime;

  public:
    eratosthenes_sieve(int MAX): is_prime(MAX + 1){
      is_prime.flip();
      is_prime[0] = is_prime[1] = false;

      for(int i = 2; i <= MAX; ++i){
        if(is_prime[i]){
          for(int j = 2 * i; j <= MAX; j += i){
            is_prime[j] = false;
          }
        }
      }
    }

    bool operator()(int i) const {
      return is_prime[i];
    }
  };
}
