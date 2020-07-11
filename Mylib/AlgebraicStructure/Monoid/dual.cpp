#pragma once

/**
 * @docs dual.md
 */
template <typename Monoid>
struct DualMonoid{
  using value_type = typename Monoid::value_type;
  Monoid M;
  value_type id() const {return M.id();}
  value_type op(const value_type &a, const value_type &b) const {return M.op(b, a);}
};
