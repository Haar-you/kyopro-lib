#pragma once

template <typename T>
struct SumMatrixMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return T();}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return a + b;}
};
