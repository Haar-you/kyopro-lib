#pragma once

/**
 * @docs trivial.md
 */
template <typename T>
struct TrivialMonoid{
  using value_type = T;
  constexpr static value_type id() {return T();}
  constexpr static value_type op(const value_type &, const value_type &) {return T();}
};
