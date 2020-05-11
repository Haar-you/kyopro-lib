#pragma once
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/AlgebraicStructure/Monoid/max.cpp"

/**
 * @docs add_max.md
 */
template <typename T, typename U>
struct AddMax{
  using monoid_get = MaxMonoid<T>;
  using monoid_update = SumMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  constexpr inline static value_type_get op(const value_type_get &a, const value_type_update &b, int len){
    return a + b;
  }
};
