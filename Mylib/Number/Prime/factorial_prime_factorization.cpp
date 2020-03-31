#pragma once

/**
 * @see https://codeforces.com/contest/1228/submission/62232341
 * @note a!に素因数pが幾つ含まれるか?
 */
int64_t factorial_prime_factorization(int64_t a, int64_t p){
  int64_t ret = 0, q = p;

  while(q <= a){
    int64_t t = a / q;

    ret += t;

    int64_t k;
    if(__builtin_smulll_overflow(q, p, &k)) break;
    
    q = k;
  }
  return ret;
}
