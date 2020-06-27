#pragma once

/**
 * @docs product_matrix.md
 */
template <typename T>
struct ProductMatrixMonoid{
  using value_type = T;
  static value_type id(){return T::make_unit();}
  static value_type op(const value_type &a, const value_type &b){return a * b;}
};
