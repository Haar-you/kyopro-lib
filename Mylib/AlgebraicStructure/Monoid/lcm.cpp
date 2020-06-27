#pragma once
#include <numeric>

/**
 * @docs lcm.md
 */
template <typename T>
struct LcmMonoid{
  using value_type = T;
  static value_type id(){return 1;}
  static value_type op(value_type a, value_type b){return std::lcm(a, b);}
};
