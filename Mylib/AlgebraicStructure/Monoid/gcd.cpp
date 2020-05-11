#pragma once
#include <numeric>

/**
 * @docs gcd.md
 */
template <typename T>
struct GcdMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return 0;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return std::gcd(a, b);}
};
