#pragma once

/**
 * @title 試し割り素数判定
 * @docs is_prime.md
 */
bool is_prime(int n){
  if(n <= 1) return false;
  for(int i = 2; i * i <= n; ++i){
    if(n % i == 0) return false;
  }
  return true;
}