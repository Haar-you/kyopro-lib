#pragma once

template <typename T>
struct Trivial{
  using value_type = T;
  constexpr static value_type id() {return T();}
  constexpr static value_type op(const value_type &, const value_type &) {return T();}
};
