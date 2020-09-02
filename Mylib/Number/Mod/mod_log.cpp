#pragma once
#include <unordered_map>
#include <optional>
#include <numeric>
#include <cmath>
#include "Mylib/Number/Mod/mod_power.cpp"
#include "Mylib/Number/Mod/mod_inv.cpp"

/**
 * @title Mod logarithm
 * @docs mod_log.md
 */
std::optional<int64_t> mod_log(int64_t a, int64_t b, int64_t m){
  if(b == 1) return 0;

  int64_t d = 0;

  while(1){
    if(auto g = std::gcd(a, m); g != 1){
      if(b % g != 0) return {};

      d += 1;
      m /= g;
      b /= g;
      (b *= mod_inv(a / g, m)) %= m;

      if(b == 1) return d;
    }else{
      break;
    }
  }

  const int64_t sq = sqrt(m) + 1;

  std::unordered_map<int64_t,int64_t> mp;
  {
    int64_t t = 1 % m;

    for(int i = 0; i < sq; ++i){
      if(mp.find(t) == mp.end()) mp[t] = i;
      (t *= a) %= m;
    }
  }

  {
    int64_t A = power(mod_inv(a, m), sq, m);
    int64_t t = b % m;

    for(int i = 0; i < sq; ++i){
      if(mp.find(t) != mp.end()){
        int64_t ret = i * sq + mp[t] + d;

        return ret;
      }

      (t *= A) %= m;
    }
  }

  return {};
}
