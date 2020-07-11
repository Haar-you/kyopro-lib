#pragma once

/**
 * @docs bitxor.md
 */
template <typename T>
struct BitXorMonoid{
  using value_type = T;
  value_type id() const {return 0;}
  value_type op(value_type a, value_type b) const {return a ^ b;}
};
