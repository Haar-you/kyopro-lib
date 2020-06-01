#pragma once
#include <utility>

/**
 * @title Greatest common divisor / Least common multiple
 * @docs gcd_lcm.md
 */
int64_t gcd(int64_t a, int64_t b){
  if(a < b) std::swap(a, b);
  if(b == 0) return a;

  return gcd(b, a % b);
}

int64_t lcm(int64_t a, int64_t b){
  return a / gcd(a, b) * b;
}
