#pragma once

/**
 * @title Primality test (Trial division)
 * @docs is_prime.md
 */
namespace haar_lib {
  bool is_prime(int n){
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; ++i){
      if(n % i == 0) return false;
    }
    return true;
  }
}
