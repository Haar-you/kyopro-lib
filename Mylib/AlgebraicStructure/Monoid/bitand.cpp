#pragma once

/**
 * @docs bitand.md
 */
template <typename T>
struct BitAndMonoid{
  using value_type = T;
  value_type id() const {return ~(value_type)0;}
  value_type op(value_type a, value_type b) const {return a & b;}
};
