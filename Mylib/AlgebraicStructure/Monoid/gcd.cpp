#pragma once
#include <numeric>

/**
 * @docs gcd.md
 */
template <typename T>
struct GcdMonoid{
  using value_type = T;
  value_type id() const {return 0;}
  value_type op(value_type a, value_type b) const {return std::gcd(a, b);}
};
