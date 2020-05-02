#pragma once

/**
 * @docs or_monoid.md
 */
template <typename T>
struct OrMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return 0;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return a | b;}
};
