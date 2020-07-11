#pragma once

/**
 * @docs product_matrix.md
 */
template <typename T>
struct ProductMatrixMonoid{
  using value_type = T;
  value_type id() const {return T::make_unit();}
  value_type op(const value_type &a, const value_type &b) const {return a * b;}
};
