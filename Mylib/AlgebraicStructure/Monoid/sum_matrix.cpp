#pragma once

/**
 * @docs sum_matrix.md
 */
template <typename T>
struct SumMatrixMonoid{
  using value_type = T;
  static value_type id(){return T();}
  static value_type op(const value_type &a, const value_type &b){return a + b;}
};
