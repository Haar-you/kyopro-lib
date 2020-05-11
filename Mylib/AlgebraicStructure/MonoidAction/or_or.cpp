#pragma once
#include "Mylib/AlgebraicStructure/Monoid/bitor.cpp"

/**
 * @docs or_or.md
 */
template <typename T, typename U>
struct OrOr{
  using monoid_get = BitOrMonoid<T>;
  using monoid_update = BitOrMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  constexpr inline static value_type_get op(const value_type_get &a, const value_type_update &b, int len){
    return a | b;
  }
};
