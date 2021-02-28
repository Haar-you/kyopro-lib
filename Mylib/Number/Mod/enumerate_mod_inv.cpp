#pragma once
#include <vector>
#include <cstdint>

std::vector<int64_t> enumerate_mod_inv(int n, int64_t p){
  std::vector<int64_t> ret(n + 1);

  ret[1] = 1;

  for(int i = 2; i <= n; ++i){
    ret[i] = (p / i) * (p - ret[p % i]) % p;
  }

  return ret;
}
