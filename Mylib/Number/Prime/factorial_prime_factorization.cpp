#pragma once

/**
 * @title Count number of prime factor p of $a!$
 * @docs factorial_prime_factorization.md
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
