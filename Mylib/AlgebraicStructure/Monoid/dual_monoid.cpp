#pragma once

/**
 * @docs dual_monoid.md
 */
template <typename Monoid>
struct DualMonoid{
  using value_type = typename Monoid::value_type;
  constexpr inline static value_type id(){return Monoid::id();}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return Monoid::op(b, a);}
};
