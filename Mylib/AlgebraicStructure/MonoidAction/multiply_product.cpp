#pragma once
#include "Mylib/AlgebraicStructure/Monoid/product_monoid.cpp"
#include "Mylib/AlgebraicStructure/Monoid/monoid_utils.cpp"

/**
 * @docs multiply_product.md
 */
template <typename T, typename U>
struct MultiplyProduct{
  using monoid_get = ProductMonoid<T>;
  using monoid_update = ProductMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  constexpr inline static value_type_get op(const value_type_get &a, const value_type_update &b, int len){
    return a * times<monoid_update>(b, len);
  }
};
