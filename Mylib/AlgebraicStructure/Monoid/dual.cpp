#pragma once

/**
 * @docs dual.md
 */
template <typename Monoid>
struct DualMonoid{
  using value_type = typename Monoid::value_type;
  const static Monoid M;
  value_type operator()() const {return M();}
  value_type operator()(const value_type &a, const value_type &b) const {return M(b, a);}
};
