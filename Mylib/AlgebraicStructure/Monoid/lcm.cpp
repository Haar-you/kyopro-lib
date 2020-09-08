#pragma once
#include <numeric>

/**
 * @title LCM monoid
 * @docs lcm.md
 */
namespace haar_lib {
  template <typename T>
  struct LcmMonoid {
    using value_type = T;
    value_type operator()() const {return 1;}
    value_type operator()(value_type a, value_type b) const {return std::lcm(a, b);}
  };
}
