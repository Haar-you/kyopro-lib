#pragma once

/**
 * @docs trivial.md
 */
template <typename T>
struct TrivialMonoid{
  using value_type = T;
  value_type id() const {return T();}
  value_type op(const value_type &, const value_type &) const {return T();}
};
