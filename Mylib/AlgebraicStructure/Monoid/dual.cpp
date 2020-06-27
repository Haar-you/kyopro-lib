#pragma once

/**
 * @docs dual.md
 */
template <typename Monoid>
struct DualMonoid{
  using value_type = typename Monoid::value_type;
  static value_type id(){return Monoid::id();}
  static value_type op(const value_type &a, const value_type &b){return Monoid::op(b, a);}
};
