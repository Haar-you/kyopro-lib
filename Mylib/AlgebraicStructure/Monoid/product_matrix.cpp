#pragma once

/**
 * @title Product matrix monoid
 * @docs product_matrix.md
 */
template <typename T>
struct ProductMatrixMonoid {
  using value_type = T;
  value_type operator()() const {return T::make_unit();}
  value_type operator()(const value_type &a, const value_type &b) const {return a * b;}
};
