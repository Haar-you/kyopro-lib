#pragma once
#include <vector>
#include <cstdint>

/**
 * @title Prime factorization (Precalculation)
 * @docs prime_factorize_precalculated.md
 */
struct PrimeFactorize {
  std::vector<int> p;

  PrimeFactorize(int N): p(N + 1){
    for(int i = 2; i <= N; ++i){
      if(p[i] != 0) continue;
      for(int j = i; j <= N; j += i){
        if(p[j] == 0) p[j] = i;
      }
    }
  }

  auto factorize(int N){
    std::vector<int64_t> ret;

    while(N > 1){
      ret.push_back(p[N]);
      N /= p[N];
    }

    return ret;
  }
};
