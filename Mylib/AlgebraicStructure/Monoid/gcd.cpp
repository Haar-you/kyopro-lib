#pragma once
#include <numeric>

/**
 * @docs gcd.md
 */
template <typename T>
struct GcdMonoid{
  using value_type = T;
  static value_type id(){return 0;}
  static value_type op(value_type a, value_type b){return std::gcd(a, b);}
};
