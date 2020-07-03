#pragma once
#include <cassert>

/**
 * @title Kth root integer
 * @docs kth_root_integer.md
 */
uint64_t kth_root(uint64_t a, int k){
  assert(k >= 1);
  if(k == 1) return a;
  if(a == 1) return 1;
  
  uint64_t lb = 0, ub = a;

  auto check =
    [](uint64_t a, int k, uint64_t n){
      uint64_t r = 1;
  
      while(k > 0){
        if(k & 1){
          if(__builtin_umulll_overflow(r, a, (unsigned long long int*)&r)) return false;
        }
        if(__builtin_umulll_overflow(a, a, (unsigned long long int*)&a) and k > 1) return false;
        k >>= 1;
      }

      return r <= n;
    };

  while(ub - lb > 1){
    uint64_t mid = lb + (ub - lb) / 2;
    
    if(check(mid, k, a)){
      lb = mid;
    }else{
      ub = mid;
    }
  }
  
  return lb;  
}
