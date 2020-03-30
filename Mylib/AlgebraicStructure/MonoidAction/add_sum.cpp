#pragma once
#include "Mylib/AlgebraicStructure/Monoid/sum_monoid.cpp"

template <typename T, typename U>
struct AddSum{
  using monoid_get = SumMonoid<T>;
  using monoid_update = SumMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  constexpr inline static value_type_get op(const value_type_get &a, const value_type_update &b, int len){
    return a + b * len;
  }
};
