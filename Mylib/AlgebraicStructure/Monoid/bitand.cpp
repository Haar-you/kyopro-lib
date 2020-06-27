#pragma once

/**
 * @docs bitand.md
 */
template <typename T>
struct BitAndMonoid{
  using value_type = T;
  static value_type id(){return ~(value_type)0;}
  static value_type op(value_type a, value_type b){return a & b;}
};
