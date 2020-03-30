#pragma once

template <typename T>
struct ProductMatrixMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return T::make_unit();}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return a * b;}
};
