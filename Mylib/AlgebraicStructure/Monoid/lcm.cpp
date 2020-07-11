#pragma once
#include <numeric>

/**
 * @docs lcm.md
 */
template <typename T>
struct LcmMonoid{
  using value_type = T;
  value_type id() const {return 1;}
  value_type op(value_type a, value_type b) const {return std::lcm(a, b);}
};
