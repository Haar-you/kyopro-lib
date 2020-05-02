#pragma once

/**
 * @docs and_monoid.md
 */
template <typename T>
struct AndMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return ~(value_type)0;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return a & b;}
};
