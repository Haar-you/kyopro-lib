#pragma once
#include <vector>
#include <cstdint>

namespace haar_lib {
  class prime_factorize_sieve {
    std::vector<int> p_;

  public:
    prime_factorize_sieve(){}
    prime_factorize_sieve(int N): p_(N + 1){
      for(int i = 2; i <= N; ++i){
        if(p_[i] != 0) continue;
        for(int j = i; j <= N; j += i){
          if(p_[j] == 0) p_[j] = i;
        }
      }
    }

    auto factorize(int N){
      std::vector<int64_t> ret;

      while(N > 1){
        ret.push_back(p_[N]);
        N /= p_[N];
      }

      return ret;
    }
  };
}
