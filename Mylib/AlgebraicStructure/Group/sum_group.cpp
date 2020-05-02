#pragma once

/**
 * @docs sum_group.md
 */
template <typename T>
struct SumGroup{
  using value_type = T;

  static value_type id(){return 0;}
  static value_type op(const value_type &a, const value_type &b){return a + b;}
  static value_type inv(const value_type &a, const value_type &b){return a - b;}
};
