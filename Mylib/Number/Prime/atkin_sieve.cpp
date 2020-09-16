#pragma once
#include <vector>
#include <cstdint>

namespace haar_lib {
  class atkin_sieve {
    std::vector<bool> is_prime;

  public:
    atkin_sieve(int MAX): is_prime(MAX + 1){
      for(int64_t i = 1; i * i <= MAX; ++i){
        for(int64_t j = 1; j * j <= MAX; ++j){
          {
            auto n = 4LL * i * i + j * j;
            if(n <= MAX and (n % 12 == 1 or n % 12 == 5)){
              is_prime[n] = not is_prime[n];
            }
          }
          {
            auto n = 3LL * i * i + j * j;
            if(n <= MAX and n % 12 == 7){
              is_prime[n] = not is_prime[n];
            }
          }
          if(i > j){
            auto n = 3LL * i * i - j * j;
            if(n <= MAX and n % 12 == 11){
              is_prime[n] = not is_prime[n];
            }
          }
        }
      }

      for(int64_t i = 5; i * i <= MAX; ++i){
        if(is_prime[i]){
          for(int64_t k = i * i, j = k; j <= MAX; j += k){
            is_prime[j] = false;
          }
        }
      }

      is_prime[2] = is_prime[3] = true;
    }

    bool operator()(int i) const {
      return is_prime[i];
    }
  };
}
