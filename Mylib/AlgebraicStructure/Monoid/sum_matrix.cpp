#pragma once

/**
 * @docs sum_matrix.md
 */
template <typename T>
struct SumMatrixMonoid{
  using value_type = T;
  value_type id() const {return T();}
  value_type op(const value_type &a, const value_type &b) const {return a + b;}
};
