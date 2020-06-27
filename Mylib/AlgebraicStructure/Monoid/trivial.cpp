#pragma once

/**
 * @docs trivial.md
 */
template <typename T>
struct TrivialMonoid{
  using value_type = T;
  static value_type id() {return T();}
  static value_type op(const value_type &, const value_type &) {return T();}
};
