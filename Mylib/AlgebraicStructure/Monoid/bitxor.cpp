#pragma once

/**
 * @docs bitxor.md
 */
template <typename T>
struct BitXorMonoid{
  using value_type = T;
  static value_type id(){return 0;}
  static value_type op(value_type a, value_type b){return a ^ b;}
};
