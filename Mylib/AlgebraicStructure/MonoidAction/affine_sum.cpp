#pragma once
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/AlgebraicStructure/Monoid/affine.cpp"

/**
 * @docs affine_sum.md
 */
template <typename T, typename U>
struct AffineSum{
  using monoid_get = SumMonoid<T>;
  using monoid_update = AffineMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  constexpr inline static value_type_get op(const value_type_get &a, const value_type_update &b, int len){
    return b.first * a + b.second * len;
  }
};
