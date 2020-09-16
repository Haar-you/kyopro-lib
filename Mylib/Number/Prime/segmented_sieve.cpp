#pragma once
#include <vector>
#include <cstdint>
#include <cassert>

namespace haar_lib {
  template <typename Checker>
  class segmented_sieve {
    int L, R, D;
    std::vector<bool> data;

  public:
    // [l, r]
    segmented_sieve(int l, int r, Checker is_prime):
      L(l), R(r), D(R - L + 1), data(D, true){
      std::vector<int> primes;
      for(int64_t i = 2; i * i <= R; ++i){
        if(is_prime(i)) primes.push_back(i);
      }

      for(int64_t i = 0; i < D; ++i){
        const int64_t x = L + i;

        if(x == 1){
          data[i] = false;
          continue;
        }

        for(auto p : primes){
          if(x == p) break;
          if(x % p == 0){
            data[i] = false;
            break;
          }
        }
      }
    }

    bool operator()(int i) const {
      assert(L <= i and i <= R);
      return data[i - L];
    }
  };
}
