#pragma once

/**
 * @title Sum matrix monoid
 * @docs sum_matrix.md
 */
template <typename T>
struct SumMatrixMonoid {
  using value_type = T;
  value_type operator()() const {return T();}
  value_type operator()(const value_type &a, const value_type &b) const {return a + b;}
};
