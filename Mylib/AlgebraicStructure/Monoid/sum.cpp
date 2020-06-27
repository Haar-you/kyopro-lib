#pragma once

/**
 * @docs sum.md
 */
template <typename T>
struct SumMonoid{
  using value_type = T;
  static value_type id(){return 0;}
  static value_type op(value_type a, value_type b){return a + b;}
};
