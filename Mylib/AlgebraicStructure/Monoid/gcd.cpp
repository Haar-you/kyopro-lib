#pragma once
#include <numeric>

/**
 * @title GCD monoid
 * @docs gcd.md
 */
template <typename T>
struct GcdMonoid {
  using value_type = T;
  value_type operator()() const {return 0;}
  value_type operator()(value_type a, value_type b) const {return std::gcd(a, b);}
};
