#pragma once
#include "Mylib/AlgebraicStructure/Monoid/update_monoid.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min_monoid.cpp"

/**
 * @docs update_min.md
 */
template <typename T, typename U>
struct UpdateMin{
  using monoid_get = MinMonoid<T>;
  using monoid_update = UpdateMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  constexpr inline static value_type_get op(const value_type_get &a, const value_type_update &b, int){
    return b ? *b : a;
  }
};
